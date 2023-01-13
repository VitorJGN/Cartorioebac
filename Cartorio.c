#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de de aloca��es de texto por regi�o 
#include <string.h>//biblioteca responsavel por cuidar de strings
int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
		setlocale(LC_ALL, "Portuguese"); //defininado linguagem
		
	//inicio cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("Digite o CPF que deseja cadastrar: "); //coletando informa��es do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");// cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digitet o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //defininado linguagem
	 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar:");
	scanf("%s",cpf);
	
	FILE *file; // mandando abrir o arquivo
	file = fopen(cpf,"r");//r=read "ler"
	
	if(file == NULL) //"if"="se" o arquivo n�o existir (null) dizer o seguinte abaixo
	{
		printf("O arquivo n�o foi localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while= enquanto
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");//o system pause "para" o menu at� apertar alguma tecla 
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
 	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}


int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");	//responsavel por limpar a tela, (ja come�ar limpo)
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem  
	
		printf("---  Cart�rio da EBAC  ---\n\n"); //Inicio do Menu
		printf("Escolha a op��o desejada no menu:\n\n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//Fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro();  //chamada de fun��es 
			system("pause");
			break;
			
			case 2:
			consulta();
			system("pause");
			break;
			
			case 3:	
			deletar();
			system("pause");
			break;
			
			default: 
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			
			
				
		
		}	//Fim da sele��o

	
	
	
	}
}
 
