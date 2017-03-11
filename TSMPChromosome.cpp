#include "TSMPChromosome.h"
#include "Population.h"

TSMPChromosome::TSMPChromosome(vector<City*> val_cities_order) :Chromosome()
{
	for each (City* city in val_cities_order)
	{
		cities_order.push_back(city);
	}
}
float TSMPChromosome::getFitness()
{
	fitness = 0;
	fitness_calculated = true;
	return 0;
}
Population* TSMPChromosome::performCrossover(Chromosome* another_chromosome, string params)
{
	return NULL;
}
void TSMPChromosome::mutate(string params)
{

}
TSMPChromosome::~TSMPChromosome()
{
}
