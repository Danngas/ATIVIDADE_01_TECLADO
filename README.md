# ATIVIDADE01
#PARTICIPANTES ATIVOS

DANIEL SILVA DE SOUZA 

ANTONIO APARECIDO MEDEIROS

HENRIQUE DA SILVA BISPO
#
 link da simulacao https://wokwi.com/projects/420369392351547393
 
 link do video mostrando o funcionamento

 
Guia de Uso - Programa para Teclado Matricial 4x4
Descrição Geral
Este programa utiliza um teclado matricial 4x4 para controlar LEDs e um buzzer. Cada tecla do teclado corresponde a uma ação específica, como ligar, desligar, fazer os LEDs piscarem ou ativar o buzzer.

Configuração Inicial

Conexão do teclado matricial:

Conecte as linhas (rows) e colunas (columns) do teclado matricial às portas GPIO indicadas no código.

Conexão dos LEDs e buzzer:

LEDs: Conecte os LEDs às portas GPIO indicadas no código, utilizando resistores adequados para limitar a corrente.
Buzzer: Conecte o buzzer à porta GPIO indicada, garantindo que ele receba a alimentação correta e, se necessário, utilize um resistor ou transistor para amplificar o sinal.
Alimentação:

Certifique-se de que o circuito está recebendo a tensão correta (geralmente 5V ou 3.3V, dependendo do microcontrolador e componentes).
Funções Implementadas

Teclas e suas Funções:

A → Liga o LED azul.

D → Liga o LED verde.

1 → Faz o LED azul piscar.

D → Liga o LED vermelho.

2 → Faz o LED verde piscar.

D → Liga o LED branco.

3 → Faz o LED vermelho piscar.

7 → Faz o rbp piscar na sequencia vermelho → verde → azul e branco com um intervalo de 0,5 segundos entre as cores.

4 → Faz o led piscar na sequencia Verde → Azul → Vermelho

(Asterisco) → Desliga os LED's
 (JOGO VA VELHA) --> Ativa o buzzer.

Restante das Teclas

Os botões 5, 6, 8, 9  ainda não têm funções atribuídas.

Como Utilizar

Iniciar o Programa: Certifique-se de que o microcontrolador foi programado corretamente e ligue o sistema.
Pressionar as Teclas: Utilize o teclado para acionar os LEDs ou o buzzer conforme descrito.

Função do Buzzer:

O buzzer será acionado automaticamente ao pressionar o botão #.


Personalizar Funções: Para adicionar novas funcionalidades, edite o código, atribuindo ações às teclas restantes.
Cuidados ao Utilizar

Evite múltiplas entradas simultâneas: Pressionar várias teclas ao mesmo tempo pode causar comportamentos inesperados.

Teste individual: Após cada atualização no código, teste cada botão e o buzzer para confirmar o funcionamento correto.

Proteção do hardware: Use resistores adequados para os LEDs e evite sobrecarga no buzzer.

Configurações de Conexões

Pinos GPIO do Microcontrolador

// Definir os pinos GPIO para LEDs e Buzzer

#define LED_RED_PIN 13

#define LED_GREEN_PIN 11

#define LED_BLUE_PIN 12

#define BUZZER_PIN 10

// Definir os pinos GPIO para as linhas e colunas do teclado matricial

const uint8_t keypad_row_pins[4] = {2, 3, 4, 5};

const uint8_t keypad_col_pins[4] = {6, 7, 8, 9};

LED Vermelho: Conectado ao pino 13.

LED Verde: Conectado ao pino 11.

LED Azul: Conectado ao pino 12.

Buzzer: Conectado ao pino 10.

Teclado Matricial:

Linhas: Conectadas aos pinos 2, 3, 4 e 5.

Colunas: Conectadas aos pinos 6, 7, 8 e 9.

Recomendações para o Circuito

LEDs: Utilize resistores entre 220Ω e 330Ω para proteger os LEDs.

