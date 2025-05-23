#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_TEL 15
#define MAX_EMAIL 50

// estrutura para armazenar os dados do contato
typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TEL];
    char email[MAX_EMAIL];
} Contato;

//função para validar se o telefone contém apenas números
int validarNumero(char *telefone) {
    size_t len = strlen(telefone);
    for (size_t i = 0; i < len; i++) {
        if (telefone[i] < '0' || telefone[i] > '9') {
            return 0; // se encontrar um caractere que não seja número, retorna falso
        }
    }

    return 1; // se todos os caracteres forem números, retorna verdadeiro
}

//função para adicionar um contato
void adicionarContato() {
    FILE *arquivo = fopen("contatos.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Contato contato;
    printf("Nome: ");
    scanf(" %[^\n]", contato.nome);

    //valida o telefone
    do{ 
    printf("Telefone: ");
    scanf(" %[^\n]", contato.telefone);

    if (!validarNumero(contato.telefone)) {
        printf("Telefone inválido! Digite apenas números.\n");
    }
    } while (!validarNumero(contato.telefone));

    printf("Email: ");
    scanf(" %[^\n]", contato.email);

    //salva o contato no arquivo
    fprintf(arquivo, "%s|%s|%s\n", contato.nome, contato.telefone, contato.email);
    fclose(arquivo);

    printf("Contato adicionado com sucesso!\n");
}

//função para listar os contatos
void listarContatos() {
    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum contato encontrado!\n");
        return;
    }
    //lê os contatos do arquivo e exibe na tela
    Contato contato;
    printf("\nLista de Contatos:\n");
    while (fscanf(arquivo, " %[^|]|%[^|]|%[^\n]\n", contato.nome, contato.telefone, contato.email) != EOF) { //lê os dados do contato
        printf("Nome: %s\nTelefone: %s\nEmail: %s\n\n", contato.nome, contato.telefone, contato.email); //exibe os dados do contato
    }

    fclose(arquivo); //fecha o arquivo
}

//função para buscar um contato
void buscarContato() {
    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum contato encontrado!\n");
        return;
    }
    //lê o nome do contato a ser buscado
    char nomeBusca[MAX_NOME];
    Contato contato;
    int encontrado = 0;

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", nomeBusca);

    //busca o contato no arquivo
    while (fscanf(arquivo, " %[^|]|%[^|]|%[^\n]\n", contato.nome, contato.telefone, contato.email) != EOF) {
        if (strcmp(nomeBusca, contato.nome) == 0) {
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n\n", contato.nome, contato.telefone, contato.email);
            encontrado = 1;
            break;
        }
    }
    //exibe mensagem se o contato não for encontrado
    if (!encontrado) {
        printf("Contato não encontrado!\n");
    }
    //fecha o arquivo
    fclose(arquivo);
}

//função principal
int main() {
    int opcao;

    //menu de opções
    do {
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        //chama a função de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                buscarContato();
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
