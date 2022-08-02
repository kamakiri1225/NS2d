#include <iostream>
#include <string>
#include "Fields.h"

void print1dvec(vector<double>& vec, std::string name)
{
	std::cout << "======= print1dvec ======" << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << name << "[" << i << "] = " << vec[i] << std::endl;
	}
	std::cout << "======= end print1dvec ======" << std::endl;

}

void print1dfield(Fields::vectorField1d& field, std::string name)
{
	std::cout << "======= print1dfield ======" << std::endl;

	for (int i = 0; i < field.size(); i++)
	{
		std::cout << name << "[" << i << "] = " << field[i].value << std::endl;;
	}

	std::cout << "======= end print1dfield ======" << std::endl;

}

void print2dfield(Fields::vectorField2d& field, std::string name)
{
	std::cout << "======= print2dfield =" << name << "=====" << std::endl;

	/*
		for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[i].size(); j++)
		{
			std::cout << name << "[" << i << "][" << j << "].x = " << field[i][j].x << std::endl;
		}

	}
	*/

	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[i].size(); j++)
		{
			std::cout << field[i][j].value << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "======= end print2dfield ======" << std::endl;

}