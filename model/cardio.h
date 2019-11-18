#ifndef CARDIO_H
#define CARDIO_H
#include "esercizio.h"

class cardio: public esercizio {
private:
	int bpm, eta;
public:
    cardio(std::string ="Nessun nome", int =1, int =1, int =2000, int =0, int =20);
	virtual ~cardio() {}
	cardio(const cardio&);
	cardio& operator=(const cardio&);
	virtual bool operator==(const cardio&) const;
	virtual bool operator!=(const cardio&) const;
	int getBPM() const;
	void setBPM(const int&);
	int getEta() const;
	void setEta(const int &);
	int FCmassima() const;
	int percentualeFC() const;
	virtual orario durataAllenamento() const =0;
	virtual std::string serializza(char) const;
};

#endif
