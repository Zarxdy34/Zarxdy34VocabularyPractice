#include <bits/stdc++.h>
using namespace std;

void Find_Layer(string &s, int &l, int &r, int depth);
void Delete_Layer(string &s, int depth);
string Choose_Layer(string &s, int depth);
void Delete_HTML(string &s);

void Find_Layer(string &s, int &l, int &r, int depth)
{
	l = 0, r = 0;
	int cnt = 0;
	if (s[0] == '"')
	{
		while (s[++r] != '"');
		l = 1;
		r--;
		return;
	}
	while (r < (int)s.length() && !(cnt == depth && s[r] == ','))
	{
		if (s[r] == ']') cnt--;
		if (s[r] == '[' && cnt == depth) l = r + 1;
		if (s[r] == ']' && cnt == depth) break;
		if (s[r] == '[') cnt++;
		r++;
	}
	r--;
}

void Delete_Layer(string &s, int depth)
{
	int l, r;
	Find_Layer(s, l, r, depth);
	if (l > 0 && r < (int)s.length() - 1 && s[l - 1] == '"' && s[r + 1] == '"')
		l--, r++;
	while (l > 0 && r < (int)s.length() - 1 && s[l - 1] == '[' && s[r + 1] == ']')
		l--, r++;
	s.erase(l, r - l + 1);
	if (l < (int)s.length() && s[l] == ',') s.erase(l, 1);
}

string Choose_Layer(string &s, int depth)
{
	int l, r;
	Find_Layer(s, l, r, depth);
	return s.substr(l, r - l + 1);
}

void Delete_HTML(string &s)
{
	for (int i = 0; i < (int)s.length(); i++) if (s[i] == '\\')
	{
		if (s.substr(i,13) == "\\u003cb\\u003e") s.erase(i,13),s.insert(i,"\033[0;34m");
		if (s.substr(i,14) == "\\u003c/b\\u003e") s.erase(i,14),s.insert(i,"\033[0m");
	}
}

struct Word_Detail
{

	struct Word_Info_Main
	{
		string spelling;
		string announce;
	}Info0;

	struct Part_of_speech
	{
		struct translations
		{
			string translation;
		};
		vector <translations> trans;
	}Info1;

	struct Source_Language
	{
		string sourcelanguage;
	}Info2;

	struct Unknown
	{
		string temp;
	}Info3,Info4,Info5,Info6,Info7,Info8,Info9,Info10,Info11;

	struct Detail_Explain
	{
		struct Detail_Info
		{
			string partofspeech;
			struct Explain
			{
				struct Explain_Info
				{
					string explain;
					string Language;
					string example_sentence;
				};
				vector <Explain_Info> explain;

				void read(string info)
				{
					explain.clear();
					while (info.length() > 0)
					{
						static string now;
						now = Choose_Layer(info,0);
						static Explain_Info temp;
						temp.explain = Choose_Layer(now,0);
						Delete_Layer(now,0);
						temp.Language = Choose_Layer(now,0);
						Delete_Layer(now,0);
						temp.example_sentence = Choose_Layer(now,0);
						Delete_Layer(now,0);
						explain.push_back(temp);
						Delete_Layer(info,0);
					}
				}
			}explain;
			string word_spell;
		};

		vector <Detail_Info> DI;

		void read(string info)
		{
			DI.clear();
			while (info.length() > 0)
			{
				static string now;
				now = Choose_Layer(info,0);
				static Detail_Info temp;
				temp.partofspeech = Choose_Layer(now,0);
				Delete_Layer(now,0);
				temp.explain.read(Choose_Layer(now,0));
				Delete_Layer(now,0);
				temp.word_spell = Choose_Layer(now,0);
				DI.push_back(temp);
				Delete_Layer(info,0);
			}
		}

		void Print(int ctr, ofstream &fout)
		{
			int maxnum = 0;
			if (ctr == 0) maxnum = 1;
			else maxnum = ctr * 5;
			for (auto x = DI.begin(); x != DI.end(); ++x)
			{
				fout << (x - DI.begin()) + 1 << ":" << x->partofspeech << endl;
				for (auto y = x->explain.explain.begin(); y != x->explain.explain.end() && y != x->explain.explain.begin() + maxnum; ++y)
					fout << "    " << (y - x->explain.explain.begin()) + 1 << ":" << y->explain << endl
						 << "        " << y->example_sentence << endl;
			}
		}
	}Info12;

	struct Example_Sentence
	{
		struct Sentence
		{
			string sentence;
			int unknown_info[4];
			string encoding;
		};
		vector <Sentence> sentence;

		void read(string info)
		{
			sentence.clear();
			info = Choose_Layer(info,0);
			while (info.length() > 0)
			{
				static Sentence temp;
				static string now;
				now = Choose_Layer(info,0);
				temp.sentence = Choose_Layer(now,0);
				Delete_HTML(temp.sentence);
				temp.encoding = Choose_Layer(now,5);
				sentence.push_back(temp);
				Delete_Layer(info,0);
			}
		}

		void Print(int ctr, ofstream &fout)
		{
			int maxnum = 0;
			if (ctr == 0) maxnum = 1;
			else maxnum = ctr * 5;
			for (auto x = sentence.begin(); x != sentence.end() && x != sentence.begin() + maxnum; ++x)
				fout << (x - sentence.begin()) + 1 << ":" << x->sentence << endl;
		}
	}Info13;

	struct Example_Phrase
	{
		vector <string> phrase;

		void read(string info)
		{
			phrase.clear();
			info = Choose_Layer(info,0);
			while (info.length() > 0)
			{
				phrase.push_back(Choose_Layer(info,0));
				Delete_Layer(info,0);
			}
		}

		void Print(int ctr, ofstream &fout)
		{
			int maxnum = 0;
			if (ctr == 0) maxnum = 1;
			else maxnum = ctr * 5;
			for (auto x = phrase.begin(); x != phrase.end() && x != phrase.begin() + maxnum; ++x)
				fout << (x - phrase.begin()) + 1 << ":" << *x << endl;
		}
	}Info14;


	void read_from_string(string info)
	{
		info.erase(0, 1);
		info.erase(info.length() - 1, 1);
		for (int i = 0; i < 12; i ++)
			Delete_Layer(info, 0);
		Info12.read(Choose_Layer(info, 0));
		Delete_Layer(info, 0);
		Info13.read(Choose_Layer(info, 0));
		Delete_Layer(info, 0);
		Info14.read(Choose_Layer(info, 0));
		Delete_Layer(info, 0);
	}
}WDInfo;

void Get_More_Detail(const char* word, int detail_num = 0)
{
	char cmd[255];
	sprintf(cmd, "./Runjs %s", word);
	system(cmd);
	
	static ifstream info_file("info.txt");
	static string info;
	getline(info_file, info);

	WDInfo.read_from_string(info);
	info_file.close();
	//Print_Detail_Info(info, detail_num);
	//12:详细释义 第一层：0,1,2...词性 第二层：0：词性 1：实例 2：词本身
}

int main(int argc,char **argv)
{
	Get_More_Detail(argv[1]);
	static ofstream fout("info.txt");
	for (int i = 2; i < argc; i++)
	{
		if (strcmp(argv[i], "d") == 0) 
			WDInfo.Info12.Print(0, fout);
		if (strcmp(argv[i], "D") == 0) 
			WDInfo.Info12.Print(1, fout);
		if (strcmp(argv[i], "s") == 0)
			WDInfo.Info13.Print(0, fout);
		if (strcmp(argv[i], "S") == 0)
			WDInfo.Info13.Print(1, fout);
		if (strcmp(argv[i], "p") == 0)
			WDInfo.Info14.Print(0, fout);
		if (strcmp(argv[i], "P") == 0)
			WDInfo.Info14.Print(1, fout);
	}
	return 0;
}
