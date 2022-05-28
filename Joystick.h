#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <Arduino.h>

typedef const unsigned char pin_number;

class Joystick
{
	public:
		//-------X_axis_pin, Y_axis_pin, Button_pin, Deadly zone X, Deadly zone Y
		Joystick(pin_number, pin_number,  pin_number, unsigned int, unsigned int);
		
		int readX(void);
		int readY(void);
		bool readButton(void){return digitalRead(Button_pin);}
		
		void calibrateCenter(void);
		
	private:
		
		pin_number X_axis_pin;
		pin_number Y_axis_pin;
		pin_number Button_pin;
		int centerX;
		int centerY;
		char dead_zone_x;
		char dead_zone_y;
};


#endif//_JOYSTICK_H