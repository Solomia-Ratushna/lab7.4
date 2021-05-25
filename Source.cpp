#include <Windows.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Friend
{
	string fname, lname;
	int telephone;
	int birthday[3];

	friend ostream& operator<<(ostream& out, const Friend& f)
	{
		out << "Прізвище та імя: " << f.lname << " " << f.fname << endl;
		out << "Номер телефону: " << f.telephone << endl;
		out << "Дата народження: " << f.birthday[0] << "." << f.birthday[1] << "." << f.birthday[2] << endl;
		return out;
	}

	bool setName(istream& in)
	{
		cout << "Введіть прізвище та імя (через пробіл): "; in >> lname >> fname;
		return true;
	}

	bool setTelephone(istream& in)
	{
		cout << "Введіть номер: "; in >> telephone;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Помилка вводу! " << endl;
			return false;
		}
		if (telephone < 0)
		{
			cout << "Номер повинен бути додатнім! " << endl;
			return false;
		}
		return true;
	}

	bool setbirthday(istream& in)
	{
		cout << "Введіть дату народження (наприклад 22 3 2002): "; in >> birthday[0] >> birthday[1] >> birthday[2];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Помилка вводу! " << endl;
			return false;
		}

		if (birthday[0] > 31 || birthday[0] < 1)
		{
			cout << "День народження повинен бути в діапазоні від 1 до 31! " << endl;
			return false;
		}
		if (birthday[1] > 12 || birthday[1] < 1)
		{
			cout << "Місяць народження повинен бути в діапазоні від 1 до 12! " << endl;
			return false;
		}
		if (birthday[2] > 2021 || birthday[2] < 1800)
		{
			cout << "Рік народження повинен бути в діапазоні від 1800 до 2021! " << endl;
			return false;
		}
		return true;
	}

};

void addNote(map<int, Friend>& nb)
{
	Friend f;
	while (!f.setName(cin))
	{
	}

	while (!f.setTelephone(cin))
	{
	}

	while (!f.setbirthday(cin))
	{
	}

	nb.emplace(nb.size(), f);
}



void output(map<int, Friend>& nb)
{
	cout << "-------------------------------------------------------" << endl;
	for (pair<int, Friend > curElem : nb)
	{
		cout << "Друг №" << curElem.first + 1 << endl;
		cout << curElem.second;
		cout << "-------------------------------------------------------" << endl;
	}
}

void findFriend(map<int, Friend>& nb)
{
	string name;
	cout << "Введіть прізвище друга: "; cin >> name;
	bool flag = true;
	for (pair<int, Friend > curElem : nb)
	{
		if (curElem.second.lname == name)
		{
			cout << "Номер телефону: " << curElem.second.telephone << endl;
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << "Не було знайденно друга!" << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<int, Friend> notebook;
	int answer = -1;
	do
	{
		cout << "[1] Додати запис. " << endl;
		cout << "[2] Відобразити записи. " << endl;
		cout << "[3] Шукати за прізвищем. " << endl;
		cout << "[0] Вихід. " << endl;
		do
		{
			cout << "Оберіть дію: ";
			cin >> answer;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				answer = -1;
			}
		} while (answer < 0 || answer > 5);

		switch (answer)
		{
		case 1: addNote(notebook); break;
		case 2: output(notebook); break;
		case 3: findFriend(notebook); break;
		default:
			break;
		}
	} while (answer);
	return 0;
}