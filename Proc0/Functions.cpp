#include "Header.h"
#include <fstream>
#include <string>

#define KEY 0// Выбор ТС для лимитированного вывыда [0..2]

// Инициализация контейнера
void Init(container* head, container* tail) {
    head->len = tail->len = 0;
    head->cont = tail->cont = NULL;
    head->next = tail->next = NULL;
    head->prev = tail->prev = NULL;
}

// Очистка контейнера от элементов
void Clear(container* head) {
    int len = head->len;
    container* temp = head;
    for (int i = 0; i < len; i++) {// Очистка транспорта
        delete temp->cont;
        temp->len = 0;
        temp = temp->next;
    }
    for (int i = 0; i < len; i++) {// Очистка контейнеров
        temp = head->next;
        delete head;
        head = temp;
    }
}

// Ввод содержимого контейнера из указанного потока
void In(container* head, container* tail, ifstream& ifst) {
    container* temp;
    int Len = 0;
    while (!ifst.eof()) {
        switch (Len)
        {
        case 0:// Для 1-го элемента
            if ((head->cont = In(ifst))) {
                Len++;
            }
            break;

        case 1:// Для 2-ух элементов
            if ((tail->cont = In(ifst))) {
                head->next = tail;
                head->prev = tail;
                tail->next = head;
                tail->prev = head;
                Len++;
            }
            break;

        default:// Для более 2-ух элементов
            temp = new container;
            temp->next = NULL;
            temp->prev = NULL;
            if ((temp->cont = In(ifst))) {
                tail->next = temp;
                head->prev = temp;
                temp->next = head;
                temp->prev = tail;
                tail = temp;
                Len++;
            }
            else { delete temp; }
            break;
        }
        temp = head;
        for (int i = 0; i < Len; i++) {// Обновление значения "len" в каждом контейнере
            temp->len = Len;
            temp = temp->next;
        }
    }
}

// Ввод параметров из файла
transport* In(ifstream& ifst)
{
    transport* sp;
    string str = "";
    getline(ifst, str);
    if ((str != "1") && (str != "2") && (str != "3")) {// Если символ не 1,2,3
        if (ifst.peek() == EOF) {// Если конец файла
            return 0;
        }
        else {
            cout << "Input data is incomplete or incorrect!";
            system("pause");
            exit(1);
        }
    }
    int k = atoi(str.c_str());
    switch (k)
    {
    case 1:
        sp = new transport;
        sp->k = transport::key::TRUCK;
        In(sp->t, ifst);
        return sp;
    case 2:
        sp = new transport;
        sp->k = transport::key::BUS;
        In(sp->b, ifst);
        return sp;
    case 3:
        sp = new transport;
        sp->k = transport::key::PASSENGER_CAR;
        In(sp->p, ifst);
        return sp;
    default:
        cout << "Incorrect transport!" << endl;
        system("pause");
        exit(1);
    }
}

// Ввод параметров грузовика из файла
void In(truck& t, ifstream& ifst)
{
    string str = "";
    string numbers = "0123456789";
    int flag = 0;// Вспомогательная переменная/количество циклов
    while (flag != 3) {
        getline(ifst, str);
        if (str == "") {// Если пустая строка
            cout << "Input data is incomplete!";
            system("pause");
            exit(1);
        }
        if (str[0] == '0') {// Если строка начинается с символа '0'
            cout << "Input data is incorrect!";
            system("pause");
            exit(1);
        }
        for (int i = 0; i < str.length(); i++) {// Если в строке есть символы помимо цифр
            
            if (numbers.find(str[i]) == -1) {
                cout << "Input data is incorrect!";
                system("pause");
                exit(1);
            }
        }
        switch (flag)
        {
        case 0:
            t.cargo = atoi(str.c_str());
            break;
        case 1:
            t.engine = atoi(str.c_str());
            break;
        case 2:
            t.fuel_tank = atoi(str.c_str());
            break;
        }
        flag++;
    }
}

// Ввод параметров автобуса из файла
void In(bus& b, ifstream& ifst) {
    string str = "";
    string numbers = "0123456789";
    int flag = 0;// Вспомогательная переменная/количество циклов
    while (flag != 3)
    {
        getline(ifst, str);
        if (str == "") {// Если пустая строка
            cout << "Input data is incomplete!";
            exit(1);
        }
        if (str[0] == '0') {// Если строка начинается с символа '0'
            cout << "Input data is incorrect!";
            exit(1);
        }
        for (int i = 0; i < str.length(); i++) {// Если в строке есть символы помимо цифр
            
            if (numbers.find(str[i]) == -1) {
                cout << "Input data is incorrect!";
                exit(1);
            }
        }
        switch (flag)
        {
        case 0:
            b.capacity = atoi(str.c_str());
            break;
        case 1:
            b.engine = atoi(str.c_str());
            break;
        case 2:
            b.fuel_tank = atoi(str.c_str());
            break;
        }
        flag++;
    }
}

// Ввод параметров легкового автомобиля из файла
void In(passenger_car& p, ifstream& ifst) {
    string str = "";
    string numbers = "0123456789";
    int flag = 0;// Вспомогательная переменная/количество циклов
    while (flag != 3)
    {
        getline(ifst, str);
        if (str == "") {// Если пустая строка
            cout << "Input data is incomplete!";
            exit(1);
        }
        if (str[0] == '0') {// Если строка начинается с символа '0'
            cout << "Input data is incorrect!";
            exit(1);
        }
        for (int i = 0; i < str.length(); i++) {// Если в строке есть символы помимо цифр
            
            if (numbers.find(str[i]) == -1) {
                cout << "Input data is incorrect!";
                exit(1);
            }
        }
        switch (flag)
        {
        case 0:
            p.max_speed = atoi(str.c_str());
            break;
        case 1:
            p.engine = atoi(str.c_str());
            break;
        case 2:
            p.fuel_tank = atoi(str.c_str());
            break;
        }
        flag++;
    }
}

// Вывод параметров в файл
void Out(container* head, ofstream& ofst) {
    container* temp = head;
    int len = temp->len;
    ofst << "Container contains " << head->len
        << " elements." << endl;
    for (int i = 0; i < len; i++) {
        ofst << i << ": ";
        Out((temp->cont), ofst);
        temp = temp->next;
    }
}

// Вывод параметров текущего транспорта в поток
void Out(transport* s, ofstream& ofst) {
    switch (s->k)
    {
    case transport::key::BUS:
        Out(s->b, ofst);
        break;
    case transport::key::TRUCK:
        Out(s->t, ofst);
        break;
    case transport::key::PASSENGER_CAR:
        Out(s->p, ofst);
        break;
    default:
        cout << "Incorrect transport!" << endl;
        system("pause");
        exit(1);
    }
}

// Вывод параметров грузовика в файл
void Out(truck& t, ofstream& ofst)
{
    ofst << "It is truck: cargo = " << t.cargo << ", engine = "
        << t.engine << ", fuel_tank = " << t.fuel_tank << endl;
}

// Вывод параметров автобуса в файл
void Out(bus& b, ofstream& ofst) {
    ofst << "It is bus: capacity = " << b.capacity << ", engine = "
        << b.engine << ", fuel_tank = " << b.fuel_tank << endl;
}
 
// Вывод параметров легкового автомобиля в файл
void Out(passenger_car& p, ofstream& ofst) {
    ofst << "It is passenger car: max_speed = " << p.max_speed << ", engine = "
        << p.engine << ", fuel_tank = " << p.fuel_tank << endl;
}

// Функция возвращающая параметр, на основе которого производится сортировка
double Gas_mil(transport* s)
{
    switch (s->k)
    {
    case 0:
        return s->t.engine * 2;
        break;
    case 1:
        return s->b.engine * 2;
        break;
    case 2:
        return s->p.engine * 2;
        break;
    default:
        cout << "Incorrect transport!" << endl;
        system("pause");
        exit(1);
    }
}

// Сортировка
void Sort(container* head)
{
    if ((head->len) > 1) {
        container* First = head;
        container* Second = head->next;
        container* Temp = new container;
        int len = head->len;
        for (int i = 0; i < len - 1; i++) {

            for (int j = 0; j < len - i - 1; j++) {

                if (Gas_mil(First->cont) < Gas_mil(Second->cont)) {
                    Temp->cont = First->cont;
                    First->cont = Second->cont;
                    Second->cont = Temp->cont;
                }

                Second = Second->next;
            }
            First = First->next;
            Second = First->next;
        }
        delete Temp;
    }
}

// Ограниченный вывод ТС
void Limited_out(container* head, ofstream& ofst)
{
    int len = head->len;
    container* temp = head;
    for (int i = 0; i < len; i++)
    {
        if ((temp->cont->k == KEY) && (temp->cont->k == 0)) {
            Out(temp->cont->t, ofst);
        }

        if ((temp->cont->k == KEY) && (temp->cont->k == 1)) {
            Out(temp->cont->b, ofst);
        }

        if ((temp->cont->k == KEY) && (temp->cont->k == 2)) {
            Out(temp->cont->p, ofst);
        }
        temp = temp->next;
    }
}