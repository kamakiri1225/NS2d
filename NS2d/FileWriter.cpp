#include "FileWriter.h"
#include <iostream>


FileWriter::FileWriter()
{
}

void FileWriter::write1dField(Fields::vectorField1d& vec, string& name_)
{
	string myfileType = ".dat"; //拡張子
	string path = "C:\\work\\C_lang\\20220413_diff_C_puls\\004_NS_Eq_1D_blog\\1DNS\\1DNS\\"; //絶対パス
	string pathName = path.append(name_).append(myfileType); //"myOutput;" + ".dat" => "myOutput.dat"
	std::cout << "pathName = " << pathName << " :  pathName.size() = " << pathName.size() << std::endl;

	FILE* outfile;
	fopen_s(&outfile, pathName.c_str(), "w+t"); //https://www.paveway.info/entry/2018/12/25/cpp_std_string_char

	std::cout << "outfile = " << &outfile << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		double xpos = vec[i].x;
		double uvel = vec[i].value;

		if (outfile)
		{
			fprintf(outfile, "%5.8lf\t%5.8lf\n", xpos, uvel);
		}

	}

	fclose(outfile);

}

void FileWriter::write2dUVFields(Fields::vectorField2d& Utemp, Fields::vectorField2d& Vtemp, Fields::vectorField2d& Ptemp, int time_, std::string& name_)
{
	string myfileType = ".dat"; //拡張子
	string path = "C:\\work\\C_lang\\20220413_diff_C_puls\\005_NS_eq_2D\\NS2d\\NS2d\\"; //絶対パス

	ostringstream temp;
	temp << time_;
	string pathName = path.append(name_).append(temp.str()).append(myfileType);
	//std::cout << "pathName = " << pathName << " :  pathName.size() = " << pathName.size() << std::endl;


	//char* cstr = new char[pathName.size() + 2]; // メモリ確保
	//std::cout << "cstr = " << &cstr << std::endl;
	//strcpy_s(cstr, name2.size() + 2, name2.c_str());

	FILE* outfile;
	fopen_s(&outfile, pathName.c_str(), "w+t"); //https://www.paveway.info/entry/2018/12/25/cpp_std_string_char

	//std::cout << "outfile = " << &outfile << std::endl;

	// tcplot format - Paraview is an Open Source Software for visualization
	int NXtemp = Utemp.size();
	int NYtemp = Utemp[0].size();

	fprintf(outfile, "VARIABLES=\"X\",\"Y\",\"U\",\"V\"\"P\"\n");
	fprintf(outfile, "ZONE  F=POINT\n");
	fprintf(outfile, "I=%d, J=%d\n", NXtemp, NYtemp);


	for (int i = 0; i < NYtemp; i++)
	{
		for (int j = 0; j < NXtemp; j++)
		{
			double xpos, ypos, UU, VV, PP;
			xpos = Utemp[i][j].x;
			ypos = Utemp[i][j].y;
			UU = Utemp[i][j].value;
			VV = Vtemp[i][j].value;
			PP = Ptemp[i][j].value;

			//%5.8lf\t

			fprintf(outfile, "%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\n", xpos, ypos, UU, VV, PP);
		}
	}

	fclose(outfile);


}

FileWriter::~FileWriter()
{
}