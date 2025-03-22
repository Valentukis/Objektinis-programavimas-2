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


