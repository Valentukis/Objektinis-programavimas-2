#ifndef APDOROJIMO_H
#define APDOROJIMO_H

#include "mano_lib.h"
#include "Studentas.h"

bool lyginti_pagal_varda(const Studentas &a, const Studentas &b);
bool lyginti_pagal_pavarda(const Studentas &a, const Studentas &b);
bool lyginti_pagal_vidurki(const Studentas &a, const Studentas &b);
bool lyginti_pagal_mediana(const Studentas &a, const Studentas &b);
void pasirink_rusiavimas(vector<Studentas> &grupe);
int rasti_nd_skaiciu_faile(ifstream& fd);
void paskaiciuoti_vid_ir_med(Studentas& laik, int sum);
void paskaiciuoti_gal(Studentas& laik);
void buferio_apdorojimas(vector <Studentas> &grupe, size_t buffer_size, vector <char> &buffer, ifstream &fd, int nd_sk);
void rusiuoti_grupemis(vector<Studentas> &grupe, vector<Studentas> &vargseliai);
void failo_generavimas(ifstream &fd);
void failo_pav_gavimas(ifstream &fd);
#endif