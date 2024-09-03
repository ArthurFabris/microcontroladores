
#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit))
#define BitTst(arg,bit) (((arg) & (1<<bit)) >> bit)
#define BitFlp(arg,bit) ((arg) ^= (1<<bit))

int prev = 1;
int atual = 1;
int sum = 1;
int ciclo = 0;


int main(void) {
	DDRB  = 0b11111111; // Notação de número binário (Bit 5 como saída, demais bits como entrada)
  PORTB = 0x00;


  DDRC =  0b00000000;
  PORTC = 0b00000001;

  while (1) { //Loop infinito
    	atual = BitTst(PINC,0);
    if (atual == 0 && prev ==1){
      sum ++;

	} 
  if(ciclo == 1){
      if(sum==1){
    PORTB = 0b00010000;
  }
    if(sum==2){
    PORTB = 0b00001000;
  }
    if(sum==3){
    PORTB = 0b00000100;
  }
    if(sum==4){
    PORTB = 0b00000010;
  }
    if(sum==5){
    PORTB = 0b00000001;
  }
  if(sum==6){
    PORTB = 0b00000010;
  }
  if(sum==7){
    PORTB = 0b00000100;
  }
  if(sum==8){
    PORTB = 0b00001000;
  }
  if(sum==9){
    sum = 1;
  }

  prev = atual;
  _delay_ms(10);
  }
  if(ciclo==0){
        if(sum==1){
    PORTB = 0b00010001;
  }
    if(sum==2){
    PORTB = 0b00001010;
  }
    if(sum==3){
    PORTB = 0b00000100;
  }
    if(sum==4){
    PORTB = 0b00001010;
  }
    if(sum==5){
    sum = 1;
  }
  }
	return 0;
  }}