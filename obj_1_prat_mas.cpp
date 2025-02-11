#include "mano_lib_mas.h"

int main(){

    srand(time(NULL));
    vector <Stud> grupe;
    int sum, atsisk_paz, medianos_poz, n, m;
    char pasirinkimas;
    bool testi = true;
    bool egz_generavimas = false, paz_generavimas = true;
    int paz_sk, pazymys;

    cout << "Sveiki! Padėsiu jums paskaičiuoti galutinius Jūsų studentožų balus!" << endl;

   while(testi) {
        Stud laik;
        sum = 0;
        int i = 0;

        cout << "Ar norite šiam studentui generuoti egzamino pažymį atsitiktinai? (0 - Ne, 1 - Taip): " << endl;
        cin >> egz_generavimas;
        cout << "Ar norite šiam studentui generuoti atsiskaitymu pažymius atsitiktinai (0 - Ne, 1 - Taip): " << endl;
        cin >> paz_generavimas;
        if (paz_generavimas) {
            cout << "Kiek pažymiu sugeneruoti šiam studentui? ";
            cin >> paz_sk;
            laik.paz_sk = paz_sk;
            //laik.paz = new int[paz_sk]; 
            laik.paz = (int*)malloc(paz_sk * sizeof(int)); 

            for (i = 0; i < paz_sk; i++) {
                atsisk_paz = rand() % 10 + 1;
                laik.paz[i] = atsisk_paz;
                sum += atsisk_paz;
                cout << i+1 << " pažymys: " << laik.paz[i] << endl;
            }

        }

        if (!egz_generavimas) {
            cout << "Įveskite egzamino įvertinimą: ";
            cin >> laik.egz;
        }
        else {
            laik.egz = rand() % 10 + 1;
            cout << "Egzamino įvertinimas: " << laik.egz << endl;
        }

        cout << "Įveskite studento vardą: ";
        cin >> laik.var;
        cout << "Įveskite studento pavardę: ";
        cin >> laik.pav;
        
        while(testi && !paz_generavimas){
            cout << "Įveskite " << i + 1 << "-ą atsiskaitymo pažymį: ";
            cin >> atsisk_paz;
            sum += atsisk_paz;

            /* int* temp = new int[i+1];
            for (int j = 0; j < i; j++) {
                temp[j] = laik.paz[j];
            }
            temp[i] = atsisk_paz;
            delete[] laik.paz;
            // laik.paz = temp; */
            laik.paz = (int*)realloc(laik.paz, (i + 1) * sizeof(int));

            laik.paz[i] = atsisk_paz;
            laik.paz_sk++;

            i++;
            cout << "Ar norite tęsti pažymių įvedimą? (0 - Ne, 1 - Taip): ";
            cin >> testi;
            if (!testi) break;

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
        cout << "Ar norite tęsti studentų įvedimą? (0 - Ne, 1 - taip): ";
        cin >> testi;
        cout << string(56, '-') << endl;
        if(!testi) break;
    }

    cout << "Įvedimas baigtas! Norite skaičiuoti galutinį įvertinimą su studentų pažymių vidurkiais ar medianomis? [V/M]" << endl;
    cin >> pasirinkimas;

    cout << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << ( (pasirinkimas == 'V') ? " Galutinis (Vid.)" : " Galutinis (Med.)" ) << endl;
    cout << string(56, '-') << endl;
    for (auto n: grupe) {
        n.galutinis = (pasirinkimas == 'V') ? (0.4 * n.vidurkis + 0.6 * n.egz) : (0.4 * n.mediana + 0.6 * n.egz);
        cout << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << n.galutinis << endl;
        }

    for (auto n: grupe) {
        //delete[] n.paz;
        free(n.paz);
    }
    grupe.clear();
}