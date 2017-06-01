#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

string szyfr(string napis, int klucz, bool deszyfruj = false);
void zadanie61();
void zadanie62();
void zadanie63();

int main(){
    
    zadanie61();
    zadanie62();
    zadanie63();
    
    return 0;
}

void zadanie61(){
    
    fstream dane;
    fstream wynik;
    
    dane.open("../Dane_PR2/dane_6_1.txt", ios::in);
    wynik.open("wyniki_6_1.txt", ios::out | ios::trunc);
    
    if(dane.good() && wynik.good()){
        while(!dane.eof()){
            string napis;
            int klucz = 107;
            getline(dane, napis);
            wynik << szyfr(napis, klucz) <<  endl;
        }
    }
    /*else{
        wynik << "Nie otwarto pliku" << endl;
    }*/
    
    dane.close();
    wynik.close();
    
}

void zadanie62(){
    
    fstream dane;
    fstream wynik;
    
    dane.open("../Dane_PR2/dane_6_2.txt", ios::in);
    wynik.open("wyniki_6_2.txt", ios::out | ios::trunc);
    
    if(dane.good() && wynik.good()){
        
        for(int i = 0; i < 700; i++){
            string napis;
            int klucz;
            
            dane >> napis;
            dane >> klucz;
            
            wynik << szyfr(napis, klucz, true) << endl;
        }
        
    }/*
    else{
        cout << "Nie otwarto pliku!" << endl;
    }*/
}

void zadanie63(){
    
    fstream dane;
    fstream wynik;
    
    dane.open("../Dane_PR2/dane_6_3.txt", ios::in);
    wynik.open("wyniki_6_3.txt", ios::out | ios::trunc);
    
    if(dane.good() && wynik.good()){
        
        for(int i = 0; i < 700; i++){
            
            string napis;
            string szyfrogram;
            int klucz;
            int dlugoscAlfabetu = 26;
            
            dane >> napis;
            dane >> szyfrogram;
            
            klucz = szyfrogram[1] - napis[1];
            if(klucz < 0) abs(klucz % dlugoscAlfabetu);
            
            if(szyfr(szyfrogram, klucz, true) != napis){
                wynik << napis << " " << szyfrogram << endl;
            }
            
            
        }
        
    }/*else{
        cout << "Nie otwarto pliku!" << endl;
    }*/
    
    dane.close();
    wynik.close();
    
}

string szyfr(string napis, int klucz, bool deszyfruj){
    
    string szyfrogram;
    int dlugoscAlfabetu = 26;
    klucz = klucz % dlugoscAlfabetu;
    
    if(deszyfruj){
        klucz = 26 - (klucz) % dlugoscAlfabetu;
    }
    
    for(unsigned int i = 0; i < napis.size(); i++){
        szyfrogram += 65 + (napis[i] - 65 + klucz) % dlugoscAlfabetu;
    }
    
    return szyfrogram;
}