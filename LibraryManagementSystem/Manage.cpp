#include "Manage.h"
#include "fileInteractive.h"


Manage::Manage(){}

// ����ISBN��
int Manage::lookUpIsbn(string _isbn) {
	int cc = 0;
	for (auto book : books) {
		
		if (book.getIsbn() == _isbn) {
			
			return cc;
		}
		cc++;
	}
	return -1;

}

// ����ͼ��(֧��ģ������)
void Manage::lookUpBook() {
	cout << "���������ѯ�������(֧��ģ����ѯ)" << endl;
	string bookName;
	cin >> bookName;
	int isEmpty = -1;
	string::size_type pos = 0;
	for (auto book : books) {
		if (book.getBookTitle().find(bookName, pos) != string::npos) {
			isEmpty = 1;
			book.toString();
			cout << endl;
		}
	}
	if (isEmpty == -1) {
		cout << "û�����ͼ��" << endl;
	}
}



// ����ͼ��
void Manage::createBook() {
	cout << "������ͼ��ISBN��:" << endl;
	cin >> isbn;
	int cc = lookUpIsbn(isbn);
	if (cc != -1) {
		int someNum;
		cout << "ISBN����Ѿ�����, ������ͼ�������" << endl;
		cin >> someNum;
		books[cc].setQtyOnHand(books[cc].getQtyOnHand() + someNum);
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		return;
	}
		
	cout << "������������" << endl;
	cin >> bookTitle;

	cout << "��������������" << endl;
	cin >> author;

	cout << "��������������ƣ�" << endl;
	cin >> publisher;

	cout << "������������ڣ�" << endl;
	cin >> dataAdded;

	cout << "������������" << endl;
	cin >> qtyOnHand;

	cout << "��������������ۣ�" << endl;
	cin >> wholesale;

	cout << "������������ۼۣ�" << endl;
	cin >> retail;
	TitleInfo tmpBook(isbn, bookTitle, author, publisher, dataAdded, qtyOnHand, wholesale, retail);
	books.push_back(tmpBook);
	fileInteractive fileWite;
	fileWite.writeTxt(books);
}

// ����ͼ��
void Manage::updateBook() {
	string isbn;
	cout << "����������鼮��ISBN�ţ�" << endl;
	cin >> isbn;
	index = lookUpIsbn(isbn);
	if (index != -1) {
		cout << "ͼ�����ҵ���" << endl;

		cout << "������������" << endl;
		cin >> bookTitle;
		books[index].setBookTitle(bookTitle);

		cout << "��������������" << endl;
		cin >> author;
		books[index].setAuthor(author);

		cout << "��������������ƣ�" << endl;
		cin >> publisher;
		books[index].setPublisher(publisher);

		cout << "������������ڣ�" << endl;
		cin >> dataAdded;
		books[index].setDataAdded(dataAdded);

		cout << "������������" << endl;
		cin >> qtyOnHand;
		books[index].setQtyOnHand(qtyOnHand);

		cout << "��������������ۣ�" << endl;
		cin >> wholesale;
		books[index].setWholesale(wholesale);

		cout << "������������ۼۣ�" << endl;
		cin >> retail;
		books[index].setRetail(retail);

		cout << "ͼ����Ϣ�Ѿ�����" << endl;
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		books[index].toString();
		index = -1;
		return;
	}
	cout << "�������ISBN��û�ҵ���" << endl;

}

// ɾ��ͼ��
void Manage::deleteBook() {
	string isbn;
	cout << "������ɾ��ͼ���ISBN�ţ�" << endl;
	cin >> isbn;
	index = lookUpIsbn(isbn);
	if (index != -1) {
		books.erase(books.begin() + index);
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		cout << "���Ϊ��" << isbn << " ��ͼ���Ѿ�ɾ����" << endl;
		index = -1;
		return;
	}

	cout << "�������ISBN��û�ҵ���" << endl;
}

// ����ͼ��
void Manage::deleteNumber(string _isbn) {
	string isbn;
	cout << "������ɾ��ͼ���ISBN�ţ�" << endl;
	cin >> isbn;
	index = lookUpIsbn(isbn);
	if (index != -1) {
		books[index].setQtyOnHand(books[index].getQtyOnHand() - 1);
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		index = -1;
		return;
	}
	cout << "�������ISBN��û�ҵ���" << endl;
}

void Manage::menu() {
	int isFlag = -1;
	
	while (true) {
		cout << "\t\t\t\t\t1������ͼ����Ϣ" << endl;
		cout << "\t\t\t\t\t2�����ͼ����Ϣ" << endl;
		cout << "\t\t\t\t\t3���޸�ͼ����Ϣ" << endl;
		cout << "\t\t\t\t\t4��ɾ��ͼ����Ϣ" << endl;
		cout << "\t\t\t\t\t5���������ͼ��" << endl;
		cout << "\t\t\t\t\t0�����ص����˵�" << endl;
		cout << "\t\t\t\t\t  ����ѡ��0 ~ 4��:" << endl;
		cin >> isFlag;
		switch (isFlag) {
		case 1: {
			system("cls");
			lookUpBook();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			createBook();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			updateBook();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			deleteBook();
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			BookData bookData;
			bookData.books = fileInteractive().readTxt();
			bookData.showInfoLibrary();
			system("pause");
			system("cls");
			break;
			
		}
		case 0: {

			system("cls");
			return;
		}
		default: {
			cout << "�����������������" << endl;
		}

		}
	}
}