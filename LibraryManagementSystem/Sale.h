#pragma once
/**
* �������۹���
*/
#include "BookData.h"
#include "TitleInfo.h"
#include "Manage.h"
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
class Sale 
{
private:
	int totalSales = 0; // ���ۺϼ�
	int tetailTax = 0; // ����˰
	int amountPayable = 0; // Ӧ�����
	vector<TitleInfo>shopping;
	

public:
	// �����������������Ϣ
	vector <TitleInfo> books;
	// ����ͼ��
	void shoppingBooks(string _isbn, int qty);

	void showInfo();

	void menu();

	
};

