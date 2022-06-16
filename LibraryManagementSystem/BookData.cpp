#include "BookData.h"

// ��Сд��ĸת��Ϊ��д��ĸ
string BookData:: strUpper(string s1) {
	string upper = "";
	for (int i = 0; i < s1.size(); i++) {
		upper += toupper(s1[i]);
	}
	return upper;
}

// ������������������
int BookData::sumTypeBook() {
	return int(books.size());
}

// ������������ʣ��������
int BookData::sumBook() {
	int num = 0;
	for (auto book : books) {
		num += book.getQtyOnHand();
	}
	return num;
}


// �������ͼ��
void BookData::showInfoLibrary() {
	cout << "ͼ�������" << " " << "����" << " " << "����" << " " << "������" << " " << "��������" << "�����" << " " << "������" << " " << "���ۼ�" << endl << endl;

	for (auto book : books) {
		cout << book.getIsbn() << " " <<book.getBookTitle() << " " << book.getAuthor()
			<< " " << book.getPublisher() << " " <<book.getDataAdded() << " " << book.getQtyOnHand()
			<< " " << book.getWholesale() << " " <<book.getRetail()  << endl;

		cout << endl;
	}
}