#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


      char login [6] = "admin", login1[6];          // Login: admin - Senha: saude518
      char senha [9] = "saude518", senha1 [9];
      int x, y;

     struct cadastro 
    {                        
        char nome [50];
        char nsocial[50];
        char cpf [14];
        char telefone [13];
        char endereco  [100];
        char cep [10];
        int  ndia, nmes, nano;
        char email [40];
        int diag_dia, diag_mes, diag_ano;
    };

    void main( )
{

    do
    {

       printf("Digite seu login: ");
       fgets(login1, 6, stdin);
       fflush(stdin);

       printf("Digite sua senha: ");
       fgets(senha1, 9, stdin);
       fflush(stdin);

       x = (strcmp(login, login1));
       y = (strcmp(senha, senha1));

        if(x != 0)
            {
                printf("\n\n Login Invalido\n");
            }
        else if(y != 0)
            {
                printf("\n\n Senha Invalida\n");
            }

    } while (x || y);


      int op = 1;

      do{

                FILE *grisco;                             // FILE função para abertura e manipulacao de arquivos
                FILE *CadCompleto;

                char escolha;                      
                int opcao;                            
                int ano;                                
                char *cmbd [15];               // define qual comorbidade

              struct cadastro cad;


            printf("\n\n**********************");
            printf("\nCadastro de paciente");
            printf("\n***********************\n\n");


                     printf("Digite o nome : ");
                     fgets(cad.nome, 50, stdin);
                     fflush(stdin);

                     printf("Digite o nome social : ");      // Mais diversidade , Carta de Direitos dos Usuários do SUS (Portaria nº 1.820, de 13 de agosto de 2009)
                     fgets(cad.nsocial, 50, stdin);
                     fflush(stdin);

                     printf("Digite cpf: ");
                     fgets(cad.cpf, 14, stdin);
                     fflush(stdin);

                     printf("Digite o telefone: ");
                     fgets(cad.telefone, 13, stdin);
                     fflush(stdin);

                     printf("Digite o endereco (rua, numero, bairro, cidade, estado): ");
                     fgets(cad.endereco, 100, stdin);
                     fflush(stdin);

                     printf("Digite o cep: ");
                     fgets(cad.cep, 10, stdin);
                     fflush(stdin);

                     printf("Digite a data de nascimento  [dd mm aaaa]: ");
                     scanf("%d %d %d", &cad.ndia, &cad.nmes,&cad.nano);
                     fflush(stdin);

                     printf("Digite o email: ");
                     fgets(cad.email, 40, stdin);
                     fflush(stdin);

                      printf("Digite a data do diagnostico [dd mm aaaa]: ");
                      scanf("%d %d %d", &cad.diag_dia, &cad.diag_mes, &cad.diag_ano );
                      fflush(stdin);


                    printf("\n\n\nO paciente possui alguma comorbidade? s/n  :  ");
                    scanf("%c",&escolha);
                    escolha = toupper (escolha);                    

        if(escolha == 'S')
        {
            printf("\n1: Diabetes\n");
         	printf("2: Obesidade\n");
         	printf("3: Hipertensao\n");
         	printf("4: Tuberculose\n");
         	printf("5: Outros\n");
            printf("Digite o numero correspondente: ");
         	scanf("%d",&opcao);
         	fflush(stdin);

         	if(opcao == 1)
            {
                *cmbd = "Diabetes";
         	}
         	 if (opcao == 2)
            {
                *cmbd = "Obesidade";
         	}
         	if  (opcao == 3)
            {
                *cmbd = "Hipertensao";
         	}
         	if (opcao == 4) 
            {
            	*cmbd = "Tuberculose";
         	}
             if (opcao == 5)
            {
                *cmbd = "Outros";
         	}

       }

      else  *cmbd = "Nenhuma";         


                int  aux =   365 * cad.diag_ano + 30 * cad.diag_mes + cad.diag_dia - 365 * cad.nano - 30 * cad.nmes - cad.ndia; 
                ano = aux / 365;      // Cálculo Idade

                if  (ano > 65 || escolha == 'S')
                {                            

                       grisco = fopen ("Grupo_risco.txt", "w");                  

                       fprintf(grisco, "\n*Grupo de risco*\n");                   
                       fprintf(grisco, "\nCEP: %s",cad.cep );                      
                       fprintf(grisco, "Idade: %d anos\n", ano);

                       fclose(grisco);                                  

                       printf("\n\n Um arquivo txt foi gerado!!\n\n");          // para aparecer no console que o arquivo foi gerado

                }
            else

                 printf("\n\nO paciente nao faz parte do grupo de risco!!\n\n");


                CadCompleto  = fopen ("Cadastro_Completo.txt", "w");          // Gerando o arquivo txt do cadastro completo ao fim do programa.

                      fprintf(CadCompleto,"\n**Cadastro Completo**\n");
                      fprintf(CadCompleto,"\nNome: %s", cad.nome);
                      fprintf(CadCompleto,"Nome social: %s", cad.nsocial);
                      fprintf(CadCompleto,"Cpf: %s", cad.cpf);
                      fprintf(CadCompleto,"Telefone: %s", cad.telefone);
                      fprintf(CadCompleto,"Endereco: %s", cad.endereco);
                      fprintf(CadCompleto,"Cep: %s", cad.cep);
                      fprintf(CadCompleto,"Data de nascimento: %d %d %d\n", cad.ndia, cad.nmes, cad.nano);
                      fprintf(CadCompleto,"E-mail: %s", cad.email);
                      fprintf(CadCompleto,"Data do diagnostico: %d %d %d\n", cad.diag_dia, cad.diag_mes, cad.diag_ano);
                      fprintf(CadCompleto,"Comorbidade: %s", *cmbd);

                fclose(CadCompleto);

                printf("Digite 1 para novo cadastro\n");
                printf("Digite 0 para Sair\n");
                printf("Digite: ");
                scanf("%d", &op);
                fflush(stdin);

       } while(op != 0);

    system("pause");
 
   
 }