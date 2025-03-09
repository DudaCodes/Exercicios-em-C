#include <stdio.h>
#include <stdlib.h>
//calculadora que leia 2 numeros e realize as 4 operações básicas

void menu(); // declaração da função menu

void soma(){
    float num1, num2, resultado; // declaração de variáveis
    printf("Digite o primeiro número: "); 
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    resultado = num1 + num2; // operação de soma
    printf("O resultado da soma é: %.2f\n", resultado);
    menu();
}

void subtrair(){
    float num1, num2, resultado; // declaração de variáveis
    printf("Digite o primeiro número: "); 
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    resultado = num1 - num2; // operação de subtração
    printf("O resultado da subtração é: %.2f\n", resultado);
    menu();
}

void multiplicacao(){
    float num1, num2, resultado; // declaração de variáveis
    printf("Digite o primeiro número: "); 
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    resultado = num1 * num2; // operação de multiplicação
    printf("O resultado da multiplicação é: %.2f\n", resultado);
    menu();
}

void divisao(){
    float num1, num2, resultado; // declaração de variáveis
    printf("Digite o primeiro número: "); 
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    resultado = num1 / num2; // operação de divisão
    printf("O resultado da divisão é: %.2f\n", resultado);
    menu();
}

void menu() {
    int opcao;

    printf("Seja bem-vindo a calculadora simples\n");

    printf("Escolha uma operação matemática: \n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("5 - Sair\n");
    scanf("%d", &opcao); //armazena a opção escolhida

    switch(opcao){
        case 1:
            soma();
            break;
        case 2:
            subtrair();
            break;
        case 3:
            multiplicacao();
            break;
        case 4:
            divisao();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
            menu();
    }
}

int main(){
    menu();
    return 0;
}
