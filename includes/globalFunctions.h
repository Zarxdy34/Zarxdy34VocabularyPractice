bool checkIsNumber(char temp);
bool checkIsNumber(string temp);
int toNumber(string temp);
void returnError(string error_info);
void toVector(string temp, vector <int> &Vec);
bool inVector(int x, vector <int> &Vec);
string toString(int x);

bool checkIsNumber(char temp)
{
	return temp >= '0' && temp <= '9';
}

bool checkIsNumber(string temp)
{
	for (unsigned int i = 0; i < temp.length(); i++)
		if (temp[i] < '0' || temp[i] > '9') return false;
	return true;
}

int toNumber(string temp)
{
	int res = 0;
	for (unsigned int i = 0; i < temp.length(); i++)
		res = res * 10 + temp[i] - '0';
	return res;
}

void returnError(string error_info)
{
	char buf[MAXBUF];
	sprintf(buf, "Error while %s", error_info.c_str());
	string error_output(buf);
	cout << error_output << endl;
	quitApplication();
	exit(0);
}

void toVector(string temp, vector <int> &Vec)
{
	unsigned int l = 0, r = 0;
	while (l < temp.length())
	{
		while (l < temp.length() && !checkIsNumber(temp[l]))
			l++;
		r = l;
		while (r < temp.length() && checkIsNumber(temp[r+1]))
			r++;
		if (r == temp.length()) break;
		if (checkIsNumber(temp.substr(l, r - l + 1)))
			Vec.push_back(toNumber(temp.substr(l, r - l + 1)));
		l = r + 1;
	}
}

bool inVector(int x, vector <int> &Vec)
{
	for (auto i = Vec.begin(); i != Vec.end(); ++i)
		if (*i == x) return true;
	return false;
}

string toString(int x)
{
	if (x == 0) return "0";
	string res = "";
	int neg = 0;
	if (x < 0) neg = 1, x = -x;
	while (x)
	{
		res += '0' + x % 10;
		x /= 10;
	}
	if (neg) res += '-';
	reverse(res.begin(), res.end());
	return res;
}
