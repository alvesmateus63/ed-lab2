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
    int min();
    int max();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    int minSubArvore(NoArv *p);
    int maxSubArvore(NoArv *p);
    bool ArvBin::ehABB();

  private:
    NoArv *raiz; // ponteiro para o No raiz da arvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxImprime(NoArv *p);
    NoArv* auxMontaArvore();
    NoArv* auxInsere(NoArv *p, int x);
    /// Exercícios
    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    void auxImprimeNivel(NoArv *p, int k, int atual);
    void auxMediaNivel(NoArv *p, int k, float *soma, int *contador);
    void auxMin(NoArv *p, int *menor);
    void auxMax(NoArv *p, int *maior);
    void auxInverte(NoArv *p);
    int auxNoMaisEsquerda(NoArv *p);
    int auxNoMaisDireita(NoArv *p);
    int auxMinSubArvore(NoArv *p, int *menor);
    int auxMaxSubArvore(NoArv *p, int *maior);
    bool auxEhABB(NoArv *p);

};

#endif // ARVBIN_H_INCLUDED
