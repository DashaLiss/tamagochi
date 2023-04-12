#include "Header.h"


int main()
{
	bool end = false;
	bool sleep;
	
	Pet pet;
	Inventory inventory;

	int choose;
	int igra1;
	int igra2;
	int igra3;
	
	time_t TimeEnd = time(NULL);
	time_t TimeStart;


	string name;
	string close;

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	cout << "���� �� ������ ������� ������ ������� - ������� '1'\n���� �� ������ ���������� - ������� '2'\n";
	cin >> choose;
	if (choose == 1) {
		inventory = { 5, 10 };
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
		inventory = ReadInventory();
		TimeStart = ReadSaveTime();
		pet = ReadSave();
		sleep = ReadSaveSleep();
		name = ReadName();
		if (!sleep) {
			pet.hungry -= (TimeEnd - TimeStart) / 20;
			pet.toilettes -= (TimeEnd - TimeStart) / 20;
			pet.sleep -= (TimeEnd - TimeStart) / 20;
			pet.play -= (TimeEnd - TimeStart) / 20;
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

			if (TimeEnd - TimeStart > 20) {
				pet.hungry -= (TimeEnd - TimeStart)/ 20;
				pet.toilettes -= (TimeEnd - TimeStart) / 20;
				pet.sleep -= (TimeEnd - TimeStart)/ 20;
				pet.play -= (TimeEnd - TimeStart) / 20;
				TimeStart = time(NULL);
			}
			// ������ 
			if (choose == 1) {
				if (inventory.eat > 0) {
					inventory.eat--;
					pet.hungry += 5;
					if (pet.hungry > 100) pet.hungry = 100;
				}
				else {
					cout << "� ��� ��� ���";
					Sleep(3500);
				}
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
					if (igra3 % 3 == 0) {
						inventory.money += 3;
						cout << "�� ���������� 3 ������� !!!\n";
					}
					else if (igra3 % 3 == 1) {
						inventory.money += 4;
						cout << "�� ���������� 4 ������� !!!\n";
					}
					else if (igra3 % 3 == 2) {
						inventory.money += 5;
						cout << "�� ���������� 5 ������� !!!\n";
					}
					Sleep(5000);
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
			
			else if (choose == 5) {
				system("cls");
				cout << "�����������������������������������\n-----------------------------------\n\n ��� - " << inventory.eat <<"\n ������� - "<< inventory.money << "\n---------------------------------- -\n ������� ����� ������ ����� ����� - " ;
				cin >> close;
			}
			else if (choose == 6) {
				while (choose != 2) {
					system("cls");
					if (close == "dasha") { cout << "*� ����� ��������� +1 ���*\n"; }
					else if (close == "dafsha") { cout << "� ��� ������������ �����((\n"; }
					cout << "�����������������������������������\n-----------------------------------\n\n ��� - 5 �������\n---------------------------------- -\n ����� ������ ���  ������� - '1'\n ����� ����� ������� - '2'";
					cin >> choose;
					if (choose == 1) {
						if (inventory.money >= 5) {
							close = "dasha";
							inventory.eat++;
							inventory.money -= 5;
						}
						else close = "dafsha";
					}
				}
			}
			else if (choose == 7)
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
				pet.sleep += (TimeEnd - TimeStart) / 20;
				if (pet.sleep > 100) pet.sleep = 100;
				pet.hungry -= (TimeEnd - TimeStart) / 20;
				pet.toilettes -= (TimeEnd - TimeStart) / 20;
				pet.play -= (TimeEnd - TimeStart) / 20;
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

	fout.open("Inventory.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "������ �������� �����" << endl;
	else {
		fout.write((char*)&inventory, sizeof(Inventory));
	}
	fout.close();
}