/*!
\file
\brief Файл , в котором хранятся методы класса airplane


*/
#include "Header.h"
using namespace std;
void airplane::_use_flaps()
{
	speed -= 40;
}
int airplane::_finish()
{
	while(speed<0)
		_use_flaps();
	speed = 0;
	return 3;
}
void airplane::_use_chassis()
{
	if (chassis)
	{
		chassis = false;
		cout << "Сhassis retracted\n";
	}
	else {
		chassis = true;
		cout << "chassis released\n";
		_finish();
	}
}
int airplane::_start()
{
	cout << "Turbines is activated\n";
	return 3;
}
void airplane::_move()
{
	while (max_speed > speed)
		speed += 30;
}
void airplane::_fly()
{
	_start();
	_use_chassis();
	_move();
}
airplane::airplane(int max_speed)
{
	this->max_speed = max_speed;
}