#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
}

Mesh::Mesh(int& n, double& txlengthx) :
	nrows(n),//x分割数
	lengthx(txlengthx),//x方向長さ
	xpts(nrows, 0.0)//vector(要素数, 値)
{
	dx = lengthx / (nrows - 1);
	discritized1dgrid(xpts, dx); //add
}

Mesh::Mesh(int& nrows_, int& ncols_, double& lengthx_, double& lengthy_) :
	nrows(nrows_),//x分割数
	ncols(ncols_),//y分割数
	lengthx(lengthx_),//x方向長さ
	lengthy(lengthy_),//y方向長さ
	xpts(nrows, 0.0),//vector(要素数, 値)
	ypts(nrows, 0.0) //vector(要素数, 値)
{
	dx = lengthx / (nrows - 1);
	dy = lengthx / (nrows - 1);

	discritized1dgrid(xpts, dx); 
	discritized1dgrid(ypts, dy);
}


void Mesh::discritized1dgrid(vector<double>& vec, double& dx_)
{
	for (int i = 1; i < vec.size(); i++) //vec[0]=0なのでi=1からループする
	{
		vec[i] = vec[i - 1] + dx_;
	}
}

Mesh::~Mesh()
{
}