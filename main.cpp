#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct automobile{
    string Categoria, Marca, Modello, Colore, lun, mar, mer, gio, ven, sab, dom;
    };
int righe=0;
automobile vet[20];
automobile appo[20];
void riempivet(){
    string app;
    ifstream fin("auto.csv");
    if (!fin) cout<<"Errore di apertura del file";
        while (!fin.eof()){
        getline(fin,vet[righe].Categoria,',');
        cout<<vet[righe].Categoria;
        getline(fin,vet[righe].Marca,',');
        cout<<vet[righe].Marca;
        getline(fin,vet[righe].Modello,',');
        cout<<vet[righe].Modello;
        getline(fin,vet[righe].Colore,',');
        cout<<vet[righe].Colore;
        getline(fin,vet[righe].lun,',');
        cout<<vet[righe].lun;
        getline(fin,vet[righe].mar,',');
        cout<<vet[righe].mar;
        getline(fin,vet[righe].mer,',');
        cout<<vet[righe].mer;
        getline(fin,vet[righe].gio,',');
        cout<<vet[righe].gio;
        getline(fin,vet[righe].ven,',');
        cout<<vet[righe].ven;
        getline(fin,vet[righe].sab,',');
        cout<<vet[righe].sab;
        getline(fin,vet[righe].dom);
        cout<<vet[righe].dom<<endl;
        righe++;
        }
    fin.close();
}
void scrivifile(int y){
    for (int i=0; i<righe; i++)
        {
            cout<<vet[i].Marca<<endl;
            cout<<appo[y-1].Marca<<endl;
            if (vet[i].Marca==appo[y-1].Marca)
            {
                vet[i].Categoria=appo[y-1].Categoria;
                vet[i].Marca=appo[y-1].Marca;
                vet[i].Modello=appo[y-1].Modello;
                vet[i].Colore=appo[y-1].Colore;
                vet[i].lun=appo[y-1].lun;
                vet[i].mar=appo[y-1].mar;
                vet[i].mer=appo[y-1].mer;
                vet[i].gio=appo[y-1].gio;
                vet[i].ven=appo[y-1].ven;
                vet[i].sab=appo[y-1].sab;
                vet[i].dom=appo[y-1].dom;
            }
        }
        ofstream fout("auto.csv");
        for (int i=0; i<righe; i++)
        {
            fout<<vet[i].Categoria;
            cout<<vet[i].Categoria;
            fout<<vet[i].Marca;
            cout<<vet[i].Marca;
            fout<<vet[i].Modello;
            cout<<vet[i].Modello;
            fout<<vet[i].Colore;
            cout<<vet[i].Colore;
            fout<<vet[i].lun;
            cout<<vet[i].lun;
            fout<<vet[i].mar;
            cout<<vet[i].mar;
            fout<<vet[i].mer;
            cout<<vet[i].mer;
            fout<<vet[i].gio;
            cout<<vet[i].gio;
            fout<<vet[i].ven;
            cout<<vet[i].ven;
            fout<<vet[i].sab;
            cout<<vet[i].sab;
            fout<<vet[i].dom;
            cout<<vet[i].dom<<endl;
            fout<<endl;
        }
    fout.close();
}
void richiesta(automobile autom){
    riempivet();
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
        cout<<"Inserire i giorni in cui prenotare l'auto \n(lun=1, mar=2, mer=3, gio=4, ven=5, sab=6, dom=7, exit=8) : ";
        cin>>n;
        n=n+3;
        app[s]=n;
        s++;
    }while (n!=11);
    for (int g=0; g<s-1; g++)
    {
        switch (app[g]){
        case 4:
            if (appo[y-1].lun==" L"){
                appo[y-1].lun=" A";
                u++;
            }
            else
                if(appo[y-1].lun==" A")
                    k++;
                u++;
        break;
        case 5:
            if (appo[y-1].mar==" L" || appo[y-1].mar==" L,"){
                appo[y-1].mar=" A";
                u++;
            }
            else
                if(appo[y-1].mar==" A")
                    k++;

        break;
        case 6:
            if (appo[y-1].mer==" L"){
                appo[y-1].mer=" A";
                u++;
            }
            else
                if(appo[y-1].mer==" A")
                    k++;
        break;
        case 7:
            if (appo[y-1].gio==" L"){
                appo[y-1].gio=" A";
                u++;
            }
            else
                if(appo[y-1].gio==" A")
                    k++;
        break;
        case 8:
            if (appo[y-1].ven==" L"){
                appo[y-1].ven=" A";
                u++;
            }
            else
                if(appo[y-1].ven==" A")
                    k++;
        break;
        case 9:
            if (appo[y-1].sab==" L"){
                appo[y-1].sab=" A";
                u++;
            }
            else
                if(appo[y-1].sab==" A")
                    k++;
        break;
        case 10:
            if (appo[y-1].dom==" L"){
                appo[y-1].dom=" A";
                u++;
            }
            else
                if(appo[y-1].dom==" A")
                    k++;
        break;
        }
    }
    sin.close();
    ifstream fin("auto.csv");
    if (!fin)
        cout<<"Errore di apertura del file";
    if (k!=0)
        cout<<"Auto non disponibile nei giorni selezionati!"<<endl;
    else{
        cout<<"Auto prenotata!"<<endl;
        scrivifile(y);
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
