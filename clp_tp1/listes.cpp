/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°1
 *
 * listes.cpp
 */

#include <iostream>
#include <forward_list>
#include <functional>
#include <limits>

#include <cstdlib>
#include <ctime>

std::forward_list< int > random_list( int length ) {
    std::forward_list< int > list;
    for( int i=0; i<length; i++ ) {
        list.push_front( rand() % 100 );
    }
    return list;
}

void print_list( const std::forward_list< int > list ) {
    std::cout << "( ";
    for( auto el : list ) std::cout << el << " ";
    std::cout << ")" << std::endl;
}

void test_21() {
    std::cout << std::endl << "*** test_15 ***" << std::endl;
    
    const std::forward_list< int > list = random_list(10);
    print_list(list);

    std::cout << std::endl;

}

int main()
{
    std::srand( std::time( nullptr ));
    test_21();
    return 0;
}

