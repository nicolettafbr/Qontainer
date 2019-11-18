#include "esercizio.h"

//METODI DI ESERCIZIO

esercizio::esercizio(std::string nomeEs, int g, int m, int a): nome(nomeEs), dataEsecuzione(g,m,a) {}

esercizio::~esercizio() {}

esercizio::esercizio(const esercizio& e): nome(e.nome), dataEsecuzione(e.dataEsecuzione) {}

esercizio& esercizio::operator=(const esercizio& e) {
	if(this!=&e) {
		nome=e.nome;
		dataEsecuzione=e.dataEsecuzione;
	}return *this;
}

bool esercizio::operator==(const esercizio& e) const {
    return caseInsensitive(this->getNome())==caseInsensitive(e.getNome()) && dataEsecuzione==e.dataEsecuzione;
}

bool esercizio::operator!=(const esercizio& e) const {
    return caseInsensitive(this->getNome())!=caseInsensitive(e.getNome()) || dataEsecuzione!=e.dataEsecuzione;
}

std::string esercizio::caseInsensitive(const std::string& s) const {        //Rende la ricerca case insensitive
    std::string nome=s;
    std::transform(nome.begin(), nome.end(), nome.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return nome;
}

std::string esercizio::getNome() const { return nome; }

void esercizio::setNome(std::string n) {
	nome=n;
}

data esercizio::getDataEsecuzione() const { return dataEsecuzione; }

void esercizio::setDataEsecuzione(const int& g, const int& m, const int& a) {
	dataEsecuzione.setGiorno(g);
	dataEsecuzione.setMese(m);
	dataEsecuzione.setAnno(a);
}

std::string esercizio::serializza(char delimiter) const {
    return nome + delimiter + dataEsecuzione.dataToString();
}
