#include <iostream>
#include "ArvBin.h"
#include "ArvBin.cpp"

using namespace std;

int main()
{
    /// Funcao cria

    ArvBin *vazia = new ArvBin();
    ArvBin *a1 = new ArvBin(); ArvBin *a2 = new ArvBin(); ArvBin *a3 = new ArvBin();

    a1->cria(16, vazia, vazia);
    a2->cria(19, vazia, vazia);
    a1->cria(18, a1, a2);

    /// Como a2 ja foi enraizado posso usar novamente
    a2->cria(38, vazia, vazia);
    a3->cria(14, vazia, vazia);
    a2->cria(25, a2, a3);

    a1->cria(10, a1, a2);

    a1->imprime();

    cout << "Total de nos: " << a1->contaNos() << endl;
    cout << "Total de folhas: " << a1->contaNosFolhas() << endl;
    cout << "Altura: " << a1->altura() << endl;
    cout << "Total de impares: " << a1->contaImpar() << endl;
    cout << "Total de folhas impares: " << a1->contaFolhaImpar() << endl;
    a1->imprimeNivel(1);
    cout << endl;
    cout << "Media do nivel: " << a1->mediaNivel(1) << endl;
    cout << "Menor Valor: " << a1->min() << endl;
    cout << "Maior Valor: " << a1->max() << endl;
    a1->inverte();
    a1->imprime();
    cout << "No mais esq: " << a1->noMaisEsquerda() << endl;
    cout << "No mais dir: " << a1->noMaisDireita() << endl;
    NoArv *teste;
    teste->setInfo(25);
    teste->setDir(NULL);
    teste->setEsq(NULL);
    //cout << "Menor sub: " << a1->minSubArvore() << endl;
    //cout << "Maior sub: " << a1->maxSubArvore() << endl;

    return 0;
}
