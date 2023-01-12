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
        /// Pré-ordem:
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
        /// In-ordem:
        /*
        auxImprime(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprime(p->getDir());
        */
        /// Pós-ordem:
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
    /// Se a raiz não for nula e não tiver filhos  uma folha
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
    auxImprimeNivel(raiz, k, 0);
}

void ArvBin::auxImprimeNivel(NoArv *p, int k, int atual)
{
    // O objetivo é imprimir tudo que está no nivel k (não descobrir em qual nivel esta o k)
    if(p != NULL) {
        if(atual == k)
            cout << p->getInfo() << " ";
        auxImprimeNivel(p->getEsq(), k, atual+1);
        auxImprimeNivel(p->getDir(), k, atual+1);
    }
}


/// Ex007

float ArvBin::mediaNivel(int k)
{
    auxMediaNivel(raiz, k, 0);
}

float ArvBin::auxMediaNivel(NoArv *p, int k, int atual)
{
    if(p != NULL) {
        int total = auxMediaNivel(p->getEsq(), k, atual+1) + auxMediaNivel(p->getDir(), k, atual+1);
        if(atual == k) {
            total += p->getInfo();
        }
        return total;
    }
}



