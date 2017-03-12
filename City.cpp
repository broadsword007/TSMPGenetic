#include "City.h"


City::City(int val_cityNumber, vector<float> val_distances, float xcord, float ycord)
{
	cityNumber = val_cityNumber, xCoord = xcord, yCoord = ycord;
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
vector<float> City::getDistances()
{
	return distances;
}
int City::getCityNumber()
{
	return cityNumber;
}
float City::getXCoord()
{
	return xCoord;
}
float City::getYCoord()
{
	return yCoord;
}
City::~City()
{
}
