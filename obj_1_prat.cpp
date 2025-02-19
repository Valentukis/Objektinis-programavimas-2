#include "mano_lib.h"
#include "ivedimo_funkcijos.h"
#include "spausdinimo_funkcijos.h"
#include "apdorojimo_funkcijos.h"

int main(){

    srand(time(NULL));
    vector <Stud> grupe;
    int eiga, lytis;
    bool testi = true;
    cout << "Sveiki! Padėsiu jums paskaičiuoti galutinius Jūsų studentų balus!" << endl;

   while(testi) {
        Stud laik;
        lytis = rand() % 2;
        int sum = 0;

        eiga = eigos_parinktis();

        switch(eiga) {
            case 1:
            ivedimas_ranka(laik, sum);
            break;

            case 2:
            ivedimas_pazymiu_generavimu(laik, sum);
            break;

            case 3:
            ivedimas_generuojant_viska(laik, sum, lytis);
            break;

            case 4:
            ivedimas_failu(grupe, laik, sum);
            break;

            case 5:
            testi = false;
            break;
        }
        
        if (eiga != 5) {
        paskaiciuoti_vid_ir_med(laik, sum);
        paskaiciuoti_gal(laik);
        grupe.push_back(laik);
        cout << string(56, '-') << endl;
        }
    }

    spausdinimas_atskiras(grupe);
}

//To do for tommorow:
//Error handling
//Delete these comments
//Seperate files
//You got this bro!