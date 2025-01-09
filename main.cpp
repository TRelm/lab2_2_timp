#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
	wstring t=Text;
	try {
		Cipher cipher(key);
		wcout<<cipher.encrypt(key, t)<<endl;
		wstring en=cipher.encrypt(key, t);
        wcout<<cipher.decrypt(key, en)<<endl;
	} catch (const cipher_error & e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}
int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	check(L"HELLO",2);
	check(L"HelLo",5);
	check(L"HELLO",0);
	return 0;
}
