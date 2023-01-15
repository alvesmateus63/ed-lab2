#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            // Menor sub-arvore direita
            /*
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
            */

            // Maior sub-arvore esquerda
            NoArv *aux = maiorSubArvEsq(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setEsq(auxRemove(p->getEsq(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

/* Exercícios */

/// Ex001

int ArvBinBusca::maior()
{
    if(!vazia()) {
        return auxMaior(raiz);
    } else {
        cout << "Arvore Vazia" << endl;
        exit(1);
    }   
}

int ArvBinBusca::auxMaior(NoArv *p)
{
    if(p != NULL) {
        if(p->getDir() == NULL) {
            return p->getInfo();
        } else {
            auxMaior(p->getDir());
        }
    }
}


/// Ex002

int ArvBinBusca::menor()
{
    if(!vazia()) {
        return auxMenor(raiz);
    } else {
        cout << "Arvore Vazia" << endl;
        exit(1);
    }
}

int ArvBinBusca::auxMenor(NoArv *p)
{
    if(p != NULL) {
        if(p->getEsq() == NULL) {
            return p->getInfo();
        } else {
            auxMenor(p->getEsq());
        }
    }
}


/// Ex003

void ArvBinBusca::removeMaior()
{
    if(!vazia()) {
        auxRemoveMaior(raiz);
    } else {
        cout << "Arvore Vazia" << endl;
        exit(1);
    }
}

void ArvBinBusca::auxRemoveMaior(NoArv *p)
{
    if(p != NULL) {
        if(p->getDir() == NULL) {
            remove(p->getInfo());
        } else {
            auxRemoveMaior(p->getDir());
        }
    }
}


/// Ex004

void ArvBinBusca::removeMenor()
{
    if(!vazia()) {
        auxRemoveMenor(raiz);
        // Jeito + simples
        /*
            int val = maior();
            remove(val);
        */
    } else {
        cout << "Arvore Vazia" << endl;
        exit(1);
    }
}

void ArvBinBusca::auxRemoveMenor(NoArv *p)
{
    if(p != NULL) {
        if(p->getEsq() == NULL) {
            remove(p->getInfo());
        } else {
            auxRemoveMenor(p->getEsq());
        }
    }
}


/// Ex005

int ArvBinBusca::contaParesCaminho(int x)
{
    if(!vazia()) {
        return auxContaParesCaminho(raiz, x);
    } else {
        cout << "Arvore Vazia" << endl;
        exit(1);
    }
}

int ArvBinBusca::auxContaParesCaminho(NoArv *p, int x)
{
    if(p->getInfo() < x) {
        if(p->getInfo() % 2 == 0)
            return auxContaParesCaminho(p->getDir(), x) + 1;
        else
            return auxContaParesCaminho(p->getDir(), x);
    } else if(p->getInfo() > x) {
        if(p->getInfo() % 2 == 0)
            return auxContaParesCaminho(p->getEsq(), x) + 1;
        else
            return auxContaParesCaminho(p->getEsq(), x);
    } else { // Nesse caso a raiz é o proprio valor
        if(p->getInfo() % 2 == 0)
            return 1;
        else    
            return 0;
    }
}


/// Ex006


NoArv* ArvBinBusca::maiorSubArvEsq(NoArv *p)
{
    NoArv *aux = p->getEsq();
    while(aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}   
