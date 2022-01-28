#include "pch.h"
#include "CppUnitTest.h"
#include "..\Proc0\Header.h"
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProcTests
{
	TEST_CLASS(ProcTests)
	{
	public:
		TEST_METHOD(In_Truck_test)// Тест проверки ввода информации о грузовике
		{
			ifstream ifst("../Proc0/InTruck.txt");
			truck t;
			In(t, ifst);
			Assert::AreEqual(t.cargo, 3000);
			Assert::AreEqual(t.engine, 120);
			Assert::AreEqual(t.fuel_tank, 50);
		}
		TEST_METHOD(In_Bus_test)// Тест проверки ввода информации об автобусе
		{
			ifstream ifst("../Proc0/InBus.txt");
			bus b;
			In(b, ifst);
			Assert::AreEqual(b.capacity, (short int)30);
			Assert::AreEqual(b.engine, 100);
			Assert::AreEqual(b.fuel_tank, 50);
		}
		TEST_METHOD(In_Passenger_car_test)// Тест проверки ввода информации о легковом автомобиле
		{
			ifstream ifst("../Proc0/InPassenger_car.txt");
			passenger_car p;
			In(p, ifst);
			Assert::AreEqual(p.max_speed, 150);
			Assert::AreEqual(p.engine, 120);
			Assert::AreEqual(p.fuel_tank, 50);
		}
		TEST_METHOD(In_transport_test)// Тест проверки ввода информации о машине
		{
			ifstream ifst("../Proc0/InTransport.txt");
			transport* ptr;
			ptr = In(ifst);
			Assert::AreEqual((int)ptr->k, (int)transport::key::TRUCK);
		}
		TEST_METHOD(Out_truck_test)// Тест проверки вывода информации о грузовике
		{
			truck t;
			t.cargo = 3000;
			t.engine = 140;
			t.fuel_tank = 50;
			ofstream ofst("../Proc0/OutTruck.txt");
			Out(t, ofst);
			ifstream ifst1("../Proc0/OutTruck.txt");
			ifstream ifst2("../Proc0/OutTruck2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Out_bus_test)// Тест проверки вывода информации об автобусе
		{
			bus b;
			b.capacity = 30;
			b.engine = 150;
			b.fuel_tank = 50;
			ofstream ofst("../Proc0/OutBus.txt");
			Out(b, ofst);
			ifstream ifst1("../Proc0/OutBus.txt");
			ifstream ifst2("../Proc0/OutBus2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Out_Passenger_car_test)// Тест проверки вывода информации о легковом автомобиле
		{
			passenger_car p;
			p.max_speed = 150;
			p.engine = 140;
			p.fuel_tank = 50;
			ofstream ofst("../Proc0/OutPassenger_car.txt");
			Out(p, ofst);
			ifstream ifst1("../Proc0/OutPassenger_car.txt");
			ifstream ifst2("../Proc0/OutPassenger_car2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(Out_transport_test)// Тест проверки вывода информации о машине
		{
			ifstream ifst("../Proc0/OutTransport3.txt");
			transport* ptr;
			ptr = In(ifst);
			ofstream ofst("../Proc0/OutTransport.txt");
			Out(ptr, ofst);
			ifstream ifst1("../Proc0/OutTransport.txt");
			ifstream ifst2("../Proc0/OutTransport2.txt");
			string test1;
			string test2;
			getline(ifst1, test1, '\0');
			getline(ifst2, test2, '\0');
			Assert::AreEqual(test1, test2);
		}
		TEST_METHOD(gas_mil_test)// Тест проверки функции
		{
			ifstream ifst("../Proc0/gas_mil.txt");
			transport* ptr;
			ptr = In(ifst);
			double par1 = 300;
			double par2 = gas_mil(ptr);
			Assert::AreEqual(par1, par2);
		}
		TEST_METHOD(init_test)// Тест проверки инициализации контейнера
		{
			container* head = new container;
			container* tail = new container;
			Init(head, tail);
			Assert::AreEqual(head->len, 0);
			Assert::AreEqual(tail->len, 0);
			Assert::IsNull(head->next);
			Assert::IsNull(head->prev);
			Assert::IsNull(head->cont);
			Assert::IsNull(tail->next);
			Assert::IsNull(tail->prev);
			Assert::IsNull(tail->cont);
		}
		TEST_METHOD(Incontainer_test)// Тест проверки ввода содержимого контейнера
		{
			ifstream ifst("../Proc0/Incontainer.txt");
			container* head = new container;
			container* tail = new container;
			Init(head, tail);
			In(head, tail, ifst);
			Assert::AreEqual(head->len, 3);
			Assert::AreEqual(tail->len, 3);
			Assert::AreEqual(head->cont->t.cargo, 1400);
			Assert::AreEqual(head->cont->t.engine, 120);
			Assert::AreEqual(head->cont->t.fuel_tank, 50);
			head = head->next;
			Assert::AreEqual(head->cont->b.capacity, (short int)30);
			Assert::AreEqual(head->cont->b.engine, 130);
			Assert::AreEqual(head->cont->b.fuel_tank, 60);
			head = head->next;
			Assert::AreEqual(head->cont->p.max_speed, 200);
			Assert::AreEqual(head->cont->p.engine, 150);
			Assert::AreEqual(head->cont->p.fuel_tank, 45);
		}
		TEST_METHOD(Outcontainer_test)// Тест проверки вывода содержимого контейнера
		{
			ifstream ifst("../Proc0/Outcontainer3.txt");
			container* head = new container;
			container* tail = new container;
			Init(head, tail);
			In(head, tail, ifst);
			ofstream ofst("../Proc0/Outcontainer.txt");
			Out(head, ofst);
			ifstream ofst1("../Proc0/Outcontainer.txt");
			ifstream ofst2("../Proc0/Outcontainer2.txt");
			string test1;
			string test2;
			getline(ofst1, test1, '\0');
			getline(ofst2, test2, '\0');
			Assert::AreEqual(test1, test2);

		}
		TEST_METHOD(Sort_test)// Тест проверки сортировки
		{
			ifstream ifst("../Proc0/Sort.txt");
			container* head = new container;
			container* tail = new container;
			Init(head, tail);
			In(head, tail, ifst);
			Sort(head);
			Assert::AreEqual(head->cont->p.engine,150);
			head = head->next;
			Assert::AreEqual(head->cont->b.engine, 130);
			head = head->next;
			Assert::AreEqual(head->cont->t.engine, 120);
		}
		TEST_METHOD(Limitedout_test)// Тест проверки ограниченного вывода
		{
			ifstream ifst("../Proc0/Limitedout3.txt");
			container* head = new container;
			container* tail = new container;
			Init(head, tail);
			In(head, tail, ifst);
			ofstream ofst("../Proc0/Limitedout.txt");
			Limited_out(head, ofst);
			ifstream ofst1("../Proc0/Limitedout.txt");
			ifstream ofst2("../Proc0/Limitedout2.txt");
			string test1;
			string test2;
			getline(ofst1, test1, '\0');
			getline(ofst2, test2, '\0');
			Assert::AreEqual(test1, test2);

		}
	};
}
