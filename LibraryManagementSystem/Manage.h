#pragma once
/**
* ��ͼ�����CRUD����
*/
#include<iostream>
#include<string>
#include "TitleInfo.h"
#include "BookData.h" 
#include<vector>

using namespace std;

class Manage: public TitleInfo
{
private:
	int index;

public:
	vector <TitleInfo> books;
	// ����ISBN��
	int lookUpIsbn(string _isbn);

	// ����ͼ��(֧��ģ������)
	void lookUpBook();

	// ����ͼ��
	void createBook();

	// ����ͼ��
	void updateBook();
		
	// ɾ��ͼ��
	void deleteBook();

	// ����ͼ��
	void deleteNumber(string _isbn);



	void menu();

	Manage();


};

