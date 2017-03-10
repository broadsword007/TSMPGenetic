#pragma once
#include <iostream>
#include <vector>
#include "Population.h"
using namespace std;
class Chromosome
{
protected:
	float fitness;
	bool fitness_calculated;
public:
	virtual float getFitness() = 0;
	virtual Population* performCrossover(Chromosome* another_chromosome, string params)=0;
	virtual void mutate(string params);
	Chromosome();
	~Chromosome();
};

