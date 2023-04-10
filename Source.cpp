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
	//������ ����������
	pet = ReadSave();
	sleep = ReadSaveSleep();

	while (!end ) {
		if (!sleep) {
			if ((pet.hungry >= 50 && pet.hungry <= 80) && (pet.sleep >= 50 && pet.sleep <= 80) && (pet.play >= 50 && pet.play <= 80) && (pet.toilettes >= 50 && pet.toilettes <= 80)) {
				printNormPet(pet);
			}
			// ������ ��������� 
			else if (pet.toilettes < 50) {
				printDirtyPet(pet);
			}
			else if (pet.hungry < 50) {
				printHungryPet(pet);
			}
			// ������� ��������� 
			else if (pet.hungry > 80) {
				printSatisfiedPet(pet);

			}


			choose = action();

			// ������� ������� 

			TimeEnd = clock();

			if ((TimeEnd - TimeStart) / CLOCKS_PER_SEC > 10) {
				pet.hungry -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.toilettes -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				pet.sleep -= ((TimeEnd - TimeStart) / CLOCKS_PER_SEC) / 10;
				TimeStart = clock();
			}
			// ������ (�������� ���)
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
			cout << "���� �� ������ ��������� ������� ������� '1'";
			cout <<endl <<"���� �� ������ ����� ������� '2'"<<endl;
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
}