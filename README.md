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
| Failo generavimas | < 0.1s | 0.1s | 0.4s | 3.7s | 27.0s |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.3s | 2.4s | 26.1s |
| Studentų rūšiavimas + Rezultatų spausdinimas | < 0.1s | 0.2s | 0.4s | 3.2s | 34.7s |
| Surūšiuotų studentų išvedimas į failą | < 0.1s | < 0.1s | 0.3s | 2.4s | 25.4 |
| Bendras vidutinis programos veikimo laikas | 0.1s | 0.5s | 1.4s | 11.7s | 113.2s |



**Programos veikimo pavyzdžiai**

Programos eiga:
![image](https://github.com/user-attachments/assets/e4e0503c-1cc8-41cd-a4f3-2cf71f096938)
Sugeneruotas studentų failas:
![image](https://github.com/user-attachments/assets/4dcdb3a0-c2ba-4f71-b03c-d8c6e0d37e56)
Surūšiuotų studentų failas:
![image](https://github.com/user-attachments/assets/39f13c60-4014-4706-8914-c793d66fbf98)



Kilus klausimams ar pastaboms, susisiekti el. paštu: valentinas.samatovicius@mif.stud.vu.lt
