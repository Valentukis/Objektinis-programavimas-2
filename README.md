Objektinio programavimo praktikos projektinis darbas, skirtas kaip pagalbinė priemonė destytojams vertinant studentus. Realizuota galimybė įvesti duomenis ranka, juos generuoti atsitktinai arba nuskaityti iš duomenų failo. Programa buvo kuriama per kelias versijas, palaipsniui papildant funkcionalumą ir optimizuojant veikimą.

**Kompiliavimas ir paleidimas**

Jūsų patogumui, buvo sukurtas Makefile. Atsidarę mėgstamiausią terminalą, galite naudoti šias komandas:
1. Kompiliavimas ir Link'inimas su Makefile - "make"
2. Paleidimas - "./main
3. Programos valymas (ištrina sugeneruotus .o failus ir vykdomąjį failą) - "make clean"
![image](https://github.com/user-attachments/assets/62828da6-0882-4aa0-ad46-5a02e9534382)

**Spartos analizė**

Programos efektyvumui nustatyti buvo atlikta spartos analizė. Kiekvieną įrašą sudaro 5 bandymų vidurkis. 

| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Failo generavimas | < 0.1s | < 0.1s | 0.4s | 3.7s | 27.0s |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.3s | 13.4s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.3s | 3.5s |
| Rezultatų spausdinimas | < 0.1s | < 0.1s | 0.3s | 3.4s | 29.9s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.3s | 2.7s |
| Surūšiuotų studentų išvedimas į failą | < 0.1s | < 0.1s | 0.3s | 2.8s | 25.0s |
| Bendras vidutinis programos veikimo laikas | < 0.1s | 0.1s | 0.8s | 8.1s | 74.4s |



**Programos veikimo pavyzdžiai**

Programos eiga:
![image](https://github.com/user-attachments/assets/ab721bc3-24ff-43f4-8ec0-7079ff88bb1f)
Sugeneruotas studentų failas:
![image](https://github.com/user-attachments/assets/4dcdb3a0-c2ba-4f71-b03c-d8c6e0d37e56)
Surūšiuotų studentų failas:
![image](https://github.com/user-attachments/assets/39f13c60-4014-4706-8914-c793d66fbf98)



Kilus klausimams ar pastaboms, susisiekti el. paštu: valentinas.samatovicius@mif.stud.vu.lt
