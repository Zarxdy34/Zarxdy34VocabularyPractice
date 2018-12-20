void getRange(int &bookID, vector <int> &unitID)
{
	cout << "选择要背的书，输入他的编号" << endl;
	for (auto book = bookList.begin(); book != bookList.end(); ++book)
		cout << book->getID() << "." << book->getName() << endl;
	string ctr;
	getline(cin, ctr);
	checkQuit(ctr);
	bookID = toNumber(ctr);
	while (!checkIsNumber(ctr) || bookID <= 0 || bookID > bookList.size())
	{
		if (!checkIsNumber(ctr)) cout << "Not a number." << endl;
		else cout << "No such book." << endl;
		cout << "重新输入书的编号" << endl;
		getline(cin, ctr);
		checkQuit(ctr);
		bookID = toNumber(ctr);
		checkQuit(ctr);
	}
	auto book = bookList.findByID(bookID);
	cout << "本书有" << book->getUnitNum() << "个单元" << endl;
	cout << "输入要背的单元（如果全部要背则输入a），每两个数字之间用一个空格隔开，" << endl;
	getline(cin, ctr);
	checkQuit(ctr);
	unitID.clear();
	if (ctr == "a")
	{
		for (int i = 1; i <= book->getUnitNum(); i++)
			unitID.push_back(i);
	}
	else toVector(ctr,unitID);
}

int selectWords()
{
	int bookID;
	static vector<int> select_unitID;
	getRange(bookID, select_unitID);
	cout << "OK searching words that in <<" << bookList.findByID(bookID)->getName() << ">> and unit num is ";
	for (auto x = select_unitID.begin(); x != select_unitID.end(); ++x) cout << *x << " ";
	cout << endl;
	srand(time(0));
	random_shuffle(wordList.begin(), wordList.end());
	int num = 0;
	for (unsigned int i = 0; i < wordList.size(); i++)
		if (wordList[i].getBookID() == bookID && find(select_unitID.begin(),select_unitID.end(),wordList[i].getUnitID()) != select_unitID.end())
	swap(wordList[i], wordList[num++]);
	return num;
}

void Start_Spelling()
{
	int wordNum = selectWords();
	for (int i = 0; i < wordNum; i++)
	{
		cout << endl << i << ". " << wordList[i].getTranslation() << endl;
		string temp;
		getline(cin, temp);
		checkQuit(temp);
		if (i > 0 && check_askDetail(temp))
		{
			Print_Detail(temp, wordList[i - 1].getSpelling());
			while (1)
			{
				cout << wordList[i].getTranslation() << endl;
				getline(cin, temp);
				checkQuit(temp);
				if (check_askDetail(temp))
					Print_Detail(temp, wordList[i - 1].getSpelling());
				else break;
			}
		}
		int wrong_time = 0;
		while (!checkSpellingCorrect(wordList[i].getSpelling(), temp))
		{
			wrong_time++;
			cout << "Wrong!" << endl;
			cout << "The correct spelling is " << wordList[i].getSpelling() << ", spell again." << endl;
			getline(cin, temp);
			checkQuit(temp);
		}
		cout << "Correct!" << endl;
		if (wrong_time == 0) wordList[i].Dec_Val();
		else wordList[i].Inc_Val();
		continue;
	}
	cout << "Done, " << wordNum << " words." << endl;
}
