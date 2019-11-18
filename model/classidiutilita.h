#ifndef CLASSIDIUTILITA_H
#define CLASSIDIUTILITA_H
#include <iostream>
#include <string>

class orario {
private:
	int sec;
public:
	orario(int =0, int =0, int =0);
	~orario() {}
	orario(const orario&);
	orario& operator=(const orario&);
	bool operator==(const orario&) const;
	bool operator!=(const orario&) const;
	bool operator>(const orario&) const;
	bool operator<(const orario&) const;
    int getSec() const;
	void setSec(const int&);
    int Ore() const;
    int Minuti() const;
    int Secondi() const;
	std::string orarioToString() const;
	static orario stringToOrario(const std::string&);
};

class data {
	private:
		int giorno, mese, anno;
	public:
		data(int =1, int =1, int =2000);
		~data() {}
		data(const data&);
		data& operator=(const data&);
		bool operator==(const data&) const;
		bool operator!=(const data&) const;
		bool operator>(const data&) const;
		bool operator<(const data&) const;
		int getGiorno() const;
		int getMese() const;
		int getAnno() const;
		void setGiorno(const int&);
		void setMese(const int&);
		void setAnno(const int&);
		std::string dataToString() const;
		static data stringToData(const std::string&);
	};

#endif
