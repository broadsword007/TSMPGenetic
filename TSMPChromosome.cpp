#include "TSMPChromosome.h"
#include "Population.h"
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
TSMPChromosome::TSMPChromosome(vector<City*> val_cities_order) :Chromosome()
{
	for each (City* city in val_cities_order)
	{
		cities_order.push_back(city);
		fitness_calculated = false;
	}
}
float TSMPChromosome::getFitness()
{
	fitness = 0;
	if (fitness_calculated) { fitness_calculated = true; return fitness; }
	else
	{
		if (cities_order.size() <=1)
		{
			fitness = 0;
			fitness_calculated = true;
			return fitness;
		}
		total_distance = 0;
		for (int i = 1; i < cities_order.size(); i++)
		{
			total_distance += cities_order[i]->distanceTo(cities_order[i - 1]->getCityNumber());
		}
		fitness = 1.0 / total_distance;
	}
		
	return fitness;
}
vector<City*>  TSMPChromosome::getcitieslist()
{
	return cities_order;
}
Population* TSMPChromosome::performCrossover(Chromosome* another_chromosome, string params)
{
	Population* resultant_population= new Population();
	if (params == "ordered crossover")
	{
		vector<City*> other_chromosome_cities_list = static_cast<TSMPChromosome*>(another_chromosome)->getcitieslist();
		vector<City*> new_cities_list(312);
		for (int i = 78; i < 233; i++)
		{
			new_cities_list[i] = other_chromosome_cities_list[i];
		}
		int k = 0;
		for (int i = 0; i < 312; i++)
		{
			if (k == 78) k = 233;  /// don't overwrite the cities already written in last loop
			bool already_exists = false;
			for (int j = 78; j < 233 && !already_exists; j++) /// check if city already exists
			{
				if (cities_order[i]->getCityNumber() == new_cities_list[j]->getCityNumber())
				{
					already_exists = true;
				}
			}
			if (!already_exists) new_cities_list[k++] = cities_order[i];
		}
		if (k != 312) cout << "Something went wrong in ordered crossover!" << endl;
		Chromosome * offspring = new TSMPChromosome(new_cities_list);
		resultant_population->addChromosome(offspring);
	}
	return resultant_population;
}
void TSMPChromosome::mutate(int mutation_rate)
{
	int genes_to_change = ceil(mutation_rate*3.12); ///////////// SWap Mutation
	srand(time(NULL));
	for (int i = 0; i < genes_to_change; i++)
	{
		int to_swap = rand() % 312;
		int with = rand() % 312;
		if (to_swap == with) i--;
		else
		{
			City* temp = cities_order[to_swap];
			cities_order[to_swap] = cities_order[with];
			cities_order[with] = temp;
		}
	}
}
void TSMPChromosome::print()
{
	cout << fitness;
}
void TSMPChromosome::writeToFile(string filename)
{
	std::ofstream out(filename);
	if (!out.is_open())
	{
		cout << "File not opened" << endl;
		return;
	}

	for each (City* city in cities_order)
	{
		stringstream ss1;
		stringstream ss2;
		int x = city->getXCoord();
		int y = city->getYCoord();
		ss1 << x;
		string cityString = ss1.str();
		ss2 << y;
		cityString += "," + ss2.str() + "\n";
		out << cityString;
	}
	out.close();
}
TSMPChromosome::~TSMPChromosome()
{
}
