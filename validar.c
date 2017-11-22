#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Assinaturas

int validaNome(char nome[81]);
int validaTelefone(char telefone[12]);
int validaSexo(char sexo[9]);
int validaIdade(char idade[3]);
int validaCidade(char cidade[51]);
int validaEmail(char email[21]);
int validaNasc(char nasc[11]);

int main(void){
	int val;
	char nasc[11];
	printf("Insira o nome: ");
	scanf(" %11[^\n]", nasc);
	val = validaNasc(nasc);
	printf(" %s ", nasc);
	while(val == 1){
		printf("Digite o telefone novamente: ");
		scanf(" %11[^\n]", nasc);
		val = validaNasc(nasc);
		}
	return 0;
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

int validaTelefone(char telefone[12]){
	int a;
	int j = strlen(telefone);
	for(a = 0; telefone[a] != '\0'; a++){
		if((telefone[a] >= 65 && telefone[a] <= 90) && (telefone[a] >=97 && telefone[a] <= 122) && (j < 11))
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

int validaIdade(char idade[3]){
	int a; 
	int j = strlen(idade);
	for(a = 0; idade[a] != '\0'; a++){
		if(j < 0)
			return 1; 
		if((idade[a] >= 'a' || idade[a] <= 'z') || (idade[a] >= 'A' || idade[a] <= 'Z'))
			return 1;
		else 
			return 0;
		}
	return 0;
	}

int validaCidade(char cidade[51]){
	int a;
	for(a = 0; cidade[a] != '\0'; a++){
		if(cidade[a] >= 48 || cidade[a] <= 57 )
			return 1;
		else 
			return 0;
		}
	return 0;
	}

int validaEmail(char email[21]){
	int a; 
	for(a = 0; email[a] != '\0'; a++){
		if(email[a] == 68 && email[a] == 46)
			return 0;	
		else
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
