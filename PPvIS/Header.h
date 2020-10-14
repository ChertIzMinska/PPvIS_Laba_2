/*!
\file
\brief Файл ,который содержит описание классов.

Данный файл содержит абстрактрый класс vechile .Его дочерние классы :car,ship,airplane,ship,space_plane,bicycle,motocycle.

*/
#pragma once
#include<string>
#include<iostream>
#include<type_traits>
using namespace std;
/*!
\brief Абстрактный класс vechile

 Данный класс является предком для всех остальных классов.
	 В нем хранятся:
	 \param int max_speed максимальная скорость нашего транспортного средства
	 \param  int speed  скорость нашего тс в данный момент времени
*/
class vechile
{
protected:
	int max_speed;
	int speed=0;
	/// <summary>
	///  Функция _move описывает движение нашего тс т.е. что нужно сделать чтобы мы смогли продолжить движение.
	/// </summary>
	void virtual _move()=0;
public:
	/// <summary>
	///  Функция _start,которая отвечает за начало движения .Например:включение двигателя(турбин), поднятие якоря.
	/// </summary>
	/// <returns>Возвращает номер дочернего класса. Для car-1,ship-2,airplane-3,space_palne-4,motocycle-1 так как  она наследует функцию start и finish от car</returns>
	int virtual _start()=0;
	/// <summary>
	///  Функция _start,которая отвечает за конец движения .Например:выключение двигателя(турбин), опущение  якоря.
	/// </summary>
	/// <returns>Возвращает номер дочернего класса. Для car-1,ship-2,airplane-3,space_palne-4,motocycle-1 так как  она наследует функцию start и finish от car</returns>
	int virtual _finish()=0;



};
/*!
\brief Дочерний класс car

 Данный класс был получен через public наследование , так как нам не нужно было менять типы доступа наших функций и атрибутов абстрактоного класса.
	 \param int light transmission светопропускаемость наших стекол,находится в private секции.
	 Все следующие параметры находятся в protected , так как нужно было чтобы эти атрибуты передавались нашим дочерним классам и при этом нельзя было просто так их изменить.
	 \param string mark -- марка/модель машины(мотоцикла для дочернего класса)
	 \param string number--номера нашей машины(мотоцикла)
	 \param int transmission--трансмиссия на данный момент(на какой передаче находится наша тс)
*/
class car :public virtual  vechile
{
private:
	int light_transmission;
	/// <summary>
	/// Функция отвечат за использование стеклоочистителей , функция находится в private секции так как она не должна передоваться дочерним классам  класса машина.
	/// </summary>
	/// <param name="_is_rain">параметр отвечает за состояние погоды , true-идет дождь false-ясно,туманно без осадков</param>
	void _use_wiper(bool _is_rain);
protected:
	string mark;
	string number;
	int transmission=0;
	/// <summary>
	/// Функция отвчает за включение стоп-сигналов при торможении.
	/// </summary>
	void _activate_stop_signals();
	/// <summary>
	/// Описывает действия ,которые нужно для передвижения.
	/// </summary>
	void _move();
public:
	/// <summary>
	/// Функция описывает переключение передач.
	/// </summary>
	/// <param name="transmission">Параметр указывает какую передачу мы хотим включить</param>
	void _change_a_transmission(int transmission);
	/// <summary>
	/// Описывает то , как надо начать движение(завести машигу).
	/// </summary>
	/// <returns>возвращает 1</returns>
	int _start();
	/// <summary>
	/// Функция которая просто описывает педаль газа т.е. ускорение или же добавление скорости
	/// </summary>
	/// <returns>true--возращает если машина уже заведена и машина ускорилась;false-- возращает если педаль ничего не сделала</returns>
	bool _use_accelarate_pedal();
	/// <summary>
	/// Функция описывает педаль торможение(снижение скорости)
	/// </summary>
	/// <returns>true--возращает если машина уже заведена и машина замедлилась;false-- возращает если педаль ничего не сделала</returns>
	bool _use_brake_pedal();
	/// <summary>
	/// Функция описывает остановку машины и выключение двигателя
	/// </summary>
	/// <returns>возвращает 1</returns>
	int  _finish();
	car(string mark, string number, int light_transmission,int max_speed);
	
};
/*!
\brief Дочерний класс ship

 Данный класс был получен через public наследование , так как нам не нужно было менять типы доступа наших функций и атрибутов абстрактоного класса.
	 В нем хранятся:
	 В private:
	 \param int displacement-- Водоизмещение (количество (обычно вес) воды, вытесняемой плавающим судном).
	 \param  bool down_anchor-- состояние якоря нашего корабля;true--первоначальное состояние т.е. якорь опущен, false--якорь поднят.
*/
class ship :public virtual vechile {
private:
	int displacement;
	bool down_anchor = true;
protected:
	/// <summary>
	/// Функция описывает движение корабля (разгон корабля при подаче топлива).
	/// </summary>
	void _move();

public:
	/// <summary>
	/// Функция ,которая отвечате за поднятие якоря ,если он опущен, и если якорь поднят , то за опуск якоря.
	/// </summary>
	void  _use_anchor();
	/// <summary>
	/// Функция ,которая отвечат за начало движение(т.е. опущение якоря и разгон двигателя)
	/// </summary>
	/// <returns>возрвращает 2</returns>
	int _start();
	/// <summary>
	/// Функция , которая отвечает за остановку корабля(опуск якоря).
	/// </summary>
	/// <returns></returns>
	int _finish();
	ship(int displacement, int max_speed);

};
/*!
\brief Дочерний класс airplane

 Данный класс является дочерним классом класса vechile.Класс был получен через private наследование,так как нужно было чтобы наши виртуальные методы были недоступны  в любой точке кода и не передовались классам дочерним от этого класса.
	 В нем хранятся:
	 В private:
	 \param bool chassis--состояние шасси; true--если шасси выпущены ,false--если шасси спрятаны.
*/
class airplane :private virtual vechile {
private:
	bool chassis = true;
	/// <summary>
	/// Функция , которая описывает работу закрылок или же можно сказать что это функция отвечает за торможение.
	/// </summary>
	void _use_flaps();
	/// <summary>
	/// Функция описывает ускорение нашего самолета.
	/// </summary>
	void  _move();
	/// <summary>
	/// Функция запускает самолет(точнее турбины).
	/// </summary>
	/// <returns>возвращает 3</returns>
	int  _start();
	/// <summary>
	/// Функция описывает посадку самолета.
	/// </summary>
	/// <returns>возвращает 3</returns>
	int  _finish();
	/// <summary>
	/// Функция отвечает за состояние шасси при взлете и посадке.
	/// </summary>
	void _use_chassis();
public:
	/// <summary>
	/// Функция описывает взлет самолета (его разгон убирание шасси и т.д.)
	///Функция является виртуальной для последующей перезагрузки данной функции в дочернем классе.
	/// </summary>
	void virtual _fly();
	airplane(int max_speed);
	airplane() {};
};
/*!
\brief Дочерний класс space_plane

 Данный класс является результатом множественного наследования от класса vechile public наследованием и от класса airplane protected наследованием.
 Множественное наследование нужно тут ,так как данному классу нужны  методы как от класса  vechile ,так и от класса airplane , однако методы от класса airplane не должны быть в public.

*/
class space_plane :public virtual vechile, protected virtual airplane
{
private:
	/// <summary>
	/// Функция отвечает за смешение двух частей ракетного топлива ,так как ракетное топливо состоит из двух компонентов и хранится в отдельных баках и сами по себе ничего не делают
	/// </summary>
	void _mix();
	/// <summary>
	/// Функция отвечает за заливание в контейнер  оксислителя топлива.
	/// </summary>
	void _use_oxidant();
	/// <summary>
	/// Функция отвечает за заливание в контейнер  основного горючего топлива.
	/// </summary>
	void _use_fuel();
	/// <summary>
	/// Функция отвечает за полет космического аппарата.
	/// </summary>
	void _fly();
public:
	/// <summary>
	/// Функция отвечает за запуск космического корабля(за его готовность к полету).
	/// </summary>
	/// <returns>возвращает 4</returns>
	int _start();
	/// <summary>
	/// Функция отвечает за отсоединение нижней части корабля, когда корабль вышел за атмосферу.
	/// </summary>
	void _detach_the_first_part();
	int _finish();
	space_plane(int max_speed);
};
/*!
\brief Дочерний класс bicycle

 Данный класс является дочерним классом от абстрактного класса vechile
	
*/
class bicycle :public virtual vechile {
public:
	/// <summary>
	/// Функция отвечает за вращение педалей(ускорение ,начало движения).
	/// </summary>
	void _use_pedals();
	/// <summary>
	/// функция отвечает за использования демпфера(в данном классе за поворот направо или налево).
	/// </summary>
	/// <param name="turn_right">параметр который отвечает за направление куда надо поворачивать.true--если поворот направо;false--если поворот налево</param>
	void  _use_damper(bool turn_right);
	/// <summary>
	/// функция отвечает за надевание шлема.
	/// </summary>
	void _put_on_helm();
};
/*!
\brief Дочерний класс motocycle

 Данный класс является результатом множественного наследования от public наследований классов car и bicycle.
 Внутри данного класса ничего не описану в связи с тем , что данный класс полностью все наследует из своих классов предков.
 Поэтому для ознакомления с методами и атрибутами motocycle следует посмотреть public и protected секции car и bicycle.
*/
class motocycle :public  car,public  bicycle
{
public:
	motocycle(string mark, string number, int max_speed, int light_transmission = 0) :car(mark, number, light_transmission, max_speed) {}
};
