bool check_askDetail(string temp)
{
	if (temp.length() == 1 || temp[1] == ' ')
		if (temp[0] == 's' || temp[0] == 'S' || temp[0] == 'd' || temp[0] == 'D' || temp[0] == 'p' || temp[0] == 'P')
			return true;
	return false;
}

void Print_Detail(string ctr, string word)
{
	static char buf[2550];
	sprintf(buf, "./Get_Detail %s %s",word.c_str(),ctr.c_str());
	system(buf);
	static string temp;
	static ifstream info_file;
	info_file.open("info.txt");
	while (getline(info_file, temp))
	{
		strcpy(buf, temp.c_str());
		printf(buf);
		printf("\n");
	}
	info_file.close();
}

int nextSplend(string temp,int start_pos = 0)
{
	for (unsigned int i = start_pos; i < temp.length(); i++)
		if (temp[i] == ' ')
			return i;
	return -1;
}

int getSpellingLength(string temp)
{
	int pos = -1;
	if (temp.find(' ') == string::npos) return -1;
	for (int i = (int)temp.length() - 1; i >= 0; i--)
	{
		if (temp[i] < 0)
		{
			pos = i;
			while (pos>=0 && temp[pos] != ' ') pos--;
			while (pos>=0 && temp[pos] == ' ') pos--;
			if (pos == -1) return -1;
			i = pos + 1;
		}
	}
	int prv = pos;
	while (prv >= 0 && temp[prv] != ' ' && temp[prv] != '&') prv--;
	prv++;
	string tmp = temp.substr(prv, pos - prv + 1);
	if (tmp == "n." || tmp == "a." || tmp=="ad." || tmp=="adv." || tmp == "adj." || tmp == "vt." || tmp == "vi." || tmp == "v.")
	{
		while (pos>=0 && temp[pos] != ' ') pos--;
		while (pos>=0 && temp[pos] == ' ') pos--;
		if (pos == -1) return -1;
	}
	return pos + 1;
}

bool checkSpellingCorrect(string a,string b)
{
	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ') a.erase(i--, 0);
		else if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
	}
	for (unsigned int i = 0; i < b.length(); i++)
	{
		if (b[i] == ' ') b.erase(i--, 0);
		else if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 'a' - 'A';
	}
	return a == b;
}

void quitApplication()
{
	ofstream outputFile;
	ofstream backupFile;
	string outputFileName = "data/word_ist.txt";
	string backupFileName = "backup/wordlist" + toString((int)clock()) + ".txt";
	outputFile.open(PATH + outputFileName);
	backupFile.open(PATH + backupFileName);
	wordList.writeToFile(outputFile, backupFile);
	outputFileName = "data/book_list.txt";
	backupFileName = "backup/booklist" + toString((int)clock()) + ".txt";
	outputFile.open(PATH + outputFileName);
	backupFile.open(PATH + backupFileName);
	bookList.writeToFile(outputFile, backupFile);
	exit(0);
}

void checkQuit(string ctr)
{
	if (ctr == "Q")
		quitApplication();
}

