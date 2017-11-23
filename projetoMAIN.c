#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

// STRUCT

typedef struct medidas{
	char biceps[5];
	char triceps[5];
	char peito[5];
	char coxa[5];
	char kg[5];
} Medidas;

typedef struct lista{
	char nome[80];
	char sexo[10];
	int cpf;
	char idade[5];
	char telefone[12];
	char cidade[30];
	char email[31];
	char nasc[11];
	Medidas medidas;
	struct lista* prox;
} Lista;


// ASSINATURAS DAS FUNÇÕES

int menuPrincipal(void);
Lista* Dadospessoais(Lista* Aluno);
void cadastroSerie(void);
void desenvolvimentoAluno(void);
int financeiro(void);
int menuAluno(void);
Lista* criarLista();
Lista* inserir_dados(Lista *aluno, char *nome, char *sexo, int cpf, char *idade, char *telefone, char *cidade, char *email, char *nasc);
Lista* remover_cpf(Lista* Aluno,int valor);
void Atualizar_dados(Lista* Aluno, int cpf);
void imprimir_dados(Lista* Aluno);
Lista* inserir_Medidas(Lista* Aluno, int cpf);
void Saude_Aluno(Lista* Aluno,int cpf);
void salvar(Lista* Aluno);
int validaNome(char nome[81]);
int validaSexo(char sexo[9]);
int validaIdade(char idade[5]);
int validaCidade(char cidade[51]);
int validaTelefone(char telefone[12]);
int validaEmail(char email[31]);
int validaNasc(char nasc[11]);
int validaPeso(char peso[5]);
int validaBiceps(char biceps[5]);
int validaTriceps(char triceps[5]);
int validaCoxa(char coxa[5]);
int validaPeitoral(char peitoral[5]); 

// ESSA FUNÇÃO IRÁ CHAMAR A OUTRAS FUNÇÕES APENAS

int main(void){
	setlocale(LC_ALL, "portuguese");

    Lista* Aluno=criarLista();

    int opc;
    int cpf;
    int acesso;
    inicio:
    opc = menuPrincipal();

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
	printf("                #   5 - IMPRIMIR                  #\n");
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
	printf("\nNome do Usuario : ");
	scanf(" %80[^\n]", novo->nome);
	fflush(stdin);
	int val = validaNome(novo->nome);
	while(val == 1){
		printf("\nDigite o nome novamente: ");
		scanf(" %80[^\n]", novo->nome);
		fflush(stdin);
		val = validaNome(novo->nome);
		}
		
	printf("\nInforme o sexo (Masculino) ou (Feminino): ");
	scanf(" %9[^\n]", novo->sexo);
	fflush(stdin);
	int val2 = validaSexo(novo->sexo);
	while(val2 == 1){
		printf("\nInforme novamente o sexo (Masculino) ou (Feminino): ");
		scanf(" %9[^\n]", novo->sexo);
		fflush(stdin);
		val2 = validaSexo(novo->sexo);
		}
	
	printf("\nInforme seu CPF: ");
	scanf("%d",&novo->cpf);
	fflush(stdin);
	
	printf("\nInforme a idade: ");
	scanf(" %4[^\n]", novo->idade);
	fflush(stdin);
	int val3 = validaIdade(novo->idade);
	while(val3 == 1){
		printf("\nInforme a idade novamente: ");
		scanf(" %4[^\n]", novo->idade);
		fflush(stdin);
		val3 = validaIdade(novo->idade);
		}

	printf("\nInforme o celular : ");
	scanf(" %11[^\n]", novo->telefone);
	fflush(stdin);
	int val4 = validaTelefone(novo->telefone);
	while(val4 == 1){
		printf("\nInforme o celular novamente: ");
		scanf(" %11[^\n]", novo->telefone);
		fflush(stdin);
		val4 = validaTelefone(novo->telefone);
	}
	
	printf("\nInforme a cidade: ");
	scanf(" %50[^\n]", novo->cidade);
	fflush(stdin);
	int val5 = validaCidade(novo->cidade);
	while(val5 == 1){
		printf("\nInforme a cidade novamente: ");
		scanf(" %50[^\n]", novo->cidade);
		fflush(stdin);
		val5 = validaCidade(novo->cidade);
		}
	
	printf("\nInforme o E-MAIL: ");								//CONSERTAR EMAIL
	scanf(" %30[^\n]", novo->email);
	fflush(stdin);
	int val6 = validaEmail(novo->email);
	while(val6 == 1){
		printf("\nInforme o E-MAIL: ");
		scanf(" %30[^\n]", novo->email);
		fflush(stdin);
		val6 = validaEmail(novo->email);
		}
	
	printf("\nInforme a data de nascimento - DD/MM/AAAA: ");
	scanf(" %11[^\n]", novo->nasc);
	fflush(stdin);
	int val7 = validaNasc(novo->nasc);
	while(val7 == 1){
		printf("\nInforme a data de nascimento - FORMA: 01/01/2000: ");
		scanf(" %11[^\n]", novo->nasc);
		fflush(stdin);
		val7 = validaNasc(novo->nasc);
		}
	
	printf("\n\nCADASTRO CONCLUIDO !! \n\n");
	Aluno = inserir_dados(novo, novo->nome, novo->sexo, novo->cpf, novo->idade, novo->telefone, novo->cidade, novo->email, novo->nasc);
	
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
			
			printf("Informe o Peso do Aluno : ");
			scanf(" %4[^\n]", p->medidas.kg);
			int op1 = validaPeso(p->medidas.kg);
			while(op1 == 1){
				printf("Informe o Peso do Aluno: ");
				scanf(" %4[^\n]", p->medidas.kg);
				op1 = validaPeso(p->medidas.kg);
				}
				
			printf("Informe o Biceps : ");
			scanf(" %4[^\n]", p->medidas.biceps);
			int op2 = validaBiceps(p->medidas.biceps);
			while(op2 == 1){
				printf("Informe o Biceps : ");
				scanf(" %4[^\n]", p->medidas.biceps);
				op2 = validaBiceps(p->medidas.biceps);
				}
			
			printf("Informe o Triceps : ");
			scanf(" %4[^\n]", p->medidas.triceps);
			int op3 = validaTriceps(p->medidas.triceps);
			while(op3 == 1){
				printf("Informe o Triceps : ");
				scanf(" %4[^\n]", p->medidas.triceps);
				op3 = validaTriceps(p->medidas.triceps);
				}
				
			printf("Informe o peitoral : ");
			scanf(" %4[^\n]", p->medidas.peito);
			
			printf("Informe a medida das pernas : ");
			scanf(" %4[^\n]", p->medidas.coxa);
			int op5 = validaCoxa(p->medidas.coxa);
			while(op5 == 1){
				printf("Informe a medida das pernas : ");
				scanf(" %4[^\n]", p->medidas.coxa);
				op5 = validaCoxa(p->medidas.coxa);
				}
			
			printf("\n\n MEDIDAS REGISTRADAS COM SUCESSO !!\n\n");
		}
		else
			printf("\n\nCPF NÃO ENCONTRADO\n\n");
	}
	return Aluno;
}


void Atualizar_dados(Lista* Aluno, int cpf){
	Lista* p;
	for (p=Aluno;p!=NULL;p=p->prox){
		if(p->cpf==cpf){
		printf("\n\n ~~ATUALIZAR CADASTRO~~\n\n");
		printf("Nome do Usuario : ");
		scanf(" %80[^\n]",p->nome);
		fflush(stdin);
		int val = validaNome(p->nome);
		while(val == 1){
			printf("\nDigite o nome novamente: ");
			scanf(" %80[^\n]", p->nome);
			fflush(stdin);
			val = validaNome(p->nome);
		}
		
		printf("\nInforme o sexo (M) ou (F): \n");
		scanf(" %9[^\n]", p->sexo);
		fflush(stdin);
		int val2 = validaSexo(p->sexo);
		while(val2 == 1){
			printf("\nInforme novamente o sexo (Masculino) ou (Feminino): ");
			scanf(" %9[^\n]", p->sexo);
			fflush(stdin);
			val2 = validaSexo(p->sexo);
		}
		
		printf("\nInforme seu CPF: ");
		scanf("%d",&p->cpf);
		fflush(stdin);
		
		printf("\nInforme a idade: ");
		scanf(" %3[\n]", p->idade);
		fflush(stdin);
		int val3 = validaIdade(p->idade);
		while(val3 == 1){
			printf("\nInforme a idade novamente: ");
			scanf(" %4[^\n]", p->idade);
			fflush(stdin);
			val3 = validaIdade(p->idade);
		}
		
		printf("\ninforme o celular: ");
		scanf(" %11[^\n]", p->telefone);
		fflush(stdin);
		int val4 = validaTelefone(p->telefone);
		while(val4 == 1){
			printf("\nInforme o celular novamente: ");
			scanf(" %11[^\n]", p->telefone);
			fflush(stdin);
			val4 = validaTelefone(p->telefone);
		}
		
		printf("\nInforme a cidade: ");
		scanf(" %50[^\n]", p->cidade);
		fflush(stdin);
		int val5 = validaCidade(p->cidade);
		while(val5 == 1){
			printf("\nInforme a cidade novamente: ");
			scanf(" %50[^\n]", p->cidade);
			fflush(stdin);
			val5 = validaCidade(p->cidade);
		}
		
		printf("\nInforme o E-MAIL : "); 				//CONSERTAR EMAIL
		scanf(" %30[^\n]", p->email);
		fflush(stdin);
		int val6 = validaEmail(p->email);
		while(val6 == 1){
			printf("\nInforme o E-MAIL: ");
			scanf(" %30[^\n]", p->email);
			fflush(stdin);
			val6 = validaEmail(p->email);
		}
		
		printf("\nInforme a data de Nascimento : ");
		scanf(" %10[^\n]", p->nasc);
		fflush(stdin);
		int val7 = validaNasc(p->nasc);
		while(val7 == 1){
			printf("\nInforme a data de nascimento - FORMA: 01/01/2000: ");
			scanf(" %11[^\n]", p->nasc);
			fflush(stdin);
			val7 = validaNasc(p->nasc);
		}
		
		}
	}
}


void imprimir_dados(Lista* Aluno){
	Lista* p;
	for (p=Aluno;p!=NULL;p=p->prox){
		printf("\n Nome do Usuario: %s\n",p->nome);
		printf("\n Sexo: %s",p->sexo);
		printf("\nCPF: %d",p->cpf);
		printf("\nIdade: %s",p->idade);
		printf("\nCelular: %s",p->telefone);
		printf("\nCidade: %s",p->cidade);
		printf("\nE-MAIL: %s",p->email);
		printf("\nData de Nascimento: %s",p->nasc);
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
	printf("                #   3 - ALUNOS ATIVOS             #\n");
	printf("                #   4 - RELATORIOS                #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opção: ");
	scanf("%d", &escolha);
    }while(escolha > 4);
    return escolha;
}

Lista* criarLista(){
	return NULL;
}

Lista* inserir_dados(Lista *aluno,char *nome,char *sexo,int cpf,char *idade,char *telefone,char *cidade,char *email,char *nasc){
	Lista* p=aluno;
	// RECEBE A LISTA ALUNO
	Lista* ant=NULL;
	// GUARDA A POSIÇÃO ANTERIOR
	Lista* novo=(Lista*)malloc(sizeof(Lista));
	// adiciona nome
	strcpy(novo->nome, nome);
	strcpy(novo->sexo, sexo);
	novo->cpf=cpf;
	strcpy(novo->idade, idade);
	strcpy(novo->telefone, telefone);
	strcpy(novo->cidade, cidade);
	strcpy(novo->email,email);
	strcpy(novo->nasc,nasc);
	novo->prox=NULL;
	// Lista vazia ?
	if (p==NULL){
			// guarda o novo
		return novo;
	}

	while((p!=NULL)&& strcmp(novo->nome,p->nome)>0) {
		// guarda as posições anteriores
		ant=p;
		// ir para o proximo
		p=p->prox;
	}
	// nao entendi
	 if (ant==NULL){
		novo->prox=p;
		return novo;
	 }
	 // novo prox aponta para ant que aponta para o proximo
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
		fprintf(s, "%s\n", salva->idade);
		fprintf(s, "%s\n", salva->cidade);
		fprintf(s, "%s\n", salva->telefone);
		fprintf(s, "%s\n", salva->nasc);
		fprintf(s, "%s\n", salva->sexo);
		fprintf(s, "%s\n", salva->medidas.biceps);
        fprintf(s, "%s\n", salva->medidas.coxa);
		fprintf(s, "%s\n", salva->medidas.kg);
		fprintf(s, "%s\n", salva->medidas.peito);
		fprintf(s, "%s\n", salva->medidas.triceps);
		fprintf(s, "%s\n", salva->email);
		}
	}
}

int validaNome(char nome[81]){
	int a;
		for(a = 0; nome[a] != '\0'; a++){
			if(nome[a] >= 48 && nome[a] <= 57)
				return 1;
			else 
				return 0;
			}
	return 0;
	}
	
int validaSexo(char sexo[9]){
	int a; 
	for(a = 0; sexo[a] != '\0'; a++){
		if((sexo[a] >= 48 && sexo[a] <= 57))
			return 1;
		else
			return 0;
		}
	return 0;
	}

int validaIdade(char idade[5]){
	int a; 
	for(a = 0; idade[a] != '\0'; a++){ 
		if(idade[a] >= 48 && idade[a] <= 57)
			return 0;
		else 
			return 1;
		}
	return 0;
	}

int validaCidade(char cidade[51]){
	int a;
	for(a = 0; cidade[a] != '\0'; a++){
		if((cidade[a] >= 'a' && cidade[a] <= 'z' ) || (cidade[a] >= 'A' && cidade[a] <= 'Z' ))
			return 0;
		else 
			return 1;
		}
	return 0;
	}
	
int validaTelefone(char telefone[12]){
	int a;
	int j = strlen(telefone);
	for(a = 0; telefone[a] != '\0'; a++){
		if((telefone[a] >= 65 && telefone[a] <= 90) || (telefone[a] >=97 && telefone[a] <= 122) || (j < 8))
			return 1;
		else
			return 0;
		}
	return 0;
	}

int validaEmail(char email[31]){
	int a; 
	for(a = 0; email[a] != '\0'; a++){
		if(email[a] != '@' && email[a] != '.')
			return 1;
		}
	return 0;
	}
	
int validaNasc(char nasc[11]){
		if(nasc[2] == 47 && nasc[5] == 47)
			return 0;
		else
			return 1;
	return 0;
	}

int validaPeso(char peso[5]){
	int a;
	for(a = 0; peso[a] != '\0'; a++){
		if(peso[a] >= 48 && peso[a] <= 57)
			return 0;
		else
			return 1;
		}
		
	return 0;
	}
	
int validaBiceps(char biceps[5]){
	int a;
	for(a = 0; biceps[a] != '\0'; a++){
		if(biceps[a] >= 48 && biceps[a] <= 57)
			return 0;
		else
			return 1;
		}
		
	return 0;
	}
	
int validaTriceps(char triceps[5]){
	int a;
	for(a = 0; triceps[a] != '\0'; a++){
		if(triceps[a] >= 48 && triceps[a] <= 57)
			return 0;
		else
			return 1;
		}
		
	return 0;
	}

int validaCoxa(char coxa[5]){
	int a;
	for(a = 0; coxa[a] != '\0'; a++){
		if(coxa[a] >= 48 && coxa[a] <= 57)
			return 0;
		else
			return 1;
		}
		
	return 0;
	}

int validaPeitoral(char peitoral[5]){
	int a;
	for(a = 0; peitoral[a] != '\0'; a++){
		if(peitoral[a] >= 48 && peitoral[a] <= 57)
			return 0;
		else
			return 1;
		}
		
	return 0;
	}
