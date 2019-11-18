#include "forza.h"

forza::forza(std::string nomeEs, int giorno, int mese, int anno, int serie, int ripetizioni, int kg): sovraccarico(nomeEs,giorno,mese,anno,serie,ripetizioni), peso(kg) {}

forza::forza(const forza& f): sovraccarico(f), peso(f.peso) {}

forza& forza::operator=(const forza& f) {
	if(this!=&f) peso=f.peso;
	return *this;
}

bool forza::operator==(const forza& f) const {
	return (sovraccarico::operator==(f) && peso==f.peso);
}

bool forza::operator!=(const forza& f) const {
	return (sovraccarico::operator!=(f) || peso!=f.peso);
}

int forza::getPeso() const { return peso; }

void forza::setPeso(const int& p) { peso=p; }

int forza::volume() const {
	return getSerie()*getRipetizioni()*peso;
}

int forza::massimale() const {
	double aux=peso*(1+(getRipetizioni()/30.0));		//Il calcolo va fatto in decimale perchè le formule per il calcolo del massimale hanno tutte numeri decimali
	return static_cast<int>(aux);
}

int forza::percentualeCarico() const {
	double carico=(peso*100)/massimale();
	double intera, decimale=modf((carico/5),&intera);	//modf chiede due double come parametri!
	if(decimale<=5) return static_cast<int>(intera*5);
	else return static_cast<int>((intera+1)*5);
}

std::string forza::serializza(char delimiter) const {
    return "FORZA," + sovraccarico::serializza(delimiter) + delimiter + std::to_string(peso) + ";";
}

forza* forza::deserializza(const std::vector<std::string>& values) {
    return new forza(values[0],
                    data::stringToData(values[1]).getGiorno(),
                    data::stringToData(values[1]).getMese(),
                    data::stringToData(values[1]).getAnno(),
					std::stoi(values[2]),
					std::stoi(values[3]),
					std::stoi(values[4]));
}
