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
        righe++;
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
    cout<<"Inserire la categoria dell'auto da prenotare: ";
    cin>>autom.Categoria;
    cout<<"Le auto disponibili sono : "<<endl;
    while (!sin.eof()){
        sin>>w;
        w.erase(remove(w.begin(),w.end(),x),w.end());
        if(w == autom.Categoria)
        {
            cout<<"\t"<<r+1<<"-";
            appo[r].Categoria=w;
            cout<<appo[r].Categoria<<",";
            getline(sin,appo[r].Marca,',');
            cout<<appo[r].Marca<<",";
            getline(sin,appo[r].Modello,',');
            cout<<appo[r].Modello<<",";
            getline(sin,appo[r].Colore,',');
            cout<<appo[r].Colore<<",";
            getline(sin,appo[r].lun,',');
            cout<<appo[r].lun<<",";
            getline(sin,appo[r].mar,',');
            cout<<appo[r].mar<<",";
            getline(sin,appo[r].mer,',');
            cout<<appo[r].mer<<",";
            getline(sin,appo[r].gio,',');
            cout<<appo[r].gio<<",";
            getline(sin,appo[r].ven,',');
            cout<<appo[r].ven<<",";
            getline(sin,appo[r].sab,',');
            cout<<appo[r].sab<<",";
            getline(sin,appo[r].dom);
            cout<<appo[r].dom;
            cout<<endl;
            r++;
        }
    }
    cout<<"Inserire il numero dell'auto da prenotare : ";
    cin>>y;
    cout<<"L'auto scelta da te e' : ";
    cout<<appo[y-1].Categoria<<",";
    cout<<appo[y-1].Marca<<",";
    cout<<appo[y-1].Modello<<",";
    cout<<appo[y-1].Colore<<",";
    cout<<appo[y-1].lun<<",";
    cout<<appo[y-1].mar<<",";
    cout<<appo[y-1].mer<<",";
    cout<<appo[y-1].gio<<",";
    cout<<appo[y-1].ven<<",";
    cout<<appo[y-1].sab<<",";
    cout<<appo[y-1].dom<<endl;
    do{
        cout<<"Inserire i giorni in cui serve l'auto \n(lun=1, mar=2, mer=3, gio=4, ven=5, sab=6, dom=7, exit=8) : ";
        cin>>n;
        n=n+3;
        app[s]=n;
        s++;
    }while (n!=11);
    for (int g=0; g<s; g++)
    {
        switch (app[u]){
        case 4:
            if (appo[u].lun==" L"){
                appo[u].lun=" A";
                u++;
            }
            else
                if(appo[u].lun==" A")
                    k++;
                u++;
        break;
        case 5:
            if (appo[u].mar==" L"){
                appo[u].mar=" A";
                u++;
            }
            else
                if(appo[u].mar==" A")
                    k++;

        break;
        case 6:
            cout<<"appo="<<appo[u].mer<<endl;
            if (appo[u].mer==" L"){
                appo[u].mer=" A";
                cout<<"cambiamento effettuato"<<endl;
                cout<<"appo="<<appo[u].mer<<endl;
                u++;
            }
            else
                if(appo[u].mer==" A")
                    k++;
        break;
        case 7:
            if (appo[u].gio==" L"){
                appo[u].gio=" A";
                u++;
            }
            else
                if(appo[u].gio==" A")
                    k++;
        break;
        case 8:
            if (appo[u].ven==" L"){
                appo[u].ven=" A";
                u++;
            }
            else
                if(appo[u].ven==" A")
                    k++;
        break;
        case 9:
            if (appo[u].sab==" L"){
                appo[u].sab=" A";
                u++;
            }
            else
                if(appo[u].sab==" A")
                    k++;
        break;
        case 10:
            if (appo[u].dom==" L"){
                appo[u].dom=" A";
                u++;
            }
            else
                if(appo[u].dom==" A")
                    k++;
        break;
        }
    }
    sin.close();
    ifstream fin("auto.csv");
    if (!fin)
        cout<<"Errore di apertura del file";
    if (k!=0)
        cout<<"Auto non disponibile nei giorni selezionati!";
    else
    {
        cout<<"Auto prenotata!"<<endl;
        while (!fin.eof()){
        fin>>w;
        w.erase(remove(w.begin(),w.end(),x),w.end());
        //cout<<"W="<<w<<endl;
        //cout<<"APPO CAT="<<appo[y-1].Categoria<<endl;
            if(w == appo[y-1].Categoria)
            {
                fin>>w;
                w.erase(remove(w.begin(),w.end(),x),w.end());
                //cout<<"W2="<<w<<endl;
                //cout<<"APPO MARCA="<<appo[y-1].Marca<<endl;
                if(appo[y-1].Marca == " FIAT")
                {
                cout<<"vediamo";
                cout<<appo[y-1].Modello<<",";
                cout<<appo[y-1].Colore<<",";
                cout<<appo[y-1].lun<<",";
                cout<<appo[y-1].mar<<",";
                cout<<appo[y-1].mer<<",";
                cout<<appo[y-1].gio<<",";
                cout<<appo[y-1].ven<<",";
                cout<<appo[y-1].sab<<",";
                cout<<appo[y-1].dom;
                r++;
                cout<<endl;
                }
            }
        }
    cout<<endl;
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

