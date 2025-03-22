#ifndef student_H
#define student_H

#include "mano_lib.h"

class Studentas {
    private:
        string var_, pav_;
        int lytis_;
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
        ~Studentas();
        
        void ivedimas_ranka();
        void ivedimas_pazymiu_generavimu();
        void ivedimas_generuojant_viska();
        void paskaiciuoti_vid_ir_med();
        void paskaiciuoti_gal();
        void sugeneruoti_lyti();
        void sugeneruoti_varda();
        void sugeneruoti_pavarde();

        string vardas() const { return var_; }
        string pavarde() const { return pav_; }
        double galutinis_vidurkis() const { return galutinis_pagal_vid_; }
        double galutinis_mediana() const { return galutinis_pagal_med_; }
        
};

bool lyginti_pagal_varda(const Studentas &a, const Studentas &b);
bool lyginti_pagal_pavarda(const Studentas &a, const Studentas &b);
bool lyginti_pagal_vidurki(const Studentas &a, const Studentas &b);
bool lyginti_pagal_mediana(const Studentas &a, const Studentas &b);
void pasirink_rusiavimas(vector<Studentas> &grupe);
void rusiuoti_grupemis(vector<Studentas> &grupe, vector<Studentas> &vargseliai);
#endif