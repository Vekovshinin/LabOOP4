#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	string name;
	int age;
};

class Student : Person {
	string predmet;
	int mark;
public:
	Student() {
		cout << "базовый конструктор" << '\t' << this << endl;
		this->name = "кто то";
		this->age = 0;
		this->predmet = "какой то";
		this->mark = 0;
	}
	Student(string name, int age, string pr, int mark) {
		cout << "конструктор параметров" << '\t' << endl;
		this->name = name;
		this->age = age;
		this->predmet = pr;
		this->mark = mark;
	}
	Student(const Student& a) {
		cout << "Копия конструктор" << '\t' << endl;
		this->name = a.name;
		this->age = a.age;
		this->predmet = a.predmet;
		this->mark = a.mark;
	}
	~Student() {
		cout << "Деструктор" << '\t' << endl;
	}
	void GetInfo() {
		cout << name << endl;
		cout << age << "лет" << endl;
		cout << predmet << endl;
		cout << "Оценка: " << mark;
		if (mark < 3) cout << "оценка неудовлетворительно";
	}
	void Setname(string& a) {
		this->name = a;
	}
	void Setage(int& a) {
		this->age = a;
	}
	void Setpredmet(string& a) {
		this->predmet = a;
	}
	void Setmark(int& a) {
		this->mark = a;
	}
	Student& operator = (const Student& a) {
		cout << "Перегрузка присваивания = " << endl;
		this->name = a.name;
		this->age = a.age;
		this->predmet = a.predmet;
		this->mark = a.mark;
		return *this;
	}

	friend ostream& operator << (ostream&, const Student&);
	friend istream& operator >> (istream& is, Student& a);



};

int main() {
	setlocale(LC_ALL, "Ru");
	system("chcp 1251 > null");
	Student pri0; // пример работы работает конструктор по умолчанию
	pri0.GetInfo();
	cout << endl << endl;
	Student pri("Иван", 17, "математика", 5);// пример работы с параметрами
	pri.GetInfo();
	cout << endl << endl;
	Student pri2 ("Иван2", 18, "информатика", 5);
	pri2.GetInfo();
	cout << endl << endl;
	
	Student pri3(pri); // пример конструктора копирования
	cout << pri3 << endl << endl;

	cin >> pri3;
	cout << endl << endl;
	Student pri4;
	pri4 = pri3; // пример перегрузки присваивания 
	cout << pri4;
	return 0;

}

ostream& operator<<(ostream& os, const Student& a)
{
	os << a.name << endl;
	os << a.age << endl;
	os << a.predmet << endl;
	os << a.mark << endl;
	return os;
}

istream& operator>>(istream& is, Student& a)
{
	cout << "Введите имя: ";
	is >> a.name;
	cout << "Введите возраст: ";
	is >> a.age;
	cout << "Введите предмет: ";
	is >> a.predmet;
	cout << "Введите оценку: ";
	is >> a.mark;
	return is;
}


