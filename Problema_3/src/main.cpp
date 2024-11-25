#include "dicionario.hpp"

int main(){
    Dicionario *d = new Dicionario();
    
    while(true){
        string prefixo;
        
        cout<<"\nDigite o prefixo para buscar (ou '~' para encerrar): ";
        cin>>prefixo;
        if(prefixo == "~") break;
        
        d->sugestoes(prefixo);
        cout<<endl;
    }
    cout << "Encerrando o programa..." << endl;

    return 0;
}