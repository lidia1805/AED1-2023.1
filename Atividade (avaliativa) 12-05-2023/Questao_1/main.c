int main() {
    Cubo cubo = criar_cubo(3.5, 2.0, 4.8);

    printf("Comprimento do cubo: %.2f\n", obter_comprimento(cubo));
    printf("Largura do cubo: %.2f\n", obter_largura(cubo));
    printf("Altura do cubo: %.2f\n", obter_altura(cubo));
    printf("Área total do cubo: %.2f\n", calcular_area(cubo));
    printf("Volume do cubo: %.2f\n", calcular_volume(cubo));

    return 0;
}
