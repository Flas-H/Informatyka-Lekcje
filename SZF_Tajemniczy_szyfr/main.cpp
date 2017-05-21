#include <iostream>

using namespace std;

int main()
{

    string napis;
    string szyfrogram;
    
    int klucz;
    int ramka;
    int przerwa;
    int pozycja;
    int iter;
    
    bool r_p = true;
    
    cin >> napis >> klucz;
    
    ramka = klucz * 2;
    przerwa = -2;
    pozycja = 0;
    iter = -1;
    
    do{
        
        ramka -= 2;
        przerwa += 2;
        iter++;
        pozycja = iter;
        
        while(pozycja < napis.size()){
            
            szyfrogram += napis[pozycja];
            
            if(r_p && ramka != 0){
                pozycja += ramka;
            }
            else if(przerwa != 0){
                pozycja += przerwa;
            }
            
            r_p = -r_p;
        }
        
    }while(ramka > 0);
    
    cout << szyfrogram;
    
    return 0;
}
