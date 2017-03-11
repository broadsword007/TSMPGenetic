#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "City.h"
#include "Population.h"
#include "Chromosome.h"
using namespace std;
class Problem
{
	vector<City*> cities;
public:
	Problem()
	{
		cout << "Enter File Name : ";
		string str;
		cin >> str;
		str = str + ".txt";
		int total_lines_read = 0;
		cities = readFromFile(str, total_lines_read);
		printer(this);
		cout << endl << "Size of Main Node : " << cities.size() << endl;
		cout << "Number Of lines read : " << total_lines_read << endl;
	}
	void printer(Problem* p)
	{
		for (int city_number = 0; city_number < p->cities.size(); city_number++)
		{
			cout << "City Number : " << p->cities[city_number]->getCityNumber() << endl;
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
	vector<City*> readFromFile(string filename, int &total_lines_read)
	{
		int size = 312;										// size is 312 because total cities = 312
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
								City* c = new City(city_number, distances_of_one_city);
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
					City* c = new City(city_number, distances_of_one_city);
					Node_with_all_cities_distances.push_back(c);
					distances_of_one_city.clear();
				}
			}
		}
		return Node_with_all_cities_distances;
	}
	~Problem();
};

