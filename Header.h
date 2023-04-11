#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
#include <Windows.h>
using namespace std;


struct Pet {
	int hungry;
	int sleep;
	int play;
	int toilettes;
};

struct Inventory {
	int eat;
	int money;
};


void print(Pet a);
void saveNull();
void saveSleepOff();

Pet ReadSave();
string ReadName();
Inventory ReadInventory();
bool ReadSaveSleep();
void printPet();
time_t ReadSaveTime();

void printNormPet(Pet a, string name);
void printHungryPet(Pet a, string name);
void printSatisfiedPet(Pet a, string name);
void printDirtyPet(Pet a, string name);
void printSleepPet(Pet a, string name);
void printHappyPet(Pet a, string name);
void printDeadPet(Pet a, string name);

int action();
