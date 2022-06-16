#include "Sale.h"
#include "fileInteractive.h"
#include <time.h>
#include<windows.h>
// ��ʾ������Ϣ

void Sale::showInfo() {

	cout << "���ڣ�";
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << sys.wYear << "��" << sys.wMonth << "��" << sys.wDay << "��" << sys.wHour << "ʱ" << sys.wMinute << "��" << sys.wSecond << "��" << endl;
	cout << endl;
	cout << "����" << " " << "ISBN��" << " " << "����" << " ���� " << "���" << endl;
	for (auto book : shopping) {
		cout << book.getQtyOnHand() << " " << book.getIsbn() << " "
			<< book.getBookTitle() << " " << book.getRetail() << " "
			<< book.getWholesale() << endl;
	}
	for (int i = 0; i < 80; i++) cout << "*";
	cout << endl;
	cout << "���ۺϼƣ�" << "RMB " << totalSales << endl;
	cout << "����˰��" << "RMB " << tetailTax << endl;
	cout << "Ӧ���ܶ" << "RMB " << amountPayable << endl;
}


// ����ͼ��
void Sale::shoppingBooks(string _isbn, int qty) {
	Manage manage;
	manage.books = fileInteractive().readTxt();
	int index = manage.lookUpIsbn(_isbn);
	if (index != -1) {
		if (books[index].getQtyOnHand() >= qty) {
			TitleInfo tmpbook = manage.books[index];
			tmpbook.setQtyOnHand(qty);
			manage.books[index].setQtyOnHand(manage.books[index].getQtyOnHand() - qty);
			shopping.push_back(tmpbook);
			totalSales += tmpbook.getRetail() * qty;
			tetailTax += 2 * qty;
			amountPayable = totalSales + tetailTax;
			fileInteractive fileWite;
			fileWite.writeTxt(manage.books);

			cout << "����ɹ���" << endl;
			
		}
		else {
			cout << "����ʧ�ܣ������������" << endl;
		}
	}
	else {
		cout << "����ʧ�ܣ����޴�ͼ����" << endl;
	}
	
	
}

void Sale::menu() {
	int isFlag = -1;
	while (true) {
		cout << "\t\t\t\t\t1������ͼ��" << endl;
		cout << "\t\t\t\t\t2������ͼ��" << endl;
		cout << "\t\t\t\t\t3���ѹ���ͼ��" << endl;
		cout << "\t\t\t\t\t0���˳�����" << endl;
		cout << "\t\t\t\t\t  �����루0 ~ 2��:" << endl;
		cin >> isFlag;
		switch (isFlag) {
		case 3: {
			system("cls");
			showInfo();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			string isbn;
			int qty;
			cout << "�����빺��ͼ����" << endl;
			cin >> isbn;
			cout << "�����빺������" << endl;
			cin >> qty;
			shoppingBooks(isbn, qty);
			system("pause");
			system("cls");
			break;
		}
		case 1: {
			  system("cls");
			  Manage bookData;
			  bookData.books = fileInteractive().readTxt();
			  bookData.lookUpBook();
			  system("pause");
			  system("cls");
			  break;
		}
		case 0: {
			
			
			system("cls");
			return;
		}
		default: {
			system("cls");
			cout << "�����������������" << endl;
		}
		}
	}
}