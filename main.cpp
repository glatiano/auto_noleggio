#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct automobile{
    string categoria;
    string marca;
    string modello;
    string colore;
    string lun, mar, mer, gio, ven, sab;
    };
int righe=0;
void contarighe(){
    string app;
    ifstream fin("auto.csv");
    if (!fin) cout<<"Errore di apertura del file";
        while (!fin.eof()){
        getline(fin, app);
        righe++;
        }
    cout<<righe;
    fin.close();
}
void richiesta(automobile autom){
    string mat[righe][11];
    int s;
    string w, app, str;
    char x=',';
    ifstream fin("auto.csv");
    if (!fin)
        cout<<"Errore di apertura del file";
    contarighe();
    while (!fin.eof()){
        for (int c=0; c<11; c++)
        {
            for (int r=0; r<righe; r++)
            {
                fin>>w;
                w.erase(remove(w.begin(),w.end(),x),w.end());
                if (w!=",")
                    mat[c][r]=w;
                cout<<mat[c][r]<<" ";
            }
            cout<<endl;
        }
    }
    fin.close();
}
int main()
{
    automobile autom;
    int s;
    do{
        cout<<"------- MENU -------"<<endl;
        cout<<"1 - Richiesta automobile"<<endl;
        cout<<"2 - Uscita";
        cout<<endl<<"Inserire il numero equivalente all' operazione da eseguire : ";
        cin>>s;
        switch(s)
        {
            case 1:
                richiesta(autom);
                break;
        }
    }while(s!=2);
}
