#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct automobile{
    string Categoria, Marca, Modello, Colore, lun, mar, mer, gio, ven, sab, dom;
    };
int righe=0;
automobile vet[20];
automobile vetd[20];
automobile appo[20];
void contarighe(){
    string app;
    ifstream fin("auto.csv");
    if (!fin) cout<<"Errore di apertura del file";
        while (!fin.eof()){
        righe++;
        fin>>vet[righe].Categoria,',';
        getline(fin,vet[righe].Marca,',');
        getline(fin,vet[righe].Modello,',');
        fin>>vet[righe].Colore,',';
        fin>>vet[righe].lun,',';
        fin>>vet[righe].mar,',';
        fin>>vet[righe].mer,',';
        fin>>vet[righe].gio,',';
        fin>>vet[righe].ven,',';
        fin>>vet[righe].sab,',';
        fin>>vet[righe].dom;
        }
    fin.close();
}
void richiesta(automobile autom){
    contarighe();
    int s=0, r=0, app[10], n=1, y=0, u=0, k=0;
    string w, ap;
    char x=',';
    ifstream sin("auto.csv");
    if (!sin)
        cout<<"Errore di apertura del file";
    cout<<"Inserire la categoria dell'auto : ";
    cin>>autom.Categoria;
    do{
        cout<<"Inserire i giorni in cui serve l'auto \n(lun=1, mar=2, mer=3, gio=4, ven=5, sab=6, dom=7, exit=8) : ";
        cin>>n;
        n=n+3;
        app[y]=n;
        y++;
    }while (n!=11);
    cout<<"Le auto disponibili sono : "<<endl;
    while (!sin.eof()){
        sin>>w;
        w.erase(remove(w.begin(),w.end(),x),w.end());
        if(w == autom.Categoria)
        {
            appo[r].Categoria=w;
            sin>>appo[r].Marca,',';
            getline(sin,appo[r].Modello,',');
            getline(sin,appo[r].Colore,',');
            switch (app[s]){
            case 4:
                sin>>ap;
                if (ap=="L,"){
                    appo[s].lun=ap;
                    u++;
                }
            break;
            case 5:
                sin>>ap;
                sin>>ap;
                if (ap=="L,"){
                    appo[s].mar=ap;
                    u++;
                }
            break;
            case 6:
               sin>>ap;
               sin>>ap;
               sin>>ap;
                if (ap=="L,"){
                    appo[s].mer=ap;
                    u++;
                }
            break;
            case 7:
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                if (ap=="L,"){
                    appo[s].gio=ap;
                    u++;
                }
            break;
            case 8:
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                if (ap=="L,"){
                    appo[s].ven=ap;
                    u++;
                }
            break;
            case 9:
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                if (ap=="L,"){
                    appo[s].sab=ap;
                    u++;
                }
            break;
            case 10:
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                sin>>ap;
                if (ap=="L"){
                    appo[s].dom=ap;
                    u++;
                }
            break;

            s++;
            }
            if (u==y-1)
            {
                vetd[r].Categoria=appo[s].Categoria;
                vetd[r].Marca=appo[s].Marca;
                vetd[r].Modello=appo[s].Modello;
                vetd[r].Colore=appo[s].Colore;
                vetd[r].lun=appo[s].lun;
                vetd[r].mar=appo[s].mar;
                vetd[r].mer=appo[s].mer;
                vetd[r].gio=appo[s].gio;
                vetd[r].ven=appo[s].ven;
                vetd[r].sab=appo[s].sab;
                vetd[r].dom=appo[s].dom;
                cout<<k+1<<"-";
                cout<<appo[r].Categoria<<", ";
                cout<<appo[r].Marca<<" ";
                cout<<appo[r].Modello<<", ";
                cout<<appo[r].Colore<<" ";
                cout<<endl;
                y++;
                k++;
            }
            r++;
        }
    }
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
