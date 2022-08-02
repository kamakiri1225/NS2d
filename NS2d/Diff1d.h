#include <vector>
#include "Fields.h"
#include <cmath> //add
using std::vector;

namespace fd1d
{
	// U    U    U    U
	//*-----*----*----*
	//     i-1   i
	Fields::vectorField1d gradX1d(Fields::vectorField1d& vec) //typedef vector<Fields> vectorField1d;
	{
		Fields::vectorField1d temp = vec;

		for (int i = 1; i < vec.size(); i++)
		{
			temp[i].value = (vec[i].value - vec[i - 1].value) / (vec[i].x - vec[i - 1].x);
		}

		return temp;
	}

	Fields::vectorField1d laplacianX1d(Fields::vectorField1d& vec) //typedef vector<Fields> vectorField1d;
	{
		Fields::vectorField1d temp = vec;

		for (int i = 1; i < vec.size() - 1; i++)
		{
			temp[i].value = (vec[i + 1].value - 2.0 * vec[i].value + vec[i - 1].value) / pow((vec[i].x - vec[i - 1].x), 2.0);
		}
		return temp;
	}
}


namespace fd
{
	Fields::vectorField2d gradX(Fields::vectorField2d& vec)
	{
		Fields::vectorField2d temp = vec;

		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				temp[i][j].value = (vec[i][j].value - vec[i - 1][j].value) / (vec[i][j].x - vec[i - 1][j].x);
			}
		}
		return temp;
	}

	Fields::vectorField2d gradY(Fields::vectorField2d& vec)
	{
		Fields::vectorField2d temp = vec;

		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				temp[i][j].value = (vec[i][j].value - vec[i][j - 1].value) / (vec[i][j].y - vec[i][j - 1].y);
			}
		}

		return temp;
	}

	Fields::vectorField2d gradXCDS(Fields::vectorField2d& vec)
	{
		Fields::vectorField2d temp = vec;

		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				temp[i][j].value = (vec[i + 1][j].value - vec[i - 1][j].value) / (2.0 * (vec[i + 1][j].x - vec[i - 1][j].x));
			}
		}
		return temp;
	}

	Fields::vectorField2d gradYCDS(Fields::vectorField2d& vec)
	{
		Fields::vectorField2d temp = vec;

		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				temp[i][j].value = (-vec[i][j - 1].value) / (2.0 * (vec[i][j + 1].y - vec[i][j - 1].y));
			}
		}

		return temp;
	}

	Fields::vectorField2d laplacian2d(Fields::vectorField2d& vec) //typedef vector<Fields> vectorField1d;
	{
		//Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size())); temp[i][j].x ‚ª‹ó[0]‚É‚È‚é
		Fields::vectorField2d temp = vec; //ã‘‚«‚·‚é.‚à‚µ‚­‚ÍQÆ“n‚µ‚É‚·‚é.
		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[j].size() - 1; j++)
			{
				temp[i][j].value = (vec[i + 1][j].value - 2.0 * vec[i][j].value + vec[i - 1][j].value) / pow((vec[i][j].x - vec[i - 1][j].x), 2.0)
					+
					(vec[i][j + 1].value - 2.0 * vec[i][j].value + vec[i][j - 1].value) / pow((vec[i][j].y - vec[i][j - 1].y), 2.0);
			}
		}

		return temp;
	}

	Fields::vectorField2d lapOp(Fields::vectorField2d& vec) //typedef vector<Fields> vectorField1d;
	{
		//Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size())); temp[i][j].x ‚ª‹ó[0]‚É‚È‚é
		Fields::vectorField2d temp = vec; //ã‘‚«‚·‚é.‚à‚µ‚­‚ÍQÆ“n‚µ‚É‚·‚é.
		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				double dxsq = pow((vec[i][j].x - vec[i - 1][j].x), 2.0);
				double dysq = dxsq;
				temp[i][j].value = (
					(vec[i + 1][j].value + vec[i - 1][j].value) * dxsq
					+
					(vec[i][j + 1].value + vec[i][j - 1].value) * dysq
					)
					/ (2.0 * (dxsq + dysq));
			}
		}

		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				//std::cout << "temp[i][j].value = " << temp[i][j].value << std::endl;
			}
		}
		return temp;
	}
	Fields::vectorField2d poissonX(Fields::vectorField2d& vec)
	{
		Fields::vectorField2d temp = vec;
	
		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				double dxsq = pow((vec[i][j].y - vec[i][j - 1].y), 2);
				double dysq = pow((vec[i][j].x - vec[i - 1][j].x), 2);
				
				temp[i][j].value = (dysq * (vec[i + 1][j].value + vec[i - 1][j].value)) / (2.0 * (dxsq + dysq));
				
			}
		}

		return temp;
	}

	Fields::vectorField2d poissonY(Fields::vectorField2d& vec)
	{
		Fields::vectorField2d temp = vec;
	
		for (int i = 1; i < vec.size() - 1; i++)
		{
			for (int j = 1; j < vec[i].size() - 1; j++)
			{
				double dxsq = pow((vec[i][j].y - vec[i][j - 1].y), 2);
				double dysq = pow((vec[i][j].x - vec[i - 1][j].x), 2);

				temp[i][j].value = (dxsq * (vec[i][j + 1].value + vec[i][j - 1].value)) / (2.0 * (dxsq + dysq));
			}
		}

		return temp;
	}
}// ene namespace fd