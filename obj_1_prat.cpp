#include "mano_lib.h"

int main(){

    vector <Stud> grupe;
    int sum, atsisk_paz, medianos_poz;
    for (int i = 0; i < 2; i++) {
        Stud laik;
        sum = 0;
        cin >> laik.var;
        cin >> laik.pav;
        
        for (int i = 0; i < 4; i++) {
            cin >> atsisk_paz;
            sum += atsisk_paz;
            laik.paz.push_back(atsisk_paz);
        }
        cin >> laik.egz;
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
    }

    for (auto n: grupe) {
        cout << endl << n.var << " " << n.pav << " " << n.egz << " " << n.vidurkis << " " << n.mediana << endl;
        for (auto m: n.paz) cout << m << " ";
    }


}
