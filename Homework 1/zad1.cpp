//TP 2022/2023: Zadaća 1, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <array>
#include <stdexcept>

enum class TretmanNegativnih {IgnorirajZnak, Odbaci, PrijaviGresku};

typedef std::array<std::vector<long long int>,10> Matrica;

int MultiplikativniDigitalniKorijen(long long int broj, int baza)
{
    if(baza<2) throw std::domain_error ("Neispravna baza");
    long long int pretvoren=std::abs(broj);
    while(!(pretvoren>=0 && pretvoren<=baza-1))
    {
        long long int rez=1;
        long long int temp=pretvoren;
        std::vector<int> cifre;
        while(temp!=0)
        {
            cifre.push_back(temp%baza);
            temp=temp/baza;
        }
        for(int i=0; i<cifre.size(); i++)
        {
            rez=rez*cifre.at(i);
        }
        pretvoren=rez;
    }
    return pretvoren;
}

Matrica RazvrstajBrojeve(std::vector<long long int>vektor, TretmanNegativnih tretman)
{
    Matrica matrica;
    long long int broj;
    for(int i=0; i<vektor.size(); i++)
    {
        if(tretman==TretmanNegativnih::PrijaviGresku && vektor.at(i)<0)
        throw std::domain_error ("Nije predvidjeno razvrstavanje negativnih brojeva");
        if(tretman==TretmanNegativnih::Odbaci && vektor.at(i)<0)
        {
            continue;
        }
        if(tretman==TretmanNegativnih::IgnorirajZnak && vektor.at(i)<0)
        vektor.at(i)=vektor.at(i)*(-1);
        broj=MultiplikativniDigitalniKorijen(vektor.at(i),10);
        for(int j=0; j<10; j++)
        {
            if(broj==j)
            matrica.at(j).push_back(vektor.at(i));
        }
    }
    return matrica;
}

int main ()
{
    try {
    std::vector<long long int> vektor;
    Matrica matrica;
    std::cout<<"Unesite brojeve (bilo koji ne-broj oznacava kraj): ";
    long long int broj;
    while(std::cin>>broj)
    {
        if(broj<0)
        {
            std::cout<<"Nije podrzano razvrstavanje negativnih brojeva!";
            return 0;
        }
        vektor.push_back(broj);
        TretmanNegativnih znak=TretmanNegativnih::IgnorirajZnak;
        matrica=RazvrstajBrojeve(vektor, znak);
    }
    std::cout<<std::endl;
    std::cout<<"Rezultati razvrstavanja po multiplikativnom digitalnom korijenu: "<<std::endl;
    for(int i=0; i<10; i++)
    {
        if(matrica.at(i).size()!=0)
        {
            std::cout<<i<<": ";
            for(int j=0; j<matrica.at(i).size(); j++)
            {
                if(matrica.at(i).at(j)<0) matrica.at(i).at(j)=matrica.at(i).at(j)*(-1);
                std::cout<<matrica.at(i).at(j)<<" ";
            }
        }else continue;
        std::cout<<std::endl;
    }
    } catch (const std::domain_error& izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}
