#include <stdio.h>
#include <stdlib.h>

#include "Cubo.h"

Cubo criar_cubo(float comprimento, float largura, float altura) {
    Cubo cubo;
    cubo.comprimento = comprimento;
    cubo.largura = largura;
    cubo.altura = altura;
    return cubo;
}


float obter_comprimento(Cubo cubo) {
    return cubo.comprimento;
}

float obter_largura(Cubo cubo) {
    return cubo.largura;
}

float obter_altura(Cubo cubo) {
    return cubo.altura;
}

float calcular_area(Cubo cubo) {
    float area_total = 2 * (cubo.comprimento * cubo.largura + cubo.largura * cubo.altura + cubo.altura * cubo.comprimento);
    return area_total;
}

float calcular_volume(Cubo cubo) {
    float volume = cubo.comprimento * cubo.largura * cubo.altura;
    return volume;
}
