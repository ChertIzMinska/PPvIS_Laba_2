/*!
\file
\brief ���� , � ������� �������� �����,����������� ������������ ��������� ����.


���� ������ ����������� � ��� , ����� ��������� ��������� �� ����������� ������������ ��� �������� ������� vechile.
*/
#include "CppUnitTest.h"
#include "Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/// <summary>
/// ������� ��� �������� ������������ � ���������� ������.� ��� �������� ��� ������� , ������� ���������� �� ������������ ��� public ��� �������� ������� (car,ship,motocycle)
///������ ������� _start() � _finish() ���������� ��������, ������� ����� ��������� ����� ��������� ������ ��� car(1) ship(2) � �.�. � �.�. 
/// </summary>
/// <param name="a">�������� � -��� � ��� ������ ������ ������������ ������ , �� ������� ����� �� ���� ����� �������� ������� ����� ������ ������� ������ vechile</param>
/// <returns>���������� ����� ������� ����� ���� ������� ���������� �� 2. </returns>
int func_for_test(vechile& a)
{
	int res = 0;
	res+=a._start();
	res+=a._finish();
	return res;
     
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		/// <summary>
		/// Test1.
		///\details Test1 ��������� �� ��������� �� ����������� ������� �� class vechile ��� class car.���� ��� ����������� ��������� , �� � ����� � ��� ����������� 2.
		/// </summary>
		TEST_METHOD(TestMethod1)
		{
			car one("mazda", "5690 HA-2", 70, 230);
			Assert::IsTrue(2==func_for_test(one));
			
			
		
		}
		/// <summary>
		/// Test2.
		///\details Test2 ��������� �� ��������� �� ����������� ������� �� class vechile ��� class ship.���� ��� ����������� ��������� , �� � ����� � ��� ����������� 4.
		/// </summary>
		TEST_METHOD(TestMethod2)
		{
			ship ecminec(70, 100);
			Assert::IsTrue(4==func_for_test(ecminec));
		}
		/// <summary>
		/// Test3.
		///\details � Test3 �� ��������� ��������� �� ��� ����������� ����� public ������� _fly . ��� ��� � ��� private ������������ ,�� �� ����� ����������� ������� ,������� �������������� � Test1 � Test2.
		/// </summary>
		TEST_METHOD(TestMethod3)
		{
			airplane test(400);
			test._fly();
		}
		/// <summary>
		/// Test4.
		///\details Test4 ��������� �� ��������� �� ����������� ������� �� class vechile ��� class ship.���� ��� ����������� ��������� , �� � ����� � ��� ����������� 8.
		/// </summary>
		TEST_METHOD(TestMethod4)
		{
			space_plane test(3000);
			Assert::IsTrue(8==func_for_test(test));
		}
		/// <summary>
		/// Test5.
		///\details � Test5 ��� ���  class motocycle ��������� ������� _start() � _finish() �� class car , �� � ����������� � ��� ������ ��������� 2.
		/// </summary>
		TEST_METHOD(TestMethod5)
		{
			motocycle test("s", "1234-ha-32", 150);
			Assert::IsTrue(2==func_for_test(test));
		}
		
	};
}
