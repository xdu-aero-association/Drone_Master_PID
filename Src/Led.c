/*
  ΢������Դ���Ȩ�����纽Э�з������Ŷ����У�δ�����Ŷ�ͬ�⣬�������������ϴ�����Դ�롣
	�뱾�����زο��������纽Э΢�����Ὺ��ָ�ϣ����ݶԱ��װ�������������Լ�Ӳ����ض�������ϸ�Ľ���
  �����ͬѧ���˸���������ĸĽ������κν��飬����ʱ�����Ǳ�����ϵ��
	���ߣ�PhillWeston
	��ϵ���䣺2436559745@qq.com
*/
#include "struct_all.h"

/******************************************************************************
����ԭ�ͣ�	static void Delay_led(u16 n)
��    �ܣ�	��ʱ
*******************************************************************************/ 
void Delay_led(uint16_t n)
{	
	uint16_t i,j;
	for(i=0;i<n;i++)
		for(j=0;j<8500;j++);
}

/******************************************************************************
����ԭ�ͣ�	void LED_ON(void)
��    �ܣ�	�ĸ���ɫLED����
*******************************************************************************/ 
void LED_ON(void)
{
	//GPIO_PIN_RESET�൱���õͣ�����LED����Ϊ��������˴˴�Ϊ����
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
}
/******************************************************************************
����ԭ�ͣ�	void LED_ON_OFF(void)
��    �ܣ�	�ĸ���ɫLEDϨ��
*******************************************************************************/ 
void LED_OFF(void)
{
	//GPIO_PIN_SET�൱���øߣ�����LED����Ϊ��������˴˴�Ϊ���
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
}
/******************************************************************************
����ԭ�ͣ�	void LED_ON_OFF(void)
��    �ܣ�	LED������˸
*******************************************************************************/ 
void LED_ON_OFF(void)
{
	uint8_t i ;
	for(i=0;i<3;i++)
	{
		LED_ON();
		Delay_led(200);
		LED_OFF();
		Delay_led(200);	
	}
	for(i=0;i<3;i++)
	{
		LED_ON();
		Delay_led(100);
		LED_OFF();
		Delay_led(100);	
	}
	Delay_led(100);
}
/******************************************************************************
����ԭ�ͣ�	void LED_ON_Frequency(uint8_t Light_Frequency)
��    �ܣ�	��LED3����ĳ��Ƶ����˸����Ҫѭ��ɨ��ú�����
��    ����   Light_Frequency����˸Ƶ�ʣ�HZ��
*******************************************************************************/ 
void LED_ON_Frequency(uint8_t Light_Frequency)
{
	uint16_t time_count;
	static uint8_t Light_On;
	static uint32_t Last_time,Now_time;
	
	Now_time = Timer3_Count;
	if( Light_On )
	{
		time_count = (uint16_t)(Timer3_Frequency / Light_Frequency / 2);	
		
		if( Now_time - Last_time >= time_count)
		{
			LED_OFF();
			Light_On=0;
			Last_time = Timer3_Count;
		}
	}
	else
	{
		time_count = (uint16_t)(Timer3_Frequency / Light_Frequency / 2);
		
		if( Now_time - Last_time >= time_count)
		{
			LED_ON();
			Light_On=1;
			Last_time = Timer3_Count;
		}
	}
}

