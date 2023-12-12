#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "queue.h"

Fila_exames *fila_exame_create(){
  Fila_exames *f=(Fila_exames*)malloc(sizeof(Fila_exames));
  f->front=NULL;
  f->rear=NULL;
  return f;
}

Laudo *Laudo_create(int x){
  Laudo *l = (Laudo*)malloc(sizeof(Laudo));
  l->next=NULL;
  l->id=x;
  
  srand(time(0));
  l->tempo=(rand() % 21)+10;
  int num;
  num = (rand() % 100) + 1;
  switch (num){
    //apendicite
    case 1 ... 15:
      l->condicao=1;
      break;
    //frat 
    case 16 ... 30:
      l->condicao=2;
      break;
    //bronq
    case 31 ... 50:
      l->condicao=3;
      break;
    //pneu
    case 51 ... 70:
      l->condicao=4;
      break;
    case 71 ... 100:
      l->condicao=5;
      break;
  }
  return l;
}

no_fila_exames *no_fila_exame_create(Paciente *p){
  no_fila_exames *n= (no_fila_exames*)malloc(sizeof(no_fila_exames));
  n->id=p->id;
  n->next=NULL;
  return n;
}

Paciente *Paciente_create(Queue_Paciente *q){
  Paciente *p = (Paciente*)malloc(sizeof(Paciente));
  strcpy(p->cpf, " ");
  strcpy(p->nome, " ");
  p->id= q->qnt+1;
  p->next=NULL;
  return p;
}

Queue_Paciente *QPaciente_create() {
  Queue_Paciente *q = (Queue_Paciente *)malloc(sizeof(Queue_Paciente));
  q->front = NULL;
  q->rear = NULL;
  q->qnt=0;
  return q;
}

Queue_Laudo *QLaudo_create() {
  Queue_Laudo *q = (Queue_Laudo *)malloc(sizeof(Queue_Laudo));
  q->front = NULL;
  q->rear = NULL;
  q->cont_laudos=0;
  q->cont_laudos_atrasados=0;
  q->cont_laudos_apendicite=0;
  q->cont_laudos_bronquite=0;
  q->cont_laudos_fratura=0;
  q->cont_laudos_pneumonia=0;
  q->tempo_laudos=0;
  q->tempo_laudos_apendicite=0;
  q->tempo_laudos_bronquite=0;
  q->cont_laudos_pneumonia=0;
  q->tempo_laudos_fratura=0;
  return q;
}

void QPaciente_inserir(Queue_Paciente *fila, Paciente *n){
  if (fila->front==NULL){
    fila->front=n;
    fila->rear=n;
    fila->qnt+=1;
  }
  else{
    fila->rear->next=n;
    fila->rear=n;
    fila->qnt+=1;
  }
}

void QLaudo_inserir(Queue_Laudo *fila, Laudo *n){
  if (fila->front==NULL){
    fila->front=n;
    fila->rear=n;
  }
  else{
    fila->rear->next=n;
    fila->rear=n;   
  }
}

void QFilaExame_inserir(Fila_exames *fila, no_fila_exames *n){
  if (fila->front==NULL){
    fila->front=n;
    fila->rear=n;

  }
  else{
    fila->rear->next=n;
    fila->rear=n;
  }
}

void Remover_primeiro_fila_exame(Fila_exames *f){
  no_fila_exames *temp = (no_fila_exames*)malloc(sizeof(no_fila_exames));
  temp = f->front;
  f->front=f->front->next;
  free(temp);
}

void Remover_primeiro_fila_laudo(Queue_Laudo *l){
  Laudo *temp = (Laudo*)malloc(sizeof(Laudo));
  temp = l->front;
  l->front=l->front->next;
  free(temp);
}

void print_metricas(Queue_Laudo *l){
  printf("\nTempo médio dos laudos: %2.lf\n", l->tempo_laudos/l->cont_laudos);
  printf("\nTempo médio dos laudos de apendicite: %2.lf\n", l->tempo_laudos_apendicite/l->cont_laudos_apendicite);
  printf("\nTempo médio dos laudos de bronqueite: %2.lf\n", (l->tempo_laudos_bronquite)/l->cont_laudos_bronquite);
  printf("\nTempo médio dos laudos de fratura no femur: %2.lf\n", l->tempo_laudos_fratura/l->cont_laudos_fratura);
  printf("\nTempo médio dos laudos de pneumonia: %2.lf\n", l->tempo_laudos_pneumonia/l->cont_laudos_pneumonia);
  printf("\nLaudos totais: %d\n", l->cont_laudos_atrasados);
}

void contagem_laudos(Queue_Laudo *laudos, int Temp_cond){
  switch(Temp_cond){
    case 1:
      laudos->tempo_laudos_apendicite+=laudos->front->tempo;
      laudos->cont_laudos_apendicite+=1;
      
      break;
    case 2:
        laudos->tempo_laudos_fratura+=laudos->front->tempo;
        laudos->cont_laudos_fratura+=1;
        
        break;
    case 3:
        laudos->tempo_laudos_bronquite+=laudos->front->tempo;
        laudos->cont_laudos_bronquite+=1;
        
        break;
    case 4:
        laudos->tempo_laudos_pneumonia+=(laudos->front->tempo);
        laudos->cont_laudos_pneumonia+=1;
        
        break;
    case 5:
        break;
    }
  }
