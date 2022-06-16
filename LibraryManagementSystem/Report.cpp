#include "Report.h"
#include "BookData.h"
#include "fileInteractive.h"
#include<algorithm>

void Report::menu() {
	int isFlag = -1;
	while (true) {
		cout << "\t\t\t\t\t1������б�" << endl;
		cout << "\t\t\t\t\t2���������б�" << endl;
		cout << "\t\t\t\t\t3�����ۼ��б�" << endl;
		cout << "\t\t\t\t\t4������������б�" << endl;
		cout << "\t\t\t\t\t5������ļ�ֵ���б�" << endl;
		cout << "\t\t\t\t\t6��������������б�" << endl;
		cout << "\t\t\t\t\t0�����ص����˵�" << endl;
		cout << "\t\t\t\t\t  �����루0 ~ 7��:" << endl;
		cin >> isFlag;
		switch (isFlag)
		{
		case 1: {
			system("cls");
			libraryList();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			wholesalePriceList();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			retailPriceList();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			quantityList();
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			valuesList();
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			dataList();
			system("pause");
			system("cls");
			break;
		}
		case 0: {
			system("cls");
			return;
		}
		default:
			cout << "�����������������" << endl;
			break;
		}
	}

}

// ����б�
void Report::libraryList() {
	cout << "����б�" << endl << endl;
	BookData bookData;
	bookData.books = fileInteractive().readTxt();
	bookData.showInfoLibrary();
}

// �������б�
void Report::wholesalePriceList() {
	cout << "�������б�" << endl;
	cout << "����" << " " << "������" << " " << "�����" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getWholesale() << " " << book.getQtyOnHand() << endl << endl;

	}

}

// ���ۼ��б�
void Report::retailPriceList() {
	cout << "���ۼ��б�" << endl;
	cout << "����" << " " << "���ۼ�" << " " << "�����" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getRetail() << " " << book.getQtyOnHand() << endl << endl;

	}
}

bool dataCmd(TitleInfo a, TitleInfo b) {
	if (a.getDataAdded() > b.getDataAdded()) {
		return true;
	}
	return false;
}

bool quantityCmd(TitleInfo a, TitleInfo b) {
	if (a.getQtyOnHand() > b.getQtyOnHand()) {
		return true;
	}
	return false;
}

bool valuesCmd(TitleInfo a, TitleInfo b) {
	if (a.getRetail() > b.getRetail()) {
		return true;
	}
	return false;
}
// �����б�
void Report::quantityList() {
	sort(books.begin(), books.end(), quantityCmd);
	cout << "�����б�" << endl ;
	// �ȶ�ͼ�鰴������Ӷൽ������
	cout << "����" << " " << "�����" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getQtyOnHand() << endl << endl;
	}
}

// ��ֵ�б�
void Report::valuesList() {
	sort(books.begin(), books.end(), valuesCmd);
	cout << "��ֵ�б�" << endl << endl;
	// ϵͳ�ȶ�ͼ�鰴ÿ������������ܶ�Ӵ�С��������
	cout << "����" << " " << "���ۼ�" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getRetail() << endl << endl;
	}

	

}

// �����б�
void Report::dataList() {
	sort(books.begin(), books.end(), dataCmd);
	cout << "�����б�" << endl << endl;
	// �ȶ�ͼ�鰴������ڽ�������
	cout << "����" << " " << "����" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getDataAdded() << endl << endl;
	}
}