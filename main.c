#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produtos {
    char nome[30];
    int id;
    int qtd;
    float preco;
} Prod;

size_t CadastroProduto(FILE * pf, int id, char * nome,  float preco, int qtd) {
    Prod x;
    strcpy(x.nome, nome);
    x.id = id;
    x.qtd = qtd;
    x.preco = preco;
    return fwrite(&x, sizeof(Prod), 1, pf);
}

void LerProduto(FILE * pf, char * nome) {
    Prod x;
    while(fread(&x, sizeof(Prod), 1, pf)) {
        if(strcmp(x.nome, nome) == 0) {
            printf("--==--==--==--==--==--==--==--\n");
            printf( "Id: %d\n", x.id);
            printf( "Nome: %s\n", x.nome);
            printf( "Preco: %.2f\n", x.preco);
            printf( "Quantidade: %d\n", x.qtd);
            printf("--==--==--==--==--==--==--==--\n");
            break;
        }
    }
}

void ListaProduto(FILE * pf) {
    Prod x;
    while(fread(&x, sizeof(Prod), 1, pf)) {
        printf("--==--==--==--==--==--==--==--\n");
        printf( "Id: %d\n", x.id);
        printf( "Nome: %s\n", x.nome);
        printf( "Preco: %.2f\n", x.preco);
        printf( "Quantidade: %d\n", x.qtd);
        printf("--==--==--==--==--==--==--==--\n");
    }
}

int main() {
    FILE * arquivo = NULL;
    int op;
    do {
        printf("\n\nEscolha uma opcao:\n\n");
        printf("Digite 1 para Adicionar um novo produto.\n");
        printf("Digite 2 para Buscar um produto pelo seu nome.\n");
        printf("Digite 3 para Atualizar um produto.\n");
        printf("Digite 4 para Listar todos produtos.\n");
        printf("Digite 5 para Remover um produto.\n");
        scanf("%d", &op);
        switch (op) {
            case 1: {
                Prod p;
                arquivo = fopen("produtos.bin", "wb"); // Abre o arquivo

                printf("\nNovo prodruto!\n\n");
                printf("Id: ");
                scanf("%d", &p.id);
                fflush(stdin);
                printf("Nome: ");
                gets(p.nome);
                printf("Preco: ");
                scanf("%f", &p.preco);
                printf("Quantidade: ");
                scanf("%d", &p.qtd);

                CadastroProduto(arquivo, p.id, p.nome, p.preco, p.qtd);

                fclose(arquivo); // Fecha o arquivo
                break;
            }
            case 2: {
                char nome[30], *pChar;
                pChar = nome;
                arquivo = fopen("produtos.bin", "rb"); // Abre o arquivo
                printf("\nBuscar prodruto pelo nome!\n\n");
                fflush(stdin);
                printf("Digite o nome do aquivo: ");
                gets(nome);
                LerProduto(arquivo, pChar);
                fclose(arquivo); // Fecha o arquivo
                break;
            }
            case 3: {

                break;
            }
            case 4: {
                arquivo = fopen( "produtos.bin", "rb"); // Abre o arquivo
                fflush(stdin);
                printf("\nLista de produtos!\n\n");
                ListaProduto(arquivo);
                fclose(arquivo); // Fecha o arquivo
                break;
            }
            case 5: {

                break;
            }
            default: {
                printf("\n\nDigito invalido!\n\n");
            }
        }
        system("cls");
    } while (op);
}