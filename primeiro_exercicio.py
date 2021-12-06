def valor_combustivel(): ##questao1
    valor_litro = float(input("Qual o valor do litro do combustível?"))
    valor_dinheiro = float(input("Qual o valor que desejas colocar?"))
    litros = valor_dinheiro / valor_litro
    print(litros)

def media_consumo():
    valor_inicial = float(input("Qual o valor do KM inicial?"))
    valor_final = float(input("Qual o valor do KM final?"))
    litros_gastos =  float(input("Quantos litros foram gastos?"))
    consumo = str((valor_final - valor_inicial) / litros_gastos)
    print("O carro faz " + consumo + " km com um litro")

def valor_divida():
    valor_original = float(input("Valor original da dívida: "))
    qtd_dias_atraso = int(input("Dias atraso: "))
    valor_multa_dia = float(input("Qual o valor da multa por dia de atraso? "))
    valor_a_ser_pago = str((valor_multa_dia * qtd_dias_atraso) + valor_original)
    print("Sua dívida total é de: " + valor_a_ser_pago + " reais")

def area_total_casa():
    largura_comodo_1 = float(input("Largura do primeiro cômodo: "))
    comprimento_comodo_1 = float(input("Comprimento do primeiro cômodo: "))
    largura_comodo_2 = float(input("Largura do segundo cômodo: "))
    comprimento_comodo_2 = float(input("Comprimento do segundo cômodo: "))
    largura_comodo_3 = float(input("Largura do terceiro cômodo: "))
    comprimento_comodo_3 = float(input("Comprimento do terceiro cômodo: "))
    largura_comodo_4 = float(input("Largura do quarto cômodo: "))
    comprimento_comodo_4 = float(input("Comprimento do quarto cômodo: "))

    area_total = str((largura_comodo_1 * comprimento_comodo_1) + (largura_comodo_2 * comprimento_comodo_2) + (largura_comodo_3 * comprimento_comodo_3) + (largura_comodo_4*comprimento_comodo_4))
    print("Área total: " + area_total + " m2")

def conversao():
    cotacao_dolar = float(input("DIGITE A COTACAO ATUAL DO DOLAR: "))
    quantos_reais_deseja_converter = float(input("QUANTOS REAIS DESEJA CONVERTER? "))
    valor_total = str(quantos_reais_deseja_converter / cotacao_dolar)
    print("O valor convertido e: " + valor_total + " dolares")

def novo_salario():
    salario_atual = float(input("Qual o salário atual: "))
    percentual_reajuste = float(input("Percentual reajuste: "))
    salario_total = str(salario_atual + ((percentual_reajuste/100) * salario_atual))
    print("Seu salário agora é: " + salario_total + " reais")

def ficar_rico():
    salario_mensal = float(input("DIGITE O SALARIO MENSAL: "))
    despesas = float(input("DIGITE AS DESPESAS MENSAIS: "))
    valor_a_calcular = salario_mensal - despesas
    qtd_anos = str((1000000 / valor_a_calcular)//12)
    print("A QUANTIDADE DE ANOS PARA A BUFUNFA RENDER UM MILHAO E: " + qtd_anos + " anos")

def ler_valor_inteiro():
    valor = int(input("DIGITE O INTEIRO AI: "))
    print(str(valor-2) + " " + str(valor-1) + " " + str(valor) + " " + str(valor+1)+ " " + str(valor+2))

def idade():
    nome = str(input("Digite seu nome: "))
    ano_nascimento = int(input("Digite o ano de nascimento: "))
    fez_aniversario = str(input("Ja fez aniversario? s/n "))
    if fez_aniversario == "s":
        print(nome + " tem " + str(2021 - ano_nascimento) + " anos")
    else:
        print(nome + " tem " + str((2021 - ano_nascimento) - 1) + " anos")

def ultima():
    largura_sala = float(input("Largura da sala: "))
    comprimento_sala = float(input("Comprimento da sala: "))
    largura_cadeira = float(input("Largura da cadeira: "))
    comprimento_cadeira = float(input("Comprimento da cadeira: "))
    largura_real = largura_sala - (largura_sala * 0.5)
    comprimento_real = (comprimento_sala - (comprimento_sala * 0.2)) - 1.5
    area_final = largura_real * comprimento_real
    area_final_carteira = largura_cadeira * comprimento_cadeira
    qtd_cadeiras = area_final // area_final_carteira
    print("A QUANTIDADE DE CADEIRAS SUPORTADA É: " + str(qtd_cadeiras) + " DE CADEIRAS")

ficar_rico()
