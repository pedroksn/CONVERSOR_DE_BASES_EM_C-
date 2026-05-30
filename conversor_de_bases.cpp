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
string trim(string s) {
    while (s.size() > 1 && s[0] == '0')
        s.erase(0, 1);
    return s;
}



// divide string decimal por base, retorna resto'
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