#pragma once
#include <iostream>
#include "List.h"

// Шаблонный тип данных
template <class T>
// Класс очереди
class TQueue_on_list {
private:
	int size;
	CList<T> data;
public:
	// Конструктор по умолчанию
	TQueue_on_list() { 
		data = CList<T>();
		size = 1;
	}
	// Конструктор инициализации
	TQueue_on_list(int _size) {
		data = CList<T>();
		_size < 1 ? throw std::string("Negative value") : NULL;
		size = _size;
	}
	// Метод - добавления
	void push(T value) {
		if (isFull()) { 
			throw std::string("Queue is full"); 
		}
		data.push_back(value);
	}
	// Геттер - получения максимального размера очереди
	int get_max_size() { 
		return size; 
	}
	// Геттер - получения реального размера списка в очереди
	int get_real_size() { 
		return data.size(); 
	}
	// Метод - удаления
	void pop() { 
		if (isEmpty()) { 
			throw std::string("Queue is empty");
		} 
		else {
			data.pop_front();
		}
	}
	// Перегрузка оператора [] возвращает элемент по индексу
	CNode<T> operator [] (int index) { 
		return *data[index]; 
	}
	// Метод - вставка в середину очереди
	void push_in_middle(T value) {
		int size = data.size() * 0.5;
		data.insert(value, size);
	}
	// Геттер данных с начального элемента
	T front() { 
		return data.front()->get_data(); 
	}
	// Геттер данных с последнего элемента
	T back() { 
		return data.back()->get_data(); 
	}
	// Метод - если полный
	bool isFull() { 
		return data.size() >= size; 
	}
	// Метод - если пустой
	bool isEmpty() { 
		return data.size() == 0; 
	}
	void task15_push(T value);
	void task15_pop();
	int task18_find(T value);
};
