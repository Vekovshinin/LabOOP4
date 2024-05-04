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
		cout << "������� �����������" << '\t' << this << endl;
		this->name = "��� ��";
		this->age = 0;
		this->predmet = "����� ��";
		this->mark = 0;
	}
	Student(string name, int age, string pr, int mark) {
		cout << "����������� ����������" << '\t' << endl;
		this->name = name;
		this->age = age;
		this->predmet = pr;
		this->mark = mark;
	}
	Student(const Student& a) {
		cout << "����� �����������" << '\t' << endl;
		this->name = a.name;
		this->age = a.age;
		this->predmet = a.predmet;
		this->mark = a.mark;
	}
	~Student() {
		cout << "����������" << '\t' << endl;
	}
	void GetInfo() {
		cout << name << endl;
		cout << age << "���" << endl;
		cout << predmet << endl;
		cout << "������: " << mark;
		if (mark < 3) cout << "������ �������������������";
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
		cout << "���������� ������������ = " << endl;
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
	Student pri0; // ������ ������ �������� ����������� �� ���������
	pri0.GetInfo();
	cout << endl << endl;
	Student pri("����", 17, "����������", 5);// ������ ������ � �����������
	pri.GetInfo();
	cout << endl << endl;
	Student pri2 ("����2", 18, "�����������", 5);
	pri2.GetInfo();
	cout << endl << endl;
	
	Student pri3(pri); // ������ ������������ �����������
	cout << pri3 << endl << endl;

	cin >> pri3;
	cout << endl << endl;
	Student pri4;
	pri4 = pri3; // ������ ���������� ������������ 
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
	cout << "������� ���: ";
	is >> a.name;
	cout << "������� �������: ";
	is >> a.age;
	cout << "������� �������: ";
	is >> a.predmet;
	cout << "������� ������: ";
	is >> a.mark;
	return is;
}


