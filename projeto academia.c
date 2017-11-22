#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
// STRUCT
typedef struct medidas{
float biceps;
float  triceps;
float peito;
float coxa;
int kg;
}Medidas;

typedef struct lista{
char nome[80];
char sexo;
int cpf;
int idade;
int celular;
char cidade [30];
char email[30];
int data;
Medidas medidas;
struct lista* prox;

}Lista;


// ASSINATURAS DAS FUNÇÕES

int menuPrincipal(void);
Lista* Dadospessoais(Lista* Aluno);
void cadastroSerie(void);
void desenvolvimentoAluno(void);
int financeiro(void);
int menuAluno(void);
Lista* criarLista();
Lista* inserir_dados(Lista *aluno,char *nome,char sexo,int cpf,int idade,int celular,char *cidade,char *email,int data);
Lista* remover_cpf(Lista* Aluno,int valor);
void Atualizar_dados(Lista* Aluno, int cpf);
void imprimir_dados(Lista* Aluno);
Lista* inserir_Medidas(Lista* Aluno, int cpf);
void Saude_Aluno(Lista* Aluno,int cpf);
void salvar(Lista* Aluno);
// ESSA FUNÇÃO IRÁ CHAMAR A OUTRAS FUNÇÕES APENAS

int main(void){
	setlocale(LC_ALL, "portuguse");

    Lista* Aluno=criarLista();

    int opc;
    int cpf;
    int acesso;
    inicio:
    opc=menuPrincipal();

    switch (opc)
    {
    case 1:

        acesso=menuAluno();

        switch (acesso)
        {
        case 1:
            Aluno=Dadospessoais(Aluno);
            break;
        case 2:
            Aluno=inserir_Medidas(Aluno,cpf);
            break;
        case 3:
            printf("Informe o CPF para pesquisar : ");
            scanf("%d",&cpf);
            Atualizar_dados(Aluno,cpf);
            break;
        case 4:
            printf("Informe o CPF do aluno para excluir cadastro :");
            scanf("%d",&cpf);
            remover_cpf(Aluno,cpf);

        }
        break;
    case 2:
        Saude_Aluno(Aluno,cpf);
        break;
    case 3:
        desenvolvimentoAluno();
        break;
    case 4:
        financeiro();
        break;
    case 5:
        imprimir_dados(Aluno);
    case 0:
        exit(0);
    default:
        printf("valor invalido");
        break;
    }

goto inicio;
	return 0;
}

// FUNÇÕES

int menuPrincipal(void){
	int escolha;

	{
	printf("                -----------------------------------\n");
	printf("                #   1 - CADASTRO DE ALUNO         #\n");
	printf("                #   2 - BUSCAR SAÚDE DO ALUNO     #\n");
	printf("                #   3 - DESENVOLVIMENTO DE ALUNO  #\n");
	printf("                #   4 - FINANCEIRO                #\n");
	printf("                #   5 imprimir                    #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opção: ");
	scanf("%d", &escolha);

	return escolha;
	}
}
int menuAluno(void){
	int escolha;{
	printf("               -----------------------------------\n");
	printf("               #   1 - CADASTRAR DADOS PESSOAIS  #\n");
	printf("               #   2 - CADASTRAR MEDIÇÃO         #\n");
	printf("               #   3 - ATUALIZAR DADOS           #\n");
	printf("               #   4 - EXCLUIR CADASTRO          #\n");
	printf("               #                                 #\n");
	printf("               #   0 - SAIR                      #\n");
	printf("               -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opção: ");
	scanf("%d", &escolha);

	return escolha;
	}
}

Lista* Dadospessoais(Lista* Aluno){
	printf("CADASTRO DE ALUNO!\n");

	Lista *novo=malloc(sizeof(Lista));
	printf("Nome do Usuario : \n");
	scanf(" %80[^\n]",novo->nome);
	fflush(stdin);
	printf("informe o sexo (M) ou (F) : \n");
	scanf("%s",&novo->sexo);
	fflush(stdin);
	printf("\nInforme seu CPF: ");
	scanf("%d",&novo->cpf);
	fflush(stdin);
	printf("\ninforme a idade : ");
	scanf("%d",&novo->idade);
	fflush(stdin);
	printf("\ninforme o celular : ");
	scanf("%d",&novo->celular);
	fflush(stdin);
	printf("\ninforme a cidade : ");
	scanf(" %80[^\n]",novo->cidade);
	fflush(stdin);
	printf("\ninforme o E-MAIL : ");
	scanf(" %80[^\n]",novo->email);
	fflush(stdin);
	printf("\nInforme a data de Nascimento : ");
	scanf("%d",&novo->data);
	fflush(stdin);
	printf("\n\nCADASTRO CONCLUIDO !! \n\n");
	Aluno=inserir_dados(novo,novo->nome,novo->sexo,novo->cpf,novo->idade,novo->celular,novo->cidade,novo->email,novo->data);
	return Aluno;
	}

Lista* inserir_Medidas(Lista* Aluno, int cpf){
    int cpf1;
    printf("\n\n~~ MEDIDAS~~\n\n");
    printf("DIGITE O CPF PARA INSERIR AS MEDIDAS : ");
    scanf("%d",&cpf1);
    Lista* p;
for (p=Aluno;p!=NULL;p=p->prox){
    if(p->cpf==cpf1){
    printf("informe o Peso do Aluno : ");
    scanf("%d",&p->medidas.kg);
    printf("informe o Biceps : ");
    scanf("%f",&p->medidas.biceps);
    printf("Informe o Triceps : ");
    scanf("%f",&p->medidas.triceps);
    printf("Informe o peitoral : ");
    scanf("%f",&p->medidas.peito);
    printf("Informe a medida das pernas : ");
    scanf("%f",&p->medidas.coxa);
    printf("\n\n MEDIDAS REGISTRADAS COM SUCESSO !!\n\n");
    }
    else
        printf("\n\nCPF NÃO ENCONTRADO\n\n");
return Aluno;

}
}

void Atualizar_dados(Lista* Aluno, int cpf){
Lista* p;
for (p=Aluno;p!=NULL;p=p->prox){
    if(p->cpf==cpf){
    printf("\n\n ~~ATUALIZAR CADASTRO~~\n\n");
	printf("Nome do Usuario : ");
	scanf(" %80[^\n]",p->nome);
	fflush(stdin);
	printf("informe o sexo (M) ou (F) : \n");
	scanf("%s",&p->sexo);
	fflush(stdin);
	printf("\nInforme seu CPF: ");
	scanf("%d",&p->cpf);
	fflush(stdin);
	printf("\ninforme a idade : ");
	scanf("%d",&p->idade);
	fflush(stdin);
	printf("\ninforme o celular : ");
	scanf("%d",&p->celular);
	fflush(stdin);
	printf("\ninforme a cidade : ");
	scanf(" %80[^\n]",p->cidade);
	fflush(stdin);
	printf("\ninforme o E-MAIL : ");
	scanf(" %80[^\n]",p->email);
	fflush(stdin);
	printf("\nInforme a data de Nascimento : ");
	scanf("%d",&p->data);
	fflush(stdin);
    }
    }
    return Aluno;
}


void imprimir_dados(Lista* Aluno){
Lista* p;
for (p=Aluno;p!=NULL;p=p->prox){
	printf("\n Nome do Usuario %s\n",p->nome);
	printf("\n sexo %c",p->sexo);
	printf("\ncpf %d",p->cpf);
	printf("\nidade %d",p->idade);
	printf("\ncelular %d",p->celular);
	printf("\ncidade %s",p->cidade);
	printf("\n E-MAIL %s",p->email);
	printf("\ndata de Nascimento %d",p->data);

	}
}

void Saude_Aluno(Lista* Aluno,int cpf){
    int cpf2;
	printf("\n\nSAUDE DO ALUNO\n\n");
	printf("Informe o CPF do Aluno : ");
	scanf("%d",&cpf2);

	}

void desenvolvimentoAluno(void){
	printf("DESENVOLVIMENTO DE ALUNO!\n");
	}
int financeiro(void){
    int escolha;
    do{
	printf("FINANCEIRO!\n");
	printf("                -----------------------------------\n");
	printf("                #   1 - ALUNOS EM ATRASOS         #\n");
	printf("                #   2 - DESPESAS DA ACADEMIA      #\n");
	printf("                #   3 - ALIUNOS ATIVOS            #\n");
	printf("                #   4 - RELATORIOS                #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opção: ");
	scanf("%d", &escolha);
    }while(escolha>4);
    return escolha;
}

Lista* criarLista(){
return NULL;

}
Lista* inserir_dados(Lista *aluno,char *nome,char sexo,int cpf,int idade,int celular,char *cidade,char *email,int data){
Lista* p=aluno;
// RECEBE A LISTA ALUNO
Lista* ant=NULL;
// GUARDA A POSIÇÃO ANTERIOR
Lista* novo=(Lista*)malloc(sizeof(Lista));
// adiciona nome
strcpy(novo->nome, nome);
novo->sexo;
novo->cpf=cpf;
novo->idade=idade;
novo->celular=celular;
strcpy(novo->cidade, cidade);
strcpy(novo->email,email);
novo->data=data;
novo->prox=NULL;
// Lista vazia ?
if (p==NULL){
        // guarda o novo
    return novo;
}
while ((p!=NULL)&& strcmp(novo->nome,p->nome)>0) {
    // guarda as posições anteriores
    ant=p;
    // ir para o proximo
    p=p->prox;
}// nao entendi
 if (ant==NULL){
    novo->prox=p;
    return novo;
 }// novo prox aponta para ant que aponta para o proximo
 // entao o anterior agora aponta para novo
 novo->prox=ant->prox;
 ant->prox=novo;
 return aluno;

}
Lista* remover_cpf(Lista* Aluno,int valor){
Lista* ant=NULL;
Lista* p=Aluno; // p é aux pra percorrer
while(p!=NULL && p->cpf!=valor){
    ant=p;
    p=p->prox;
}// caso ELE NAO ACHAR----
if (p==NULL)
    printf("ALUNO NÃO ENCONTRADO\n");
    return Aluno;
// ant é null so se for o primeiro elemento
if(ant==NULL){
    Aluno=p->prox;
}
else
    ant->prox=p->prox;
free(p);
printf(" CADASTRO REMOVIDO COM SUCESSO !");
return Aluno;
}


void salvar(Lista* Aluno){
FILE *s;
s=fopen("arquivo.txt","wt");{
Lista *salva;
for(salva=Aluno;salva!=NULL;salva=salva->prox){
        fprintf(s, "%s\n", salva->nome);
		fprintf(s, "%d\n", salva->cpf);
		fprintf(s, "%d\n", salva->idade);
		fprintf(s, "%s\n", salva->cidade);
		fprintf(s, "%d\n", salva->celular);
		fprintf(s, "%d\n", salva->data);
		fprintf(s, "%c\n", salva->sexo);
		fprintf(s, "%f\n", salva->medidas.biceps);
        fprintf(s, "%f\n", salva->medidas.coxa);
		fprintf(s, "%d\n", salva->medidas.kg);
		fprintf(s, "%f\n", salva->medidas.peito);
		fprintf(s, "%f\n", salva->medidas.triceps);
		fprintf(s, "%s\n", salva->email);

}
}
}
