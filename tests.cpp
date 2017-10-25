#include "tests.h"

struct hash{
    string data;
    int index;								
    hash *next;    								// wskaźnik na następny element
    hash();        								
};
 
hash::hash() {
    next = 0;       							
}

struct list {
    hash *first;  								// wskaźnik na początek listy
    void add_hash(string data, int index);
    void del_hash(int index);
    void display_list ();
    list();
};
 
list::list() {
    first = 0;       							
}

void list::add_hash(string data, int index){
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

void list::delete_hash(int index){
    if (index>=2)
    {
        int j = 1;								// do usuniecia srodkowego elementu potrzebujemy wskaznika na hash n-1										
        hash *temp = first;		                // wskaznik *temp bedzie wskaznikiem na hash poprzedzajaca hash usuwana
		
        while (temp)		
        {		
			if ((j+1)==index) break;			// sprawdzamy czy wskaznik jest na hash n-1 niz usuwana      
												// jezeli nie to przewijamy petle do przodu
            temp = temp->next;
            j++;
        }
											
		if (temp->next->next==0)				// wskaznik *temp wskazuje teraz na hash n-1
		    temp->next = 0;						// nadpisujemy wkaznik ash n na hash n+1
												// bezpowrotnie tracimy hash n-ta
		else								
		    temp->next = temp->next->next;		// dodatkowo sprawdzamy czy aby nie jest to ostatni element
												// wtedy nalezy wyzerowac ostatni wskaznik
												// jezeli nie byl to ostatni element    
    }
}

void list::display_list(){									
    hash *temp = first;							// wskaznik na pierszy element listy
    while (temp)								// przewijamy wskazniki na nastepne elementy
    {
        cout << "data: " << temp->data << " index: " << temp->number << endl;
        temp=temp->next;
    }
}

double test(unsigned int v, unsigned int tab[n])
{
	/* v = 1-64 2-96 3-128
	 * n - how many hashes we generate
	 * we need hash functions or table with hashes
	 * if equal then we do sth
	 * eff = n-retr/n
	 *
	 */
	double eff;
	
	if ( v == 1 )
	{
		
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
