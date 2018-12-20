#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
//const char CURRENT_PATH[] = "Google\\ Translate\\ API/";
//const char CURRENT_PATH[] = "./";

char cmd[maxn];

void Get_JS(char *word)
{
	FILE *file;
	file = fopen("swap.txt","w");
	fprintf(file,"%s\n",word);
	fclose(file);
	sprintf(cmd,"%s","node main.js > info.txt");
	system(cmd);
	//file = fopen("info.txt","r");
	//fgets(buf,maxn,file);
	//cout << buf;
	//cout << strlen(buf);
}

int main(int argc,char **argv)
{
	Get_JS(argv[1]);
}
