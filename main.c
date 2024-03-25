#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct CadastroReceita{
    char nomeReceita[50];
    char nomeIngrediente[50][50];
    int QuantIngrediente;
    int contaCadastro;
    int id;


};

FILE *file;


void MostraMenu(){
    printf("-----Menu Pizzaria-----");
    printf("\n1 - Cadastre uma receita");
    printf("\n2 - Mostrar receitas cadastradas");
    printf("\n3 - Editar receitas cadastradas");
    printf("\n4 - Deletar uma receita cadastrada");
    printf("\n0 - Sair");
}


void CadastraReceita(struct CadastroReceita *cadastro){
    printf("Insira o nome da receita:");
    fgets(cadastro->nomeReceita, sizeof(cadastro->nomeReceita), stdin);

    printf("Insira a quantidade de ingredientes:");
    scanf("%d", &cadastro->QuantIngrediente);
    getchar();
    printf("=====Insira os ingredientes=====\n");
    for(int i = 0; i < cadastro->QuantIngrediente; i++){
        printf("%d - ", i + 1);
        fgets(cadastro->nomeIngrediente[i], sizeof(cadastro->nomeIngrediente[i]), stdin);
        cadastro->nomeIngrediente[i][strcspn(cadastro->nomeIngrediente[i], "\n")] = '\0'; //Aqui retira o caractere \n no final da string
    }
    system("cls");
    printf("\nCadastro feito com sucesso!\n");
    cadastro->contaCadastro++;

}

void MostraCadastros(struct CadastroReceita *cadastro){
    printf("\n-------RECEITAS-------\n");
    printf("\nID RECEITA %d\n", cadastro->id);
    printf("Nome da receita: %s", cadastro->nomeReceita);
    for(int i = 0; i < cadastro->QuantIngrediente; i++){
        printf("\nIngrediente %d:%s\n", i + 1, cadastro->nomeIngrediente[i]);
    }
    printf("\n----------------------\n");
}

void DeletaReceita(struct CadastroReceita *cadastro){
    cadastro->contaCadastro = 0;
}

void InsereArquivo(FILE *file, struct CadastroReceita *cadastro){
    file = fopen("Receitas.txt", "a");
    fprintf(file,"----------------\n");
    fprintf(file, "RECEITA: %d\n",cadastro->id, cadastro->nomeReceita);

    for(int i = 0; i < cadastro->QuantIngrediente; i++){
        fprintf(file, "Ingrediente %d:%s\n", i + 1, cadastro->nomeIngrediente[i]);
    }
    fprintf(file,"----------------\n");

}



int main(int argc, char ** argv) {

    struct CadastroReceita cadastro1;
    struct CadastroReceita cadastro2;
    struct CadastroReceita cadastro3;
    struct CadastroReceita cadastro4;
    struct CadastroReceita cadastro5;
    cadastro1.contaCadastro = 0;
    cadastro2.contaCadastro = 0;
    cadastro3.contaCadastro = 0;
    cadastro4.contaCadastro = 0;
    cadastro5.contaCadastro = 0;
    int id;

    file = fopen("Receitas.txt", "w");



    int op = 999;
    while(op != 0){
            MostraMenu();
            printf("\nInsira sua opcao:");
            scanf("%d", &op);
            system("cls");
            getchar();
        switch(op){

        case 1:
            if(cadastro1.contaCadastro == 0){
                    cadastro1.id = 1;
                CadastraReceita(&cadastro1);

            break;
            }else if(cadastro2.contaCadastro == 0){
                cadastro1.id = 2;
                CadastraReceita(&cadastro2);
            break;

            }else if(cadastro3.contaCadastro == 0){
                cadastro1.id = 3;
                CadastraReceita(&cadastro3);
            break;

            }
            else if(cadastro4.contaCadastro == 0){
                    cadastro1.id = 4;
                CadastraReceita(&cadastro4);
            break;

            }
            else if(cadastro5.contaCadastro == 0){
                    cadastro1.id = 5;
                CadastraReceita(&cadastro5);
            break;

            }
            break;

        case 2:

            if(cadastro1.contaCadastro == 0 && cadastro2.contaCadastro == 0 && cadastro3.contaCadastro == 0 && cadastro4.contaCadastro == 0 && cadastro5.contaCadastro == 0)
                printf("\nNenhuma receita cadastrada!\n");

            if(cadastro1.contaCadastro == 1)
                MostraCadastros(&cadastro1);

            if(cadastro2.contaCadastro == 1)
                MostraCadastros(&cadastro2);

            if(cadastro3.contaCadastro == 1)
                MostraCadastros(&cadastro3);

            if(cadastro4.contaCadastro == 1)
                MostraCadastros(&cadastro4);

            if(cadastro5.contaCadastro == 1)
                MostraCadastros(&cadastro5);

            break;
        case 3:

            if(cadastro1.contaCadastro == 0 && cadastro2.contaCadastro == 0 && cadastro3.contaCadastro == 0 && cadastro4.contaCadastro == 0 && cadastro5.contaCadastro == 0){
                printf("\nNenhuma receita cadastrada!\n");
                break;
            }
            int opcao;
            printf("\nInsira o ID da receita que deseja editar:");
            scanf("%d", &opcao);
            getchar();
                switch(opcao){
                case 1:
                    cadastro1.contaCadastro = 0;
                    CadastraReceita(&cadastro1);
                    break;

                case 2:
                    if(cadastro2.contaCadastro == 0){
                        printf("\nId não cadastrado ainda!\n");
                        break;
                    }
                    cadastro2.contaCadastro = 0;
                    CadastraReceita(&cadastro2);
                    break;

                case 3:
                    if(cadastro3.contaCadastro == 0){
                        printf("\nId não cadastrado ainda!\n");
                        break;
                    }
                    cadastro3.contaCadastro = 0;
                    CadastraReceita(&cadastro3);
                    break;

                case 4:
                    if(cadastro4.contaCadastro == 0){
                        printf("\nId não cadastrado ainda!\n");
                        break;
                    }
                    cadastro4.contaCadastro = 0;
                    CadastraReceita(&cadastro4);
                    break;

                case 5:
                    if(cadastro5.contaCadastro == 0){
                        printf("\nId não cadastrado ainda!\n");
                        break;
                    }
                    cadastro5.contaCadastro = 0;
                    CadastraReceita(&cadastro5);
                    break;

                default:
                    printf("\nId de receita inválida!\n");
                    break;
                }

            break;

        case 4:

            if(cadastro1.contaCadastro == 0 && cadastro2.contaCadastro == 0 && cadastro3.contaCadastro == 0 && cadastro4.contaCadastro == 0 && cadastro5.contaCadastro == 0){
                printf("\nNenhuma receita cadastrada!\n");
                break;
            }
            printf("Insira a receita que deseja deletar:");
            scanf("%d", &id);
            system("cls");
            switch(id){
            case 1:
                DeletaReceita(&cadastro1);
                printf("Receita de ID %d deletada com sucesso!\n", cadastro1.id);
                break;

            case 2:
                if(cadastro2.contaCadastro == 0){
                    printf("Não existe receita 2!\n\n");
                    break;
                }
                DeletaReceita(&cadastro2);
                printf("Receita de ID %d deletada com sucesso!\n", cadastro2.id);
                break;
            case 3:
                if(cadastro3.contaCadastro == 0){
                    printf("Não existe receita 3!\n\n");
                    break;
                }
                DeletaReceita(&cadastro3);
                printf("Receita de ID %d deletada com sucesso!\n", cadastro3.id);
                break;
            case 4:
                if(cadastro4.contaCadastro == 0){
                    printf("Não existe receita 4!\n\n");

                    break;
                }
                DeletaReceita(&cadastro4);
                printf("Receita de ID %d deletada com sucesso!\n", cadastro4.id);
                break;

            case 5:
                if(cadastro5.contaCadastro == 0){
                    printf("Não existe receita 5!\n\n");
                    break;
                }
                DeletaReceita(&cadastro5);
                printf("Receita de ID %d deletada com sucesso!\n", cadastro5.id);
                break;
            default:
                printf("\n\nNenhuma receita selecionada.\n\n");
                break;
                }
            break;

        case 0:
            printf("Saindo...");
            if(cadastro1.contaCadastro == 1)
            InsereArquivo(file, &cadastro1);

            if(cadastro2.contaCadastro == 1)
            InsereArquivo(file, &cadastro2);

            if(cadastro3.contaCadastro == 1)
            InsereArquivo(file, &cadastro3);

            if(cadastro4.contaCadastro == 1)
            InsereArquivo(file, &cadastro4);

            if(cadastro5.contaCadastro == 1)
            InsereArquivo(file, &cadastro5);
            break;
        default:
            printf("----------------\n");
            printf("Opcao incorreta!!!\n");
            printf("-----------------\n\n");
            break;

        }

    }

    fclose(file);


	return 0;
}
