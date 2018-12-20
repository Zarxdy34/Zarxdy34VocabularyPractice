void Import_File()
{
	cout << "输入导入文件的文件名（英文，后缀名为.txt，输入时无需加上后缀名，放在import_file文件夹下面）" << endl;
	cout << "注意：书本分单元时，单元的名字为\"unit 数字\"（区分大小写），书本不分单元的情况下按照单元编号为1处理" << endl;
	string importFileName;
	getline(cin, importFileName);

	ifstream fin("import_file/" + importFileName + ".txt");
	string temp;
	auto book = bookList.insertBook(importFileName);
	int bookID = book->getID();
	int unitID = 1;
	int line = 0;
	cout << "Every time check if it is right:" << endl;
	cout << "If it is not right, print \'n\', otherwise press ENTER to continue." << endl;
	cout << "If you have already checked the importing text, print \'a\' to skip all requests." << endl;
	int acceptAll = 0;
	while (getline(fin, temp))
	{
		if (temp.substr(0,4) == "unit" && checkIsNumber(temp.substr(5, temp.length() - 5)))
		{
			unitID = toNumber(temp.substr(5, temp.length() - 5));
			continue;
		}
		int mid = 0;
		line++;
		mid = getSpellingLength(temp);
		if (mid == -1)
			returnError("importing new words from" + importFileName);
		if (!acceptAll) while (1)
		{
			cout << temp.substr(0,mid) << "     -Spelling" << endl;
			cout << temp.substr(mid + 1, temp.length() - mid - 1) << "     -Translation" <<  endl;
			string ctr;
			if (!acceptAll)
			{
				getline(cin, ctr);
				checkQuit(ctr);
			}
			if (ctr == "a") acceptAll = 1;
			if (ctr != "n" || acceptAll) break;
			mid = (mid + 1) % temp.length();
			while (temp[mid] != ' ') mid = (mid + 1) % temp.length();
		}
		WordInfo newWord(temp.substr(0, mid), temp.substr(mid + 1, temp.length() - mid - 1), 9, wordList.size() + 1, bookID, unitID);
		wordList.push_back(newWord);
	}
	book->update_unitNum(unitID);
	cout << "Done, book <<" << book->getName() << ">>, " << book->getUnitNum() << "units." << endl;
	fin.close();
}
