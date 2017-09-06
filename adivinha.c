/*
 * Programa que sorteia um número entre 0 e 100 para ser adivinhado em até 10 tentativas
 * email: marcio [ at ] exacts.com.br
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes e definições
#define LINHA "************************************\n"
#define MEIO  "  * Esse é o Jogo de Adivinhação *\n"
#define NUMIN "\nInforme um número: "
#define FAIXA "\nEscolha um número entre 0 e "
#define FIM   "Número oculto é o "
#define NOK   "Errou!!\n"
#define OK    "Acertou!!\n"
#define TOP 100

//Globais
int numoculto;
int numdigitado;

//Prototipos
int infonumero();
int setNum();
void acertou();
void errou();

//Função main
int main() {
int numero, i;

//Garantir numero variado
srand(time(NULL));

//Cabeçalho
printf(LINHA);
printf(MEIO);
printf(LINHA);

//Mensagem inicial
printf("\n%s%d\n",FAIXA,TOP);

//Gerar inteiro aleatorio
numoculto = setNum();

for(i=1;i<=10;i++){
//Tentativa de acerto

printf("\n%d de %d >>",i,10);
numero = infonumero();
//Conferir e direcionar
if(numero==numoculto){
    acertou();
    break;
    }
    else {
        errou();
    }
}
//Apresentar número sorteado e sair
printf("\n%s%2d\n\n",FIM, numoculto);
return 0;
}
//Ler número digitado a comparar
int infonumero(){
printf(NUMIN);
scanf("%d",&numdigitado);
return numdigitado;
}
//Gerar aleatorio dentro de um limite
int setNum(){
int oculto;
oculto = rand() % TOP;
return oculto;
}
//Mensagem perdeu
void errou(){
printf(NOK);
return;
}
//Mensagem ganhou
void acertou(){
printf(OK);
return;
}
