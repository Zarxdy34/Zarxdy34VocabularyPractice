class BookInfo
{
private:
	string name;
	int ID;
	int unitNum;
public:
	BookInfo() {name="";ID=0;unitNum=0;}
	BookInfo(const string str_bookinfo) {assignBook(str_bookinfo);}
	void assignBook(const string str_bookinfo);
	string toString() const;
	string getName() const {return name;}
	int getID() const {return ID;}
	int getUnitNum() const {return unitNum;}
	void update_unitNum(const int _unitNum) {unitNum = max(_unitNum, unitNum);}
};

bool book_cmpByID(const BookInfo &a,const BookInfo &b) {return a.getID()<b.getID();}

void BookInfo :: assignBook(const string str_bookinfo)
{
	unsigned int infoLen = str_bookinfo.length();
	unsigned int pos = 1;
	while (pos < infoLen && checkIsNumber(str_bookinfo[infoLen - pos - 1])) pos++;
	pos++;
	while (pos < infoLen && checkIsNumber(str_bookinfo[infoLen - pos - 1])) pos++;
	if (pos == infoLen)
		returnError("importing book list " + str_bookinfo);
	sscanf(str_bookinfo.substr(infoLen - pos, pos).c_str(), "%d%d", &ID, &unitNum);
	name = str_bookinfo.substr(0, infoLen - pos - 1);
}

string BookInfo :: toString() const
{
	char buf[MAXBUF];
	sprintf(buf,"\"%s\" %d %d",name.c_str(), ID, unitNum);
	return string(buf);
}
