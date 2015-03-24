#include <iostream>
#include "assert.h"
#include "Quadratic_hash_table.h"
#include "Exception.h"

int main() {
    
    int n = 5;
    
    Quadratic_hash_table<int> *QHT0 = new Quadratic_hash_table<int>(n);
    
    std::cout << "Base test" << std::endl;
    QHT0->insert(31);
    QHT0->insert(191);
    assert(QHT0->bin(31) == 31);
    assert(QHT0->bin(0) == 191);
    QHT0->insert(159);
    assert(QHT0->bin(2) == 159);
    assert(QHT0->erase(111) == false);
    assert(QHT0->erase(159) == true);
    assert(QHT0->erase(159) == false);
    assert(QHT0->size() == 2);
    std::cout << "Base test passed" << std::endl;
    
    delete QHT0;
    
    Quadratic_hash_table<int> *QHT = new Quadratic_hash_table<int>(n);
    
    std::cout << "Testing Initialization" << std::endl;
    assert(QHT->size() == 0);
    assert(QHT->capacity() == 1 << n);
    assert(QHT->load_factor() == 0);
    assert(QHT->empty() == true);
    std::cout << "Testing Initializations passed" << std::endl;
    
    std::cout << "Testing insertion into UNOCCUPIED bin" << std::endl;
    QHT->insert(0);
    QHT->insert(1);
    QHT->insert(2);
    QHT->insert(3);
    QHT->insert(4);
    QHT->insert(5);
    QHT->insert(6);
    
    assert(QHT->bin(0) == 0);
    assert(QHT->bin(1) == 1);
    assert(QHT->bin(2) == 2);
    assert(QHT->bin(3) == 3);
    assert(QHT->bin(4) == 4);
    assert(QHT->bin(5) == 5);
    assert(QHT->bin(6) == 6);
    
    assert(QHT->size() == 7);
    std::cout << "Testing insertion into UNOCCUPIED bin pass" << std::endl;
    
    std::cout << "Testing insertion where collisions occur" << std::endl;
    QHT->insert(12);
    QHT->insert(13);
    QHT->insert(20);
    QHT->insert(31);
    QHT->insert(63);
    QHT->insert(11);
    QHT->insert(24);
    QHT->insert(42);
    QHT->insert(64);
    assert(QHT->bin(12) == 12);
    assert(QHT->bin(13) == 13);
    assert(QHT->bin(20) == 20);
    assert(QHT->bin(31) == 31);
    assert(QHT->bin(9) == 63);
    assert(QHT->bin(11) == 11);
    assert(QHT->bin(24) == 24);
    assert(QHT->bin(10) == 42);
    assert(QHT->bin(15) == 64);
    
    assert(QHT->size() == 16);
    
    std::cout << "Testing insertion where collisions occur passed" << std::endl;
    
    std::cout << "Testing erase/member functionality" << std::endl;
    assert(QHT->member(100) == false);
    assert(QHT->erase(100) == false);
    
    assert(QHT->member(-12823) == false);
    assert(QHT->erase(-12823) == false);
    
    assert(QHT->member(12) == true);
    assert(QHT->erase(12) == true);
    assert(QHT->member(12) == false);
    
    assert(QHT->member(64) == true);
    assert(QHT->member(31) == true);
    assert(QHT->erase(64) == true);
    assert(QHT->erase(31) == true);
    assert(QHT->member(64) == false);
    assert(QHT->member(31) == false);
    
    assert(QHT->size() == 13);
    
    std::cout << "Testing erase/member functionality passed" << std::endl;
    
    std::cout << "Testing clear functionality" << std::endl;
    QHT->clear();
    assert(QHT->size() == 0);
    assert(QHT->member(0) == false);
    assert(QHT->member(1) == false);
    assert(QHT->member(2) == false);
    assert(QHT->erase(3) == false);
    assert(QHT->erase(4) == false);
    assert(QHT->erase(5) == false);
    assert(QHT->erase(6) == false);
    std::cout << "Testing clear functionality passed" << std::endl;
    
    delete QHT;
    
    Quadratic_hash_table<int> *QHT2 = new Quadratic_hash_table<int>(n);
    
    std::cout << "Testing for overflow" << std::endl;
    
    for (int i = 0; i < (1 << n); i++) {
        QHT2->insert(i);
    }
    
    try {
        QHT2->insert(32);
        assert(false);
    } catch (overflow e) {}
    
    std::cout << "Testing for overflow passed" << std::endl;
    
    delete QHT2;
    
    Quadratic_hash_table<int> *QHT3 = new Quadratic_hash_table<int>(n);
    
    std::cout << "Testing insertion of both negative and positive numbers" << std::endl;
    
    QHT3->insert(0);
    QHT3->insert(5);
    QHT3->insert(100);
    QHT3->insert(-10);
    QHT3->insert(-20);
    QHT3->insert(-69);
    QHT3->insert(69);
    QHT3->insert(42);
    QHT3->insert(-42);
    QHT3->insert(3);
    QHT3->insert(6);
    QHT3->insert(9);
    QHT3->insert(-11);
    QHT3->insert(13);
    QHT3->insert(14);
    QHT3->insert(27);
    QHT3->insert(33);
    QHT3->insert(22);
    QHT3->insert(86);
    QHT3->insert(-79);
    QHT3->insert(49);
    QHT3->insert(52);
    QHT3->insert(-3);
    QHT3->insert(-7);
    QHT3->insert(-31);
    QHT3->insert(4);
    QHT3->insert(28);
    QHT3->insert(2000);
    QHT3->insert(-15);
    QHT3->insert(23);
    QHT3->insert(15);
    QHT3->insert(7);
    
    assert(QHT3->bin(0) == 0);
    assert(QHT3->bin(1) == 33);
    assert(QHT3->bin(2) == -31);
    assert(QHT3->bin(3) == 3);
    assert(QHT3->bin(4) == 100);
    assert(QHT3->bin(5) == 5);
    assert(QHT3->bin(6) == 69);
    assert(QHT3->bin(7) == 6);
    assert(QHT3->bin(8) == 7);
    assert(QHT3->bin(9) == 9);
    assert(QHT3->bin(10) == 42);
    assert(QHT3->bin(11) == 86);
    assert(QHT3->bin(12) == -20);
    assert(QHT3->bin(13) == 13);
    assert(QHT3->bin(14) == 14);
    assert(QHT3->bin(15) == 15);
    assert(QHT3->bin(16) == 2000);
    assert(QHT3->bin(17) == -79);
    assert(QHT3->bin(18) == 49);
    assert(QHT3->bin(19) == 4);
    assert(QHT3->bin(20) == 52);
    assert(QHT3->bin(21) == -11);
    assert(QHT3->bin(22) == -10);
    assert(QHT3->bin(23) == -42);
    assert(QHT3->bin(24) == 23);
    assert(QHT3->bin(25) == 22);
    assert(QHT3->bin(26) == -7);
    assert(QHT3->bin(27) == -69);
    assert(QHT3->bin(28) == 27);
    assert(QHT3->bin(29) == -3);
    assert(QHT3->bin(30) == -15);
    assert(QHT3->bin(31) == 28);
    assert(QHT3->size() == 32);
    
    std::cout << "Testing insertion of both negative and positive numbers Passed" << std::endl;
    
    std::cout << "Testing for erase with load factor" << std::endl;
    
    assert(QHT3->load_factor() == 1);
    QHT3->erase(69);
    QHT3->erase(-69);
    assert(QHT3->load_factor() == 0.9375);
    assert(QHT3->size() == 30);
    
    std::cout << "Testing for erase with load factor passed" << std::endl;
    
    delete QHT3;
    
    std::cout << "Additional testing for erase with load factor" << std::endl;
    QHT3 = new Quadratic_hash_table<int>(3);
    QHT3->insert(8);
    assert(QHT3->bin(0) == 8);
    QHT3->insert(16);
    assert(QHT3->bin(1) == 16);
    QHT3->insert(24);
    assert(QHT3->bin(3) == 24);
    QHT3->insert(32);
    assert(QHT3->bin(6) == 32);
    QHT3->insert(10);
    assert(QHT3->bin(2) == 10);
    assert(QHT3->erase(16) == true);
    assert(QHT3->member(24) == true);
    QHT3->insert(7);
    assert(QHT3->bin(7) == 7);
    assert(QHT3->member(15) == false);
    QHT3->insert(64);
    assert(QHT3->bin(1) == 64);
    assert(QHT3->load_factor() == 0.75);
    assert(QHT3->erase(10) == true);
    assert(QHT3->erase(7) == true);
    assert(QHT3->load_factor() == 0.75);
    QHT3->insert(15);
    assert(QHT3->load_factor() == 0.75);
    QHT3->insert(13);
    assert(QHT3->load_factor() == 0.875);
    QHT3->insert(12);
    QHT3->insert(65);
    assert(QHT3->load_factor() == 1.0);
    QHT3->clear();
    assert(QHT3->load_factor() == 0.0);
    std::cout << "Additional testing for erase with load factor passed" << std::endl;
    
    delete QHT3;
    
    Quadratic_hash_table<int> *QHT4 = new Quadratic_hash_table<int>(n);
    
    std::cout << "Testing ignore duplicates" << std::endl;
    
    QHT4 = new Quadratic_hash_table<int>(n);
    
    QHT4->insert(0);
    QHT4->insert(5);
    QHT4->insert(100);
    QHT4->insert(-10);
    QHT4->insert(-20);
    QHT4->insert(-69);
    QHT4->insert(69);
    QHT4->insert(42);
    QHT4->insert(-42);
    QHT4->insert(3);
    QHT4->insert(6);
    QHT4->insert(9);
    
    assert(QHT4->bin(0) == 0);
    assert(QHT4->bin(3) == 3);
    assert(QHT4->bin(4) == 100);
    assert(QHT4->bin(5) == 5);
    assert(QHT4->bin(6) == 69);
    assert(QHT4->bin(7) == 6);
    assert(QHT4->bin(9) == 9);
    assert(QHT4->bin(10) == 42);
    assert(QHT4->bin(12) == -20);
    assert(QHT4->bin(22) == -10);
    assert(QHT4->bin(27) == -69);
    assert(QHT4->bin(23) == -42);
    assert(QHT4->size() == 12);
    
    QHT4->insert(-10);
    
    //Ensure table was not modified
    assert(QHT4->size() == 12);
    assert(QHT4->bin(0) == 0);
    assert(QHT4->bin(3) == 3);
    assert(QHT4->bin(4) == 100);
    assert(QHT4->bin(5) == 5);
    assert(QHT4->bin(6) == 69);
    assert(QHT4->bin(7) == 6);
    assert(QHT4->bin(9) == 9);
    assert(QHT4->bin(10) == 42);
    assert(QHT4->bin(12) == -20);
    assert(QHT4->bin(22) == -10);
    assert(QHT4->bin(27) == -69);
    assert(QHT4->bin(23) == -42);
    
    delete QHT4;
    
    std::cout << "Testing ignore duplicates passed" << std::endl;
    
    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}
