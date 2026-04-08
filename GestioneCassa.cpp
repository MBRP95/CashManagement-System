#include<iostream>
#include<fstream>
#include<string>
#include <sstream> 
#include <iomanip>
using namespace std;

struct giorno {
    int gg, mm, aa;
};

struct Cassa {
    giorno Versamento;
    giorno Ieri;
    giorno Data;
    float fondoA, fondoC, esterni,incasso, buste, nonVersatoResiduo, fondoCIeri, errore;
    string ultimaOperazione;
    int aperto ,numVersamento;
 

    void chiusura() {
        apriFile();
        if (aperto==0){
        	cout << "Errore, effettuare prima l'apertura." << endl;
        	return;
		}
		
        cout << "Chiusura del " << Data.gg << "/" << Data.mm << "/20" << Data.aa << endl;
        float Fondo;
        int scelta;
        float Incasso;
        float Esterni;
        float Busta;
        int conferma=0;
        while (conferma==0){
		
        cout << "Inserisce fondo: "; cin >> Fondo; cout << endl;
        cout << "Inserisce incasso: "; cin >> Incasso; cout << endl;
        cout << "Inserisce busta: "; cin >> Busta; cout << endl;
        cout << "Inserisce esterni: "; cin >> Esterni; cout << endl;
        cout << "Per confermare premere 1, per reinserire i dati premere 0 "; cin >> conferma; cout << endl;
}
        incasso = incasso + Incasso;
        buste = buste + Busta;
        esterni = esterni + Esterni;
        fondoC = fondoA + Incasso - Busta + Esterni;
        ultimaOperazione = "Chiusura del " +std::to_string(Data.gg) + "/"+std::to_string(Data.mm)+ "/20"+std::to_string(Data.aa)+".";
        if (Fondo == fondoC) {
            cout << "Chiusura ok" << endl;
        }
        else {
            if (Fondo > fondoC) {
                cout << "Errore, il fondo dovrebbe essere di " << setprecision (2) <<fixed <<fondoC << " Euro. Ci sono " <<  setprecision (2) <<fixed <<Fondo - fondoC << " Euro in piu." << endl;
            }
            if (Fondo < fondoC) {
                cout << "Errore, il fondo dovrebbe essere di " << setprecision (2) <<fixed <<fondoC << " Euro. Ci sono "  << setprecision (2) <<fixed <<fondoC - Fondo << " Euro in meno." << endl;
            }
            cout << "Confermare il fondo contato?(premere 1 per si oppure 0 per no, mantenendo il fondo al valore corretto)"; cin >> scelta;
            while (scelta != 0 && scelta != 1) {
                cout << "Valore errato, reinserire 1 o 0: "; cin >> scelta;}
            if (scelta == 1) {
                fondoC = Fondo;
                errore=errore+Fondo-fondoC;
            }
            
        }reportFileChiusura(Esterni, Busta, Incasso);
        aperto=0;
        chiudiFile();
    }

    bool newFile() {
        int i = 0;
        ifstream fin("cassa.txt");
        string test;
        while (!fin.eof()) {

            getline(fin, test);
            i++;
        }
        if (i == 1) {
        	fin.close();
            return true;
        }
        else {
        	fin.close();
            return false;
        }

    }

    void apriFile() {
        ifstream fin("cassa.txt");
        int i = 0;
        int l = 0;
        string read[50];
        string Read;
        bool NewFile;
        NewFile = newFile();
        int x;
        float y;
        if (NewFile == false) {
            while (!fin.eof()) {
                getline(fin, Read);
                read[i] = Read;
                i++;

            }
            Versamento.gg = stoi(read[0]);
            Versamento.mm = stoi(read[1]);
            Versamento.aa = stoi(read[2]);
            Ieri.gg = stoi(read[3]);
            Ieri.mm = stoi(read[4]);
            Ieri.aa = stoi(read[5]);
            Data.gg = stoi(read[6]);
            Data.mm = stoi(read[7]);
            Data.aa = stoi(read[8]);
            fondoA = stof(read[9]);
            fondoC = stof(read[10]);
            fondoCIeri = stof(read[11]);
            esterni = stof(read[12]);
            buste = stof(read[13]);
            incasso = stof(read[14]);
            nonVersatoResiduo = stof(read[15]);
            errore = stof(read[16]);
            ultimaOperazione= read[17];
            aperto=stoi(read[18]);
            numVersamento=stoi(read[19]);

            return;
        }
        else {
            cout << "Inserire giorno, mese e anno ultimo versamento: "; cin >> x;
            Versamento.gg = x;
            cin >> x;
            Versamento.mm = x;
            cin >> x;
            Versamento.aa = x;
            cout << "Inserire ultimo giorno, mese e anno lavorato: "; cin >> x;
            Ieri.gg = x;
            cin >> x;
            Ieri.mm = x;
            cin >> x;
            Ieri.aa = x;
            cout << "Inserire giorno, mese e anno di oggi: "; cin >> x;
            Data.gg = x;
            cin >> x;
            Data.mm = x;
            cin >> x;
            Data.aa = x;
            cout << "Inserire fondo in apertura: "; cin >> y;
            fondoA = y;
            cout << "Inserire fondo chiusura ieri: "; cin >> y;
            fondoC = y;
            cout << "Inserire totale esterni: "; cin >> y;
            esterni = y;
            cout << "Inserire totale buste: "; cin >> y;
            buste = y;
            cout << "Inserire totale incassi: "; cin >> y;
            incasso = y;
            cout << "Inserire totale non versato residuo: "; cin >> y;
            nonVersatoResiduo = y;
            errore=0;
            fin.close();
            chiudiFile();
        }

    }

    void chiudiFile() {
        ofstream fout("cassa.txt", ios::trunc);
        fout << Versamento.gg << "\n";
        fout << Versamento.mm << "\n";
        fout << Versamento.aa << "\n";
        fout << Ieri.gg << "\n";
        fout << Ieri.mm << "\n";
        fout << Ieri.aa << "\n";
        fout << Data.gg << "\n";
        fout << Data.mm << "\n";
        fout << Data.aa << "\n";
        fout << fondoA << "\n";
        fout << fondoC << "\n";
        fout << fondoCIeri << "\n";
        fout << esterni << "\n";
        fout << buste << "\n";
        fout << incasso << "\n";
        fout << nonVersatoResiduo << "\n";
        fout << errore << "\n";
        fout << ultimaOperazione << "\n";
        fout << aperto << "\n";
        fout << numVersamento << "\n";
        cout << "Scrittura completata" << endl;

    }
      void backupFile() {
      	ifstream fin("cassa.txt");
        int i = 0;
        int l = 0;
        string read[50];
        string Read;
        bool NewFile;
        NewFile = newFile();
        int x;
        float y;
        if (NewFile == false) {
            while (!fin.eof()) {
                getline(fin, Read);
                read[i] = Read;
                i++;

            }
            Versamento.gg = stoi(read[0]);
            Versamento.mm = stoi(read[1]);
            Versamento.aa = stoi(read[2]);
            Ieri.gg = stoi(read[3]);
            Ieri.mm = stoi(read[4]);
            Ieri.aa = stoi(read[5]);
            Data.gg = stoi(read[6]);
            Data.mm = stoi(read[7]);
            Data.aa = stoi(read[8]);
            fondoA = stof(read[9]);
            fondoC = stof(read[10]);
            fondoCIeri = stof(read[11]);
            esterni = stof(read[12]);
            buste = stof(read[13]);
            incasso = stof(read[14]);
            nonVersatoResiduo = stof(read[15]);
            errore = stof(read[16]);
            ultimaOperazione = read[17];
            aperto = stoi(read[18]);
            numVersamento = stoi(read[19]);
        }
        ofstream fout("cassaBackup.txt", ios::trunc);
        fout << Versamento.gg << "\n";
        fout << Versamento.mm << "\n";
        fout << Versamento.aa << "\n";
        fout << Ieri.gg << "\n";
        fout << Ieri.mm << "\n";
        fout << Ieri.aa << "\n";
        fout << Data.gg << "\n";
        fout << Data.mm << "\n";
        fout << Data.aa << "\n";
        fout << fondoA << "\n";
        fout << fondoC << "\n";
        fout << fondoCIeri << "\n";
        fout << esterni << "\n";
        fout << buste << "\n";
        fout << incasso << "\n";
        fout << nonVersatoResiduo << "\n";
        fout << errore << "\n";
        fout << ultimaOperazione << "\n";
        fout << aperto << "\n";
        fout << numVersamento << "\n";
        cout << "Scrittura Backup completata" << endl;

    }

    void reportFileChiusura(float Esterni, float Buste, float Incasso) {
        ofstream fout("report.txt", ios::app);
        fout << Data.gg << "/" << Data.mm << "/" << Data.aa << " - Fondo apertura: "<<setprecision (2) <<fixed << fondoA << "€, Fondo chiusura: "<<setprecision (2) <<fixed << fondoC << "€, Esterni: "
           <<setprecision (2) <<fixed << Esterni << "€, Incasso: " <<setprecision (2) <<fixed << Incasso <<"€, Buste: " << setprecision (2) <<fixed <<Buste <<"€.\n";
        fout << "Totale fondo: " <<setprecision (2) <<fixed << fondoC + buste << "€, Totale buste: " << setprecision (2) <<fixed <<buste << "€, Totale incasso: " <<setprecision (2) <<fixed << incasso << "€, Totale esterni: " <<setprecision (2) <<fixed << esterni << "€.\n";
        fout << "Incasso errato: " << setprecision (2) <<fixed <<errore <<"€."<< endl;
        fout << endl  << endl;
        cout << "Report ok."<< endl;
    }

    void apertura() {
        apriFile();
        float Fondo;
        int scelta;
        int Gg, Mm, Aa;
        int conferma=0;
        if (aperto==1){
        	cout << "Errore, effettuare prima la chiusura." << endl;
        	return;
		}
		backupFile();
        while (conferma==0){
		
        cout << "Inserisce giorno: "; cin >> Gg; cout << endl;
        cout << "Inserisce mese: "; cin >> Mm; cout << endl;
        cout << "Inserisce anno: "; cin >> Aa; cout << endl;
        cout << "Inserisce fondo contato: "; cin >> Fondo; cout << endl;
        cout << "Per confermare premere 1, per reinserire i dati premere 0 "; cin >> conferma; cout << endl;
    }
    ultimaOperazione = "Apertura del " +std::to_string(Gg) + "/"+std::to_string(Mm)+ "/20"+std::to_string(Aa)+".";
        Ieri.gg = Data.gg;
        Ieri.mm = Data.mm;
        Ieri.aa = Data.aa;
        Data.gg = Gg;
        Data.mm = Mm;
        Data.aa = Aa;
        fondoCIeri = fondoC;
        fondoC = 0;
        if (Fondo == fondoCIeri)
        {
            cout << "Apertura ok" << endl;
            fondoA = Fondo;
        }
        else {
            if (Fondo > fondoCIeri)
            {
                cout << "Errore, il fondo dovrebbe essere di " << setprecision (2) <<fixed <<fondoCIeri << " Euro. Ci sono "  << setprecision (2) <<fixed <<Fondo - fondoCIeri << " Euro in piu." << endl;
            }
            if (Fondo < fondoCIeri)
            {
                cout << "Errore, il fondo dovrebbe essere di " << setprecision (2) <<fixed <<fondoCIeri << " Euro. Ci sono "  <<setprecision (2) <<fixed <<fondoCIeri - Fondo << " Euro in meno." << endl;
            }
            cout << "Confermare il fondo contato?(premere 1 per si oppure 0 per no, mantenendo il fondo a "<<setprecision (2) <<fixed <<fondoCIeri <<" Euro)"; cin >> scelta;
            while (scelta != 0 && scelta != 1) {
                cout << "Valore errato, reinserire 1 o 0: "; cin >> scelta;
            }
            if (scelta == 1) {
                fondoA = Fondo;
            }
            if (scelta == 0) {
                fondoA = fondoCIeri;
                errore=errore+Fondo-fondoCIeri;
            }

        }
        aperto=1;
        chiudiFile();
    }

    void versamento() {
        apriFile();
        float versamento;
        float nonVersato;
        float nonVersatoPrecedente = nonVersatoResiduo;
        int conferma =0;
        if (aperto==0){
        	cout << "Errore, effettuare prima l'apertura." << endl;
        	return;
		}
		stampa();
        while (conferma==0){
        	
        cout << endl;
		cout << endl;	
		cout << "Versamento consigliato: "; cout << incasso+nonVersatoResiduo;
		if (esterni>0){
			cout << " e togliere " << esterni <<" Euro di esterni.";
		}
		if (esterni<0){
			cout << " e aggiungere " << -esterni <<" Euro di esterni.";
		}
		cout << endl;
  cout << "Importo da versare: "; cin >> versamento;
  cout << versamento;
  cout << "Per confermare premere 1, per reinserire i dati premere 0 "; cin >> conferma; cout << endl;
}
numVersamento ++;
ultimaOperazione = "Versamento del " +std::to_string(Data.gg) + "/"+std::to_string(Data.mm)+ "/20"+std::to_string(Data.aa)+".";
		
            nonVersato = incasso - versamento;
            nonVersatoResiduo = nonVersatoResiduo + nonVersato;
            fondoA = fondoA - versamento + buste;
            
        
                ofstream fout("versamenti.txt", ios::app);
                cout << "Versamento numero: " << numVersamento <<"."<< endl;
            cout << "Incasso dal " << Versamento.gg << "/" << Versamento.mm << "/" << Versamento.aa << " al " << Ieri.gg << "/" << Ieri.mm << "/" << Ieri.aa << ". " << endl;
        cout << "Incasso versato: " << setprecision (2) <<fixed <<versamento <<" Euro (di cui non versato precedente "  <<setprecision (2) <<fixed <<nonVersatoPrecedente <<" Euro)."<<endl;
        cout << "Incasso reale: "  <<setprecision (2) <<fixed <<incasso << " Euro. " << endl;
        cout << "Non versato: "  <<setprecision (2) <<fixed <<nonVersato << " Euro. " << endl;
 cout << "Totale non versato residuo: "  <<setprecision (2) <<fixed <<nonVersatoResiduo << " Euro. " << endl;
 fout << "Versamento numero: " << numVersamento <<"."<< endl;
    fout << "Incasso dal " << Versamento.gg << "/" << Versamento.mm << "/" << Versamento.aa << " al " << Ieri.gg << "/" << Ieri.mm << "/" << Ieri.aa << ". " << endl;
        fout << "Incasso versato: "  <<setprecision (2) <<fixed <<versamento <<"€ (di cui non versato precedente "  <<setprecision (2) <<fixed << nonVersatoPrecedente <<"€)."<<endl;
        fout << "Incasso reale: "  <<setprecision (2) <<fixed <<incasso << "€. " << endl;
        fout << "Non versato: "  << setprecision (2) <<fixed <<nonVersato << "€. " << endl;
 fout << "Totale non versato residuo: "  << setprecision (2) <<fixed <<nonVersatoResiduo << "€. " << endl;
        fout << endl << endl;
        fout.close();
        Versamento.gg = Data.gg;
        Versamento.mm = Data.mm;
        Versamento.aa = Data.aa;
        buste = 0;
         incasso=0;
        chiudiFile();
    }

    void stampa() {
        apriFile();
        cout << Data.gg << "/" << Data.mm << "/" << Data.aa << endl;
        cout << "Ultima operazione: " << ultimaOperazione << endl;
        cout << "Fondo in apertura: "<< setprecision (2) <<fixed <<fondoA << " Euro"<< endl;
        cout << "Totale buste: " << setprecision (2) <<fixed <<buste << " Euro"<<endl;
        cout << "Fondo totale: " << setprecision (2) <<fixed <<buste + fondoA << " Euro (fondo su Hyera "<< setprecision (2) <<fixed <<buste + fondoA-esterni-errore<<" Euro)"<<endl;
        cout << "Totale esterni: " << setprecision (2) <<fixed <<esterni << " Euro"<<endl;
        cout << "Incasso totale (dall'ultimo versamento): "<< setprecision (2) <<fixed << incasso << " Euro"<<endl;
        cout << "Non versato residuo: " << setprecision (2) <<fixed <<nonVersatoResiduo << " Euro"<<endl;

    }
};

int main() {
    Cassa cassa;
    char scelta;
    cassa.apriFile();
    cout <<"Ultima operazione: "<< cassa.ultimaOperazione << endl;
    cout << "Inserire a per apertura, c per chiusura, o v per versamento, s per stampa: "; cin >> scelta; cout << endl;
    while (scelta != 'a' && scelta != 'c' && scelta != 'v' && scelta != 's') {
        cout << "Valore errato, inserire a, c o v: "; cin >> scelta; cout << endl;
    }
    while (scelta != 'f')
        switch (scelta) {
        case ('a'):
            cassa.apertura();
            cout << "Nuova operazione: "; cin >> scelta;
            while (scelta != 'a' && scelta != 'c' && scelta != 'v' && scelta != 's'&& scelta != 'f') {
        cout << "Valore errato, inserire a, c, v o f: "; cin >> scelta; cout << endl;
    }
            break;
        case ('c'):
            cassa.chiusura();
            cout << "Nuova operazione: "; cin >> scelta;
             while (scelta != 'a' && scelta != 'c' && scelta != 'v' && scelta != 's'&& scelta != 'f') {
        cout << "Valore errato, inserire a, c, v o f: "; cin >> scelta; cout << endl;
    }
            break;
        case ('v'):
            cassa.versamento();
            cout << "Nuova operazione: "; cin >> scelta;
            while (scelta != 'a' && scelta != 'c' && scelta != 'v' && scelta != 's'&& scelta != 'f') {
        cout << "Valore errato, inserire a, c, v o f: "; cin >> scelta; cout << endl;
    }
            break;
        case ('s'):
            cassa.stampa();
            cout << "Nuova operazione: "; cin >> scelta;
            while (scelta != 'a' && scelta != 'c' && scelta != 'v' && scelta != 's'&& scelta != 'f') {
        cout << "Valore errato, inserire a, c, v o f: "; cin >> scelta; cout << endl;
    }
            break;

        }
}