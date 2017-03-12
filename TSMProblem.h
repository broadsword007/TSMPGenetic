#pragma once
#include <iostream>
#include <vector>
#include "City.h"
#include "Population.h"
#include "TSMPChromosome.h"
using namespace std;
class TSMProblem
{
	vector<City*> cities;
	void initialize_cities(string coord_filename, string distances_filename);
	void printer(TSMProblem* p);
	vector<City*> readDistancesFromFile(string filename, string CoordFile, int &total_lines_read);
	vector<vector<float>> readCoords(string filename, int &total_lines_read);
public:
	TSMProblem(string coord_filename, string distances_filename);
	Population* getInitialPopulation(int size);
	~TSMProblem();
};

