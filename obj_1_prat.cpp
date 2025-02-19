#include "mano_lib.h"

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

bool lyginti_pagal_varda(const Stud &a, const Stud &b) {
    return a.var < b.var;
}

bool lyginti_pagal_pavarde(const Stud &a, const Stud &b) {
    return a.pav < b.pav;
}

bool lyginti_pagal_vidurki(const Stud &a, const Stud &b) {
    return a.galutinis_pagal_vid > b.galutinis_pagal_vid;
}

bool lyginti_pagal_mediana(const Stud &a, const Stud &b) {
    return a.galutinis_pagal_med > b.galutinis_pagal_med;
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

void pasirink_rusiavimas(vector<Stud> &grupe) {

    int ivestis;

    while(true) {
        cin >> ivestis;
        if (cin.fail() || ivestis > 4 || ivestis < 1) {
            std::cerr << "Bloga įvestis! Bandykite vėl." << endl;
            cout << "Pagal ką norėsite rūšiuoti duomenis? (1 - vardas, 2 - pavardė, 3 - galutinis balas pagal vidurkį, 4 - galutinis balas pagal medianą):" << endl; 
            cin.clear();  
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        else break;
    }

    if (ivestis == 1) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_varda);
    else if (ivestis == 2) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_pavarde);
    else if (ivestis == 3) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_vidurki);
    else if (ivestis == 4) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_mediana);
}

int rasti_nd_skaiciu_faile(ifstream& fd) {
    string line, word;
    int nd_sk = 0;
    getline(fd, line);
    istringstream pirma_eilute(line);

    while (pirma_eilute >> word) nd_sk++;
    nd_sk -= 3; //atimti varda, pavarde, egz
    return nd_sk;
}

void paskaiciuoti_vid_ir_med(Stud& laik, int sum) {
    int medianos_poz;
    laik.vidurkis = double(sum) / laik.paz.size();
    sort(laik.paz.begin(), laik.paz.end());

    if (laik.paz.size() % 2 == 0) {
        medianos_poz = laik.paz.size() / 2;
        laik.mediana = ( laik.paz.at(medianos_poz) + laik.paz.at(medianos_poz - 1) ) / 2.0;
    }
    else {
        medianos_poz = floor(laik.paz.size() / 2);
        laik.mediana = laik.paz.at(medianos_poz);
    }   
}

void paskaiciuoti_gal(Stud& laik) {
    laik.galutinis_pagal_vid = (0.4 * laik.vidurkis + 0.6 * laik.egz);
    laik.galutinis_pagal_med = (0.4 * laik.mediana + 0.6 * laik.egz);
}

void spausdinimas_atskiras(vector <Stud> &grupe) {
    char pasirinkimas;
    
    while(true) {
        cout << "Norite skaičiuoti galutinį įvertinimą su studentų pažymių vidurkiais ar medianomis? [V/M]" << endl;
        cin >> pasirinkimas;
        pasirinkimas = toupper(pasirinkimas);
        if (pasirinkimas != 'V' && pasirinkimas != 'M') std::cerr << "Bloga pasirinkimo įvestis. Bandykite vėl: " << endl;
        else break;
    }
    
    cout << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << ( (pasirinkimas == 'V') ? " Galutinis (Vid.)" : " Galutinis (Med.)" ) << endl;
    cout << string(56, '-') << endl;
    for (auto n: grupe) {
        cout << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << ((pasirinkimas == 'V') ? (n.galutinis_pagal_vid) : (n.galutinis_pagal_med)) << endl;
        }
        grupe.clear();
}

void spausdinimas_kartu(vector <Stud> &grupe, bool spausdinimas) {
    if (spausdinimas) {
        std::ofstream fr("rez.txt");
        cout << "Įrašoma į failą..." << endl;
        fr << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << " Galutinis (Vid.)" << setw(20) << " Galutinis (Med.)" << endl;
        fr << string(76, '-') << endl;
        for (auto n: grupe) {
            fr << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << (0.4 * n.vidurkis + 0.6 * n.egz) << setw(20) << (0.4 * n.mediana + 0.6 * n.egz) << endl;
            }
            grupe.clear();
            fr.close();
            cout << "Baigta!";
    }
    
    else {
    std::ostringstream output;
    output << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << " Galutinis (Vid.)" << setw(20) << " Galutinis (Med.)" << endl;
    output << string(76, '-') << endl;
    for (auto n: grupe) {
        output << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << (0.4 * n.vidurkis + 0.6 * n.egz) << setw(20) << (0.4 * n.mediana + 0.6 * n.egz) << endl;
        }
        grupe.clear();
        cout << output.str();
    }
}

void buferio_apdorojimas(vector <Stud> &grupe, Stud& laik, size_t buffer_size, vector <char> &buffer, ifstream &fd, int &sum, int nd_sk) {
    string line, leftover = "", word, chunk;
    int ivestis;

    while(fd.read(buffer.data(), buffer_size) || fd.gcount() ) {
        chunk = leftover + string(buffer.data(), fd.gcount());
        size_t last_new_line = chunk.rfind('\n');

        if (last_new_line != string::npos) {
            leftover = chunk.substr(last_new_line + 1);
            chunk = chunk.substr(0, last_new_line);
        }

        else leftover = "";
            
        istringstream stream(chunk);

        while (std::getline(stream, line)) {
            istringstream duom(line);
            duom >> laik.var >> laik.pav;
            for (int i = 0; i < nd_sk; i++) {
                duom >> ivestis;
                sum += ivestis; 
                laik.paz.push_back(ivestis);

            }
            duom >> laik.egz;
            paskaiciuoti_vid_ir_med(laik, sum);
            paskaiciuoti_gal(laik);
            grupe.emplace_back(std::move(laik)); 
            laik.paz.clear();
            sum = 0;
        }
        
    }

    if (!leftover.empty()) {
        istringstream duom(leftover);
        duom >> laik.var >> laik.pav;
    
        for (int i = 0; i < nd_sk; i++) {
            duom >> ivestis;
            sum += ivestis;
            laik.paz.push_back(ivestis);
        }
        duom >> laik.egz;
    
        paskaiciuoti_vid_ir_med(laik, sum);
        paskaiciuoti_gal(laik);
        grupe.emplace_back(std::move(laik));
    }
    fd.close();
}

void ivedimas_failu(vector <Stud> &grupe, Stud &laik, int &sum) {
    const size_t buffer_size = 8192;
    vector <char> buffer(buffer_size);
    int spausdinimas;
    ifstream fd;
    try {
        fd.open("studentai1000000.txt");
        if (!fd) throw std::runtime_error("Klaida atidarant failą. Patikrinkite, ar failas direktyvoje ir paleiskite programą iš naujo.");
    }
    catch(const std::exception &e) {
        std::cerr << e.what();
        exit(1);
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

int eigos_parinktis() {
    int eiga;
    while(true) {
        cout << "Kaip norėsite įvesti duomenis apie šį studentą? \n(1 - ranka, 2 - generuoti pažymius ir egzamino rezultatą, 3 - generuoti pažymius, egzaminą bei vardą ir pavardę, 4 - nuskaityti duomenis iš failo (visiems studentams), 5 - baigti darbą): \n";
        cin >> eiga;

        if(cin.fail() || eiga < 1 || eiga > 5) {
            std::cerr << "Bloga įvestis! Bandykite dar kartą" << endl;
            cout << string(56, '-') << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        else {
            break;
        }
    }
    return eiga;
}
int main(){

    srand(time(NULL));
    vector <Stud> grupe;
    int eiga, lytis;
    bool testi = true;
    cout << "Sveiki! Padėsiu jums paskaičiuoti galutinius Jūsų studentų balus!" << endl;

   while(testi) {
        Stud laik;
        lytis = rand() % 2;
        int sum = 0;

        eiga = eigos_parinktis();

        switch(eiga) {
            case 1:
            ivedimas_ranka(laik, sum);
            break;

            case 2:
            ivedimas_pazymiu_generavimu(laik, sum);
            break;

            case 3:
            ivedimas_generuojant_viska(laik, sum, lytis);
            break;

            case 4:
            ivedimas_failu(grupe, laik, sum);
            break;

            case 5:
            testi = false;
            break;
        }
        
        if (eiga != 5) {
        paskaiciuoti_vid_ir_med(laik, sum);
        paskaiciuoti_gal(laik);
        grupe.push_back(laik);
        cout << string(56, '-') << endl;
        }
    }

    spausdinimas_atskiras(grupe);
}

//To do for tommorow:
//Error handling
//Delete these comments
//Seperate files
//You got this bro!