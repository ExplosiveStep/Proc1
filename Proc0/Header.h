#ifndef HEADER
#define HEADER

#include <iostream>

using namespace std;

// Грузовик
struct truck {
	int cargo;// Грузоподъемность
	int engine;// Мощность двигателя
	int fuel_tank;// Объем топливного бака
};

// Автобус
struct bus {
	short int capacity;// Пассажировместимость
	int engine;// Мощность двигателя
	int fuel_tank;// Объем топливного бака
};

struct passenger_car {
	int max_speed;// Максимальная скорость
	int engine;// Мощность двигателя
	int fuel_tank;// Объем топливного бака
};

// Обобщение
struct transport {

	enum key { TRUCK, BUS, PASSENGER_CAR };
	key k;
	union {
		truck t;
		bus b;
		passenger_car p;
	};
};

// Контейнер
struct container
{
	int len;
	transport* cont;
	container* next;
	container* prev;
};

void Init(container* head, container* tail);

void Clear(container* head);

void In(container* head, container* tail, ifstream& ifst);

transport* In(ifstream& ifdt);

void In(passenger_car& p, ifstream& ist);

void In(truck& t, ifstream& ist);

void In(bus& b, ifstream& ist);

void Out(container* head, ofstream& ofst);

void Out(transport* s, ofstream& ofst);

void Out(truck& t, ofstream& ofst);

void Out(bus& b, ofstream& ofst);

void Out(passenger_car& p, ofstream& ofst);

double Gas_mil(transport* s);

void Sort(container* head);

void Limited_out(container* head, ofstream& ofst);

#endif