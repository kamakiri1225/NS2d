#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
}

Mesh::Mesh(int& n, double& txlengthx):
	NumberOfNode(n),//x������
	lengthx(txlengthx),//x��������
	xpts(NumberOfNode, 0.0)//vector(�v�f��, �l)
{
		dx1d = lengthx / (NumberOfNode-1);
		discritized1dgrid(xpts); //add
}

void Mesh::discritized1dgrid(vector<double>& vec)
{
	for (int i = 1; i < vec.size(); i++) //vec[0]=0�Ȃ̂�i=1���烋�[�v����
	{
		vec[i] = vec[i - 1] + dx1d;
	}
}

Mesh::~Mesh()
{
}