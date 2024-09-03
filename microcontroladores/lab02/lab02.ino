#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit))
#define BitTst(arg,bit) (((arg) & (1<<bit)) >> bit)
#define BitFlp(arg,bit) ((arg) ^= (1<<bit))

volatile uint8_t led_state = 0;

void setup(){
    // Configura os pinos PB0, PB1, PB2 como saída (LEDs) e os demais como entrada
    DDRB = 0b00001111;
    // Inicializa todos os LEDs apagados e habilita pull-up nas entradas
    PORTB = 0b11111000;
    
    // Configura a interrupção externa no pino INT0 (PD2 no Arduino Uno)
    EICRA = 0b00000010; 
    EIMSK = 0b00000001;
    sei();                 // Habilita interrupções globais
}

void loop(){
    // Gera uma onda quadrada no pino de saída para o INT0
    BitFlp(PORTB, PB3);
    _delay_ms(1000);
}

ISR(INT0_vect) {
    // Lógica para acender os LEDs sequencialmente a cada borda de descida
    led_state++;
    if (led_state > 3) {
        led_state = 0; // Reseta o estado para apagar todos os LEDs
    }

    switch (led_state) {
        case 0:
        PORTB = 0b00000001; // Apaga todos os LEDs
            
            break;
        case 1:
        PORTB = 0b00000011;

            break;
        case 2:
        PORTB = 0b00000111;

            break;
        case 3:
        PORTB = 0b00000000;

            break;
    }
}
