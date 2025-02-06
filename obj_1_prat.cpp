#include "mano_lib.h"

int main(){

    vector <Stud> grupe;

    for (int i = 0; i < 2; i++) {
        Stud laik;
        int atsisk_paz;
        cin >> laik.var;
        cin >> laik.pav;
        
        for (int i = 0; i < 3; i++) {
            cin >> atsisk_paz;
            laik.paz.push_back(atsisk_paz);
        }
        cin >> laik.egz;

        grupe.push_back(laik);
    }

    for (auto n: grupe) {
        cout << endl << n.var << " " << n.pav << " " << n.egz << endl;
        for (auto m: n.paz) cout << m << " ";
    }
}
