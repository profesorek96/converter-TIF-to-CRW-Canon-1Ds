#include <iostream>
#include <dirent.h>
#include <conio.h> //biblioteka z getch()
#include <cstdio>  //zmiana nazwy pliku rename

using namespace std;

void konwesja_TIF_CRW( const char * nazwa_sciezki ) {
    bool kon=0;
    int d,i;
    string nazwa;
    string rozsz;
    string staranazwa;
    string nowanazwa;
    struct dirent * plik;
    DIR * sciezka;

    if(( sciezka = opendir( nazwa_sciezki ) ) ) {
        while(( plik = readdir( sciezka ) ) ){

                nazwa=plik->d_name;
                //cout<<nazwa<<endl;
                d=nazwa.length();

                if(d>3){
                for(i=d-1;nazwa[i]!='.';i--);
                rozsz=nazwa.substr(i,d-1);

                if(rozsz==".TIF"){
                kon=1;
                cout<<"Trwa konwersja rozszezen plikow z TIF na CRW"<<endl;
                staranazwa=nazwa;
                nazwa.erase(i,d-1);
                nowanazwa=nazwa+".CRW";
                cout<<staranazwa<<" "<<nowanazwa;
                if(rename(staranazwa.c_str(), nowanazwa.c_str() )==0)cout<<" "<<"Skonwertowano"<<endl<<endl; //funkcja zmiany nazwy
                else cout<<"Blad"<<endl<<endl;
                }

                }

        }
        if(kon==0)cout<<"Program nie zanalzl plikow do skonwertowania"<<endl;
        else cout<<"Program zakonczyl konwersje rozszezen plikow"<<endl;
        closedir( sciezka );

    }
    else
        cout<<"BLAD!!! Podana sciezka moze nie istniec";


}

main( int argc, char ** argv ) {

konwesja_TIF_CRW( "." );//przeszukiwanie katalogu w ktorym jest umieszczony program
cout<<"Dziekuje za skozystaie z programu"<<endl;
cout<<"Program powstal aby ulatwic prace z aparatem Canon EOS 1DS ktory zapisuje pliki RAW w formacie TIF"<<endl;
cout<<"Krzysztof Los Hubenice 25.08.2015r."<<endl;
cout<<"Nacisnij dowolny klawisz aby zakonczyc dzialanie konwertera"<<endl;
getch();//czeka na wcisniecie klawisza

return 0;
}
//Bibliografia
//http://cpp0x.pl/artykuly/?id=53
