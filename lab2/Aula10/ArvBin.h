#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int x);
    void imprime();
    void montaArvore();
    void insere(int x);
    /// Exercícios
    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);


  private:
    NoArv *raiz; // ponteiro para o No raiz da arvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxImprime(NoArv *p);
    NoArv* auxMontaArvore();
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    /// Exercícios
    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    void auxImprimeNivel(NoArv *p, int k, int atual);
    float auxMediaNivel(NoArv *p, int k, int atual);
};

#endif // ARVBIN_H_INCLUDED
