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
	void genHashes(unsigned int n);
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

void list::delHash(int index){
    if (index>=2)
    {
        int j = 1;								// do usuniecia srodkowego elementu potrzebujemy wskaznika na hash n-1										
        hash *temp = first;		                // wskaznik *temp bedzie wskaznikiem na hash poprzedzajacy hash usuwany
		
        while (temp)		
        {		
			if ((j+1)==index) break;			// sprawdzamy czy wskaznik jest na hash n-1 niz usuwany      
												// jezeli nie to przewijamy petle do przodu
            temp = temp->next;
            j++;
        }
											
		if (temp->next->next==0)				// wskaznik *temp wskazuje teraz na hash n-1
		    temp->next = 0;						// nadpisujemy wskaznik hash n na hash n+1
												// bezpowrotnie tracimy hash n-ty
		else								
		    temp->next = temp->next->next;		// dodatkowo sprawdzamy czy aby nie jest to ostatni element
												// wtedy nalezy wyzerowac ostatni wskaznik
												// jezeli nie byl to ostatni element    
    }
}

void list::displayList(){									
    hash *temp = first;							// wskaznik na pierszy element listy
    while (temp)								// przewijamy wskazniki na nastepne elementy
    {
        std::cout << "data: " << temp->data << " index: " << temp->index << std::endl;
        temp=temp->next;
    }
}

void list::genHashes(unsigned int n)
{
	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(alphanum) - 1;
	std::string str;

	hash *new_hash = new hash;
	list HashList;
	
	for (unsigned int i = 0; i < n; i++) {
		str = alphanum[rand() % stringLength];
		unsigned int data = SDBMHash(str);
		hash->data = data;
		//HashList.addHash(Hash.data, i);
	}
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
	std::string str;
	double eff = 0;
	if ( v == 1 )
	{
		HashList.genHashes(n);
		HashList.displayList();
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

