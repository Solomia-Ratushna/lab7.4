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
		out << "������� �� ���: " << f.lname << " " << f.fname << endl;
		out << "����� ��������: " << f.telephone << endl;
		out << "���� ����������: " << f.birthday[0] << "." << f.birthday[1] << "." << f.birthday[2] << endl;
		return out;
	}

	bool setName(istream& in)
	{
		cout << "������ ������� �� ��� (����� �����): "; in >> lname >> fname;
		return true;
	}

	bool setTelephone(istream& in)
	{
		cout << "������ �����: "; in >> telephone;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� �����! " << endl;
			return false;
		}
		if (telephone < 0)
		{
			cout << "����� ������� ���� �������! " << endl;
			return false;
		}
		return true;
	}

	bool setbirthday(istream& in)
	{
		cout << "������ ���� ���������� (��������� 22 3 2002): "; in >> birthday[0] >> birthday[1] >> birthday[2];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� �����! " << endl;
			return false;
		}

		if (birthday[0] > 31 || birthday[0] < 1)
		{
			cout << "���� ���������� ������� ���� � ������� �� 1 �� 31! " << endl;
			return false;
		}
		if (birthday[1] > 12 || birthday[1] < 1)
		{
			cout << "̳���� ���������� ������� ���� � ������� �� 1 �� 12! " << endl;
			return false;
		}
		if (birthday[2] > 2021 || birthday[2] < 1800)
		{
			cout << "г� ���������� ������� ���� � ������� �� 1800 �� 2021! " << endl;
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
		cout << "���� �" << curElem.first + 1 << endl;
		cout << curElem.second;
		cout << "-------------------------------------------------------" << endl;
	}
}

void findFriend(map<int, Friend>& nb)
{
	string name;
	cout << "������ ������� �����: "; cin >> name;
	bool flag = true;
	for (pair<int, Friend > curElem : nb)
	{
		if (curElem.second.lname == name)
		{
			cout << "����� ��������: " << curElem.second.telephone << endl;
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << "�� ���� ��������� �����!" << endl;
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
		cout << "[1] ������ �����. " << endl;
		cout << "[2] ³��������� ������. " << endl;
		cout << "[3] ������ �� ��������. " << endl;
		cout << "[0] �����. " << endl;
		do
		{
			cout << "������ ��: ";
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