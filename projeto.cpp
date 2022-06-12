#include <fstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <ctime>
#include <tuple>

using namespace std;

struct conta{ //deve ser lembrado que há no salvamento uma conta default com saldo 100, usada para facilitar a manutenção do programa
    int numero_conta;
    int numero_agencia;
    string nome_titular;
    string cpf_titular;
    float saldo;
    conta *ant, *prox;

};

struct conta_sem_ponteiros{ //essa struct existe para poder salvar os dados em um arquivo binario
    int numero_conta;
    int numero_agencia;
    char nome_titular[30];
    char cpf_titular[30];
    float saldo;

};

struct historico_arabanco{
    char lancamento[90];
    char ano[9];
    char mes[9];
    char dia[9];
    char hora[9];
    char minuto[9];
    int numero_conta;
    int numero_agencia;
    char nome_titular[30];
    char cpf_titular[30];
    float saldo;
    float valor_anterior;
    historico_arabanco* prox;
};



void inserir_item_no_historico(historico_arabanco* h, historico_arabanco* historico_novo){
    historico_arabanco* aux = h;

    while (aux->prox != NULL){

        aux = aux->prox;
    }
    aux->prox = historico_novo;
}

//mudar esses parametros
void inserir_historico_operacoes(historico_arabanco* h, string lancamento, int numero_conta, int numero_agencia, string nome_titular, string cpf_titular, float saldo, float valor_anterior, int dia, int ano, int mes,int hora, int minuto){
    mes +=1;
    ano+= 1900;

    string ano_string = to_string(ano);
    char ano_char[10];
    strcpy(ano_char, ano_string.c_str()); //fazendo a conversao de inteiro para char

    string numero_saldo_string = to_string(saldo);
    char numero_saldo_char[10];
    strcpy(numero_saldo_char, numero_saldo_string.c_str()); // saldo para char

    string numero_valor_string = to_string(valor_anterior);
    char numero_valor_char[10];
    strcpy(numero_valor_char, numero_valor_string.c_str()); //valor anterior para char

    string numero_dia_string = to_string(dia);
    char numero_dia_char[10];
    strcpy(numero_dia_char, numero_dia_string.c_str()); //dia para char

    string numero_mes_string = to_string(mes);
    char numero_mes_char[10];
    strcpy(numero_mes_char, numero_mes_string.c_str()); // mes para char

    string numero_hora_string = to_string(hora);
    char numero_hora_char[10];
    strcpy(numero_hora_char, numero_hora_string.c_str()); //hora para char

    string numero_minuto_string = to_string(minuto);
    char numero_minuto_char[10];
    strcpy(numero_minuto_char, numero_minuto_string.c_str()); // minuto para char

    char cpf_titular_char[10];
    strcpy(cpf_titular_char, cpf_titular.c_str());

    char nome_titular_char[10];
    strcpy(nome_titular_char, nome_titular.c_str());

    char lancamento_char[10];
    strcpy(lancamento_char, lancamento.c_str());

    historico_arabanco *historico_novo = new historico_arabanco;

    //converter os strings para chars para serem aceitos aqui embaixo
    historico_novo->prox = NULL;
    strcpy(historico_novo->ano, ano_char);
    strcpy(historico_novo->cpf_titular, cpf_titular_char);
    strcpy(historico_novo->dia, numero_dia_char);
    strcpy(historico_novo->hora, numero_hora_char);
    strcpy(historico_novo->lancamento, lancamento_char);
    strcpy(historico_novo->mes, numero_mes_char);
    strcpy(historico_novo->minuto, numero_minuto_char);
    strcpy(historico_novo->nome_titular, nome_titular_char);
    historico_novo->numero_agencia = numero_agencia;
    historico_novo->numero_conta = numero_conta;
    historico_novo->saldo = saldo;
    historico_novo->valor_anterior = valor_anterior;

    historico_arabanco* aux = h;

    while (aux->prox != NULL){

        aux = aux->prox;
    }

    aux->prox = historico_novo;
}
conta*& inserir_fim_conta(conta *c, int numero_conta, int numero_agencia, string nome_titular, string cpf_titular, float saldo){ //funcao que salva a conta desejada no final do vetor contas
  conta *novo = new conta;

  novo->numero_conta = numero_conta;
  novo->numero_agencia = numero_agencia;
  novo->nome_titular = nome_titular;
  novo->cpf_titular = cpf_titular;
  novo->saldo = saldo;
  novo->ant = NULL;
  novo->prox = NULL;

  if(c == NULL)
    c = novo;

  else{
    conta *aux = c;

    while(aux->prox != NULL){

        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
  }
  return c;
}

conta*& inserir_conta_no_fim_duas_contas(conta *conta_principal, conta *conta_a_ser_inserida){ //usa-se a conta base para percorrer os ponteiros e a segunda conta que é a que se deseja ser inserida
    conta *aux = conta_principal;

    while(aux->prox != NULL){

        aux = aux->prox;
    }
    aux->prox = conta_a_ser_inserida;
    conta_a_ser_inserida->ant = aux;
}

void listar_contas(conta *c){ //funcao de testes
    conta* aux = c;

    while (aux != NULL){
        cout << "Número da conta: " << aux->numero_conta << endl;
        cout << "Número da agência: " << aux->numero_agencia << endl;
        cout << "Nome do titular: " << aux->nome_titular << endl;
        cout << "CPF do titular: " << aux->cpf_titular << endl;
        cout << "Saldo do titular: " << aux->saldo << endl;
        cout << "******************************"<< endl << endl;
        aux = aux->prox;
    }
}

void cabecalho(){ //funcao do cabecalho
    cout << "********************************************" << endl;
    cout << "*      ARABANCO – SEMPRE COM VOCÊ =P       *" << endl;
    cout << "********************************************" << endl << endl << endl;
    cout << "Menu de opções:" << endl;
    cout << "1 – Cadastrar Conta Corrente" << endl;
    cout << "2 – Alterar dados de uma Conta Corrente" << endl;
    cout << "3 – Excluir uma Conta Corrente" << endl;
    cout << "4 – Consultar Saldo" << endl;
    cout << "5 - Fazer depósito" << endl;
    cout << "6 – Realizar Saque" << endl;
    cout << "7 – Transferir Valores" << endl;
    cout << "8 – Mostrar todas as contas e saldos" << endl;
    cout << "9 – Emitir extrato de conta" << endl;
    cout << "10 – Sair" <<endl;
    cout << "Escolha uma opcao: ";
    }

bool verifica_conta_agencia_existe(conta* c, int numero_conta, int numero_agencia){
    conta* aux = c;

    while (aux != NULL){

        if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia)
            return true;

        aux = aux->prox;
    }
    return false;

}

void atualiza_dados_cliente(conta* c, int numero_conta, int numero_agencia, string nome_titular, string cpf_titular){
    conta* aux = c;

    while (aux != NULL){

        if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia){
            aux->nome_titular = nome_titular;
            aux->cpf_titular = cpf_titular;
        }

        aux = aux->prox;
    }
}

void excluir_conta_corrente(conta* c, int numero_conta, int numero_agencia){
    conta* aux = c;

    while (aux != NULL){

        if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia && aux->prox == NULL){// se for o ultimo

            aux->ant->prox = NULL;
            cout << "Conta removida: " << aux->numero_conta << endl;
            delete(aux);

        }

        else if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia){ //se estiver no meio

            aux->ant->prox = aux->prox;
            cout << "Conta removida: " << aux->numero_conta << endl;
            aux->prox->ant = aux->ant;
            delete(aux);
        }
        aux = aux->prox;
    }
}

void consulta_saldo(conta *c, int numero_conta, int numero_agencia){
    conta* aux = c;

    while (aux != NULL){

        if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia){
            cout << "Numero da conta: " << aux->numero_conta << endl << "Numero da agencia: " << aux->numero_agencia << endl;
            cout << "Nome do titular: " << aux->nome_titular << endl << "CPF do titular: " << aux->cpf_titular << endl;
            cout << "Saldo: " << aux->saldo << endl;
        }

        aux = aux->prox;
    }

}

tuple<float,float> fazer_deposito(conta *c, int numero_conta, int numero_agencia, float valor){
    conta* aux = c;
    float saldo_antigo;
    float saldo_atual;

    while (aux != NULL){

        if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia){
            saldo_antigo = aux->saldo;
            aux->saldo += valor;
            saldo_atual = aux->saldo;
        }

        aux = aux->prox;
    }
    return {saldo_antigo, saldo_atual};

}
tuple<float,float> fazer_saque(conta* c, int numero_conta, int numero_agencia, float valor){
    conta* aux = c;
    float saldo_antigo;
    float saldo_atual;

    while (aux != NULL){

        if (aux->numero_conta == numero_conta && aux->numero_agencia == numero_agencia){
            saldo_antigo = aux->saldo;
            aux->saldo -= valor;
            saldo_atual = aux->saldo;
        }

        aux = aux->prox;
    }
    if (saldo_atual < 0){
        cout << "*********SAQUE NEGATIVO...SAINDO DO PROGRAMA************";
        exit(0);
    }
    return {saldo_antigo, saldo_atual};
}

tuple<float,float,float,float> fazer_transferencia(conta *c, float valor, int numero_conta_origem, int numero_agencia_origem, int numero_conta_destino, int numero_agencia_destino){
    conta* aux = c;
    float saldo_antigo_conta_origem;
    float saldo_atual_conta_origem;
    float saldo_antigo_conta_destino;
    float saldo_atual_conta_destino;

    while (aux != NULL){//subtraindo da conta de origem

        if (aux->numero_conta == numero_conta_origem && aux->numero_agencia == numero_agencia_origem){
            if (valor > aux->saldo){
                cout << "*******NÃO HÁ SALDO PARA ESSA TRANSFERENCIA******";
                exit(0);
            }
            saldo_antigo_conta_origem = aux->saldo;
            aux->saldo -= valor;
            saldo_atual_conta_origem = aux->saldo;
        }

        aux = aux->prox;
    }

    conta* aux1 = c;

    while (aux1 != NULL){ // adicionando na conta de destino

        if (aux1->numero_conta == numero_conta_destino && aux1->numero_agencia == numero_agencia_destino){
            saldo_antigo_conta_destino = aux1->saldo;
            aux1->saldo += valor;
            saldo_atual_conta_destino = aux1->saldo;
        }

        aux1 = aux1->prox;
    }


    return {saldo_antigo_conta_origem, saldo_atual_conta_origem, saldo_antigo_conta_destino, saldo_atual_conta_destino};

}

void imprime_extrato(conta* c, historico_arabanco* h, int numero_conta, int numero_agencia){
    time_t now = time(0);
    tm *tm = localtime(&now);

    conta* aux_conta = c;
    historico_arabanco* aux_arabanco = h;

    while (aux_conta != NULL){

        if (aux_conta->numero_conta == numero_conta && aux_conta->numero_agencia == numero_agencia)
            break;

        aux_conta = aux_conta->prox;
    }

    cout << "*****************************EXTRATO BANCARIO*******************************" << endl; //criacao da interface grafica do extrato
    cout << "Nome: " << aux_conta->nome_titular<< "                                                "<< "Agencia/Conta: " << aux_conta->numero_agencia << "/" << aux_conta->numero_conta << endl;
    cout << "Data: " << tm->tm_mday << "/" << tm->tm_mon+1 << "/" << tm->tm_year+1900 << "                                            " << "Horario: " << tm->tm_hour << ":" << tm->tm_min << endl << endl;
    cout << "*********************************HISTORICO**********************************" << endl;
    cout << "Data                  " << "Hora " << "  Lancamento              " << "Valor (R$)  " << "Saldo (R$)" << endl <<endl;

     while (aux_arabanco != NULL){
        if (aux_arabanco->numero_conta == numero_conta && aux_arabanco->numero_agencia == numero_agencia){
            string s(aux_arabanco->lancamento);

            if (s == "Saldo inicial")
                cout << aux_arabanco->dia << "/" << aux_arabanco->mes << "/" << aux_arabanco->ano << "             " << aux_arabanco->hora << ":" << aux_arabanco->minuto << "   " << aux_arabanco->lancamento << "                " << aux_arabanco->saldo<< "         " << aux_arabanco->valor_anterior <<endl;
            if (s == "Transferencia enviada")
                cout << aux_arabanco->dia << "/" << aux_arabanco->mes << "/" << aux_arabanco->ano << "             " << aux_arabanco->hora << ":" << aux_arabanco->minuto << "   " << aux_arabanco->lancamento << "        " << aux_arabanco->saldo<< "         " << aux_arabanco->valor_anterior <<endl;
            if (s == "Deposito")
                cout << aux_arabanco->dia << "/" << aux_arabanco->mes << "/" << aux_arabanco->ano << "             " << aux_arabanco->hora << ":" << aux_arabanco->minuto << "   " << aux_arabanco->lancamento << "                     " << aux_arabanco->saldo<< "        " << aux_arabanco->valor_anterior <<endl;
            if (s == "Saque")
                cout << aux_arabanco->dia << "/" << aux_arabanco->mes << "/" << aux_arabanco->ano << "             " << aux_arabanco->hora << ":" << aux_arabanco->minuto << "   " << aux_arabanco->lancamento << "                        " << aux_arabanco->saldo<< "         " << aux_arabanco->valor_anterior <<endl;
            if (s == "Transferencia recebida")
                cout << aux_arabanco->dia << "/" << aux_arabanco->mes << "/" << aux_arabanco->ano << "             " << aux_arabanco->hora << ":" << aux_arabanco->minuto << "   " << aux_arabanco->lancamento << "       " << aux_arabanco->saldo<< "         " << aux_arabanco->valor_anterior <<endl;
        }

        aux_arabanco = aux_arabanco->prox;
    }
}

string retorna_extrato_em_html(conta* c, historico_arabanco* h, int numero_conta, int numero_agencia){//criando a string para salvar em um arquivo
    time_t now = time(0);
    tm *tm = localtime(&now);

    conta* aux_conta = c;
    historico_arabanco* aux_arabanco = h;

    while (aux_conta != NULL){

        if (aux_conta->numero_conta == numero_conta && aux_conta->numero_agencia == numero_agencia)
            break;

        aux_conta = aux_conta->prox;
    }

    string nome_titular_string(aux_conta->nome_titular);
    string numero_agencia_string = to_string(aux_conta->numero_agencia);
    string numero_conta_string = to_string(aux_conta->numero_conta); // tem que ser feita a conversão de tudo para string ,para haver a concatenacao no arquivo html
    string dia = to_string(tm->tm_mday);
    string mes = to_string(tm->tm_mon+1);
    string ano = to_string(tm->tm_year+1900);
    string hora = to_string(tm->tm_hour);
    string minuto = to_string(tm->tm_min);
    string espaco("<div>");
    string final = "";
    final += "*************EXTRATO BANCARIO***************" + espaco;
    final += espaco + "Nome: " + nome_titular_string + "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp"+ "Agencia/Conta: " + numero_agencia_string + "/" + numero_conta_string + espaco;
    final += "Data: " + dia + "/" + mes + "/" + ano + "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp" + "Horario: " + hora + ":" + minuto + espaco + espaco;
    final += "****************HISTORICO*********************" + espaco;
    final += "Data&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspHora&nbsp&nbsp&nbsp&nbsp&nbspLancamento&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspValor&nbsp(R$)&nbspSaldo (R$)"+espaco+espaco;

    while (aux_arabanco != NULL){
        if (aux_arabanco->numero_conta == numero_conta && aux_arabanco->numero_agencia == numero_agencia){
            string s(aux_arabanco->lancamento);
            string dia(aux_arabanco->dia);
            string mes(aux_arabanco->mes);
            string ano(aux_arabanco->ano);
            string hora(aux_arabanco->hora);
            string minuto(aux_arabanco->minuto);
            string lancamento(aux_arabanco->lancamento);
            string saldo = to_string(aux_arabanco->saldo);
            string valor_anterior = to_string(aux_arabanco->valor_anterior);

            if (s == "Saldo inicial")
                final += dia + "/" + mes + "/" + ano + "             " + hora + ":" + minuto + "&nbsp&nbsp&nbsp&nbsp" + lancamento + "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp" + saldo + "&nbsp&nbsp&nbsp" + valor_anterior + espaco;
            if (s == "Transferencia enviada")
                final += dia + "/" + mes+ "/" + ano + "             " + hora + ":" + minuto + "&nbsp&nbsp&nbsp&nbsp" + lancamento + "&nbsp&nbsp&nbsp&nbsp&nbsp" + saldo + " &nbsp&nbsp&nbsp" + valor_anterior + espaco;
            if (s == "Deposito")
                final += dia + "/" + mes + "/" + ano + "             " + hora + ":" + minuto + "&nbsp&nbsp&nbsp&nbsp" + lancamento +"&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp" + saldo + " &nbsp&nbsp&nbsp" + valor_anterior + espaco;
            if (s == "Saque")
                final += dia + "/" + mes + "/" + ano + "             " + hora + ":" + minuto + "&nbsp&nbsp&nbsp&nbsp" + lancamento + "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp" + saldo + "&nbsp&nbsp&nbsp" + valor_anterior + espaco;
            if (s == "Transferencia recebida")
                final += dia + "/" + mes + "/" + ano + "             " + hora + ":" + minuto + "&nbsp&nbsp&nbsp&nbsp" + lancamento + "&nbsp&nbsp&nbsp&nbsp&nbsp"+ saldo + " &nbsp&nbsp&nbsp" + valor_anterior + espaco;
        }

        aux_arabanco = aux_arabanco->prox;
    }
    return final;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    conta c; //instanciacao das contas
    conta_sem_ponteiros csp;
    historico_arabanco h;

    FILE *f1 = fopen("contas.bin", "ab"); //abertura do arquivo para leitura dos dados, se não há arquivo, um é criado
    fclose(f1);

    FILE *f2 = fopen("historico.bin", "ab"); //abertura do arquivo para leitura dos dados, se não há arquivo, um é criado
    fclose(f2);

    FILE *f = fopen("contas.bin", "rb");

    FILE *f3 = fopen("historico.bin","rb");

    if (!f){
        cout << "Erro ao tentar ler!"; // checa algum erro na leitura
    }

    conta* conta_geral = new conta; //conta default
    conta_geral->saldo = 100;
    conta_geral->prox = NULL;
    conta_geral->ant = NULL;
    historico_arabanco* historico_default = new historico_arabanco;
    historico_default->prox = NULL;
    historico_default->saldo = 100;

    fseek(f, 0, SEEK_END); //posiciona o ponteiro do arquivo no fim

    int esta_vazio = ftell(f) - 1; // se estiver vazio esse valor será <= 0

    fseek(f,0,SEEK_SET);

    while(fread(&csp, sizeof(conta), 1,f)==1 && esta_vazio > 0){ //carregando os dados no sistema do arquivo clientes.bin

        conta* conta_nova = new conta;
        conta_nova->ant = NULL;
        conta_nova->prox = NULL;
        conta_nova->nome_titular = string(csp.nome_titular);
        conta_nova->cpf_titular = string(csp.cpf_titular);
        conta_nova->numero_agencia = csp.numero_agencia;
        conta_nova->numero_conta = csp.numero_conta;
        conta_nova->saldo = csp.saldo;


        inserir_conta_no_fim_duas_contas(conta_geral, conta_nova);

    }

    fclose(f);

    if (!f3){ //carregando o historico arabanco
        cout << "Erro ao tentar ler o historico*********";
    }else{

        fseek(f3, 0, SEEK_END); //posiciona o ponteiro do arquivo no fim

        int esta_vazio = ftell(f3) - 1; // se estiver vazio esse valor será <= 0

        fseek(f3,0,SEEK_SET);

        while(fread(&h, sizeof(historico_arabanco), 1,f3)==1 && esta_vazio > 0){
            historico_arabanco *historico_gravando = new historico_arabanco;

            historico_gravando->prox = NULL;
            strcpy(historico_gravando->ano, h.ano);
            strcpy(historico_gravando->cpf_titular,h.cpf_titular);
            strcpy(historico_gravando->nome_titular, h.nome_titular);
            strcpy(historico_gravando->dia,h.dia);
            strcpy(historico_gravando->hora, h.hora);
            strcpy(historico_gravando->lancamento, h.lancamento);
            strcpy(historico_gravando->mes, h.mes);
            strcpy(historico_gravando->minuto, h.minuto);
            historico_gravando->numero_agencia = h.numero_agencia;
            historico_gravando->numero_conta = h.numero_conta;
            historico_gravando->saldo = h.saldo;
            historico_gravando->valor_anterior = h.valor_anterior;

            inserir_item_no_historico(historico_default, historico_gravando);

        }

    }

    fclose(f3);

    cabecalho();

    int opcao;
    cin >> opcao;

    if (opcao == 10){
        exit(1);
    }
    time_t now = time(0);

    tm *tm = localtime(&now);

    while (opcao != 10){

        if (opcao == 1){
            cout << "******MENU DE CADASTRO DE CONTAS*******"<< endl;
            int numero_conta;
            int numero_agencia;
            string nome_titular;
            string cpf_titular;
            float saldo_inicial;

            cout << "Informe o numero da conta: ";
            cin >> numero_conta;
            cout << "Informe o numero da agencia: ";
            cin >> numero_agencia;
            cout << "Informe o nome do titular: ";
            cin >> nome_titular;
            cout << "Informe o CPF do titular: ";
            cin >> cpf_titular;
            cout << "Informe o saldo inicial da conta: ";

            do{ //verificacao de saldo negativo
                cin >> saldo_inicial;
                if (saldo_inicial < 0)
                    cout << "Saldo negativo!" << endl;
                    cout << "Informe o saldo inicial da conta: " << endl;
            }while(saldo_inicial < 0);

            inserir_fim_conta(conta_geral, numero_conta, numero_agencia, nome_titular, cpf_titular, saldo_inicial);
            cout << "******CONTA CADASTRADA COM SUCESSO!*******" << endl;

            inserir_historico_operacoes(historico_default,"Saldo inicial",numero_conta,numero_agencia,nome_titular,cpf_titular,saldo_inicial,saldo_inicial,tm->tm_mday,tm->tm_year,tm->tm_mon,tm->tm_hour,tm->tm_min);

            }

        else if (opcao == 2){
            cout << "******MENU DE ATUALIZACAO DE CONTAS*******"<< endl;
            int numero_conta;
            int numero_agencia;

            cout << "Informe o numero da conta: ";
            cin >> numero_conta;
            cout << "Informe o numero da agencia: ";
            cin >> numero_agencia;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta, numero_agencia) == true){
                cout << "Informe os novos dados!" << endl;
                string nome_novo;
                string cpf_novo;

                cout << "Nome do titular: ";
                cin >> nome_novo;
                cout << "CPF titular: ";
                cin >> cpf_novo;

                atualiza_dados_cliente(conta_geral, numero_conta,numero_agencia,nome_novo,cpf_novo);
                cout << "******CONTA ATUALIZADA COM SUCESSO!*******" << endl;
            }else{
                cout << "A conta não existe no sistema!" << endl;
            }


        }

        else if (opcao == 3){
            cout << "******MENU DE EXCLUSÃO DE CONTAS*******"<< endl;
            int numero_conta;
            int numero_agencia;

            cout << "Informe o numero da conta: ";
            cin >> numero_conta;
            cout << "Informe o numero da agencia: ";
            cin >> numero_agencia;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta, numero_agencia) == true){
                excluir_conta_corrente(conta_geral,numero_conta,numero_agencia);
                cout << "******CONTA EXCLUÍDA COM SUCESSO!*******" << endl;

            }else{
                cout << "A conta não existe no sistema!" << endl;
            }

        }

        else if (opcao == 4){
            cout << "******MENU DE CONSULTA DE SALDO DE CONTAS*******"<< endl;
            int numero_conta;
            int numero_agencia;

            cout << "Informe o numero da conta: ";
            cin >> numero_conta;
            cout << "Informe o numero da agencia: ";
            cin >> numero_agencia;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta, numero_agencia) == true){
                consulta_saldo(conta_geral, numero_conta, numero_agencia);

            }else{
                cout << "A conta não existe no sistema!" << endl;
            }
        }

        else if (opcao == 5){
            float valor;
            tuple<float,float> valor_antigo;

            cout << "******MENU DE DEPOSITO DE VALORES EM CONTAS*******"<< endl;
            int numero_conta;
            int numero_agencia;

            cout << "Informe o numero da conta: ";
            cin >> numero_conta;
            cout << "Informe o numero da agencia: ";
            cin >> numero_agencia;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta, numero_agencia) == true){
                consulta_saldo(conta_geral, numero_conta, numero_agencia);

                cout << "Digite o valor do depósito: ";
                cin >> valor;
                if (valor > 0){
                    valor_antigo = fazer_deposito(conta_geral, numero_conta, numero_agencia, valor);
                    inserir_historico_operacoes(historico_default,"Deposito",numero_conta,numero_agencia,"DEFAULT","DEFAULT",valor,get<1>(valor_antigo),tm->tm_mday,tm->tm_year,tm->tm_mon,tm->tm_hour,tm->tm_min);
                }
                else
                    cout << "Valor negativo, voltando ao menu!" << endl;

            }else{
                cout << "A conta não existe no sistema!" << endl;
            }


        }

        else if (opcao == 6){
            cout << "******MENU DE SAQUE EM CONTAS*******"<< endl;
            int numero_conta;
            int numero_agencia;
            tuple<float,float> valor_antigo;

            cout << "Informe o numero da conta: ";
            cin >> numero_conta;
            cout << "Informe o numero da agencia: ";
            cin >> numero_agencia;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta, numero_agencia) == true){
                consulta_saldo(conta_geral, numero_conta, numero_agencia);
                float valor;
                cout << "Digite o valor do saque: ";
                cin >> valor;
                if (valor > 0){
                    valor_antigo = fazer_saque(conta_geral, numero_conta, numero_agencia,valor);
                    cout << get<1>(valor_antigo) << endl;
                    inserir_historico_operacoes(historico_default,"Saque",numero_conta,numero_agencia,"DEFAULT","DEFAULT",valor,get<1>(valor_antigo),tm->tm_mday,tm->tm_year,tm->tm_mon,tm->tm_hour,tm->tm_min);
                }
                else
                    cout << "Valor negativo, voltando ao menu!" << endl;

            }else{
                cout << "A conta não existe no sistema!" << endl;
            }

        }

        else if (opcao == 7){
            cout << "******MENU DE TRANSFERENCIA DE VALORES ENTRE CONTAS*******"<< endl;
            int numero_conta_origem;
            int numero_agencia_origem;
            int numero_conta_destino;
            int numero_agencia_destino;
            tuple<float,float,float,float> valor_antigo;

            cout << "Informe o numero da conta de origem: ";
            cin >> numero_conta_origem;
            cout << "Informe o numero da agencia de origem: ";
            cin >> numero_agencia_origem;
            cout << "Informe o numero da conta de destino: ";
            cin >> numero_conta_destino;
            cout << "Informe o numero da agencia de destino: ";
            cin >> numero_agencia_destino;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta_origem, numero_agencia_origem) == true && verifica_conta_agencia_existe(conta_geral, numero_conta_destino, numero_agencia_destino)==true){

                cout << "Dados da conta de origem: ************" << endl;
                consulta_saldo(conta_geral, numero_conta_origem, numero_agencia_origem);
                cout << "Dados da conta de destino: *************" << endl;
                consulta_saldo(conta_geral, numero_conta_destino, numero_agencia_destino);


                float valor;
                cout << "Digite o valor da transferência: ";
                cin >> valor;
                if (valor > 0){
                    valor_antigo = fazer_transferencia(conta_geral,valor,numero_conta_origem,numero_agencia_origem,numero_conta_destino,numero_agencia_destino);
                    inserir_historico_operacoes(historico_default,"Transferencia enviada",numero_conta_origem,numero_agencia_origem,"DEFAULT","DEFAULT",valor,get<1>(valor_antigo),tm->tm_mday,tm->tm_year,tm->tm_mon,tm->tm_hour,tm->tm_min);
                    inserir_historico_operacoes(historico_default,"Transferencia recebida",numero_conta_destino,numero_agencia_destino,"DEFAULT","DEFAULT",valor,get<3>(valor_antigo),tm->tm_mday,tm->tm_year,tm->tm_mon,tm->tm_hour,tm->tm_min);
                    cout << "******VALORES TRANSFERIDOS COM SUCESSO!*******" << endl;
                }
                else
                    cout << "Valor negativo, voltando ao menu!" << endl;

            }else{
                cout << "A conta não existe no sistema!" << endl;
            }

        }

        else if (opcao == 8){
            if (conta_geral->prox == NULL){
                cout << "Não há contas cadastradas**********" << endl;
            }else{
                cout << endl << "******************************" << endl;
                listar_contas(conta_geral->prox); //lista todas as contas cadastradas
            }
        }

        else if (opcao == 9){
            string opcao;
            int numero_conta;
            int numero_agencia;
            cout << "Extrato em tela ou em arquivo? t/a:";
            cin >> opcao;
            cout << "Numero da conta: ";
            cin >> numero_conta;
            cout << "Numero da agencia: ";
            cin >> numero_agencia;

            if (verifica_conta_agencia_existe(conta_geral, numero_conta, numero_agencia)){
                if (opcao == "t"){
                    imprime_extrato(conta_geral, historico_default, numero_conta, numero_agencia); //imprimindo extrato em tela
                }else{
                    remove("extrato.html");
                    ofstream out("extrato.html");
                    out << retorna_extrato_em_html(conta_geral, historico_default, numero_conta, numero_agencia); //salvando extrato em html
                    out.close();
                }
            }else{
                cout << "Conta inexistente!" << endl;
            }

        }

        remove("contas.bin"); //remove o arquivo para poder escrever sem repeticoes
        FILE *f1 = fopen("contas.bin", "ab"); //abertura do arquivo para gravacao

        remove("historico.bin");
        FILE *f3 = fopen("historico.bin", "ab");

        historico_arabanco* aux_arabanco = historico_default->prox;
        conta* aux = conta_geral->prox; //o primeiro elemento é um elemento neutro, portanto, será gravado apenas o que esta depois dele

        while (aux != NULL){

            string nome = aux->nome_titular;
            strcpy(csp.nome_titular,nome.c_str()); //fazendo a copia de uma string para um char

            string cpf = aux->cpf_titular;
            strcpy(csp.cpf_titular, cpf.c_str());//fazendo a copia de uma string para um char

            csp.numero_agencia = aux->numero_agencia;
            csp.numero_conta = aux->numero_conta;
            csp.saldo = aux->saldo;

            fwrite(&csp, sizeof(conta), 1,f1); //escrevendo

            aux = aux->prox;

            }

        while (aux_arabanco != NULL){

            strcpy(h.ano,aux_arabanco->ano);
            strcpy(h.cpf_titular,aux_arabanco->cpf_titular); //setando os atributos de h para gravação
            strcpy(h.dia,aux_arabanco->dia);
            strcpy(h.hora, aux_arabanco->hora);
            strcpy(h.lancamento, aux_arabanco->lancamento);
            strcpy(h.mes, aux_arabanco->mes);
            strcpy(h.minuto, aux_arabanco->minuto);
            strcpy(h.nome_titular, aux_arabanco->nome_titular);
            h.numero_agencia = aux_arabanco->numero_agencia;
            h.numero_conta = aux_arabanco->numero_conta;
            h.saldo = aux_arabanco->saldo;
            h.valor_anterior = aux_arabanco->valor_anterior;

            fwrite(&h, sizeof(historico_arabanco), 1, f3);

            aux_arabanco = aux_arabanco->prox;
        }

        fclose(f);
        fclose(f3);

        cabecalho();

        cin >> opcao;

        if (opcao == 10){
                exit(1);
            }

    }


}

