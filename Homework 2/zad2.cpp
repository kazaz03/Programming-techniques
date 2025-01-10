// TP 2022/2023: Zadaća 2, Zadatak 2
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

typedef std::vector<int> vektor;

bool Prost(long long int broj) {
  if (broj < 2)
    return false;
  if (broj == 2)
    return true;
  for (int i = 2; i <= std::sqrt(broj); i++) {
    if (broj % i == 0)
      return false;
  }
  return true;
}

void RastavaBroja(int broj, int &p, int &q) {
  bool negativan = false;
  if (broj < 0)
    negativan = true;
  long long int temp = std::abs(broj);
  p = 1, q = 1;
  if (broj == 0) {
    p = 0;
    q = 1;
  } else if (Prost(temp)) {
    p = broj;
    q = 1;
  } else {
    vektor v1;
    int i = 2;
    int brojac = 0;
    vektor stepen;
    while (i <= std::sqrt(temp)) {
      brojac = 0;
      while (broj % i == 0) {
        brojac++;
        broj = broj / i;
      }
      if (brojac == 1) {
        p = p * i;
      }
      if (brojac > 1) {
        stepen.push_back(brojac);
        v1.push_back(i);
      }
      i++;
    }
    if (broj != 0)
      p = p*std::abs(broj);
    vektor stepenzaq;
    for (int i = 0; i < stepen.size(); i++) {
      int temp = stepen.at(i);
      int j = 0;
      while (temp >= 2) {
        j++;
        temp = temp - 2;
      }
      stepen.at(i) = stepen.at(i) - 2 * j;
      stepenzaq.push_back(j);
    }
    for (int i = 0; i < v1.size(); i++) {
      p = p * std::pow(v1.at(i), stepen.at(i));
    }
    for (int i = 0; i < v1.size(); i++) {
      q = q * std::pow(v1.at(i), stepenzaq.at(i));
    }
    if (negativan)
      p = -p;
  }
}

int main() {
  int n = 0;
  int p = 0, q = 0;
  std::cout << "Unesi broj: ";
  std::cin >> n;
  RastavaBroja(n, p, q);
  std::cout << n << " = " << p << "*" << q << "^2";
  return 0;
}
