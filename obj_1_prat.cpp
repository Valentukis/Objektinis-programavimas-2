#include "mano_lib.h"

int main(){
    srand(time(NULL));
    vector <Stud> grupe;
    int sum, atsisk_paz, medianos_poz, n, m;
    char pasirinkimas;
    bool testi = true;
    bool egz_generavimas = false, paz_generavimas = true;
    int paz_sk, pazymys;
    cout << "Sveiki! Padesiu jums paskaiciuoti galutini studento bala!" << endl;

   while(testi) {
        Stud laik;
        sum = 0;
        int i = 1;
        
        cout << "Ar norite siam studentui generuoti egzamino pazymi atsitiktinai? (0 - Ne, 1 - Taip): " << endl;
        cin >> egz_generavimas;
        cout << "Ar norite siam studentui generuoti atsiskaitymu pazymius atsitiktinai (0 - Ne, 1 - Taip): " << endl;
        cin >> paz_generavimas;
        if (paz_generavimas) {
            cout << "Kiek pazymiu sugeneruoti siam studentui? ";
            cin >> paz_sk;

            for (int i = 0; i < paz_sk; i++) {
                pazymys = rand() % 10 + 1;
                laik.paz.push_back(pazymys);
                sum += pazymys;
                cout << i + 1 << " pazymys: " << laik.paz.at(i) << endl;
            }

        }
        cout << "Iveskite studento varda: ";
        cin >> laik.var;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        
        while(testi && !paz_generavimas){
            cout << "Iveskite " << i << "-a atsiskaitymo pazymi: ";
            i++;
            cin >> atsisk_paz;
            sum += atsisk_paz;
            laik.paz.push_back(atsisk_paz);
            cout << "Ar norite testi pazymiu ivedima? (0 - Ne, 1 - taip): ";
            cin >> testi;
            if (!testi) break;
        }

        if (!egz_generavimas) {
            cout << "Iveskite egzamino ivertinima: ";
            cin >> laik.egz;
        }
        else laik.egz = rand() % 10 + 1;

        laik.vidurkis = double(sum) / laik.paz.size();

        cout << "Egzaminas - " << laik.egz << endl;
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
        cout << "Ar norite testi studentu ivedima? (0 - Ne, 1 - taip): ";
        cin >> testi;
        if(!testi) break;
    }

    cout << "Ivedimas baigtas! Norite skaiciuoti galutini bala su studentu vidurkiais ar medianomis? [V/M]" << endl;
    cin >> pasirinkimas;

    cout << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << ( (pasirinkimas == 'V') ? " Galutinis (Vid.)" : " Galutinis (Med.)" ) << endl;
    cout << string(56, '-') << endl;
    for (auto n: grupe) {
        n.galutinis = (pasirinkimas == 'V') ? (0.4 * n.vidurkis + 0.6 * n.egz) : (0.4 * n.mediana + 0.6 * n.egz);
        cout << std::left << setw(20) << n.pav << setw(20) << n.var << setw(20) << std::fixed << std::setprecision(2) << n.galutinis << endl;
        }

}

