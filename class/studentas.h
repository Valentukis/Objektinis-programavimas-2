#include "mano_lib.h"

class Studentas {
    private:
        string var_, pav_;
        vector<int> paz_;
        int egz_;
        double vidurkis_;
        double mediana_;
        double galutinis_pagal_vid_;
        double galutinis_pagal_med_;
        
    public:
        Studentas();

        Studentas(const std::string& vardas, const std::string& pavarde, 
            const std::vector<int>& paz, int egzaminas);
        
        Studentas(std::istream& is);
        
        /*FUNKCIJOS KURIAS REIKIA PAVERSTI I METHODUS:
        IS MAIN/IVEDIMO:
        IVEDIMO FUNKCIJOS APART FAILO
        
        void ivedimas_ranka(int& sum);
        void ivedimas_pazymiu_generavimu(int& sum);
        void ivedimas_generuojant_viska(int& sum, int lytis);
        
        void paskaiciuoti_vid_ir_med(Stud& laik, int sum);
        void paskaiciuoti_gal(Stud& laik);
        
        */

        
};