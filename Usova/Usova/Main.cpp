#include <iostream>
#include "Stack.h"
#include "List.h"
#include "Queue.h"

void printer(CList<int> l) {
	int size = l.size();
	for (int i = 0; i < size; i++) {
		std::cout << "(" << l[i]->get_data() << ")";
		if (i + 1 < size) {
			std::cout << "->";
		}
	}
}

void printer(TQueue_on_list<int> l) {
	int size = l.get_real_size();
	for (int i = 0; i < size; i++) {
		std::cout << "(" << l[i].get_data() << ")";
		if (i + 1 < size) {
			std::cout << "<-";
		}
	}
}

int main() {
	// Стек
	std::cout << "Stack";
	MyStack<int> stack(5);
	stack.push(3);
	stack.push(5);
	stack.push(7);
	stack.push(9);
	stack.push(10);
	stack.print();
	std::cout << std::endl << std::endl << "List" << std::endl;
	// Список
	CList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	printer(l);
	l.reverse();
	std::cout << std::endl << std::endl << "List reverse" << std::endl;
	printer(l);
	// Очередь
	std::cout << std::endl << std::endl << "Queue" << std::endl;
	TQueue_on_list<int> t(5);
	t.push(1);
	t.push(2);
	t.push(3);
	t.push(4);
	t.push(5);
	printer(t);

	return 0;
}