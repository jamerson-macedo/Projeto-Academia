#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct despesas{				//Despesas da academia
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
	struct despesas* prox;
}Despesas;

typedef struct pagamentos{						//Pagamentos dos alunos
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

typedef struct medidas{							//Medidas dos alunos
	char biceps[4];
	char peito[4];
	char coxa[4];
	char kg[4];
	char alt[4];
	struct medidas* prox;
}Medidas;

typedef struct lista{							//Dados pessoais
	char nome[80];
	char sexo[2];
	char cpf[12];
	char idade[3];
	char celular[20];
	char cidade [80];
	char email[30];
	char data[11];
	int ativo;
	Medidas medidas;
	Pagamentos pago;
	struct lista* prox;
}Lista;

// ASSINATURAS DAS FUNÇÕES

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
int validaTelefone(char *telefone);
int validaNome(char *cidade);
int validaSexo(char *sexo);
int validaIdade(char idade[3]);
int validaData(char *nasc);
int validaMedidas(char *medida);
int validaCPF(char cpf[12]);
int meses(void);
void pagar(Lista* Aluno);
void desenvolvimentoAluno(Lista* Aluno);
void desativar(Lista* aluno);
void mostrar_aluno(Lista* aluno);
void relatorios (Lista* aluno);
void alunos_atrasos(Lista* aluno);
int validaNumero(char desp[5]);
Lista* ler_arquivos(Lista* Aluno);
void salvar(Lista* l);
void total_despesas(Despesas re);
void salvartudo(Lista* Aluno);
Lista* carregar(Lista* Aluno);
int menu_at(void);
void ativar(Lista* aluno);
int alunos_desativaados(Lista* aluno);
int validaEmail(char *email);
//void salvardespesas(Despesas* d);
//Despesas* carregardespesas(Despesas* d);
Despesas despesas(Despesas me);
//void inicializa_Medidas(Lista** Aluno);

// ESSA FUNÇÃO IRÁ CHAMAR A OUTRAS FUNÇÕES APENAS

int main(void){
	setlocale(LC_ALL, "portuguese");

    Lista* Aluno=criarLista();


    Despesas DESPESAS;
	//Despesas* despesas_;
    int opc;
    int opc2;
    char cpf[12];
    int acesso;
        Aluno = carregar(Aluno);
    inicio:
    opc=menuPrincipal();


	//despesas_ = carregardespesas(despesas_);								                  //Carregar;


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
        system("cls");
        Saude_Aluno(Aluno);
        break;
    case 3:
        system("cls");
        desenvolvimentoAluno(Aluno);
        break;
    case 4:
        system("cls");
        opc2=financeiro();

        if (opc2==1){
            system("cls");
            pagar(Aluno);
            break;
        }
        else if (opc2==2){
            system("cls");
            DESPESAS=despesas(DESPESAS);
            break;
        }
        else if (opc2==3){
            system("cls");
            relatorios(Aluno);
            break;
        }
        else if (opc2==4){
            system("cls");
            alunos_atrasos(Aluno);
            break;
        }
        else if (opc2==5){
            system("cls");
            desativar(Aluno);
            break;
            }
        else if (opc2==6){
            system("cls");
            ativar(Aluno);
            break;
        }
        else if (opc2==7){
            system("cls");
            total_despesas(DESPESAS);
            break;
        }


    case 5:
        imprimir_dados(Aluno);
        break;

    case 0:
        salvartudo(Aluno);
        //salvardespesas(despesas_);
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
	printf("                #   0 - SAIR E SALVAR             #\n");
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
	scanf(" %29[^\n]",novo->email);
	fflush(stdin);
	int val7 = validaEmail(novo->email);
	while(val7 == 1){
		printf("\nInforme o E-MAIL : ");
		scanf(" %29[^\n]",novo->email);
		val7 = validaEmail(novo->email);
		}

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
	
	strcpy(novo->medidas.biceps, "0");
	strcpy(novo->medidas.peito, "0");
    strcpy(novo->medidas.coxa, "0");
    strcpy(novo->medidas.kg, "0");
    strcpy(novo->medidas.alt, "0");
    
	Aluno=inserir_dados(Aluno,novo->nome,novo->sexo,novo->cpf,novo->idade,novo->celular,novo->cidade,novo->email,novo->data);
  
	return Aluno;

	}

Lista* inserir_Medidas(Lista* Aluno){

	Lista* x=Aluno;
	//inicializa_Medidas(Aluno);
    char cpf1[12];
    if(Aluno==NULL){
            printf("\n\nNÃO EXISTE ALUNO CADASTRADO. \n\n");
            system("pause");
    }
    else{
    printf("\n\n~~ MEDIDAS~~\n\n");
    printf("DIGITE O CPF PARA INSERIR AS MEDIDAS: ");
    scanf(" %11[^\n]", cpf1);
    int val0 = validaCPF(cpf1);
	while(val0 == 1){
		printf("\nDigite o CPF sem pontos e tracos: ");
		scanf(" %11[^\n]", cpf1);
		val0 = validaCPF(cpf1);
		}



		for (x=Aluno;x!=NULL;x=x->prox){
			if(strcmp(x->cpf, cpf1) == 0){
				printf("\nInforme o Peso do Aluno: ");
				scanf(" %3[^\n]", x->medidas.kg);
				int val1 = validaMedidas(x->medidas.kg);
				while(val1 == 1){
					printf("\nInforme o Peso do Aluno: ");
					scanf(" %3[^\n]", x->medidas.kg);
					fflush(stdin);
					val1 = validaMedidas(x->medidas.kg);
					}

				printf("\nInforme o Biceps: ");
				scanf(" %3[^\n]", x->medidas.biceps);
				int val2 = validaMedidas(x->medidas.biceps);
				while(val2 == 1){
					printf("\nInforme o Biceps: ");
					scanf(" %3[^\n]", x->medidas.biceps);
					fflush(stdin);
					val2 = validaMedidas(x->medidas.biceps);
					}

				printf("\nInforme o peitoral: ");
				scanf(" %3[^\n]", x->medidas.peito);
				int val4 = validaMedidas(x->medidas.peito);
				while(val4 == 1){
					printf("\nInforme o peitoral: ");
					scanf(" %3[^\n]", x->medidas.peito);
					fflush(stdin);
					val4 = validaMedidas(x->medidas.peito);
					}

				printf("\nInforme a medida das pernas: ");
				scanf(" %3[^\n]", x->medidas.coxa);
				int val5 = validaMedidas(x->medidas.coxa);
				while(val5 == 1){
					printf("\nInforme a medida das pernas: ");
					scanf(" %3[^\n]", x->medidas.coxa);
					fflush(stdin);
					val5 = validaMedidas(x->medidas.coxa);
					}
				printf("\n Informe a altura : ");
				scanf(" %3[^\n]", x->medidas.alt);
				int val6 = validaMedidas(x->medidas.alt);
				while (val6==1){
					printf("\n Informe novamente a altura : ");
					scanf(" %3[^\n]", x->medidas.alt);
					fflush(stdin);
					val6=validaMedidas(x->medidas.alt);
				}

				printf("\n\n MEDIDAS REGISTRADAS COM SUCESSO !!\n\n");
				}
		}
	}
	return Aluno;
}

void Atualizar_dados(Lista* Aluno, char *cpf){

	Lista* p=Aluno;
	if (p==NULL){
            printf("\n\nNÃO EXISTE ALUNO CADASTRADO !\n\n");
        system("pause");
	}
	else{
            printf("\n\n ~~ATUALIZAR CADASTRO~~\n\n");
            printf("\n\nINFORME O CAMPO QUE DESEJA ATUALIZAR\n\n");
	for (p=Aluno;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf) == 0){
               int menu=menu_at();
        if (menu==1){

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
				printf("\n\n ATUALIZADO COM SUCESSO\n\n");
        }
        else if (menu==2){

			printf("\nInforme o sexo (M) ou (F): ");
			scanf(" %1[^\n]", p->sexo);
			fflush(stdin);
			int val2 = validaSexo(p->sexo);
			while(val2 == 1){
				printf("\nInforme o sexo (M) ou (F) novamente: ");
				scanf(" %1[^\n]", p->sexo);
				fflush(stdin);
				val2 = validaSexo(p->sexo);
				}
				printf("\n\n ATUALIZADO COM SUCESSO\n\n");
        }
        else if (menu==3){
        printf("\nInforme seu CPF: ");
			scanf(" %12[^\n]", p->cpf);
			fflush(stdin);
			int val3 = validaCPF(p->cpf);
			while(val3 == 1){
				printf("\nDigite o CPF sem pontos e tracos: ");
				scanf(" %12[^\n]", p->cpf);
				val3 = validaCPF(p->cpf);
				}
        }

        else if (menu==4){
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
				printf("\n\n ATUALIZADO COM SUCESSO\n\n");
        }
        else if (menu==5){

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
				printf("\n\n ATUALIZADO COM SUCESSO\n\n");
        }
        else if (menu==6){
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
				printf("\n\n ATUALIZADO COM SUCESSO\n\n");
        }
        else if (menu==7){

			printf("\nInforme o E-MAIL: ");
			scanf(" %29[^\n]",p->email);
			fflush(stdin);
			int val7 = validaEmail(p->email);
			while(val7 == 1){
				printf("\nInforme o E-MAIL : ");
				scanf(" %29[^\n]", p->email);
				val7 = validaEmail(p->email);
				}

        }
        else if (menu==8){
			printf("\nInforme a data de Nascimento Ex: 01/01/2001: ");
			scanf(" %10[^\n]",p->data);
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
	}
}
void imprimir_dados(Lista *Aluno){
	Lista* p=Aluno;
	if (p==NULL){
			printf("\n\nNão há alunos cadastrados!\n\n");
			system("pause");
			}
    else {
		for (p=Aluno;p!=NULL;p=p->prox){
			printf("\nNome do Usuario:              %s", p->nome);
			printf("\nSexo:                         %s", p->sexo);
			printf("\nCPF:                          %s", p->cpf);
			printf("\nIdade:                        %s", p->idade);
			printf("\nCelular:                      %s", p->celular);
			printf("\nCidade:                       %s", p->cidade);
			printf("\nE-MAIL:                       %s", p->email);
			printf("\nData de Nascimento:           %s", p->data);
			printf("\nCoxa:                         %s", p->medidas.biceps);
			printf("\nAltura:                       %s", p->medidas.peito);
			printf("\nPeito:                        %s", p->medidas.coxa);
			printf("\nKilos:                        %s", p->medidas.kg);
			printf("\nBiceps:                       %s", p->medidas.alt);
			printf("\nativo:                        %d",p->ativo);
			printf("\n");

		}
	}
}

void Saude_Aluno(Lista* Aluno){
    char cpf2[12];
    Lista* p;
    if(Aluno==NULL){
        printf("\nNÃO EXISTE ALUNO CADASTRADO\n");
        system("pause");
    }
    else{
		float imc=0;
		printf("\n\nSAÚDE DO ALUNO\n\n");
		printf("\nInforme o CPF do Aluno: ");
		scanf(" %11[^\n]", cpf2);
		int val01 = validaCPF(cpf2);
		while(val01 == 1){
			printf("\nDigite o CPF sem pontos e tracos: ");
			scanf(" %11[^\n]", cpf2);
			val01 = validaCPF(cpf2);
			}

		for (p=Aluno;p!=NULL;p=p->prox){
			if(strcmp(p->cpf, cpf2)==0){
				float altura=atof(p->medidas.alt);
				float pesoc=atof(p->medidas.kg);
				imc=pesoc/(altura*altura);
				if (imc<17.0){
					printf("\n%s, você esta muito abaixo do peso ideal, com um IMC de %.2f.\n",p->nome,imc);
				}
				else if (imc>17.0 &&imc<18.4){
					printf("\n%s, você está abaixo do peso ideal, com um IMC de %.2f.\n ",p->nome,imc);
				}
				else if (imc>=18.5 && imc <=24.9){
					printf("\n%s, você esta com o peso ideal, IMC de %.2f.\n ",p->nome,imc);
				}
				else if (imc>=25.0 && imc<=29.99){
					printf("\n%s, você esta acima do peso, com IMC de %.2f. \n",p->nome,imc);
				}
				else if (imc>=30.0 && imc<34.99){
					printf("\n%s, você está OBESO, com um IMC de %.2f.\n",p->nome,imc);
				}
				else if(imc>=35.0 && imc <=39.99){
					printf("\n%s, você está com uma obesidade SEVERA, com um IMC de %.2f. \n",p->nome,imc);
				}
				else if(imc>40.0){
					printf("\n%s, você está com uma obesidade MÓRBIDA, com um IMC de %.2f.\n",p->nome,imc);
				}
				break;
			}


		}
	}
}

void desenvolvimentoAluno(Lista* Aluno){
	printf("DESENVOLVIMENTO DE ALUNO!\n");
	float nova_altura,novo_peito,nova_coxa,novo_biceps,resAlt,resPeso,resPeito,resBraco,resCoxs; //novo_peso,
	Lista* p=Aluno;
    if (p==NULL){
        printf("\n\nNÃO EXISTE ALUNO CADASTRADO !!\n\n");
        system("pause");
    }
    else{
    char cpf3[12];
    printf("DIGITE O CPF DO ALUNO : ");
    scanf(" %11[^\n]", cpf3);
    int b1 = validaCPF(cpf3);
	while(b1 == 1){
		printf("\nDigite o CPF sem pontos e tracos: ");
		scanf(" %11[^\n]", cpf3);
		b1 = validaCPF(cpf3);
		}
    float altura=atof(p->medidas.alt);
    float biceps=atof(p->medidas.biceps);
    float coxa=atof(p->medidas.coxa);
    float peito=atof(p->medidas.peito);
    char temp2[5];
	for (p=Aluno;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf3) == 0){
		    printf("\nAVISO !!\n");
            printf("\nESSE PROCEDIMENTO DEVE SER FEITO APÓS 3 MESES DE TREINO !! \n");

            printf("\n\nInforme sua atual altura : \n\n");
            scanf(" %4[^\n]", temp2);
			sscanf(temp2, "%f", &nova_altura);
			int a = validaNumero(temp2);
			while(a == 1){
				printf("Informe sua atual altura ? \n");
				scanf(" %4[^\n]", temp2);
				sscanf(temp2, "%f", &nova_altura);
				a = validaNumero(temp2);
				}

            if(nova_altura>altura){
                resAlt=nova_altura-altura;
                printf("Voce aumentou %.1f cm.\n",resAlt);
            }
            else if(nova_altura<altura){
                resPeso=nova_altura-altura;
                printf("Voce diminuiu %.f cm.\n",resPeso);
            }
            else if (nova_altura==altura){
                printf("Não obteve resultados ! ");
            }

            printf("\n\nInforme o peitoral : \n\n");
            scanf(" %4[^\n]", temp2);
			sscanf(temp2, "%f", &novo_peito);
			int b = validaNumero(temp2);
			while(b == 1){
				printf("\n\nInforme o peitoral : \n\n");
				scanf(" %4[^\n]", temp2);
				sscanf(temp2, "%f", &novo_peito);
				b = validaNumero(temp2);
				}

            if (novo_peito>peito){
                resPeito=novo_peito-peito;
                printf(" Voce aumentou %.1f cm.",resPeito);
            }
            else if (novo_peito<peito){
                resPeito=novo_peito-peito;
                printf("Voce diminuiu %.1f cm.",resPeito);
            }
            else if (novo_peito==peito){
                printf("Não obteve resultados ! ");

            }

            printf("\n\nInforme o biceps : \n\n");
            scanf(" %4[^\n]", temp2);
			sscanf(temp2, "%f", &novo_biceps);
			int c = validaNumero(temp2);
			while(c == 1){
				printf("Informe o biceps ? \n");
				scanf(" %4[^\n]", temp2);
				sscanf(temp2, "%f", &novo_biceps);
				c = validaNumero(temp2);
				}

            if (novo_biceps>biceps){
                resBraco=novo_biceps-biceps;
                printf("Você aumentou %.1f cm.",resBraco);
            }
            else if (novo_biceps<biceps){
                resBraco=novo_biceps-biceps;
                printf(" voce diminuiu %.1f cm",resBraco);
            }
            else if (novo_biceps==biceps){
                printf(" Não obteve resultados ! ");

            }

            printf("\n\nInforme as medidas da perna : \n\n");
			scanf(" %4[^\n]", temp2);
			sscanf(temp2, "%f", &nova_coxa);
			int c1 = validaNumero(temp2);
			while(c1 == 1){
				printf("\n\nInforme as medidas da perna : \n\n");
				scanf(" %4[^\n]", temp2);
				sscanf(temp2, "%f", &nova_coxa);
				c1 = validaNumero(temp2);
				}

            if (nova_coxa>coxa){
                resCoxs=nova_coxa-coxa;
                printf("Você aumentou %.1f cm.",resCoxs);
            }
            else if (nova_coxa<coxa){
                resCoxs=nova_coxa-coxa;
                printf("Você diminuiu %.1f cm.",resCoxs);
            }
            else if (nova_coxa==coxa){
                     printf(" Não obteve resultados ! ");
            }
        }

		}
	}
}

int financeiro(void){
    int escolha;
    do{
	printf("FINANCEIRO!\n");
	printf("                -----------------------------------\n");
	printf("                #   1 - PAGAR MêS                 #\n");
	printf("                #   2 - DESPESAS DA ACADEMIA      #\n");
	printf("                #   3 - RELATORIOS                #\n");
	printf("                #   4 - ALUNOS EM ATRASO          #\n");
	printf("                #   5 - DESATIVAR ALUNO           #\n");
	printf("                #   6 - ATIVAR ALUNO              #\n");
	printf("                #   7 - TOTAL DESPESAS            #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
	printf("\n");
	printf(">>> Escolha sua opção: ");
	scanf("%d", &escolha);
    }while(escolha>7);
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
	novo->ativo=1;
	novo->prox=NULL;

	// Lista vazia ?

	if (p==NULL){
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
	   return novo;
		}
	// novo prox aponta para ant que aponta para o proximo
	// entao o anterior agora aponta para novo
	novo->prox=ant->prox;
	ant->prox=novo;
	return aluno;
}

Lista* remover_cpf(Lista* Aluno, char* cpf){
	Lista* ant=NULL;
	Lista* p=Aluno;                  					// p é aux pra percorrer
	while((p != NULL) && strcmp(p->cpf,cpf) != 0){
		ant=p;
		p=p->prox;
		}
														// caso ELE NAO ACHAR----
		if (p==NULL){
			printf("ALUNO NÃO ENCONTRADO\n");
			return Aluno;
		}
														// ant é null so se for o primeiro elemento
		if(ant==NULL){
			Aluno=p->prox;
		}
		else{
			ant->prox=p->prox;
		}
	free(p);
	printf("CADASTRO REMOVIDO COM SUCESSO !");
	return Aluno;
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

int validaIdade(char idade[3]){
	int a;
	for(a = 0; idade[a] != '\0'; a++){
		if(idade[a] >= 48 && idade[a] <= 57){
				return 0;
		}
		else
			return 1;
		}
	return 0;
	}


int validaEmail(char *email){
	if (strlen(email) >= 8) {
        int cont = 0;
        int cont1 = 0;
        int i;
        for (i = 0; email[i] != '\0'; i++){
            if (email[i] == '@') {
                cont++;
                cont1++;
            }
            else if (email[i] == '.') {
                cont++;
            }
            else if (cont == 2 && cont1 == 1) {
                return 0;
            }
        }
    }
    return 1;
}




int validaData(char *nasc){
    int cont = 0;
	if (strlen(nasc) == 10) {
        for (cont = 0; nasc[cont] != '\0'; cont++) {
            if ((cont < 2) || (cont > 2 && cont < 5) || (cont > 5 && cont < 10)) {
                if (!(nasc[cont] >= 48 && nasc[cont] <= 57)) {
                    return 1;
                }
            }
        }
        return 0;

    }
    else {
        return 1;
		}
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

int validaCPF(char cpf[12]){


	int cont, aux1, aux2 = 0, digito;
    aux1 = (int) strlen(cpf);
    int a;
    if(aux1 == 11 && cpf[1] != cpf[3] && cpf[2] != cpf[7]){
        for (a = 9; a <= 10; a++) {
            aux2 = 0;

            for (cont = 0; cont < a; cont++)
                aux2 += (cpf[cont] - 48) * ((a + 1) - cont);

            digito = aux2 % 11;
            digito = (digito < 2 ? 0 : 11 - digito);

            if ((cpf[a] - 48) != digito) {
                return 1;
				}
        }
        return 0;
    }
    return 1;
}



int validaNumero(char desp[5]){
	int a;
	for(a = 0; desp[a] != '\0'; a++){
	if(desp[a] >= 48 && desp[a] <= 57){
		 return 0;
		}
	else{
		return 1;
		}
	}
	return 0;
	}

int meses(void){
    int escolha;
    do{
	printf("\nInforme o mês referente ao pagamento !!\n");
	printf("| 1 - JANEIRO       |\n");
	printf("| 2 - FEVEREIRO     |\n");
	printf("| 3 - MARÇO         |\n");
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

	return escolha;
}

void pagar(Lista* Aluno){
    Lista* p=Aluno;
    if (p==NULL){
        printf("\n\nNão existe aluno cadastrado !!\n\n");
        system("pause");
    }
    else{
    char cpf3[12];
    printf("DIGITE O CPF DO ALUNO : ");
    scanf(" %11[^\n]", cpf3);
    int x = validaCPF(cpf3);
	while(x == 1){
		printf("\nDigite o CPF sem pontos e tracos: ");
		scanf(" %11[^\n]", cpf3);
		x = validaCPF(cpf3);
		}
	for (p=Aluno;p!=NULL;p=p->prox){
		if(strcmp(p->cpf, cpf3) == 0){
			int mes_pag=meses();
			if(mes_pag==1){
                p->pago.janeiro=35.00;
                printf(" MêS DE JANEIRO PAGO !! \n");
			}
			else if (mes_pag==2){
                p->pago.fevereiro=35.00;
                printf(" MêS DE FEVEREIRO PAGO !! \n");
			}
			else if (mes_pag==3){
                p->pago.marco=35.00;
                printf(" MêS DE MARÇO PAGO !! \n");
			}
			else if (mes_pag==4){
                p->pago.abri=35.00;
                printf(" MêS DE ABRIL PAGO !! \n");
            }
            else if (mes_pag==5){
                p->pago.maio=35.00;
                printf(" MêS DE MAIO PAGO !! \n");
            }
            else if (mes_pag==6){
                p->pago.jun=35.00;
                printf(" MêS DE JUNHO PAGO !! \n");
            }
            else if (mes_pag==7){
                p->pago.jul=35.00;
                printf(" MêS DE JULHO PAGO !! \n");
            }
            else if (mes_pag==8){
                p->pago.ago=35.00;
                printf(" MêS DE AGOSTO PAGO !! \n");
            }
            else if (mes_pag==9){
                p->pago.set=35.00;
                printf(" MêS DE SETEMBRO PAGO !! \n");
            }
            else if (mes_pag==10){
                p->pago.out=35.00;
                printf(" MêS DE OUTUBRO PAGO !! \n");
            }
            else if (mes_pag==11){
                p->pago.nov=35.00;
                printf(" MêS DE NOVEMBRO PAGO !! \n");
            }
            else if (mes_pag==12){
                p->pago.dez=35.00;
                printf(" MêS DE DEZEMBRO PAGO !! \n");
            }
		}
		}
	}
}

Despesas despesas(Despesas me){
    float luz;
    float agua;
    float funcionarios;
    float manutencao;
    float total;
    char temp[5];
	printf("\n\nINFORME AS DESPESAS DA ACADEMIA \n\n");


	printf("Quanto gastou com luz ? \n");
	scanf(" %4[^\n]", temp);
	sscanf(temp, "%f", &luz);
	int a = validaNumero(temp);
    while(a == 1){
        printf("\nDigite novamente: ");
        scanf(" %4[^\n]", temp);
        sscanf(temp, "%f", &luz);
        a = validaNumero(temp);
    }


	printf("Quanto gastou com agua ? \n");
	scanf(" %4[^\n]", temp);
	sscanf(temp, "%f", &agua);
	int b = validaNumero(temp);
    while(b == 1){
        printf("\nDigite novamente: ");
        scanf(" %4[^\n]", temp);
        sscanf(temp, "%f", &agua);
        b = validaNumero(temp);
    }


	printf("Quanto gastou com funcionarios ? \n");
	scanf(" %4[^\n]", temp);
	sscanf(temp, "%f", &funcionarios);
	int c = validaNumero(temp);
    while(c == 1){
        printf("\nDigite novamente: ");
        scanf(" %4[^\n]", temp);
        sscanf(temp, "%f", &funcionarios);
        c = validaNumero(temp);
    }

	printf("Quanto gastou com Manutenção ? \n");
    scanf(" %4[^\n]", temp);
	sscanf(temp, "%f", &manutencao);
	int cc = validaNumero(temp);
    while(cc == 1){
        printf("\nDigite novamente: ");
        scanf(" %4[^\n]", temp);
        sscanf(temp, "%f", &manutencao);
        cc = validaNumero(temp);
    }

	total=luz+agua+funcionarios+manutencao;
	//int mes;
	printf(" TOTAL %f",total);
	printf(" QUAL O MES DESEJA CONTABILIZAR AS DESPESAS ?");
	int mes_pag=meses();
	printf("chegou ");

	if(mes_pag==1){
        me.janeiro=total;

        printf(">>> MêS DE JANEIRO CONTABILIZADO\n");
        //mes = 1;
		}
	else if (mes_pag==2){
		me.fevereiro=total;
		printf(">>>  MêS DE FEVEREIRO CONTABILIZADO!! \n");
		//mes = 2;
		}
	else if (mes_pag==3){
		me.marco=total;
		printf(">>>  MêS DE MARÇO CONTABILIZADO !! \n");
		//mes = 3;
		}
	else if (mes_pag==4){
		me.abri=total;
		printf(">>>  MêS DE ABRIL CONTABILIZADO !! \n");
		//mes = 4;
		}
	else if (mes_pag==5){
		me.maio=total;
		printf(">>>  MêS DE MAIO CONTABILIZADO !! \n");
		//mes = 5;
		}
	else if (mes_pag==6){
		me.jun=total;
		printf(">>>  MêS DE JUNHO CONTABILIZADO !! \n");
		//mes = 6;
		}
	else if (mes_pag==7){
		me.jul=total;
		printf(">>>  MêS DE JULHO CONTABILIZADO !! \n");
		//mes = 7;
		}
	else if (mes_pag==8){
		me.ago=total;
		printf(">>>  MêS DE AGOSTO CONTABILIZADO !! \n");
		//mes = 8;
		}
	else if (mes_pag==9){
		me.set=total;
		printf(">>>  MêS DE SETEMBRO CONTABILIZADO !! \n");
		//mes = 9;
		}
	else if (mes_pag==10){
		me.out=total;
		printf(">>>  MêS DE OUTUBRO CONTABILIZADO !! \n");
		//mes = 10;
		}
	else if (mes_pag==11){
		me.nov=total;
		printf(">>>  MêS DE NOVEMBRO CONTABILIZADO !! \n");
		//mes = 11;
		}
	else if (mes_pag==12){
		me.dez=total;
		printf(">>>  MêS DE DEZEMBRO CONTABILIZADO !! \n");
		//mes = 12;
	}
return me;
}

void desativar(Lista* aluno){
	Lista* p=aluno;
		if (p==NULL){
			printf("\nNão existe aluno cadastrado.\n");
			system("pause");
		}
		else{
            mostrar_aluno(p);
            printf("\n\n");
		char cpf3[12];
		printf("DIGITE O CPF DO ALUNO : ");
		scanf(" %11[^\n]", cpf3);
		int x = validaCPF(cpf3);
		while(x == 1){
			printf("\nDigite o CPF sem pontos e tracos: ");
			scanf(" %11[^\n]", cpf3);
			x = validaCPF(cpf3);
		}
		for (p=aluno;p!=NULL;p=p->prox){
			if(strcmp(p->cpf, cpf3) == 0){
				p->ativo=0;
				printf("\nO aluno %s, desativado do sistema com sucesso.\n\n", p->nome);
			}
        }
    }
}

void mostrar_aluno(Lista* aluno){
	Lista* p=aluno;
		if (p==NULL){
			printf("\n\nNão existe aluno cadastrado !!\n\n");
			system("pause");
		}
		else{
		for (p=aluno;p!=NULL;p=p->prox){
			if(p->ativo==1){
				printf("ALUNOS ATIVOS ! ");
				printf("%s\n", p->nome);
			}
		}
	}
}

void relatorios (Lista* aluno){
	Lista* p=aluno;
    if (p==NULL){
        printf("\n\nNão existe aluno cadastrado!!\n\n");
        system("pause");
    }
    else{
		float recebeu;

			printf("Informe um mes que deseja consultar receita: ");
			int mes_pag=meses();
			if(mes_pag==1){
				recebeu=p->pago.janeiro;
					printf("\nSaldo no mes de janeiro %.2f\n",recebeu);
				}
				else if (mes_pag==2){
					recebeu=p->pago.fevereiro;
					printf("\nSaldo do mes de fevereiro %.2f\n",recebeu);
				}
				else if (mes_pag==3){
					recebeu=p->pago.marco;
					printf("\nSaldo no mes de março %.2f\n",recebeu);
				}
				else if (mes_pag==4){
					recebeu=p->pago.abri;
					printf("\nSaldo no mes de abril %.2f\n",recebeu);
				}
				else if (mes_pag==5){
					recebeu=p->pago.maio;
					printf("\nSaldo no mes de maio %.2f\n",recebeu);
				}
				else if (mes_pag==6){
					recebeu=p->pago.jul;
					printf("\nSaldo no mes de junho %.2f\n",recebeu);
				}
				else if (mes_pag==7){
				   recebeu=p->pago.jul;
					printf("\nSaldo no mes de julho %.2f\n",recebeu);
				}
				else if (mes_pag==8){
					recebeu=p->pago.ago;
					printf("\nSaldo no mes de Agosto %.2f\n",recebeu);
				}
				else if (mes_pag==9){
					recebeu=p->pago.set;
					printf("\nSaldo no mes de setembro %.2f\n",recebeu);
				}
				else if (mes_pag==10){
					recebeu=p->pago.out;
					printf("\nSaldo no mes de outubro %.2f\n",recebeu);
				}
				else if (mes_pag==11){
					recebeu=p->pago.nov;
					printf("\nSaldo no mes de Novembro %.2f\n",recebeu);
				}
				else if (mes_pag==12){
					recebeu=p->pago.dez;
					printf("\nSaldo no mes de dezembro %.2f\n",recebeu);
			}
		}
    }

void alunos_atrasos(Lista* aluno){
	Lista* p=aluno;
	if (p==NULL){
			printf("\nNão existe aluno cadastrado.\n");
			system("pause");
		}
		else{

		for (p=aluno;p!=NULL;p=p->prox){
			printf("\n%s está devendo ", p->nome);
				if(p->pago.janeiro==0){
					printf(">>> Janeiro \n");
					}
				if (p->pago.fevereiro==0){
					printf(">>> Fevereiro \n");
					}
				 if (p->pago.marco==0){
					printf(">>> Março \n");
					}
				 if (p->pago.abri==0){
					printf(">>> Abril \n");
					}
				 if (p->pago.maio==0){
					printf(">>> Maio \n");
					}
				 if (p->pago.jun==0){
					printf(">>> Junho \n");
					}
				 if (p->pago.jul==0){
				   printf(">>> Julho \n");
					}
				 if (p->pago.ago==0){
					printf(">>> Agosto \n");
					}
				 if (p->pago.set==0){
					printf(">>> Setembro \n");
					}
				 if (p->pago.out==0){
					printf(">>> Outubro \n");
					}
				 if (p->pago.nov==0){

					printf(">>> Novembro \n");
					}
				 if (p->pago.dez==0){
					printf(">>> Dezembro \n");
					}
			}
	}
}

void total_despesas(Despesas re){
		float recebeu;

			printf("Informe um mes que deseja consultar as despesas : ");
			int mes_pag=meses();

			if(mes_pag==1){
				recebeu=re.janeiro;
					printf("\nDespesas em janeiro %.1f R$\n",recebeu);
				}
				else if (mes_pag==2){
					recebeu=re.fevereiro;
					printf("\nDespesas em fevereiro %.1f R$\n",recebeu);
				}
				else if (mes_pag==3){
					recebeu=re.marco;
					printf("\nDespesas em março %.1f R$\n",recebeu);
				}
				else if (mes_pag==4){
					recebeu=re.abri;
					printf("\nDespesas em abril %.1f R$\n",recebeu);
				}
				else if (mes_pag==5){
					recebeu=re.maio;
					printf("\nDespesas em maio %.1f R$\n",recebeu);
				}
				else if (mes_pag==6){
					recebeu=re.jun;
					printf("\nDespesas em junho %.1f R$\n",recebeu);
				}
				else if (mes_pag==7){
				   recebeu=re.jul;
					printf("\nDespesas em julho %.1f R$\n",recebeu);
				}
				else if (mes_pag==8){
					recebeu=re.ago;
					printf("\nDespesas em Agosto %.1f R$\n",recebeu);
				}
				else if (mes_pag==9){
					recebeu=re.set;
					printf("\nDespesas em setembro %.1f R$\n",recebeu);
				}
				else if (mes_pag==10){
					recebeu=re.out;
					printf("\nDespesas em outubro %.1f R$\n",recebeu);
				}
				else if (mes_pag==11){
					recebeu=re.nov;
					printf("\nDespesas em Novembro %.1f R$\n",recebeu);
				}
				else if (mes_pag==12){
					recebeu=re.dez;
					printf("\nDespesas em dezembro %.1f R$\n",recebeu);
			}
		}

Lista* carregar(Lista* Aluno) {
    FILE *file = fopen("banco.txt", "r");

    char nome[81];
	char sexo[2];
	char cpf[12];
	char idade[3];
	char celular[20];
	char cidade[81];
	char email[30];
	char data[12];
	char alt[4];
	char biceps[4];
	char coxa[4];
	char kg[4];
	char peito[4];
	int ativo;
	//file = fopen("teste.txt", "r");
        while (fscanf(file, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|\n", nome,sexo,cpf,idade,celular,cidade,email,data,alt,biceps,coxa,kg,peito,&ativo) != EOF) {
            Lista* nova = (Lista*) malloc(sizeof(Lista));
   //         if (nome[0] >= 33) {
                strcpy(nova->nome, nome);
                strcpy(nova->sexo, sexo);
                strcpy(nova->cpf,cpf);
                strcpy(nova->idade,idade);
                strcpy(nova->celular,celular);
                strcpy(nova->cidade,cidade);
                strcpy(nova->email,email);
                strcpy(nova->data,data);
                strcpy(nova->medidas.alt,alt);
                strcpy(nova->medidas.biceps,biceps);
                strcpy(nova->medidas.coxa,coxa);
                strcpy(nova->medidas.kg,kg);
                strcpy(nova->medidas.peito,peito);
                nova->ativo=ativo;
                nova->prox = Aluno;
                Aluno = nova;
            //}
        }
    fclose(file);
    return Aluno;
    }


void salvartudo(Lista* Aluno) {
    FILE *file = fopen("banco.txt", "w");
    if (file == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    } else {
        Lista* aux;
        for (aux = Aluno; aux != NULL; aux = aux->prox) {
            fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%d|\n", aux->nome, aux->sexo,aux->cpf, aux->idade,aux->celular,aux->cidade,aux->email, aux->data, aux->medidas.alt, aux->medidas.biceps, aux->medidas.coxa, aux->medidas.kg, aux->medidas.peito,aux->ativo);
        }
        fclose(file);
    }
}


int menu_at(void){
int escolha;
do{
	printf("                -----------------------------------\n");
	printf("                #   1 - NOME                      #\n");
	printf("                #   2 - SEXO                      #\n");
	printf("                #   3 - CPF                       #\n");
	printf("                #   4 - IDADE                     #\n");
	printf("                #   5 - CELULAR                   #\n");
	printf("                #   6 - CIDADE                    #\n");
	printf("                #   7 - EMAIL                     #\n");
	printf("                #   8 - DATA DE NASCIMENTO        #\n");
	printf("                #   0 - SAIR                      #\n");
	printf("                -----------------------------------\n");
    scanf("%d",&escolha);
	}while(escolha>12&&escolha<1);

	return escolha;
}

void ativar(Lista* aluno){
	Lista* p=aluno;
		if (p==NULL){
			printf("\nNão existe aluno cadastrado.\n");
			system("pause");
		}
		else{
                if(alunos_desativaados(p)==0){
            printf("Não existe alunos inativos");
		}
		else {

                printf("\n\n");
		char cpf3[12];
		printf("DIGITE O CPF DO ALUNO : ");
		scanf(" %11[^\n]", cpf3);
		int x = validaCPF(cpf3);
		while(x == 1){
			printf("\nDigite o CPF sem pontos e tracos: ");
			scanf(" %11[^\n]", cpf3);
			x = validaCPF(cpf3);
		}
		for (p=aluno;p!=NULL;p=p->prox){

			if(strcmp(p->cpf, cpf3) == 0){
				p->ativo=1;
				printf("O aluno %s, Esta ativado com sucesso.", p->nome);
			}
        }
    }

		}
}
int alunos_desativaados(Lista* aluno){
	Lista* p=aluno;
	int cont=0;
		if (p==NULL){
			printf("\n\nNão existe aluno cadastrado !!\n\n");
			system("pause");
		}
		else{

		for (p=aluno;p!=NULL;p=p->prox){
			if(p->ativo==0){
			    cont++;
				printf("ALUNOS INATIVOS ! \n");
				printf("%s\n", p->nome);
			}
		}

	}
	return cont;
}




/*void salvardespesas(Despesas* d){
	FILE *file = fopen("bancod.txt", "w");
	if (file == NULL) {
		printf("Houve um erro ao abrir o arquivo.\n");
		exit(1);
	}
	else {
		Despesas* aux;
		for(aux = d;aux != NULL;aux=aux->prox){
			fprintf(file, "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n",aux->janeiro, aux->fevereiro, aux->marco, aux->abri, aux->maio, aux->jun, aux->jul, aux->ago, aux->set, aux->out, aux->nov, aux->dez);
		}
		fclose(file);
	}

}

Despesas* carregardespesas(Despesas* d){
	FILE *file = fopen("bancod.txt", "a+");
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
	if (file == NULL) {
		printf("Houve um erro ao abrir o arquivo.\n");
		exit(1);
		}
	else {
	while(fscanf(file, "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n", &janeiro, &fevereiro, &marco, &abri, &maio, &jun, &jul, &ago, &set, &out, &nov, &dez) != EOF){
		Despesas* nova = (Despesas*) malloc(sizeof(Despesas));
		nova->janeiro=janeiro;
		nova->fevereiro=fevereiro;
		nova->marco=marco;
		nova->abri=abri;
		nova->maio=maio;
		nova->jun=jun;
		nova->jul=jul;
		nova->ago=ago;
		nova->set=set;
		nova->out=out;
		nova->nov=nov;
		nova->dez=dez;
		nova->prox = d;
		d = nova;

		}
	fclose(file);
	}
	return d;
}*/
