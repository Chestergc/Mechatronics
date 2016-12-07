#include <16f877.h>  // Picversion
#device ADC=10 // Analog/Digital Converter bitdepth
#use  delay (clock=20000000) // clock setup
#include <cuscostdio.h>  // stdio

void fillTank(){
  while(!input(D2)){
    output_low(C0);
    delay_ms(100);
  }
  output_high(C0);
}

void heater(){
  while(!input(D0)){
    output_low(C3);
    delay_ms(100);
  }
  output_high(C3);
}

void cooling(){
  output_low(C2);
  delay_ms(6000000);
  output_high(C2);
}

int lights(int x){
  int loop;
  loop = x;
  while (loop>=1){
    output_low(C4);
    output_high(BUZZER);
    delay_ms(500);
    output_high(C4);
    output_low(BUZZER);
    delay_ms(500);
    loop--;
  }
}

void emptyTank() {
  if (input(D3)) {
    while (!input(D1)) {
      output_low(C1);
      lights(4); //Alarms
    }
    output_high(C1);
    output_high(C4);
  }
}

main()      //Main doesn't need to be an int
{
        output_a(0x00); //Send 0 in hex to outputs
        output_b(0x00);
        output_c(0x00);
        output_d(0x00);
        int loop=1;

        while(loop>0) //Loop
        {
          fillTank();
          delay_ms(1000);
          heater();
          delay_ms(1000);
          cooling();
          delay_ms(1000);
          emptyTank();
          delay_ms(1000);
          loop--;
        }
        lights(100);
}
