#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)
#define LED_PIN PIN5

int main(void)
{
    RCC->AHB1ENR |=GPIOAEN;

    GPIOA->MODER |=(1<<10);
    GPIOA->MODER &=~(1U<<11);
    

    while(1)
    {
        // Liga o LED
        GPIOA->BSRR = LED_PIN;
        for(int i=0;i<100000;i++){}

        // Desliga o LED (Bit de reset para o pino 5 é o bit 21 (5+16))
        GPIOA->BSRR = (1U<<21);
        for(int i=0;i<100000;i++){}
    }
}