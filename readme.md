# Pratica 1 

## Problema 1



## Problema 2
O código do algoritmo se encontra no repositório : 
GitHub www.github.com/AndersonR-S/Pratica_1_AedsII.git

### 1 - Cálculo do Nível Máximo (Altura da Árvore)

    typedef struct No {
        int valor;
        No* left;
        No* right;
        No(int valor) : valor(valor), left(nullptr), right(nullptr) {}
    } No;

    int Tree::maxNivel(No* raiz) {
        if (raiz == nullptr) {
            return 0;
        } else {
            int size_left = maxNivel(raiz->left);
            int size_right = maxNivel(raiz->right);

            return size_left > size_right ? size_left + 1 : size_right + 1;
        }
    }

### 2 - Inserção e Remoção com Atualização da Altura

#### Inserindo um novo elemento:

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


#### Removendo um  elemento:

    // Procurando o sucessor para o numero que será retirado
    No* Tree::sucessor(No* raiz) {
        No* aux = raiz;
        while (aux && aux->left != nullptr) {
            aux = aux->left;
        }
        return aux;
        }

    // Remover um elemento
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

#### Visualização Interativa:

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

### 3 - Análise de Crescimento:
- Conjunto 1: Árvore "Desbalanceada"
Utilizasse uma sequência crescente de números para representar a inserção em uma árvore desbalanceada. Escolheremos os valores de 1 a 10:

        Conjunto 1 (desbalanceado): *[1, 2, 3, 4, 5, 6, 7, 8, 9]*

- Conjunto 2: Árvore "Balanceada"
Agora, escolho uma sequência de valores que resulta em uma árvore balanceada. Uma árvore binária balanceada pode ser construída a partir de uma sequência ordenada, escolhendo os elementos do meio em cada nível. Com isso, utilizaremos:

        Conjunto 2 (balanceado): *[5, 3, 7, 2, 4, 6, 8, 1, 9]*


**Tabela de Comparação das Árvores e Depreciação**

| Etapa de Inserção | Altura da Árvore Desbalanceada | Altura da Árvore Balanceada | Depreciação (%) |
|-------------------|-------------------------------|----------------------------|-----------------|
| 1                 | 1                             | 1                          | 0.00            |
| 2                 | 2                             | 2                          | 0.00            |
| 3                 | 3                             | 2                          | 33.33           |
| 4                 | 4                             | 3                          | 25.00           |
| 5                 | 5                             | 3                          | 40.00           |
| 6                 | 6                             | 3                          | 50.00           |
| 7                 | 7                             | 3                          | 57.14           |
| 8                 | 8                             | 4                          | 50.00           |
| 9                 | 9                             | 4                          | 55.56           |
| 10                | 10                            | 4                          | 60.00           |

Observações 

- A altura da árvore desbalanceada aumenta rapidamente à medida que as inserções são feitas em ordem crescente.
- A árvore balanceada, por sua vez, mantém uma altura mais constante devido ao processo de balanceamento durante as inserções.
- A depreciação, que mede o impacto negativo de não balancear a árvore, aumenta conforme a diferença de altura entre as árvores desbalanceada e balanceada se amplia.

Concluindo assim, que esta análise mostra a importância de balancear a árvore para reduzir o custo das operações de busca, inserção e remoção. Em cada etapa, a árvore balanceada mantém uma altura menor, o que resulta em maior eficiência.



### 4 - Caminho mais longo:

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


## Problema 3
O código do algoritmo se encontra no repositório : 
GitHub www.github.com/AndersonR-S/Pratica_1_AedsII.git

