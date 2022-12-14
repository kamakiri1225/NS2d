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

	double lengthx, lengthy; //x方向長さ
	int nrows, ncols;        //分割数
	double dx, dy;           //分割幅
	vector<double> xpts;     //x座標
	vector<double> ypts;     //y座標

	//add
	void discritized1dgrid(vector<double>&, double&); //x[i], y[i]の作成
	//add end
};

#endif //MESH_H