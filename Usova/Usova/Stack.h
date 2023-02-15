#pragma once
// Создание шаблонного типа данных TYPE
template<class T>
// Шаблонны класс MyStack
class MyStack {
public:
	int size;
	T* data;
	int top;
	// Констркуктор по умолчанию
	MyStack() {
		data = new T[1];
		size = 1;
		top = -1;
	}
	// Конструктор инициализации
	MyStack(int _size) {
		if (_size < 1) {
			throw std::string("Negative value");
		}
		data = new T[_size];
		size = _size;
		top = -1;
	}
	// Деструктор
	~MyStack() {}
	// Метод - если стек заполнен (возвращает true/false)
	bool isFull() {
		return top == size - 1;
	}
	// Метод - если стек пуст (возвращает true/false)
	bool isEmpty() {
		return top == -1;
	}
	// Метод - получение последнего значения
	T get_top() {
		isEmpty() ? throw std::string("Stack is empty") : NULL;
		return data[top];
	}
	// Метод - добавления в конец
	void push(T value) {
		if (isFull()) {
			throw std::string("Stack is full");
		}
		top++;
		data[top] = value;
	}
	// Метод - удаления с конца
	void pop() {
		if (isEmpty()) {
			throw std::string("Stack is empty");
		}
		else {
			top--;
		}
	}
	// Метод - добавления в середину
	void push_in_middle(T value) {
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
	// Метод - разворота стека
	void reverse() {
		MyStack temp_stack(size);
		while (top != -1) {
			T temp_first_value = this->get_top();
			this->pop();
			temp_stack.push(temp_first_value);
		}
		*this = temp_stack;
	}
	// Метод - вывода в консоль
	void print() {
		MyStack<T> temp(size);
		while (!this->isEmpty()) {
			T temp_value = this->get_top();
			this->pop();
			temp.push(temp_value);
		}
		std::cout << "\n";
		while (!temp.isEmpty()) {
			T element = temp.get_top();
			temp.pop();
			std::cout << "(" << element << ") ";
			this->push(element);
		}
	}

	void task1_push(T value);
	void task2_pop();
	void task3_push_in_middle(T value);
	void task4_reverse();
	int task17_find(T value);
};