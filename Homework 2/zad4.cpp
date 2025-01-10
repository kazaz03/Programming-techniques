// TP 2022/2023: Zadaća 2, Zadatak 4
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename TipElemenata>
using Matrica = std::vector<std::vector<TipElemenata>>;

template <typename TipElemenata> using vektor = std::vector<TipElemenata>;

template <typename Tip> void Unos(Matrica<Tip> &matrica) {
  Tip element;
  while (true) {
    vektor<Tip> v;
    while (true) {
      std::cin >> element;
      if (!std::cin) {
        std::cin.clear();
        std::cin.ignore();
        break;
      }
      v.push_back(element);
    }
    if (v.size() == 0)
      break;
    matrica.push_back(v);
  }
}

template <typename Tip>
bool Kriterij(vektor<Tip> red1, vektor<Tip> red2) {
  if (red1.size() == 0 || red2.size() == 0) return false;
    auto it1 = red1.begin();
    auto it3 = red2.begin();
    Tip p1 = *it1, p2 = *it3;
    for (auto i = red1.begin() + 1; i != red1.end(); i++) {
      p1 = p1 * (*i);
    }
    for (auto i = red2.begin() + 1; i != red2.end(); i++) {
      p2 = p2 * (*i);
    }
    if (p1 != p2) return p1<p2;
    return red1<red2;
}

template <typename Tip> void SortirajPoProizvoduRedova(Matrica<Tip> &matrica) {
  std::sort(matrica.begin(), matrica.end(), Kriterij<Tip>);
}


int main ()
{
    Matrica <int> matrica;
    std::cout<<"Unesi elemente (* za kraj reda, * na pocetku reda za kraj unosa): "<<std::endl; 
    Unos(matrica); 
    SortirajPoProizvoduRedova(matrica);
    std::cout<<"Matrica nakon sortiranja: "<<std::endl;
    for(int i=0; i<matrica.size(); i++)
    {
        for(int j=0; j<matrica.at(i).size(); j++)
           std::cout<<matrica.at(i).at(j)<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Unesite elemente sekvence koja se trazi (* za kraj reda): ";
    vektor <int> v; int element;
    while(true)
    {
        std::cin>>element;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            break;
        }
        v.push_back(element);
    }
    std::cin.ignore();
    auto m1=matrica.begin(); auto m2=matrica.end();
    auto p=std::lower_bound(m1,m2,v,Kriterij<int>);
    std::cout<<std::endl;
    if(*p!=v || p==m2)
    {
        std::cout<<"Trazena sekvenca se ne nalazi u matrici";
    }
    else{
     std::cout<<"Trazena sekvenca se nalazi u "<<p-m1+1<<". redu (nakon sortiranja)";
    }
        return 0;
}
