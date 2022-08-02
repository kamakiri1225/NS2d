#include <iostream>
#include <vector>
#include "Mesh.h" //メッシュ設定 
#include "Fields.h" //場の定義 
#include "Diff1d.h" //空間微分
#include "FileWriter.h" //ファイル出力

#include "PrintVector.h" //場のprint文
using std::vector;


int main()
{
	int nx = 20, ny = 20;
	double lengthx = 2.0, lengthy = 2.0;
	Mesh mesh2d_(nx, ny, lengthx, lengthy);//Meshクラスのインスタンス化

	/*
		U,V,P,bの定義
	*/
	#include "creatFields.h"

	// solution
	int ntimestep = 100;
	double dt = 0.001;
	double rho = 1.0;
	double visc = 1e-1;

	// file write
	FileWriter filewriter2d_;
	string name = "2DNS";


	string inlet = "INLET"; string outlet = "OUTLET";
	string right = "RIGHT"; string left = "LEFT";
	int nitmax = 50;
	double dxsq = mesh2d_.dx * mesh2d_.dx;
	double dysq = mesh2d_.dy * mesh2d_.dy;
	double dxsqdysq = dxsq * dysq;
	double deno = 2.0 * (dxsq + dysq);
	double conmined = dxsqdysq / deno;

	double bSpacing = (dxsq * dysq) / (2.0 * (dxsq + dysq));
	double invDelta = 1.0 / dt;
	double invrho = 1.0 / rho;
	double bSpacingRho = bSpacing * rho;
	double two = 2.0;
	double zerov = 0;
	double targetresidual = 1e-03;


	double ulid = 1.0;
	FieldsOperations.fixedValueBoundary(U, inlet, ulid);

	Pnew = P;
	Unew = U;
	Vnew = V;

	print2dfield(U, "U");

	for (int nt = 0; nt < ntimestep; nt++)
	{
		std::cout << "Iteration no : " << nt << std::endl;
		
		U = Unew;
		V = Vnew;
		
		//outcome
		if (nt % 10 == 0)
		{
			filewriter2d_.write2dUVFields(Unew, Vnew, Pnew, nt, name);
		}

		for (int nit = 0; nit < nitmax; nit++)
		{
			P = Pnew;
			b = -1.0 * (fd::gradXCDS(U) && fd::gradXCDS(U))
				- 2.0 * (fd::gradYCDS(U) && fd::gradXCDS(V))
				- (fd::gradYCDS(V) && fd::gradYCDS(V));
			Pnew = (fd::poissonX(P)) + (fd::poissonY(P)) - (bSpacingRho * b);
			// P boundary condition
			double leftboundaryValue = 0.0;
			FieldsOperations.fixedValueBoundary(Pnew, inlet, leftboundaryValue);
			FieldsOperations.zeroGradient(Pnew, outlet);
			FieldsOperations.zeroGradient(Pnew, right);
			FieldsOperations.zeroGradient(Pnew, left);

			double l1normal = FieldsOperations.L1norm(Pnew, P);
			//cout << "L1 norm  Pressure Eqn Residual = "<< nit << "  == " << l1normal << endl;
			if (l1normal < targetresidual)
			{
				std::cout << "pressure eqn is converged : " << nit << std::endl;
				std::cout << "L1 norm  Pressure Eqn Residual = " << l1normal << std::endl;
				break;
			}
		} //  Pressure Eqn end loop
		double l1normal = FieldsOperations.L1norm(Pnew, P);
		std::cout << "L1 norm  Pressure Eqn Residual = " << l1normal << std::endl;


		// du/dt+udu/dx+vdu/dy= -1/ρdp/dx + nu ∇^2 u
		// dv/dt+udv/dx+vdv/dy= -1/ρdp/dy + nu ∇^2 v
		Unew = U
			- dt * (U && fd::gradX(U)) - dt * (V && fd::gradY(U))
			- dt * invrho * fd::gradXCDS(P)
			+ dt * visc * (fd::laplacian2d(U));
		Vnew = V
			- dt * (U && fd::gradX(V)) - dt * (V && fd::gradY(V))
			- dt * invrho * fd::gradYCDS(P)
			+ dt * visc * (fd::laplacian2d(V));


		// UV boundary condition
		FieldsOperations.fixedValueBoundary(Unew, inlet, ulid);
		FieldsOperations.fixedValueBoundary(Unew, outlet, zerov);
		FieldsOperations.fixedValueBoundary(Unew, right, zerov);
		FieldsOperations.fixedValueBoundary(Unew, left, zerov);

		FieldsOperations.fixedValueBoundary(Vnew, inlet, zerov);
		FieldsOperations.fixedValueBoundary(Vnew, outlet, zerov);
		FieldsOperations.fixedValueBoundary(Vnew, right, zerov);
		FieldsOperations.fixedValueBoundary(Vnew, left, zerov);


		} // solution ends

	return 0;
}
