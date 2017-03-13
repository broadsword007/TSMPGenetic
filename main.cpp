#include <iostream>
#include "TSMProblem.h"
#include "GeneticSearch.h"
#include "Chromosome.h"
#include <algorithm>
using namespace std;
int main()
{
	TSMProblem p1("coordinates", "distances");
	int population_size=50;
	string selection_method="tournament selection";
	string crossoverMethod="ordered crossover";
	float mutation_rate=10;
	int no_of_iterations=2;
	float max_fitness=0;
	GeneticSearch problemSolver(population_size,selection_method,crossoverMethod,mutation_rate,no_of_iterations, max_fitness);
	Chromosome* c=problemSolver.Solve(&p1);
	cout << "Final Best fitness : ";
	c->print();
	cout << endl;
	c->writeToFile("output.txt");
	system("pause");
	return 0;
}
