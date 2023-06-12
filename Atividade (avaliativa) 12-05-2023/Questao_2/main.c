#include <stdio.h>
#include <stdlib.h>

#include "questao_2.h"

int main(){
NumeroComplexo complexo1 = criar_complexo(2.0, 3.0);
    NumeroComplexo complexo2 = criar_complexo(1.0, 4.0);

    NumeroComplexo soma = somar_complexos(complexo1, complexo2);
    printf("Soma: %.2f + %.2fi\n", soma.parte_real, soma.parte_imaginaria);

    NumeroComplexo subtracao = subtrair_complexos(complexo1, complexo2);
    printf("Subtração: %.2f + %.2fi\n", subtracao.parte_real, subtracao.parte_imaginaria);
}
