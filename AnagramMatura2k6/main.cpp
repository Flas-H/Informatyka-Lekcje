#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    
    ifstream dane("anagram.txt");
    ofstream wynik("odp_4a.txt");
    ofstream wynik2("odp_4b.txt");
    
    int ilosc = 0;
    
    if(dane.good() && wynik.good() && wynik2.good()){
        
        
        while(!dane.eof()){
            string linia;
            string liniaKopia;
            getline(dane, linia);
            
            liniaKopia = linia;
            sort(linia.begin(), linia.end());
            
            //---- ppkt a
            int iloscSpacji = 0;
            
            for(; linia[iloscSpacji] == ' '; iloscSpacji++);
            double iloscSlow = iloscSpacji + 1;
            double iloscLiter = linia.length() - iloscSpacji;
            double iloscLiterWSlowie = iloscLiter / iloscSlow;
            
            if(iloscLiterWSlowie == floor(iloscLiterWSlowie)){
                wynik << liniaKopia << endl;
            }
            
            //---- ppkt b
            
            int litery[123] = {0};
            bool anagram = true;
            for(int i = iloscSpacji; i < linia.length(); i++){
                litery[(int)linia[i]]++;
            }
            int j = 64; // ilosc powtorzen pierwszej litery
            for(; j < 123 && litery[j] == 0; j++);
            
            

            for(int i = j + 1; i < 123; i++){
                if(litery[i] != 0 && litery[i] != litery[j]){
                    anagram = false;
                    break;
                }
            }
            if(anagram) wynik2 << liniaKopia << endl;\
        }
    }
          
    return 0;
}
