#include "ivedimo_funkcijos.h"
#include "apdorojimo_funkcijos.h"
#include "spausdinimo_funkcijos.h"

int sugeneruoti_lyti() {
    int lytis = rand() % 2;
    return lytis;
}
string sugeneruoti_varda(int lytis) {

    string vyru_vardai[10] = {"Antanas", "Giedrius", "Adomas", "Arturas", "Martynas", "Valentinas", "Tomas", "Armandas", "Andrius", "Dovydas"};
    string moteru_vardai[10] = {"Austeja", "Auguste", "Otilija", "Greta", "Dovile", "Anastasija", "Sabina", "Emilija", "Agne", "Ieva"};
    int pasirinkimas = rand() % 10;
    if (lytis == 1) return vyru_vardai[pasirinkimas];
    else return moteru_vardai[pasirinkimas];
}

string sugeneruoti_pavarde(int lytis) {

    string vyru_pavardes[10] = {"Jokubauskas", "Petrauskas", "Giedrikas", "Slabada", "Siesikas", "Povilaitis", "Katulis", "Kavaliauskas", "Sabaliauskas", "Karalaitis"};
    string moteru_pavardes[10] = {"Jokubauskaite", "Petrasiunaite", "Korolkova", "Vdovenko", "Povilaityte", "Kavaliauskaite", "Sabaliauskaite", "Zinkeviciute", "Sapitaviciute", "Geleziute"};
    int pasirinkimas = rand() % 10;

    if (lytis == 1) return vyru_pavardes[pasirinkimas];
    else return moteru_pavardes[pasirinkimas];
}
void ivedimas_ranka(Stud& laik, int& sum) {
    int i = 0;
    int atsisk_paz;

    while (true) {

        try {
        cout << "Įveskite studento vardą: ";
        cin >> laik.var;
        if (cin.fail()) throw std::runtime_error("Netinkamas vardo įvedimas. Bandykite vėl.");

        cout << "Įveskite studento pavardę: ";
        cin >> laik.pav;
        if (cin.fail()) throw std::runtime_error("Netinkamas pavardės įvedimas. Bandykite vėl.");

        while(true){
            cout << "Įveskite " << i + 1 << "-ą atsiskaitymo pažymį (Arba, jei baigėte pažymių įvedimą, įveskite -1): ";
            i++;
            cin >> atsisk_paz;
            if (cin.fail() || (atsisk_paz < 0 && atsisk_paz != -1)) throw std::runtime_error("Netinkamas pažymio įvedimas. Bandykite vėl.");

            if (atsisk_paz == -1) break;
            sum += atsisk_paz;
            laik.paz.push_back(atsisk_paz);
        }

        cout << "Įveskite egzamino įvertinimą: ";
        cin >> laik.egz;
        if (cin.fail() || laik.egz < 0 || laik.egz > 10) throw std::runtime_error("Netinkamas egzamino įvedimas. Bandykite vėl.");
        break;
        }

        catch(const std::exception &e) {
            std::cerr << e.what() << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            laik.paz.clear();
            sum = 0;
            i = 0;
        }

    }
}

void ivedimas_pazymiu_generavimu(Stud& laik, int& sum) {
    int paz_sk, pazymys;

    while(true) {
        try {
        cout << "Įveskite studento vardą: ";
        cin >> laik.var;
        if (cin.fail()) throw std::runtime_error("Netinkamas vardo įvedimas. Bandykite vėl.");
        cout << "Įveskite studento pavardę: ";
        cin >> laik.pav;
        if (cin.fail()) throw std::runtime_error("Netinkamas pavardės įvedimas. Bandykite vėl.");
        
        cout << "Kiek pažymiu sugeneruoti šiam studentui? ";
        cin >> paz_sk;
        if (cin.fail() || paz_sk < 0 || paz_sk > 10) throw std::runtime_error("Netinkamas pažymių skaičiaus įvedimas. Bandykite vėl.");

        for (int i = 0; i < paz_sk; i++) {
            pazymys = rand() % 10 + 1;
            laik.paz.push_back(pazymys);
            sum += pazymys;
            cout << i + 1 << " pažymys: " << laik.paz.at(i) << endl;
        }

        laik.egz = rand() % 10 + 1;
        cout << "Egzamino įvertinimas: " << laik.egz << endl;
        break;
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        laik.paz.clear();
        sum = 0;
    }
    }
}

void ivedimas_generuojant_viska(Stud& laik, int& sum, int lytis) {
    int paz_sk, pazymys;
    laik.var = sugeneruoti_varda(lytis);
    laik.pav = sugeneruoti_pavarde(lytis);
    cout << "Vardas - " << laik.var << endl;
    cout << "Pavardė - " << laik.pav << endl;
    
    while(true) {
        try{
            cout << "Kiek pažymiu sugeneruoti šiam studentui? ";
            cin >> paz_sk;
            if (cin.fail() || paz_sk < 0) throw std::runtime_error("Netinkamas pažymių skaičiaus įvedimas. Bandykite įvesti jį vėl.");
            break;
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    for (int i = 0; i < paz_sk; i++) {
        pazymys = rand() % 10 + 1;
        laik.paz.push_back(pazymys);
        sum += pazymys;
        cout << i + 1 << " pažymys: " << laik.paz.at(i) << endl;
    }

    laik.egz = rand() % 10 + 1;
    cout << "Egzamino įvertinimas: " << laik.egz << endl;
}

void ivedimas_failu(vector <Stud> &grupe, Stud &laik, int &sum) {
    string file_name;
    const size_t buffer_size = 8192;
    vector <char> buffer(buffer_size);
    int spausdinimas;
    ifstream fd;
    bool generuoti;
    cout << "Norite naudoti ęsamą failą ar sugeneruoti naują? (0 - Naudoti esamą, 1 - Generuoti naują): " << endl;
    cin >> generuoti;

    if(generuoti) {
        int student_sk, nd_sk;
        cout << "Įveskite, kiek studentų sugeneruoti: " << endl;
        cin >> student_sk;
        cout << "Įveskite, kiek buvo namų darbų atsiskaitymų: " << endl;
        cin >> nd_sk;

        string failo_pav = "studentai" + std::to_string(student_sk) + ".txt";

        ofstream fr;
        fr.open(failo_pav);
        fr << "Test";
        fr.close();
        exit(1);

    }

    while (true) {
        cout << "Įveskite failo pavadinimą, esantį darbo aplanke, kurį norite naudoti [pavadinimas.txt]: " << endl;
        cin >> file_name;
        fd.open(file_name);
        if (!fd || fd.peek() == ifstream::traits_type::eof()){
             std::cerr << ("Klaida atidarant failą. Patikrinkite, ar failas direktyvoje ir bandykite įvesti vėl.\n");
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             cout << string(80, '-') << endl;
    }
    else break;
    
}
    
    cout << "Nuskaitomi duomenys iš failo..." << endl;
    auto start = std::chrono::high_resolution_clock::now(); 
    int nd_sk = rasti_nd_skaiciu_faile(fd);
    
    buferio_apdorojimas(grupe, laik, buffer_size, buffer, fd, sum, nd_sk);
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start;
    cout << "Užtruko: " << std::fixed << std::setprecision(2) << elapsed.count() << " s" << endl;

    cout << "Baigta! Pagal ką norėsite rūšiuoti duomenis? (1 - vardas, 2 - pavardė, 3 - galutinis balas pagal vidurkį, 4 - galutinis balas pagal medianą): " << endl;
    pasirink_rusiavimas(grupe);
    
    while(true) {
    cout << "Duomenis išvesti ekrane ar į tekstinį failą? (0 - ekrane, 1 - faile): " << endl;
    cin >> spausdinimas;
    if (cin.fail() || spausdinimas < 0 || spausdinimas > 1) {
        std::cerr << "Bloga įvestis. Bandykite vėl." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else break;
    }
    spausdinimas_kartu(grupe, spausdinimas);
    exit(0);
}