/*!
\file
\brief Файл , в котором хранятся тесты,проверяющие правильность написания кода.


Суть тестов заключается в том , чтобы проверить правильно ли выполняется наследование для дочерних классов vechile.
*/
#include "CppUnitTest.h"
#include "Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/// <summary>
/// Функция для проверки наследования в конкретном классе.В ней написаны две функции , которые передаются по наследованию как public для дочерних классов (car,ship,motocycle)
///Каждая функция _start() и _finish() возвращает значение, которое чисто указывает номер дочернего класса для car(1) ship(2) и т.д. и т.п. 
/// </summary>
/// <param name="a">параметр а -это у нас объект нашего виртуального класса , но который будет по сути любым дочерним классом кроме самого объекта класса vechile</param>
/// <returns>Возвращает сумму номеров наших этих классов умноженных на 2. </returns>
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
		///\details Test1 проверяет на правильно ли наследуются функции от class vechile для class car.Если все наследуется правильно , то в итоге у нас возращается 2.
		/// </summary>
		TEST_METHOD(TestMethod1)
		{
			car one("mazda", "5690 HA-2", 70, 230);
			Assert::IsTrue(2==func_for_test(one));
			
			
		
		}
		/// <summary>
		/// Test2.
		///\details Test2 проверяет на правильно ли наследуются функции от class vechile для class ship.Если все наследуется правильно , то в итоге у нас возращается 4.
		/// </summary>
		TEST_METHOD(TestMethod2)
		{
			ship ecminec(70, 100);
			Assert::IsTrue(4==func_for_test(ecminec));
		}
		/// <summary>
		/// Test3.
		///\details В Test3 мы проверяем правильно ли все наследуется через public функцию _fly . Так как у нас private наследование ,мы не можем исползьвать функцию ,которая использовалась в Test1 и Test2.
		/// </summary>
		TEST_METHOD(TestMethod3)
		{
			airplane test(400);
			test._fly();
		}
		/// <summary>
		/// Test4.
		///\details Test4 проверяет на правильно ли наследуются функции от class vechile для class ship.Если все наследуется правильно , то в итоге у нас возращается 8.
		/// </summary>
		TEST_METHOD(TestMethod4)
		{
			space_plane test(3000);
			Assert::IsTrue(8==func_for_test(test));
		}
		/// <summary>
		/// Test5.
		///\details В Test5 так как  class motocycle наследует функцию _start() и _finish() от class car , то в резуельтате у нас должно вернуться 2.
		/// </summary>
		TEST_METHOD(TestMethod5)
		{
			motocycle test("s", "1234-ha-32", 150);
			Assert::IsTrue(2==func_for_test(test));
		}
		
	};
}
