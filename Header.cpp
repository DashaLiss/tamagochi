#include "Header.h"

Pet null = { 81,50,50,50 };
Pet os;

string savePet = "save.txt";
string sprate = "sprate.txt";
string name = "������";

void print(Pet a) {
	cout << "������� - " << a.hungry << "; �������� -" << a.sleep << "; �����  - " << a.play << "; ������� - " << a.toilettes;
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
Pet ReadSave(){
	ifstream fin;
	fin.open(savePet);
	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		fin.read((char*)&os, sizeof(Pet));
	}
	fin.close();
	return os;
}

void printNormPet(Pet a) {
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
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printHungryPet(Pet a)
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
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printSatisfiedPet(Pet a)
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
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printDirtyPet(Pet a)
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "������ �������� �����" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 36; ++c) {
			if (c >= 25)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " ��.... "<< name <<" �� ����� ���� � ����� ������� ������� ";
		cout << "\n\n-----------------------------------\n";
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

int action()
{
	cout << "\n* ���� �� ������ ��������� ������� ,������� - 1\n* ���� �� ������ ������� ����� �������, ������� - 2\n* ���� �� ������ �������� � ��������, ������� - 3\n* ���� �� ������ �������� ������ ,������� - 4\n* ���� �� ������ �����, �������(��������� ���� ������ �� ����������� ��� ���� �������� ���������) - 5\n";
	int enter;
	cout << "\n ��� ����� - ";
	cin >> enter;
	return enter;
}


