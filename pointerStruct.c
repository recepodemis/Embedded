#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct
{
    uint32_t MODER;
    uint32_t OSPEEDR;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t PUPR;
    uint32_t BSRR;
    uint32_t CLKR;
    uint32_t AFR[2];
}GPIO_Typedef_t;


int main()
{
    GPIO_Typedef_t* GPIOA = (GPIO_Typedef_t *)malloc(sizeof(GPIO_Typedef_t));

    printf("Main    AADR: %p \n\n",GPIOA);
    printf("MODER   AADR: %p \n",&GPIOA->MODER);
    printf("OSPEEDR AADR: %p \n",&GPIOA->OSPEEDR);
    printf("IDR     AADR: %p \n",&GPIOA->IDR);
    printf("ODR     AADR: %p \n",&GPIOA->ODR);
    printf("PUPR    AADR: %p \n",&GPIOA->PUPR);
    printf("BSRR    AADR: %p \n",&GPIOA->BSRR);
    printf("CLKR    AADR: %p \n",&GPIOA->CLKR);
    printf("AFR[0]  AADR: %p \n",&GPIOA->AFR);
    printf("AFR[1]  AADR: %p \n",&GPIOA->AFR[1]);

    return 0;
}