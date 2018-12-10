#include "Arduino.h"
#include "uno_timer.hpp"

void timer_init(float fFrequency, int iTimerNo){

    cli();
    switch (iTimerNo) {
        case 0:
            TCCR0A = 0;
            TCCR0B = 0;
            TCNT0  = 0;
            OCR0A = ( 16 * 1000000 )/( fFrequency * 64) - 1; //(must be <256)
            TCCR0A |= (1 << WGM01);
            TCCR0B |= (1 << CS01) | (1 << CS00);   //prescaler set on 64
            TIMSK0 |= (1 << OCIE0A);
            break;
        case 1:
            TCCR1A = 0;
            TCCR1B = 0;
            TCNT1 = 0;
            OCR1A = ( 16 * 1000000 )/( fFrequency * 1024) - 1; //(must be <65536)
            TCCR1B |= (1 << WGM12);
            TCCR1B |= (1 << CS12) | (1 << CS10);  //prescaler set on 1024
            TIMSK1 |= (1 << OCIE1A);
            break;
        case 2:
            TCCR2A = 0;
            TCCR2B = 0;
            TCNT2 = 0;
            OCR2A = 249; //( 16 * 1000000 )/( fFrequency * 8) - 1;
            TCCR2A |= (1 << WGM21);
            TCCR2B |= (1 << CS21);
            TIMSK2 |= (1 << OCIE2A);
        default:
            break;
    }
    sei();
}