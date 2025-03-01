#ifndef APDOROJIMO_H
#define APDOROJIMO_H

#include "mano_lib.h"
bool lyginti_pagal_varda(const Stud &a, const Stud &b);
bool lyginti_pagal_pavarda(const Stud &a, const Stud &b);
bool lyginti_pagal_vidurki(const Stud &a, const Stud &b);
bool lyginti_pagal_mediana(const Stud &a, const Stud &b);
void pasirink_rusiavimas(vector<Stud> &grupe);
int rasti_nd_skaiciu_faile(ifstream& fd);
void paskaiciuoti_vid_ir_med(Stud& laik, int sum);
void paskaiciuoti_gal(Stud& laik);
void buferio_apdorojimas(vector <Stud> &grupe, Stud& laik, size_t buffer_size, vector <char> &buffer, ifstream &fd, int &sum, int nd_sk, ofstream &kiet, ofstream &varg);

#endif