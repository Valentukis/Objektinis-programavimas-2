#include "ivedimo_funkcijos.h"
#include "apdorojimo_funkcijos.h"
#include "spausdinimo_funkcijos.h"
#include "studentas.h"

void ivedimas_failu(vector <Studentas> &grupe) {

    const size_t buffer_size = 8192;
    vector <char> buffer(buffer_size);
    int spausdinimas, sum = 0;
    ifstream fd;
    bool generuoti;

    cout << string(80, '-') << endl;
    cout << "Norite naudoti ęsamą failą ar sugeneruoti naują? (0 - Naudoti esamą, 1 - Generuoti naują): " << endl;
    while(true) {
    cin >> generuoti;
    if (cin.fail() || (generuoti != 0 && generuoti != 1)) {
        cin.clear(); // Clear error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Klaida! Prašome įvesti 0 arba 1: ";
    }
    else break;
    }

    if(generuoti) failo_generavimas(fd);
    else failo_pav_gavimas(fd);
    
    cout << "Nuskaitomi duomenys iš failo..." << endl;
    int nd_sk = rasti_nd_skaiciu_faile(fd);
    auto start = std::chrono::high_resolution_clock::now(); 
    buferio_apdorojimas(grupe, buffer_size, buffer, fd, nd_sk);
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start;
    cout << "Baigta! Duomenų nuskaitymas užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << " s" << endl;
    cout << string(80, '-') << endl;
    
    cout << "Pagal ką norėsite rūšiuoti duomenis? (1 - vardas, 2 - pavardė, 3 - galutinis balas pagal vidurkį, 4 - galutinis balas pagal medianą): " << endl;
    pasirink_rusiavimas(grupe);

    cout << string(80, '-') << endl;
    while(true) {
    cout << "Duomenis išvesti ekrane ar į tekstinį failą? (0 - ekrane, 1 - faile): " << endl;
    cin >> spausdinimas;
    if (cin.fail() || spausdinimas < 0 || spausdinimas > 1) {
        std::cerr << "Bloga įvestis. Bandykite vėl." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else break;
    }
    spausdinimas_kartu(grupe, spausdinimas);
    cout << string(80, '-') << endl;
    cout << "Rūšiuojama į kietuolius ir varšelius..." << endl;
    ofstream varg("vargseliai"+std::to_string(grupe.size()) + ".txt");
    ofstream kiet("kietuoliai"+std::to_string(grupe.size()) + ".txt");
    vector<Studentas> kietuoliai, vargseliai;
    rusiuoti_grupemis(grupe, vargseliai);

    cout << "Išvedama į failą..." << endl;
    start = std::chrono::high_resolution_clock::now();
    for (auto n: grupe) kiet << std::left << setw(15) << n.vardas() << setw(15) << n.pavarde() << setw(15) << std::fixed << std::setprecision(2) << n.galutinis_vidurkis() << endl;
    for (auto n: vargseliai) varg << std::left << setw(15) << n.vardas() << setw(15) << n.pavarde() << setw(15) << std::fixed << std::setprecision(2) << n.galutinis_vidurkis()  << endl;

    end = std::chrono::high_resolution_clock::now(); 
    elapsed = end - start;
    cout << "Sūrušiuotų studentų išvedimas į failą užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
    cout << string(80, '-') << endl;

}