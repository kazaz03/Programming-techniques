// TP 2022/2023: Zadaća 1, Zadatak 3
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>


typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajSpiralnuMatricu(int red, int kolona, int broj, bool koja) {
  Matrica matrica;
  if (red < 0 || kolona < 0)
    return matrica;
  matrica.resize(red);
  for (int i = 0; i < red; i++)
    matrica.at(i).resize(kolona);
  int k = 0, z = 0;
  int posljednjired = red - 1, posljednjakolona = kolona - 1;
  if (koja) {
    while (k <= posljednjired && z <= posljednjakolona) {
      for (int i = z; i <= posljednjakolona; i++) {
        matrica.at(k).at(i) = broj;
        broj++;
      }
      k++;
      for (int i = k; i <= posljednjired; i++) {
        matrica.at(i).at(posljednjakolona) = broj;
        broj++;
      }
      posljednjakolona--;
      if (k <= posljednjired) {
        for (int i = posljednjakolona; i >= z; i--) {
          matrica.at(posljednjired).at(i) = broj;
          broj++;
        }
      }
      posljednjired--;
      if (z <= posljednjakolona) {
        for (int i = posljednjired; i >= k; i--) {
          matrica.at(i).at(z) = broj;
          broj++;
        }
      }
      z++;
    }
  } else if (koja == false) {
    while (k <= posljednjired && z <= posljednjakolona) {
      for (int i = k; i <= posljednjired; i++) {
        matrica.at(i).at(z) = broj;
        broj++;
      }
      z++;
      for (int i = z; i <= posljednjakolona; i++) {
        matrica.at(posljednjired).at(i) = broj;
        broj++;
      }
      posljednjired--;
      if (z <= posljednjakolona) {
        for (int i = posljednjired; i >= k; i--) {
          matrica.at(i).at(posljednjakolona) = broj;
          broj++;
        }
      }
      posljednjakolona--;
      if (k <= posljednjired) {
        for (int i = posljednjakolona; i >= z; i--) {
          matrica.at(k).at(i) = broj;
          broj++;
        }
      }
      k++;
    }
  }
  return matrica;
}

bool DaLiJeSpiralnaMatrica(Matrica matrica) {
  int red = matrica.size();
  int kolona = matrica.at(0).size();
  for (int i = 0; i < red; i++) {
    if (kolona != matrica.at(i).size())
      return false;
  }
  Matrica desna, lijeva;
  desna = KreirajSpiralnuMatricu(red, kolona, matrica.at(0).at(0), true);
  lijeva = KreirajSpiralnuMatricu(red, kolona, matrica.at(0).at(0), false);
  bool manjiodprvog=false; int prvi=matrica.at(0).at(0);
  int k = 0, z = 0, posljednjakolona = kolona - 1, posljednjired = red - 1;
  
  while (k <= posljednjired && z <= posljednjakolona) {
    for (int i = z; i <= posljednjakolona; i++) {
      if (desna.at(k).at(i)<prvi) manjiodprvog=true;
    }
    k++;
    for (int i = k; i <= posljednjired; i++) {
      if (desna.at(i).at(posljednjakolona)<prvi) manjiodprvog=true;
    }
    posljednjakolona--;
    if (k <= posljednjired) {
      for (int i = posljednjakolona; i >= z; i--) {
        if (desna.at(posljednjired).at(i)<prvi) manjiodprvog=true;
      }
    }
    posljednjired--;
    if (z <= posljednjakolona) {
      for (int i = posljednjired; i >= k; i--) {
        if (desna.at(i).at(z)<prvi) manjiodprvog=true;
      }
    }
    z++;
    if(manjiodprvog) return false;
  }
  k=0,z=0;
  posljednjakolona = kolona - 1, posljednjired = red - 1;

  while(k<=posljednjired && z<=posljednjakolona)
  {
      for(int i=k; i<=posljednjired; i++)
      {
          if(lijeva.at(i).at(z)<prvi) manjiodprvog=true;
      }
      z++;
      for(int i=z; i<=posljednjakolona; i++)
      {
          if(lijeva.at(posljednjired).at(i)<prvi) manjiodprvog=true;
      }
      posljednjired--;
      if(z<=posljednjakolona)
      {
          for(int i=posljednjired; i-1>=k && i>=k; i--)
          {
              if(lijeva.at(i).at(posljednjakolona)<prvi) manjiodprvog=true;
          }
      }
      posljednjakolona--;
      if(k<=posljednjired)
      {
          for(int i=posljednjakolona; i-1>=z && i>=z; i--)
          {
              if(lijeva.at(k).at(i)<prvi) manjiodprvog=true;
          }
      }
      k++;
      if(manjiodprvog) return false;
  }

  bool L = true, D = true;
  for (int i = 0; i < red; i++) {
    for (int j = 0; j < kolona; j++) {
      if (desna.at(i).at(j) != matrica.at(i).at(j)) {
        D = false;
        break;
      }
    }
  }
  for (int i = 0; i < red; i++) {
    for (int j = 0; j < kolona; j++) {
      if (lijeva.at(i).at(j) != matrica.at(i).at(j)) {
        L = false;
        break;
      }
    }
  }
  if (L || D)
    return true;
  else
    return false;
}

int NajvecaSirina(Matrica matrica) {
  if (matrica.size() == 0)
    return 0;
  int najveci = 0;
  for (std::vector<int> red : matrica) {
    for (int i : red) {
      int brojac = 0;
      int broj = i;
      if (broj < 0)
        brojac++;
      while (std::abs(broj) != 0) {
        broj = broj / 10;
        brojac++;
      }
      if (brojac > najveci)
        najveci = brojac;
    }
  }
  return najveci;
}

int main()
{
    int n=0,m=0,broj=0;
    std::cout<<"Unesite broj redova i kolona matrice: ";
    std::cin>>n>>m;
    std::cout<<"Unesite pocetnu vrijednost: ";
    std::cin>>broj;
    char znak;
    std::cout<<"Unesite L za lijevu, a D za desnu spiralnu matricu: ";
    std::cin>>znak;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    bool koja_je=false;
    if(znak=='D' || znak=='d') koja_je=true;
    else if(znak=='L' || znak=='l') koja_je=false;
    Matrica matrica=KreirajSpiralnuMatricu(n,m,broj,koja_je);
    int maxduzina=NajvecaSirina(matrica);
    std::cout<<"\n"<<"Kreirana spiralna matrica:"<<std::endl;
    for(int i=0; i<matrica.size(); i++)
    {
        for(int j=0; j<matrica.at(i).size(); j++)
        {
            std::cout<<std::setw(maxduzina+1)<<matrica.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
        return 0;
}
