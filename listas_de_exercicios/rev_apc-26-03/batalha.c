#include <stdio.h>

double fogo(int nivel){
    if(nivel == 1) return 2.0;
    if(nivel == 2) return 3.0;
    if(nivel == 3) return 5.0;
}
double agua(int nivel){
    if(nivel == 1) return 1.0;
    if(nivel == 2) return 2.5;
    if(nivel == 3) return 4.0;
}
double terra(int nivel){
    if(nivel == 1) return 2.5;
    if(nivel == 2) return 5.5;
    if(nivel == 3) return 7.0;
}

double calculaVantagem(int tipoPlayer, int tipoCPU){
    if(tipoPlayer == 2 && tipoCPU == 1) return 1.0;
    if(tipoPlayer == 2 && tipoCPU == 2) return 0.5;
    if(tipoPlayer == 2 && tipoCPU == 3) return 2.0;
    
    if(tipoPlayer == 3 && tipoCPU == 1) return 2.0;
    if(tipoPlayer == 3 && tipoCPU == 2) return 1.0;
    if(tipoPlayer == 3 && tipoCPU == 3) return 0.5;

    if(tipoPlayer == 1 && tipoCPU == 1) return 0.5;
    if(tipoPlayer == 1 && tipoCPU == 2) return 2.0;
    if(tipoPlayer == 1 && tipoCPU == 3) return 1.0;
}

double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU){
    if(tipoPlayer == 1){
        int multNivel = terra(nivelPlayer);
        int multTipo = calculaVantagem(tipoPlayer, tipoCPU);
        int dano = 100*multNivel*multTipo-defesaCPU;
        if(dano >= 0) return dano;
    }
    if(tipoPlayer == 2){
        int multNivel = fogo(nivelPlayer);
        int multTipo = calculaVantagem(tipoPlayer, tipoCPU);
        int dano = 100*multNivel*multTipo-defesaCPU;
        if(dano >= 0) return dano;
    }
    if(tipoPlayer == 3){
        int multNivel = agua(nivelPlayer);
        int multTipo = calculaVantagem(tipoPlayer, tipoCPU);
        int dano = 100*multNivel*multTipo-defesaCPU;
        if(dano >= 0) return dano;
    }
}
