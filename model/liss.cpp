#include "liss.h"

liss::liss(std::string nomeEs, int giorno, int mese, int anno, int bpm, int eta, int o, int m, int s): cardio(nomeEs,giorno,mese,anno,bpm,eta), durata(o,m,s) {}

liss::liss(const liss& l): cardio(l), durata(l.durata) {}

liss& liss::operator=(const liss& l) {
	if(this!=&l) durata=l.durata;
	return *this;
}

bool liss::operator==(const liss& l) const {
	return (cardio::operator==(l) && durata==l.durata);
}

bool liss::operator!=(const liss& l) const {
	return (cardio::operator!=(l) || durata!=l.durata);
}

orario liss::getDurata() const { return durata; }

void liss::setDurata(const int& d) { durata.orario::setSec(d); }

orario liss::durataAllenamento() const { return durata; }

std::string liss::serializza(char delimiter) const {
    return "LISS," + cardio::serializza(delimiter) + delimiter + durata.orario::orarioToString() + ";";
}

liss* liss::deserializza(const std::vector<std::string>& values) {
    return new liss(values[0],
                    data::stringToData(values[1]).getGiorno(),
                    data::stringToData(values[1]).getMese(),
                    data::stringToData(values[1]).getAnno(),
					std::stoi(values[2]),
					std::stoi(values[3]),
					orario::stringToOrario(values[4]).Ore(),
					orario::stringToOrario(values[4]).Minuti(),
					orario::stringToOrario(values[4]).Secondi());
}

