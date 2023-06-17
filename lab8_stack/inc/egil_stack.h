#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



template <typename type>
class stack {
private:
	type* data = nullptr;
	size_t m_size = 0;
	size_t m_ElementsCount=0;


public:

	stack(size_t size) :  m_size(size), data(new type[size]) {}

	stack(const stack<type>& copy) {
		m_size = copy.m_size;
		ElementsCount = copy.ElementsCount;
		type* newdata = new type[m_size];
		for (int i = 0; i < m_size; i++) {
			newdata[i] = copy.data[i];
		}
		delete[] data;
		data = newdata;
	}

	stack<type>& operator= (const stack<type>& copy) {
		if (this != &copy) {
			m_size = copy.m_size;
			m_ElementsCount = copy.ElementsCount;
			type* newdata = new char[m_size];
			for (int i = 0; i < m_size; i++) {
				newdata[i] = copy.data[i];
			}
			delete[] data;	
			data = newdata;
		}
		return *this;
	}

	void size() {
		std::cout << "Elements count: " << m_ElementsCount << std::endl << "Size in bytes: " << sizeof(*this)<<std::endl;
	}

	bool empty() const {
		if (m_ElementsCount == 0) {
			return true;
		}
		return false;
	}

	void push(const type& newElement) {

		if (m_size > m_ElementsCount) {
			data[m_ElementsCount] = newElement;
			m_ElementsCount++;
		}
		else {
			throw std::overflow_error("Stack is full");
		}
	}

	type pop() {
		if (m_ElementsCount != 0) {
			m_ElementsCount--;
			return data[m_ElementsCount];
		}
		throw std::out_of_range("Empty stack");
	}
	

	type top() {
		if (m_ElementsCount != 0) {
			return data[m_ElementsCount];
		}
		throw std::logic_error("Empty stack");
	}
	~stack() {
		delete[] data;
	}

};
