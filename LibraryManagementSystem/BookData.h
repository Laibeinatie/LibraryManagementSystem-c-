#pragma once
#include "TitleInfo.h"
#include "Sale.h"
#include<string>
#include<vector>
#include<fstream>
using namespace std;



class BookData :public TitleInfo
{
public:
	// �����������������Ϣ
	vector <TitleInfo> books;

	// ��Сд��ĸת��Ϊ��д��ĸ
	static string strUpper(string s1);

	// ������������������
	int sumTypeBook();

	// ������������ʣ��������
	int sumBook();

	

	// �������ͼ��
	void showInfoLibrary();

};

