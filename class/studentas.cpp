#include "studentas.h"

Studentas::Studentas() : egz_(0) {}
Studentas::Studentas(const string& vardas, const string& pavarde, const vector<int>& paz, int egzaminas) : var_(vardas), pav_(pavarde), paz_(paz), egz_(egzaminas) {}

Studentas::Studentas(std::istream& is, int sk) {
    is >> var_ >> pav_;

    int paz;
    for (int i = 0; i < sk; i++) {
        is >> paz;
        paz_.push_back(paz);
    }
    is >> egz_;

    paskaiciuoti_vid_ir_med();
    paskaiciuoti_gal();
}

Studentas::~Studentas() {
    paz_.clear();
    var_ = "";
    pav_ = "";
    egz_ = 0;
    vidurkis_ = 0;
    mediana_ = 0;
    galutinis_pagal_med_ = 0;
    galutinis_pagal_vid_ = 0;
}

void Studentas::sugeneruoti_lyti() {
    lytis_ = rand() % 2;  //0 - moteris, 1 - vyras;
}

void Studentas::sugeneruoti_varda() {
    string vyru_vardai[10] = {"Antanas", "Giedrius", "Adomas", "Arturas", "Martynas", "Valentinas", "Tomas", "Armandas", "Andrius", "Dovydas"};
    string moteru_vardai[10] = {"Austeja", "Auguste", "Otilija", "Greta", "Dovile", "Anastasija", "Sabina", "Emilija", "Agne", "Ieva"};
    int pasirinkimas = rand() % 10;
    if (lytis_ == 1) var_ = vyru_vardai[pasirinkimas];
    else var_ = moteru_vardai[pasirinkimas];
}

void Studentas::sugeneruoti_pavarde() {
    string vyru_pavardes[10] = {"Jokubauskas", "Petrauskas", "Giedrikas", "Slabada", "Siesikas", "Povilaitis", "Katulis", "Kavaliauskas", "Sabaliauskas", "Karalaitis"};
    string moteru_pavardes[10] = {"Jokubauskaite", "Petrasiunaite", "Korolkova", "Vdovenko", "Povilaityte", "Kavaliauskaite", "Sabaliauskaite", "Zinkeviciute", "Sapitaviciute", "Geleziute"};
    int pasirinkimas = rand() % 10;

    if (lytis_ == 1) pav_ = vyru_pavardes[pasirinkimas];
    else pav_ = moteru_pavardes[pasirinkimas];
}

void Studentas::ivedimas_ranka() {
    int i = 0, sum = 0;
    int atsisk_paz;

    while (true) {

        try {
        cout << "Įveskite studento vardą: ";
        cin >> var_;
        if (cin.fail()) throw std::runtime_error("Netinkamas vardo įvedimas. Bandykite vėl.");

        cout << "Įveskite studento pavardę: ";
        cin >> pav_;
        if (cin.fail()) throw std::runtime_error("Netinkamas pavardės įvedimas. Bandykite vėl.");

        while(true){
            cout << "Įveskite " << i + 1 << "-ą atsiskaitymo pažymį (Arba, jei baigėte pažymių įvedimą, įveskite -1): ";
            i++;
            cin >> atsisk_paz;
            if (cin.fail() || (atsisk_paz < 0 && atsisk_paz != -1)) throw std::runtime_error("Netinkamas pažymio įvedimas. Bandykite vėl.");

            if (atsisk_paz == -1) break;
            sum += atsisk_paz;
            paz_.push_back(atsisk_paz);
        }

        cout << "Įveskite egzamino įvertinimą: ";
        cin >> egz_;
        if (cin.fail() || egz_ < 0 || egz_ > 10) throw std::runtime_error("Netinkamas egzamino įvedimas. Bandykite vėl.");
        break;
        }

        catch(const std::exception &e) {
            std::cerr << e.what() << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            paz_.clear();
            sum = 0;
            i = 0;
        }

    }

    paskaiciuoti_vid_ir_med();
    paskaiciuoti_gal();
}

void Studentas::ivedimas_pazymiu_generavimu() {
    int paz_sk, pazymys, sum = 0;

    while(true) {
        try {
        cout << "Įveskite studento vardą: ";
        cin >> var_;
        if (cin.fail()) throw std::runtime_error("Netinkamas vardo įvedimas. Bandykite vėl.");
        cout << "Įveskite studento pavardę: ";
        cin >> pav_;
        if (cin.fail()) throw std::runtime_error("Netinkamas pavardės įvedimas. Bandykite vėl.");
        
        cout << "Kiek pažymiu sugeneruoti šiam studentui? ";
        cin >> paz_sk;
        if (cin.fail() || paz_sk < 0 || paz_sk > 10) throw std::runtime_error("Netinkamas pažymių skaičiaus įvedimas. Bandykite vėl.");

        for (int i = 0; i < paz_sk; i++) {
            pazymys = rand() % 10 + 1;
            paz_.push_back(pazymys);
            sum += pazymys;
            cout << i + 1 << " pažymys: " << paz_.at(i) << endl;
        }

        egz_ = rand() % 10 + 1;
        cout << "Egzamino įvertinimas: " << egz_ << endl;
        break;
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        paz_.clear();
        sum = 0;
    }
    }

    paskaiciuoti_vid_ir_med();
    paskaiciuoti_gal();
}

void Studentas::ivedimas_generuojant_viska() {
    sugeneruoti_lyti();
    sugeneruoti_varda();
    sugeneruoti_pavarde();

    int paz_sk, pazymys, sum = 0;

    cout << "Vardas - " << var_ << endl;
    cout << "Pavardė - " << pav_ << endl;
    
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
        paz_.push_back(pazymys);
        sum += pazymys;
        cout << i + 1 << " pažymys: " << paz_.at(i) << endl;
    }

    egz_ = rand() % 10 + 1;
    cout << "Egzamino įvertinimas: " << egz_ << endl;

    paskaiciuoti_vid_ir_med();
    paskaiciuoti_gal();
}

void Studentas::paskaiciuoti_vid_ir_med() {
    if (paz_.empty()) {
        vidurkis_ = 0;
        mediana_ = 0;
        return;
    }
    int sum = std::accumulate(paz_.begin(), paz_.end(), 0);
    int medianos_poz;
    
    vidurkis_ = double(sum) / paz_.size();
    sort(paz_.begin(), paz_.end());

    if (paz_.size() % 2 == 0) {
        medianos_poz = paz_.size() / 2;
        mediana_ = ( paz_.at(medianos_poz) + paz_.at(medianos_poz - 1) ) / 2.0;
    }
    else {
        medianos_poz = paz_.size() / 2;
        mediana_ = paz_.at(medianos_poz);
    }   

}

void Studentas::paskaiciuoti_gal() {
    galutinis_pagal_vid_ = (0.4 * vidurkis_ + 0.6 * egz_);
    galutinis_pagal_med_ = (0.4 * mediana_ + 0.6 * egz_);
}

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

