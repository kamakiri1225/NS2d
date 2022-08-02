#ifndef FIELDS_H
#define FIELDS_H
#include "Mesh.h"
#include <vector>
#include <string>
using std::vector;

class Fields
{
public:
	Fields();//constructor
	virtual ~Fields(); //deconstructor

	typedef vector<Fields> vectorField1d;
	typedef vector<vector<Fields> > vectorField2d;

	double x,y; //座標
	double value; //流速の値

	Fields::vectorField1d pass1DGridinfomation(Fields::vectorField1d&, vector<double>&);
	Fields::vectorField2d pass2DGridinfomation(Fields::vectorField2d&, vector<double>&, vector<double>&);

	//境界条件
	void fixedValueBoundary(Fields::vectorField2d&, std::string&, double&);
	void specialPBoundary(Fields::vectorField2d&, std::string&);
	void zeroGradient(Fields::vectorField2d&, std::string&);

	//残差計算
	double L1norm(Fields::vectorField2d&, Fields::vectorField2d&);



	//演算子のオーバーロード(1d)
	friend Fields::vectorField1d operator+(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator-(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator&&(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator*(const double&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator*(const Fields::vectorField1d&, const double&);

	//演算子のオーバーロード(2d)
	friend Fields::vectorField2d operator+(const Fields::vectorField2d&, const Fields::vectorField2d&);
	friend Fields::vectorField2d operator-(const Fields::vectorField2d&, const Fields::vectorField2d&);
	friend Fields::vectorField2d operator&&(const Fields::vectorField2d&, const Fields::vectorField2d&);
	friend Fields::vectorField2d operator*(const double&, const Fields::vectorField2d&);
	friend Fields::vectorField2d operator*(const Fields::vectorField2d&, const double&);
};


#endif //FIELDS_H

