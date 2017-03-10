#pragma once
#include <iostream>
#include <vector>
#include "City.h"
#include "Population.h"
#include "Chromosome.h"
using namespace std;
class TSMPChromosome: public Chromosome
{
	vector<City*> cities_order;
public:
	TSMPChromosome(vector<City*> val_cities_order);
	float getFitness();
	Population* performCrossover(Chromosome* another_chromosome, string params);
	void mutate(string params);
	~TSMPChromosome();
};

