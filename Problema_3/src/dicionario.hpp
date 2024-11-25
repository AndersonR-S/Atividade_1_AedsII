#ifndef DICIONARIO_HPP
#define DICIONARIO_HPP

#include "tree.hpp"
#include <iostream>
#include <vector>   
#include <string>
#include <chrono>


using namespace std;

class Dicionario{
private:
    No* root;
    void lendoArquivo(string nomeArquivo);
public:
    Dicionario(string nomeArquivo = "dataset/dicionario.txt");
    void sugestoes(string prefixo);
};


#endif