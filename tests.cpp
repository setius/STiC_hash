#include "tests.h"
#include "hashfunctions.h"

struct hash{
    unsigned int data;
    int index;								
    hash *next;    								// wskaźnik na następny element
    hash();        								
};
 
hash::hash() {
    next = 0;       							
}

struct list {
    hash *first;  								// wskaźnik na początek listy
    void addHash(unsigned int data, int index);
	void compHash (unsigned int n);
    void delHash(int index);
    void displayList ();
    list();
};
 
list::list() {
    first = 0;       							
}

void list::addHash(unsigned int data, int index){
    hash *new_hash = new hash;   				// tworzy nowy element listy
												
    new_hash->data = data;						// wypełniamy naszymi danymi
    new_hash->index = index;		
		
    if (first==0) 								// sprawdzamy czy to pierwszy element listy
    {											// jeżeli tak to nowy element jest teraz początkiem listy
        first = new_hash;		
    }		
    else		
    {											// w przeciwnym wypadku wędrujemy na koniec listy
        hash *temp = first;		
        while (temp->next)		
        {								
            temp = temp->next; 					// znajdujemy wskaźnik na ostatni element
        }		
        temp->next = new_hash;  				// ostatni element wskazuje na nasz nowy
        new_hash->next = 0;     				// ostatni nie wskazuje na nic
    }
}

void list::compHash(unsigned int n) {
	unsigned int index = 1;
	hash *temp = first;
	hash *check = first->next;//ustawiamy checka na drugim miejscu
	while (index < n) {
		if (temp->data == check->data) {
			std::cout << "powtorka" << std::endl;
			for (unsigned int i=1; i > n-1; i++) {
				check->data = check->next->data; 			//do checka przypisujemy kolejna wartosc
				check = check->next;			
			}
			temp = temp->next;
			index++;
		} else {
			temp = temp->next;
			check = check->next;	
			index++;
		}
	}
}


void list::delHash(int index){
	// jezeli to pierwszy element listy
	if (index == 1)
	{
		hash *temp = first;
		first = temp->next; //poczatek listy, 1 el. wskazuje na 2 el. itd..
	}

	// jeżeli nie jest to pierwszy element
	if (index >= 2)
	{
		int j = 1;

		// do usuniecia srodkowego elemetnu potrzebujemy wskaznika na osobe n-1
		// wskaznik *temp bedzie wskaznikiem na osobe poprzedzajaca osobe usuwana
		hash *temp = first;

		while (temp)
		{
			// sprawdzamy czy wskaznik jest na osobie n-1 niz usuwana
			if ((j + 1) == index) break;

			// jezeli nie to przewijamy petle do przodu
			temp = temp->next;
			j++;
		}

		// wskaznik *temp wskazuje teraz na osobe n-1
		// nadpisujemy wkaznik osoby n na osobe n+1
		// bezpowrotnie tracimy osobe n-ta

		// dodatkowo sprawdzamy czy aby nie jest to ostatni element
		// wtedy nalezy wyzerowac ostatni wskaznik
		if (temp->next->next == 0)
			temp->next = 0;

		// jezeli nie byl to ostatni element
		else
			temp->next = temp->next->next;
	}
}


void list::displayList(){									
    hash *temp = first;							// wskaznik na pierszy element listy
    while (temp)								// przewijamy wskazniki na nastepne elementy
    {
        std::cout<< std::hex << "data: " << temp->data << std::dec << " index: " << temp->index << std::endl;
        temp=temp->next;
    }
	std::cout << "-----------------------------------" << std::endl;
}

std::string genHash(void)
{
	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(alphanum) - 1;
	std::string str;
	str = alphanum[rand() % stringLength];
	return str;
}

double test(unsigned int v, unsigned int n){
	/* v = 1. 64B; 2. 96B; 3. 128B
	 * n - how many hashes we generate
	 * we need hash functions or table with hashes
	 * if equal then we do sth
	 * eff = n-retr/n
	 *
	 */
	
	hash Hash;
	list HashList;
	std::string strHash;
	double eff = 0;
	if ( v == 1 )
	{
		for (unsigned int i = 1; i < n+1; i++) {
			strHash = genHash();
			Hash.data = SDBMHash(strHash);//replace with your function
			HashList.addHash(Hash.data, i);
		}
		HashList.displayList();
		HashList.compHash(n);//compare if eq del else do nothing
		HashList.displayList();
		//check efficiency
		return eff;
	}	
	else if ( v == 2 )
	{
		return eff;
	}	
	else if ( v == 3 )
	{
		return eff;
	}	
	else 
	{
		std::cout << "Error, wrong length" << std::endl;
		return 0;
	}
}

