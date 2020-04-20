#ifndef __STACK__
#define __STACK__

#include<iostream>
#include "LinkedList.h"
using namespace std;

template<class T>
class Stack :public LinkedList<T> {//LinkedLIst로부터 상속받는다
public:
	virtual bool Delete(T& element) { //맨 처음 원소를 삭제한다
		if (this->first == 0)
			return false;

		element = this->first->data;
		this->first = this->first->link; 
		
		this->current_size--;

		return true;
	}
};
#endif
