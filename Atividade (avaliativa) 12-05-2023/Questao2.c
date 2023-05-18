typedef struct {
    float parte_real;
    float parte_imaginaria;
} NumeroComplexo;

NumeroComplexo criar_complexo(float parte_real, float parte_imaginaria) {
    NumeroComplexo complexo;
    complexo.parte_real = parte_real;
    complexo.parte_imaginaria = parte_imaginaria;
    return complexo;
}

void destruir_complexo(NumeroComplexo complexo) {
    free(conplexo)
}

NumeroComplexo somar_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2) {
    NumeroComplexo resultado;
    resultado.parte_real = complexo1.parte_real + complexo2.parte_real;
    resultado.parte_imaginaria = complexo1.parte_imaginaria + complexo2.parte_imaginaria;
    return resultado;
}

NumeroComplexo subtrair_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2) {
    NumeroComplexo resultado;
    resultado.parte_real = complexo1.parte_real - complexo2.parte_real;
    resultado.parte_imaginaria = complexo1.parte_imaginaria - complexo2.parte_imaginaria;
    return resultado;
}

NumeroComplexo multiplicar_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2) {
    NumeroComplexo resultado;
    resultado.parte_real = complexo1.parte_real * complexo2.parte_real - complexo1.parte_imaginaria * complexo2.parte_imaginaria;
    resultado.parte_imaginaria = complexo1.parte_real * complexo2.parte_imaginaria + complexo1.parte_imaginaria * complexo2.parte_real;
    return resultado;
}

NumeroComplexo dividir_complexos(NumeroComplexo complexo1, NumeroComplexo complexo2) {
    NumeroComplexo resultado;
    float divisor = complexo2.parte_real * complexo2.parte_real + complexo2.parte_imaginaria * complexo2.parte_imaginaria;
    resultado.parte_real = (complexo1.parte_real * complexo2.parte_real + complexo1.parte_imagin
