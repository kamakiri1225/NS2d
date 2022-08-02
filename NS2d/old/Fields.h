#ifndef FIELDS_H
#define FIELDS_H
#include "Mesh.h"
#include <vector>
using std::vector;

class Fields
{
public:
	Fields();//constructor
	virtual ~Fields(); //deconstructor

	typedef vector<Fields> vectorField1d;
	
	double x1d; //x���W
	double value; //U�̒l

	Fields::vectorField1d passGridinfomation(Fields::vectorField1d&, vector<double>&);

	//���Z�q�̃I�[�o�[���[�h
	friend Fields::vectorField1d operator+(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator-(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator&&(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator*(const double&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator*(const Fields::vectorField1d&, const double&);
};


#endif //FIELDS_H

