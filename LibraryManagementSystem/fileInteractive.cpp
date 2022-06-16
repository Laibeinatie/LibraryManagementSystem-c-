#include "fileInteractive.h"

// ����ת�ַ���
string fileInteractive::numberToString(int num) {
	string s1 = to_string(num);
	return s1;
}

// �־û��ڴ棨ջ������д���ļ���
 void fileInteractive::writeTxt(vector <TitleInfo> books) {
	
	ofstream f;
	f.open("BookData.txt", ios::out);
	for (auto book : books) {
		string tmpWrite = "";
		tmpWrite += book.getIsbn() + " " + book.getBookTitle() + " " + book.getAuthor() + " " + book.getPublisher() + " "
			+ book.getDataAdded() + " " + numberToString(book.getQtyOnHand()) + " " + numberToString(book.getWholesale()) + " " + numberToString(book.getRetail());
		f << tmpWrite << endl;
	}
	f.close();
}

// ͼ���ʼ�������ļ��ж�ȡ���ݣ�
 vector <TitleInfo> fileInteractive::readTxt() {
	vector <TitleInfo> books;
	ifstream infile;
	infile.open("BookData.txt", ios::in);
	while (infile >> isbn >> bookTitle >> author >> publisher >> dataAdded >> qtyOnHand >> wholesale >> retail) {
		TitleInfo tmpBook;
		tmpBook.setIsbn(isbn);
		tmpBook.setBookTitle(bookTitle);
		tmpBook.setAuthor(author);
		tmpBook.setPublisher(publisher);
		tmpBook.setDataAdded(dataAdded);
		tmpBook.setQtyOnHand(qtyOnHand);
		tmpBook.setWholesale(wholesale);
		tmpBook.setRetail(retail);
		books.push_back(tmpBook);
	}
	infile.close();
	return books;
}
