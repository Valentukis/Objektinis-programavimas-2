#include "apdorojimo_funkcijos.h"

bool lyginti_pagal_varda(const Stud &a, const Stud &b) {
    return a.var < b.var;
}

bool lyginti_pagal_pavarde(const Stud &a, const Stud &b) {
    return a.pav < b.pav;
}

bool lyginti_pagal_vidurki(const Stud &a, const Stud &b) {
    return a.galutinis_pagal_vid > b.galutinis_pagal_vid;
}

bool lyginti_pagal_mediana(const Stud &a, const Stud &b) {
    return a.galutinis_pagal_med > b.galutinis_pagal_med;
}
void pasirink_rusiavimas(vector<Stud> &grupe) {

    int ivestis;

    while(true) {
        cin >> ivestis;
        if (cin.fail() || ivestis > 4 || ivestis < 1) {
            std::cerr << "Bloga įvestis! Bandykite vėl." << endl;
            cout << "Pagal ką norėsite rūšiuoti duomenis? (1 - vardas, 2 - pavardė, 3 - galutinis balas pagal vidurkį, 4 - galutinis balas pagal medianą):" << endl; 
            cin.clear();  
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        else break;
    }

    if (ivestis == 1) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_varda);
    else if (ivestis == 2) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_pavarde);
    else if (ivestis == 3) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_vidurki);
    else if (ivestis == 4) stable_sort(grupe.begin(), grupe.end(), lyginti_pagal_mediana);
}

int rasti_nd_skaiciu_faile(ifstream& fd) {
    string line, word;
    int nd_sk = 0;
    getline(fd, line);
    istringstream pirma_eilute(line);

    while (pirma_eilute >> word) nd_sk++;
    nd_sk -= 3; //atimti varda, pavarde, egz
    return nd_sk;
}

void paskaiciuoti_vid_ir_med(Stud& laik, int sum) {
    int medianos_poz;
    laik.vidurkis = double(sum) / laik.paz.size();
    sort(laik.paz.begin(), laik.paz.end());

    if (laik.paz.size() % 2 == 0) {
        medianos_poz = laik.paz.size() / 2;
        laik.mediana = ( laik.paz.at(medianos_poz) + laik.paz.at(medianos_poz - 1) ) / 2.0;
    }
    else {
        medianos_poz = floor(laik.paz.size() / 2);
        laik.mediana = laik.paz.at(medianos_poz);
    }   
}

void paskaiciuoti_gal(Stud& laik) {
    laik.galutinis_pagal_vid = (0.4 * laik.vidurkis + 0.6 * laik.egz);
    laik.galutinis_pagal_med = (0.4 * laik.mediana + 0.6 * laik.egz);
}

void buferio_apdorojimas(vector <Stud> &grupe, Stud& laik, size_t buffer_size, vector <char> &buffer, ifstream &fd, int &sum, int nd_sk, ofstream &kiet, ofstream &varg) {
    string line, leftover = "", word, chunk;
    int ivestis;
    
    while(fd.read(buffer.data(), buffer_size) || fd.gcount() ) {
        chunk = leftover + string(buffer.data(), fd.gcount());
        size_t last_new_line = chunk.rfind('\n');

        if (last_new_line != string::npos) {
            leftover = chunk.substr(last_new_line + 1);
            chunk = chunk.substr(0, last_new_line);
        }

        else leftover = "";
            
        istringstream stream(chunk);

        while (std::getline(stream, line)) {
            istringstream duom(line);
            duom >> laik.var >> laik.pav;
            for (int i = 0; i < nd_sk; i++) {
                duom >> ivestis;
                sum += ivestis; 
                laik.paz.push_back(ivestis);

            }
            duom >> laik.egz;
            paskaiciuoti_vid_ir_med(laik, sum);
            paskaiciuoti_gal(laik);
            if (laik.galutinis_pagal_vid >= 5.0) kiet << std::left << setw(15) << laik.var << setw(15) << laik.pav << setw(15) << laik.galutinis_pagal_vid << endl;
            else varg << std::left << setw(15) << laik.var << setw(15) << laik.pav << setw(15) << laik.galutinis_pagal_vid << endl;
            grupe.emplace_back(std::move(laik)); 
            laik.paz.clear();
            sum = 0;
        }
        
    }

    if (!leftover.empty()) {
        istringstream duom(leftover);
        duom >> laik.var >> laik.pav;
    
        for (int i = 0; i < nd_sk; i++) {
            duom >> ivestis;
            sum += ivestis;
            laik.paz.push_back(ivestis);
        }
        duom >> laik.egz;
    
        paskaiciuoti_vid_ir_med(laik, sum);
        paskaiciuoti_gal(laik);
        grupe.emplace_back(std::move(laik));
    }
    fd.close();
}