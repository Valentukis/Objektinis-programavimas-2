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
    int lytis_ = rand() % 2;  //0 - moteris, 1 - vyras;
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



