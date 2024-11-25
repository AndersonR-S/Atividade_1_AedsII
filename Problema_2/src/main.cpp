#include "tree.hpp"
#include <iostream>
#include <vector>

int main() {    
    No *raiz = nullptr; 
    Tree *t = new Tree();


    vector<int> valoresInserir = {5, 3, 7, 2, 4, 6, 8, 90, 4 ,23, 245, 43 , 22, 45};
    for(auto &i : valoresInserir){
        raiz = t->inserir(raiz, i);
        cout<< "Altura da arvore: " << t->maxNivel(raiz) << endl;
    }
    cout<<endl;


    vector<int> valoresRemover = {3, 90, 245, 43 , 22};
    for(auto &i : valoresRemover){
        raiz = t->remover(raiz, i);
        cout<< "Altura da arvore: " << t->maxNivel(raiz) << endl;
    }
    cout<<endl;


    vector<int> caminho, melhorCaminho;
    t->encontrarCaminhoMaisLongo(raiz, caminho, melhorCaminho);
    cout <<endl<<"Caminho mais longo: ";
    for (int i : melhorCaminho) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}