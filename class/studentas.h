#include "mano_lib.h"

class Studentas {
    private:
        string var_, pav_;
        int lytis;
        vector<int> paz_;
        int egz_;
        double vidurkis_;
        double mediana_;
        double galutinis_pagal_vid_;
        double galutinis_pagal_med_;
        
    public:
        Studentas();
        Studentas(const string& vardas, const string& pavarde, const vector<int>& paz, int egzaminas);
        Studentas(std::istream& is, int sk);
        
        void ivedimas_ranka();
        void ivedimas_pazymiu_generavimu();
        void ivedimas_generuojant_viska();
        void paskaiciuoti_vid_ir_med();
        void paskaiciuoti_gal();
        void sugeneruoti_lyti();

        string vardas() const { return var_; }
        string pavarde() const { return pav_; }
        double galutinisVidurkis() const { return galutinis_pagal_vid_; }
        double galutinisMediana() const { return galutinis_pagal_med_; }
        
};