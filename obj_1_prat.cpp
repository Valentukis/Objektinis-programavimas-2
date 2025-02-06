#include "mano_lib.h"

int main(){

    vector <Stud> grupe;
    int sum, atsisk_paz;

    for (int i = 0; i < 2; i++) {
        Stud laik;
        sum = 0;
        cin >> laik.var;
        cin >> laik.pav;
        
        for (int i = 0; i < 3; i++) {
            cin >> atsisk_paz;
            sum += atsisk_paz;
            laik.paz.push_back(atsisk_paz);
        }
        cin >> laik.egz;
        laik.vidurkis = double(sum) / laik.paz.size();
        grupe.push_back(laik);
    }

    for (auto n: grupe) {
        cout << endl << n.var << " " << n.pav << " " << n.egz << " " << n.vidurkis << endl;
        for (auto m: n.paz) cout << m << " ";
    }


}
