#include <bits/stdc++.h>
using namespace std;
const string OS = "linux";

#include "includes/includes.h"
#include "initialize.h"
#include "ImportFile.h"
#include "SpellingMain.h"

void Work()
{
	cout << "英语背单词软件 v1.0 Made by Zarxdy34" << endl;
	cout << "测试中，可能会有很多bug" << endl;
	cout << "退出时输入大写Q后回车，否则数据不会保存（将会在之后的版本处理这个问题）" << endl;
	cout << "需要导入书本的单词表：import" << endl;
	cout << "开始背单词：start" << endl;

	string buf;
	while (getline(cin,buf))
	{
		checkQuit(buf);
		if (buf == "import")
			Import_File();
		else if (buf == "start")
			Start_Spelling();
		else cout << "无效的指令" << endl;
		cout << "接下来要做什么？" << endl;
		cout << "退出时输入大写Q后回车，否则数据不会保存（将会在之后的版本处理这个问题）" << endl;
		cout << "需要导入书本的单词表：import" << endl;
		cout << "开始背单词：start" << endl;
	}
}

int main()
{
	initialize();
	Work();
	return 0;
}
