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
	selectivity_from_parents = 0;
	selectivity_from_children = 0;
}
void GeneticSearch::Solve(TSMProblem * problem)
{
	Population* currentPopulation = problem->getInitialPopulation(population_size);
	for (int i = 0; i < no_of_iterations; i++)
	{
		currentPopulation->selectBest(selectivity_from_parents);
		Population* offsprings= currentPopulation->performCrossover(crossoverMethod);

		/////////////////////////// Bullshit
		std::ostringstream ss;
		ss << mutation_rate;
		///////////////////////////

		offsprings->mutate(string(ss.str()));
		offsprings->selectBest(selectivity_from_children);
		currentPopulation->mergePopulation(offsprings);
	}
}
GeneticSearch::~GeneticSearch()
{
}
