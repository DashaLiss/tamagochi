#include "Header.h"


int main()
{
	bool end = false;
	bool sleep;
	
	Pet pet;

	int choose;
	int igra1;
	int igra2;
	int igra3;
	
	time_t TimeEnd = time(NULL);
	time_t TimeStart;


	string name;

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	cout << "���� �� ������ ������� ������ ������� - ������� '1'\n���� �� ������ ���������� - ������� '2'\n";
	cin >> choose;
	if (choose == 1) {
		saveNull();
		pet = ReadSave();
		saveSleepOff();
		sleep = ReadSaveSleep();
		TimeStart = time(NULL);
		cout << "��� �� ������� ������� ? - ";
		cin >> name;
		ofstream fout;
		fout.open("name.txt", ofstream::trunc);
		if (!fout.is_open()) cout << "������ �������� �����" << endl;
		else {
			fout.write((char*)&name, sizeof(string));
		}
		fout.close();
	}
	else if (choose == 2) {

		TimeStart = ReadSaveTime();
		pet = ReadSave();
		sleep = ReadSaveSleep();
		name = ReadName();
		if (!sleep) {
			pet.hungry -= (TimeEnd - TimeStart) / 10;
			pet.toilettes -= (TimeEnd - TimeStart) / 10;
			pet.sleep -= (TimeEnd - TimeStart) / 10;
			pet.play -= (TimeEnd - TimeStart) / 10;
		}
	}


	while (!end ) {
		if (choose != 3)
			system("cls");
		if (!sleep) {
			if (pet.hungry <= 1 || pet.toilettes <= 1 || pet.play <= 1 || pet.sleep <= 1) {
				printDeadPet(pet,name);
				break;
			}
			else if ((pet.hungry >= 50 && pet.hungry <= 80) &&  (pet.toilettes >= 50 && pet.toilettes <= 80) && (pet.sleep >= 50 && pet.sleep <= 80) && (pet.play >= 50 && pet.play <= 80)) {
				printNormPet(pet, name);
			}
			// ������ ��������� 
			else if (pet.toilettes < 50 || pet.sleep < 50 || pet.play < 50) {
				printDirtyPet(pet, name);
			}
			else if (pet.hungry < 50) {
				printHungryPet(pet, name);
			}
			// ������� ��������� 
			else if (pet.hungry > 80) {
				printSatisfiedPet(pet, name);

			}
			else if (pet.sleep > 80 || pet.toilettes > 80 || pet.play > 80) {
				printHappyPet(pet, name);
			}


			choose = action();

			// ������� ������� 

			TimeEnd = time(NULL);

			if (TimeEnd - TimeStart > 10) {
				pet.hungry -= (TimeEnd - TimeStart)/ 10;
				pet.toilettes -= (TimeEnd - TimeStart) / 10;
				pet.sleep -= (TimeEnd - TimeStart)/ 10;
				pet.play -= (TimeEnd - TimeStart) / 10;
				TimeStart = time(NULL);
			}
			// ������ 
			if (choose == 1) {
				pet.hungry += 5;
				if (pet.hungry > 100) pet.hungry = 100;
			}
		
			if (choose == 2) {
				sleep = true;
				TimeStart = time(NULL);

			}
			if (choose == 3) {
				system("cls");
				srand(time(NULL));
				igra1 = (rand() + 100) % 1000;
				igra2 = (rand() + 100) % 1000;
				cout << "-----------------------------------\n\n";
				cout << "���������� ������� ����� " << igra1 << " + " << igra2 << " = ";
				cin >> igra3;
				if (igra3 == igra1 + igra2) {
					cout << "���, ��� ���������� �����! " << name << " �����������!\n";
					pet.play += 5;
				}
				else {
					cout << "� ���, ��� ������������ �����! " << name << " ����������\n";
					pet.play -= 5;
				}
			}
			else if (choose == 4) {
				pet.toilettes += 5;
				if (pet.toilettes > 100) pet.hungry = 100;
			}
		
			else if (choose == 5)
				end = true;
		}
		while (sleep && !end) {
			system("cls");
			printSleepPet(pet, name);
			cout << "���� �� ������ ��������� ������� ������� '1'";
			cout <<endl <<"���� �� ������ ����� ������� '2'"<<endl;
			cin >> choose;
			if (choose == 1) {
				sleep = false;
				TimeEnd = time(NULL);
				pet.sleep += (TimeEnd - TimeStart) / 10;
				if (pet.sleep > 100) pet.sleep = 100;
				pet.hungry -= (TimeEnd - TimeStart) / 10;
				pet.toilettes -= (TimeEnd - TimeStart) / 10;
				pet.play -= (TimeEnd - TimeStart) / 10;
			}
			else if (choose == 2) 
				end = true;
		}
	}

	//����������(������ - ��������)
	ofstream fout;
	fout.open("save.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "������ �������� �����" << endl;
	else {
		fout.write((char*)&pet, sizeof(Pet));
	}
	fout.close();

	fout.open("sleep.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "������ �������� �����" << endl;
	else {
		fout.write((char*)&sleep, sizeof(bool));
	}
	fout.close();

	fout.open("time.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "������ �������� �����" << endl;
	else {
		fout.write((char*)&TimeStart, sizeof(time_t));
	}
	fout.close();

}