#include <ios>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

// Funkcii za sortiranje
// cmp = komparacija pomegu 2 parovi vo covid mapata
bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b) { return a.second < b.second; }
// sort = funkcija koja gi stava site pparovi vo mapata vo vektor od parovi i go sortira vektorot.
std::vector< std::pair<std::string, int> > sort(std::map<std::string, int>& M) {
    std::vector< std::pair<std::string, int> > A;
    for (auto& it : M) A.push_back(it);

    sort(A.begin(), A.end(), cmp);

    std::cout << std::endl;
    for (auto& it : A) std::cout << "{ " << it.first << ", " << it.second << " }" << std::endl;
    std::cout << std::endl;

    return A;
}

// Procedura za vnesuvanje na podatoci
void vnesi_gradovi(std::map<std::string, int>& M) {
    // user choice - 1 / 2
    // 1 = Vnesi nov grad
    // 2 = Kraj na vnesuvanje
    int c = 2;
    while (true) {
        std::cout << "Izberete opcija:" << std::endl;
        std::cout << "1. Iskoristi gotovi podatoci." << std::endl;
        std::cout << "2. Vnesi podatoci." << std::endl;
        std::cout << "3. Kraj na vnesuvanje." << std::endl;
        std::cin >> c;
        if (c == 1) {
            M["Skopje"] = 28;
            M["Bitola"] = 1;
            M["Prilep"] = 1;
            M["Veles"] = 1;
            M["Kumanovo"] = 1;
            break;
        }
        if (c == 3) break;

        std::string grad;
        std::cout << "Vnesi ime na grad: ";
        std::cin >> grad;

        int zarazeni;
        std::cout << "Vnesi broj na zarazeni: ";
        std::cin >>  zarazeni;

        M[grad] = zarazeni;
    }
}

// Struktura student
struct student {
    std::string ime;
    std::string prezime;
    std::string nasoka;
    int br_index;
    int dat_rag;
};

int main() {
    // Deklaracija na COVID Mapa
    std::map <std::string, signed int> Covid2505;
    vnesi_gradovi(Covid2505);

    // Sortiranje i pecatenje na sortirana niza
    std::vector< std::pair<std::string, int> > sorted = sort(Covid2505);

    // Citanje na podatocite za student
    student s;
    std::cout << "Ime: "; std::cin >> s.ime;
    std::cout << "Prezime: "; std::cin >> s.prezime;
    std::cout << "Nasoka: "; std::cin >> s.nasoka;
    std::cout << "Br. Indeks: "; std::cin >> s.br_index;
    std::cout << "Datum na raganje: "; std::cin >> s.dat_rag;

    // Deklaracija na parovite index i ime_dat
    std::pair<std::string, int> index, ime_dat;
    // Inicijalizacija na index
    index.first = s.nasoka;
    index.second = s.br_index;
    // Inicijalizacija na ime_dat
    ime_dat.first = s.ime;
    ime_dat.second = s.dat_rag;

    // Dodavanje na parovite vo vektorot na sortirani gradovi
    sorted.push_back(index);
    sorted.push_back(ime_dat);

    // Pecatenje
    for (auto& it : sorted) std::cout << "{ " << it.first << ", " << it.second << " }" << std::endl;

    // Deklaracija na ofstream file
    std::string f_name = "./" + s.nasoka + std::to_string(s.br_index) + "." + s.ime + s.prezime;
    std::ofstream file;

    // Zapisuvanje vo file
    file.open(f_name, std::ios_base::app);
    for (auto& it : sorted) file << "{ " << it.first << ", " << it.second << " }" << std::endl;
    file.close();

    return 0;
}
