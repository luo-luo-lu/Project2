#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;
struct book{
	int isbn;
	char bookName[20];
	double price;
};

/*int main() {
	book b;
	b.isbn = 123456;
	strcpy_s(b.bookName,"Sample Book");
	b.price = 19.99;
	cout << "ISBN: " << b.isbn << endl;
	cout << "Book Name: " << b.bookName << endl;
	cout << "Price: $" << b.price << endl;

	system("pause");
	return 0;
}*/