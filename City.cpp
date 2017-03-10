#include "City.h"


City::City(int val_cityNumber, vector<float> val_distances)
{
	cityNumber = val_cityNumber;
	for each (float distance in val_distances)
	{
		distances.push_back(distance);
	}
}
float City::distanceTo(int val_cityNumber)
{
	if (val_cityNumber >= distances.size()) { cout<<"wrong city number"<<endl ; return 0; }
	return distances[val_cityNumber];
}

City::~City()
{
}
