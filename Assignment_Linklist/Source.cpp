

#include <iostream>
#include <fstream>
using namespace std;

struct node {
	int data;
	node* next;
};

struct list {
	node* head;
	node* tail;
};

void InitLinked_List(list& l) {
	l.head = nullptr;
	l.tail = nullptr;
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

void Add_Tail(list& l, int x) {

	node* p = getNode(x);
	if (l.head == nullptr) {
		l.head = l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
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

	while (l.head != nullptr && l.head->data == x) {
		node* temp = l.head;
		l.head = l.head->next;
		delete temp;
	}
	node* cur = l.head;
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

void RemoveDuplicate_AfterSorted(list& l) {


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

/*Sorted list
Given a linked list of integers sorted from smallest to largest (head to end). Insert a new integer into the
linked list so that it remains sorted.
Input:
27
10 20 30 40 50 60 0
Output:
10 20 27 30 40 50 60 0*/


void Sorted_LinkedList(list& l, int x) {
	if (l.head == nullptr) return;

	if (l.head->data > x) {

		node* temp = getNode(x);
		temp->next = l.head;
		l.head = temp;
	}
	else {

		bool flag = false;
		//cout << "1" << endl;
		node* cur = l.head->next;
		node* prev = l.head;
		node* tmp = getNode(x);
		while (cur) {

			if (cur->data > x) {

				prev->next = tmp;
				tmp->next = cur;
				flag = true;
				break;
			}
			else {
				prev = cur;
				cur = cur->next;
			}
		}
		if (flag == false) {
			node* Move = l.head;
			while (Move->next) {
				Move = Move->next;
			}
			Move->next = tmp;
		}
	}

}

list ListofSum(list& l) {


	if (l.head == nullptr) return l;
	list k;
	InitLinked_List(k);


	// Fibonacci sequence
	/*node* prev = l.head;
	node* cur = l.head->next;
	Add_Head(k, prev->data);
	while (cur) {
		Add_Head(k, prev->data + cur->data);
		prev = cur;
		cur = cur->next;
	}
	return k;*/

	int y = 0;

	node* cur = l.head;
	while (cur) {
		int res = cur->data + y;
		Add_Head(k, res);
		y = res;
		cur = cur->next;
	}

	return k;
}
/*
Given a linked list, re-arrange its nodes into two lists: <1st node, 3rd node, 5th node...> and <2nd node,
4th node, 6th node...>. Do not allocate any new nodes.
Input:
10 20 30 40 50 0
Output:
10 30 50 0
20 40 0
*/

void SplitLinkedList(list& l) {

	list odd, even;
	InitLinked_List(odd);
	InitLinked_List(even);
	int i = 1;
	while (l.head) {
		if (i % 2 == 1) {
			Add_Head(odd, l.head->data);
			l.head = l.head->next;
			++i;
		}
		else {
			Add_Head(even, l.head->data);
			l.head = l.head->next;
			i++;
		}
	}
	PrintList(odd); cout << endl;
	PrintList(even); cout << endl;

}

/*
3.8 2 lists ->. 1 list
Given two linked lists, combine their nodes so that the nodes of the new list alternate between those of
the two original nodes: <1st node of 1st list, 1st node of 2nd list, 2nd node of 1st list, 2nd node of 2nd list...>.
Do not allocate any new nodes.
Input:
10 30 50 70 90 110 0
20 40 60 0
Output:
10 20 30 40 50 60 70 90 110 0*/

void Input(ifstream& fin, list& l, list& k) {

	InitLinked_List(l);
	InitLinked_List(k);
	bool flag = false;
	while (fin.good()) {
		int x;
		fin >> x;
		if (x == 0) flag = true;
		if (flag == false && x != 0) Add_Head(l, x);
		if (flag == true && x != 0) Add_Head(k, x);

	}
}

void Input_Tail(ifstream& fin, list& l, list& k) {

	InitLinked_List(l);
	InitLinked_List(k);
	bool flag = false;
	while (fin.good()) {
		int x;
		fin >> x;
		if (x == 0) flag = true;
		if (flag == false && x != 0) Add_Tail(l, x);
		if (flag == true && x != 0) Add_Tail(k, x);
	}
}


int Count(list& l) {
	int cnt = 0;
	node* p = l.head;
	while (p) {
		cnt++;
		p = p->next;
	}

	return cnt;
}

list MergeList(list& l, list& k) {

	list Merge;
	InitLinked_List(Merge);
	int n = Count(l);
	int m = Count(k);

	int j = 0, i = 0;
	while (i < n && j < m && l.head && k.head) {
		Add_Head(Merge, l.head->data);
		Add_Head(Merge, k.head->data);
		i++; j++; l.head = l.head->next; k.head = k.head->next;
	}
	while (i < n && l.head) {
		Add_Head(Merge, l.head->data);
		++i; l.head = l.head->next;
	}
	while (j < n && k.head) {
		Add_Head(Merge, k.head->data);
		++j; k.head = k.head->next;
	}

	return Merge;
}



void CatTwoList(list& l, list& k) {
	if (l.head == nullptr) return;
	l.tail->next = k.head;
}

int ListToNumber(list& l) {
	if (l.head == nullptr) return 0;
	int res = l.head->data;
	node* p = l.head;
	while (p->next) {
		res = res * 10 + p->next->data;
		p = p->next;
	}
	return res;
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


		/* write function to solve problems right here.(Question 4.) */

	//	InsertEvenNumber_KAISEN(l);
		/* write function to solve problems right here.(Question 5.) */

	//	Sorted_LinkedList(l, 27);

			/* write function to solve problems right here.(Question 6.) */

			/*	list k = ListofSum(l);
		PrintList(k); cout << endl;*/

		/* write function to solve problems right here.(Question 7.) */

	// 	SplitLinkedList(l);
			/* write function to solve problems right here.(Question 8.) */
		/*list tmp, temp;
		Input(fin, tmp, temp);
		list buffer = MergeList(tmp, temp);
		PrintList(buffer);*/

		/* write function to solve problems right here.(Question 9.) */
	/*	list tmp, temp;
		Input_Tail(fin, tmp, temp);
		CatTwoList(tmp, temp);
		PrintList(tmp); */


		/* write function to solve problems right here.(Question 10.) */
		cout << ListToNumber(l);


		//PrintList(l);

	}

}