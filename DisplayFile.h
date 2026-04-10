#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include "Objeto.h"
#include <vector>

class DisplayFile {
public:
    std::vector<Objeto*> objetos;

    void adicionar(Objeto* obj) {
        objetos.push_back(obj);
    }

    ~DisplayFile() {
        for (auto obj : objetos)
            delete obj;
    }
};

#endif
