// =============== CONVERSOR DE BASES ================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//=============== FUNÇÕES ================

// "Dicionario" de conversão até base 32
const string caractere = "0123456789ABCDEFGHIJKLMNOPQRSTUV";

// Converte char para número  |  ex: A -> retorna sua posição(10), logo A = 10
int charToValue(char c) {
    return caractere.find(c);
}

// Converte número para caractere  |  ex: posição 10 -> contém o caractere A, logo 10 = A
char valueToChar(int v) {
    return caractere[v];
}

// Remove zeros à esquerda 
/*
    A função trim serve para remover zeros à esquerda de um número em forma de texto.
    Enquanto a variavel s for diferente de 0 ela continua apagando o primeiro caractere da string.
*/
string trim(string s) {
    while (s.size() > 1 && s[0] == '0')
        s.erase(0, 1);
    return s;
}



// divide string decimal por base, retorna resto'
/*
    Essa função simula uma divisão manual de números grandes, lendo o numero como uma string.
    Ele usa uma variável chamada carry, que funciona como um acumulador.
    Ela vai juntando os dígitos aos poucos, como se fosse uma conta feita no papel.
    O programa percorre cada dígito do número da esquerda para a direita.
    Em cada passo, ele pega o valor atual, junta com o anterior e monta um número parcial.
    No final, a função retorna duas coisas: o resultado da divisão como string, e o resto da divisão.
*/
string divide(string num, int base, int &resto) {
    string result = "";
    long long carry = 0;

    for (char c : num) {
        carry = carry * 10 + (c - '0');
        result += (carry / base) + '0';
        carry %= base;
    }

    resto = carry;
    return trim(result);
}

// soma  |  resultado = dígito_a + dígito_b + carry
/*
    Essa função faz a soma de dois números muito grandes que estão armazenados como texto.
    O programa simula uma soma como no papel, dígito por dígito.
    Ele inverte as duas strings para começar da direita
    Soma cada dígito um por um
    Guarda o “sobe um” na variável carry
    Depois monta o resultado final
*/
string add(string a, string b) {
    string res = "";
    int carry = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    size_t n = max(a.size(), b.size());

    for (size_t i = 0; i < n; i++) {
        int x = i < a.size() ? a[i] - '0' : 0;
        int y = i < b.size() ? b[i] - '0' : 0;

        int sum = x + y + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) res += carry + '0';

    reverse(res.begin(), res.end());
    return trim(res);
}

// multiplicação  |  resultado = dígito * base + carry
/*
    Multiplica um número grande por um número pequeno, que no caso é a base.
    pega o último dígito
    multiplica pela base
    guarda o resto
    leva o excesso para o próximo dígito (carry)
    É uma multiplicação igual a feita no papel, onde cada dígito gera um ‘vai um’ para o próximo.
*/
string multiply(string a, int b) {
    string res = "";
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        int prod = (a[i] - '0') * b + carry;
        res += (prod % 10) + '0';
        carry = prod / 10;
    }

    while (carry) {
        res += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(res.begin(), res.end());
    return trim(res);
}   

// Converte para decimal  |  resultado = resultado × base + dígito
/*
    Converte qualquer número de uma base para decimal usando multiplicação e adição.
    Para cada dígito do número, o programa primeiro multiplica o resultado atual pela base, depois soma o valor do dígito.
    Fórmula Honer: resultado = resultado × base + dígito
    Ele vai construindo o número decimal aos poucos, lendo da esquerda para a direita e recalculando o valor a cada novo dígito.
*/
string toDecimal(string num, int base) {
    string result = "0";

    for (char c : num) {
        int digit = charToValue(c);

        result = multiply(result, base);
        result = add(result, to_string(digit));
    }

    return result;
}

// Converte decimal → qualquer base
/*
    Essa função converte um número decimal para qualquer base.
    Ela funciona dividindo o número repetidamente pela base escolhida.
    A cada divisão, o resto vira um dígito do novo número.
    Como esses dígitos saem na ordem inversa, no final o programa inverte o resultado para formar o número correto.
*/
string fromDecimal(string num, int base) {
    string result = "";

    while (num != "0") {
        int resto;
        num = divide(num, base, resto);
        result += valueToChar(resto);
    }

    reverse(result.begin(), result.end());

    return result.empty() ? "0" : result;
}

// =============== MAIN ===============
int main() {
    char repetir = 'S';

    while (repetir == 'S' || repetir == 's') {

        cout << "\n===== CONVERSOR DE BASES =====\n";
        cout << "Bases suportadas: 2, 8, 10, 16, 32\n\n";

        int baseEntrada, baseSaida;
        string num;

        cout << "Base de entrada: ";
        cin >> baseEntrada;

        cout << "Numero: ";
        cin >> num;

        cout << "Base de saida: ";
        cin >> baseSaida;

        // conversões
        string decimal = toDecimal(num, baseEntrada);
        string result = fromDecimal(decimal, baseSaida);

        cout << "\nResultado: " << result << "\n";

        cout << "\nDeseja fazer outra conversao? (S/N): ";
        cin >> repetir;
    }

    cout << "\nPrograma encerrado.\n";

    return 0;
}