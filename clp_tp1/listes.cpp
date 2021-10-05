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

void print_list( const std::forward_list< int > &list ) {
    std::cout << "( ";
    for( auto el : list ) std::cout << el << " ";
    std::cout << ")" << std::endl;
}

std::forward_list< int > map_iter( const std::forward_list< int > &list, std::function< int( int ) > fct ) {
    std::forward_list< int > modified_list;
    for( auto el : list ) {
        modified_list.push_front(fct(el));
    }
    return modified_list;
}

void test_21() {
    std::cout << std::endl << "*** test_21 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    print_list(list);

    std::cout << std::endl;

}

void test_22() {
    std::cout << std::endl << "*** test_22 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    std::cout << std::endl << "Random list" << std::endl;
    print_list(list);

    std::forward_list< int > three_times_list = map_iter(list, []( int a ){ return 3*a; });
    std::cout << std::endl << "3* list" << std::endl;
    print_list(three_times_list);

    std::cout << std::endl;
}

int main()
{
    std::srand( std::time( nullptr ));

    //test_21();
    test_22();

    return 0;
}

