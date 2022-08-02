#ifndef FILEWRITWE_H
#define FILEWRITWE_H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream> //ファイルの書き込みに必要
#include "Fields.h"
using namespace std;
using std::vector;
using std::string;

class FileWriter
{
public:
	FileWriter();//constructor
	virtual ~FileWriter(); //destructor

	void write1dField(Fields::vectorField1d&, string&);
	void write2dUVFields(Fields::vectorField2d&, Fields::vectorField2d&, Fields::vectorField2d&, int, std::string&);
};

#endif
