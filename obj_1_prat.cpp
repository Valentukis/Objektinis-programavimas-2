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

int main(){

    srand(time(NULL));
    vector <Stud> grupe;
    int sum, atsisk_paz, medianos_poz, eiga;
    char pasirinkimas;
    int paz_sk, pazymys, lytis;
    bool spausdinimas;
    const size_t buffer_size = 8192;
    vector <char> buffer(buffer_size);

    ifstream fd("studentai1000000.txt");
    cout << "Sveiki! Padėsiu jums paskaičiuoti galutinius Jūsų studentų balus!" << endl;

   while(true) {
        Stud laik;
        sum = 0;
        int i = 0;
        lytis = rand() % 2;

        cout << "Kaip norėsite įvesti duomenis apie šį studentą? \n(1 - ranka, 2 - generuoti pažymius ir egzamino rezultatą, 3 - generuoti pažymius, egzaminą bei vardą ir pavardę, 4 - nuskaityti duomenis iš failo (visiems studentams), 5 - baigti darbą): \n";
        cin >> eiga;

        if (eiga == 1) {
            cout << "Įveskite studento vardą: ";
            cin >> laik.var;
            cout << "Įveskite studento pavardę: ";
            cin >> laik.pav;

            while(true){
            cout << "Įveskite " << i + 1 << "-ą atsiskaitymo pažymį (Arba, jei baigėte pažymių įvedimą, įveskite -1): ";
            i++;
            cin >> atsisk_paz;
            sum += atsisk_paz;
            laik.paz.push_back(atsisk_paz);
            if (atsisk_paz == -1) break;
        }

        cout << "Įveskite egzamino įvertinimą: ";
            cin >> laik.egz;
    }

        else if (eiga == 2) {
            cout << "Įveskite studento vardą: ";
            cin >> laik.var;
            cout << "Įveskite studento pavardę: ";
            cin >> laik.pav;
            
            cout << "Kiek pažymiu sugeneruoti šiam studentui? ";
            cin >> paz_sk;

            for (int i = 0; i < paz_sk; i++) {
                pazymys = rand() % 10 + 1;
                laik.paz.push_back(pazymys);
                sum += pazymys;
                cout << i + 1 << " pažymys: " << laik.paz.at(i) << endl;
            }

            laik.egz = rand() % 10 + 1;
            cout << "Egzamino įvertinimas: " << laik.egz << endl;

        }

        else if (eiga == 3) {
            laik.var = sugeneruoti_varda(lytis);
            laik.pav = sugeneruoti_pavarde(lytis);
            cout << "Vardas - " << laik.var << endl;
            cout << "Pavardė - " << laik.pav << endl;
            
            cout << "Kiek pažymiu sugeneruoti šiam studentui? ";
            cin >> paz_sk;

            for (int i = 0; i < paz_sk; i++) {
                pazymys = rand() % 10 + 1;
                laik.paz.push_back(pazymys);
                sum += pazymys;
                cout << i + 1 << " pažymys: " << laik.paz.at(i) << endl;
            }

            laik.egz = rand() % 10 + 1;
            cout << "Egzamino įvertinimas: " << laik.egz << endl;

        }

        else if (eiga == 4) {
            int a;
            string line, leftover = "", word, chunk;
            int nd_sk = 0;

            getline(fd, line);
            istringstream pirma_eilute(line);

            while (pirma_eilute >> word) nd_sk++;
            nd_sk -= 3; //atimti varda, pavarde, egz


            while(fd.read(buffer.data(), buffer_size) || fd.gcount() ) {
                chunk = leftover + string(buffer.data(), fd.gcount());
                size_t last_new_line = chunk.rfind('\n');

                if (last_new_line != string::npos) {
                    leftover = chunk.substr(last_new_line + 1);
                    chunk = chunk.substr(0, last_new_line);
                }

                else {
                    leftover = "";
                }

                istringstream stream(chunk);

                while (std::getline(stream, line)) {
                    istringstream duom(line);
                    duom >> laik.var >> laik.pav;
                    for (int i = 0; i < nd_sk; i++) {
                        duom >> a;
                        laik.paz.push_back(a);

                    }
                    duom >> laik.egz;
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
                        laik.galutinis_pagal_vid = (0.4 * laik.vidurkis + 0.6 * laik.egz);
                        laik.galutinis_pagal_med = (0.4 * laik.mediana + 0.6 * laik.egz);
                        grupe.emplace_back(std::move(laik)); //Pagrindas opttimizacijos
                        cout << laik.var << " " << laik.pav << endl;
                }
                
            }

            fd.close();

            cout << "Pagal ką norėsite rūšiuoti duomenis? (1 - vardas, 2 - pavardė, 3 - galutinis balas pagal vidurkį, 4 - galutinis balas pagal medianą): " << endl;
            cin >> a;
            cout << "Duomenis išvesti ekrane ar į tekstinį failą? (0 - ekrane, 1 - faile): " << endl;
            cin >> spausdinimas;

            if (a == 1) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_varda);
            else if (a == 2) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_pavarde);
            else if (a == 3) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_vidurki);
            else if (a == 4) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_mediana);
            
            if (spausdinimas) {
                std::ofstream fr("rez.txt");
                fr << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << " Galutinis (Vid.)" << setw(20) << " Galutinis (Med.)" << endl;
                fr << string(76, '-') << endl;
                for (auto n: grupe) {
                    n.galutinis = (pasirinkimas == 'V') ? (0.4 * n.vidurkis + 0.6 * n.egz) : (0.4 * n.mediana + 0.6 * n.egz);
                    fr << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << (0.4 * n.vidurkis + 0.6 * n.egz) << setw(20) << (0.4 * n.mediana + 0.6 * n.egz) << endl;
                    }
                    grupe.clear();
                    fr.close();
                    return 0;
            }
            
            else {

            
            cout << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << " Galutinis (Vid.)" << setw(20) << " Galutinis (Med.)" << endl;
            cout << string(76, '-') << endl;
            for (auto n: grupe) {
                n.galutinis = (pasirinkimas == 'V') ? (0.4 * n.vidurkis + 0.6 * n.egz) : (0.4 * n.mediana + 0.6 * n.egz);
                cout << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << (0.4 * n.vidurkis + 0.6 * n.egz) << setw(20) << (0.4 * n.mediana + 0.6 * n.egz) << endl;
                }
                grupe.clear();
                return 0;
            }
        }

        
        else if (eiga == 5) break;
        else {
            cout << "Bloga įvestis! Bandykite dar kartą" << endl;
            continue;
        }
        

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
        
        grupe.push_back(laik);
        cout << string(56, '-') << endl;
    }

    cout << "Įvedimas baigtas! Norite skaičiuoti galutinį įvertinimą su studentų pažymių vidurkiais ar medianomis? [V/M]" << endl;
    cin >> pasirinkimas;

    cout << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << ( (pasirinkimas == 'V') ? " Galutinis (Vid.)" : " Galutinis (Med.)" ) << endl;
    cout << string(56, '-') << endl;
    for (auto n: grupe) {
        n.galutinis = (pasirinkimas == 'V') ? (0.4 * n.vidurkis + 0.6 * n.egz) : (0.4 * n.mediana + 0.6 * n.egz);
        cout << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << n.galutinis << endl;
        }
        grupe.clear();
}

