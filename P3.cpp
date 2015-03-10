#include <iostream>
#include "assert.h"
#include "Leftist_heap.h"
#include "Exception.h"

int main() {
	Leftist_heap<int> *heap = new Leftist_heap<int>();

	std::cout << "Testing initialization and accessors" << std::endl;
	assert(heap->size() == 0);
	assert(heap->empty() == true);
	assert(heap->null_path_length() == -1);
	try {
		heap->top();
		assert(false);
	} catch (underflow e) {}
	try {
		heap->pop();
		assert(false);
	} catch (underflow e) {}


	std::cout << "Testing push" << std::endl;
	heap->push(10);
	assert(heap->size() == 1);
	assert(heap->top() == 10);
	assert(heap->null_path_length() == 0);
	heap->push(11);
	assert(heap->size() == 2);
	assert(heap->top() == 10);
	assert(heap->null_path_length() == 0);
	heap->push(9);
	assert(heap->size() == 3);
	assert(heap->top() == 9);
	assert(heap->null_path_length() == 0);
	heap->push(12);
	assert(heap->size() == 4);
	assert(heap->top() == 9);
	assert(heap->null_path_length() == 1);

	std::cout << "Testing push (Negative Numbers)" << std::endl;
	heap->push(-5);
	assert(heap->size() == 5);
	assert(heap->top() == -5);
	assert(heap->null_path_length() == 0);
	heap->push(6);
	assert(heap->size() == 6);
	assert(heap->top() == -5);
	assert(heap->null_path_length() == 1);
	heap->push(-7);
	assert(heap->size() == 7);
	assert(heap->top() == -7);
	assert(heap->null_path_length() == 0);

	std::cout << "Testing pop" << std::endl;
	assert(heap->pop() == -7);
	assert(heap->size() == 6);
	assert(heap->pop() == -5);
	assert(heap->size() == 5);
	assert(heap->pop() == 6);
	assert(heap->size() == 4);
	assert(heap->pop() == 9);
	assert(heap->size() == 3);
	assert(heap->pop() == 10);
	assert(heap->size() == 2);
	assert(heap->pop() == 11);
	assert(heap->size() == 1);
	assert(heap->pop() == 12);
	assert(heap->size() == 0);

	std::cout << "Testing clear" << std::endl;
	for (int i = 0; i < 100; i++) {
		heap->push(i);
	}
	heap->clear();
	assert(heap->size() == 0);
	try {
		heap->top();
		assert(false);
	} catch (underflow e) {}
	try {
		heap->pop();
		assert(false);
	} catch (underflow e) {}


	std::cout << "Testing count" << std::endl;
	heap->push(10);
	heap->push(11);
	heap->push(9);
	heap->push(12);
	heap->push(-5);
	heap->push(6);
	heap->push(-7);

	heap->push(50);
	heap->push(25);
	heap->push(30);
	heap->push(20);
	heap->push(50);
	heap->push(42);
	heap->push(-612);
	heap->push(1);
	heap->push(123);
	heap->push(42);

	//Ensure the old numbers actually got deleted
	assert(heap->count(10) == 1);
	assert(heap->count(11) == 1);
	assert(heap->count(9) == 1);
	assert(heap->count(12) == 1);
	assert(heap->count(-5) == 1);
	assert(heap->count(6) == 1);
	assert(heap->count(-7) == 1);

	assert(heap->count(50) == 2);
	assert(heap->count(42) == 2);
	assert(heap->count(30) == 1);
	assert(heap->count(-612) == 1);
	assert(heap->count(3) == 0);


	//Testing min-heap property/stress test
	std::cout << "Testing random numbers" << std::endl;
	for (int i = 0; i < 100000; i++) {
		heap->push(-50000 + (rand() % (int)(100001)));
	}

	int last_num = heap->pop();
	int current_num;
	while(!heap->empty()) {
		current_num = heap->pop();
		//std::cout << current_num << " >? " << last_num << std::endl;
		assert(current_num >= last_num);
		last_num = current_num;
	}

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
