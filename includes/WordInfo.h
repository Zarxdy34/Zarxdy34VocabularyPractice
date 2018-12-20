class WordInfo
{
private:
	string spell;
	string trans;
	int val;               //单词的难度，0~9，数值越大难度越高，初始为9
	int ID;                //单词在数据库中的ID
	int bookID;           //单词所在书的ID
	int unitID;           //单词所在书的单元
public:
	WordInfo() {spell = trans = ""; val = ID = bookID = unitID = 0;}
	WordInfo(const string str_wordinfo) {assignWord(str_wordinfo);}
	WordInfo(const string _spell,const string _trans, const int _val = 0, const int _ID = 0, const int _bookID = 0, const int _unitID = 0)
	{
		spell = _spell;
		trans = _trans;
		val = _val;
		ID = _ID;
		bookID = _bookID;
		unitID = _unitID;
	}
	void assignWord(const string str_wordinfo);
	string toString() const;
	string getSpelling() const {return spell;}
	string getTranslation() const {return trans;}
	int getVal() const {return val;}
	int getID() const {return ID;}
	int getBookID() const {return bookID;}
	int getUnitID() const {return unitID;}
	void Inc_Val() {if (this->val < 9) this->val++;}
	void Dec_Val() {if (this->val >= 0) this->val--;}
};

bool word_cmpByID(const WordInfo &a,const WordInfo &b) {return a.getID()<b.getID();}
bool word_cmpByVal(const WordInfo &a,const WordInfo &b) {return a.getVal()<b.getVal();}

void WordInfo :: assignWord(const string str_wordinfo)
{
	unsigned int l = 0, r = 0;
	while (l < str_wordinfo.length() && str_wordinfo[l] != '"') l++;
	r = l + 1;
	while (r < str_wordinfo.length() && str_wordinfo[r] != '"') r++;
	if (r >= str_wordinfo.length())
		returnError("importing word list" + str_wordinfo);
	spell = str_wordinfo.substr(l + 1, r - l - 1);

	l = r + 1;
	while (l < str_wordinfo.length() && str_wordinfo[l] != '"') l++;
	r = l + 1;
	while (r < str_wordinfo.length() && str_wordinfo[r] != '"') r++;
	if (r >= str_wordinfo.length())
		returnError("importing word list" + str_wordinfo);
	trans = str_wordinfo.substr(l + 1, r - l - 1);
	sscanf(str_wordinfo.substr(r + 1, str_wordinfo.length() - r - 1).c_str(), "%d%d%d%d", &val, &ID, &bookID, &unitID);
}

string WordInfo :: toString() const
{
	char buf[MAXBUF];
	sprintf(buf,"\"%s\" \"%s\" %d %d %d %d",spell.c_str(), trans.c_str(), val, ID, bookID, unitID);
	return string(buf);
}
