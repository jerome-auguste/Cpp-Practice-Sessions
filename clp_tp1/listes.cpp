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

std::forward_list< int > map_iter( const std::forward_list< int > list, std::function< int( int ) > fct ) {
    std::forward_list< int > modified_list;
    for( auto el : list ) {
        modified_list.push_front(fct(el));
    }
    return modified_list;
}

std::forward_list< int > filter_iter( const std::forward_list< int > list, std::function< bool( int ) > predicate ) {
    std::forward_list< int > filtered_list;
    for(auto el : list) {
        if(predicate(el)) {
            filtered_list.push_front(el);
        }
    }
    return filtered_list;
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

void test_23() {
    std::cout << std::endl << "*** test_23 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    std::cout << std::endl << "Random list" << std::endl;
    print_list(list);

    std::forward_list< int > three_times_list = map_iter(list, []( int a ){ return 3*a; });
    std::cout << std::endl << "3* list" << std::endl;
    print_list(three_times_list);

    std::forward_list< int > filtered_list = filter_iter(three_times_list, []( int a ){ return a%2==0; });
    std::cout << std::endl << "filtered list" << std::endl;
    print_list(filtered_list);

    std::cout << std::endl;
}

void test_24() {
    std::cout << std::endl << "*** test_24 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    std::cout << std::endl << "Random list" << std::endl;
    print_list(list);

    int coef = rand()%5 + 1;
    std::cout << std::endl << "Times" << std::endl << coef << std::endl;

    std::forward_list< int > three_times_list = map_iter(list, [coef]( int a ){ return coef*a; });
    std::cout << std::endl << coef << "* list" << std::endl;
    print_list(three_times_list);

    std::forward_list< int > filtered_list = filter_iter(three_times_list, []( int a ){ return a%2==0; });
    std::cout << std::endl << "filtered list" << std::endl;
    print_list(filtered_list);

    std::cout << std::endl;
}

int main()
{
    std::srand( std::time( nullptr ));

    //test_21();
    //test_22();
    //test_23();
    test_24();

    return 0;
}

