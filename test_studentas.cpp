#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "class/studentas.h"
#include <sstream>
#include <vector>

TEST_CASE("Copy constructor works", "[rule_of_five]") {
    std::vector<int> pazymiai = {8, 9, 10, 7, 6};
    int egzaminas = 9;
    Studentas a("Vardenis", "Pavardenis", pazymiai, egzaminas);
    Studentas b = a;

    REQUIRE(b.vardas() == a.vardas());
    REQUIRE(b.pavarde() == a.pavarde());
    REQUIRE(b.galutinis_vidurkis() == a.galutinis_vidurkis());
    REQUIRE(b.galutinis_mediana() == a.galutinis_mediana());
}

TEST_CASE("Move constructor works", "[rule_of_five]") {
    std::vector<int> pazymiai = {5, 6, 7, 8, 9};
    int egzaminas = 8;
    Studentas a("Vardenis", "Pavardenis", pazymiai, egzaminas);
    std::string oldName = a.vardas();
    std::string oldSurname = a.pavarde();

    Studentas c(std::move(a));

    REQUIRE(c.vardas() == oldName);
    REQUIRE(c.pavarde() == oldSurname);
}

TEST_CASE("Copy assignment works", "[rule_of_five]") {
    std::vector<int> pazymiai = {6, 7, 8, 7, 6};
    int egzaminas = 7;
    Studentas a("Vardenis", "Pavardenis", pazymiai, egzaminas);
    Studentas d;
    d = a;

    REQUIRE(d.vardas() == a.vardas());
    REQUIRE(d.pavarde() == a.pavarde());
    REQUIRE(d.galutinis_vidurkis() == a.galutinis_vidurkis());
    REQUIRE(d.galutinis_mediana() == a.galutinis_mediana());
}

TEST_CASE("Move assignment works", "[rule_of_five]") {
    std::vector<int> pazymiai = {4, 5, 6, 5, 4};
    int egzaminas = 6;
    Studentas a("Vardenis", "Pavardenis", pazymiai, egzaminas);
    std::string oldName = a.vardas();
    std::string oldSurname = a.pavarde();

    Studentas e;
    e = std::move(a);

    REQUIRE(e.vardas() == oldName);
    REQUIRE(e.pavarde() == oldSurname);
}

TEST_CASE("Destructor runs without issues", "[rule_of_five]") {
    std::vector<int> pazymiai = {7, 8, 7, 9, 8};
    int egzaminas = 8;
    Studentas* s = new Studentas("Vardenis", "Pavardenis", pazymiai, egzaminas);
    REQUIRE_NOTHROW(delete s);
}

TEST_CASE("Input operator >> works", "[io]") {
    std::stringstream ss("Vardenis Pavardenis 8");
    Studentas s;
    ss >> s;

    REQUIRE(s.vardas() == "Vardenis");
    REQUIRE(s.pavarde() == "Pavardenis");
    REQUIRE(s.egzaminas() == 8);
}

TEST_CASE("Output operator << works", "[io]") {
    std::vector<int> pazymiai = {9, 8, 10, 9, 9};
    int egzaminas = 9;
    Studentas s("Vardenis", "Pavardenis", pazymiai, egzaminas);
    std::stringstream out;
    out << s;
    std::string result = out.str();

    REQUIRE(result.find("Pavardenis") != std::string::npos);
    REQUIRE(result.find("Vardenis") != std::string::npos);
}
