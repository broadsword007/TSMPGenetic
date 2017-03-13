#include "Population.h"
#include "Chromosome.h"
#include <time.h>

Population::Population()
{
}
Population::Population(vector<Chromosome*> val_chromosomes)
{
	for each (Chromosome* chromosome in val_chromosomes)
	{
		chromosomes.push_back(chromosome);
	}
}
void Population::selectBest(int number_of_best, string param)
{
	vector<Chromosome*> best_chromosomes;
	vector<int> best_indices; /// index of already selected chromosomes
	if (param == "tournament selection")
	{
		//selecting best using tournment selection ; 4-way tournament
		srand(time(NULL));
		for (int i = 0; i < number_of_best; i++)
		{
			Chromosome* best=NULL;
			int best_index;
			for (int j = 0; j < chromosomes.size() / 4; j++)
			{
				int child_no = rand() % chromosomes.size();
				if (best==NULL) 
				{
					best = chromosomes[child_no];
					best_index = child_no; 
				}
				else
				{
					if (chromosomes[child_no]->getFitness() > best->getFitness())
					{
						best = chromosomes[child_no];
						best_index = child_no;
					}
				}
			}
			//////////check if it is already selected then choose another one
			bool already_selected = false;
			for (int j = 0; j < best_indices.size() && !already_selected; j++)
			{
				if (best_index == best_indices[j]) already_selected = true;
			}
			if (!already_selected)
			{
				best_chromosomes.push_back(best);
				best_indices.push_back(best_index);
			}
			else i--;
			/////////
		}
	}
	chromosomes = best_chromosomes;
}
Population* Population::performCrossover(string params)
{
	//perform crossover
	Population* offspring_population=new Population();
	for (int i = 0; i < chromosomes.size(); i++)
	{
		for (int j = 0; j < chromosomes.size(); j++)
		{
			if (i != j) offspring_population->mergePopulation(chromosomes[i]->performCrossover(chromosomes[j], params));
		}
	}
	return offspring_population;
}
void Population::mutate(float mutation_rate)
{
	// mutate each chromosome
	for each (Chromosome* chromosome in chromosomes)
	{
		chromosome->mutate(mutation_rate);
	}
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
	Chromosome* best=NULL;
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
void Population::addChromosome(Chromosome* new_chromosome)
{
	chromosomes.push_back(new_chromosome);
}
Population::~Population()
{
}
