#include "cardio.h"

cardio::cardio(std::string nomeEs, int giorno, int mese, int anno, int b, int e): esercizio(nomeEs,giorno,mese,anno), bpm(b), eta(e) {}

cardio::cardio(const cardio& c): esercizio(c), bpm(c.bpm), eta(c.eta) {}

cardio& cardio::operator=(const cardio& c) {
	if(this!=&c) {
		bpm=c.bpm;
		eta=c.eta;
	} return *this;
}

bool cardio::operator==(const cardio& c) const {
	return (esercizio::operator==(c) && bpm==c.bpm && eta==c.eta);
}

bool cardio::operator!=(const cardio& c) const {
	return (esercizio::operator!=(c) || bpm!=c.bpm || eta!=c.eta);
}

int cardio::getBPM() const { return bpm; }

void cardio::setBPM(const int& b) { bpm=b; }

int cardio::getEta() const { return eta; }

void cardio::setEta(const int & e) { eta=e; }

int cardio::FCmassima() const {
	int max=220-eta;
	return max;
}

int cardio::percentualeFC() const {
	int aux=(bpm*100)/FCmassima();
	return aux;
}

std::string cardio::serializza(char delimiter) const {
    return esercizio::serializza(delimiter) + delimiter + std::to_string(bpm) + delimiter + std::to_string(eta);
}
