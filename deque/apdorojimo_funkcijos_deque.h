#ifndef APDOROJIMO_H
#define APDOROJIMO_H

#include <windows.h>
#include <psapi.h>
#include "mano_lib_deque.h"
bool lyginti_pagal_varda(const Stud &a, const Stud &b);
bool lyginti_pagal_pavarda(const Stud &a, const Stud &b);
bool lyginti_pagal_vidurki(const Stud &a, const Stud &b);
bool lyginti_pagal_mediana(const Stud &a, const Stud &b);
void pasirink_rusiavimas(deque<Stud> &grupe);
int rasti_nd_skaiciu_faile(ifstream& fd);
void paskaiciuoti_vid_ir_med(Stud& laik, int sum);
void paskaiciuoti_gal(Stud& laik);
void buferio_apdorojimas(deque <Stud> &grupe, Stud& laik, size_t buffer_size, vector <char> &buffer, ifstream &fd, int &sum, int nd_sk);
void rusiuoti_grupemis(deque<Stud> &grupe, deque<Stud> &kietuoliai, deque<Stud> &vargseliai);
void failo_generavimas(ifstream &fd);
void failo_pav_gavimas(ifstream &fd);
SIZE_T getMemoryUsage()
#endif
