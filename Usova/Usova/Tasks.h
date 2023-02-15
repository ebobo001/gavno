#pragma once
#include "Stack.h"
#include "List.h"
#include "Queue.h"

template<class T>
class TQueue_on_mass {
public:
	int size;
	int top;
	T* data;
	void task5_push(T value);
	void task6_pop();
	void task7_push_in_middle(T value);
	void task8_reverse();
	bool isFull();
	void pop();
	void push(T value);
};
template<class T>
class TQueue_insert_and_pop {
public:
	CList<std::pair<T, int>> data;
	void push(std::pair<T, int> value);
	bool isFull();
	bool isEmpty();
	void pop();
};
template<class T>
class Stack_on_list {
public:
	int size;
	int top;
	CList<T> data;
	void push(T value);
	void pop();
};
/*
1. Реализовать метод вставки элемента шаблонного типа данных в стек. Считается,
что стек организован на массиве.
*/
template<class T>
void MyStack<T>::task1_push(T value) {
	// Если стек полон
	if (isFull()) {
		// Вызвать исключение
		throw std::string("Stack is full");
	}
	// Прибавить топ
	top++;
	// Записать на это место данные
	data[top] = value;
}
/*
2. Реализовать метод удаления элемента шаблонного типа данных из стека.
Считается, что стек организован на массиве.
*/
template<class T>
void MyStack<T>::task2_pop() {
	if (isEmpty()) {
		throw std::string("Stack is empty");
	}
	else {
		top--;
	}
}
/*
3. Реализовать метод вставки элемента шаблонного типа данных в середину стека. 
Считается, что стек организован на массиве.
*/
template<class T>
void MyStack<T>::task3_push_in_middle(T value) {
	MyStack temp_stack(size);
	int mytop = top / 2;
	while (mytop != top) {
		T temp_first_value = this->get_top();
		this->pop();
		temp_stack.push(temp_first_value);
	}
	this->push(value);
	while (!temp_stack.isEmpty()) {
		T temp_second_value = temp_stack.get_top();
		temp_stack.pop();
		this->push(temp_second_value);
	}
}
/*
4. Реализовать метод разворота стека. Считается, что стек организован на массиве.
*/
template<class T>
void MyStack<T>::task4_reverse() {
	MyStack temp_stack(size);
	while (top != -1) {
		T temp_first_value = this->get_top();
		this->pop();
		temp_stack.push(temp_first_value);
	}
	*this = temp_stack;
}
/*
5. Реализовать метод вставки элемента шаблонного типа данных в очередь.
Считается, что очередь организована на массиве.
*/
template<class T>
void TQueue_on_mass<T>::task5_push(T value) {
	if (isFull()) {
		throw std::string("Queue is full");
	}
	push_back(value);
}
/*
6. Реализовать метод удаления элемента шаблонного типа данных из очереди.
Считается, что очередь организована на массиве.
*/
template<class T>
void TQueue_on_mass<T>::task6_pop() {
	if (isEmpty()) {
		throw std::string("Queue is empty");
	}
	else {
		pop();
	}
}
/*
7. Реализовать метод вставки элемента шаблонного типа данных в середину очереди.
Считается, что очередь организована на массиве
*/
template<class T>
void TQueue_on_mass<T>::task7_push_in_middle(T value) {
	if (size - 1 >= top) {
		throw std::out_of_range("out of range (queue is full)");
	}
	else { 
		//////////////////
		// 1 2 3 4 5 0 0//
		// 1 2 3 4 5 5 0//
		// 1 2 3 3 4 5 0//
		// 1 2 T 3 4 5 0//
		// 0 1 2 3 4 5 6//
		//////////////////
		// 1 2 3 4 0 0 0//
		// 1 2 3 4 4 0 0//
		// 1 2 3 3 4 0 0//
		// 1 2 Е 3 4 0 0//
		// 0 1 2 3 4 5 6//
		//////////////////
		for (int i = top; i > top * 0.5; i--) {
			data[i] = data[i - 1];
		}
		data[top * 0.5] = value;
	}
}
/*
8. Реализовать метод разворота очереди. Считается, что очередь организована на
массиве.
*/
template<class T>
void TQueue_on_mass<T>::task8_reverse() {
	TQueue_on_mass temp_q(size);
	for (int i = top; i > 0; i--) {
		temp_q.push(data[i]);
	}
	*this = temp_qk;
}
/*
9. Реализовать метод вставки элемента шаблонного типа данных в конец
односвязного списка.
*/
template<class T>
void CList<T>::task9_push_back(T value) {
	CNode<T>* new_node = new CNode<T>(value);
	if (!isEmpty()) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = new_node;
		tail = new_node;
	}
}
/*
10. Реализовать метод вставки элемента шаблонного типа данных в начало
односвязного списка.
*/
template<class T>
void CList<T>::task10_push_front(T value) {
	CNode<T>* new_node = new CNode<T>(value);
	CNode<T>* tmp = head;
	if (!isEmpty()) {
		head = new_node;
		head->next = tmp;
	}
	else {
		head = new_node;
		tail = new_node;
	}
}
/*
11. Реализовать метод вставки элемента шаблонного типа данных на заданную 
позицию в односвязном списке.
*/
template<class T>
void CList<T>::task11_insert(T value, int index) {
	if (index < 0) {
		throw std::out_of_range("out of range");
	}
	if (index == 0) {
		push_front(_data);
		return;
	}
	if (index == size() - 1) {
		push_back(_data);
		return;
	}
	if (index >= size() - 1) {
		throw std::out_of_range("out of range");
	}
	CNode<T>* tmp = new CNode<T>(_data);
	CNode<T>* post = (*this)[index];
	CNode<T>* pre = (*this)[index - 1];
	pre->set_next(tmp);
	tmp->set_next(post);
}
/*
12. Реализовать метод разворота односвязного списка.
*/
template<class T>
void CList<T>::task12_reverse() {
	CList<T>* temp = new CList<T>();
	for (; !isEmpty(); temp->push_front(front()->get_data()), this->pop_front());
	(*this) = *temp;
}
/*
13. Реализовать метод вставки элемента шаблонного типа данных в приоритетную
очередь (очередь с приоритетным исключением).
*/
template<class T>
void TQueue_insert_and_pop<T>::push(std::pair<T, int> value) {
	if (isFull()) { 
		throw std::string("Queue is full"); 
	}
	int size = data.size();
	if (size == 0) {
		data.push_back(value);
		return;
	}
	CNode<std::pair<T, int>>* tmp = data.front();
	int index = 0;
	for (; tmp != NULL && tmp != nullptr; tmp = tmp->get_next_node()) {
		if (value.first >= tmp->get_data().first) {
			data.insert(value, index);
			return;
		}
		++index;
	}
	data.push_back(value);
}
/*
14. Реализовать метод удаления элемента шаблонного типа данных из приоритетной 
очереди (очередь с приоритетным включением).
*/
template<class T>
void TQueue_insert_and_pop<T>::pop() {
	if (!isEmpty()) {
		if (data.size() == 1) {
			data.pop_back();
			return;
		}
		else {
			CNode<std::pair<T, int>>* tmp = data.front();
			CNode<std::pair<T, int>>* tmp2 = data.front();
			int index = 0;
			int ind_max = 0;
			for (; tmp != NULL && tmp != nullptr; tmp = tmp->get_next_node()) {
				if (tmp2->get_data().first <= tmp->get_data().first) {
					tmp2 = tmp;
					ind_max = index;
				}
				++index;
			}
			data.erase(ind_max);
		}
	}
	else {
		throw std::logic_error("Queue is clear!");
	}
}
/*
15. Реализовать методы вставки и удаления элемента шаблонного типа данных из
очереди. Считается, что очередь организована на списке.
*/
template<class T>
void TQueue_on_list<T>::task15_push(T value) {
	if (isFull()) {
		throw std::string("Queue is full");
	}
	data.push_back(value);
}
template<class T>
void TQueue_on_list<T>::task15_pop() {
	if (isEmpty()) {
		throw std::string("Queue is empty");
	}
	else {
		data.pop_front();
	}
}
/*
16. Реализовать методы вставки и удаления элемента шаблонного типа данных из
стека. Считается, что стек организован на списке.
*/
template<class T>
void Stack_on_list<T>::push(T value) {
	if (top >= size - 1) {
		throw std::out_of_range("out of range (stack full)");
	}
	data.push_back(value);
	top++;
}
template<class T>
void Stack_on_list<T>::pop() {
	if (top < 0) {
		throw std::out_of_range("out of range (stack empty)");
	}
	data.pop_back();
	top--;
}
/*
17. Реализовать метод поиска заданного элемента шаблонного типа данных в стеке
*/
template<class T>
int MyStack<T>::task17_find(T value) {
	MyStack<T> temp;
	int index = -1;
	for (int i = 0; !this->isEmpty(); i++) {
		if (this->get_top() == value) {
			index = i;
			break;
		}
		temp.push(this->get_top());
		this->pop();
	}
	while (!temp.isEmpty()) {
		this->push(temp.get_top());
		temp.pop();
	}
	return index
}
/*
18. Реализовать метод поиска заданного элемента шаблонного типа данных в очереди.
*/
template<class T>
int TQueue_on_list<T>::task18_find(T value) {
	TQueue_on_list<T> temp;
	int index = -1;
	for (int i = 0; !this->isEmpty(); i++) {
		if (front() == value) {
			index = i;
		}
		temp.push(this->front());
		this->pop();
	}
	for (; !temp.isEmpty(); i++) {
		this->push(temp.front());
		temp.pop();
	}
	return index;
}
/*
19. Реализовать метод поиска заданного элемента шаблонного типа данных в списке.
*/
template<class T>
int CList<T>::task19_find(T value) {
	CNode<T>* tmp = head;
	int tmp_index = -1;
	for (int i = 0; tmp_index < index && tmp != NULL; tmp = tmp->get_next_node(), i++) {
		if (tmp->get_data() == value) {
			tmp_index = i;
			break;
		}
	}
	return tmp_index;
}