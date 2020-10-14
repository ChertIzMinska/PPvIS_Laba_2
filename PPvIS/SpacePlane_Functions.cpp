/*!
\file
\brief Файл , в котором хранятся методы класса space_rplane

*/
#include "Header.h"
using namespace std;
void space_plane::_use_fuel()
{
	cout << "Fuel is on a place\n";
}
void space_plane::_use_oxidant()
{
	cout << "Oxidant is on a place\n";
}
void space_plane::_detach_the_first_part()
{
	cout << "You flew through the upper atmosphere.You are in space\n";
}
void space_plane::_mix()
{
	_use_fuel();
	_use_oxidant();
	cout << "Reaction and cravings occur\n";
}
void space_plane::_fly()
{
	_mix();
	cout << "You are flying\n";
	while(max_speed>speed)
		speed += 150;

}
int space_plane::_start()
{
	cout << "You are ready to fly\n";
	_fly();
	return 4;
}
space_plane::space_plane(int max_speed)
{
	this->max_speed = max_speed;
}
int space_plane::_finish()
{
	return 4;
}