#ifndef IPERTROFIA_H
#define IPERTROFIA_H
#include "sovraccarico.h"

class ipertrofia: public sovraccarico {
private:
	orario recupero;
public:
    ipertrofia(std::string ="Nessun nome", int =1, int =1, int =2000, int =0, int =0, int =0, int =0, int =0);
	ipertrofia(const ipertrofia&);
	ipertrofia& operator=(const ipertrofia&);
	virtual bool operator==(const ipertrofia&) const;
	virtual bool operator!=(const ipertrofia&) const;
	virtual ~ipertrofia() {}
	orario getRecupero() const;
	void setRecupero(const int&);
	virtual int volume() const;
	int intensita() const;
	virtual std::string serializza(char) const;
	static ipertrofia* deserializza(const std::vector<std::string>&);
};

#endif
