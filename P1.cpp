//////============================================================================
////// Name        : P1.cpp
////// Author      : Aaron Lobo
////// Version     :
////// Copyright   :
////// Description : Hello World in C++, Ansi-style
//////============================================================================
////
////#include <iostream>
////#include <assert.h>
////
////#include "Double_sentinel_list.h"
////#include "ece250.h"
////
////int main() {
////	Double_sentinel_list<int> list;
////
////	std::cout << "Size:  " << list.size() << " ( = 0 )" << std::endl;
////	std::cout << "Empty:  " << list.empty() << " ( = 1 )" << std::endl;
////
////	assert(list.size() == 0);
////	assert(list.empty());
////
////	try {
////		list.front();
////	} catch (underflow e) {
////		std::cout << "Test Access Empty List (Front): Caught Underflow" << std::endl;
////	}
////	try {
////		list.back();
////	} catch (underflow e) {
////		std::cout << "Test Access Empty List (Back): Caught Underflow" << std::endl;
////	}
////
////	// start with 1, then try 2, and then 3, etc.
////	const int N = 3;
////
////	for ( int i = 0; i < N; ++i ) {
////		std::cout << "Push to front: " << i << std::endl;
////		list.push_front( i );
////	}
////	std::cout << "Size:  " << list.size() << " ( = " << N << " )" << std::endl;
////	std::cout << "Empty:  " << list.empty() << " ( = " << (N <= 0) << " )" << std::endl;
////	std::cout << "Front:  " << list.front() << " ( = " << (N - 1) << " )" << std::endl;
////	std::cout << "Back:  " << list.back() << " ( = 0 )" << std::endl;
////
////
////	for ( int i = N - 1; i >= 0; --i ) {
////		std::cout << "Pop front: " << list.pop_front() << " ( = " << i << ")" << std::endl;
////	}
////	std::cout << "Size:  " << list.size() << " ( = 0 )" << std::endl;
////	std::cout << "Empty:  " << list.empty() << " ( = 1 )" << std::endl;
////
////
////	for ( int i = 0; i < N; ++i ) {
////		std::cout << "Push to back: " << i << std::endl;
////		list.push_back( i );
////	}
////	std::cout << "Size:  " << list.size() << " ( = " << N << " )" << std::endl;
////	std::cout << "Empty:  " << list.empty() << " ( = " << (N <= 0) << " )" << std::endl;
////	std::cout << "Front:  " << list.front() << " ( = 0 )" << std::endl;
////	std::cout << "Back:  " << list.back() << " ( = " << (N - 1) << " )" << std::endl;
////
////
////	for ( int i = N - 1; i >= 0; --i ) {
////		std::cout << "Pop back: " << list.pop_back() << " ( = " << i << ")" << std::endl;
////	}
////	std::cout << "Size:  " << list.size() << " ( = 0 )" << std::endl;
////	std::cout << "Empty:  " << list.empty() << " ( = 1 )" << std::endl;
////
////
////	list.push_front(12);
////	list.push_front(189237);
////	list.push_back(12);
////	list.push_front(189237);
////	list.push_back(64);
////	list.push_front(421);
////	list.push_back(420);
////	list.push_front(683947);
////	list.push_back(12);
////
////	std::cout << "Count:  " << list.count(12) << " ( = 3 )" << std::endl;
////	std::cout << "Count:  " << list.count(189237) << " ( = 2 )" << std::endl;
////	std::cout << "Count:  " << list.count(421) << " ( = 1 )" << std::endl;
////
////	assert(list.count(12) == 3);
////	assert(list.count(189237) == 2);
////	assert(list.count(421) == 1);
////	for ( int i = 0; i < 9; ++i ) {
////		list.pop_back();
////	}
////
////	for ( int i = 0; i < 19; ++i ) {
////		list.push_front( i );
////	}
////	list.push_front( 3 );
////
////	assert(list.size() == 20);
////	assert(list.erase(2) == 1);
////	std::cout << list << std::endl;
////	assert(list.size() == 19);
////	assert(list.erase(3) == 1);
////	std::cout << list << std::endl;
////	assert(list.size() == 18);
////
////	std::cout << "Copying list" << std::endl;
////	Double_sentinel_list<int> list2 = Double_sentinel_list<int>(list);
////	std::cout << list << std::endl;
////	std::cout << list2 << std::endl;
////
////	std::cout << "Modifying Original List" << std::endl;
////	assert(list.erase(4) == 1);
////	assert(list.erase(5) == 1);
////	assert(list.erase(6) == 1);
////	std::cout << list << std::endl;
////	std::cout << list2 << std::endl;
////	return 0;
////}
//
///**
// * Executable:  Double_sentinel_list_cpptest.o
// * Author: Huh
// *
// * DO EDIT THIS FILE
// *
// */
//
//#include <iostream>
//#include "Double_sentinel_list.h"
//#include "Double_node.h"
//#include <assert.h>
//#include "Exception.h"
//
//template <typename T>
//T at(Double_sentinel_list<T> const&, int);
//
//template <typename T>
//void traverse(Double_sentinel_list<T> const& pList);
//
//int main() {
//
//	std::cout << "Starting Test Run" << std::endl;
//
//	/// Testing the Double_nodes
//	Double_node<double> temp1(1.0, NULL, NULL);
//	Double_node<double> temp2(1.0, NULL, NULL);
//
//	Double_node<double> d(5.0, &temp1, &temp2);
//	assert(d.retrieve() == 5.0);
//	assert(d.previous() == &temp1);
//	assert(d.next() == &temp2);
//
//	std::cout << "Double_node appears to be functional." << std::endl;
//
//	Double_sentinel_list<double> a;
//	assert(a.size() == 0);
//	assert(a.head()->next() == a.tail());
//	assert(a.head()->previous() == 0);
//	assert(a.tail()->previous() == a.head());
//	assert(a.tail()->next() == 0);
//	std::cout << "Double_sentinel_list default ctor as well as head() and tail() appear to be functional." <<  std::endl;
//
//	/// Testing push back and push front.
//	a.push_back(3.0);
//	a.push_back(4.0);
//	a.push_back(5.0);
//	a.push_front(2.0);
//	a.push_front(1.0);
//
//	assert(at(a, 0) == 1.0);
//	assert(at(a, 1) == 2.0);
//	assert(at(a, 2) == 3.0);
//	assert(at(a, 3) == 4.0);
//	assert(at(a, 4) == 5.0);
//	traverse(a);
//
//	std::cout << "push_back() and push_front() appear to be functional." << std::endl;
//
//	// Test front and back
//	assert(a.front() == 1.0);
//	assert(a.back() == 5.0);
//	std::cout << "front() and back() appear to be functional." << std::endl;
//
//	assert(a.size() == 5);
//	std::cout << "size() appears to be functional." << std::endl;
//
//	/// Test the copy constructor.
//	Double_sentinel_list<double> b(a);
//	assert(b.size() == 5);
//	assert(at(b, 0) == 1.0);
//	assert(at(b, b.size() - 1) == 5.0);
//	b.push_front(0.0);
//	b.push_front(-1.0);
//	assert(at(a, 0) == 1.0);
//	assert(at(a, 1) == 2.0);
//	assert(b.head()->previous() == 0);
//	assert(b.tail()->next() == 0);
//	traverse(b);
//
//	// Use copy constructor on an empty list
//	Double_sentinel_list<double> empty_list1;
//	Double_sentinel_list<double> empty_list2(empty_list1);
//	assert(empty_list2.size() == 0);
//	assert(empty_list2.head()->next() == empty_list2.tail());
//	assert(empty_list2.head()->previous() == 0);
//	assert(empty_list2.tail()->previous() == empty_list2.head());
//	assert(empty_list2.tail()->next() == 0);
//	traverse(empty_list2);
//	std::cout << "Copy constructor appears to be functional." << std::endl;
//
//
//	// Test to ensure that copy constructor creates a list of NEW nodes
//	a.push_back(3.0);
//	a.push_back(3.0);
//	a.push_back(3.0);
//	a.push_back(3.0);
//
//	assert(b.size() == 7);
//	assert(at(b, 0) == -1.0);
//	assert(at(b, 1) == 0.0);
//	assert(at(b, 2) == 1.0);
//	assert(b.pop_back() == 5.0);
//	b.push_back(5.0);
//	assert(b.pop_front() == -1.0);
//	b.push_front(-1.0);
//	std::cout << "Copy constructor appears to create a fully independent copy." << std::endl;
//
//	/// Test count function.
//	assert(a.count(3.0) == 5);
//	assert(a.count(-223.23) == 0);
//	std::cout << "count() appears to be functional." << std::endl;
//
//	/// Test erase function.
//	assert(a.erase(3.0) == 1);
//	assert(a.erase(12314.123) == 0);
//
//	assert(a.size() == 8);
//	assert(at(a, 0) == 1.0);
//	assert(at(a, 1) == 2.0);
//	assert(at(a, 2) == 4.0);
//	assert(at(a, 3) == 5.0);
//	assert(at(a, 4) == 3.0);
//	assert(at(a, 5) == 3.0);
//	assert(at(a, 6) == 3.0);
//	assert(at(a, 7) == 3.0);
//
//	std::cout << "erase() seems to be functional." << std::endl;
//
//	/// Test pop_back() and pop_front()
//	assert(a.pop_back() == 3.0);
//	assert(a.size() == 7);
//	assert(a.pop_front() == 1.0);
//	assert(a.size() == 6);
//	a.push_front(10.0);
//	assert(at(a, 2) == 4.0);
//
//	std::cout << "pop_back(), pop_front() appear to be functional." << std::endl;
//
//	a.swap(b);
//	assert(a.size() == 7);
//	assert(!a.empty());
//	traverse(a);
//	traverse(b);
//	std::cout << "empty() appears to be functional." << std::endl;
//
//	Double_sentinel_list<double> c;
//	assert(c.erase(2423.12354) == 0);
//	std::cout << "Running erase on an empty list doesn't pose issues." << std::endl;
//
//	assert(c.size() == 0);
//	assert(c.empty());
//
//	// Test a bunch of functions on an empty list to make sure that works
//	c.push_back(42.0);
//	assert(c.erase(42.0) == 1);
//	assert(c.size() == 0);
//	assert(c.count(5.0) == 0);
//	assert(c.empty());
//	assert(c.head()->next() == c.tail());
//	assert(c.tail()->previous() == c.head());
//	traverse(c);
//	std::cout << "erase appears to properly modify the sentinels." << std::endl;
//
//
//	// Test to make sure your code throws the correct exceptions
//	try
//	{
//		c.pop_front();
//		assert(false);
//	}
//	catch (underflow e)
//	{
//		std::cout << "pop front on empty working as expected." << std::endl;
//	}
//
//	try
//	{
//		c.pop_back();
//		assert(false);
//	}
//	catch (underflow e)
//	{
//		std::cout << "pop back on empty working as expected." << std::endl;
//	}
//
//	try
//	{
//		c.front();
//		assert(false);
//	}
//	catch (underflow e)
//	{
//		std::cout << "front on empty is working as expected." << std::endl;
//	}
//
//	try
//	{
//		c.back();
//		assert(false);
//	}
//	catch (underflow e)
//	{
//		std::cout << "back on empty is working as expected." << std::endl;
//	}
//
//	std::cout << "Finishing Test Run" << std::endl;
//
//
//	return 0;
//}
//
//// This function checks the value of your list at certain index.
//// If it fails, it means you can't get to the member from either side like
//// you should be able to.
//template <typename T>
//T at(Double_sentinel_list<T> const& pList, int pIndex)
//{
//	int lIndex = pIndex;
//	Double_node<T> *it = pList.head()->next();
//	Double_node<T> *tmp;
//
//	while(lIndex > 0)
//	{
//		it = it->next();
//		lIndex--;
//	}
//
//	tmp = it;
//
//	// Example: size 9, index 5 (6th member)
//	// it starts on index 8, and must move back 3
//	// therefore lIndex = size - 1 - index when going backwards
//	lIndex = pList.size() - 1 - pIndex;
//	it = pList.tail()->previous();
//
//	while(lIndex > 0)
//	{
//		it = it->previous();
//		lIndex--;
//	}
//
//	assert(it == tmp);
//
//	return it->retrieve();
//}
//
//// Checks to see if you can get from the head to the tail of the list.
//// then checks to see if you can get from the tail to the head.
//// If this fails, it means that you've damaged your list when reassigning pointers.
//template <typename T>
//void traverse(Double_sentinel_list<T> const& pList)
//{
//	Double_node<T> *it = pList.head();
//	int counter = 0;
//
//	std::cout << "_" << std::endl;
//
//	while (it != nullptr)
//	{
//		std::cout << it->retrieve() << std::endl;
//
//		if (counter > pList.size())
//		{
//			assert(false);
//		}
//		it = it->next();
//		// Upon reaching the tail node break
//		if (it->next() == nullptr)
//		{
//			break;
//		}
//		++counter;
//	}
//
//	assert(it == pList.tail() && counter == pList.size());
//
//	it = pList.tail();
//	counter = 0;
//
//	while (it != nullptr)
//	{
//		if (counter > pList.size())
//		{
//			assert(false);
//		}
//		it = it->previous();
//
//		if (it->previous() == nullptr)
//		{
//			break;
//		}
//		++counter;
//	}
//
//	assert(it == pList.head() && counter == pList.size());
//}
