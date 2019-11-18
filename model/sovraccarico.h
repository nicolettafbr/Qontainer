#ifndef SOVRACCARICO_H
#define SOVRACCARICO_H
#include "esercizio.h"

class sovraccarico: public esercizio {
private:
	int serie, ripetizioni;
public:
    sovraccarico(std::string ="Nessun nome", int =1, int =1, int =2000, int =0, int =0);
	sovraccarico(const sovraccarico&);
	sovraccarico& operator=(const sovraccarico&);
	virtual bool operator==(const sovraccarico&) const;
	virtual bool operator!=(const sovraccarico&) const;
	virtual ~sovraccarico() {}
	int getSerie() const;
	void setSerie(const int&);
	int getRipetizioni() const;
	void setRipetizioni(const int&);
	virtual int volume() const =0;
	virtual std::string serializza(char) const;
};

#endif
