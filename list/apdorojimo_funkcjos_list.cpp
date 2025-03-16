#include "apdorojimo_funkcijos_list.h"

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
void pasirink_rusiavimas(list<Stud> &grupe) {

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
    
    cout << "Duomenys rūšiuojami..." << endl;
    auto start = std::chrono::high_resolution_clock::now();
    if (ivestis == 1) grupe.sort(lyginti_pagal_varda);
    else if (ivestis == 2) grupe.sort(lyginti_pagal_pavarde);
    else if (ivestis == 3) grupe.sort(lyginti_pagal_vidurki);
    else if (ivestis == 4) grupe.sort(lyginti_pagal_mediana);
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rūšiavimas pagal parinktį užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
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

void buferio_apdorojimas(list <Stud> &grupe, Stud& laik, size_t buffer_size, vector <char> &buffer, ifstream &fd, int &sum, int nd_sk) {
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

void rusiuoti_grupemis(list<Stud> &grupe, list<Stud> &kietuoliai, list<Stud> &vargseliai) {
    auto start = std::chrono::high_resolution_clock::now(); 

    for (auto n: grupe) {
        if (n.galutinis_pagal_vid >= 5.0) kietuoliai.emplace_back(std::move(n));
        else vargseliai.emplace_back(std::move(n));
    }

    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rūšiavimas į kietuolius/vargšelius užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
}

void failo_generavimas(ifstream &fd){

    int student_sk, nd_sk;
        
        cout << "Įveskite, kiek studentų sugeneruoti: " << endl;
        while(true) {
            cin >> student_sk;
            if (cin.fail() || student_sk <= 0) {
                cin.clear(); // Clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cout << "Klaida! Įveskite teigiamą sveiką skaičių studentams: ";
            } else break;
        }

        cout << "Įveskite, kiek buvo namų darbų atsiskaitymų: " << endl;
        while(true) {
            cin >> nd_sk;
            if (cin.fail() || nd_sk <= 0) {
                cin.clear(); // Clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cout << "Klaida! Įveskite teigiamą sveiką skaičių studentams: ";
            } else break;
        }

        auto start = std::chrono::high_resolution_clock::now(); 

        string failo_pav = "studentai" + std::to_string(student_sk) + ".txt";
        ofstream fr;
        fr.open(failo_pav);
        
        fr << std::left << setw(20) << "Vardas" << setw(20) << std::right << "Pavarde" << setw(15);
        for (int i = 0; i < nd_sk; i++) fr << "ND" + std::to_string(i+1) << setw(15); 
        fr << "Egzaminas" << endl;

        for (int i = 0; i < student_sk; i++) {
            fr << std::left << setw(20) << "Vardas" + std::to_string(i+1) << std::right << setw(20) << "Pavarde" + std::to_string(i+1) << setw(15);
            for (int j = 0; j < nd_sk; j++) fr << std::right << rand() % 10 + 1 << setw(15);
            fr << rand() % 10 + 1 << endl;
        }
        fr.close();
        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = end - start;
        cout << "Failas sugeneruotas per " << std::fixed << std::setprecision(1) << elapsed.count() << " sekundžių!" << endl;
        fd.open(failo_pav);
    }

void failo_pav_gavimas(ifstream &fd) {
    string file_name;
    
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
}