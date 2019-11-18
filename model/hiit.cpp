#include "hiit.h"

hiit::hiit(std::string nomeEs, int giorno, int mese, int anno, int bpm, int eta, int interv, int io, int im, int is, int ro, int rm, int rs): cardio(nomeEs,giorno,mese,anno,bpm,eta), numeroIntervalli(interv), durataIntervalli(io,im,is), riposo(ro,rm,rs) {}

hiit::hiit(const hiit& h): cardio(h), numeroIntervalli(h.numeroIntervalli), durataIntervalli(h.durataIntervalli), riposo(h.riposo) {}

hiit& hiit::operator=(const hiit& h) {
	if(this!=&h){
		numeroIntervalli=h.numeroIntervalli;
		durataIntervalli=h.durataIntervalli;
		riposo=h.riposo;
	}return *this;
}

bool hiit::operator==(const hiit& h) const {
	return (cardio::operator==(h) && numeroIntervalli==h.numeroIntervalli && durataIntervalli==h.durataIntervalli && riposo==h.riposo);
}

bool hiit::operator!=(const hiit& h) const {
	return (cardio::operator!=(h) || numeroIntervalli!=h.numeroIntervalli || durataIntervalli!=h.durataIntervalli || riposo!=h.riposo);
}

int hiit::getNumeroIntervalli() const { return numeroIntervalli; }

void hiit::setNumeroIntervalli(const int& i) { numeroIntervalli=i; }

orario hiit::getDurataIntervalli() const { return durataIntervalli; }

void hiit::setDurataIntervalli(const int& d) { durataIntervalli.setSec(d); }

orario hiit::getRiposo() const { return riposo; }

void hiit::setRiposo(const int& r) { riposo.setSec(r); }

orario hiit::durataAllenamento() const {
	int durata=((durataIntervalli.getSec()*numeroIntervalli)+(riposo.getSec()*(numeroIntervalli-1)));
	orario aux;
	aux.setSec(durata);
	return aux;
}

std::string hiit::serializza(char delimiter) const {
    return "HIIT," + cardio::serializza(delimiter) + delimiter + std::to_string(numeroIntervalli) + delimiter + durataIntervalli.orarioToString() + delimiter + riposo.orarioToString() + ";";
}

hiit* hiit::deserializza(const std::vector<std::string>& values) {
    return new hiit(values[0],
                    data::stringToData(values[1]).getGiorno(),
                    data::stringToData(values[1]).getMese(),
                    data::stringToData(values[1]).getAnno(),
					std::stoi(values[2]),
					std::stoi(values[3]),
					std::stoi(values[4]),
					orario::stringToOrario(values[5]).Ore(),
					orario::stringToOrario(values[5]).Minuti(),
					orario::stringToOrario(values[5]).Secondi(),
					orario::stringToOrario(values[6]).Ore(),
					orario::stringToOrario(values[6]).Minuti(),
					orario::stringToOrario(values[6]).Secondi());
}
