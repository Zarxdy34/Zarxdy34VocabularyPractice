#include <bits/stdc++.h>
using namespace std;

struct Info
{
	int x;
	Info();
	friend bool cmpByID(const Info &a,const Info &b) {return a.x<b.x;}
};

Info :: Info() {

}

int main()
{
	char buf[10];
	cout << string(buf);
}
