#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // Biblioteca responsável por criar string

int registro() // função responsavel por cadastrar usuarios no sistema
{
	
	// inicio da criaçao das variaveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criaçao das variaveis
	
	printf ("Digite o CPF a ser cadastrado:"); // coletando informaçao do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar as string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo,"w"); // Cria arquivo
	fprintf(file, cpf); // Salva o valor da variável
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
		printf("Nâo foi possível abrir o arquivo, não localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("O CPF digitado não foi encontrado no sistema!. \n");
		system("pause");
		return 0;
	}
    
	fclose(file);
	
	printf("Deseja deletar este aluno do sistema?");
	printf("%s" , cpf);
	printf("\nDigite (S) para sim ou digite (N) para não! \n\n");
	
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
		printf("Opção inválida");
		system("pause");
	}
	
}




int main()
    {
	int opcao =0;// definindo variáveis
	int laco =1;
	
	for(laco =1; laco =1;)
	{
	
	
	    setlocale(LC_ALL, "Portuguese");// definindo linguagens 
	    
	    system("cls");
	
	    printf("### Cartório da Juriscreuda ###\n\n");// início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    
	    printf("Opção:");// fim do menu
    
    
        scanf("%d", &opcao);// armazenando a escolha do usuário
    
        system("cls"); // responsavel por limpar a tela
        
        
        switch(opcao) // inicio da seleçao do menu
        {
        	case 1:
        	registro(); // chamada de funçoes registro
    	    break;
    	   
    	    case 2:
    	    consulta(); // chamada de funçoes consulta
		    break;
		    
		    case 3:
		    deletar(); // chamada de funçoes deletar
 		    break;
 		    
 		    
 		
 		
 	        default:
 		    printf("Esta opção não esta disponível!\n");
		    system ("pause");
			break;	
			// fim da seleçao
		    	
		}
    
       
    }
     
}

