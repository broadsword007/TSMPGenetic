#include "Population.h"


Population::Population(vector<Chromosome*> val_chromosomes)
{
	for each (Chromosome* chromosome in val_chromosomes)
	{
		chromosomes.push_back(chromosome);
	}
}
void Population::selectBest(int number_of_best)
{
	//selecting best
}
Population* Population::performCrossover(string params)
{
	//perform crossover
	return NULL;
}
void Population::mutate(string params)
{
	// mutate each chromosome
}
Population* Population::mergePopulation(Population* another_population)
{
	for each (Chromosome* chromosome in another_population->getChromosomes())
	{
		chromosomes.push_back(chromosome);
	}
}
vector<Chromosome*> Population::getChromosomes()
{
	return chromosomes;
}
Population::~Population()
{
}
