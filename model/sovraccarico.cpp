#include "sovraccarico.h"

sovraccarico::sovraccarico(std::string nomeEs, int giorno, int mese, int anno, int sets, int reps): esercizio(nomeEs,giorno,mese,anno), serie(sets), ripetizioni(reps) {}

sovraccarico::sovraccarico(const sovraccarico& s): esercizio(s), serie(s.serie), ripetizioni(s.ripetizioni) {}

sovraccarico& sovraccarico::operator=(const sovraccarico& s) {
	if(this!=&s){
		serie=s.serie;
		ripetizioni=s.ripetizioni;
	}return *this;
}

bool sovraccarico::operator==(const sovraccarico& s) const {
	return (esercizio::operator==(s) && serie==s.serie && ripetizioni==s.ripetizioni);
}

bool sovraccarico::operator!=(const sovraccarico& s) const {
	return (esercizio::operator!=(s) || serie!=s.serie || ripetizioni!=s.ripetizioni);
}

int sovraccarico::getSerie() const { return serie; }

void sovraccarico::setSerie(const int& s) { serie=s; }
	
int sovraccarico::getRipetizioni() const { return ripetizioni; }

void sovraccarico::setRipetizioni(const int& r) { ripetizioni=r; }

std::string sovraccarico::serializza(char delimiter) const {
    return esercizio::serializza(delimiter) + delimiter + std::to_string(serie) + delimiter + std::to_string(ripetizioni);
}

