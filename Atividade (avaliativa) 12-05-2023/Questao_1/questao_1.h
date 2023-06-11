#ifndef CUBO_H_INCLUDE
#define CUBO_H_INCLUDE

typedef struct {
    float comprimento;
    float largura;
    float altura;
} Cubo;

Cubo criar_cubo(float comprimento, float largura, float altura);
float obter_comprimento(Cubo cubo);
float obter_largura(Cubo cubo);
float obter_altura(Cubo cubo;
float calcular_area(Cubo cubo);
float calcular_volume(Cubo cubo);
