#include "test.h"

const int LEN_TAB = 50;
std::list < std::vector< unsigned int > > lista;
std::vector< unsigned int > hash;

void display()
{

	//system("CLS");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << " ZAWARTOSC LISTY: " << std::endl;
	std::cout << "---------------------------" << std::endl;
	lista.push_back(std::vector< unsigned int >());

	lista.front().push_back(255);

	for (std::list<std::vector< unsigned int >>::iterator i = lista.begin(); i != lista.end(); ++i) {
		for (std::vector< unsigned int >::iterator j = i->begin(); j != i->end(); ++j) {
			std::cout << std::hex << *j << " " << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//-------- 1 ------------

void push_front()
{
	std::vector< unsigned int > liczba;
	std::cout << "Podaj jaka liczbe wstawic na pocz\245tek listy: ";
	std::cin >> liczba.back();
	lista.push_front(liczba);
}

//--------- 2 -----------

void push_back()
{
	std::vector< unsigned int > liczba;
	std::cout << "Podaj jaka liczbe wstawic na koniec listy: ";
	std::cin >> liczba.back();
	lista.push_back(liczba);
}

//---------- 3 ---------

void pop_front()
{
	std::cout << "Nast\245pi usuni\251cie liczby z pocz\245tku listy";
	Sleep(2000);
	lista.pop_front();
}

//---------- 4 ---------

void pop_back()
{
	std::cout << "Nast\245pi usuni\251cie liczby z konca listy";
	Sleep(2000);
	lista.pop_back();
}

//---------- 5 ----------

void size()
{
	std::cout << "Liczb na li\230cie: " << lista.size();
	Sleep(2000);
}

//---------- 6 ----------

void max_size()
{
	std::cout << "Max liczb na li\230cie: " << lista.max_size();
	Sleep(5000);
}

//---------- 7 ----------

void empty()
{
	std::cout << "Czy lista pusta? -> ";
	if (lista.empty() == 1) std::cout << "TRUE"; else std::cout << "FALSE";
	Sleep(2000);
}

//---------- 8 ----------

void reverse()
{
	std::cout << "Nastapi odwrocenie kolejnosci liczb!";
	lista.reverse();
	Sleep(2000);
}

//---------- 9 ----------

void exit()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << "Koniec programu!";
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
//------------------------

void delEqual() {
	std::list<std::vector< unsigned int >>::iterator it1, it2;
	it1 = it2 = lista.begin();
	it2++;
	while (it1!=lista.end()) {
		if (it2 != lista.end()) {
			if (*it1 == *it2) {
				it2 = lista.erase(it2);//usuniecie i skok na nastpne
			}
			else {
				it2++;
			}
		}
		else {
			it1++;
			it2 = it1;
			if (it1 != lista.end())
				it2++;
		}
	}
}



std::string genHash(void)
{
	
	char sTab[LEN_TAB];
	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(alphanum) - 1;
	std::string str;
	for (int i = 0; i < LEN_TAB; ++i) {
		sTab[i] = alphanum[rand() % stringLength];
	}
	str = sTab;
	return str;
}


void gen_random(char *s, const int len) {

	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}


void test(unsigned int v, unsigned int n) {
	/* v = 1. 64B; 2. 96B; 3. 128B
	* n - how many hashes we generate
	* we need hash functions or table with hashes
	* if equal then we do sth
	* eff = n-retr/n
	*
	*/
	std::vector< unsigned int > hash (64);
	std::string strHash;
	float eff, sBefore, sAfter;
	if (v == 1)
	{
		for (unsigned int i = 1; i < n + 1; i++) {
			strHash = genHash();
			hash = SDBMHash(strHash);//replace with your function from hashfunctions
			lista.push_back(hash);
		}
		lista.sort();
		sBefore = lista.size();
		delEqual();
		sAfter = lista.size();
		display();
		eff = (sAfter / sBefore)*100 ;
		std::cout << "Efektywnosc na poziomie: "<< eff << "%" <<std::endl;
		
	}
	else if (v == 2)
	{
		//return eff;
	}
	else if (v == 3)
	{
		//return eff;
	}
	else
	{
		std::cout << "Error, wrong length" << std::endl;
		//return 0;
	}
}

