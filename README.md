# Mechatronics

This is a project i've been proposed to write for a mechatronics class, the project proposed the project
and building of a simple fermentation system for beers, using a PIC series micro controller and sensors
for triggering positions in the system.

This will be the repository for the source code of the system, to be loaded to the micro controller using
a custom library(cuscostdio.h) written by a professor in my institution.

The commands added by the library are:

- output_high();
- output_low();
- delay_ms();
- delay_us();
- C0=>C7 (outputs)
- D0=>D7 (inputs)
- RELE1, RELE2 (Relay Interfaces)
- BUZZER (exactly what it sounds like.)
