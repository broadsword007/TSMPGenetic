#pragma once
#include <iostream>
#include <vector>
using namespace std;
class City
{
	int cityNumber;
	vector<float> distances;
public:
	City(int val_cityNumber, vector<float> val_distances);
	float distanceTo(int val_cityNumber);
	vector<float> getDistances();
	int getCityNumber();
	~City();
};

