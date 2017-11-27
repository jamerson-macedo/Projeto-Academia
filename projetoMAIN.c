#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
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
	char alt[5];
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

// ASSINATURAS DAS FUN«’ES

int menuPrincipal(void);
Lista* Dadospessoais(Lista* Aluno);
void cadastroSerie(void);
int financeiro(void);
int menuAluno(void);
Lista* criarLista();
Lista* inserir_dados(Lista *aluno,char *nome,char *sexo,char *cpf,char *idade,char *celular,char *cidade,char *email,char *data);
Lista* remover_cpf(Lista* Aluno, char* cpf);
void Atualizar_dados(Lista* Aluno, char *cpf);
void imprimir_dados(Lista *Aluno);
Lista* inserir_Medidas(Lista* Aluno);
void Saude_Aluno(Lista* Aluno);
void salvar(Lista* Aluno);
int validaTelefone(char *telefone);
int validaNome(char *cidade);
int validaSexo(char *sexo);
int validaIdade(char *idade);
int validaData(char *nasc);
int validaMedidas(char *medida);
int validaCPF(char *cpf);
int meses(void);
void pagar(Lista* Aluno);
void desenvolvimentoAluno(Lista* Aluno);
// ESSA FUN«√O IR¡ CHAMAR A OUTRAS FUN«’ES APENAS

int main(void){
	setlocale(LC_ALL, "portuguese");

    Lista* Aluno=criarLista();

    int opc;
    int opc2;
    char cpf[12];
    int acesso;
    inicio:
    opc=menuPrincipal();

    switch (opc){
    case 1:
        system("cls");
        acesso=menuAluno();

        switch (acesso){
        case 1:
            system("cls");
            Aluno=Dadospessoais(Aluno);
            break;
        case 2:
            system("cls");
            Aluno=inserir_Medidas(Aluno);
            break;
        case 3:
            system("cls");
            printf("Informe o CPF para Pesquisar: ");
            scanf(" %11[^\n]", cpf);
			int a = validaCPF(cpf);
			while(a == 1){
				printf("\n CPF INVALIDO ! \n");
				printf("Digite novamente : ");
				scanf(" %11[^\n]", cpf);
				a = validaCPF(cpf);
				}
			Atualizar_dados(Aluno,cpf);
            break;
        case 4:
            system("cls");
            printf("Informe o CPF do aluno para excluir cadastro: ");
			scanf(" %11[^\n]", cpf);
			int b = validaCPF(cpf);
			while(b == 1){
				printf("\n CPF INVALIDO ! \n");
				printf("Digite novamente : ");
				scanf(" %11[^\n]", cpf);
				b = validaCPF(cpf);
				}
            Aluno=remover_cpf(Aluno,cpf);
        }

        break;
    case 2:
        Saude_Aluno(Aluno);
        break;
    case 3:
        desenvolvimentoAluno(Aluno);
        break;
    case 4:
        system("cls");
        opc2=financeiro();
        printf("%d",opc2);

        if (opc2==1){
            pagar(Aluno);
            break;
        }
    case 5:
        system("cls");
        imprimir_dados(Aluno);
    case 0:
        exit(0);
    default:
        printf("\nValor inv·lido.");
        break;
    }


goto inicio;
	return 0;
}

// FUN«’ES

int menuPrincipal(void){
	int escolha;

	{
	printf("                -----------------------------------\n");
	printf("                #   1 - CADASTRO DE ALUNO         #\n");
	printf("                #   2 - BUSCAR SA⁄DE DO ALUNO     #\n");
	printf("                #   3 - DESENVOLVIMENTO DE ALUNO  #\n");
	printf("                #   4 - FINANCEIRO                #\n");
	printf("                #   5 - IMPRIMIR                  #\n");
	printf("                #                                 #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opÁ„o: ");
	scanf("%d", &escolha);

	return escolha;
	}
}
int menuAluno(void){
	int escolha;{
	printf("               -----------------------------------\n");
	printf("               #   1 - CADASTRAR DADOS PESSOAIS  #\n");
	printf("               #   2 - CADASTRAR MEDI«√O         #\n");
	printf("               #   3 - ATUALIZAR DADOS           #\n");
	printf("               #   4 - EXCLUIR CADASTRO          #\n");
	printf("               #                                 #\n");
	printf("               #   0 - SAIR                      #\n");
	printf("               -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opÁ„o: ");
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
		printf("\n CPF INVALIDO ! \n");
        printf("Digite novamente : ");
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



	printf("\n\nCADASTRO CONCLUÕDO! \n\n");
	Aluno=inserir_dados(Aluno,novo->nome,novo->sexo,novo->cpf,novo->idade,novo->celular,novo->cidade,novo->email,novo->data);
	return Aluno;
	}

Lista* inserir_Medidas(Lista* Aluno){
    char cpf1[12];
    if(Aluno==NULL){
            printf("\nN√O EXISTE ALUNO CADASTRADO. ");
            exit(1);
    }
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
        printf("\n Informe a altura : ");
        scanf(" %4[^\n]", p->medidas.alt);
        int val6 = validaMedidas(p->medidas.alt);
        while (val6==1){
            printf("\n Informe novamente a altura : ");
            scanf(" %4[^\n]", p->medidas.alt);
            fflush(stdin);
            val6=validaMedidas(p->medidas.alt);
        }

		printf("\n\n MEDIDAS REGISTRADAS COM SUCESSO !!\n\n");
		}
		else
			printf("\n\nCPF N√O ENCONTRADO\n\n");
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


			printf("\nInforme o celular [sem pontos e traÁos]: ");
			scanf(" %11[^\n]",p->celular);
			fflush(stdin);
			int val5 = validaTelefone(p->celular);
			while(val5 == 1){
				printf("\nInforme o celular [sem pontos e traÁos] novamente: ");
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
				printf("\n\n ATUALIZADO COM SUCESSO\n\n");

            }
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

void Saude_Aluno(Lista* Aluno){
    char cpf2[12];
    if(Aluno==NULL){
        printf("\nN√O EXISTE ALUNO CADASTRADO\n");
        exit(0);
    }
    float imc=0;
	printf("\n\nSAU⁄DE DO ALUNO\n\n");
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
		if(strcmp(p->cpf, cpf2)==0){
        printf("aluno encontrado !");
        float altura=atof(p->medidas.alt);
        float pesoc=atof(p->medidas.kg);
        imc=pesoc/(altura*altura);
        printf("\n%f\n",imc);
        if (imc<=16.9){
            printf("%s, VocÍ esta abaixo do peso ideal, com um IMC de %f.\n, Muito abaixo do peso,\n Recomenda-se que vocÍ procure se alimentar mais frequentemente\n",p->nome,imc);

        }
        else if (imc>17.0&&imc<18.4){
            printf("%s, voce esta abaixo do peso ideal, com um IMC de %f.\n Abaixo do peso,\n ",p->nome,imc);
        }
        else if (imc>=18.5 && imc <=24.9){
            printf("peso normal");
        }
    }
    else
        printf("CPF N√O ENCONTRADO");
}
}

void desenvolvimentoAluno(Lista* Aluno){
	printf("DESENVOLVIMENTO DE ALUNO!\n");
	Lista* p=Aluno;
    if (p==NULL){
        printf("n„o existe aluno cadastrado !!");
        exit(1);
    }
    char cpf3[12];
    printf("DIGITE O CPF DO ALUNO : ");
    scanf(" %11[^\n]", cpf3);
	for (p;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf3) == 0){



        }
    }
}

int financeiro(void){
    int escolha;
    do{
	printf("FINANCEIRO!\n");
	printf("                -----------------------------------\n");
	printf("                #   1 - PAGAR MÍS                 #\n");
	printf("                #   2 - DESPESAS DA ACADEMIA      #\n");
	printf("                #   3 - ALUNOS ATIVOS             #\n");
	printf("                #   4 - RELATORIOS                #\n");
	printf("                #   5 - ALUNOS EM ATRASO          #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opÁ„o: ");
	scanf("%d", &escolha);
    }while(escolha>5);
    return escolha;
}

Lista* criarLista(){
	return NULL;
	}

Lista* inserir_dados(Lista *aluno,char *nome,char *sexo,char *cpf,char *idade,char *celular,char *cidade,char *email, char *data){
	Lista* p=aluno;  // RECEBE A LISTA ALUNO
	Lista* ant=NULL; // GUARDA A POSI«√O ANTERIOR
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
		// guarda as posiÁıes anteriores
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

Lista* remover_cpf(Lista* Aluno, char* cpf){
	Lista* ant=NULL;
	Lista* p=Aluno;                  // p È aux pra percorrer
	while((p != NULL) && strcmp(p->cpf,cpf) != 0){
		ant=p;
		p=p->prox;
		printf("\n\nentrou no while\n\n");
		}
		// caso ELE NAO ACHAR----
		if (p==NULL){
			printf("ALUNO N√O ENCONTRADO\n");
			return Aluno;
		}
		// ant È null so se for o primeiro elemento
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
	int digito10, digito11, tam;
	soma = 0;
	tam = strlen(cpf);
	if(tam < 11){
		printf("\nDigite o CPF com 11 campos.\n");
		return 1;
		}
	else{
	for(contador = 0; contador < 11; contador++){
		cpf[contador] -= 48;
	}

	for(contador = 0; contador < 9; contador++){ //VerificaÁ„o para primeiro digito
		soma += cpf[contador] * (10 - contador);
		}

	resultado = soma % 11;

	if(resultado == 0 || resultado == 1)
		digito10 = 0;
	else
		digito10 = 11 - resultado;

	soma = 0;

	for(contador = 0; contador < 10; contador++){ //VerificaÁ„o para segundo digito
		soma += cpf[contador] * (11 - contador);
		}
	valor = (soma / 11) * 11;
	resultado2 = soma - valor;
	if(resultado2 == 0 || resultado2 == 1)
		digito11 = 0;
	else
		digito11 = 11 - resultado2;

	for(contador = 0; contador < 11; contador++){
		cpf[contador] += 48;
	}
	if((digito10 == cpf[9]) && (digito11 == cpf[10]))
		return 1;
	else
		return 0;
	return 0;
	}
}

int meses(void){
    int escolha;
    do{
printf("\nInforme o mÍs referente ao pagamento !!\n");
printf("| 1 - JANEIRO       |\n");
printf("| 2 - FEVEREIRO     |\n");
printf("| 3 - MAR«O         |\n");
printf("| 4 - ABRIL         |\n");
printf("| 5 - MAIO          |\n");
printf("| 6 - JUNHO         |\n");
printf("| 7 - JULHO         |\n");
printf("| 8 - AGOSTO        |\n");
printf("| 9 - SETEMBRO      |\n");
printf("| 10 - OUTUBRO      |\n");
printf("| 11 - NOVEMBRO     |\n");
printf("| 12 - DEZEMBRO     |\n");
scanf("%d",&escolha);
}while(escolha>12&&escolha<1);





}

void pagar(Lista* Aluno){
    Lista* p=Aluno;
    if (p==NULL){
        printf("n„o existe aluno cadastrado !!");
        exit(1);
    }
    char cpf3[12];
    printf("DIGITE O CPF DO ALUNO : ");
    scanf(" %11[^\n]", cpf3);
	for (p;p!=NULL;p=p->prox){
	    printf("entrou no for");
	    printf("p = %s",p->cpf);
		if(strcmp(p->cpf, cpf3) == 0){
			int mes_pag=meses();
			if(mes_pag==1){
                p->pago.janeiro=35.00;
                printf(" MÍS DE JANEIRO PAGO !! \n");
			}
			else if (mes_pag==2){
                p->pago.fevereiro=35.00;
                printf(" MÍS DE FEVEREIRO PAGO !! \n");
			}
			else if (mes_pag==3){
                p->pago.marco=35.00;
                printf(" MÍS DE MAR«O PAGO !! \n");
			}
			else if (mes_pag==4){
                p->pago.abri=35.00;
                printf(" MÍS DE ABRIL PAGO !! \n");
            }
            else if (mes_pag==5){
                p->pago.maio=35.00;
                printf(" MÍS DE MAIO PAGO !! \n");
            }
            else if (mes_pag==6){
                p->pago.jun=35.00;
                printf(" MÍS DE JUNHO PAGO !! \n");
            }
            else if (mes_pag==7){
                p->pago.jul=35.00;
                printf(" MÍS DE JULHO PAGO !! \n");
            }
            else if (mes_pag==8){
                p->pago.ago=35.00;
                printf(" MÍS DE AGOSTO PAGO !! \n");
            }
            else if (mes_pag==9){
                p->pago.set=35.00;
                printf(" MÍS DE SETEMBRO PAGO !! \n");
            }
            else if (mes_pag==10){
                p->pago.out=35.00;
                printf(" MÍS DE OUTUBRO PAGO !! \n");
            }
            else if (mes_pag==11){
                p->pago.nov=35.00;
                printf(" MÍS DE NOVEMBRO PAGO !! \n");
            }
            else if (mes_pag==2){
                p->pago.dez=35.00;
                printf(" MÍS DE DEZEMBRO PAGO !! \n");
            }
		}
		else
            printf("CPF N√O ENCONTRADO");
	}
}
