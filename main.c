#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main()
{
    //Criação das filas de paciente, espera de exame, espera de laudo.
    Queue_Paciente *pacientes = QPaciente_create();
    Queue_Laudo *laudos = QLaudo_create();
    Fila_exam *fila_exames1 = fila_exame_create(); 
    //aparelhos e máquinas disponíveis
    int radiologistasDisp=3;
    int aparelhosDisp= 5;
    //declaração das variaveis de tempo e de contagem
    time_t tempo_simulacao;
    tempo_simulacao = time(NULL); 
    srand(time(0)); 
    int num_rand1;
  
  // condição temporária, usada no loop
  time_t tempo10;
  int tempo_espera;
  tempo10=time(NULL);
  int Temp_cond;
  while (time(NULL) - tempo_simulacao<=(time_t)42000){
      num_rand1 = (rand() % 5);
      
      if (num_rand1 == 0){
          Paciente *NovoP = Paciente_create(pacientes);
          QPaciente_inserir(pacientes, NovoP);
          Node_exames *NovoN = no_fila_exame_create(NovoP);
          QFilaExame_inserir(fila_exames1, NovoN);
          Node_exames *i;
          i=fila_exames1->front;
      }
    
      if (aparelhosDisp>0 && fila_exames1->front!=NULL){
        aparelhosDisp-=1;
        sleep(1);
        Laudo *l;
        // inicio exame e fim do exame
        // junto da criação do laudo

        l = Laudo_create(fila_exames1->front->id);
        QLaudo_inserir(laudos, l);
        
        Remover_primeiro_fila_exame(fila_exames1);      
        laudos->cont_laudos+=1;
        aparelhosDisp+=1;
      }

    
      if (radiologistasDisp>0 && laudos->front!=NULL){
        radiologistasDisp-=1;
        //sleep((rand()%21)+10);
        sleep(1);
        laudos->tempo_laudos+=laudos->front->tempo;
       
        laudos->cont_laudos_atrasados+=1;
        Temp_cond = laudos->front->condicao;
        //fim do laudo
        contagem_laudos(laudos, Temp_cond);
        Remover_primeiro_fila_laudo(laudos);
        radiologistasDisp+=1;  
     }
    
    if (time(NULL)-tempo10>10){
      sleep(2);
      system("clear");
      print_metricas(laudos);
      sleep(5);
      tempo10=time(NULL);
    }
  }
    free(laudos);
    free(fila_exames1);
    free(pacientes);
    printf("fim do loop");
    return 0;
}
