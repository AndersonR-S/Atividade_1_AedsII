#include "dicionario.hpp"
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <algorithm>
#include <cctype>


void Dicionario::lendoArquivo(string nomeArquivo){
    tree *arvore = new tree();

    No* raiz = nullptr;
    string palavra;
    ifstream arquivo;

    arquivo.open(nomeArquivo);
    if(!arquivo.is_open()){
        cout<<"Erro ao abrir o arquivo"<<endl;
        exit(1);
    }

    while(arquivo >> palavra){
        raiz = arvore->insert(raiz, palavra);
    }

    arquivo.close();
    root = raiz;
}

Dicionario::Dicionario(string nomeArquivo) {
    root = nullptr;

    cout<<"Lendo as palavras do dicionario..."<<endl;
    auto inicio = chrono::high_resolution_clock::now();
    lendoArquivo(nomeArquivo);
    auto final = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = final - inicio;

    cout << "Dicionario carregado em " << duracao.count() << " segundos.\n";
}

void Dicionario::sugestoes(string prefixo) {
    tree *arvore = new tree();


    transform(prefixo.begin(), prefixo.end(), prefixo.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

    cout<<"Buscando sugestoes para o prefixo '"<<prefixo<<"'..."<<endl;
    auto inicio = chrono::high_resolution_clock::now();
    vector<string> sugestoes = arvore->autocomplete(root, prefixo);
    auto final = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = final - inicio;

    if(sugestoes.empty()){
        cout<<"Nenhuma sugestao encontrada para o prefixo '"<<prefixo<<"'."<<endl;
    }else{
        cout << "Sugestoes encontradas: "<< endl;
        for (const string& sugestao : sugestoes) {
            cout << sugestao << endl;
        }
    }

    cout<<endl << "Tempo de busca: " << duracao.count() << " segundos."<<endl;

}