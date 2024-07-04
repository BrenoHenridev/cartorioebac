#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // Biblioteca respons�vel por criar string

int registro() // fun��o responsavel por cadastrar usuarios no sistema
{
	
	// inicio da cria�ao das variaveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria�ao das variaveis
	
	printf ("Digite o CPF a ser cadastrado:"); // coletando informa�ao do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar as string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo,"w"); // Cria arquivo
	fprintf(file, cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");// definindo linguagens 
	
	char cpf [40];
	char conteudo[200];
	
	
	printf("Digite o seu CPF: ");
	scanf("%s" , cpf);
	
	FILE *file;
	file = fopen(cpf , "r");
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do aluno a ser deletado: ");
	scanf("%s" , cpf);
	
	FILE *file;
	file = fopen(cpf , "r");
	
	if (file == NULL)
	{
		printf("O CPF digitado n�o foi encontrado no sistema!. \n");
		system("pause");
		return 0;
	}
    
	fclose(file);
	
	printf("Deseja deletar este aluno do sistema?");
	printf("%s" , cpf);
	printf("\nDigite (S) para sim ou digite (N) para n�o! \n\n");
	
	getchar();
	
	char opcao;
	opcao = getchar();
	
	if (opcao == 's' || opcao == 'S')
	{
	if (remove(cpf) == 0)
	{
		printf("Aluno deletado com sucesso!\n");
	}
	    system("pause");
    }
    
    
    else if (opcao == 'n' || opcao == 'N')
    {
    	printf("Retorne ao menu principal \n");
    	system("pause");
	}
	
	else
	{
		printf("Op��o inv�lida");
		system("pause");
	}
	
}




int main()
    {
	int opcao =0;// definindo vari�veis
	int laco =1;
	
	for(laco =1; laco =1;)
	{
	
	
	    setlocale(LC_ALL, "Portuguese");// definindo linguagens 
	    
	    system("cls");
	
	    printf("### Cart�rio da Juriscreuda ###\n\n");// in�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    
	    printf("Op��o:");// fim do menu
    
    
        scanf("%d", &opcao);// armazenando a escolha do usu�rio
    
        system("cls"); // responsavel por limpar a tela
        
        
        switch(opcao) // inicio da sele�ao do menu
        {
        	case 1:
        	registro(); // chamada de fun�oes registro
    	    break;
    	   
    	    case 2:
    	    consulta(); // chamada de fun�oes consulta
		    break;
		    
		    case 3:
		    deletar(); // chamada de fun�oes deletar
 		    break;
 		    
 		    
 		
 		
 	        default:
 		    printf("Esta op��o n�o esta dispon�vel!\n");
		    system ("pause");
			break;	
			// fim da sele�ao
		    	
		}
    
       
    }
     
}

