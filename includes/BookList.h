#include "BookInfo.h"
class BookList
{
private:
	vector <BookInfo> bookList;
public:
	void readFromFile(ifstream &inputFile);
	void writeToFile(ofstream &outputFile, ofstream &backupFile);
	auto insertBook(string bookName);
	BookInfo& operator[] (int x) {return bookList[x];}
	auto begin() {return bookList.begin();}
	auto rbegin() {return bookList.rbegin();}
	auto end() {return bookList.end();}
	auto rend() {return bookList.rend();}
	int size() {return bookList.size();}
	auto findByID(int bookID);
};

void BookList :: readFromFile(ifstream &inputFile)
{
	string tmp_bookinfo;
	while (getline(inputFile, tmp_bookinfo))
		bookList.push_back(BookInfo(tmp_bookinfo));
}

void BookList :: writeToFile(ofstream &outputFile, ofstream &backupFile)
{
	sort(bookList.begin(), bookList.end(), book_cmpByID);
	for (auto b : bookList)
	{
		outputFile << b.toString() << endl;
		backupFile << b.toString() << endl;
	}
}

auto BookList :: insertBook(string bookName)
{
	for (auto book = bookList.begin(); book != bookList.end(); ++book)
		if (book->getName() == bookName)
			return book;
	bookList.push_back(BookInfo(bookName));
	return bookList.end() - 1;
}

auto BookList :: findByID(int bookID)
{
	for (auto book = bookList.begin(); book != bookList.end(); ++book)
		if (book->getID() == bookID)
			return book;
	return bookList.end();
}
