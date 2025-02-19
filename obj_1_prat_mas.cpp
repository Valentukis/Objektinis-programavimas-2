#include "mano_lib_mas.h"

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

int main(){

    srand(time(NULL));
    vector <Stud> grupe;
    int sum, atsisk_paz, medianos_poz, eiga;
    char pasirinkimas;
    int paz_sk, pazymys, lytis;

    cout << "Sveiki! Padėsiu jums paskaičiuoti galutinius Jūsų studentų balus!" << endl;

   while(true) {
        Stud laik;
        sum = 0;
        int i = 0;
        lytis = rand() % 2;

        cout << "Kaip norėsite įvesti duomenis apie studentus? (1 - ranka, 2 - generuoti pažymius ir egzamino rezultatą, 3 - generuoti pažymius, egzaminą bei vardus ir pavardes, 4 - baigti darbą): \n";
        cin >> eiga;

        if (eiga == 1) {
            cout << "Įveskite studento vardą: ";
            cin >> laik.var;
            cout << "Įveskite studento pavardę: ";
            cin >> laik.pav;

            while(true){
            cout << "Įveskite " << i + 1 << "-ą atsiskaitymo pažymį (Arba, jei baigėte pažymių įvedimą, įveskite -1): ";
            cin >> atsisk_paz;
            if (atsisk_paz == -1) break;
            sum += atsisk_paz;

            int* temp = new int[i+1];
            for (int j = 0; j < i; j++) {
                temp[j] = laik.paz[j];
            }
            temp[i] = atsisk_paz;
            delete[] laik.paz;
            laik.paz = temp; 

            laik.paz[i] = atsisk_paz;
            laik.paz_sk++;

            i++;
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
            laik.paz_sk = paz_sk;
            laik.paz = new int[paz_sk]; 

            for (i = 0; i < paz_sk; i++) {
                atsisk_paz = rand() % 10 + 1;
                laik.paz[i] = atsisk_paz;
                sum += atsisk_paz;
                cout << i+1 << " pažymys: " << laik.paz[i] << endl;
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
            laik.paz_sk = paz_sk;
            laik.paz = new int[paz_sk]; 

            for (i = 0; i < paz_sk; i++) {
                atsisk_paz = rand() % 10 + 1;
                laik.paz[i] = atsisk_paz;
                sum += atsisk_paz;
                cout << i+1 << " pažymys: " << laik.paz[i] << endl;
            }

            laik.egz = rand() % 10 + 1;
            cout << "Egzamino įvertinimas: " << laik.egz << endl;

        }

        else if (eiga == 4) break;
        else {
            cout << "Bloga įvestis! Bandykite dar kartą" << endl;
            continue;
        }


        laik.vidurkis = double(sum) / i;

        sort(laik.paz, laik.paz + i);

        if (i % 2 == 0) {
            medianos_poz = i / 2;
            laik.mediana = ( laik.paz[medianos_poz] + laik.paz[medianos_poz - 1] ) / 2.0;
        }
        else {
            medianos_poz = floor(i / 2);
            laik.mediana = laik.paz[medianos_poz];
        }

        grupe.push_back(laik);
        cout << string(56, '-') << endl;
    }

    cout << "Įvedimas baigtas! Norite skaičiuoti galutinį įvertinimą su studentų pažymių vidurkiais ar medianomis? [V/M]" << endl;
    cin >> pasirinkimas;

    cout << std::left << setw(20) << "Pavardė " << setw(20) << " Vardas" << setw(20) << ( (pasirinkimas == 'V') ? " Galutinis (Vid.)" : " Galutinis (Med.)" ) << endl;
    cout << string(56, '-') << endl;
    for (auto n: grupe) {
        n.galutinis = (pasirinkimas == 'V') ? (0.4 * n.vidurkis + 0.6 * n.egz) : (0.4 * n.mediana + 0.6 * n.egz);
        cout << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << n.galutinis << endl;
        }

    for (auto n: grupe) {
        delete[] n.paz;
    }
    grupe.clear();
}


