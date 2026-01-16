#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>

using namespace std;

class MyString
{
private:
	int nrCaracteres;
	char* str;

public:


	MyString();
	MyString(const char* a);
	

	~MyString();
	MyString(const MyString& copia);
	MyString& operator=(const MyString& copia);




	void acrescenta(const char* texto);

	const char* obtemCString() const;

	bool removeDeAte(int inicio, int fim);
	bool mudaCharAt(int indice, char c);

};

