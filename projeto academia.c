#include <stdio.h>
#include <locale.h>
// STRUCT
typedef struct lista{
char nome[50];
char sexo;
int cpf[12];
int idade [3];
int celular [12];
char cidade [30];
char email[30];
int data[20];
struct lista* prox;
}Lista;

// ASSINATURAS DAS FUNÇÕES

int menuPrincipal(void);
void cadastroAluno(void);
void cadastroSerie(void);
void desenvolvimentoAluno(void);
void financeiro(void);
Lista* criarLista();
// ESSA FUNÇÃO IRÁ CHAMAR A OUTRAS FUNÇÕES APENAS

int main(void){
	setlocale(LC_ALL, "portuguse");

    Lista* Aluno=criarLista();

    int opc;

    opc=menuPrincipal();

    switch (opc)
    {
    case 1:
        cadastroAluno();
        break;
    case 2:
        cadastroSerie();
        break;
    case 3:
        desenvolvimentoAluno();
        break;
    case 4:
        financeiro();
        break;
    default:
        printf("valor invalido");
        break;
    }


	return 0;
}

// FUNÇÕES

int menuPrincipal(void){
	int escolha;{
	printf("###################################\n");
	printf("#   1 - CADASTRO DE ALUNO         #\n");
	printf("#   2 - CADASTRO DE SÉRIE         #\n");
	printf("#   3 - DESENVOLVIMENTO DE ALUNO  #\n");
	printf("#   4 - FINANCEIRO                #\n");
	printf("#                                 #\n");
	printf("#   0 - SAIR                      #\n");
	printf("###################################\n");
	printf("\n");
	printf(">>> Escolha sua opção: ");
	scanf("%d", &escolha);

	return escolha;
	}
}
void cadastroAluno(void){
	printf("CADASTRO DE ALUNO!\n");
	}
void cadastroSerie(void){
	printf("CADASTRO DE SÉRIES!\n");
	}
void desenvolvimentoAluno(void){
	printf("DESENVOLVIMENTO DE ALUNO!\n");
	}
void financeiro(void){
	printf("FINANCEIRO!\n");
	}

Lista* criarLista(){
return NULL;

}
