#include "Header.h"


int main()
{
	bool end = false;
	bool sleep;
	
	Pet pet;

	int choose;
	int TimeStart = clock();
	int TimeEnd;

	setlocale(LC_ALL, "ru");
	saveNull(); 
	//saveSleepOff(); 
	//ручное сохранение
	pet = ReadSave();
	sleep = ReadSaveSleep();

	while (!end ) {
		if (!sleep) {
			if ((pet.hungry >= 50 && pet.hungry <= 80) && (pet.sleep >= 50 && pet.sleep <= 80) && (pet.play >= 50 && pet.play <= 80) && (pet.toilettes >= 50 && pet.toilettes <= 80)) {
				printNormPet(pet);
			}
			// низкие параметры 
			else if (pet.toilettes < 50) {
				printDirtyPet(pet);
			}
			else if (pet.hungry < 50) {
				printHungryPet(pet);
			}
			// высокие параметры 
			else if (pet.hungry > 80) {
				printSatisfiedPet(pet);

			}


			choose = action();

			// разница времени 

			TimeEnd = clock();

			if ((TimeEnd - TimeStart) / CLOCKS_PER_SEC > 10) {
				pet.hungry -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.toilettes -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.sleep -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				TimeStart = clock();
			}
			// выборы (доделать сон)
			if (choose == 1) {
				pet.hungry += 5;
				if (pet.hungry > 100) pet.hungry = 100;
			}
		
			if (choose == 2) {
				sleep = true;
				TimeStart = clock();

			}
			else if (choose == 4) {
				pet.toilettes += 5;
				if (pet.toilettes > 100) pet.hungry = 100;
			}
		
			else if (choose == 5)
				end = true;
		}
		while (sleep && !end) {
			printSleepPet(pet);
			cout << "Если вы хотите разбудить питомца нажмите '1'";
			cout <<endl <<"Если вы хотите выйти нажмите '2'"<<endl;
			cin >> choose;
			if (choose == 1) {
				sleep = false;
				TimeEnd = clock();
				pet.sleep += ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 5;
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
}