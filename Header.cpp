#include "Header.h"

Pet null = { 70,70,70,70 };
Pet os;
bool sleep;
bool sleepOff = false;

string savePet = "save.txt";
string sprate = "sprate.txt";
string saveSleep = "sleep.txt";
string name = "Котёнок";

void print(Pet a) {
	cout << "сытость - " << a.hungry << "; бодрость -" << a.sleep << "; досуг  - " << a.play << "; гигиена - " << a.toilettes;
}
void saveNull()
{
	ofstream fout;
	fout.open(savePet, ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&null, sizeof(Pet));
	}
	fout.close();
}
void saveSleepOff() {
	ofstream fout;
	fout.open(saveSleep, ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&sleepOff, sizeof(bool));
	}
	fout.close();
}
Pet ReadSave(){
	ifstream fin;
	fin.open(savePet);
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fin.read((char*)&os, sizeof(Pet));
	}
	fin.close();
	return os;
}

bool ReadSaveSleep()
{
	ifstream fin;
	fin.open(saveSleep);
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fin.read((char*)&sleep, sizeof(bool));
	}
	fin.close();
	return sleep;
}

void printNormPet(Pet a) {
	ifstream fin;
	fin.open(sprate);
	
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 7; ++c) {
			cout << s << std::endl;
		}
		cout << endl;
		cout << name << " чувствует себя никак...";
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

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 18; ++c) {
			if (c >= 8)
			cout << s << std::endl;
		}
		cout << endl;
		cout << name << " очень голодный , но в его коробке с едой ничего нет !\nОсторожно он уже смотрит голодными глазами на вас";
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

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 24; ++c) {
			if (c >= 19)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " объелся и привратился в кото-шарик, осторожно он может улететь ";
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

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 36; ++c) {
			if (c >= 25)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " Фу.... "<< name <<" не хочет жить в такой грязной комнате ";
		cout << "\n\n-----------------------------------\n";
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printSleepPet(Pet a)
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 43; ++c) {
			if (c >= 37)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " видит радужные сны ";
		cout << "\n\n-----------------------------------\n";
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

int action()
{
	cout << "\n* Если вы хотите накормить питомца ,введите - 1\n* Если вы хотите уложить спать питомца, введите - 2\n* Если вы хотите поиграть с питомцем, введите - 3\n* Если вы хотите наверсти уборку ,введите - 4\n* Если вы хотите выйти, введите(осторожно выши данные не сохраняться при ином закрытие программы) - 5\n";
	int enter;
	cout << "\n Ваш выбор - ";
	cin >> enter;
	return enter;
}


