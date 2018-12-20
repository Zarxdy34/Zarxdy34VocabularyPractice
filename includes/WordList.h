#include "WordInfo.h"

class WordList
{
private:
	vector <WordInfo> wordList;
public:
	void readFromFile(ifstream &inputFile);
	void writeToFile(ofstream &outputFile, ofstream &backupFile);
	WordInfo& operator[] (int x) {return wordList[x];}
	auto begin() {return wordList.begin();}
	auto rbegin() {return wordList.rbegin();}
	auto end() {return wordList.end();}
	auto rend() {return wordList.rend();}
	int size() {return wordList.size();}
	auto push_back(const WordInfo x) {wordList.push_back(x);return wordList.end() - 1;}
};

void WordList :: readFromFile(ifstream &inputFile)
{
	string tmp_wordinfo;
	while (getline(inputFile, tmp_wordinfo))
		wordList.push_back(WordInfo(tmp_wordinfo));
}

void WordList :: writeToFile(ofstream &outputFile, ofstream &backupFile)
{
	sort(wordList.begin(), wordList.end(), word_cmpByID);
	for (auto w : wordList)
	{
		outputFile << w.toString() << endl;
		backupFile << w.toString() << endl;
	}
}
