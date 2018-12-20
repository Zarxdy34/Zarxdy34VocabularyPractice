#include "config.h"
bool check_askDetail(string temp);
void Print_Detail(string ctr, string word);
int nextSplend(string temp,int start_pos);
int getSpellingLength(string temp);
bool checkSpellingCorrect(string a,string b);
void quitApplication();
#include "globalFunctions.h"
#include "WordList.h"
#include "BookList.h"

static WordList wordList;
static BookList bookList;

#include "Function.h"
#define ERROR -1
