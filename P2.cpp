#include <iostream>
#include <assert.h>
#include "Dynamic_queue.h"
#include "Linked_stack.h"

using namespace std;

void test_linked_stack() {
	Linked_stack<int> *s = new Linked_stack<int>();

	std::cout << "Testing getters" << std::endl;
	assert(s->empty() == true);
	try {
		s->pop();
		assert(false);
	} catch (underflow e) {}

	try {
		s->top();
		assert(false);
	} catch (underflow e) {}

	std::cout << "Testing push" << std::endl;
	for (int i = 0; i < 8; i++) {
		assert(s->size() == i);
		s->push(i);
	}
	assert(s->list_size() == 1);

	std::cout << "Testing push resize (1)" << std::endl;
	s->push(8);
	assert(s->list_size() == 2);

	std::cout << "Testing push resize (2)" << std::endl;
	for (int i = 9; i < 18; i++) {
		s->push(i);
	}
	assert(s->list_size() == 3);


	std::cout << "Testing pop (1)" << std::endl;
	assert(s->pop() == 17);
	assert(s->pop() == 16);
	assert(s->size() == 16);
	assert(s->list_size() == 2);

	for (int i = 15; i >= 0; i--) {
		assert(s->top() == i);
		assert(s->pop() == i);
	}
	assert(s->size() == 0);
	assert(s->list_size() == 0);


	std::cout << "Testing push after empty" << std::endl;
	for (int i = 0; i < 8; i++) {
		assert(s->size() == i);
		s->push(i * 10);
		assert(s->top() == i * 10);
	}
	std::cout << "Testing push resize (2)" << std::endl;
	s->push(80);
	assert(s->list_size() == 2);

	delete s;


	std::cout << "Testing copy constructor" << std::endl;
	s = new Linked_stack<int>();
	for (int i = 0; i < 10; i++) {
		s->push(i);
	}
	assert(s->size() == 10);
	assert(s->list_size() == 2);
	assert(s->top() == 9);

	Linked_stack<int> *s2 = new Linked_stack<int>(*s);
	assert(s->size() == 10);
	assert(s->list_size() == 2);
	assert(s->top() == 9);
	assert(s2->size() == 10);
	assert(s2->list_size() == 2);
	assert(s2->top() == 9);

	std::cout << "Testing copy constructor (modifying original stack)" << std::endl;
	assert(s->pop() == 9);
	assert(s->pop() == 8);
	assert(s->size() == 8);
	assert(s2->size() == 10);

	for (int i = 9; i >=0; i--) {
		assert(s2->pop() == i);
	}
	assert(s2->size() == 0);
	assert(s->size() == 8);

	for (int i = 7; i >=0; i--) {
		assert(s->pop() == i);
	}
}

void test_dynamic_queue() {

	int N = 4;
	Dynamic_queue<int>* q = new Dynamic_queue<int>(N);

	std::cout << "Testing getters" << std::endl;
	assert(q->capacity() == N);
	assert(q->size() == 0);
	try {
		q->head();
		assert(false);
	} catch (underflow e) {}

	try {
		q->dequeue();
		assert(false);
	} catch (underflow e) {}

	std::cout << "Testing basic enqueue" << std::endl;
	for (int i = 1; i < N+1; i++) {
		q->enqueue(i);
		assert(q->head() == 1);
		assert(q->size() == i);
		assert(q->capacity() == N);
	}

	//Test a size double
	q->enqueue(42);
	assert(q->head() == 1);
	assert(q->capacity() == N*2);
	assert(q->size() == ++N);

	std::cout << *q << std::endl;

	std::cout << "Testing basic dequeue" << std::endl;
	for (int i = 1; i < 4; i++) {
		assert(q->dequeue() == i);
		assert(q->head() == i + 1);
		assert(q->size() == --N);
	}

	int size = N;
	for (int i = 1; i <= 5; i++) {
		q->enqueue(i*101);
		assert(q->head() == 4);
		assert(q->size() == ++size);
	}

	q->clear();
	assert(q->capacity() == 4);
	delete q;

	q = new Dynamic_queue<int>(10);

	std::cout << "Testing resize (1)" << std::endl;
	for (int i = 1; i < 11; i++) {
		q->enqueue(i);
	}

	assert(q->dequeue() == 1);
	assert(q->dequeue() == 2);

	q->enqueue(11);
	q->enqueue(12);

	for (int i = 3; i < 13; i++) {
		assert(q->dequeue() == i);
	}

	q->clear();

	std::cout << "Testing resize (2)" << std::endl;
	for (int i = 1; i < 11; i++) {
		q->enqueue(i);
	}

	assert(q->dequeue() == 1);
	assert(q->dequeue() == 2);

	assert(q->size() == 8);
	assert(q->capacity() == 10);

	q->enqueue(11);
	q->enqueue(12);

	std::cout << *q << std::endl;

	assert(q->size() == 10);
	assert(q->capacity() == 10);

	q->enqueue(13);
	q->enqueue(14);

	assert(q->size() == 12);
	assert(q->capacity() == 20);

	for (int i = 3; i < 15; i++) {
		assert(q->dequeue() == i);
	}

	std::cout << *q << std::endl;

	delete q;

	N = 4;

	q = new Dynamic_queue<int>(N);
	std::cout << "Testing copy constructor" << std::endl;
	for (int i = 1; i < N+1; i++) {
		q->enqueue(i);
		assert(q->head() == 1);
		assert(q->size() == i);
		assert(q->capacity() == N);
	}

	Dynamic_queue<int>* q2 = new Dynamic_queue<int>(*q);
	assert(q->size() == N);
	assert(q->head() == 1);
	assert(q2->size() == N);
	assert(q2->head() == 1);
	assert(q2->size() == N);

	std::cout << "Testing copy constructor (modifying original queue)" << std::endl;
	assert(q->dequeue() == 1);
	assert(q->size() == N-1);
	assert(q2->size() == N);

	assert(q2->dequeue() == 1);
	assert(q2->dequeue() == 2);
	assert(q2->dequeue() == 3);

	assert(q->size() == N-1);
}

int main() {

	test_linked_stack();
	std::cout << "Linked Stack Test Complete" << std::endl;

	test_dynamic_queue();
	std::cout << "Dynamic Queue Test Complete" << std::endl;

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
