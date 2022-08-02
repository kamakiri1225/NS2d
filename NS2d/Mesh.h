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

	double lengthx, lengthy; //x•ûŒü’·‚³
	int nrows, ncols;        //•ªŠ„”
	double dx, dy;           //•ªŠ„•
	vector<double> xpts;     //xÀ•W
	vector<double> ypts;     //yÀ•W

	//add
	void discritized1dgrid(vector<double>&, double&); //x[i], y[i]‚Ìì¬
	//add end
};

#endif //MESH_H