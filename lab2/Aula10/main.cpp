#include <iostream>
#include "ArvBin.h"


using namespace std;

int main()
{
    /// Função cria

    ArvBin *vazia = new ArvBin();
    ArvBin *a1 = new ArvBin(); ArvBin *a2 = new ArvBin(); ArvBin *a3 = new ArvBin();

    a1->cria(16, vazia, vazia);
    a2->cria(19, vazia, vazia);
    a1->cria(18, a1, a2);

    /// Como a2 já foi enraizado posso usar novamente
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
    a1->imprimeNivel(0);
    cout << endl;
    cout << "Media do nivel: " << a1->mediaNivel(0) << endl;



    return 0;
}
