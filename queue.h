#ifndef QUEUE_H
#define QUEUE_H
#include <time.h>

typedef struct Node_exames Node_exames;

typedef struct Fila_exam Fila_exam;

typedef struct Paciente Paciente;

typedef struct Laudo Laudo;

typedef struct Queue_Paciente Queue_Paciente;

typedef struct Queue_Laudo Queue_Laudo;

typedef struct Node_exames {
  int id;
  struct Node_exames *next;
} no_fila_exames;

typedef struct Fila_exam {
  no_fila_exames *front;
  no_fila_exames *rear;
} Fila_exames;

typedef struct Paciente {
  struct Paciente *next;
  char cpf[13];
  char nome[50];
  int id;
} Paciente;

typedef struct Laudo {
  struct Laudo *next;
  int id;
  int tempo;
  int condicao;
  
} Laudo;

typedef struct Queue_Paciente {
  Paciente *front;
  Paciente *rear;
  int qnt;
} Queue_Paciente;

typedef struct Queue_Laudo {
  Laudo *front;
  Laudo *rear;
  int quant;
  int cont_laudos_atrasados;
  double tempo_laudos_pneumonia;
  int cont_laudos_pneumonia;
  double tempo_laudos_bronquite;
  int cont_laudos_bronquite;
  double tempo_laudos_fratura;
  int cont_laudos_fratura;
  double tempo_laudos_apendicite;
  int cont_laudos_apendicite;
  double tempo_laudos;
  int cont_laudos;
} Queue_Laudo;


extern Queue_Paciente *QPaciente_create();

Laudo *Laudo_create(int id);

extern Queue_Laudo *QLaudo_create();

extern Paciente *Paciente_create();

extern void QPaciente_inserir(Queue_Paciente *fila, Paciente *n);

extern void QLaudo_inserir(Queue_Laudo *fila, Laudo *n);

extern Fila_exam *fila_exame_create();

extern Node_exames *no_fila_exame_create(Paciente *p);

extern void QFilaExame_inserir(Fila_exam *fila, Node_exames *n);

extern void Remover_primeiro_fila_exame(Fila_exam *f);

extern void Remover_primeiro_fila_laudo(Queue_Laudo *l);

extern void print_metricas(Queue_Laudo *l);

extern void contagem_laudos(Queue_Laudo *l, int Temp);

#endif
