#include "TSMProblem.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <istream>

TSMProblem::TSMProblem(string coord_filename, string distances_filename)
{
	initialize_cities(coord_filename, distances_filename);
}
void TSMProblem::initialize_cities(string coord_filename, string distances_filename)
{
	coord_filename = coord_filename + ".txt";
	distances_filename = distances_filename + ".txt";
	int total_lines_read = 0;
	cities = readDistancesFromFile(distances_filename, coord_filename, total_lines_read);
	printer(this);
	cout << endl << "Size of Main Node : " << cities.size() << endl;
	cout << "Number Of lines read : " << total_lines_read << endl;
}
Population* TSMProblem::getInitialPopulation(int size)
{
	Population * new_population=new Population();
	for (int i = 0; i < size; i++)
	{
		vector<City*> new_city_order = cities;
		std::random_shuffle(new_city_order.begin(), new_city_order.end());
		Chromosome * new_chromosome = new TSMPChromosome(new_city_order);
		new_population->addChromosome(new_chromosome);
	}
	return new_population;
}
vector<vector<float>> readCoords(string filename, int & total_lines_read)
{
	int size = 2;										// size is 312 because total cities = 312
	vector<float> coord_of_one_city;
	vector<vector<float>> Node_with_all_cities_coords;
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		int req = -1, req2 = 0, spcCount = -1, decCount = 0;
		bool flag = false;
		string str;
		while (getline(fin, str))
		{
			total_lines_read++;
			if (str[0] == ' ' || (str[0] >= 48 && str[0] <= 57))	// to check if the line we read is relevant
			{
				for (int i = 0; str[i] != '\0'; i++)
				{
					if (str[i] >= 48 && str[i] <= 57 || str[i] == '.' || str[i] == '-')
					{
						if (str[i] == '.')
						{
							flag = true;
						}
						else if (str[i] != '-')
						{
							if (flag)
							{
								decCount++;
							}
							req2 = str[i] - 48;						// req and req2 are just conversion numbers from string to int
							if (req < 0)
							{
								req = req * 0;
							}
							req = req * 10;							// ignore them
							req = req + req2;
							spcCount = 0;							// checks if there are more than 1 spaces in the file
						}
					}
					else if (str[i] == ' ' && spcCount == 0 && req != -1)
					{
						float num = req / pow(10, decCount);
						coord_of_one_city.push_back(num);
						spcCount = -1;
						req = -1;
						decCount = 0;
						flag = false;
						if (coord_of_one_city.size() == size)
						{
							Node_with_all_cities_coords.push_back(coord_of_one_city);
							coord_of_one_city.clear();
						}
					}
				}
			}
		}
		if (req != -1)	// to check if any value is remaining at the end (not pushed in vecotr) and eof() is reached
		{
			req = req / pow(10, decCount);
			coord_of_one_city.push_back(req);
			spcCount = -1;
			req = -1;
			if (coord_of_one_city.size() == size)
			{
				Node_with_all_cities_coords.push_back(coord_of_one_city);
				coord_of_one_city.clear();
			}
		}
	}
	return Node_with_all_cities_coords;
}vector<City*> readDistancesFromFile(string filename, string CoordFile, int & total_lines_read)
{
	int size = 0;
	vector<vector<float>> Node_with_all_cities_coords = readCoords(CoordFile, size);
	vector<float> distances_of_one_city;
	vector<City*> Node_with_all_cities_distances;
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		int req = -1, req2 = 0, spcCount = -1;
		string str;
		while (getline(fin, str))
		{
			total_lines_read++;
			if (str[0] == ' ' || (str[0] >= 48 && str[0] <= 57))	// to check if the line we read is relevant
			{
				for (int i = 0; str[i] != '\0'; i++)
				{
					if (str[i] >= 48 && str[i] <= 57)
					{
						req2 = str[i] - 48;						// req and req2 are just conversion numbers from string to int
						if (req < 0)
						{
							req = req * 0;
						}
						req = req * 10;							// ignore them
						req = req + req2;
						spcCount = 0;							// checks if there are more than 1 spaces in the file
					}
					else if (str[i] == ' ' && spcCount == 0 && req != -1)
					{
						distances_of_one_city.push_back(req);
						spcCount = -1;
						req = -1;
						if (distances_of_one_city.size() == size)
						{
							int city_number = Node_with_all_cities_distances.size();
							float xcoord = Node_with_all_cities_coords[city_number][0];
							float ycoord = Node_with_all_cities_coords[city_number][1];
							City* c = new City(city_number, distances_of_one_city, xcoord, ycoord);
							Node_with_all_cities_distances.push_back(c);
							distances_of_one_city.clear();
						}
					}
				}
			}
		}
		if (req != -1)	// to check if any value is remaining at the end (not pushed in vecotr) and eof() is reached
		{
			distances_of_one_city.push_back(req);
			spcCount = -1;
			req = -1;
			if (distances_of_one_city.size() == size)
			{
				int city_number = Node_with_all_cities_distances.size();
				float xcoord = Node_with_all_cities_coords[city_number][0];
				float ycoord = Node_with_all_cities_coords[city_number][1];
				City* c = new City(city_number + 1, distances_of_one_city, xcoord, ycoord);
				Node_with_all_cities_distances.push_back(c);
				distances_of_one_city.clear();
			}
		}
	}
	return Node_with_all_cities_distances;
}
void TSMProblem::printer(TSMProblem* p)
{
	for (int city_number = 0; city_number < p->cities.size(); city_number++)
	{
		cout << "City Number : " << p->cities[city_number]->getCityNumber() << endl;
		cout << "City Corrdinates ( X = " << p->cities[city_number]->getXCoord() << " , Y = " << p->cities[city_number]->getYCoord() << " )" << endl;
		for (int i = 0; i < p->cities[city_number]->getDistances().size(); i++)
		{
			if (i != p->cities[city_number]->getDistances().size() - 1)
			{
				cout << p->cities[city_number]->getDistances()[i] << ",";
			}
			else
			{
				cout << p->cities[city_number]->getDistances()[i];
			}
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}
TSMProblem::~TSMProblem()
{
}
