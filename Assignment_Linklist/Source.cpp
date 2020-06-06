

#include <iostream>
#include <fstream>
using namespace std;

struct node {
	int data;
	node* next;
};

struct list {
	node* head;

};

void InitLinked_List(list& l) {
	l.head = nullptr;
}

node* getNode(int x) {
	node* p = new node();
	if (p == nullptr) return nullptr;
	p->data = x;
	p->next = nullptr;
	
	return p;
}

void Add_Head(list& l, int x) {
	
	node* p = getNode(x);
	if (l.head == nullptr) {
		l.head = p;
	}
	else {
		node* cur = l.head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = p;
	}
}

void PrintList(list& l) {
	if (l.head == nullptr) return;
	node* cur = l.head;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "0";
}

void InPut(ifstream& fin, list& l) {
	
	while (true) {
		int x;
		fin >> x;
		if (x == 0) break;
		Add_Head(l, x);
	}
}
/*
Remove all x
Load a sequence of integer numbers from a text file.Ask user to enter a value x.If x exists, remove all
occurrences of x out of the list.Otherwise, do not thing.Save the list to another text file.
Input:
1 2 2 4 2 6 0
User enter 2
Ouput : 
1 4 6 0
*/

void RemoveALL(list& l, int x)
{
	if (l.head == nullptr) return;

	while (l.head != nullptr && l.head->data == x ) {
		node* temp = l.head;
		l.head = l.head->next;
		delete temp;
	}
	node *cur = l.head;
	while (cur->next) {
		if (cur->next->data == x) {
			node* temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
		else {
			cur = cur->next;
		}
	}
}

/*3.2 Remove duplicates
Load a sequence of integer numbers from a text file. If an element appears twice or more, remove it so
that it appears only once. Save the list to another text file.
Input:
1 2 2 4 2 6 0
Ouput:
1 2 4 6 0*/

void RemoveDuplicate(list& l) {
	// Time Complexity is O(N^2);
	for (node* cur = l.head; cur; cur = cur->next) {

		node* cur1 = cur;

		while (cur1->next) {
			if (cur1->next->data == cur->data) {
				node* temp = cur1->next;
				cur1->next = cur1->next->next;
				delete temp;
			}
			else {
				cur1 = cur1->next;
			}
		}
	}
	
}

void Sorted_LinkedList(list& l) {
	// increase
	if (l.head == nullptr) return;
	for (node* p = l.head; p->next; p = p->next) {
		for (node* p1 = p->next; p1; p1 = p1->next) {
			if (p->data > p1->data) {
				swap(p->data, p1->data);
			}
		}
	}
}

void RemoveDuplicate_AfterSorted(list &l){
	

	//Time complexity is O(N); 
	if (l.head == nullptr) return;
	
	node* cur = l.head;
	while (cur->next) {
		if (cur->data == cur->next->data) {
			node* temp = cur->next;
			cur->next = temp->next;
			delete temp;
		}
		else {
			cur = cur->next;
		}
	}
}

void Reverse_LinkedList(list& l) {

	if (l.head == nullptr) return;
	node* next;
	node* cur = l.head;
	node* prev = nullptr;

	while (cur) {

		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	l.head = prev;
}

void AddFrist(list& l, int x) {
	if (l.head == nullptr) return;
	node* p = l.head;

	p->next = l.head;
	l.head = p;
}


void InsertEvenNumber(list& l) {

	int even = 2, count = 0;

	if (l.head == nullptr) return;
	// Add Head
	node* tmp = getNode(even);
	tmp->next = l.head;
	l.head = tmp;
	even += 2;

	// Add Mid
	node* cur = l.head->next;
	node* prev = l.head;
	while (cur->next) {	
		prev = cur;
		cur = cur->next;

		node* temp = getNode(even);
		prev->next = temp;
		temp->next = cur;
		even += 2;

	}

}

void InsertEvenNumber_KAISEN(list& l) {
	if (l.head == nullptr) return;
	int even = 2;

	node* add = getNode(even);
	add->next = l.head;
	l.head = add; even += 2;
	node* cur = l.head->next;
	while (cur->next) {
		
		node* NEXT = cur->next;
		node* p = getNode(even); even += 2;
		cur->next = p;
		p->next = NEXT;
		cur = NEXT;

	}

}

int main(void) {

	ifstream fin("TestFile.txt");
	if (fin.fail()) {
		cout << "Can't opent file. ";
		return 0;
	}
	else {
		list l;
		InitLinked_List(l);
		InPut(fin, l);
	
		/* write function to solve problems right here. (Question 1.) */
		
	//	RemoveALL(l, 2);

		/* write function to solve problems right here.(Question 2.) */

	//	RemoveDuplicate(l);

		/* write function to solve problems right here.(Question Sorted LinkedList.) */

		/*Sorted_LinkedList(l);
		RemoveDuplicate_AfterSorted(l);*/

		/* write function to solve problems right here.(Question 3.) */
	//	Reverse_LinkedList(l);

		PrintList(l); cout << endl;
		/* write function to solve problems right here.(Question 4.) */

		InsertEvenNumber_KAISEN(l);
		PrintList(l);

	}

}