#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Arvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::imprime()
{
    cout << "Arvore Binaria: ";
    auxImprime(raiz);
    cout << endl;

}

void ArvBin::auxImprime(NoArv *p)
{
    if (p != NULL)
    {
        /// Pr�-ordem:
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
        /// In-ordem:
        /*
        auxImprime(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprime(p->getDir());
        */
        /// P�s-ordem:
        /*
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
        cout << p->getInfo() << " ";
        */
    }
}


/// Ex001

int ArvBin::contaNos()
{
    if(!vazia())
        return auxContaNos(raiz);
    else {
        cout << "A arvore eh vazia";
        exit(1);
    }
}

int ArvBin::auxContaNos(NoArv *p)
{
    if(p == NULL) {
        return 0;
    } else {
        return 1 + auxContaNos(p->getDir()) + auxContaNos(p->getEsq());
    }
}


/// Ex002

int ArvBin::contaNosFolhas()
{
    if(!vazia())
        return auxContaNosFolhas(raiz);
    else {
        cout << "A arvore eh vazia";
        exit(1);
    }
}

int ArvBin::auxContaNosFolhas(NoArv *p)
{
    /// Se a raiz for nula retorna 0
    if(p == NULL)
        return 0;
    /// Se a raiz n�o for nula e n�o tiver filhos  uma folha
    else if (p->getDir() == NULL && p->getEsq() == NULL)
        return 1;
    /// Se a raiz nao for nula  e tiver filhos devemos seguir
    else
        return auxContaNosFolhas(p->getDir()) + auxContaNosFolhas(p->getEsq());

}


/// Ex003

int ArvBin::altura()
{
    return auxAltura(raiz);
}


int ArvBin::auxAltura(NoArv *p)
{
    if(p == NULL)
        return -1;
    else {
        int he = auxAltura(p->getEsq());
        int hd = auxAltura(p->getDir());

        return (he > hd ? he : hd) + 1;
    }
}


/// Ex004

int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p)
{
    if(p == NULL)
        return 0;
    else {
        int total = auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
        if(p->getInfo() % 2 != 0)
            total++;
        return total;
    }

}


/// Ex005

int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}

int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if(p == NULL)
        return 0;
    else {
        int total = auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
        if(p->getEsq() == NULL && p->getDir() == NULL)
            if(p->getInfo() % 2 != 0)
                total++;
        return total;
    }
}


/// Ex006

void ArvBin::imprimeNivel(int k)
{
    cout << "Valores do nivel: ";
    auxImprimeNivel(raiz, k, 0);
}

void ArvBin::auxImprimeNivel(NoArv *p, int k, int atual)
{
    // O objetivo � imprimir tudo que est� no nivel k (n�o descobrir em qual nivel esta o k)
    if(p != NULL) {
        if(atual == k)
            cout << p->getInfo() << " ";
        else if (atual < k) {
            auxImprimeNivel(p->getEsq(), k, atual+1);
            auxImprimeNivel(p->getDir(), k, atual+1);
        }
    }
}


/// Ex007

float ArvBin::mediaNivel(int k)
{
    float soma = 0;
    int contador = 0;
    auxMediaNivel(raiz, k, &soma, &contador);
    if(contador > 0)
        return soma / contador;
    else
        return 0;
}

void ArvBin::auxMediaNivel(NoArv *p, int k, float *soma, int *contador)
{
    if(p != NULL && k >=0 ) {
        if(k == 0) {
            *soma += p->getInfo();
            (*contador)++;
        }
        auxMediaNivel(p->getEsq(), k-1, soma, contador);
        auxMediaNivel(p->getDir(), k-1, soma, contador);
    }
}


/// Ex 008

int ArvBin::min()
{
    if(raiz == NULL) {
        cout << "Arvore Vazia" << endl;
        exit(0);
    }

    int menor = raiz->getInfo();
    auxMin(raiz, &menor);
    return menor;
}

void ArvBin::auxMin(NoArv *p, int *menor) 
{
    if(p != NULL) {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();

        auxMin(p->getEsq(), menor);
        auxMin(p->getDir(), menor);
    }
}


int ArvBin::max()
{
    if(raiz == NULL) {
        cout << "Arvore Vazia" << endl;
        exit(0);
    }

    int maior = raiz->getInfo();
    auxMax(raiz, &maior);
    return maior;
}

void ArvBin::auxMax(NoArv *p, int *maior)
{
    if(p != NULL) {
        if(p->getInfo() > *maior)
            *maior = p->getInfo();

        auxMax(p->getEsq(), maior);
        auxMax(p->getDir(), maior);
    }
}


/// Ex 009

void ArvBin::inverte()
{
    if(!vazia())
        auxInverte(raiz);
    else {
        exit(1);
    }
}

void ArvBin::auxInverte(NoArv *p)
{
    if(p != NULL) {
        auxInverte(p->getDir());
        auxInverte(p->getEsq());

        NoArv *q = p->getDir();
        p->setDir(p->getEsq());
        p->setEsq(q);
    }
}


/// Ex 010

int ArvBin::noMaisEsquerda()
{
    return auxNoMaisEsquerda(raiz);
}

int ArvBin::auxNoMaisEsquerda(NoArv *p)
{
    if(p->getEsq() == NULL && p->getDir() == NULL)
        return p->getInfo();
    else 
        auxNoMaisEsquerda(p->getEsq());
}

int ArvBin::noMaisDireita()
{
    return auxNoMaisDireita(raiz);
}

int ArvBin::auxNoMaisDireita(NoArv *p)
{
    if(p->getEsq() == NULL && p->getDir() == NULL) 
        return p->getInfo();
    else
        auxNoMaisDireita(p->getDir());
}


/// Ex 011
/*
int ArvBin::minSubArvore(NoArv *p)
{
    if(p == NULL) {
        cout << "Arvore Vazia" << endl;
        exit(0);
    }

    int menor = p->getInfo();
    auxMinSubArvore(p, &menor);
    return menor;
}

int ArvBin::auxMinSubArvore(NoArv *p, int *menor)
{
    if(p != NULL) {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();

        auxMin(p->getEsq(), menor);
        auxMin(p->getDir(), menor);
    }
}    

int ArvBin::maxSubArvore(NoArv *p)
{
    if(p == NULL) {
        cout << "Arvore Vazia" << endl;
        exit(0);
    }

    int maior = p->getInfo();
    auxMaxSubArvore(p, &maior);
    return maior;
}

int ArvBin::auxMaxSubArvore(NoArv *p, int *maior)
{
    if(p != NULL) {
        if(p->getInfo() > *maior)
            *maior = p->getInfo();

        auxMin(p->getEsq(), maior);
        auxMin(p->getDir(), maior);
    }
}
*/

/// Ex012

bool ArvBin::ehABB()
{
    return auxEhABB(raiz);
}

bool ArvBin::auxEhABB(NoArv *p)
{
    if(p != NULL) {
        if(valor > p-getEsq())
            return false;
        else if (valor < p->getDir())
            return false;
        else
            return true;
    }
}