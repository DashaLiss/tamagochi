#include "Header.h"

Pet null = { 50,50,50,50 };
Pet os;

string savePet = "save.txt";
string sprate = "sprate.txt";
string name = "������";

void print(Pet a) {
	cout << "����� - " << a.hunger << "; ��������� -" << a.sleep << "; �����  - " << a.play << "; ������� - " << a.toilettes;
}
void saveNull()
{
	ofstream fout;
	fout.open(savePet, ofstream::trunc);
	if (!fout.is_open()) cout << "������ �������� �����" << endl;
	else {
		fout.write((char*)&null, sizeof(Pet));
	}
	fout.close();
}
void savePrint(){
	ifstream fin;
	fin.open(savePet);
	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		while (fin.read((char*)&os, sizeof(Pet))) {
			print(os);
		}
	}
	fin.close();
}
void printNormPet() {
	ifstream fin;
	fin.open(sprate);
	
	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 7; ++c) {
			cout << s << std::endl;
		}
		cout << endl;
		cout << name << " ��������� ���� �����...";
		cout << "\n\n-----------------------------------\n";
		savePrint();
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printHungryPet()
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 18; ++c) {
			if (c >= 8)
			cout << s << std::endl;
		}
		cout << endl;
		cout << name << " ����� �������� , �� � ��� ������� � ���� ������ ��� !\n��������� �� ��� ������� ��������� ������� �� ���";
		cout << "\n\n-----------------------------------\n";
		savePrint();
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printSatisfiedPet()
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 24; ++c) {
			if (c >= 19)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " ������� � ����������� � ����-�����, ��������� �� ����� ������� ";
		cout << "\n\n-----------------------------------\n";
		savePrint();
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}


int action()
{
	cout << "\n* ���� �� ������ ��������� ������� ������� - 1\n* ���� �� ������ ������� ����� ������� ������� - 2\n* ���� �� ������ �������� � �������� ������� - 3\n* ���� �� ������ �������� ������ ������� - 4\n* ���� �� ������ ����� �������(��������� ���� ������ �� ����������� ��� ���� �������� ���������) - 5\n";
	int enter;
	cout << "\n ��� ����� - ";
	cin >> enter;
	return enter;
}

