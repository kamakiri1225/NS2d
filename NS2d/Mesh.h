#ifndef MESH_H
#define MESH_H
#include "Mesh.h"
#include <vector>
using std::vector;

class Mesh
{
public:
	Mesh();	//constructor
	Mesh(int&, double&); 
	Mesh(int&, int&, double&, double&);
	virtual ~Mesh();     //deconstructor

	double lengthx, lengthy; //x��������
	int nrows, ncols;        //������
	double dx, dy;           //������
	vector<double> xpts;     //x���W
	vector<double> ypts;     //y���W

	//add
	void discritized1dgrid(vector<double>&, double&); //x[i], y[i]�̍쐬
	//add end
};

#endif //MESH_H