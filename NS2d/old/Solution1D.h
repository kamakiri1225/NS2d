#ifndef SOLUTION_H
#define SOLUTION_H

class Solution1d
{
public:
	Solution1d(int&, double&, double&); // constructor
	virtual ~Solution1d(); //deconstructor

	int nt; //�X�e�b�v��
	double dt; //���ԍ��ݕ�
	double visc; //�S���W��
};

#endif