// Stack using Array

#include<iostream>

#define MAX 50
using namespace std;

struct stack {
	int top_of_stack;
	int element[MAX];
}ps;

int empty() {
	if(ps.top_of_stack == -1) 
		return 1;
	else
		return 0;
}

int full() {
	if(ps.top_of_stack == MAX-1) {
		return 1;
	}
 	else 
 		return 0;
}
void push() {
	if(full()) 
		cout<< "STACK OVERFLOW";
	else
	{
		cout<<"Enter Element : ";
		int elem;
		cin>> elem;
		ps.top_of_stack = ps.top_of_stack + 1;
		ps.element[ps.top_of_stack] = elem;
		cout<< "Successful";
	}
}
void pop() {
	if(empty())
		cout<< "STACK UNDERFLOW";
		
	else
		ps.element[(ps.top_of_stack--)];
}
void peek() {
	cout << ps.element[ps.top_of_stack];
}

int main() {
	cout<< "PROGRAM FOR STACK"<<endl;
	ps.top_of_stack = -1;
	int choice;
	while(1) {
	cout<<"PRESS 1 to PUSH PRESS 2 to POP  PRESS 3 to Exit"<< endl;
	cin>>choice;
	if(choice == 1) {
		push();
		peek();
	}
	else if(choice ==2 ) {
		pop();
		peek();
	} 
	else if(choice == 3) { break;}
	else {cout<< "INVALID CHOICE";}

	}

	return 0;
}
