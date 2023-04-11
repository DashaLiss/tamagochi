#include "Header.h"

Pet null = { 70,70,70,70 };
Pet os;
Inventory inventory;

time_t tiime;

bool sleep;
bool sleepOff = false;

string savePet = "save.txt";
string saveInventory = "Inventory.txt";
string sprate = "sprate.txt";
string saveSleep = "sleep.txt";
string Savetime = "time.txt";
string saveName = "name.txt";
string name;

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

string ReadName()
{
	ifstream fin;
	fin.open(saveName);
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fin.read((char*)&name, sizeof(string));
	}
	fin.close();
	return name;
}

Inventory ReadInventory() {
	ifstream fin;
	fin.open(saveInventory);
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fin.read((char*)&inventory, sizeof(Inventory));
	}
	fin.close();
	return inventory;
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

time_t ReadSaveTime()
{
	ifstream fin;
	fin.open(Savetime);
	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fin.read((char*)&tiime, sizeof(time_t));
	}
	fin.close();
	return tiime;
}

void printNormPet(Pet a, string name) {
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

void printHungryPet(Pet a, string name)
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

void printSatisfiedPet(Pet a, string name)
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

void printDirtyPet(Pet a, string name)
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
		if (a.toilettes < 50) {
			cout << endl;
			cout << name << " Фу.... " << name << " не хочет жить в такой грязной комнате ";
		}
		if (a.sleep < 50) {
			cout << endl;
			cout << name << " весь на нервах, он очень хочет спать ";
		}
		if (a.sleep < 50) {
			cout << endl;
			cout << name << " очень напряжённый, он хочет поиграть ! ";
		}
		cout << "\n\n-----------------------------------\n";
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printSleepPet(Pet a, string name)
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 40; ++c) {
			if (c >= 37)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " видит радужные сны ";
		cout << "\n\n-----------------------------------\n";
	}
	fin.close();
}

void printHappyPet(Pet a, string name)
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 52; ++c) {
			if (c >= 41)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " очень счастливый ";
		cout << "\n\n-----------------------------------\n";
		print(a);
		cout << "\n-----------------------------------\n";
	}
	fin.close();
}

void printDeadPet(Pet a, string name)
{
	ifstream fin;
	fin.open(sprate);

	if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		cout << "-----------------------------------\n\n";
		ifstream in("sprate.txt");
		string s;
		for (int c = 1; getline(in, s) && c <= 67; ++c) {
			if (c >= 53)
				cout << s << std::endl;
		}
		cout << endl;
		cout << name << " уже не в этом мире.Ты так давно его не навещал.... ";
		cout << "\n\n-----------------------------------\n";
	}
	fin.close();
}

int action()
{
	cout << "\n* Если вы хотите накормить питомца ,введите - 1\n* Если вы хотите уложить спать питомца, введите - 2\n* Если вы хотите поиграть с питомцем, введите - 3\n* Если вы хотите наверсти уборку ,введите - 4\n* Если вы хотите открыть инвентарь, введите - 5\n* Если вы хотите открыть магазин, введите - 6\n* Если вы хотите выйти, введите(осторожно выши данные не сохраняться при ином закрытие программы) - 7\n";
	int enter;
	cout << "\n Ваш выбор - ";
	cin >> enter;
	return enter;
}


