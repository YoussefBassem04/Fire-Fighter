/*
 * main.c
 *
 * Created: 8/17/2024 7:08:28 PM
 * Author : Youssef Bassem
 */ 

/* Section: Includes */
#include "main.h"

void Car_Move_Forward(){
	DC_MOTOR_voidMoveForward_1(100);
	DC_MOTOR_voidMoveForward_2(100);

	
}

void Car_Move_Backward(){
	DC_MOTOR_voidMoveBackward_1(100);
	DC_MOTOR_voidMoveBackward_2(100);
}

void Car_Stop(){
	DC_MOTOR_voidStop_1();
	DC_MOTOR_voidStop_2();

	
}

void Car_Move_Left(){
	DC_MOTOR_voidMoveForward_1(100);
	DC_MOTOR_voidStop_2();

			
}

void Car_Move_Right(){
	
	DC_MOTOR_voidStop_1();
	DC_MOTOR_voidMoveForward_2(100);

	
	
}


void pump_on(){
	
	DIO_voidSetPinVal(DIO_PORTA,DIO_PIN2,HIGH);
}

void pump_off(){
	
	DIO_voidSetPinVal(DIO_PORTA,DIO_PIN2,LOW);
	
}
int main(void) {
	
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN2,OUTPUT);
	

	UART_voidInit();
	
	
	u8 data = 0;
	
	while(1){
		data = UART_u8Rx();
		
		switch(data){
			case 'U':
				Car_Move_Forward();
				break;
			case 'D':
				Car_Move_Backward();
				break;
			case 'R':
				Car_Move_Right();
				break;
			case 'L':
				Car_Move_Left();
				break;
			default:
				Car_Stop();
				if (data == '1' )
				{
					pump_on();
					//_delay_ms(1000);
				}else if(data == '2') {
					pump_off();
				}
				break;
				
			
			
		}
	
	}
		
		
			
		
		
	
	
	
}