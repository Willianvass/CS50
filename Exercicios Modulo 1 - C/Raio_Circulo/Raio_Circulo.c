#include <stdio.h>
#include <stdlib.h>

int main(){
    float raio;
    float areaCirculo;
    float area;
    const pi = 3.141592;

    printf("Qual o raio: ");
    scanf("%f", &raio);
    areaCirculo = pi*(raio*raio);
    printf("A area do circulo: %.2f", areaCirculo);
    return 0;
}
