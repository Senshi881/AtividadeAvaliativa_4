/*
Instruções
Para o controle dos veículos que circulam em uma determinada cidade, a Secretaria dos Transportes criou o seguinte registro padrão:

 Proprietário:__________________________ Combustível:____________________

 Modelo: _____________________________ Cor: __________________________

Nº chassi: _________________________ Ano: __________ Placa: ____________

Em que:

• Combustível pode ser álcool, diesel ou gasolina;
• Placa possui os três primeiros valores alfabéticos e os quatro restantes valores numéricos.

Sabendo que não temos uma definição do número máximo de veículos da cidade e que é preciso armazenar todos os valores em uma lista encadeada simples, construa:

a. Uma função que liste todos os proprietários cujos carros são do ano de 2010 ou posterior e que sejam movidos a diesel. (1,0 ponto)
b. Uma função que liste todas as placas que comecem com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietários. (1,0 ponto)
c. Uma função que liste o modelo e a cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par. (1,0 ponto)
d. Uma função que permita a troca de proprietário com o fornecimento do número do chassi apenas para carros com placas que não possuam nenhum dígito igual a zero. (1,0 ponto)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Veiculo {
    char proprietario[100], combustivel[10], modelo[65], cor[20], placa[8];
    int chassiN, ano;
    struct Veiculo* proximo;
} Veiculo;

void registrar(Veiculo* veiculos, int* i) {
    (*i)++;
}

typedef struct ListarVeiculos{
    struct Veiculo* primeiro;
} ListarVeiculos;

void registro(Veiculo* veiculos, int *i){
    char combustivelStr1[] = "alcool";
    char combustivelStr2[] = "diesel";
    char combustivelStr3[] = "gasolina";

    printf("\nVamos registrar o veiculo %d;\nInforme o nome do proprietario completo: ", *i);
    fgets(veiculos->proprietario, sizeof(veiculos->proprietario), stdin);
    veiculos->proprietario[strcspn(veiculos->proprietario, "\n")] = '\0';
    fflush(stdin);
    printf("\nInforme o combustivel do veiculo: ");
    fgets(veiculos->combustivel, sizeof(veiculos->combustivel), stdin);
    veiculos->combustivel[strcspn(veiculos->combustivel, "\n")] = '\0';
    fflush(stdin);
    converterParaMinusculas(veiculos->combustivel);
    printf("\nInforme o modelo do veiculo: ");
    fgets(veiculos->modelo, sizeof(veiculos->modelo), stdin);
    veiculos->modelo[strcspn(veiculos->modelo, "\n")] = '\0';
    fflush(stdin);
    printf("\nInforme a cor do veiculo: ");
    fgets(veiculos->cor, sizeof(veiculos->cor), stdin);
    veiculos->cor[strcspn(veiculos->cor, "\n")] = '\0';
    fflush(stdin);
    printf("\nInforme o numero do chassi do veiculo: ");
    scanf("%d", &veiculos->chassiN);
    while(getchar() != '\n');
    printf("\nInforme o ano do veiculo: ");
    scanf("%d", &veiculos->ano);
    while(getchar() != '\n');
    printf("\nInforme a placa do veiculo: ");
    fgets(veiculos->placa, sizeof(veiculos->placa), stdin);
    veiculos->placa[strcspn(veiculos->placa, "\n")] = '\0';
    fflush(stdin);
    if(verificaPlaca(veiculos->placa)){
        printf("\nPlaca valida;");
    }else{
        printf("\nPlaca invalida;");
        strcpy(veiculos->placa, "Nao informado");
        printf("\nOs dados da placa foi substituido para nao informado;");
    }
    if(strcasecmp(veiculos->combustivel, combustivelStr1) == 0 || strcasecmp(veiculos->combustivel, combustivelStr2) == 0 || strcasecmp(veiculos->combustivel, combustivelStr3) == 0){
        printf("\nCombustivel valido;");
    }else{
        printf("\nCombustivel invalido;");
        strcpy(veiculos->combustivel, "Nao informado");
        printf("\nOs dados do combustivel foi substituido para nao informado;");
    }
    (*i)++;
}

void converterParaMinusculas(char *string){
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}
void converterParaMaiusculas(char *string){
    for (int i = 0; string[i]; i++){
        string[i] = toupper(string[i]);
    }
}

int verificaPlaca(const char *placa){
    if (strlen(placa) != 7) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (!isalpha((unsigned char)placa[i])) {
            return 0;
        }
    }
    for (int i = 3; i < 7; i++) {
        if (!isdigit((unsigned char)placa[i])) {
            return 0;
        }
    }
    converterParaMaiusculas(placa);

    return 1;
}

void listaAnoCombustivel(Veiculo* veiculos, int i) {
    int encontrado = 1;
    char combustivelStr2[] = "diesel";
    for (int r = 0; r < i; r++){
        if(veiculos[r].ano > 2009 && strcasecmp(veiculos[r].combustivel, combustivelStr2) == 0){
            printf("\nO proprietario %s possui o veiculo com: \nAno: %d; \nCombustivel: %s;", veiculos[r].proprietario, veiculos[r].ano, veiculos[r].combustivel);
        }else if(r == i - 1 && encontrado == 1){
            printf("\nNao encontrado;");
        }
    }

//2010+ diesel
}

void listaPlacasEspecificas(Veiculo* veiculos, int i) {
    int posicao1 = 1, posicao7 = 7, numerosEspecificos[] = {0, 2, 4, 7}, encontrado = 1;
    char letraEspecifica = 'J';

    for (int r = 0; r < i; r++) {
        if (veiculos[r].placa[posicao1] == letraEspecifica) {
            for (int k = 0; k < sizeof(numerosEspecificos) / sizeof(numerosEspecificos[0]); k++) {
                if (veiculos[r].placa[posicao7] == numerosEspecificos[k]) {
                    printf("\nO proprietario %s possui a placa %s;", veiculos[r].proprietario, veiculos[r].placa);
                    encontrado = 0;
                    break;
                }
            }
        }
    }

    if (encontrado) {
        printf("\nNenhum veiculo de placa especifica encontrado;");
    }
//placas que comecem com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietários
}

void listaVogalSoma(Veiculo* veiculos, int i){
    int posicao2 = 2, soma = 0, encontrado = 1;
    char vogalEspecificaA = 'A', vogalEspecificaE = 'E', vogalEspecificaI = 'I', vogalEspecificaO = 'O', vogalEspecificaU = 'U';
    for (int r = 0; r < i; r++) {
    if (veiculos[r].placa[posicao2] == vogalEspecificaA || veiculos[r].placa[posicao2] == vogalEspecificaE || veiculos[r].placa[posicao2] == vogalEspecificaI || veiculos[r].placa[posicao2] == vogalEspecificaO || veiculos[r].placa[posicao2] == vogalEspecificaU) {
        for (int j = 0; veiculos[r].placa[j] != '\0'; j++) {
            if (isdigit(veiculos[r].placa[j])) {
                soma += veiculos[r].placa[j] - '0';
                if (soma % 2 == 0) {
                    printf("\nO proprietario %s possui um veiculo com: \nModelo: %s;\nCor: %s;\nPlaca: %s;", veiculos[r].proprietario, veiculos[r].modelo, veiculos[r].cor, veiculos[r].placa);
                    encontrado = 0;
                }
            }
        }
    }
}

// Adicione uma verificação após o loop interno para imprimir a mensagem de não encontrado
if (encontrado) {
    printf("\nNenhum veiculo de placa especificada encontrado;");
}

//placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par
}

void trocaProprietario(Veiculo* veiculos, int i){
    int chassiNumero, temZero = 0, confirmacao = 1, tentativas = 0;
    printf("\nInsira o numero do chassi: ");
    scanf("%d", &chassiNumero);
    while (getchar() != '\n');
    for (int r = 0; r < i; r++) {
        tentativas++;
        if(veiculos[r].chassiN == chassiNumero){
            for(int j = 0; veiculos[r].placa[j] != '\0'; j++){
                if(veiculos[r].placa[j] >= '0' && veiculos[r].placa[j] <= '9' && veiculos[r].placa[j] == '0'){
                    temZero = 1;
                    break;
                }
            }
            if(temZero == 1){
                printf("\nA placa do chassi informado possui zero, logo nao sera possivel trocar de proprietario;");
            } else{
                printf("\nInformacao sobre o veiculo do Chassi %d: \nProprietario: %s;\nCombustivel: %s;\nModelo: %s;\nCor: %s;\nAno: %d;\nPlaca: %s;\nTem certeza que trocara de proprietario?\n0 - SIM;\n1 - NAO;\n", chassiNumero, veiculos[r].proprietario, veiculos[r].combustivel, veiculos[r].modelo, veiculos[r].cor, veiculos[r].ano, veiculos[r].placa);
                scanf("%d", &confirmacao);
                while(getchar() != '\n');

                if(confirmacao == 0){
                    printf("\nQual e o nome do novo proprietario? ");
                    fgets(veiculos[r].proprietario, sizeof(veiculos[r].proprietario), stdin);
                    veiculos[r].proprietario[strcspn(veiculos[r].proprietario, "\n")] = '\0';
                    fflush(stdin);
                }
            }
            break;
        }
    }

//placa nao pode ter 0
}

int main(){
    Veiculo* veiculos = NULL;
    int totalVeiculos = 0, reset = 0, escolha;

    do{
        printf("\nO que deseja?\n1 - Registrar veiculo;\n2 - Listar veiculos de 2010+ a diesel;\n3 - Listar placas que comecem com a letra J e terminem com 0, 2, 4 ou 7;\n4 - Listar placas que possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par;\n5 - Trocar de proprietario a partir do chassi;\n");
        scanf("%d", &escolha);
        while(getchar() != '\n');
        switch(escolha){
            case 1:
            veiculos = (Veiculo*)realloc(veiculos, (totalVeiculos + 1) * sizeof(Veiculo));
                if(veiculos == NULL){
                    printf("\nErro na alocação de memória;\n");
                    return 1;
                }
                registro(&veiculos[totalVeiculos], &totalVeiculos);
            break;
            case 2:
            listaAnoCombustivel(veiculos, totalVeiculos);
            break;
            case 3:
            listaPlacasEspecificas(veiculos, totalVeiculos);
            break;
            case 4:
            listaVogalSoma(veiculos, totalVeiculos);
            break;
            case 5:
            trocaProprietario(veiculos, totalVeiculos);
            break;
            default:
            printf("\nResposta invalida;");
            break;
        }
        printf("\nDeseja realizar mais alguma acao? \n0 - SIM;\n1 - NAO;\n");
        scanf("%d", &reset);
        while(getchar() != '\n');
    }while(reset != 1);

    free(veiculos);

    return 0;
}