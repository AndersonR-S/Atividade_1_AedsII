#include "tree.hpp"

tree::tree() {}

No* tree::insert(No* raiz, string palavra) {
    if (raiz == nullptr) {
        raiz = new No(palavra);
    } else if (palavra < raiz->palavra) {
        raiz->left = insert(raiz->left, palavra);
    } else {
        raiz->right = insert(raiz->right, palavra);
    }
    return raiz;
}


void coletarSugestoes(No* raiz, const string& prefixo, vector<string>& suggestions) {
    if (raiz == nullptr) {
        return;
    }
    if (raiz->palavra.compare(0, prefixo.size(), prefixo) == 0) {
        suggestions.push_back(raiz->palavra);
    }

    coletarSugestoes(raiz->left, prefixo, suggestions);
    coletarSugestoes(raiz->right, prefixo, suggestions);
}

void tree::mostraOrdemCrescente(No* raiz) {
    if (raiz != nullptr) {
        mostraOrdemCrescente(raiz->left);
        cout << raiz->palavra <<endl;
        mostraOrdemCrescente(raiz->right);
    }
}

vector<string> tree::autocomplete(No* raiz, const string& prefixo) {
    vector<string> suggestions;
    coletarSugestoes(raiz, prefixo, suggestions);
    return suggestions;
}

