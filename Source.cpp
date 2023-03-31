#include "Header.h"


int main()
{
	bool end = false;
	
	Pet pet;

	int choose;

	setlocale(LC_ALL, "ru");
	saveNull();
	pet = save();
	
	while (!end) {
		if ((pet.hungry >= 50 && pet.hungry <= 80) && (pet.sleep >= 50 && pet.sleep <= 80) && (pet.play >= 50 && pet.play <= 80) && (pet.toilettes >= 50 && pet.toilettes <= 80)) {
			printNormPet(pet);
		}
		else if (pet.hungry > 80) {
			printHungryPet(pet);
		}
		else if (pet.hungry < 50) {
			printSatisfiedPet(pet);
		}
		choose = action();
	}
}