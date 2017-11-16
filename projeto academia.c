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
void Dadospessoais(void);
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
        Dadospessoais();
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
void Dadospessoais(void){
	printf("CADASTRO DE ALUNO!\n");
	Lista *cadastro=malloc(sizeof(Lista));
	printf("Nome do Usuario : ");
	scanf(" %80[^\n]",cadastro->nome);
	printf("informe o sexo (M) ou (F) : ");
	scanf("%c",cadastro->sexo);
	printf("Informe seu CPF: ");
	scanf("%d",&cadastro->cpf);
	printf("informe a idade : ");
	scanf("%d",&cadastro->idade);
	printf("informe o celular : ");
	scanf("%d",&cadastro->celular);
	printf("informe a cidade : ");
	scanf(" %80[^\n]",cadastro->cidade);
	printf("informe o E-MAIL : ");
	scanf(" %80[^\n]",cadastro->email);
	printf("Informe a data de Nascimento : ");
	scanf("%d",&cadastro->data);

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
