#include "GeneticSearch.h"
#include <sstream>
GeneticSearch::GeneticSearch(int val_population_size, string val_selection_method,
	string val_crossoverMethod, float val_mutation_rate, int val_no_of_iterations, float val_max_fitness)
{
	population_size = val_population_size;
	selection_method = val_selection_method;
	crossoverMethod = val_crossoverMethod;
	mutation_rate = val_mutation_rate;
	no_of_iterations = val_no_of_iterations;
	max_fitness = val_max_fitness;

	////// determined by analysis
	selectivity_from_parents = population_size/2;
	selectivity_from_children = population_size / 2;
}
Chromosome* GeneticSearch::Solve(TSMProblem * problem)
{
	Population* currentPopulation = problem->getInitialPopulation(population_size);
	cout << "Current fitness : ";
	currentPopulation->currentBest()->print();
	cout << endl;
	for (int i = 0; i < no_of_iterations; i++)
	{
		currentPopulation->selectBest(selectivity_from_parents, selection_method);
		Population* offsprings= currentPopulation->performCrossover(crossoverMethod);

		offsprings->mutate(mutation_rate);
		offsprings->selectBest(selectivity_from_children, selection_method);
		currentPopulation->mergePopulation(offsprings);
		cout << "ran for " << i + 1 << "th iteration successfully!" << endl;
	}
	return currentPopulation->currentBest();
}
GeneticSearch::~GeneticSearch()
{
}
