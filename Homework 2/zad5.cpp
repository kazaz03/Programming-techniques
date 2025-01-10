// TP 2022/2023: Zadaća 2, Zadatak 5
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <new>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename Tip1, typename Tip2>
auto **KreirajTablicuSabiranja(Tip1 it1, Tip1 it2, Tip2 it3) {
  using tip_matrice =
      typename std::remove_reference<decltype(*it1 + *it3)>::type;
  int br_red = 0;
  auto poc1 = it1;
  tip_matrice **mat = nullptr;
  int br_el = 0, j = 1;
  try {
    br_red = std::distance(it1, it2);
    mat = new tip_matrice *[br_red] {};
    int i = 0;
    br_el=(br_red*(br_red+1))/2;
  } catch (...) {
    delete[] mat;
    throw std::range_error("Nema dovoljno memorije!");
  }
  try {
    mat[0] = new tip_matrice[br_el]{};
    j = 1;
    for (int i = 1; i < br_red; i++) {
      mat[i] = mat[i - 1] + j;
      j++;
    }
  } catch (...) {
    delete[] mat[0];
    delete[] mat;
    throw std::range_error("Nema dovoljno memorije!");
  }
  auto poc = it1;
  auto poc2 = it3;
  int k = 0;
  j = 0;
  while (it1 != it2) {
    k = 0;
    int brojac = 0, poz = std::distance(poc, it1);
    std::vector<tip_matrice> red;
    it3 = poc2;
    while (brojac <= poz) {
      tip_matrice suma = tip_matrice();
      if (*it1 + *it3 != *it3 + *it1) {
        delete[] mat[0];
        delete[] mat;
        throw std::logic_error("Nije ispunjena pretpostavka o komutativnosti");
      }
      suma = *it1 + *it3;
      red.push_back(suma);
      it3++;
      brojac++;
    }
    for (int i = 0; i < red.size(); i++) {
      mat[j][k] = red.at(k);
      k++;
    }
    j++;
    it1++;
  }
  return mat;
}

int main() {
  try {
    int n = 0;
    std::cout << "Duzina sekvenci: ";
    std::cin >> n;
    std::cout << std::endl;
    std::cout << "Elementi prve sekvence: ";
    int i = 0;
    std::vector<double> vektor;
    std::deque<double> dek;
    while (i < n) {
      double broj;
      std::cin >> broj;
      vektor.push_back(broj);
      i++;
    }
    std::cout << std::endl;
    std::cout << "Elementi druge sekvence: ";
    i = 0;
    while (i < n) {
      double broj;
      std::cin >> broj;
      dek.push_back(broj);
      i++;
    }
    std::vector<double>::iterator it1 = vektor.begin();
    std::vector<double>::iterator it2 = vektor.end();
    std::deque<double>::iterator it3 = dek.begin();
    using tip_matrice =
        typename std::remove_reference<decltype(*it1 + *it3)>::type;
    tip_matrice **matrica = nullptr;
    try {
      matrica = KreirajTablicuSabiranja(std::begin(vektor), std::end(vektor),
                                        std::begin(dek));
    } catch (...) {
      delete[] matrica[0];
      delete[] matrica;
      std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    int k = 1;
    std::cout << std::endl;
    std::cout << "Tablica sabiranja: \n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        std::cout << matrica[i][j] << " ";
      }
      std::cout << std::endl;
      k++;
    }
    delete[] matrica[0];
    delete[] matrica;
  } catch (std::range_error izuzetak) {
    std::cout << "Nema dovoljno memorije!" << std::endl;
  } catch (std::logic_error izuzetak) {
    std::cout << "Nije ispunjena pretpostavka o komutativnosti" << std::endl;
  }
  return 0;
}
