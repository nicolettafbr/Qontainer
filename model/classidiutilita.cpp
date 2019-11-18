#include "classidiutilita.h"

//METODI DI ORARIO

orario::orario(int o, int m, int s) {
	if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59) sec=0;
	else sec=o*3600+m*60+s;
}

orario::orario(const orario& o): sec(o.sec) {}

orario& orario::operator=(const orario& o) {
	if(this!=&o) sec=o.sec;
	return *this;
}

bool orario::operator==(const orario& o) const { return sec==o.sec; }

bool orario::operator!=(const orario& o) const { return sec!=o.sec; }

bool orario::operator>(const orario& o) const {
	return((Ore()==o.Ore() && Minuti()==o.Minuti() && Secondi()>o.Secondi()) || 
		(Ore()==o.Ore() && Minuti()>o.Minuti()) || 
		Ore()>o.Ore());
}

bool orario::operator<(const orario& o) const {
	return((Ore()==o.Ore() && Minuti()==o.Minuti() && Secondi()<o.Secondi()) || 
		(Ore()==o.Ore() && Minuti()<o.Minuti()) || 
		Ore()<o.Ore());
}

void orario::setSec(const int& s) { sec=s; }

int orario::getSec() const { return sec; }

int orario::Ore() const { return sec/3600; }

int orario::Minuti() const { return (sec/60)%60; }

int orario::Secondi() const { return sec%60; }

std::string orario::orarioToString() const {
    return (std::to_string(Ore())+":"+std::to_string(Minuti())+":"+std::to_string(Secondi()));
}

orario orario::stringToOrario(const std::string& o) {
    std::string ore, minuti, secondi;
    unsigned long i=0;
	while(i<o.length() && o[i]!=':'){ 
		ore+=o[i];
		i++;
	}
	i++;
	while(i<o.length() && o[i]!=':'){ 
		minuti+=o[i];
		i++;
	}
	i++;
	while(i<o.length() && o[i]!=':'){ 
		secondi+=o[i];
		i++;
	}
	orario* p=new orario(std::stoi(ore), std::stoi(minuti), std::stoi(secondi));
	return *p;
}


//METODI DI DATA

data::data(int g, int m, int a): giorno(g), mese(m), anno(a) {}

data::data(const data& d): giorno(d.giorno), mese(d.mese), anno(d.anno) {}

data& data::operator=(const data& d) {
	if(this!=&d) {
		giorno=d.giorno;
		mese=d.mese;
		anno=d.anno;
	}return *this;
}

bool data::operator==(const data& d) const {
	return (giorno==d.giorno && mese==d.mese && anno==d.anno);
}

bool data::operator!=(const data& d) const {
	return (giorno!=d.giorno || mese!=d.mese || anno!=d.anno);
}

bool data::operator>(const data& d) const {
	return ((giorno>d.giorno && mese==d.mese && anno==d.anno) ||
			(mese>d.mese && anno== d.anno) ||
			(anno>d.anno));
}

bool data::operator<(const data& d) const {
	return ((giorno<d.giorno && mese==d.mese && anno==d.anno) ||
			(mese<d.mese && anno== d.anno) ||
			(anno<d.anno));
}

int data::getGiorno() const { return giorno; }

int data::getMese() const { return mese; }

int data::getAnno() const { return anno; }

void data::setGiorno(const int& g) { giorno=g; }

void data::setMese(const int& m) { mese=m; }

void data::setAnno(const int& a) { anno=a; }

std::string data::dataToString() const {
    return (std::to_string(getGiorno())+"/"+std::to_string(getMese())+"/"+std::to_string(getAnno()));
}

data data::stringToData(const std::string& d) {
	std::string giorno, mese, anno;
    unsigned long i=0;
	while(i<d.size() && d[i]!='/'){
		giorno+=d[i];
		i++;
	} 
	i++;
	while(i<d.size() && d[i]!='/'){
		mese+=d[i];
		i++;
	} 
	i++;
	while(i<d.size()){
		anno+=d[i];
		i++;
	}
	data* p=new data(std::stoi(giorno),std::stoi(mese),std::stoi(anno));
	return *p;
}
