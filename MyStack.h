#include <iostream>
#include <memory>


template <class Type>
class MyStack
{
public:
	MyStack();					//Constructor
	MyStack(const MyStack &);	//Copy Constructor
	//~Queue();					//Destructor if using raw pointers
	void push(Type item);		//Adds an item 
	void pop();					//Removes an item 
	Type peek();				//Returns the top value
	int size();					//Returns the size
	bool isEmpty();				//Returns true if empty
	void clear();				//Erases all the items
	MyStack<Type>& operator=(const MyStack<Type>& other);	//Deep copy
	friend ostream &operator<< <>(ostream &out, const MyStack<Type> &q);  //Displays all the items

private:

};
template <class Type>
MyStack<Type>::MyStack() {

}
template <class Type>
MyStack<Type>::MyStack(const MyStack<Type> &other) {
	
	
}



/*
template <class Type>
Queue<Type>::~Queue() {

}

*/
template <class Type>
void MyStack<Type>::push(Type item) {

}

template <class Type>
Type MyStack<Type>::peek() {

}

template <class Type>
int MyStack<Type>::size() {
	return cnt;
}
template <class Type>
bool MyStack<Type>::isEmpty() {
	return cnt == 0;
}

template <class Type>
void MyStack<Type>::clear() {

}

template <class Type>
void MyStack<Type>::pop() {

}

template <class Type>
MyStack<Type>& MyStack<Type>::operator=(const MyStack& other) {

	return *this;
}

template <class Type>
ostream& operator<<(ostream& out, const MyStack<Type>& q)
{
	auto temp = q.top;
	while (temp) {
		out << temp->data;
		if (temp->next) out << " ";
		temp = temp->next;
	}
	return out;
}
