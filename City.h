#pragma once
#include <iostream>
#include <vector>
using namespace std;
class City
{
	int cityNumber;
	vector<float> distances;
	float xCoord;
	float yCoord;
public:
	City(int val_cityNumber, vector<float> val_distances, float xcord, float ycord);
	float distanceTo(int val_cityNumber);
	vector<float> getDistances();
	int getCityNumber();
	float getXCoord();
	float getYCoord();
	~City();
};

