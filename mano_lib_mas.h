#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <random>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::endl;
using std::cin;
using std::sort;
using std::setw;
using std::vector;

const int mas_dyd = 100;

struct Stud{
    string var, pav;
    int paz[mas_dyd];
    int egz;
    double vidurkis;
    double mediana;
    double galutinis;
};