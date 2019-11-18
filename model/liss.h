#ifndef LISS_H
#define LISS_H
#include "cardio.h"

class liss: public cardio {
private:
	orario durata;
public:
    liss(std::string ="Nessun nome", int =1, int =1, int =2000, int =0, int =0, int =0, int =0, int =0);
	liss(const liss&);
	liss& operator=(const liss&);
	virtual bool operator==(const liss&) const;
	virtual bool operator!=(const liss&) const;
	virtual ~liss() {}
	orario getDurata() const;
	void setDurata(const int&);
	virtual orario durataAllenamento() const;
	virtual std::string serializza(char) const;
	static liss* deserializza(const std::vector<std::string>&);
};

#endif
