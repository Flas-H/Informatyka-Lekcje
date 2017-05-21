#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int iloscHaselNumerycznych(string hasla[200]);
void iloscHaselUzytychDwaRazy(string hasla[200], fstream& wynik);
int czteryZnaki(string hasla[200]); // hasla zawierajace cztery kolejne znaki ascii
int _75_4(string hasla[200]);

int main(int argc, char **argv)
{
    
    fstream dane;
    fstream wynik;
    
    dane.open("Hasla.txt", ios::in);
    wynik.open("wyniki_hasla.txt", ios::out | ios::trunc);
    
    if(dane.good() && wynik.good()){
        
        string hasla[200];
        
        for(int i = 0; i < 200; i++){
            getline(dane, hasla[i]);
        }
        dane.close();
        
        wynik << "74.1 " << iloscHaselNumerycznych(hasla) << endl;
        //cout << iloscHaselNumerycznych(hasla);
        
        iloscHaselUzytychDwaRazy(hasla, wynik);
        
        wynik << "74.3 " << czteryZnaki(hasla) << endl;
        //cout << czteryZnaki(hasla);
        
        wynik << "74.5 " << _75_4(hasla) << endl;
        cout << czteryZnaki(hasla);
    }
    
    dane.close();
    wynik.close();
    
    return 0;
}

int iloscHaselNumerycznych(string hasla[200]){
    
    int ilosc = 0;
    
    for(int i = 0; i < 200; i++){
        sort(hasla[i].begin(), hasla[i].end());
        if((int)hasla[i][hasla[i].length() - 1] <= 57){
            ilosc++;
            //cout << hasla[i] << endl;
        }
    }
    
    return ilosc;
}

void iloscHaselUzytychDwaRazy(string hasla[200], fstream& wynik){
    
    int ilosc = 0;
    int powtorzen = 1;
    sort(hasla, hasla + 200);
    
    wynik << "74.2" << endl;
    
    for(int i = 1; i < 200; i++){
        if(hasla[i] == hasla[i - 1]){
            powtorzen++;
        }
        else{
            if(powtorzen > 1){
                wynik << hasla[i - 1] <<endl;;
                ilosc++;
            }
            powtorzen = 1;
        }
    }
    
}

int czteryZnaki(string hasla[200]){
    
    int ilosc = 0;
    
    
    for(int i = 0; i < 200; i++){
        for(unsigned int j = 0; j < hasla[i].size() - 5; j++){
            if((int)hasla[i][j] == hasla[i][j + 1] && hasla[i][j + 1] == hasla[i][j + 2] && hasla[i][j + 2] == hasla[i][j + 3]){
                ilosc++;
                break;
            }
        }
    }
    
    return ilosc;
}

int _75_4(string hasla[200]){
    
    int ilosc = 0;
    
    for(int i = 0; i < 200; i++){
        
        bool jedenZnakNumeryczny = false;
        bool malaLitera = false;
        bool duzaLitera = false;
        
        for(unsigned int j = 0; j < hasla[i].size() - 1; j++){
            int litera = (int)hasla[i][j];
            if(litera <= 57) jedenZnakNumeryczny = true;
            else if(litera > 57 && litera <= 90) duzaLitera = true;
            else if(litera > 90 && litera <= 122) malaLitera = true;
        }
        
        if(jedenZnakNumeryczny && malaLitera && duzaLitera) ilosc++;
        
    }
    
    return ilosc;
}