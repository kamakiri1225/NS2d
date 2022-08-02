#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
}

Mesh::Mesh(int& n, double& txlengthx) :
	nrows(n),//x������
	lengthx(txlengthx),//x��������
	xpts(nrows, 0.0)//vector(�v�f��, �l)
{
	dx = lengthx / (nrows - 1);
	discritized1dgrid(xpts, dx); //add
}

Mesh::Mesh(int& nrows_, int& ncols_, double& lengthx_, double& lengthy_) :
	nrows(nrows_),//x������
	ncols(ncols_),//y������
	lengthx(lengthx_),//x��������
	lengthy(lengthy_),//y��������
	xpts(nrows, 0.0),//vector(�v�f��, �l)
	ypts(nrows, 0.0) //vector(�v�f��, �l)
{
	dx = lengthx / (nrows - 1);
	dy = lengthx / (nrows - 1);

	discritized1dgrid(xpts, dx); 
	discritized1dgrid(ypts, dy);
}


void Mesh::discritized1dgrid(vector<double>& vec, double& dx_)
{
	for (int i = 1; i < vec.size(); i++) //vec[0]=0�Ȃ̂�i=1���烋�[�v����
	{
		vec[i] = vec[i - 1] + dx_;
	}
}

Mesh::~Mesh()
{
}