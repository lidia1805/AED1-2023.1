#ifndef COMPLEXO_H_INCLUDE
#define COMPLEXO_H_INCLUDE

typedef struct {
    float parte_real;
    float parte_imaginaria;
} NumeroComplexo;

NumeroComplexo criar_complexo(float parte_real, float parte_imaginaria);

void destruir_complexo(NumeroComplexo complexo) ;

NumeroComplexo somar_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2);

NumeroComplexo subtrair_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2);

NumeroComplexo multiplicar_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2);

NumeroComplexo dividir_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2);
