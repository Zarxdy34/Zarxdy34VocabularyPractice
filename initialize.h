void initialize()
{
	ifstream wordInputFile(PATH + "data/word_list.txt");
	ifstream bookInputFile(PATH + "data/book_list.txt");
	wordList.readFromFile(wordInputFile);
	bookList.readFromFile(bookInputFile);
	wordInputFile.close();
	bookInputFile.close();
}
