#pragma once
/**
* ���ڱ���ͼ��Ļ�����Ϣ��
* ��Ҫ���������������硢ISBN�š����ߵȣ�
* �Լ������Щ���ݳ�Ա��һЩ������Ա��
*/
#include<string>
#include<iostream>
using namespace std;
class TitleInfo
{
protected:
	string isbn; // ��ı�׼����
	string bookTitle; // ����
	string author; // ����
	string publisher; // ����������
	string dataAdded; // ��������
	int qtyOnHand; // �����
	int wholesale; // ������
	int retail; // ���ۼ�

public:
	TitleInfo();
	
	TitleInfo(string _isbn, string _bookTitle, string _author, string _publisher, string _dataAdded, int _qtyOnhand, int _wholesale, int _retail) :
		isbn(_isbn), bookTitle(_bookTitle), author(_author), publisher(_publisher), dataAdded(_dataAdded), qtyOnHand(_qtyOnhand), wholesale(_wholesale), retail(_retail){}
	void setIsbn(string _isbn);

	string getIsbn() ;

	void setBookTitle(string _bookTitle);
	string getBookTitle();

	void setAuthor(string _author);
	string getAuthor();

	void setPublisher(string _publisher);
	string getPublisher();

	void setDataAdded(string _dataAdded);
	string getDataAdded();

	void setQtyOnHand(int _qtyOnHand);
	int getQtyOnHand();

	void setWholesale(int _wholesale);
	int getWholesale();

	void setRetail(int _retail);
	int getRetail();

	void toString();

};


