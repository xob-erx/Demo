/*基于字符串匹配模式算法的病毒感染问题
author: 肖异骐
create timt:2021-11-2*/
#include <iostream>
using namespace std;

class String//define qsstring class
{
private:
	char* str;
	int length;
public:
	String(int maxlen)
	{
		str = new char[maxlen + 1];
		length = 0;
	}
	int getlen()
	{
		return length;
	}
	int* getnext() 
	{
		int* next = new int[length];
		int i = 0,j=-1; next[0] = -1;
		while (i < length - 1)
		{
			if (j == -1 || str[i] == str[j]) {
				++i; ++j; next[i] = j;
			}
			else j = next[i];
		}
		return next;
	}
	friend istream& operator>>(istream& in, String& S);
};
istream& operator>>(istream& in, String& S)
{
	in >> S.str;
	while (S.str[S.length] != '\0') {
		S.length++;
	}
	return in;
}
int main()
{
	String s(100);
	cin >> s;
	//cout << s.getlen();
	int *next = s.getnext();
	for (int i = 0; i < s.getlen(); i++)
	{
		cout << next[i] << " ";
	}
}