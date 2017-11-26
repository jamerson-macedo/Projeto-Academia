#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
// STRUCT
typedef struct pagamentos{
	float janeiro;
	float fevereiro;
	float marco;
	float abri;
	float maio;
	float jun;
	float jul;
	float ago;
	float set;
	float out;
	float nov;
	float dez;
}Pagamentos;

typedef struct medidas{
	char biceps[5];
	char triceps[5];
	char peito[5];
	char coxa[5];
	char kg[5];
}Medidas;

typedef struct lista{
	char nome[80];
	char sexo[2];
	char cpf[12];
	char idade[3];
	char celular[20];
	char cidade [80];
	char email[30];
	char data[11];
Medidas medidas;
Pagamentos pago;
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
Lista* inserir_dados(Lista *aluno,char *nome,char *sexo,char *cpf,char *idade,char *celular,char *cidade,char *email,char *data);
Lista* remover_cpf(Lista* Aluno,int valor);
void Atualizar_dados(Lista* Aluno, char *cpf);
void imprimir_dados(Lista *Aluno);
Lista* inserir_Medidas(Lista* Aluno);
void Saude_Aluno(Lista* Aluno,char *cpf);
void salvar(Lista* Aluno);
int validaTelefone(char *telefone);
int validaNome(char *cidade);
int validaSexo(char *sexo);
int validaIdade(char *idade);
int validaData(char *nasc);
int validaMedidas(char *medida);
int validaCPF(char *cpf);

// ESSA FUNÇÃO IRÁ CHAMAR A OUTRAS FUNÇÕES APENAS

int main(void){
	setlocale(LC_ALL, "portuguese");

    Lista* Aluno=criarLista();

    int opc;
    char cpf[12];
    int acesso;
    inicio:
    opc=menuPrincipal();

    switch (opc){
    case 1:

        acesso=menuAluno();

        switch (acesso){
        case 1:
            Aluno=Dadospessoais(Aluno);
            break;
        case 2:
            Aluno=inserir_Medidas(Aluno);
            break;
        case 3:
            printf("Informe o CPF para pesquisar: ");
            scanf(" %11[^\n]", cpf);
			int a = validaCPF(cpf);
			while(a == 1){
				printf("\nDigite o CPF sem pontos e tracos: ");
				scanf(" %11[^\n]", cpf);
				a = validaCPF(cpf);
				}
			Atualizar_dados(Aluno,cpf);
            break;
        case 4:
            printf("Informe o CPF do aluno para excluir cadastro: ");
			scanf(" %11[^\n]", cpf);
			int b = validaCPF(cpf);
			while(b == 1){
				printf("\nDigite o CPF sem pontos e tracos: ");
				scanf(" %11[^\n]", cpf);
				b = validaCPF(cpf);
				}
            Aluno=remover_cpf(Aluno,*cpf);
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
        printf("\nValor inválido.");
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
	printf("                #                                 #\n");
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
	printf("\n");
	
	return escolha;
	}
}

Lista* Dadospessoais(Lista* Aluno){
	printf("CADASTRO DE ALUNO!\n");

	Lista *novo=malloc(sizeof(Lista));
	printf("\nNome do Usuario: ");
	scanf(" %80[^\n]",novo->nome);
	fflush(stdin);
	int val = validaNome(novo->nome);
	while(val == 1){
		printf("\nDigite o nome novamente: ");
		scanf(" %80[^\n]", novo->nome);
		fflush(stdin);
		val = validaNome(novo->nome);
		}
	
	printf("\nInforme o sexo (M) ou (F): ");
	scanf(" %1[^\n]", novo->sexo);
	fflush(stdin);
	int val2 = validaSexo(novo->sexo);
	while(val2 == 1){
		printf("\nInforme o sexo (M) ou (F): ");
		scanf(" %1[^\n]", novo->sexo);
		fflush(stdin);
		val2 = validaSexo(novo->sexo);
		}
		
	printf("\nInforme seu CPF: ");
	scanf(" %11[^\n]", novo->cpf);
	fflush(stdin);
	int val3 = validaCPF(novo->cpf);
	while(val3 == 1){
		printf("\nDigite o CPF sem pontos e tracos: ");
		scanf(" %11[^\n]", novo->cpf);
		val3 = validaCPF(novo->cpf);
		}
	
	printf("\nInforme a idade: ");
	scanf(" %2[^\n]",novo->idade);
	fflush(stdin);
	int val4 = validaIdade(novo->idade);
	while(val4 == 1){
		printf("\nInforme a idade novamente: ");
		scanf(" %2[^\n]", novo->idade);
		fflush(stdin);
		val4 = validaIdade(novo->idade);
		}
		
	printf("\nInforme o celular: ");
	scanf(" %11[^\n]", novo->celular);
	fflush(stdin);
	int val5 = validaTelefone(novo->celular);
	while(val5 == 1){
		printf("\nInforme o celular novamente: ");
		scanf(" %11[^\n]", novo->celular);
		fflush(stdin);
		val5 = validaTelefone(novo->celular);
		}
		
	printf("\nInforme a cidade: ");
	scanf(" %80[^\n]",novo->cidade);
	fflush(stdin);
	int val6 = validaNome(novo->cidade);
	while(val6 == 1){
		printf("\nInforme a cidade novamente: ");
		scanf(" %80[^\n]", novo->cidade);
		fflush(stdin);
		val6 = validaNome(novo->cidade);
		}
	
	printf("\nInforme o E-MAIL : ");
	scanf(" %80[^\n]",novo->email);
	fflush(stdin);
	
	printf("\nInforme a data de Nascimento Ex: 01/01/2001: ");
	scanf(" %10[^\n]", novo->data);
	fflush(stdin);
	int val8 = validaData(novo->data);
	while(val8 == 1){
		printf("\nInforme a data novamente: ");
		scanf(" %10[^\n]", novo->data);
		fflush(stdin);
		val8 = validaData(novo->data);
		}
		
	
	
	printf("\n\nCADASTRO CONCLUÍDO! \n\n");
	Aluno=inserir_dados(Aluno,novo->nome,novo->sexo,novo->cpf,novo->idade,novo->celular,novo->cidade,novo->email,novo->data);
	return Aluno;
	}

Lista* inserir_Medidas(Lista* Aluno){
    char cpf1[12];
    printf("\n\n~~ MEDIDAS~~\n\n");
    printf("DIGITE O CPF PARA INSERIR AS MEDIDAS: ");
    scanf(" %11[^\n]", cpf1);
    int val0 = validaCPF(cpf1);
	while(val0 == 1){
		printf("\nDigite o CPF sem pontos e tracos: ");
		scanf(" %11[^\n]", cpf1);
		val0 = validaCPF(cpf1);
		}
    Lista* p;
    if(Aluno==NULL){
            printf("\nNÃO EXISTE ALUNO CADASTRADO. ");
    }

	for (p=Aluno;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf1) == 0){
		printf("\nInforme o Peso do Aluno: ");
		scanf(" %4[^\n]", p->medidas.kg);
		int val1 = validaMedidas(p->medidas.kg);
		while(val1 == 1){
			printf("\nInforme o Peso do Aluno: ");
			scanf(" %4[^\n]", p->medidas.kg);
			fflush(stdin);
			val1 = validaMedidas(p->medidas.kg);
			}
		
		printf("\nInforme o Biceps: ");
		scanf(" %4[^\n]", p->medidas.biceps);
		int val2 = validaMedidas(p->medidas.biceps);
		while(val2 == 1){
			printf("\nInforme o Biceps: ");
			scanf(" %4[^\n]", p->medidas.biceps);
			fflush(stdin);
			val2 = validaMedidas(p->medidas.biceps);
			}
		
		printf("\nInforme o triceps: ");
		scanf(" %4[^\n]", p->medidas.triceps);
		int val3 = validaMedidas(p->medidas.triceps);
		while(val3 == 1){
			printf("\nInforme o triceps: ");
			scanf(" %4[^\n]", p->medidas.triceps);
			fflush(stdin);
			val3 = validaMedidas(p->medidas.triceps);
			}
		
		printf("\nInforme o peitoral: ");
		scanf(" %4[^\n]", p->medidas.peito);
		int val4 = validaMedidas(p->medidas.peito);
		while(val4 == 1){
			printf("\nInforme o peitoral: ");
			scanf(" %4[^\n]", p->medidas.peito);
			fflush(stdin);
			val4 = validaMedidas(p->medidas.peito);
			}
		
		printf("\nInforme a medida das pernas: ");
		scanf(" %4[^\n]", p->medidas.coxa);
		int val5 = validaMedidas(p->medidas.coxa);
		while(val5 == 1){
			printf("\nInforme a medida das pernas: ");
			scanf(" %4[^\n]", p->medidas.coxa);
			fflush(stdin);
			val5 = validaMedidas(p->medidas.coxa);
			}
		
		printf("\n\n MEDIDAS REGISTRADAS COM SUCESSO !!\n\n");
		}
		else
			printf("\n\nCPF NÃO ENCONTRADO\n\n");
		}
	return Aluno;
}

void Atualizar_dados(Lista* Aluno, char *cpf){
	Lista* p;
	for (p=Aluno;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf) == 0){
			printf("\n\n ~~ATUALIZAR CADASTRO~~\n\n");
			printf("\nNome do Usuario: ");
			scanf(" %80[^\n]",p->nome);
			fflush(stdin);
			int val = validaNome(p->nome);
			while(val == 1){
				printf("\nDigite o nome novamente: ");
				scanf(" %80[^\n]", p->nome);
				fflush(stdin);
				val = validaNome(p->nome);
				}
			
			printf("\nInforme o sexo (M) ou (F): ");
			scanf("%s", p->sexo);
			fflush(stdin);
			int val2 = validaSexo(p->sexo);
			while(val2 == 1){
				printf("\nInforme o sexo (M) ou (F) novamente: ");
				scanf(" %1[^\n]", p->sexo);
				fflush(stdin);
				val2 = validaSexo(p->sexo);
				}
			
			printf("\nInforme seu CPF: ");
			scanf(" %12[^\n]", p->cpf);
			fflush(stdin);
			int val3 = validaCPF(p->cpf);
			while(val3 == 1){
				printf("\nDigite o CPF sem pontos e tracos: ");
				scanf(" %12[^\n]", p->cpf);
				val3 = validaCPF(p->cpf);
				}
			
			
			printf("\nInforme a idade: ");
			scanf(" %2[^\n]",p->idade);
			fflush(stdin);
			int val4 = validaIdade(p->idade);
			while(val4 == 1){
				printf("\nInforme a idade novamente: ");
				scanf(" %2[^\n]", p->idade);
				fflush(stdin);
				val4 = validaIdade(p->idade);
				}
			
			
			printf("\nInforme o celular [sem pontos e traços]: ");
			scanf(" %11[^\n]",p->celular);
			fflush(stdin);
			int val5 = validaTelefone(p->celular);
			while(val5 == 1){
				printf("\nInforme o celular [sem pontos e traços] novamente: ");
				scanf(" %11[^\n]", p->celular);
				fflush(stdin);
				val5 = validaTelefone(p->celular);
				}

			printf("\nInforme a cidade: ");
			scanf(" %80[^\n]",p->cidade);
			fflush(stdin);
			int val6 = validaNome(p->cidade);
			while(val6 == 1){
				printf("\nInforme a cidade novamente: ");
				scanf(" %80[^\n]", p->cidade);
				fflush(stdin);
				val6 = validaNome(p->cidade);
				}	
			
			printf("\nInforme o E-MAIL: ");
			scanf(" %80[^\n]",p->email);
			fflush(stdin);
			
			
			printf("\nInforme a data de Nascimento Ex: 01/01/2001: ");
			scanf("%s",p->data);
			fflush(stdin);
			int val8 = validaData(p->data);
			while(val8 == 1){
				printf("\nInforme a data novamente: ");
				scanf(" %10[^\n]", p->data);
				fflush(stdin);
				val8 = validaData(p->data);
				}
			}
			printf("CADASTRO ATUALIZADO");
		}
}

void imprimir_dados(Lista *Aluno){
	Lista* p=Aluno;
	int cont=0;
	if (p==NULL){
			printf("vazio");
			}
	for (p=Aluno;p!=NULL;p=p->prox){
		printf("\nNome do Usuario: %s", p->nome);
		printf("\nSexo: %s", p->sexo);
		printf("\nCPF: %s", p->cpf);
		printf("\nIdade: %s", p->idade);
		printf("\nCelular: %s", p->celular);
		printf("\nCidade: %s", p->cidade);
		printf("\nE-MAIL: %s", p->email);
		printf("\nData de Nascimento: %s", p->data);
		printf("\n");
		cont++;
	}
	printf("\n%d\n",cont);
}

void Saude_Aluno(Lista* Aluno, char *cpf){
    char cpf2[12];
	printf("\n\nSAUÚDE DO ALUNO\n\n");
	printf("\nInforme o CPF do Aluno: ");
    scanf(" %11[^\n]", cpf2);
    int val01 = validaCPF(cpf2);
	while(val01 == 1){
		printf("\nDigite o CPF sem pontos e tracos: ");
		scanf(" %11[^\n]", cpf2);
		val01 = validaCPF(cpf2);
		}
    Lista* p;
	for (p=Aluno;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf2)==0);
		// aqui comparar
	}
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
    }while(escolha>4);
    return escolha;
}

Lista* criarLista(){
	return NULL;
	}

Lista* inserir_dados(Lista *aluno,char *nome,char *sexo,char *cpf,char *idade,char *celular,char *cidade,char *email, char *data){
	Lista* p=aluno;  // RECEBE A LISTA ALUNO
	Lista* ant=NULL; // GUARDA A POSIÇÃO ANTERIOR
	Lista* novo=(Lista*)malloc(sizeof(Lista)); // adiciona nome
	
	strcpy(novo->nome, nome);
	strcpy(novo->sexo, sexo);
	strcpy(novo->cpf, cpf);
	strcpy(novo->idade, idade);
	strcpy(novo->celular, celular);
	strcpy(novo->cidade, cidade);
	strcpy(novo->email,email);
	strcpy(novo->data, data);
	novo->prox=NULL;
	
	// Lista vazia ?
	
	if (p==NULL){
        printf("chegou em novo ");
        // guarda o novo
		return novo;
	}
	while ((p!=NULL) && strcmp(novo->nome,p->nome)>0) {
		// guarda as posições anteriores
		ant=p;
		// ir para o proximo
		p=p->prox;
		}
		// nao entendi
	if (ant==NULL){
	   novo->prox=p;
	   printf("chegou em novo2");
	   return novo;
		}
	// novo prox aponta para ant que aponta para o proximo
	// entao o anterior agora aponta para novo
	novo->prox=ant->prox;
	ant->prox=novo;
	printf("chegou em aluno");
	return aluno;
}

Lista* remover_cpf(Lista* Aluno, int valor){
	Lista* ant=NULL;
	Lista* p=Aluno;                  // p é aux pra percorrer
	while((p != NULL) && strcmp(p->cpf, p->cpf) != 0){
		ant=p;
		p=p->prox;
		printf("\n\nentrou no while\n\n");
		}
		// caso ELE NAO ACHAR----
		if (p==NULL){
			printf("ALUNO NÃO ENCONTRADO\n");
			return Aluno;
		}
		// ant é null so se for o primeiro elemento
		if(ant==NULL){
			Aluno=p->prox;
			printf("chegou aqui ant null");
		}
		else{
			printf("chegou no se n");
			ant->prox=p->prox;
		}
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
		fprintf(s, "%s\n", salva->cpf);
		fprintf(s, "%s\n", salva->idade);
		fprintf(s, "%s\n", salva->cidade);
		fprintf(s, "%s\n", salva->celular);
		fprintf(s, "%s\n", salva->data);
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
int validaNome(char* cidade){
	int a;
	for(a = 0; cidade[a] != '\0'; a++){
		if((cidade[a] >= 'a' && cidade[a] <= 'z' ) || (cidade[a] >= 'A' && cidade[a] <= 'Z' ))
			return 0;
		else
			return 1;
		}
	return 0;
	}

int validaTelefone(char *telefone){
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
	
int validaSexo(char *sexo){
	int a; 
	for(a = 0; sexo[a] != '\0'; a++){
		if((sexo[a] == 'M' || sexo[a] == 'm') || (sexo[a] == 'F' || sexo[a] == 'f'))
			return 0;
		else
			return 1;
		}
	return 0;
	}

int validaIdade(char *idade){
	int a; 
	for(a = 0; idade[a] != '\0'; a++){ 
		if(idade[a] >= 48 && idade[a] <= 57)
			return 0;
		else 
			return 1;
		}
	return 0;
	}
	
int validaData(char *nasc){
		if(nasc[2] == 47 && nasc[5] == 47)
			return 0;
		else
			return 1;
	return 0;
	}

int validaMedidas(char *medida){
	int a;
	for(a = 0; medida[a] != '\0'; a++){
		if(medida[a] >= 48 && medida[a] <= 57)
			return 0;
		else
			return 1;
		}
		
	return 0;
	}

int validaCPF(char *cpf){
	int contador, soma, resultado, resultado2, valor;
	int digito10, digito11; 
	soma = 0;
	
	for(contador = 0; contador < 11; contador++){
		cpf[contador] -= 48;
	}
	
	for(contador = 0; contador < 9; contador++){
		soma += cpf[contador] * (10 - contador);
		}	
		
	resultado = soma % 11;
	
	if((resultado == 0) || (resultado == 1))
		digito10 = 0;
	else 
		digito10 = 11 - resultado;
	
	soma = 0;
	
	for(contador = 0; contador < 10; contador++){
		soma += cpf[contador] * (11 - contador);
		}
	valor = (soma / 11) * 11;
	resultado2 = soma - valor;
	if((resultado2 == 0) || (resultado2 == 1))
		digito11 = 0;
	else 
		digito11 = 11 - resultado2;
	if((digito10 == cpf[9]) && (digito11 == cpf[10]))
		return 0;
	else
		return 1;
	return 0;
	}

