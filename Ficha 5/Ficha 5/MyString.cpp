#include "MyString.h"
#include <string>
#include <iostream>
#include <cstring>  
#include <sstream>
using namespace std;

//CONTRUTOR COM PARAMETROS
MyString::MyString(const char* a) {

	nrCaracteres = strlen(a);
	str = new char[nrCaracteres + 1];
	strcpy(str, a);

}
//CONSTRUTOR PADRAO
MyString::MyString() {
	 nrCaracteres = 0;
	str = new char[nrCaracteres + 1];
	str[0] = '\0';

}

//DESTRUTOR
MyString::~MyString() {
	delete[] str;
	str = nullptr;
}

//CONSTRUTOR POR COPIA
MyString::MyString(const MyString& copia) {
	
	nrCaracteres = copia.nrCaracteres;
	str = new char[nrCaracteres + 1];
	strcpy(str, copia.str);
}

//OPERADOR DE ATRIBUICAO
MyString& MyString::operator=(const MyString& outro) {

	if (this == &outro) {
		return *this;
	}
	delete[] str;
	nrCaracteres = outro.nrCaracteres;
	str = new char[nrCaracteres + 1];
	strcpy(str, outro.str);
	return *this;
	
}


void MyString::acrescenta(const char* texto) {  

    int novoTamanho = nrCaracteres + strlen(texto);  
    char* novo = new char[novoTamanho + 1];  
    strcpy(novo, this->str);  
    strcat(novo, texto);      
    delete[] this->str;      
    this->str = novo;        
    nrCaracteres = novoTamanho;  
}


const char* MyString::obtemCString() const {
    return str;
}

bool MyString::mudaCharAt(int indice, char c) {

		if (indice < 0 || indice >= nrCaracteres) {
    return false;
}
		
		str[indice] = c;
		
	return true;
	
}


bool MyString::removeDeAte(int inicio, int fim) {

	if (inicio < 0 || fim < 0 || inicio > fim || fim >= nrCaracteres) { return false; }
	
		int caracteresSub = fim - inicio + 1;
		int novoTamanho = nrCaracteres - caracteresSub;
		char* novo = new char[novoTamanho + 1];
		strncpy(novo, str, inicio);
		novo[inicio] = '\0';
		strcat(novo, str + fim + 1);
		delete[] str;
		str = novo;
		nrCaracteres = novoTamanho;


		return true;
}