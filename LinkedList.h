#ifndef __LINKED__
#define __LINKED__

#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* link;
	Node(T element)
	{
		data = element;
		link = NULL;
	}
};

template<class T>
class LinkedList {
protected:
	Node<T>* first;
	int current_size;
public:
	LinkedList<T>() {//생성자, first와 curren_size를 초기화한다
		first = 0;
		current_size = 0;
	}
	int Getsize() { //현재 크기를 반환한다
		return current_size;
	}
	void Insert(T element) { //element를 삽입한다
		Node<T>* newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;
	}
	virtual bool Delete(T& element) { //맨 뒤 원소를 삭제한다
		if (first == 0)
			return false;
		Node<T>* current = first;
		Node<T>* previous = 0;

		while (1) {
			if (current->link == 0) {
				if (previous) previous->link = current->link;
				else first = first->link;
				break;
			}
			previous = current;
			current = current->link;
		}
		element = current->data;
		delete current;

		current_size--;

		return true;
	}
	void Print() { //형식에 맞게 원소들을 툴력한다
		if (first == 0) 
			return;

		int i = 1;
		Node<T>* current = first;
		while (current->link != 0) {
			cout << "[" << i << "|" << current->data << "]";
			cout << " -> ";
			current = current->link;
			i++;
		}
		cout << "[" << i << "|" << current->data << "]"<<endl;

		return;
	}
 };
#endif
