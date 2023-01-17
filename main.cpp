#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct automobile{
    string categoria;
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
    fin.close();
}
void richiesta(automobile autom){
    contarighe();
    int s=0, r=0, app[10], n=1, y=0;
    string mat[righe][11];
    string w, str[10], ap;
    char x=',';
    ifstream fin("auto.csv");
    if (!fin)
        cout<<"Errore di apertura del file";
    while (!fin.eof()){
        for (int r=0; r<righe; r++)
        {
            for (int c=0; c<11; c++)
            {
                getline(fin,mat[r][c],',');
                cout<<mat[r][c]<<" ";
            }
            cout<<endl;
        }
    }
    fin.close();
    ifstream sin("auto.csv");
    if (!sin)
        cout<<"Errore di apertura del file";
    cout<<"Inserire la categoria dell'auto : ";
    cin>>autom.categoria;
    while (n!=0){
        cout<<"Inserire i giorni in cui serve l'auto \n(lun=1, mar=2, mer=3, gio=4, ven=5, sab=6, dom=7, exit=0) : ";
        cin>>n;
        app[s]=n+3;
        s++;
        cout<<endl;
    }
    while (!sin.eof()){
            sin>>w;
            w.erase(remove(w.begin(),w.end(),x),w.end());
            if(w==autom.categoria){
            getline(sin, ap);
            str[r]= w + "," + ap;
            r++;
            }
    }
    s--;
    for (int f=0; f<s; f++)
    {
        cout<<"gg: "<<mat[2][f];
        cout<< "sono dentro";
        for (int o=app[f]; o<app[f]; o++)
        {


        if (mat[2][o]=="A")
            str[o]=str[o+1];
        else
            if (mat[2][o]=="L"){
                y++;
            }
        }
    }
    cout<<"s="<<s;
    cout<<"y="<<y;
    if (y==s)
    cout<<"L'auto "<<str[0]<<" e' stata prenotata";

    sin.close();
    cout<<endl;
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
