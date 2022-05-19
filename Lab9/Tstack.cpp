#include "pch.h"
#include <stdlib.h>


template<typename T>
class Tstack
{

protected:
	int num;
	T *item;
public:
	Tstack(size_t size = 10) {
		num = 0;
		item = new T[size];
	}

	~Tstack() {
		delete[] item;
	}

	bool empty() {
		return this->num == 0;
	}

	void push(T t) {
		this->item[this->num++] = t;
	}
	T pop() {
		return item[--num];
	}

	T peek() {
		return item[num-1];
	}

	size_t size() {
		return num;
	}
};
