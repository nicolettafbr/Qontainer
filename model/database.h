#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "container.h"
#include "esercizio.h"
#include "forza.h"
#include "ipertrofia.h"
#include "hiit.h"
#include "liss.h"
using std::string; using std::vector;

class database {
private:
    std::string path;
    char delimiter;
public:
    database(std::string = "0", char = ',');
    void load(Container<esercizio*>&);
    void save(Container<esercizio*>&);
    static bool controllo(std::string);
};

#endif // DATABASE_H
