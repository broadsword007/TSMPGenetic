#pragma once
#include <iostream>
#include <vector>
#include "City.h"
//#include "Chromosome.h"
class Chromosome;
using namespace std;
class Population
{
	vector<Chromosome*> chromosomes;
public:
	void selectBest(int number_of_best);
	Population* performCrossover(string params);
	void mutate(string params);
	Population(vector<Chromosome*> val_chromosomes);
	void mergePopulation(Population* another_population);
	vector<Chromosome*> getChromosomes();
	Chromosome* currentBest();
	~Population();
};

