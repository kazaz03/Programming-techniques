//TP 2022/2023: Zadaća 1, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica UsrednjavajuciFilter(Matrica matrica, int N)
{
    Matrica m;
    if(N<0) throw std::domain_error ("Neispravan red filtriranja");
    m.resize(matrica.size());
    for(int i=0; i<matrica.size(); i++)
    {
        for(int j=0; j<matrica.at(i).size(); j++)
        {
            double suma=0;
            int brojac=0;
            int min_red=i-N, min_kolona=j-N, max_red=i+N,max_kolona=j+N;
            if(min_red<0) min_red=0;
            if(min_kolona<0) min_kolona=0;
            if(max_red>=matrica.size()) max_red=matrica.size()-1;
            for(int k=min_red; k<=max_red; k++)
            {
                for(int z=min_kolona; z<=max_kolona; z++)
                {
                    if(z>=0 && z<matrica.at(k).size())
                    {
                     suma=suma+matrica.at(k).at(z);
                     brojac++;
                    }
                }
            }
            double rj=suma/brojac;
            m.at(i).push_back(rj);
        }
    }
    return m;
}

int main ()
{
    try {
    Matrica matrica;
    int n=0,m=0;
    std::cout<<"Unesite broj redova i kolona matrice: ";
    std::cin>>n>>m;
    matrica.resize(n);
    for(int i=0; i<n; i++)
    {
        matrica.at(i).resize(m);
    }
    std::cout<<"Unesite elemente matrice: "<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            double broj;
            std::cin>>broj;
            matrica.at(i).at(j)=broj;
        }
    }
    int N; 
    std::cout<<"Unesite red filtriranja: ";
    std::cin>>N;
    std::cout<<std::endl;
    matrica=UsrednjavajuciFilter(matrica,N);
    std::cout<<"Matrica nakon filtriranja: "<<"\n";
    for(std::vector<double> red: matrica)
    {
        for(double broj: red)
        std::cout<<std::setw(7)<<std::fixed<<std::setprecision(2)<<broj;
        std::cout<<std::endl;
    }
    } catch (const std::domain_error& izuzetak) {
        std::cout<<"GRESKA: Neispravan red filtriranja!"<<std::endl;
    }
	return 0;
}
