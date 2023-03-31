#pragma once
//////////////
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Pet {
	int hungry;
	int sleep;
	int play;
	int toilettes;
};


void print(Pet a);
void saveNull();

Pet save();
void printPet();

void printNormPet(Pet a);
void printHungryPet(Pet a);
void printSatisfiedPet(Pet a);

int action();
