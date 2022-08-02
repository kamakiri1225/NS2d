#ifndef MESH_H
#define MESH_H
#include "Mesh.h"
#include <vector>
using std::vector;

class Mesh
{
public:
	Mesh();	//constructor
	Mesh(int&, double&); //��������constructor
	virtual ~Mesh();//deconstructor

	int NumberOfNode;//x������
	double lengthx;//x��������
	double dx1d;//������
	vector<double> xpts;//x���W

	//add
	void discritized1dgrid(vector<double>&); //x[i]�̍쐬
	//add end
};

#endif //MESH_H