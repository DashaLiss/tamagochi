#include "Header.h"


int main()
{
	bool end = false;
	bool sleep;
	
	Pet pet;

	int choose;
	int TimeEnd = clock();
	int TimeStart;
	int igra1;
	int igra2;
	int igra3;

	string name;

	setlocale(LC_ALL, "ru");


	cout << "Если Вы хотите создать нового питомца - введите '1'\nЕсли Вы хотите продолжить - введите '2'\n";
	cin >> choose;
	if (choose == 1) {
		saveNull();
		pet = ReadSave();
		saveSleepOff();
		sleep = ReadSaveSleep();
		TimeStart = clock();
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

		TimeStart = ReadSaveTime();
		pet = ReadSave();
		sleep = ReadSaveSleep();
		name = ReadName();
		pet.hungry -= ((TimeStart - TimeEnd) / CLOCKS_PER_SEC) / 10;
		pet.toilettes -= ((TimeStart - TimeEnd) / CLOCKS_PER_SEC) / 10;
		pet.play -= ((TimeStart - TimeEnd) / CLOCKS_PER_SEC) / 10;
		if (!sleep) pet.sleep -= ((TimeStart - TimeEnd) / CLOCKS_PER_SEC) / 10;
	}


	while (!end ) {
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

			TimeEnd = clock();

			if ((TimeEnd - TimeStart) / CLOCKS_PER_SEC > 10) {
				pet.hungry -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.toilettes -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.sleep -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.play -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				TimeStart = clock();
			}
			// выборы 
			if (choose == 1) {
				pet.hungry += 5;
				if (pet.hungry > 100) pet.hungry = 100;
			}
		
			if (choose == 2) {
				sleep = true;
				TimeStart = clock();

			}
			if (choose == 3) {
				srand(time(NULL));
				igra1 = (rand() + 100) % 1000;
				igra2 = (rand() + 100) % 1000;
				cout << "-----------------------------------\n\n";
				cout << "Посчитайте сколько будет " << igra1 << " + " << igra2 << " = ";
				cin >> igra3;
				if (igra3 == igra1 + igra2) {
					cout << "Ура, это правильный ответ! " << name << " обрадовался!\n";
					pet.play += 5;
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
		
			else if (choose == 5)
				end = true;
		}
		while (sleep && !end) {
			printSleepPet(pet, name);
			cout << "Если вы хотите разбудить питомца нажмите '1'";
			cout <<endl <<"Если вы хотите выйти нажмите '2'"<<endl;
			cin >> choose;
			if (choose == 1) {
				sleep = false;
				TimeEnd = clock();
				pet.sleep += ((TimeStart - TimeEnd) / CLOCKS_PER_SEC) / 5;
				if (pet.sleep > 100) pet.sleep = 100;
			}
			else if (choose == 2) {
				end = true;
				ofstream fout;
				fout.open("time.txt", ofstream::trunc);
				if (!fout.is_open()) cout << "Ошибка открытия файла" << endl;
				else {
					fout.write((char*)&TimeStart, sizeof(int));
				}
				fout.close();
			}
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

}