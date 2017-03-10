#pragma once
#include <iostream>
#include <vector>
#include "City.h"
#include "Population.h"
#include "Chromosome.h"
using namespace std;
class TSMProblem
{
	vector<City*> cities;
	void initialize_cities(string filename);
public:
	TSMProblem(string filename);
	Population* getInitialPopulation(int size);
	~TSMProblem();
};

