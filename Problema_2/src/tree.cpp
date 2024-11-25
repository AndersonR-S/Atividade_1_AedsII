#include "tree.hpp"

Tree::Tree() {}

No* Tree::inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
       raiz = new No(valor);
    }
    else if (valor < raiz->valor) {
        raiz->left = inserir(raiz->left, valor);
    } else {
        raiz-> right = inserir(raiz->right, valor);
    }
    return raiz;
}

void Tree::mostraOrdemCrescente(No* raiz) {
    if (raiz != nullptr) {
        mostraOrdemCrescente(raiz->left);
        cout << raiz->valor << " ";
        mostraOrdemCrescente(raiz->right);
    }
}

No* Tree::sucessor(No* raiz) {
    No* aux = raiz;
    while (aux && aux->left != nullptr) {
        aux = aux->left;
    }
    return aux;
}

No *Tree::remover(No *raiz, int valor) {
    if (raiz == nullptr) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->left = remover(raiz->left, valor);
    } else if (valor > raiz->valor) {
        raiz->right = remover(raiz->right, valor);
    } else {

        // no com um ou nenhum filho
        if (raiz->left == nullptr) {
            No *aux = raiz->right;
            delete raiz;
            return aux;
        } else if (raiz->right == nullptr) {
            No *aux = raiz->left;
            delete raiz;
            return aux;
        }

        // no com dois filhos
        No *sucessor_minimo = sucessor(raiz->right);
        raiz->valor = sucessor_minimo->valor;
        raiz->right = remover(raiz->right, sucessor_minimo->valor);
    }
    return raiz;
}

int Tree::maxNivel(No* raiz) {
    if (raiz == nullptr) {
        return 0;
    } else {
        int size_left = maxNivel(raiz->left);
        int size_right = maxNivel(raiz->right);

        return size_left > size_right ? size_left + 1 : size_right + 1;
    }
}

void Tree::encontrarCaminhoMaisLongo(No* raiz, vector<int>& caminho, std::vector<int>& melhorCaminho) {
    if (raiz == nullptr) {
        return;
    }

    caminho.push_back(raiz->valor);

    if (raiz->left == nullptr && raiz->right == nullptr) {
        if (caminho.size() > melhorCaminho.size()) {
            melhorCaminho = caminho;
        }
    }

    encontrarCaminhoMaisLongo(raiz->left, caminho, melhorCaminho);
    encontrarCaminhoMaisLongo(raiz->right, caminho, melhorCaminho);

    caminho.pop_back();
}
