#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

int takieSameLitery(string (&napisy)[1876]);
void czestotliwoscWystepowanieLiter(string (&napis)[1876], fstream& wynik);
void najdluzszePodSlowo(string (&napisy)[1876], fstream& wynik);

int main(int argc, char **argv)
{
    
    fstream dane;
    fstream wynik;
    
    dane.open("tekst.txt", ios::in);
    wynik.open("wyniki.txt", ios::out | ios::trunc);
    
    if(dane.good() && wynik.good()){
        
        string napisy[1876];
        
        for(int i = 0; i < 1876; i++){
            dane >> napisy[i];
        }
        
        wynik << takieSameLitery(napisy) << endl;
        //cout << takieSameLitery(napisy);
        
        czestotliwoscWystepowanieLiter(napisy, wynik);
        
        najdluzszePodSlowo(napisy, wynik);
    }
    
    dane.close();
    wynik.close();
    
    return 0;
}

int takieSameLitery(string (&napisy)[1876]){
    
    int ilosc = 0;
    
    for(int i = 0; i < 1876; i++){
        for(unsigned int j = 1; j < napisy[i].size() - 1; j++){
            if(napisy[i][j] == napisy[i][j - 1]){
                ilosc++;
                break;
            }
        }
    }
    
    return ilosc;
}

void czestotliwoscWystepowanieLiter(string (&napis)[1876], fstream& wynik){
    
    double iloscLiter[91] = {0};
    double iloscWszytskichLiter = 0;
    
    for(int i = 0; i < 1876; i++){
        for(unsigned int j = 0; j < napis[i].size() - 1; j++){
            iloscLiter[(int)napis[i][j]]++;
            if(napis[i][j] != ' ') iloscWszytskichLiter++;
        }
    }
    
    for(int i = 65; i <= 90; i++){
        wynik << (char)i << ": " << iloscLiter[i] << "(" << setprecision(3) << iloscLiter[i] / iloscWszytskichLiter * 100 << "%)" << endl;
    }
    
}

void najdluzszePodSlowo(string (&napisy)[1876], fstream& wynik){
    
    int najwiekszePodSlowo = -1;
    int dlugoscPodSlowa = 1;
    vector<string> slowa;
    
    wynik << endl;
    
    for(int i = 0; i < 1876; i++){
        for(unsigned int j = 1; j < napisy[i].size() - 1; j++){
            if((int)napisy[i][j] == (int)napisy[i][j - 1] + 1 && napisy[i][j] != 'A' && napisy[i][j] != 'E' && napisy[i][j] != 'I' && napisy[i][j] != 'O' && napisy[i][j] != 'U' && napisy[i][j] != 'Y'){
                dlugoscPodSlowa++;
            }
            else{
                if(dlugoscPodSlowa > najwiekszePodSlowo){
                    najwiekszePodSlowo = dlugoscPodSlowa;
                    slowa.clear();
                    slowa.push_back(napisy[i]);
                }
                if(dlugoscPodSlowa == najwiekszePodSlowo){
                    slowa.push_back(napisy[i]);
                }
                dlugoscPodSlowa = 1;
            }
        }
    }
    
    for(string napis : slowa){
        wynik << napis << endl;
    }
    wynik << najwiekszePodSlowo << endl;
}