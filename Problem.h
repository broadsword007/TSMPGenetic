#pragma once
#include <iostream>
#include <vector>
#include "City.h"
#include "Population.h"
#include "Chromosome.h"
using namespace std;
class Problem
{
	vector<City*> cities;
public:
	Problem();
	~Problem();
};

