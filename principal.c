//Felipe Silva Nogueira Correia
// João Pedrozo
// Unidade Osório
// 04/11/2020

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int velocidade_max;
    int hp;
} tipoCarta;

int empates = 0;
int pc = 0;
int user = 0;

tipoCarta baralho [5];
char cartasUsuario[3] = {0, 1, 3};

void criarBaralho(){
    // 
    for (int i = 1; i < 7; i++)
    {
        baralho[i].id = i;
        baralho[i].velocidade_max = rand() % 3 * 100 + rand() % 10 * 10;
        baralho[i].hp = rand() % 100 + 1;
    } 
}

void partida(){
    
    for (int i = 0; i < 3; i++)
    {
        int user_option = 0;
        printf("## SUPER TRUNFO ## \n");
        printf("Rodada %i \n", i);
         if (i==0)
        {
            mostrarCarta(baralho[1].id, baralho[1].velocidade_max, baralho[1].hp);
        } else if(i==1) {
            mostrarCarta(baralho[3].id, baralho[3].velocidade_max, baralho[3].hp);
        } else {
            mostrarCarta(baralho[5].id, baralho[5].velocidade_max, baralho[5].hp);
        }
        printf("Escolha a característica: \n");
        printf("1. Velocidade máxima \n");
        printf("2. HP \n");
        while (user_option != 1 && user_option != 2)
        {
            scanf("%d", &user_option);
        }
        printf("Opção: %i \n",user_option);
        if (i==0)
        {
            analiseJogada(user_option, 1, 2);
        } else if(i==1) {
            analiseJogada(user_option, 3, 4);
        } else {
            analiseJogada(user_option, 5, 6);
        }
    }

    if(user > pc){
        printf("VOCÊ GANHOU!! \n");
    } else if(pc > user){
        printf("VOCÊ PERDEU!! \n");
    } else {
        printf("EMPATOU!! \n");
    }
}

void analiseJogada(int opcaoUsuario, int cartaUsuario, int cartaPc){
    mostrarCarta(baralho[cartaUsuario].id, baralho[cartaUsuario].velocidade_max, baralho[cartaUsuario].hp);
    mostrarCarta(baralho[cartaPc].id, baralho[cartaPc].velocidade_max, baralho[cartaPc].hp);

    if(opcaoUsuario == 1) {
        if(baralho[cartaUsuario].velocidade_max > baralho[cartaPc].velocidade_max){
            printf("Valor do usuário %i x %i Valor do computador \n", baralho[cartaUsuario].velocidade_max, baralho[cartaPc].velocidade_max);
            printf("Você venceu! \n");
            user = user + 1;
        } else if (baralho[cartaUsuario].velocidade_max < baralho[cartaPc].velocidade_max){
            printf("Valor do usuário %i x %i Valor do computador \n", baralho[cartaUsuario].velocidade_max, baralho[cartaPc].velocidade_max);
            printf("Você perdeu! \n");
            pc = pc + 1;
        } else {
            printf("Valor do usuário %i x %i Valor do computador \n", baralho[cartaUsuario].velocidade_max, baralho[cartaPc].velocidade_max);
            printf("Empate! \n");
            empates = empates + 1;
        }
    } else {
         if(baralho[cartaUsuario].hp > baralho[cartaPc].hp){
            printf("Valor do usuário %i x %i Valor do computador \n", baralho[cartaUsuario].hp, baralho[cartaPc].hp);
            printf("Você venceu! \n");
            user = user + 1;
        } else if (baralho[cartaUsuario].hp < baralho[cartaPc].hp){
            printf("Valor do usuário %i x %i Valor do computador \n", baralho[cartaUsuario].hp, baralho[cartaPc].hp);
            printf("Você perdeu! \n");
            pc = pc + 1;
        } else {
            printf("Valor do usuário %i x %i Valor do computador \n", baralho[cartaUsuario].hp, baralho[cartaPc].hp);
            printf("Empate! \n");
            empates = empates + 1;
        }
    }
    sleep(2);
    printf("------------------ \n");
}

void mostrarCarta(int id, int vel, int hp){
    
    if(id == 1 || id == 3 || id == 5){
        printf("Sua carta...: ");
    } else {
        printf("Carta do comp...:");
    }
    
    printf("Id: %i - Vel. Máxima: %i - HP - %i \n", id,vel,hp);
}

int main(){
    srand(time(NULL));

    criarBaralho();

    partida();
}
