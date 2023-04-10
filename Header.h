#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
using namespace std;


struct Pet {
	int hungry;
	int sleep;
	int play;
	int toilettes;
};


void print(Pet a);
void saveNull();
void saveSleepOff();

Pet ReadSave();
bool ReadSaveSleep();
void printPet();

void printNormPet(Pet a);
void printHungryPet(Pet a);
void printSatisfiedPet(Pet a);
void printDirtyPet(Pet a);
void printSleepPet(Pet a);

int action();
