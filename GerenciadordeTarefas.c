#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100

// estrutura para armazenar os dados da tarefa
typedef struct {
    int id;
    char descricao[MAX_TAREFAS];
}Tarefa;

//função para adicionar uma tarefa
void adicionarTarefa() {
    FILE *arquivo = fopen("tarefas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    //lê a descrição da tarefa
    Tarefa tarefa;
    printf("Descrição: ");
    scanf(" %[^\n]", tarefa.descricao);
    //salva a tarefa no arquivo
    fprintf(arquivo, "%s\n", tarefa.descricao);
    fclose(arquivo); //fecha o arquivo

    printf("Tarefa adicionada com sucesso!\n");
}

//função para listar as tarefas
void listarTarefas() {
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhuma tarefa encontrada!\n");
        return;
    }
    //lê as tarefas do arquivo e exibe na tela
    Tarefa tarefa;
    while (fscanf(arquivo, " %[^\n]\n", tarefa.descricao) != EOF) {
        printf("Descrição: %s\n", tarefa.descricao);
    }

    fclose(arquivo);
}

//função para remover uma tarefa
void removerTarefa() {
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhuma tarefa encontrada!\n");
        return;
    }
    //lê o ID da tarefa a ser removida
    Tarefa tarefa;
    int id;
    printf("Digite o ID da tarefa a ser excluída: ");
    scanf("%d", &id);
    //cria um arquivo temporário para armazenar as tarefas
    FILE *temp = fopen("temp.txt", "w");
    while (fscanf(arquivo, "%d %[^\n]\n", &tarefa.id, tarefa.descricao) != EOF) {
        if (tarefa.id != id) {
            fprintf(temp, "%d %s\n", tarefa.id, tarefa.descricao);
        }
    }
    fclose(arquivo);
    fclose(temp);

    remove("tarefas.txt");
    rename("temp.txt", "tarefas.txt");

    printf("Tarefa excluída com sucesso!\n");
}

//função principal
int main(){
    int opcao;

    //menu de opções
    do{      
        printf("\n1 - Adicionar Tarefa\n");
        printf("2 - Listar Tarefas\n");
        printf("3 - Remover Tarefa\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        //chama a função de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                listarTarefas();
                break;
            case 3:
                removerTarefa();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
