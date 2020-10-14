/*!
\file
\brief Файл , в котором хранятся методы класса ship

*/#include "Header.h"
using namespace std;
void bicycle::_use_pedals()
{
	if(max_speed>speed)
		speed += 0.2;
}
void bicycle::_use_damper(bool turn_right)
{
	if (turn_right)
		cout << "You turned right\n";
	else{ cout << "You turned left\n"; }

}
void bicycle::_put_on_helm()
{
	cout << "You put on helm\n";
}