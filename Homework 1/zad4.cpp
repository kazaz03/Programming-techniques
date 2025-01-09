//TP 2022/2023: Zadaća 1, Zadatak 4
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

std::string Cenzura(std::string recenica, std::vector<std::string> vektor)
{
    std::string s=recenica;
    for(std::string& rijec: vektor)
     {
         for(char& znak: rijec)
         {
             if(!((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9')))
             throw std::logic_error ("Neispravna riječ");
         }
     }
     for(int i=0; i<recenica.length(); i++)
     {
        std::string rijec;
        int poz1=0,poz2=0;
        if((recenica.at(i)>='a' && recenica.at(i)<='z') || (recenica.at(i)>='A' && recenica.at(i)<='Z') || (recenica.at(i)>='0' && recenica.at(i)<='9'))
        {
            poz1=i;
            poz2=recenica.length();
            while(i<recenica.length() && ((recenica.at(i)>='a' && recenica.at(i)<='z') || (recenica.at(i)>='A' && recenica.at(i)<='Z') || (recenica.at(i)>='0' && recenica.at(i)<='9')))
            {
                rijec+=recenica.at(i);
                i++;
            }
            poz2=i;
        } 
        for(int j=0; j<vektor.size(); j++)
        {
            for(char& znak: vektor.at(j))
            {
                znak=std::tolower(znak);
            }
            for(char& znak: rijec)
            {
                znak=std::tolower(znak);
            }if(rijec==vektor.at(j))
            {
                for(int z=poz1; z<poz2; z++)
                s.at(z)='*';
            }
        }
     }
     return s;
}

int main ()
{
    try
    {
        std::string recenica;
        std::cout<<"Unesite recenicu: ";
        std::getline(std::cin,recenica);
        std::cout<<"Unesite zabranjene rijeci (. za kraj): ";
        std::vector<std::string> vektor;
        char znak;
        while(std::cin.peek()!='.')
        {
            std::string rijec;
            if(std::cin.peek()=='.') break;
            else
            while((znak=std::cin.get())!=' ')
            rijec+=znak;
            vektor.push_back(rijec);
        }
        std::string s=Cenzura(recenica,vektor);
        std::cout<<std::endl;
        std::cout<<"Cenzurisana recenica: ";
        std::cout<<s;
        return 0;
    }catch(const std:: logic_error& e)
    {
        std::cout<<"GRESKA: Nelegalne zabranjene rijeci!";
    }
	return 0;
}
