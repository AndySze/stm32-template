/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2013 Andy Sze(andy.sze.mail@gmail.com) & MakerLAB.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *****************************************************************************/

/**
 *  @file main.c
 *
 *  @brief 
 *
 */

#include "stm32f10x.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);
void LED_GPIO_Config(void);

int main(void)
{	
	LED_GPIO_Config();

	while (1)
	{
		//LED1:PC3
    GPIO_ResetBits(GPIOC,GPIO_Pin_3);
		Delay(0x0F0FEF);
    GPIO_SetBits(GPIOC,GPIO_Pin_3);
		
		//LED2:PC4;
    GPIO_ResetBits(GPIOC,GPIO_Pin_4);
		Delay(0x1FFFEF);
    GPIO_SetBits(GPIOC,GPIO_Pin_4);
		
		//LED3:PC5;
    GPIO_ResetBits(GPIOC,GPIO_Pin_5);
		Delay(0x0FFFEF);
    GPIO_SetBits(GPIOC,GPIO_Pin_5);
	}
}

void Delay(__IO u32 nCount)	
{
	for(; nCount != 0; nCount--);
} 

void LED_GPIO_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;	

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

  GPIO_Init(GPIOC, &GPIO_InitStructure);		  

	GPIO_SetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);	 
}

