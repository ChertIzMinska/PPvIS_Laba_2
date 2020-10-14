/*!
\file
\brief Файл , в котором хранятся функции класса car .


*/
#include "Header.h"
using namespace std;
void car::_use_wiper(bool _is_rain)
{
	if (_is_rain)
		cout << "You used wiper.You see better\n";
	else
		cout << "Nothing changed\n";
}
void car::_activate_stop_signals()
{
	cout << "Stop signals activated\n";
}
void car::_change_a_transmission(int transmission)
{
	if(this->transmission==transmission)
		cout << "You have already changed your transmission on " << transmission << endl;
	this->transmission = transmission;
	speed -= 2;
}
bool car::_use_accelarate_pedal()
{
	if (transmission == 0)
		return false;
	if(max_speed>speed)
		speed += 5;
	return true;
}
void car::_move()
{
	_use_accelarate_pedal();
}
int car::_start()
{
	_change_a_transmission(1);
	_move();
	return 1;
	
}
bool car::_use_brake_pedal()
{
	if (transmission == 0)
		return false;
	
	speed -= 5;
	_activate_stop_signals();
	if (speed < 0)
	{
		speed = 0;
		return true;
	}
}
int car::_finish()
 {while(speed!=0)
	_use_brake_pedal();

_change_a_transmission(0);
return 1;
}
car::car(string mark, string number, int light_transmission, int max_speed)
{
	this->mark = mark;
	this->number = number;
	this->light_transmission = light_transmission;
	this->max_speed = max_speed;
}