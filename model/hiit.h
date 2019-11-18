#ifndef HIIT_H
#define HIIT_H
#include "cardio.h"

class hiit: public cardio {
private:
	int numeroIntervalli;
	orario durataIntervalli, riposo;
public:
    hiit(std::string ="Nessun nome", int =1, int =1, int =2000, int =0, int =0, int =0, int =0, int =0, int =0, int =0, int=0, int =0);
	virtual ~hiit() {}
	hiit(const hiit&);
	hiit& operator=(const hiit&);
	virtual bool operator==(const hiit&) const;
	virtual bool operator!=(const hiit&) const;
	int getNumeroIntervalli() const;
	void setNumeroIntervalli(const int&);
	orario getDurataIntervalli() const;
	void setDurataIntervalli(const int&);
	orario getRiposo() const;
	void setRiposo(const int&);
	virtual orario durataAllenamento() const;
	virtual std::string serializza(char) const;
	static hiit* deserializza(const std::vector<std::string>&);
};

#endif
