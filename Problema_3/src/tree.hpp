#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct No{
    string palavra;
    No* left;
    No* right;

    No(string palavra) : palavra(palavra), left(nullptr), right(nullptr) {}
}No;

class tree{
public:
    tree();

    No* insert(No* root, string palavra);
    vector<string> autocomplete(No* raiz, const string& prefixo);
    void mostraOrdemCrescente(No* raiz);

};
#endif