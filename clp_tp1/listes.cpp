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

#include <algorithm>

std::forward_list< int > random_list( int length ) {

    //Random list generation
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
    //Interative function over the element of the list

    //Create a new list that will contain the modified values
    std::forward_list< int > modified_list;

    for( auto el : list ) {
        modified_list.push_front(fct(el));
    }

    return modified_list;
}

std::forward_list< int > filter_iter( const std::forward_list< int > list, std::function< bool( int ) > predicate ) {
    //Filter a list depending on a predicate

    //Create a new list that will contain filtered value according to the predicate
    std::forward_list< int > filtered_list;

    for(auto el : list) {
        if(predicate(el)) {
            filtered_list.push_front(el);
        }
    }

    return filtered_list;
}

int reduce( const std::forward_list< int > list, int n, std::function< int( int, int ) > red_fct ) {
    //Reduction function (min, max...)

    bool first_el = true;
    int res;

    for( auto el : list ) {
        //First element specificity
        if (first_el) {
            res = red_fct(n, el);
            first_el = false;
        }
        else {
            res = red_fct(res, el);
        }
    }
    return res;
}

int fold_left_aux( std::forward_list< int >::const_iterator it, std::forward_list< int >::const_iterator end, int n, std::function< int( int, int ) > red_fct ) {

    if (std::next(it,1) == end) {
        return red_fct(n, *it);
    }

    return red_fct(*it, fold_left_aux(std::next(it,1), end, n, red_fct));
}

int fold_left(const std::forward_list< int > list, int n, std::function< int( int, int ) > red_fct) {
    return fold_left_aux(list.cbegin(), list.cend(), n, red_fct);
}

std::forward_list< int > map_aux(std::forward_list< int >::const_iterator it, std::forward_list< int >::const_iterator end, std::function< int( int ) > fct) {
    std::forward_list< int > res_list;
    if (std::next(it,1) == end) {
        res_list.push_front(fct(*it));
        return res_list;
    }
    res_list.merge(map_aux(std::next(it, 1), end, fct));
    res_list.push_front(fct(*it));
    return res_list;
}

std::forward_list< int > map( const std::forward_list< int > list, std::function< int( int ) > fct ) {
    return map_aux(list.cbegin(), list.cend(), fct);
}

std::forward_list< int > filter_aux( std::forward_list< int >::const_iterator it, std::forward_list< int >::const_iterator end, std::function< bool( int ) > predicate ) {
    std::forward_list< int > filtered_list;
    if (std::next(it,1) == end) {
        if (predicate(*it)) {
            filtered_list.push_front(*it);
        }
        return filtered_list;
    }

    filtered_list.merge(filter_aux(std::next(it, 1), end, predicate));

    if (predicate(*it)) {
        filtered_list.push_front(*it);
    }

    return filtered_list;
}

std::forward_list< int > filter( const std::forward_list< int > list, std::function< bool( int ) > predicate ) {
    return filter_aux(list.cbegin(), list.cend(), predicate);
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

void test_25() {
    std::cout << std::endl << "*** test_25 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    std::cout << std::endl << "Random list" << std::endl;
    print_list(list);

    int min_result = reduce(list, std::numeric_limits<int>::max(), []( int res, int el ){ return std::min(res, el); });
    std::cout << std::endl << "min value" << std::endl << min_result << std::endl;

    int max_result = reduce(list, std::numeric_limits<int>::min(), []( int res, int el ){ return std::max(res, el); });
    std::cout << std::endl << "max value" << std::endl << max_result << std::endl;

    std::cout << std::endl;
}

void test_31() {
    std::cout << std::endl << "*** test_31 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    std::cout << std::endl << "Random list" << std::endl;
    print_list(list);

    int min_result = fold_left(list, std::numeric_limits<int>::max(), []( int res, int el ){ return std::min(res, el); });
    std::cout << std::endl << "min value" << std::endl << min_result << std::endl;

    int max_result = fold_left(list, std::numeric_limits<int>::min(), []( int res, int el ){ return std::max(res, el); });
    std::cout << std::endl << "max value" << std::endl << max_result << std::endl;

    std::cout << std::endl;
}

void test_32() {
    std::cout << std::endl << "*** test_32 ***" << std::endl;

    const std::forward_list< int > list = random_list(10);
    std::cout << std::endl << "Random list" << std::endl;
    print_list(list);

    int coef = rand()%5 + 1;
    std::cout << std::endl << "Times" << std::endl << coef << std::endl;

    std::forward_list< int > mapped_list = map(list, [coef]( int a ){ return coef*a; });
    std::cout << std::endl << coef << "* list" << std::endl;
    print_list(mapped_list);

    std::forward_list< int > filtered_list = filter(mapped_list, []( int a ){ return a%2==0; });
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
    //test_24();
    //test_25();
    //test_31();
    test_32();

    return 0;
}

