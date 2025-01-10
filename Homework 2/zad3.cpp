// TP 2022/2023: Zadaća 2, Zadatak 3
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename TipElemenata>
using Matrica = std::vector<std::vector<TipElemenata>>;

template <typename Tip1, typename Tip2, typename TipF, typename TipG>
auto GeneraliziraniMatricniProizvod(Matrica<Tip1> a, Matrica<Tip2> b, TipF f,
                                    TipG g) {
    bool grbavaA = false;
    bool grbavaB = false;
    for (int i = 0; i + 1 < a.size() && i < a.size(); i++) {
      if (a.at(i).size() != a.at(i + 1).size()) {
        grbavaA = true;
        break;
      }
    }
    for (int i = 0; i + 1 < b.size() && i < b.size(); i++) {
      if (b.at(i).size() != b.at(i + 1).size()) {
        grbavaB = true;
        break;
      }
    }
    if (grbavaB || grbavaA) {
      throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    int red_b = b.size();
    int kol_a = a.at(0).size();
    if (red_b != kol_a) {
      throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    using tipmatrice = typename std::remove_reference<decltype(
        g(a.at(0).at(0), b.at(0).at(0)))>::type;
    Matrica<tipmatrice> rez;
    if (red_b == 0 || kol_a == 0)
      return rez;
    int red_a = a.size();
    int kol_b = b.at(0).size();
    rez.resize(red_a);
    for (int i = 0; i < red_a; i++) {
      rez.at(i).resize(kol_b);
    }
    try {
    int k = 0;
    for (int i = 0; i < red_a; i++) {
      for (int j = 0; j < kol_b; j++) {
        tipmatrice suma = g(a.at(i).at(0), b.at(0).at(j));
        for (int k = 1; k < kol_a; k++) {
          suma = f(suma, g(a.at(i).at(k), b.at(k).at(j)));
        }
        rez.at(i).at(j) = suma;
      }
    }
    return rez;
  } catch (...) {
    throw std::runtime_error("Neocekivani problemi pri racunanju");
  }
}


int main ()
{
    try
    {
        Matrica<std::string> a,b;
        int brred1=0, brkol2=0, brkol1red2=0;
        std::cout<<"Unesite broj redova prve matrice: ";
        std::cin>>brred1;
        std::cout<<"Unesite broj kolona prve matrice, ujedno broj redova druge matrice: "; std::cin>>brkol1red2; 
        std::cout<<"Unesite broj kolona druge matrice:"; 
        std::cin>>brkol2; std::cout<<std::endl<<"Unesite elemente prve matrice:"<<std::endl; 
        a.resize(brred1, std::vector<std::string>(brkol1red2,""));
        b.resize(brkol1red2, std::vector<std::string>(brkol2,""));
        int z;
        std::cin.clear(); std::cin.ignore(1000,'\n');
        for(int i=0; i<brred1; i++)
        {
            z=0;
            std::string elementi;
            while(z<brkol1red2)
            {
                std::cin>>elementi;
                a.at(i).at(z)=elementi;
                z++;
            }
        }
        std::cout<<"Unesite elemente druge matrice: \n";
        z=0;
        for(int i=0; i<brkol1red2; i++)
        {
            z=0;
            std::string elementi;
            while(z<brkol2)
            {
                std::cin>>elementi;
                b.at(i).at(z)=elementi;
                z++;
            }
        }
        std::cout<<std::endl<<"Matricni proizvod: ";
        auto M=GeneraliziraniMatricniProizvod(a,b,
        [](std::string s1, std::string s2){return std::string(s1+"+"+s2);},
        [](std::string s1, std::string s2) {return std::string(s1+"*"+s2);});
        for(int i=0; i<M.size(); i++)
        {
            for(int j=0; j<M.at(i).size(); j++)
             std::cout<<M.at(i).at(j)<<" ";
            std::cout<<std::endl;
        }
    }catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }catch(std::runtime_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
        return 0;
}
