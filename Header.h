#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Pet {
	int hunger;
	int sleep;
	int play;
	int toilettes;
};


void print(Pet a);
void saveNull();

void savePrint();
void printPet();

void printNormPet();
void printHungryPet();
void printSatisfiedPet();

int action();
