Objektinio programavimo praktikos projektinis darbas, skirtas kaip pagalbinė priemonė destytojams vertinant studentus. Realizuota galimybė įvesti duomenis ranka, juos generuoti atsitktinai arba nuskaityti iš duomenų failo. Programa buvo kuriama per kelias versijas, palaipsniui papildant funkcionalumą ir optimizuojant veikimą.

Programos pasikeitimai tarp versijų:  
-v0.1: Pradinė programos versija, leidžianti ranka įvesti duomenis ir juos sūrušiuoti bei išvesti ekrane.  
-v0.2: Pridėta galimybė nuskaityti duomenis iš tekstinio failo.  
-v0.3: Pilnas refactoringas, pritaikomas geros programavimo praktikos.  
-v0.4: Įgyvendinta failo generavimo bei studentų skirstymo į grupes pagal pažymius funkcijos.  
-v1.0: Pilna programos versija, sutvarkytos direktyvos, patobulinta išvestis, sukurtas Makefile, realizuotos kelios versijos naudojant skirtingus konteinerius, optimizuotos senos funkcijos.  

**Įdiegimo instrukcija**

Jūsų patogumui, buvo sukurtas Makefile. Atsidarę mėgstamiausią terminalą, galite naudoti šias komandas:
1. Paleidžiamojo failo kūrimas   
  1.1 Vector realziacija - "make vector" (arba "make")   
  1.2 List realizacija - "make list"   
  1.3 Deque realizacija - "make deque"   
2. Paleidimas  
  2.1 Vector realziacija - "./vector_program"   
  2.2 List realizacija - "./list_program"   
  2.3 Deque realizacija - "./deque_program"   
3. Programos valymas (ištrina sugeneruotus vykdomuosius failus) - "make clean"

![image](https://github.com/user-attachments/assets/3dd5d1c4-d354-4ee9-97e0-7e0a875af4ed)

**Naudojimosi instrukcija**
Programa sukurta intuityviai ir aiškiai. Atsidarius programą, Jūsų bus paprašoma pasirinkti norimą įvedimo būdą. Atitinkamai po to būsite prašomi įvesti studentų informaciją arba failo, laikančius šiuos duomenis, pavadinimą. Jūsų patogumui, bus galima pasirinkti rūšiavimo ir spausdinimo būdus. Pasirinkus įvedimą failu, studentai bus skirstomi į papildomus 2 failus pagal jų vidurkį, rezultatus rasite projekto direktyvoje

**Programos veikimo pavyzdžiai**

Programos eiga:
![image](https://github.com/user-attachments/assets/ab721bc3-24ff-43f4-8ec0-7079ff88bb1f)
Sugeneruotas studentų failas:
![image](https://github.com/user-attachments/assets/4dcdb3a0-c2ba-4f71-b03c-d8c6e0d37e56)
Surūšiuotų studentų failas:
![image](https://github.com/user-attachments/assets/39f13c60-4014-4706-8914-c793d66fbf98)


**Spartos analizė**

Programos efektyvumui nustatyti buvo atlikta spartos analizė. Nuo v1.0 taip pat atlikta list ir deque analizė, palyginimui matuojamas duomenų nuskaitymo, rūšiavimo mažėjimo tvarka beiskirstymo į kategorijas laikai. Kiekvieną įrašą sudaro 5 bandymų vidurkis naudojant tuos pačius failus. Optimizavimui naudojamas 'O3' flag'as. Naudojamo kompiuterio specifikacijos:

CPU: AMD Ryzen 7840hs

Memory: 16GB LPDDR5 6400Mhz RAM

Storage: PCIe 4.0 NVMe M.2 1TB SSD

**Analizės rezultatai**
</br> 

"Vector" realizacija
| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Failo generavimas | < 0.1s | < 0.1s | 0.4s | 3.7s | 27.0s |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.3s | 16.7s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.3s | 3.9s |
| Rezultatų spausdinimas | < 0.1s | < 0.1s | 0.3s | 3.4s | 37.0s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.1s | 1.1s |
| Surūšiuotų studentų išvedimas į failą | < 0.1s | < 0.1s | 0.3s | 2.8s | 31.3s |
| Bendras vidutinis programos veikimo laikas | < 0.1s | 0.1s | 0.8s | 8.1s | 92.2s |

"List" realizacija
| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.4s | 16.6s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.6s | 14.2s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.2s | 2.8s |

"Deque" realizacija
| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.4s | 17.2s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.7s | 7.8s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.1s | 1.4s |

Atlikus analizę galima teigti, kad sparčiausiai programa veikia, naudojant vektoriaus tipo konteinerius duomenims laikyti. Su mažesniais failais skirtumas minimalus, tačiau su dideliais failais (>10000000 įrašų) vektoriai veikia greičiau už kitus, o deque yra šiek tiek greitiesnis už list'ą. 

Sekančiai daliai, bus išbandomos įvairios strategijos rūšiavimui į 2 grupes ir randamas optimaliausias variantas.  Bus matuojamas ir palyginiamas rūšiavimo laikas tarp implementacijų (nuo 100000 įrašų).

**1 Strategija**
Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius. Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų. 

"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.3s | 3.4s |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.4s | 5.1s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.3s | 4.1s |

Pastebama, kad ši strategija neoptimali, atsižvelgiant į naudojamos atminties dydį
![image](https://github.com/user-attachments/assets/56c74d1f-2a2e-41e3-8ed7-c3b029b0ee8d)

**2 Strategija**
"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | 4.2s | > 5min | > 5min |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | 0.3s| 0.2s | 2.8s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | 8.1s | > 5min | > 5min |

Pastebime, kad dabartinė strategijos implementacija labai lėta, nes naudojami metodai yra neefektyvus naudojant deque ir vector, palyginus su list. 

**3 Strategija (realizacija iki v1.0)**
Šioje strategijoje mes einame pro esamą konteinerį, ir iš jo keliame į naujus naudodami std::move. Taip yra sutaupoma atmintis ir move yra "pigesnė" operacija už kopijavimą.

"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 1.1s |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.2s | 2.8s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 1.4s |

Taigi, iš pateiktų strategijų, 3 buvo geriausia dėl žymiai efektyvesnio rušiavimo vector ir deque konteineriuose. 

**4 Strategija (realizacija iki v1.0)**
Įdėja yra sujungti originalų sprendimą su std::move ir 2 strategiją su tik vienu nauju konteineriu, pridedant efektyvius algoritmus kaip std::partition

"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 0.3s |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.4s | 3.5s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 1.1s |

Ši optimizacija geriausiai veikia su vector konteineriais dėl jo savybių, tačiau šiek tiek praverčia ir deque. Pažymėtina, kad list geriau veikia su 3 strategija, nes std::partition nėra efektyvus be random access galimybių.

Kilus klausimams ar pastaboms, susisiekti el. paštu: valentinas.samatovicius@mif.stud.vu.lt
