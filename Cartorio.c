#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de de alocações de texto por região 
#include <string.h>//biblioteca responsavel por cuidar de strings
int registro() //Função responsavel por cadastrar os usuarios no sistema
{
		setlocale(LC_ALL, "Portuguese"); //defininado linguagem
		
	//inicio criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/strings
	
	printf("Digite o CPF que deseja cadastrar: "); //coletando informações do usuario
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
	
	if(file == NULL) //"if"="se" o arquivo não existir (null) dizer o seguinte abaixo
	{
		printf("O arquivo não foi localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while= enquanto
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");//o system pause "para" o menu até apertar alguma tecla 
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
 	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}


int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");	//responsavel por limpar a tela, (ja começar limpo)
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem  
	
		printf("---  Cartório da EBAC  ---\n\n"); //Inicio do Menu
		printf("Escolha a opção desejada no menu:\n\n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//Fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();  //chamada de funções 
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
			
			
				
		
		}	//Fim da seleção

	
	
	
	}
}
 
