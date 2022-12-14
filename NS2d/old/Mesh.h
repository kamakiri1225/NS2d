#ifndef MESH_H
#define MESH_H
#include "Mesh.h"
#include <vector>
using std::vector;

class Mesh
{
public:
	Mesh();	//constructor
	Mesh(int&, double&); //引数ありconstructor
	virtual ~Mesh();//deconstructor

	int NumberOfNode;//x分割数
	double lengthx;//x方向長さ
	double dx1d;//分割幅
	vector<double> xpts;//x座標

	//add
	void discritized1dgrid(vector<double>&); //x[i]の作成
	//add end
};

#endif //MESH_H