﻿#pragma once

#include <iostream>
// Описываем шаблонный класс CNode чтобы список видел такой класс для возможности взаимодействия
template <class T> class CNode;
// Шаблонна переменная
template <class T>
// Класс списка
class CList {
private:
	CNode<T>* head;
	CNode<T>* tail;
public:
	// Конструктор по умолчанию
	CList() : head(nullptr), tail(nullptr) {}
	// Деструктор
	~CList() {}
	// Метод - получения размера
	size_t size() {
		if (head == nullptr) {
			return 0;
		}
		int size = 0;
		CNode<T>* tmp = head;
		for (; tmp != NULL && tmp != nullptr; tmp = tmp->get_next_node()) { ++size; }
		return size;
	}
	// Метод - добавления в конец
	void push_back(T value) {
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
	// Метод - добавления в начало
	void push_front(T value) {
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
	// Метод - удаления с конца
	void pop_back() {
		if (head == tail) { throw std::logic_error("Head = tail"); }
		else if (isEmpty()) { throw std::logic_error("List is empty"); }
		CNode<T>* tmp = (*this)[size() - 2];
		tmp->del_next();
		tail = tmp;
	}
	// Метод - удаления головы и хвоста (первого и последнего элемента)
	void clearHeadAndTail() {
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	// Метод - удаления с начала
	void pop_front() {
		if (head != tail) {
			CNode<T>* tmp = head;
			head = head->next;
			delete tmp;
			tmp = nullptr;
		}
		else {
			clearHeadAndTail();
		}
	}
	// Метод - получения головы (первого элемента)
	CNode<T>* front() {
		return head;
	}
	// Метод - получения конца (последнего элемента)
	CNode<T>* back() {
		return tail;
	}
	// Метод - вставки внутрь списка по индексу
	void insert(T _data, int index) {
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
	// Метод - удаления по индексу
	void erase(int index) {
		if (index < 0) {
			throw std::out_of_range("out of range");
		}
		if (index == 0) {
			pop_back();
			return;
		}
		if (index == size() - 1) {
			pop_back();
			return;
		}
		if (index >= size() - 1) {
			throw std::out_of_range("out of range");
		}
		CNode<T>* del_elem = (*this)[index];
		CNode<T>* pre = (*this)[index - 1];
		CNode<T>* post = (*this)[index + 1];
		pre->set_next(post);
		delete del_elem;
		del_elem = nullptr;
	}
	// Метод - перегрузки квадратных скобок (получения элемента по индексу)
	CNode<T>* operator[] (int index) {
		CNode<T>* tmp = head;
		int tmp_index = 0;
		for (; tmp_index < index; tmp = tmp->get_next_node()) {
			++tmp_index;
		}
		return tmp;
	}
	// Метод - если список пустой
	bool isEmpty() {
		return head == nullptr;
	}
	// Метод - разворот списка
	void reverse() {
		CList<T>* temp = new CList<T>();
		for (; !isEmpty(); temp->push_front(front()->get_data()), this->pop_front());
		(*this) = *temp;
	}

	void task9_push_back(T value);
	void task10_push_front(T value);
	void task11_insert(T value, int index);
	void task12_reverse();
	int task19_find(T value);
};
// Шаблонный тип данный
template <class T>
// Класс элемента списка CNode
class CNode {
	// Определяем класс другом (позволяет пользоваться приватными полями и методами)
	friend class CList<T>;
private:
	T data;
	CNode<T>* next;
public:
	// Конструктор по умолчанию
	CNode(T value) {
		data = value;
		next = nullptr;
	}
	// Деструктор
	~CNode() {}
	// Сеттер указателя на следующий элемент списка
	void set_next(CNode<T>* next_node) {
		next = next_node;
	}
	// Геттер указателя на слудующий элемент списка
	CNode<T>* get_next_node() {
		return next;
	}
	// Сеттер данный
	void set_data(T _data) {
		data = _data;
	}
	// Геттер данных
	T get_data() {
		return data;
	}
	// Вывод даты в консоль
	void print() {
		std::cout << data;
	}
	// Удалить указатель на следующий элемент
	void del_next() {
		delete next;
		next = nullptr;
	}
	// Перегрузка оператора равно
	void operator = (CNode<T>* node) {
		data = node->get_data();
		next = node->get_next_node();
	}
};
