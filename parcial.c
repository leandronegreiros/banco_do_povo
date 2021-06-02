#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura de clientes*/
typedef struct
{
    char nome[30];
    char cpf[14];
    int contaCorrente;
    char senha[20];
    int agencia;
    float rendaMensal;
    float saldo;
    float emprestimo;
} cliente;

typedef struct
{
    char nome[30];
    char senha[30];
} gerente;

gerente gerente1;

/* Variavel clientes*/
cliente cliente_busca[2];
cliente cliente_aux[2];
cliente cliente_delet[2];
cliente clientes[2];

int cont_cliente = 0;

/* Consultar emprestimo*/
int consultarEmprestimo(int agencia, int contaCorrente)
{
    float valorEmprestimo;
    int count = 0;

    printf("Consultar emprestimo...\n\n");

    //Mostrando emprestimo
    for (int i = 0; i < 3; i++)
    {
        if (clientes[i].agencia == agencia && clientes[i].contaCorrente == contaCorrente)
        {
            printf("Valor total do emprestimo: %.2f\n", clientes[i].emprestimo);
        }
    }
}

/* Realizar Emprestimo*/
int realizarEmprestimo(int agencia, int contaCorrente)
{
    float valorEmprestimo;
    float emprestimo;
    int count = 0;

    //Informando valor do emprestimo
    printf("Realizar emprestimo...\n\n");

    printf("Informe o valor do emprestimo: ");
    scanf("%f", &emprestimo);

    printf("emprestimo: ");

    if (emprestimo > 0)
    {
        //Regras para fazer o emprestimo
        for (int i = 0; i < 3; i++)
        {
            if (clientes[i].agencia == agencia && clientes[i].contaCorrente == contaCorrente)
            {
                if (emprestimo <= (clientes[i].saldo + (clientes[i].saldo / 2)))
                {
                    clientes[i].saldo = clientes[i].saldo + emprestimo;

                    valorEmprestimo = emprestimo + (emprestimo * 0.2);

                    clientes[i].emprestimo = valorEmprestimo;

                    printf("Numero de parcelas: 12x\n");
                    printf("Valor da parcela: %.2f\n", valorEmprestimo / 12);
                    printf("Valor solicitado do emprestimo: %.2f\n", emprestimo);
                    printf("Valor total do pagamento: %.2f\n", valorEmprestimo);
                }
                else
                {
                    printf("Credito nao liberado\n");
                }
            }
        }
    }
    else
    {
        printf("Erro, o valor e menor que 0!");
    }
}
/* Realizar Saque*/
int realizaeSaque(int agencia, int contaCorrente, float valor)
{
    float saque;
    int count = 0;
    //Informando valor para o saque
    printf("Realizar deposito...\n\n");

    printf("Informe o valor do saque: ");
    scanf("%f", &saque);

    if (saque > 0)
    {
        for (int i = 0; i < 3; i++)
        {
            //fazendo o saque debitando da conta
            if (clientes[i].agencia == agencia && clientes[i].contaCorrente == contaCorrente)
            {
                if (clientes[i].saldo >= saque)
                {
                    clientes[i].saldo = clientes[i].saldo - saque;
                    printf("Saque feito com sucesso, valor: %.2f\n", saque);
                }
                else
                {
                    printf("Erro, o valor e maior que saldo em conta\n");
                    printf("Saldo: %.2f", clientes[i].saldo);
                }
            }
        }
    }
    else
    {
        printf("Erro, o valor e menor que 0!");
    }
}
/* Realizar deposito*/
int realizarDeposito(int agencia, int contaCorrente)
{
    float deposito;

    //Informando valor 
    printf("Realizar deposito...\n\n");

    printf("Informe o valor do deposito: ");
    scanf("%f", &deposito);

    if (deposito > 0)
    {
        //fazendo deposito
        for (int i = 0; i < 3; i++)
        {
            if (clientes[i].agencia == agencia && clientes[i].contaCorrente == contaCorrente)
            {
                clientes[i].saldo = clientes[i].saldo + deposito;
                printf("Deposito feito com sucesso, valor: %.2f\n", deposito);
            }
        }
    }
    else
    {
        printf("Erro, o valor e menor que 0!");
    }
}

/* Busca dados do cliente e informa todas todos os dados*/
int consultarExtrato()
{
    int count = 0;
    //Informar o dadps do cliente para ser verificado
    printf("Buscar cliente...\n\n");

    printf("Informe a agencia do cliente: ");
    scanf("%d", &cliente_busca[0].agencia);
    printf("Informe a conta corrente do cliente: ");
    scanf("%d", &cliente_busca[0].contaCorrente);

    for (int i = 0; i < 3; i++)
    {
        if (clientes[i].agencia == cliente_busca[0].agencia && clientes[i].contaCorrente == cliente_busca[0].contaCorrente)
        {
            //Mostrando dados do cliente
            printf("\nNome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Conta corrente: %d\n", clientes[i].contaCorrente);
            printf("Senha: %s\n", clientes[i].senha);
            printf("Agencia: %d\n", clientes[i].agencia);
            printf("Renda Mensal: %.2f\n", clientes[i].rendaMensal);
            printf("Saldo: %.2f\n", clientes[i].saldo);
            printf("Emprestimo: %.2f\n", clientes[i].emprestimo);
        }
    }
}

/* Funcao que informa o perfil do cliente e suas funcionalidades*/
int perfilCliente()
{
    int funcaoSelecionada;
    char nome[30];
    char senha[30];
    int count_login = 0;
    int token = 0;

    do
    {
        if (token == 0)
        { //valida se o gerente esta logado 
            token = 1;
            printf("\n\nLogin do cliente...\n");
            printf("nome:");
            scanf("%s", &nome);

            printf("senha:");
            scanf("%s", &senha);
        }
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(nome, clientes[i].nome) == 0 && strcmp(senha, clientes[i].senha) == 0)
            {
                //Menu de funções que o gerente pode fazer
                printf("\nSeja bem-vindo, Cliente: (%s)\n", nome);

                printf("\nMENU PERFIL CLIENTE\n");
                printf("***********Banco do Povo***********\n");
                printf("[1] Consultar Extrato (0.5):\n");
                printf("[2] Realizar deposito (0.5):\n");
                printf("[3] Realizar saque (0.5):\n");
                printf("[4] Realizar Emprestimo (1.0):\n");
                printf("[5] Consultar emprestimo (0.5):\n");
                printf("[0] Sair(0.25):\n");

                scanf("%d", &funcaoSelecionada);

                switch (funcaoSelecionada)
                {
                case 1: /* Consultar Extrato*/
                    consultarExtrato();
                    break;
                case 2: /* Realizar deposito*/
                    realizarDeposito(clientes[i].agencia, clientes[i].contaCorrente);
                    break;
                case 3: /*  Realizar saque*/
                    realizaeSaque(clientes[i].agencia, clientes[i].contaCorrente, clientes[i].saldo);
                    break;
                case 4: /* Realizar Emprestimo */
                    realizarEmprestimo(clientes[i].agencia, clientes[i].contaCorrente);
                    break;
                case 5: /*  Consultar emprestimo*/
                    consultarEmprestimo(clientes[i].agencia, clientes[i].contaCorrente);
                    break;
                case 0: /* Sair*/
                    printf("\nAte logo...\n");
                    break;
                default:
                    printf("\n infome novamente!\n");
                    break;
                }
            }
            else
            {
                count_login++;
                if (count_login == 3)
                {
                    printf("Login invalido...");
                }
            }
        }
    } while (funcaoSelecionada != 0);
}

/* Funcao que faz o encerramento da conta*/
int encerrarConta()
{

    int funcaoSelecionada;
    int count = 0;
    int agencia;
    int contaCorrente;
    cliente limpar;

    printf("Encerrar conta...\n\n");
    printf("Infome a agencia do cliente: ");
    scanf("%d", &agencia);
    printf("Infome a conta corrente do cliente: ");
    scanf("%d", &contaCorrente);

    printf("Agencia: %d\n", agencia);
    printf("Conta corrente: %d\n", contaCorrente);

    for (int i = 0; i < 3; i++)
    {
        //Apagando dados do vetor
        if (clientes[i].agencia == agencia && clientes[i].contaCorrente == contaCorrente)
        {
            strcpy(clientes[i].nome, "");
            strcpy(clientes[i].cpf, "");
            strcpy(clientes[i].senha, "");
            clientes[i].contaCorrente = 0;
            clientes[i].agencia = 0;
            clientes[i].rendaMensal = 0;
            clientes[i].saldo = 0;
            clientes[i].emprestimo = 0;

            printf("\nCliente Removido!\n");
            cont_cliente--;
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
                // Dados do cliente que podem ser atualizados
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
    for (int i = 0; i < 3; i++)
    {
        if (strlen(clientes[i].nome) == 0)
        {
            cont_cliente++;
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

            printf("\nCliente cadastrado com sucesso: \n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Conta Corrente: %d\n", clientes[i].contaCorrente);
            printf("Senha: %s\n", clientes[i].senha);
            printf("Agencia: %d\n", clientes[i].agencia);
            printf("Renda Mensal: %.2f\n", clientes[i].rendaMensal);
            printf("Saldo: %.2f\n", clientes[i].saldo);
            break;
        }
        else
        {
            //valida o cadastro de clientes no maximo 3 
            if (cont_cliente >= 3)
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
    char nome[30];
    char senha[30];
    int token = 0;

    strcpy(nome, "thanos");
    strcpy(senha, "123");
    do
    {
        if (token == 0)
        { //valida se o gerente esta logado
            token = 1;
            printf("\n\nLogin do gerente...\n\n");
            printf("nome:");
            scanf("%s", &gerente1.nome);

            printf("senha:");
            scanf("%s", &gerente1.senha);
        }
        if (strcmp(nome, gerente1.nome) == 0 && strcmp(senha, gerente1.senha) == 0)
        {
            //Funcionalidades que o gerente pode fazer
            printf("\nSeja bem-vindo, GERENTE: (%s)\n", nome);

            printf("\nMENU PERFIL GERENTE\n");
            printf("***********Banco do Povo***********\n");
            printf("[1] Abrir conta (0,5):\n");
            printf("[2] Atualizar dados (1.0):\n");
            printf("[3] Encerrar conta(0.5):\n");
            printf("[0] Sair(0.25):\n");

            scanf("%d", &funcaoSelecionada);

            switch (funcaoSelecionada)
            {
            case 1: /*  [1] Abrir conta*/

                abrirConta(); /* Chamada da Função que faz a bertura de conta*/

                break;
            case 2: /* [2] Atualizar dados*/
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
        }
        else
        {
            printf("Login invalido...");
        }

    } while (funcaoSelecionada != 0);
}
/* Funcao principal*/
int main()
{
    int perfilSelecionado;

    do
    {
        // tipos de usarios do sitema
        printf("***********Banco do Povo***********\n");
        printf("[1] Gerente:\n");
        printf("[2] Cliente:\n");
        printf("[0] Sair:\n");
        scanf("%d", &perfilSelecionado);
        /* No windows e: system("cls"); */

        switch (perfilSelecionado)
        {
        case 1: /* Gerente*/
            perfilGerente(); /* Chamada das funcao do Gerente */
            break;
        case 2:
            perfilCliente(); /* Chamada da funcao  cliente */
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