#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>

using namespace std;

typedef struct No {
    int valor;
    No* left;
    No* right;
    No(int valor) : valor(valor), left(nullptr), right(nullptr) {}
} No;

class Tree{
public:

    Tree();
    No* inserir(No* raiz, int valor);
    No* remover(No* raiz, int valor);

    void mostraOrdemCrescente(No* raiz);
    No* sucessor(No* raiz);

    int maxNivel(No* raiz);
    void encontrarCaminhoMaisLongo(No* raiz, vector<int>& caminho, std::vector<int>& melhorCaminho);

private:

};

#endif