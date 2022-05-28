#include "Joystick.h"

////////////////////////////////////////////////////////////////////////
int Joystick::readX(void){

	int	state = analogRead(X_axis_pin) - centerX;
	int dead_zone_plus = centerX + dead_zone_x;
	int dead_zone_minus = centerX - dead_zone_x;
	
	if ((state > dead_zone_minus) && (state < dead_zone_plus)) state = 0;
	
	return state;
}

////////////////////////////////////////////////////////////////////////
int Joystick::readY(void)
{
	int state = analogRead(Y_axis_pin) - centerY;
	int dead_zone_plus = centerY + dead_zone_y;
	int dead_zone_minus = centerY - dead_zone_y;
	
	if ((state > dead_zone_minus) && (state < dead_zone_plus)) state = 0;
	
	return state;
}

////////////////////////////////////////////////////////////////////////
void Joystick::calibrateCenter(void)
{
	centerX = analogRead(X_axis_pin);
	centerY = analogRead(Y_axis_pin);
}
