📌 Conversor de Bases em C++

📖 Descrição
Este projeto é um conversor de bases numéricas desenvolvido em C++, capaz de converter números entre as bases:

Base 2 (binário)
Base 8 (octal)
Base 10 (decimal)
Base 16 (hexadecimal)
Base 32 (duotrigesimal)

▶️ Instruções

Ao executar o programa, o usuário será guiado por um menu interativo no terminal.

Informe a base de entrada do número (2, 8, 10, 16 ou 32)
Digite o número a ser convertido
Informe a base de saída desejada
O resultado da conversão será exibido na tela
Escolha se deseja realizar outra conversão:
S → continua o programa
N → encerra a execução

🧠 Como funciona

O projeto utiliza os seguintes algoritmos de conversão:

🔁 Base → Decimal

Utiliza a fórmula:

resultado = resultado × base + dígito
🔁 Decimal → Base

Utiliza divisões sucessivas:

enquanto número > 0:
    resto = número % base
    número = número / base

📂 Estrutura do código

O código é dividido em funções simples modulares:

charToValue() → converte caractere para valor numérico
valueToChar() → converte valor para caractere
trim() → remove zeros à esquerda
add() → soma números grandes em string
multiply() → multiplica string por inteiro
divide() → divisão manual de strings
toDecimal() → converte qualquer base para decimal
fromDecimal() → converte decimal para qualquer base

🚀 Como compilar e executar
Compilador C++ (g++, MinGW ou MSVC)
Suporte a C++11 ou superior
💻 Compilação (g++)
g++ main.cpp -o conversor
▶️ Execução
./conversor

⚠️ Observações
O projeto não utiliza bibliotecas externas
Todas as operações são feitas manualmente com strings
Pode haver lentidão em números extremamente grandes devido à complexidade das operações.
Não possui interface gráfica


Este projeto foi desenvolvido com objetivo acadêmico.

👨‍💻 Autor
Pedro Dall'oca Kusano