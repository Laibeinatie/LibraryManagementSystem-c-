#pragma once
/**
* ��ʾͼ����ϸ��Ϣ
*/
#include<iostream>
#include "TitleInfo.h"
#include<vector>
using namespace std;
class Report
{
private:
	int isFlag = -1;
	
public:
	vector <TitleInfo> books;
	void menu();

	// ����б�
	void libraryList();

	// �������б�
	void wholesalePriceList();

	// ���ۼ��б�
	void retailPriceList();

	// �����б�
	void quantityList();

	// ��ֵ�б�
	void valuesList();

	// �����б�
	void dataList();




};

