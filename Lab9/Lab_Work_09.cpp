// Lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

#include <stdlib.h>
#include <stack>
#include <list>

#include "Money.h"
#include "Tstack.cpp"
using namespace std;

template<typename T>
void sort(T arr[], int arrayLength) {
	T tmp; 
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayLength; j++) {
			if (arr[i] > arr[j]) {	
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


template<typename T>
T getmax(T a, T b) {
	return a > b ? a : b;
}

// отдельная реализация для параметров char*
char* getmax(char* a, char* b) {
	return strcmp(a, b) > 0 ? a : b;
}

// перегрузка для массивов любого типо
template<typename T>
T getmax(T arr[], int size) {
	int max = 0; 
	for (int i = 0; i < size; i++) {
		if (arr[i] > arr[max]) { 
			max = i;
		}
	}

	return arr[max];
}

template<typename T>
T getmin(T arr[], int from, int to) {
	int min = from;
	for (int i = from; i < to; i++) {
		if (arr[i] < arr[min]) {
			min = i;
		}
	}
	return arr[min];
}

int* solve2(int vagons[], int size) {
	stack<int> stk;
	int *way2 = (int*) malloc(sizeof(int) * size);
	int wayOneIndex = 0;
	int wayTwoIndex = 0;

	

	while (true) {
		if (wayTwoIndex == (size))
			break;

		if (wayOneIndex == (size)) {
			while (!stk.empty()) {
				way2[wayTwoIndex++] = stk.top();
				stk.pop();
			}
			break;
		}

		int min = getmin(vagons, wayOneIndex, size);
		
		if (vagons[wayOneIndex] != min) {  // все что больше минимального вагона - вывезти в тупик
			if (!stk.empty()) {
				if (stk.top() < min) {
					way2[wayTwoIndex++] = stk.top();
					stk.pop();
				}
			}

			stk.push(vagons[wayOneIndex]);
			wayOneIndex++;
		}
		else {
			way2[wayTwoIndex++] = vagons[wayOneIndex++];
		}

		
	}
	return way2;
}

int* solve(int vagons[], int size) {
	Tstack<int> stk(size);
	int *way2 = (int*)malloc(sizeof(int) * size);
	int wayOneIndex = 0;
	int wayTwoIndex = 0;



	while (true) {
		if (wayTwoIndex == (size))             // Если на пути 2 количество вагонов равное 1 - стоп 
			break;                       

		if (wayOneIndex == (size)) {           // Если на пути 1 закончились вагоны, достать остатки из стека
			while (!stk.empty()) {         
				way2[wayTwoIndex++] = stk.pop();
			}
			break;
		}

		int min = getmin(vagons, wayOneIndex, size);
		
		if (vagons[wayOneIndex] != min) {       // все что больше минимального вагона - вывезти в тупик
			if (!stk.empty()) {
				if (stk.peek() < min) {
					way2[wayTwoIndex++] = stk.pop();
					stk.pop();
				}
				else {
					way2[wayTwoIndex++] = min;
				}
			}

			stk.push(vagons[wayOneIndex]);
			wayOneIndex++;
		}
		else {
			// иначе перенести вагон на путь 2
			way2[wayTwoIndex++] = vagons[wayOneIndex++];
		}
	}
	return way2;
}

int main() {
	setlocale(0, "Russian");
	int vagons[] = { 3, 2, 1 };
	solve(vagons, 3);

	int vagons2[] = { 4, 1, 2, 3 };
	solve(vagons2, 4);

	int vagons3[] = { 5, 3, 1 };
	cout << "Вагоны на 1 пути:\n";
	for (int i = 0; i < 3; i++) {
		cout << vagons3[i] << " ";
	}

	int *solved = solve(vagons3, 3);

	cout << "\nВагоны на 2 пути:\n";
	for (int i = 0; i < 3; i++) {
		cout << solved[i] << " ";
	}
	return 0;
}

//int main()
//{
//  setlocale(0, "Russian");
//	int arr[] = { 10, 0, 100, 123, 12, 70, 3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << '\n';
//
//	int a = 10, b = 20;
//	cout << "getmax(10, 20) = " << getmax(a, b) << '\n';
//
//	char a_s[] = "aa";
//	char b_s[] = "ab";
//	cout << "getmax(\"aa\", \"ab\") = " << getmax(a_s, b_s) << '\n';
//
//	int arr2[] = { 10, 0, 100, 123, 12, 70, 3 };
//	int max = getmax(arr2, sizeof(arr2) / sizeof(arr2[0]));
//	cout << "max el = " << max << '\n';
//
//	Money money[] = {
//		Money(10, 20),
//		Money(20, 10),
//		Money(88, 88),
//		Money(0, 0)
//	};
//
//	cout << "Деньги до сортировки: \n";
//	for (int i = 0; i < 4; i++) {
//		cout << money[i] << '\n';
//	}
//
//	cout << "\nДеньги после сортировки:\n";
//	sort(money, 4);
//	for (int i = 0; i < 4; i++) {
//		cout << money[i] << '\n';
//	}
//
//	int vagons[] = {3, 2, 1};
//	solve(vagons, 3);
//
//	return 0;
//}

//int main() {
//	Tstack<int> intStack;
//	std::cout << "intStack.empty(): " << intStack.empty() << '\n';
//	std::cout << "Push into stack 10, 20, 30\n";
//	intStack.push(10);
//	intStack.push(20);
//	intStack.push(30);
//
//	std::cout << "On top of the stack: " << intStack.peek() << '\n';
//	std::cout << "intStack.empty(): " << intStack.empty() << '\n';
//
//	std::cout << "intStack.size(): " << intStack.size() << '\n';
//
//	std::cout << "intStack.pop(): " << intStack.pop() << '\n';
//
//	std::cout << "intStack.size(): " << intStack.size() << '\n';
//
//	return 0;
//}
