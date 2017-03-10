#pragma once
#include <iostream>
#include <vector>
#include "TSMProblem.h"
#include "Population.h"
using namespace std;
class GeneticSearch
{
	int population_size;
	string selection_method;
	string crossoverMethod;
	float mutation_rate;
	int no_of_iterations;
	float max_fitness;

	////// determined by analysis
	int selectivity_from_parents;
	int selectivity_from_children;
public:
	GeneticSearch(int val_population_size, string val_selection_method,
		string val_crossoverMethod, float val_mutation_rate, int val_no_of_iterations, float val_max_fitness);
	void Solve(TSMProblem * problem);
	~GeneticSearch();
};

