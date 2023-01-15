#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"

using namespace std;

void preencheABB(ArvBinBusca *a, int p, int q) {
    if( p <= q) {
        int m = (p+q)/2; // Ponto médio da arvore (ele tem que ser a raiz)
        a->insere(m);
        preencheABB(a, p, m-1); // Vou do começo até o ponto médio
        preencheABB(a, m+1, q); // Vou do ponto medio até o final
    }
}

int main()
{
    /*
    ArvBinBusca arv;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(11);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.imprime();
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;

    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;

    
    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(18);
    arv.remove(5);
    cout << endl;
    

    cout << "Arvore Binaria de Busca final:" << endl;
    arv.imprime();

    cout << "Maior: " << arv.maior() << endl;
    cout << "Menor: " << arv.menor() << endl;
    cout << "Removendo o Maior e o Menor: " << endl;
    arv.removeMaior();
    arv.removeMenor();
    arv.imprime();
    cout << "Pares no caminho: " << arv.contaParesCaminho(10) << endl ;
    arv.remove(15);
    arv.imprime();

    */

    // Ex007
    ArvBinBusca *arv2 = new ArvBinBusca();
    preencheABB(arv2, 1, 10);
    arv2->imprime();

    return 0;
}

