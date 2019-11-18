#include "database.h"

database::database(std::string s, char d) : path(s), delimiter(d) {}

void database::load(Container<esercizio*>& contenitore) {
    std::ifstream datafile;
    datafile.open(path, std::ifstream::in);
    if(datafile.is_open()){
        vector<string> valori;
        string riga;
        std::getline(datafile,riga,';'); //La prima riga è 'Database;'
            while(std::getline(datafile,riga,';')) {    //Finchè ho righe da caricare
                    std::stringstream rigaCorrente(riga);
                    string elemento;
                    valori.erase(valori.begin(),valori.end());
                    while(std::getline(rigaCorrente,elemento,','))
                        valori.push_back(elemento);  //Metto nel vettore elemento per elemento

                    string tipoEsercizio=valori[0].substr(1, string::npos);
                    valori.erase(valori.begin());
                    if(tipoEsercizio=="FORZA")
                        contenitore.insert(forza::deserializza(valori));
                    if(tipoEsercizio=="IPERTROFIA")
                        contenitore.insert(ipertrofia::deserializza(valori));
                    if(tipoEsercizio=="HIIT")
                        contenitore.insert(hiit::deserializza(valori));
                    if(tipoEsercizio=="LISS")
                        contenitore.insert(liss::deserializza(valori));
            }
    }
}

void database::save(Container<esercizio*>& contenitore) {
    std::ofstream datafile;
    datafile.open(path, std::ofstream::trunc);

    if (datafile.is_open()) {
        datafile << "Database;\n";
        for(auto it=contenitore.begin(); it!=contenitore.end(); ++it)
            datafile << (*it)->serializza(delimiter) << std::endl;
    }
}

bool database::controllo(std::string path) {
    bool risultato=false;
    std::regex db("Database;");
    std::ifstream file;
    file.open(path, std::ifstream::in);
    if(file.is_open()){
        std::string riga;
        std::getline(file,riga,'\n');
        risultato = regex_match(riga, db);
    }return risultato;
}
