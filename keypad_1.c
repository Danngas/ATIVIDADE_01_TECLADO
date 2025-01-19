#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definir os pinos GPIO para LEDs e Buzzer
#define LED_RED_PIN 13
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12
#define BUZZER_PIN 10

// Definir o layout da matriz do teclado e os pinos correspondentes
char keypad_layout[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

const uint8_t keypad_row_pins[4] = {2, 3, 4, 5};
const uint8_t keypad_col_pins[4] = {6, 7, 8, 9};

// Função para inicializar os pinos GPIO
void initialize_gpio()
{
    // Inicializar os pinos das linhas como saída e configurá-los como ALTO
    for (int i = 0; i < 4; i++)
    {
        gpio_init(keypad_row_pins[i]);
        gpio_set_dir(keypad_row_pins[i], GPIO_OUT);
        gpio_put(keypad_row_pins[i], 1);
    }

    // Inicializar os pinos das colunas como entrada com resistores pull-up
    for (int i = 0; i < 4; i++)
    {
        gpio_init(keypad_col_pins[i]);
        gpio_set_dir(keypad_col_pins[i], GPIO_IN);
        gpio_pull_up(keypad_col_pins[i]);
    }

    // Inicializar os pinos dos LEDs como saída
    gpio_init(LED_RED_PIN);
    gpio_init(LED_GREEN_PIN);
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    // Inicializar o pino do Buzzer como saída
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

// Função para controlar o LED RGB com base na tecla pressionada
void control_rgb_led(char key)
{
    // Desligar todos os LEDs inicialmente
    gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);
    gpio_put(LED_BLUE_PIN, 0);

    // Ativar LEDs específicos com base na tecla
    switch (key)
    {
    case 'A':
        gpio_put(LED_RED_PIN, 1);
        break;
    case 'B':
        gpio_put(LED_GREEN_PIN, 1);
        break;
    case 'C':
        gpio_put(LED_BLUE_PIN, 1);
        break;
    case 'D':
        gpio_put(LED_RED_PIN, 1);
        gpio_put(LED_GREEN_PIN, 1);
        gpio_put(LED_BLUE_PIN, 1);
        break;
    }
}

// Função para controlar o Buzzer
void control_buzzer(char key)
{
    if (key == '#')
    {
        gpio_put(BUZZER_PIN, 1);
        sleep_ms(100);
        gpio_put(BUZZER_PIN, 0);
    }
}

// Funções para teclas numéricas
void handle_key_1()
{
    for (int i = 0; i < 3; i++)
    {
        gpio_put(LED_RED_PIN, 1);
        sleep_ms(200);
        gpio_put(LED_RED_PIN, 0);
        sleep_ms(200);
    }
}

void handle_key_2()
{
    for (int i = 0; i < 3; i++)
    {
        gpio_put(LED_GREEN_PIN, 1);
        sleep_ms(200);
        gpio_put(LED_GREEN_PIN, 0);
        sleep_ms(200);
    }
}

void handle_key_3()
{
    for (int i = 0; i < 3; i++)
    {
        gpio_put(LED_BLUE_PIN, 1);
        sleep_ms(200);
        gpio_put(LED_BLUE_PIN, 0);
        sleep_ms(200);
    }
}

void handle_key_4()
{
    // Liga os leds em sequencia
    // Verde->Azul->Vermelho
    for (int i = 11; i < 14; i++) {
      gpio_put(i,1);
      sleep_ms(500);
      gpio_put(i,0);
      sleep_ms(500);
    }
}

void handle_key_5()
{
    // Implementação futura
}

void handle_key_6()
{
    // Implementação futura
}

void handle_key_7()
{
    // Implementação futura
}

void handle_key_8()
{
    // Implementação futura
}

void handle_key_9()
{
    // Implementação futura
}

// Função para escanear o teclado e detectar uma tecla pressionada
char get_keypad_input()
{
    char pressed_key = 0;

    // Iterar sobre cada linha para detectar teclas pressionadas
    for (int row = 0; row < 4; row++)
    {
        gpio_put(keypad_row_pins[row], 0);
        uint32_t gpio_states = gpio_get_all();

        for (int col = 0; col < 4; col++)
        {
            if (!(gpio_states & (1u << keypad_col_pins[col])))
            {
                pressed_key = keypad_layout[row][col];
                sleep_ms(200); // Atraso para debounce
            }
        }

        gpio_put(keypad_row_pins[row], 1);
    }

    return pressed_key;
}

// Loop principal do programa
int main()
{
    stdio_init_all();
    initialize_gpio();

    while (1)
    {
        char key = get_keypad_input();

        if (key != 0)
        {
            // Imprimir a tecla pressionada
            printf("Tecla pressionada: %c\n", key);

            // Desligar todos os LEDs ao pressionar qualquer tecla
            gpio_put(LED_RED_PIN, 0);
            gpio_put(LED_GREEN_PIN, 0);
            gpio_put(LED_BLUE_PIN, 0);

            // Tratar teclas numéricas
            if (key == '1')
                handle_key_1();
            if (key == '2')
                handle_key_2();
            if (key == '3')
                handle_key_3();
            if (key == '4')
                handle_key_4();
            if (key == '5')
                handle_key_5();
            if (key == '6')
                handle_key_6();
            if (key == '7')
                handle_key_7();
            if (key == '8')
                handle_key_8();
            if (key == '9')
                handle_key_9();

            // Tratar teclas de controle de LED RGB
            if (key >= 'A' && key <= 'D')
            {
                control_rgb_led(key);
            }

            // Tratar controle do Buzzer
            if (key == '#' || key == '*')
            {
                control_buzzer(key);
            }
        }

        sleep_ms(50); // Atraso para evitar polling excessivo
    }

    return 0;
}
