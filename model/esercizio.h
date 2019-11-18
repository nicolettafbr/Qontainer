#ifndef ESERCIZIO_H
#define ESERCIZIO_H
#include "classidiutilita.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

class esercizio {
private:
	std::string nome;
	data dataEsecuzione;
public:
    esercizio(std::string ="Nessun nome", int =1, int =1, int =2000);
	virtual ~esercizio();
	esercizio(const esercizio&);
	esercizio& operator=(const esercizio&);
	virtual bool operator==(const esercizio&) const;
	virtual bool operator!=(const esercizio&) const;
    std::string caseInsensitive(const std::string&) const;
	std::string getNome() const;
	void setNome(std::string n);
	data getDataEsecuzione() const;
	void setDataEsecuzione(const int&, const int&, const int&);
    virtual std::string serializza(char) const;
};

#endif
