/*!
\file
\brief ���� ,������� �������� �������� �������.

������ ���� �������� ����������� ����� vechile .��� �������� ������ :car,ship,airplane,ship,space_plane,bicycle,motocycle.

*/
#pragma once
#include<string>
#include<iostream>
#include<type_traits>
using namespace std;
/*!
\brief ����������� ����� vechile

 ������ ����� �������� ������� ��� ���� ��������� �������.
	 � ��� ��������:
	 \param int max_speed ������������ �������� ������ ������������� ��������
	 \param  int speed  �������� ������ �� � ������ ������ �������
*/
class vechile
{
protected:
	int max_speed;
	int speed=0;
	/// <summary>
	///  ������� _move ��������� �������� ������ �� �.�. ��� ����� ������� ����� �� ������ ���������� ��������.
	/// </summary>
	void virtual _move()=0;
public:
	/// <summary>
	///  ������� _start,������� �������� �� ������ �������� .��������:��������� ���������(������), �������� �����.
	/// </summary>
	/// <returns>���������� ����� ��������� ������. ��� car-1,ship-2,airplane-3,space_palne-4,motocycle-1 ��� ���  ��� ��������� ������� start � finish �� car</returns>
	int virtual _start()=0;
	/// <summary>
	///  ������� _start,������� �������� �� ����� �������� .��������:���������� ���������(������), ��������  �����.
	/// </summary>
	/// <returns>���������� ����� ��������� ������. ��� car-1,ship-2,airplane-3,space_palne-4,motocycle-1 ��� ���  ��� ��������� ������� start � finish �� car</returns>
	int virtual _finish()=0;



};
/*!
\brief �������� ����� car

 ������ ����� ��� ������� ����� public ������������ , ��� ��� ��� �� ����� ���� ������ ���� ������� ����� ������� � ��������� ������������� ������.
	 \param int light transmission ������������������� ����� ������,��������� � private ������.
	 ��� ��������� ��������� ��������� � protected , ��� ��� ����� ���� ����� ��� �������� ������������ ����� �������� ������� � ��� ���� ������ ���� ������ ��� �� ��������.
	 \param string mark -- �����/������ ������(��������� ��� ��������� ������)
	 \param string number--������ ����� ������(���������)
	 \param int transmission--����������� �� ������ ������(�� ����� �������� ��������� ���� ��)
*/
class car :public virtual  vechile
{
private:
	int light_transmission;
	/// <summary>
	/// ������� ������� �� ������������� ����������������� , ������� ��������� � private ������ ��� ��� ��� �� ������ ������������ �������� �������  ������ ������.
	/// </summary>
	/// <param name="_is_rain">�������� �������� �� ��������� ������ , true-���� ����� false-����,������� ��� �������</param>
	void _use_wiper(bool _is_rain);
protected:
	string mark;
	string number;
	int transmission=0;
	/// <summary>
	/// ������� ������� �� ��������� ����-�������� ��� ����������.
	/// </summary>
	void _activate_stop_signals();
	/// <summary>
	/// ��������� �������� ,������� ����� ��� ������������.
	/// </summary>
	void _move();
public:
	/// <summary>
	/// ������� ��������� ������������ �������.
	/// </summary>
	/// <param name="transmission">�������� ��������� ����� �������� �� ����� ��������</param>
	void _change_a_transmission(int transmission);
	/// <summary>
	/// ��������� �� , ��� ���� ������ ��������(������� ������).
	/// </summary>
	/// <returns>���������� 1</returns>
	int _start();
	/// <summary>
	/// ������� ������� ������ ��������� ������ ���� �.�. ��������� ��� �� ���������� ��������
	/// </summary>
	/// <returns>true--��������� ���� ������ ��� �������� � ������ ����������;false-- ��������� ���� ������ ������ �� �������</returns>
	bool _use_accelarate_pedal();
	/// <summary>
	/// ������� ��������� ������ ����������(�������� ��������)
	/// </summary>
	/// <returns>true--��������� ���� ������ ��� �������� � ������ �����������;false-- ��������� ���� ������ ������ �� �������</returns>
	bool _use_brake_pedal();
	/// <summary>
	/// ������� ��������� ��������� ������ � ���������� ���������
	/// </summary>
	/// <returns>���������� 1</returns>
	int  _finish();
	car(string mark, string number, int light_transmission,int max_speed);
	
};
/*!
\brief �������� ����� ship

 ������ ����� ��� ������� ����� public ������������ , ��� ��� ��� �� ����� ���� ������ ���� ������� ����� ������� � ��������� ������������� ������.
	 � ��� ��������:
	 � private:
	 \param int displacement-- ������������� (���������� (������ ���) ����, ����������� ��������� ������).
	 \param  bool down_anchor-- ��������� ����� ������ �������;true--�������������� ��������� �.�. ����� ������, false--����� ������.
*/
class ship :public virtual vechile {
private:
	int displacement;
	bool down_anchor = true;
protected:
	/// <summary>
	/// ������� ��������� �������� ������� (������ ������� ��� ������ �������).
	/// </summary>
	void _move();

public:
	/// <summary>
	/// ������� ,������� �������� �� �������� ����� ,���� �� ������, � ���� ����� ������ , �� �� ����� �����.
	/// </summary>
	void  _use_anchor();
	/// <summary>
	/// ������� ,������� ������� �� ������ ��������(�.�. �������� ����� � ������ ���������)
	/// </summary>
	/// <returns>����������� 2</returns>
	int _start();
	/// <summary>
	/// ������� , ������� �������� �� ��������� �������(����� �����).
	/// </summary>
	/// <returns></returns>
	int _finish();
	ship(int displacement, int max_speed);

};
/*!
\brief �������� ����� airplane

 ������ ����� �������� �������� ������� ������ vechile.����� ��� ������� ����� private ������������,��� ��� ����� ���� ����� ���� ����������� ������ ���� ����������  � ����� ����� ���� � �� ������������ ������� �������� �� ����� ������.
	 � ��� ��������:
	 � private:
	 \param bool chassis--��������� �����; true--���� ����� �������� ,false--���� ����� ��������.
*/
class airplane :private virtual vechile {
private:
	bool chassis = true;
	/// <summary>
	/// ������� , ������� ��������� ������ �������� ��� �� ����� ������� ��� ��� ������� �������� �� ����������.
	/// </summary>
	void _use_flaps();
	/// <summary>
	/// ������� ��������� ��������� ������ ��������.
	/// </summary>
	void  _move();
	/// <summary>
	/// ������� ��������� �������(������ �������).
	/// </summary>
	/// <returns>���������� 3</returns>
	int  _start();
	/// <summary>
	/// ������� ��������� ������� ��������.
	/// </summary>
	/// <returns>���������� 3</returns>
	int  _finish();
	/// <summary>
	/// ������� �������� �� ��������� ����� ��� ������ � �������.
	/// </summary>
	void _use_chassis();
public:
	/// <summary>
	/// ������� ��������� ����� �������� (��� ������ �������� ����� � �.�.)
	///������� �������� ����������� ��� ����������� ������������ ������ ������� � �������� ������.
	/// </summary>
	void virtual _fly();
	airplane(int max_speed);
	airplane() {};
};
/*!
\brief �������� ����� space_plane

 ������ ����� �������� ����������� �������������� ������������ �� ������ vechile public ������������� � �� ������ airplane protected �������������.
 ������������� ������������ ����� ��� ,��� ��� ������� ������ �����  ������ ��� �� ������  vechile ,��� � �� ������ airplane , ������ ������ �� ������ airplane �� ������ ���� � public.

*/
class space_plane :public virtual vechile, protected virtual airplane
{
private:
	/// <summary>
	/// ������� �������� �� �������� ���� ������ ��������� ������� ,��� ��� �������� ������� ������� �� ���� ����������� � �������� � ��������� ����� � ���� �� ���� ������ �� ������
	/// </summary>
	void _mix();
	/// <summary>
	/// ������� �������� �� ��������� � ���������  ����������� �������.
	/// </summary>
	void _use_oxidant();
	/// <summary>
	/// ������� �������� �� ��������� � ���������  ��������� �������� �������.
	/// </summary>
	void _use_fuel();
	/// <summary>
	/// ������� �������� �� ����� ������������ ��������.
	/// </summary>
	void _fly();
public:
	/// <summary>
	/// ������� �������� �� ������ ������������ �������(�� ��� ���������� � ������).
	/// </summary>
	/// <returns>���������� 4</returns>
	int _start();
	/// <summary>
	/// ������� �������� �� ������������ ������ ����� �������, ����� ������� ����� �� ���������.
	/// </summary>
	void _detach_the_first_part();
	int _finish();
	space_plane(int max_speed);
};
/*!
\brief �������� ����� bicycle

 ������ ����� �������� �������� ������� �� ������������ ������ vechile
	
*/
class bicycle :public virtual vechile {
public:
	/// <summary>
	/// ������� �������� �� �������� �������(��������� ,������ ��������).
	/// </summary>
	void _use_pedals();
	/// <summary>
	/// ������� �������� �� ������������� ��������(� ������ ������ �� ������� ������� ��� ������).
	/// </summary>
	/// <param name="turn_right">�������� ������� �������� �� ����������� ���� ���� ������������.true--���� ������� �������;false--���� ������� ������</param>
	void  _use_damper(bool turn_right);
	/// <summary>
	/// ������� �������� �� ��������� �����.
	/// </summary>
	void _put_on_helm();
};
/*!
\brief �������� ����� motocycle

 ������ ����� �������� ����������� �������������� ������������ �� public ������������ ������� car � bicycle.
 ������ ������� ������ ������ �� ������� � ����� � ��� , ��� ������ ����� ��������� ��� ��������� �� ����� ������� �������.
 ������� ��� ������������ � �������� � ���������� motocycle ������� ���������� public � protected ������ car � bicycle.
*/
class motocycle :public  car,public  bicycle
{
public:
	motocycle(string mark, string number, int max_speed, int light_transmission = 0) :car(mark, number, light_transmission, max_speed) {}
};
