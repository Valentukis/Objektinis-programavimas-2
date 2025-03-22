#include "apdorojimo_funkcijos.h"

bool lyginti_pagal_varda(const Studentas &a, const Studentas &b) {
    return a.vardas() < b.vardas();
}

bool lyginti_pagal_pavarde(const Studentas &a, const Studentas &b) {
    return a.pavarde() < b.pavarde();
}

bool lyginti_pagal_vidurki(const Studentas &a, const Studentas &b) {
    return a.galutinis_vidurkis() > b.galutinis_vidurkis();
}

bool lyginti_pagal_mediana(const Studentas &a, const Studentas &b) {
    return a.galutinis_mediana() > b.galutinis_mediana();
}
void pasirink_rusiavimas(vector<Studentas> &grupe) {

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

    auto start = std::chrono::high_resolution_clock::now();
    if (ivestis == 1) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_varda);
    else if (ivestis == 2) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_pavarde);
    else if (ivestis == 3) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_vidurki);
    else if (ivestis == 4) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_mediana);
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

void buferio_apdorojimas(vector <Studentas> &grupe, size_t buffer_size, vector <char> &buffer, ifstream &fd, int nd_sk) {
    string line, leftover = "", chunk;
    
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
            Studentas laik(duom, nd_sk);
            grupe.emplace_back(std::move(laik)); 
        }
        
    }

    if (!leftover.empty()) {
        istringstream duom(leftover);
        Studentas laik(duom, nd_sk);
        grupe.emplace_back(std::move(laik)); 
    }
    fd.close();
}

void rusiuoti_grupemis(std::vector<Studentas> &grupe, std::vector<Studentas> &vargseliai) {
    auto start = std::chrono::high_resolution_clock::now(); 

    auto it = std::partition(grupe.begin(), grupe.end(), [](const Studentas &s) {
        return s.galutinis_vidurkis() >= 5.0;
    });

    vargseliai.assign(std::make_move_iterator(it), std::make_move_iterator(grupe.end()));
    grupe.erase(it, grupe.end());
    
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rūšiavimas į kietuolius/vargšelius užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
}

void failo_generavimas(ifstream &fd){

    int Studentasent_sk, nd_sk;
        
        cout << "Įveskite, kiek Studentasentų sugeneruoti: " << endl;
        while(true) {
            cin >> Studentasent_sk;
            if (cin.fail() || Studentasent_sk <= 0) {
                cin.clear(); // Clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cout << "Klaida! Įveskite teigiamą sveiką skaičių Studentasentams: ";
            } else break;
        }

        cout << "Įveskite, kiek buvo namų darbų atsiskaitymų: " << endl;
        while(true) {
            cin >> nd_sk;
            if (cin.fail() || nd_sk <= 0) {
                cin.clear(); // Clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cout << "Klaida! Įveskite teigiamą sveiką skaičių Studentasentams: ";
            } else break;
        }

        auto start = std::chrono::high_resolution_clock::now(); 

        string failo_pav = "Studentasentai" + std::to_string(Studentasent_sk) + ".txt";
        ofstream fr;
        fr.open(failo_pav);
        
        fr << std::left << setw(20) << "Vardas" << setw(20) << std::right << "Pavarde" << setw(15);
        for (int i = 0; i < nd_sk; i++) fr << "ND" + std::to_string(i+1) << setw(15); 
        fr << "Egzaminas" << endl;

        for (int i = 0; i < Studentasent_sk; i++) {
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