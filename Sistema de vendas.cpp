#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LINE_SIZE 512

void read_line(char *buffer, int size){
    if(fgets(buffer, size, stdin) == NULL){
        buffer[0] = '\0';
        return;
    }
    size_t len = strlen(buffer);
    while(len > 0 && (buffer[len-1] == '\n' || buffer[len-1] == '\r')){
        buffer[len-1] = '\0';
        len--;
    }
}

void trim(char *s){
    char *start = s;
    while(*start == ' ' || *start == '\t') start++;
    if(start != s) memmove(s, start, strlen(start)+1);
    int len = strlen(s);
    while(len > 0 && (s[len-1] == ' ' || s[len-1] == '\t')){ s[len-1] = '\0'; len--; }
}

void wait_enter(){
    printf("\nPressione ENTER para voltar...");
    char tmp[10];
    read_line(tmp, sizeof(tmp));
}

void inserir_registro(int menuPrincipal){
    FILE *arquivo;
    char path[50];
    char line[LINE_SIZE];

    if(menuPrincipal == 1) strcpy(path, "clientes.txt");
    else if(menuPrincipal == 2) strcpy(path, "produtos.txt");
    else if(menuPrincipal == 3) strcpy(path, "fornecedores.txt");
    else strcpy(path, "vendas.txt");

    char CPF[32], nome[128], telefone[32];
    char codigo[32], codFornecedor[32], preco[32], email[128], data[32], total[32];
    char resp[10];

    do{
        arquivo = fopen(path, "a");
        if(arquivo == NULL){
            printf("Erro ao abrir arquivo %s.\n", path);
            return;
        }

        system("cls");
        printf("=== Inserir Registro (%s) ===\n\n", path);

        if(menuPrincipal == 1){
            printf("CPF: ");
            read_line(CPF, sizeof(CPF));
            trim(CPF);

            printf("Nome: ");
            read_line(nome, sizeof(nome));
            trim(nome);

            printf("Telefone: ");
            read_line(telefone, sizeof(telefone));
            trim(telefone);

            fprintf(arquivo, "%s\t%s\t%s\n", CPF, telefone, nome);
        }
        else if(menuPrincipal == 2){
            printf("Código: ");
            read_line(codigo, sizeof(codigo));
            trim(codigo);

            printf("Código do Fornecedor: ");
            read_line(codFornecedor, sizeof(codFornecedor));
            trim(codFornecedor);

            printf("Nome: ");
            read_line(nome, sizeof(nome));
            trim(nome);

            printf("Preço Unitário: ");
            read_line(preco, sizeof(preco));
            trim(preco);

            fprintf(arquivo, "%s\t%s\t%s\t%s\n", codigo, codFornecedor, nome, preco);
        }
        else if(menuPrincipal == 3){
            printf("Código: ");
            read_line(codigo, sizeof(codigo));
            trim(codigo);

            printf("Nome: ");
            read_line(nome, sizeof(nome));
            trim(nome);

            printf("Telefone: ");
            read_line(telefone, sizeof(telefone));
            trim(telefone);

            printf("Email: ");
            read_line(email, sizeof(email));
            trim(email);

            fprintf(arquivo, "%s\t%s\t%s\t%s\n", codigo, nome, telefone, email);
        }
        else {
            printf("Código da Venda: ");
            read_line(codigo, sizeof(codigo));
            trim(codigo);

            printf("Código do Produto: ");
            read_line(codFornecedor, sizeof(codFornecedor));
            trim(codFornecedor);

            printf("Data (dd/mm/aaaa): ");
            read_line(data, sizeof(data));
            trim(data);

            printf("Total: ");
            read_line(total, sizeof(total));
            trim(total);

            fprintf(arquivo, "%s\t%s\t%s\t%s\n", codigo, codFornecedor, data, total);
        }

        fclose(arquivo);

        do{
            printf("\nDeseja inserir outro registro (s/n)? ");
            read_line(resp, sizeof(resp));
        } while(!(resp[0]=='s' || resp[0]=='S' || resp[0]=='n' || resp[0]=='N'));

    } while(resp[0]=='s' || resp[0]=='S');
}

void consultar_registros(int menuPrincipal){
    FILE *arquivo;
    char path[50];
    char linha[LINE_SIZE];

    if(menuPrincipal == 1) strcpy(path, "clientes.txt");
    else if(menuPrincipal == 2) strcpy(path, "produtos.txt");
    else if(menuPrincipal == 3) strcpy(path, "fornecedores.txt");
    else strcpy(path, "vendas.txt");

    system("cls");
    printf("=== Consultar (%s) ===\n\n", path);

    arquivo = fopen(path, "r");
    if(arquivo == NULL){
        printf("Nenhum registro encontrado.\n");
        wait_enter();
        return;
    }

    while(fgets(linha, sizeof(linha), arquivo)){
        printf("%s", linha);
    }

    fclose(arquivo);
    wait_enter();
}

void alterar_registro(int menuPrincipal){
    FILE *arquivo, *temp;
    char path[50];
    char linha[LINE_SIZE];
    char busca[128];
    int encontrado = 0;

    if(menuPrincipal == 1) strcpy(path, "clientes.txt");
    else if(menuPrincipal == 2) strcpy(path, "produtos.txt");
    else if(menuPrincipal == 3) strcpy(path, "fornecedores.txt");
    else strcpy(path, "vendas.txt");

    system("cls");
    printf("=== Alterar (%s) ===\n\n", path);
    printf("Digite o identificador (CPF ou Código): ");
    read_line(busca, sizeof(busca));
    trim(busca);

    arquivo = fopen(path, "r");
    temp = fopen("temp.txt", "w");
    if(arquivo == NULL){
        printf("Arquivo não encontrado.\n");
        if(temp) fclose(temp);
        wait_enter();
        return;
    }

    if(menuPrincipal == 1){
        char CPF[64], telefone[64], nome[128];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok;

            tok = strtok(copy, "\t");
            if(tok == NULL) continue;
            strcpy(CPF, tok);
            trim(CPF);

            tok = strtok(NULL, "\t");
            if(tok == NULL) { strcpy(telefone, ""); }
            else { strcpy(telefone, tok); trim(telefone); }

            tok = strtok(NULL, "\n");
            if(tok == NULL) { strcpy(nome, ""); }
            else { strcpy(nome, tok); trim(nome); }

            if(strcmp(CPF, busca) == 0){
                encontrado = 1;
                printf("\nRegistro encontrado:\nCPF: %s\nTelefone: %s\nNome: %s\n\n", CPF, telefone, nome);
                printf("Novo nome: ");
                read_line(nome, sizeof(nome));
                trim(nome);
                printf("Novo telefone: ");
                read_line(telefone, sizeof(telefone));
                trim(telefone);

                fprintf(temp, "%s\t%s\t%s\n", CPF, telefone, nome);
            } else {
                fprintf(temp, "%s\t%s\t%s\n", CPF, telefone, nome);
            }
        }
    }
    else if(menuPrincipal == 2){
        char codigo[64], codFornecedor[64], nome[128], preco[64];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok;

            tok = strtok(copy, "\t");
            if(tok == NULL) continue;
            strcpy(codigo, tok); trim(codigo);

            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(codFornecedor, ""); else { strcpy(codFornecedor, tok); trim(codFornecedor); }
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(nome, ""); else { strcpy(nome, tok); trim(nome); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(preco, ""); else { strcpy(preco, tok); trim(preco); }

            if(strcmp(codigo, busca) == 0){
                encontrado = 1;
                printf("\nRegistro encontrado:\nCodigo: %s\nFornecedor: %s\nNome: %s\nPreco: %s\n\n", codigo, codFornecedor, nome, preco);
                printf("Novo nome: ");
                read_line(nome, sizeof(nome));
                trim(nome);
                printf("Novo preço: ");
                read_line(preco, sizeof(preco));
                trim(preco);

                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, codFornecedor, nome, preco);
            } else {
                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, codFornecedor, nome, preco);
            }
        }
    }
    else if(menuPrincipal == 3){
        char codigo[64], nome[128], telefone[64], email[128];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok;

            tok = strtok(copy, "\t"); if(tok==NULL) continue; strcpy(codigo, tok); trim(codigo);
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(nome, ""); else { strcpy(nome, tok); trim(nome); }
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(telefone, ""); else { strcpy(telefone, tok); trim(telefone); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(email, ""); else { strcpy(email, tok); trim(email); }

            if(strcmp(codigo, busca) == 0){
                encontrado = 1;
                printf("\nRegistro encontrado:\nCodigo: %s\nNome: %s\nTelefone: %s\nEmail: %s\n\n", codigo, nome, telefone, email);
                printf("Novo nome: ");
                read_line(nome, sizeof(nome));
                trim(nome);
                printf("Novo telefone: ");
                read_line(telefone, sizeof(telefone));
                trim(telefone);
                printf("Novo email: ");
                read_line(email, sizeof(email));
                trim(email);

                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, nome, telefone, email);
            } else {
                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, nome, telefone, email);
            }
        }
    }
    else {
        char codigo[64], codProduto[64], data[64], total[64];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok;

            tok = strtok(copy, "\t"); if(tok==NULL) continue; strcpy(codigo, tok); trim(codigo);
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(codProduto, ""); else { strcpy(codProduto, tok); trim(codProduto); }
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(data, ""); else { strcpy(data, tok); trim(data); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(total, ""); else { strcpy(total, tok); trim(total); }

            if(strcmp(codigo, busca) == 0){
                encontrado = 1;
                printf("\nRegistro encontrado:\nCodigo: %s\nProduto: %s\nData: %s\nTotal: %s\n\n", codigo, codProduto, data, total);
                printf("Nova data: ");
                read_line(data, sizeof(data));
                trim(data);
                printf("Novo total: ");
                read_line(total, sizeof(total));
                trim(total);

                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, codProduto, data, total);
            } else {
                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, codProduto, data, total);
            }
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(path);
    rename("temp.txt", path);

    if(!encontrado) printf("\nRegistro não encontrado.\n");
    else printf("\nRegistro atualizado com sucesso!\n");

    wait_enter();
}

void excluir_registro(int menuPrincipal){
    FILE *arquivo, *temp;
    char path[50];
    char linha[LINE_SIZE];
    char busca[128];
    int encontrado = 0;

    if(menuPrincipal == 1) strcpy(path, "clientes.txt");
    else if(menuPrincipal == 2) strcpy(path, "produtos.txt");
    else if(menuPrincipal == 3) strcpy(path, "fornecedores.txt");
    else strcpy(path, "vendas.txt");

    system("cls");
    printf("=== Excluir (%s) ===\n\n", path);
    printf("Digite o identificador (CPF ou Código): ");
    read_line(busca, sizeof(busca));
    trim(busca);

    arquivo = fopen(path, "r");
    temp = fopen("temp.txt", "w");
    if(arquivo == NULL){
        printf("Arquivo não encontrado.\n");
        if(temp) fclose(temp);
        wait_enter();
        return;
    }

    if(menuPrincipal == 1){
        char CPF[64], telefone[64], nome[128];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok = strtok(copy, "\t");
            if(tok==NULL) continue; strcpy(CPF, tok); trim(CPF);
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(telefone,""); else { strcpy(telefone, tok); trim(telefone); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(nome,""); else { strcpy(nome, tok); trim(nome); }

            if(strcmp(CPF, busca) == 0){
                encontrado = 1;
            } else {
                fprintf(temp, "%s\t%s\t%s\n", CPF, telefone, nome);
            }
        }
    }
    else if(menuPrincipal == 2){
        char codigo[64], codFornecedor[64], nome[128], preco[64];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok = strtok(copy, "\t");
            if(tok==NULL) continue; strcpy(codigo, tok); trim(codigo);
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(codFornecedor,""); else { strcpy(codFornecedor, tok); trim(codFornecedor); }
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(nome,""); else { strcpy(nome, tok); trim(nome); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(preco,""); else { strcpy(preco, tok); trim(preco); }

            if(strcmp(codigo, busca) == 0){
                encontrado = 1;
            } else {
                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, codFornecedor, nome, preco);
            }
        }
    }
    else if(menuPrincipal == 3){
        char codigo[64], nome[128], telefone[64], email[128];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok = strtok(copy, "\t");
            if(tok==NULL) continue; strcpy(codigo, tok); trim(codigo);
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(nome,""); else { strcpy(nome, tok); trim(nome); }
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(telefone,""); else { strcpy(telefone, tok); trim(telefone); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(email,""); else { strcpy(email, tok); trim(email); }

            if(strcmp(codigo, busca) == 0){
                encontrado = 1;
            } else {
                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, nome, telefone, email);
            }
        }
    }
    else {
        char codigo[64], codProduto[64], data[64], total[64];
        while(fgets(linha, sizeof(linha), arquivo)){
            char copy[LINE_SIZE];
            strcpy(copy, linha);
            char *tok = strtok(copy, "\t");
            if(tok==NULL) continue; strcpy(codigo, tok); trim(codigo);
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(codProduto,""); else { strcpy(codProduto, tok); trim(codProduto); }
            tok = strtok(NULL, "\t"); if(tok==NULL) strcpy(data,""); else { strcpy(data, tok); trim(data); }
            tok = strtok(NULL, "\n"); if(tok==NULL) strcpy(total,""); else { strcpy(total, tok); trim(total); }

            if(strcmp(codigo, busca) == 0){
                encontrado = 1;
            } else {
                fprintf(temp, "%s\t%s\t%s\t%s\n", codigo, codProduto, data, total);
            }
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(path);
    rename("temp.txt", path);

    if(!encontrado) printf("\nRegistro não encontrado.\n");
    else printf("\nRegistro excluído com sucesso!\n");

    wait_enter();
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int menuPrincipal = -1;
    int menuOperacao = -1;
    char line[64];

    while(1){
        system("cls");
        printf("=== Sistema de Gestão ===\n");
        printf("1 - Clientes\n");
        printf("2 - Produtos\n");
        printf("3 - Fornecedores\n");
        printf("4 - Vendas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        read_line(line, sizeof(line));
        menuPrincipal = atoi(line);

        if(menuPrincipal == 0){
            system("cls");
            printf("Encerrando o sistema...\n");
            break;
        }
        if(menuPrincipal < 0 || menuPrincipal > 4){
            printf("Opção inválida!\n");
            wait_enter();
            continue;
        }

        while(1){
            system("cls");
            printf("=== Menu de Operações ===\n");
            printf("1 - Inserir\n");
            printf("2 - Consultar\n");
            printf("3 - Alterar\n");
            printf("4 - Excluir\n");
            printf("0 - Voltar\n");
            printf("Escolha uma opção: ");
            read_line(line, sizeof(line));
            menuOperacao = atoi(line);

            if(menuOperacao == 0) break;

            switch(menuOperacao){
                case 1: inserir_registro(menuPrincipal); break;
                case 2: consultar_registros(menuPrincipal); break;
                case 3: alterar_registro(menuPrincipal); break;
                case 4: excluir_registro(menuPrincipal); break;
                default:
                    printf("Opção inválida!\n");
                    wait_enter();
                    break;
            }
        }
    }

    return 0;
}