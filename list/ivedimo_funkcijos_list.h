#ifndef IVEDIMO_H
#define IVEDIMO_H

#include "mano_lib_list.h"
#include "apdorojimo_funkcijos_list.h"
int sugeneruoti_lyti();
string sugeneruoti_varda(int lytis);
string sugeneruoti_pavarde(int lytis);
void ivedimas_ranka(Stud& laik, int& sum);
void ivedimas_pazymiu_generavimu(Stud& laik, int& sum);
void ivedimas_generuojant_viska(Stud& laik, int& sum, int lytis);
void ivedimas_failu(list <Stud> &grupe, Stud &laik, int &sum);
#endif