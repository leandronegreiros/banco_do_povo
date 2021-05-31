#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura de clientes*/
struct cliente
{
    char nome[30];
    char cpf[14];
    int contaCorrente;
    char senha[20];
    int agencia;
    float rendaMensal;
    float saldo;
};

/* Variavel clientes*/
struct cliente cliente;
struct cliente cliente_aux[2];
struct cliente cliente_delet[2];
struct cliente clientes[2];

/* Funcao que faz o encerramento da conta*/
int encerrarConta()
{
    int funcaoSelecionada;
    int count = 0;

    printf("Encerrar conta...\n\n");
    printf("Infome a agencia do cliente: ");
    scanf("%d", &cliente_delet[0].agencia);
    printf("Infome a conta corrente do cliente: ");
    scanf("%d", &cliente_delet[0].contaCorrente);

    printf("Agencia: %d\n", cliente_delet[0].agencia);
    printf("Conta corrente: %d\n", cliente_delet[0].contaCorrente);

    for (int i = 0; i < 3; i++)
    {
        if (clientes[i].agencia == cliente_delet[0].agencia && clientes[i].contaCorrente == cliente_delet[0].contaCorrente)
        {
            printf("\n\n[1] Nome: %s\n", clientes[i].nome);
            printf("[2] CPF: %s\n", clientes[i].cpf);
            printf("[3] Conta corrente: %d\n", clientes[i].contaCorrente);
            printf("[4] Senha: %s\n", clientes[i].senha);
            printf("[5] Agencia: %d\n", clientes[i].agencia);
            printf("[6] Renda Mensal: %.2f\n\n", clientes[i].rendaMensal);
        }
    }
}

/* Funcao que faz a atualizacao dos dados do cliente*/
int atualizarDadosCliente()
{
    int funcaoSelecionada;
    int count = 0;

    printf("Atualizar dados...\n\n");

    printf("Infome a agencia do cliente: ");
    scanf("%d", &cliente_aux[0].agencia);

    printf("Infome a conta corrente do cliente: ");
    scanf("%d", &cliente_aux[0].contaCorrente);

    printf("\n\nCliente cadastrado com sucesso: \n");
    printf("Nome: %s\n", clientes[0].nome);
    printf("CPF: %s\n", clientes[0].cpf);
    printf("Conta Corrente: %d\n", clientes[0].contaCorrente);
    printf("Senha: %s\n", clientes[0].senha);
    printf("Agencia: %d\n", clientes[0].agencia);
    printf("Renda Mensal: %.2f\n\n", clientes[0].rendaMensal);
    printf("Saldo: %.2f\n", clientes[0].saldo);

    printf("\n\nCliente cadastrado com sucesso: \n");
    printf("Nome: %s\n", clientes[1].nome);
    printf("CPF: %s\n", clientes[1].cpf);
    printf("Conta Corrente: %d\n", clientes[1].contaCorrente);
    printf("Senha: %s\n", clientes[1].senha);
    printf("Agencia: %d\n", clientes[1].agencia);
    printf("Renda Mensal: %.2f\n\n", clientes[1].rendaMensal);
    printf("Saldo: %.2f\n", clientes[1].saldo);

    printf("\n\nCliente cadastrado com sucesso: \n");
    printf("Nome: %s\n", clientes[2].nome);
    printf("CPF: %s\n", clientes[2].cpf);
    printf("Conta Corrente: %d\n", clientes[2].contaCorrente);
    printf("Senha: %s\n", clientes[2].senha);
    printf("Agencia: %d\n", clientes[2].agencia);
    printf("Renda Mensal: %.2f\n\n", clientes[2].rendaMensal);
    printf("Saldo: %.2f\n", clientes[2].saldo);

    for (int i = 0; i < 3; i++)
    {
        if (clientes[i].agencia == cliente_aux[0].agencia && clientes[i].contaCorrente == cliente_aux[0].contaCorrente)
        {
            do
            {
                system("clear"); /* No windows e: system("cls"); */
                printf("\nMENU DE ATUALIZACAO DO CLIENTE\n");
                printf("***********Banco do Povo***********\n");
                printf("[1] Nome: %s\n", clientes[i].nome);
                printf("[2] CPF: %s\n", clientes[i].cpf);
                printf("[3] Conta corrente: %d\n", clientes[i].contaCorrente);
                printf("[4] Senha: %s\n", clientes[i].senha);
                printf("[5] Agencia: %d\n", clientes[i].agencia);
                printf("[6] Renda Mensal: %.2f\n", clientes[i].rendaMensal);
                printf("[0] Sair\n");
                scanf("%d", &funcaoSelecionada);
                system("clear"); /* No windows e: system("cls"); */

                switch (funcaoSelecionada)
                {
                case 1: /* Editar nome*/

                    printf("Infome o nome do cliente: ");
                    scanf("%s", &clientes[i].nome);

                    break;
                case 2: /* Editar CPF*/

                    printf("Infome o CPF do cliente: ");
                    scanf("%s", &clientes[i].cpf);

                    break;
                case 3: /*  Editar conta corrente*/

                    printf("Infome a conta corrente do cliente: ");
                    scanf("%d", &clientes[i].contaCorrente);

                    break;
                case 4: /*  Editar senha*/

                    printf("Infome a senha do cliente: ");
                    scanf("%s", &clientes[i].senha);

                    break;
                case 5: /*  Editar agencia*/

                    printf("Infome a agencia do cliente: ");
                    scanf("%d", &clientes[i].agencia);

                    break;
                case 6: /*  Editar Renda mensal*/

                    printf("Infome a renda mensal do cliente: ");
                    scanf("%f", &clientes[i].rendaMensal);

                    break;
                case 0: /* Sair*/
                    break;
                default:
                    printf("\n infome novamente!\n");
                    break;
                }

            } while (funcaoSelecionada != 0);

            break;
        }
        else
        {
            count++;
            if (count == 3)
            {
                printf("Cliente nao encontrado\n");
                break;
            }
        }
    }
}

/* Funcao que faz a abertura de conta*/
int abrirConta()
{
    int cont = 0;
    for (int i = 0; i < 3; i++)
    {
        if (strlen(clientes[i].nome) == 0)
        {
            printf("Infome o nome do cliente: ");
            scanf("%s", &clientes[i].nome);

            printf("Infome o CPF do cliente: ");
            scanf("%s", &clientes[i].cpf);

            printf("Infome a conta corrente do cliente: ");
            scanf("%d", &clientes[i].contaCorrente);

            printf("Infome a senha do cliente: ");
            scanf("%s", &clientes[i].senha);

            printf("Infome a agencia do cliente: ");
            scanf("%d", &clientes[i].agencia);

            printf("Infome a renda mensal do cliente: ");
            scanf("%f", &clientes[i].rendaMensal);

            printf("Infome o saldo do cliente: ");
            scanf("%f", &clientes[i].saldo);

            /*
            system("clear"); 
            printf("\nCliente cadastrado com sucesso: \n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Conta Corrente: %d\n", clientes[i].contaCorrente);
            printf("Senha: %s\n", clientes[i].senha);
            printf("Agencia: %d\n", clientes[i].agencia);
            printf("Renda Mensal: %.2f\n", clientes[i].rendaMensal);
            printf("Saldo: %.2f\n", clientes[i].saldo);
            */

            printf("\n\nCliente cadastrado com sucesso: \n");
            printf("Nome: %s\n", clientes[0].nome);
            printf("CPF: %s\n", clientes[0].cpf);
            printf("Conta Corrente: %d\n", clientes[0].contaCorrente);
            printf("Senha: %s\n", clientes[0].senha);
            printf("Agencia: %d\n", clientes[0].agencia);
            printf("Renda Mensal: %.2f\n\n", clientes[0].rendaMensal);
            printf("Saldo: %.2f\n", clientes[0].saldo);

            printf("\n\nCliente cadastrado com sucesso: \n");
            printf("Nome: %s\n", clientes[1].nome);
            printf("CPF: %s\n", clientes[1].cpf);
            printf("Conta Corrente: %d\n", clientes[1].contaCorrente);
            printf("Senha: %s\n", clientes[1].senha);
            printf("Agencia: %d\n", clientes[1].agencia);
            printf("Renda Mensal: %.2f\n\n", clientes[1].rendaMensal);
            printf("Saldo: %.2f\n", clientes[1].saldo);

            printf("\n\nCliente cadastrado com sucesso: \n");
            printf("Nome: %s\n", clientes[2].nome);
            printf("CPF: %s\n", clientes[2].cpf);
            printf("Conta Corrente: %d\n", clientes[2].contaCorrente);
            printf("Senha: %s\n", clientes[2].senha);
            printf("Agencia: %d\n", clientes[2].agencia);
            printf("Renda Mensal: %.2f\n\n", clientes[2].rendaMensal);
            printf("Saldo: %.2f\n", clientes[2].saldo);

            break;
        }
        else
        {
            cont++;
            if (cont == 3)
            {
                printf("O cadastro de cliente e limitado a 3 pessoas!\n");
            }
        }
    }
}

/* Funcao que informa o perfil do gerente e suas funcionalidades*/
int perfilGerente()
{
    int funcaoSelecionada;

    do
    {
        printf("\nMENU PERFIL GERENTE\n");
        printf("***********Banco do Povo***********\n");
        printf("[1] Abrir conta (0,5):\n");
        printf("[2] Atualizar dados (1.0):\n");
        printf("[3] Encerrar conta(0.5):\n");
        printf("[0] Sair(0.25):\n");

        scanf("%d", &funcaoSelecionada);

        system("clear"); /* No windows e: system("cls"); */
        switch (funcaoSelecionada)
        {
        case 1: /*  [1] Abrir conta*/

            abrirConta(); /* Chamada da Função que faz a bertura de conta*/

            break;
        case 2:                      /* [2] Atualizar dados*/
            atualizarDadosCliente(); /* Chamada da Função que faz a atualizacao dos dados do cliente*/
            break;
        case 3: /*  Chamada da Função que encerrar conta*/
            encerrarConta();
            break;
        case 0: /* Sair*/
            printf("\nAte logo...\n");
            break;
        default:
            printf("\n infome novamente!\n");
            break;
        }

    } while (funcaoSelecionada != 0);
}

/* Funcao principal*/
int main()
{
    int perfilSelecionado;

    do
    {
        system("clear"); /* No windows e: system("cls"); */
        printf("\nLogin \n");
        printf("***********Banco do Povo***********\n");
        printf("[1] Gerente:\n");
        printf("[2] Cliente:\n");
        printf("[0] Sair:\n");

        scanf("%d", &perfilSelecionado);
        system("clear"); /* No windows e: system("cls"); */
        switch (perfilSelecionado)
        {
        case 1: /* Gerente*/

            perfilGerente(); /* Chamada da funcao   perfilGerente() */

            break;
        case 2: /* Cliente*/
            printf("\nCliente\n");
            break;
        case 0: /* Sair*/
            printf("\nAte logo...\n");
            break;
        default:
            printf("\nPerfil nao encontrado, infome novamente!\n");
            break;
        }

    } while (perfilSelecionado != 0);

    return 0;
}
