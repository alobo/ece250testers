#include <iostream>
#include <assert.h>
#include "Dynamic_queue.h"
#include "Linked_stack.h"

using namespace std;

//TODO: Finish testing linked stack
void test_linked_stack() {
	Linked_stack<int> *s = new Linked_stack<int>();
	assert(s->empty() == true);

	for (int i = 0; i < 8; i++) {
		assert(s->size() == i);
		s->push(i);
	}
	assert(s->list_size() == 1);

	//Test adding second array
	s->push(8);
	assert(s->list_size() == 2);

	//Test adding a third array
	for (int i = 9; i < 18; i++) {
		s->push(i);
	}
	assert(s->list_size() == 3);

	std::cout << *s << std::endl;
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
//		std::cout << q->head() << " =? " << i << std::endl;
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
}

int main() {

	test_linked_stack();
	std::cout << "Linked Stack Test Complete" << std::endl;

	test_dynamic_queue();
	std::cout << "Dynamic Queue Test Complete" << std::endl;

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
