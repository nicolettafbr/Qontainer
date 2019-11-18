#ifndef FORZA_H
#define FORZA_H
#include <cmath>
#include "sovraccarico.h"

class forza: public sovraccarico {
private:
	int peso;
public:
    forza(std::string ="Nessun nome", int =1, int =1, int =2000, int =0, int =0, int =0);
	forza(const forza&);
	forza& operator=(const forza&);
	virtual bool operator==(const forza&) const;
	virtual bool operator!=(const forza&) const;
	virtual ~forza() {}
	int getPeso() const;
	void setPeso(const int&);
	virtual int volume() const;
	int massimale() const;
	int percentualeCarico() const;
	virtual std::string serializza(char) const;
	static forza* deserializza(const std::vector<std::string>&);
};

#endif
