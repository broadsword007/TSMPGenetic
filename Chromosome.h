#pragma once
#include <iostream>
#include <vector>
//#include "Population.h"
class Population;

using namespace std;
class Chromosome
{
protected:
	float fitness;
	bool fitness_calculated;
public:
	virtual float getFitness() = 0;
	virtual Population* performCrossover(Chromosome* another_chromosome, string params)=0;
	virtual void mutate(int mutation_rate)=0;
	Chromosome();
	~Chromosome();
};

