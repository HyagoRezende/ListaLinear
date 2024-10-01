#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Paciente *OrdemChegada;

typedef struct Paciente
{
    unsigned int tempo;
    unsigned int critico;
    OrdemChegada prox;
} Paciente;

int CriaOrdemNula(OrdemChegada *p){
    (*p) = NULL;
    return(1);
}

void InsereInicio(OrdemChegada *p, Paciente paciente){
    OrdemChegada q;

    q = (OrdemChegada)malloc(sizeof(Paciente));

    if(q != NULL){
        q->tempo   = paciente.tempo;
        q->critico = paciente.critico;
        q->prox    = (*p);
        (*p)       = q;
    }
}

void InsereFinal(OrdemChegada *p, Paciente paciente){
    OrdemChegada q,r;

    if((*p)==NULL){
        InsereInicio(p,paciente);
    }
    else{
        q = (OrdemChegada)malloc(sizeof(Paciente));

        if(q != NULL){
            q->tempo   = paciente.tempo;
            q->critico = paciente.critico;
            q->prox    = NULL;

            r = (*p);
            while(r->prox != NULL){
                r = r->prox;
            }
            r->prox = q;
        }
    }
}


int ProcuraCondicaoCritica(OrdemChegada *p)
{
    int tempo,critico=0;
    OrdemChegada q,r;
    q = (*p);
    tempo = (q->tempo) + 30;
    while (q->prox != NULL)
    {
        r = q->prox;
        if((r->critico)+(r->tempo) < tempo){
            critico++;
            tempo += 30;
            q = q->prox;
        }
        else{
            tempo += 30;
            q = q->prox;
        }
    }
    return(critico);
}

int main()
{
    unsigned int hora, minuto;
    unsigned int qtdPacientes, i;
    OrdemChegada ordem;
    Paciente paciente;

    CriaOrdemNula(&ordem);

    scanf("%u", &qtdPacientes);
    i = qtdPacientes;

    while (i > 0)
    {
        scanf("%u %u %u", &hora, &minuto, &paciente.critico);
        paciente.tempo = ((hora*60) + minuto);
        InsereFinal(&ordem, paciente);
        i--;
    }
    printf("%d\n", ProcuraCondicaoCritica(&ordem));
}