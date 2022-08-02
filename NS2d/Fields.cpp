#include "Fields.h"
#include <iostream>

Fields::Fields() :
	x(0.0),
	y(0.0),
	value(0.0)
{
}

Fields::vectorField1d Fields::pass1DGridinfomation(Fields::vectorField1d& vec, vector<double>& xpts_)
{
	/*
	typedef vector<Fields> vectorField1d;
	double value;
	double x1d;
	*/
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].x = xpts_[i];
	}

	return vec;
}

Fields::vectorField2d Fields::pass2DGridinfomation(Fields::vectorField2d& vec, vector<double>& xpts_, vector<double>& ypts_)
{
	for (int i = 0; i < vec.size(); i++)
	{
		double xpos = xpts_[i];
		for (int j = 0; j < vec[i].size(); j++)
		{
			double ypos = ypts_[j];
			vec[i][j].x = xpos;
			vec[i][j].y = ypos;
		}
	}

return vec;
}


Fields::vectorField1d operator+(const Fields::vectorField1d& vecA, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecA;

	for (int i = 0; i < vecA.size(); i++)
	{
		temp[i].value += vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator-(const Fields::vectorField1d& vecA, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecA;

	for (int i = 0; i < vecA.size(); i++)
	{
		temp[i].value -= vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator&&(const Fields::vectorField1d& vecA, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecA;

	for (int i = 0; i < vecA.size(); i++)
	{
		temp[i].value *= vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator*(const double& dbvalue, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecB;

	for (int i = 0; i < vecB.size(); i++)
	{
		temp[i].value = dbvalue * vecB[i].value;
	}
	return temp;
}

void Fields::fixedValueBoundary(Fields::vectorField2d& vec, std::string& name, double& pvalue)
{
	if (name == "INLET")
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int j = vec.size() - 1;
			vec[i][j].value = pvalue;
		}
	}
	else if (name == "OUTLET")
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int j = 0;
			vec[i][j].value = pvalue;
		}
	}
	else if (name == "RIGHT")
	{
		for (int j = 1; j < vec.size() - 1; j++)
		{
			int i = vec.size() - 1;
			vec[i][j].value = pvalue;
		}
	}
	else if (name == "LEFT")
	{
		for (int j = 1; j < vec.size() - 1; j++)
		{
			int i = 0;
			vec[i][j].value = pvalue;
		}
	}
	else
	{
		std::cout << "The boundary name " << name << "is not found in the geometry" << std::endl;
	}
}


void Fields::zeroGradient(Fields::vectorField2d& vec, std::string& name)
{
	if (name == "INLET")
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int j = vec.size() - 1;
			vec[i][j].value = vec[i][j - 1].value;
		}
	}
	else if (name == "OUTLET")
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int j = 0;
			vec[i][j].value = vec[i][j + 1].value;
		}
	}
	else if (name == "RIGHT")
	{
		for (int j = 1; j < vec.size() - 1; j++)
		{
			int i = vec.size() - 1;
			vec[i][j].value = vec[i - 1][j].value;
		}
	}
	else if (name == "LEFT")
	{
		for (int j = 1; j < vec.size() - 1; j++)
		{
			int i = 0;
			vec[i][j].value = vec[i + 1][j].value;
		}
	}
	else
	{
		std::cout << "The boundary name " << name << "is not found in the geometry" << std::endl;
	}
}

void Fields::specialPBoundary(Fields::vectorField2d& vec, std::string& name)
{
	if (name == "RIGHT")
	{
		for (int j = 1; j < vec.size() - 1; j++)
		{
			int i = vec.size() - 1;
			vec[i][j].value = vec[i - 1][j].y;
		}
	}
}


double Fields::L1norm(Fields::vectorField2d& VecNew, Fields::vectorField2d& VecOld)
{
	double tempL1norm = 0.0;
	double tempL2norm = 0.0;
	double tempResult = 0.0;

	for (int i = 1; i < VecNew.size(); i++)
	{
		for (int j = 1; j < VecNew[i].size(); j++)
		{
			tempL1norm += abs(abs(VecNew[i][j].value - VecOld[i][j].value));
			tempL2norm += abs(VecOld[i][j].value);
		}
	}
	tempResult = tempL1norm / tempL2norm;
	return tempResult;

}


Fields::vectorField1d operator*(const Fields::vectorField1d& vecB, const double& dbvalue)
{
	Fields::vectorField1d temp = vecB;

	for (int i = 0; i < vecB.size(); i++)
	{
		temp[i].value = dbvalue * vecB[i].value;
	}
	return temp;
}

// 2D overloaded operators
Fields::vectorField2d operator+(const Fields::vectorField2d& vecA, const Fields::vectorField2d& vecB)
{
	Fields::vectorField2d temp(vecA);


	for (int i = 1; i < vecA.size() - 1; i++)
	{
		for (int j = 1; j < vecA[i].size() - 1; j++)
		{
			temp[i][j].value += vecB[i][j].value;
		}
	}
	return temp;

}

Fields::vectorField2d operator-(const Fields::vectorField2d& vecA, const Fields::vectorField2d& vecB)
{
	Fields::vectorField2d temp(vecA);
	for (int i = 1; i < vecA.size() - 1; i++)
	{
		for (int j = 1; j < vecA[i].size() - 1; j++)
		{
			temp[i][j].value -= vecB[i][j].value;
		}
	}
	return temp;

}
Fields::vectorField2d operator&&(const Fields::vectorField2d& vecA, const Fields::vectorField2d& vecB)
{
	Fields::vectorField2d temp(vecA);
	for (int i = 1; i < vecA.size() - 1; i++)
	{
		for (int j = 1; j < vecA[i].size() - 1; j++)
		{
			temp[i][j].value *= vecB[i][j].value;
		}
	}
	return temp;

}

Fields::vectorField2d operator*(const double& dblvalue, const Fields::vectorField2d& vecB)
{
	//Fields::vectorField2d temp(vecB.size(), vector<Fields>(vecB[0].size()));
	Fields::vectorField2d temp = vecB;
	for (int i = 1; i < vecB.size() - 1; i++)
	{
		for (int j = 1; j < vecB[i].size() - 1; j++)
		{
			temp[i][j].value = dblvalue * vecB[i][j].value;
		}
	}

	return temp;

}
Fields::vectorField2d operator*(const Fields::vectorField2d& vecB, const double& dblvalue)
{
	//Fields::vectorField2d temp(vecB.size(), vector<Fields>(vecB[0].size()));
	Fields::vectorField2d temp = vecB;
	for (int i = 1; i < vecB.size() - 1; i++)
	{
		for (int j = 1; j < vecB[i].size() - 1; j++)
		{
			temp[i][j].value = dblvalue * vecB[i][j].value;
		}
	}
	return temp;
}

Fields::~Fields()
{
}