#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define __IO volatile

typedef struct{
	__IO	uint32_t MODER;				/*!< GPIO port mode register 					 Address offset: 0x00	 */
	__IO	uint32_t OTYPER;			/*!< GPIO port output type register 			 Address offset: 0x04    */
	__IO	uint32_t OSPEEDR;			/*!< GPIO port output speed register			 Address offset: 0x08    */
	__IO	uint32_t PUPDR;				/*!< GPIO port pull-up/pull-down register 		 Address offset: 0x0C	 */
	__IO	uint32_t IDR;				/*!< GPIO port input data register				 Address offset: 0x10    */
	__IO	uint32_t ODR;				/*!< GPIO port output data register				 Address offset: 0x14	 */
	__IO	uint32_t BSRR;				/*!< GPIO port bit set/reset register			 Address offset: 0x18	 */
	__IO	uint32_t LCKR;				/*!< GPIO port configuration lock register  	 Address offset: 0x1C	 */
	__IO	uint32_t AFR[2];			/*!< GPIO alternate function low/high register   Address offset: 0x20	 */
}GPIO_Typedef_t;

typedef struct{

uint32_t Mode;                /*!< GPIO Mode Type 00: Input (reset state) 01: General purpose output mode 10: Alternate function mode 11: Analog mode	 */
uint32_t pinNumber;           /*!< GPIO Pin Number 0-15	                                                                                                 */
uint32_t oType;               /*!< GPIO Output Type 0: Output push-pull (reset state) 1: Output open-drain	                                             */
uint32_t Speed;               /*!< GPIO Speed  00: Low speed 01: Medium speed 10: High speed 11: Very high speed                                         */   
uint32_t PupDr;               /*!< GPIO Pull Up/Down  00: No pull-up, pull-down 01: Pull-up 10: Pull-down 11: Reserved                                   */   
uint32_t Alternate;           /*!< GPIO AFRLy:Alternatefunctionselectionforportxbity(y=0..7)                                                             */         

}GPIO_InitTypedef_t;

void GPIO_Init( GPIO_Typedef_t* GPIOx, GPIO_InitTypedef_t * GPIO_InitStruct)
{
    GPIOx -> MODER = GPIO_InitStruct-> Mode;
    GPIOx -> OTYPER = GPIO_InitStruct-> oType;
    GPIOx -> OSPEEDR = GPIO_InitStruct -> Speed;
    GPIOx -> PUPDR = GPIO_InitStruct -> PupDr;
}

int main(void)
{
    GPIO_Typedef_t *GPIOA = (GPIO_Typedef_t *)malloc(sizeof(GPIO_Typedef_t));
    GPIO_InitTypedef_t *GPIO_InitStruct = (GPIO_InitTypedef_t *)malloc(sizeof(GPIO_InitTypedef_t));

    GPIO_InitStruct->Mode = 0x3;
    GPIO_Init(GPIOA, GPIO_InitStruct);

    printf("GPIOA MODE %#X %d", GPIOA->MODER, GPIOA->MODER);

    // Remember to free the allocated memory before the program exits
    free(GPIOA);
    free(GPIO_InitStruct);

    return 0;
}