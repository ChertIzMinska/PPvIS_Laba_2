/*!
\file
\brief Файл , в котором хранятся методы класса ship .


*/
#include "Header.h"
using namespace std;
void ship::_use_anchor()
{
	if (down_anchor)
		down_anchor = false;
	else {
		down_anchor = true;
	}
}
ship::ship(int displacement,int max_speed)
{
	this->displacement = displacement;
	this->max_speed = max_speed;
}
void ship::_move()
{
	if(max_speed>speed)
		speed += 2;
}
int ship::_start()
{
		_use_anchor();
	while(speed!=50)
		_move();
	return 2;

}
int ship::_finish()
{
	_use_anchor();
	return 2;
}