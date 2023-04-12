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


	cout << "Если Вы хотите создать нового питомца - введите '1'\nЕсли Вы хотите продолжить - введите '2'\n";
	cin >> choose;
	if (choose == 1) {
		inventory = { 5, 10 };
		saveNull();
		pet = ReadSave();
		saveSleepOff();
		sleep = ReadSaveSleep();
		TimeStart = time(NULL);
		cout << "Как вы назовёте питомца ? - ";
		cin >> name;
		ofstream fout;
		fout.open("name.txt", ofstream::trunc);
		if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
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
			// низкие параметры 
			else if (pet.toilettes < 50 || pet.sleep < 50 || pet.play < 50) {
				printDirtyPet(pet, name);
			}
			else if (pet.hungry < 50) {
				printHungryPet(pet, name);
			}
			// высокие параметры 
			else if (pet.hungry > 80) {
				printSatisfiedPet(pet, name);

			}
			else if (pet.sleep > 80 || pet.toilettes > 80 || pet.play > 80) {
				printHappyPet(pet, name);
			}


			choose = action();

			// разница времени 

			TimeEnd = time(NULL);

			if (TimeEnd - TimeStart > 20) {
				pet.hungry -= (TimeEnd - TimeStart)/ 20;
				pet.toilettes -= (TimeEnd - TimeStart) / 20;
				pet.sleep -= (TimeEnd - TimeStart)/ 20;
				pet.play -= (TimeEnd - TimeStart) / 20;
				TimeStart = time(NULL);
			}
			// выборы 
			if (choose == 1) {
				if (inventory.eat > 0) {
					inventory.eat--;
					pet.hungry += 5;
					if (pet.hungry > 100) pet.hungry = 100;
				}
				else {
					cout << "У вас нет еды";
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
				cout << "Посчитайте сколько будет " << igra1 << " + " << igra2 << " = ";
				cin >> igra3;
				if (igra3 == igra1 + igra2) {
					cout << "Ура, это правильный ответ! " << name << " обрадовался!\n";
					pet.play += 5;
					if (igra3 % 3 == 0) {
						inventory.money += 3;
						cout << "Вы заработали 3 монетки !!!\n";
					}
					else if (igra3 % 3 == 1) {
						inventory.money += 4;
						cout << "Вы заработали 4 монетки !!!\n";
					}
					else if (igra3 % 3 == 2) {
						inventory.money += 5;
						cout << "Вы заработали 5 монеток !!!\n";
					}
					Sleep(5000);
				}
				else {
					cout << "О нет, это неправильный ответ! " << name << " растроился\n";
					pet.play -= 5;
				}
			}
			else if (choose == 4) {
				pet.toilettes += 5;
				if (pet.toilettes > 100) pet.hungry = 100;
			}
			
			else if (choose == 5) {
				system("cls");
				cout << "ммммммммммммммммммммммммммммммммммм\n-----------------------------------\n\n еда - " << inventory.eat <<"\n монетки - "<< inventory.money << "\n---------------------------------- -\n введите любой символ чтобы выйти - " ;
				cin >> close;
			}
			else if (choose == 6) {
				while (choose != 2) {
					system("cls");
					if (close == "dasha") { cout << "*В вашем инвентаре +1 еда*\n"; }
					else if (close == "dafsha") { cout << "У вас недостаточно денег((\n"; }
					cout << "ммммммммммммммммммммммммммммммммммм\n-----------------------------------\n\n еда - 5 монеток\n---------------------------------- -\n Чтобы купить еду  введите - '1'\n Чтобы выйти введите - '2'";
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
			cout << "Если вы хотите разбудить питомца нажмите '1'";
			cout <<endl <<"Если вы хотите выйти нажмите '2'"<<endl;
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

	//сохранение(статус - работает)
	ofstream fout;
	fout.open("save.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&pet, sizeof(Pet));
	}
	fout.close();

	fout.open("sleep.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&sleep, sizeof(bool));
	}
	fout.close();

	fout.open("time.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&TimeStart, sizeof(time_t));
	}
	fout.close();

	fout.open("Inventory.txt", ofstream::trunc);
	if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
	else {
		fout.write((char*)&inventory, sizeof(Inventory));
	}
	fout.close();
}