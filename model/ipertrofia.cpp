#include "ipertrofia.h"

ipertrofia::ipertrofia(std::string nomeEs, int giorno, int mese, int anno, int serie, int ripetizioni, int o, int m, int s): sovraccarico(nomeEs,giorno,mese,anno,serie,ripetizioni), recupero(o,m,s) {}

ipertrofia::ipertrofia(const ipertrofia& i): sovraccarico(i), recupero(i.recupero) {}

ipertrofia& ipertrofia::operator=(const ipertrofia& i) {
	if(this!=&i) recupero=i.recupero;
	return *this;
}

bool ipertrofia::operator==(const ipertrofia& i) const {
	return (sovraccarico::operator==(i) && recupero==i.recupero);
}

bool ipertrofia::operator!=(const ipertrofia& i) const {
	return (sovraccarico::operator!=(i) || recupero!=i.recupero);
}

orario ipertrofia::getRecupero() const { return recupero; }

void ipertrofia::setRecupero(const int& r) { recupero.orario::setSec(r); }

int ipertrofia::volume() const {
	return getSerie()*getRipetizioni()*intensita();
}

int ipertrofia::intensita() const {
	if(getRecupero()>orario::stringToOrario("0:1:30")) return 10;
	else if((getRecupero()<orario::stringToOrario("0:1:30"))|| (getRecupero()==orario::stringToOrario("0:1:30"))) return 20;
    else return 1;
}

std::string ipertrofia::serializza(char delimiter) const {
    return "IPERTROFIA," + sovraccarico::serializza(delimiter) + delimiter + recupero.orarioToString() + ";";
}

ipertrofia* ipertrofia::deserializza(const std::vector<std::string>& values) {
    return new ipertrofia(values[0],
                    data::stringToData(values[1]).getGiorno(),
                    data::stringToData(values[1]).getMese(),
                    data::stringToData(values[1]).getAnno(),
					std::stoi(values[2]),
					std::stoi(values[3]),
					orario::stringToOrario(values[4]).Ore(),
					orario::stringToOrario(values[4]).Minuti(),
					orario::stringToOrario(values[4]).Secondi());
}
