#include "Population.h"
#include "Chromosome.h"

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
void Population::mergePopulation(Population* another_population)
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
Chromosome* Population::currentBest()
{
	Chromosome* best;
	for each (Chromosome* chromosome in chromosomes)
	{
		if (!best) best = chromosome;
		else
		{
			if (chromosome->getFitness() > best->getFitness())
			{
				best = chromosome;
			}
		}
	}
	return best;
}
Population::~Population()
{
}
