/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°1
 *
 * tris.cpp
 */

#include <iostream>
#include <vector>
#include <utility>
#include <functional>

#include <cstdlib>
#include <ctime>

#include <vector>
#include <algorithm>


void print_tab(const std::vector< int > &tab) {
    std::cout << "[ ";
    for (int i=0; i<tab.size(); i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void random_tab(std::vector< int > &tab) {
    for (int i=0; i<tab.size(); i++) {
        tab[i] = rand() % 21 - 10;
    }
}

void sort_tab_1(std::vector< int > &tab) {
    for (int i=0; i<tab.size();i++) {
        int j_min = i;
        int min = tab[i];
        for (int j=i; j<tab.size(); j++) {
            if (tab[j]<min) {
                min = tab[j];
                j_min = j;
            }
        }
        std::swap(tab[i], tab[j_min]);
    }
}

bool less(int a, int b) {
    return a<b;
}

bool greater (int a, int b) {
    return a>b;
}

void sort_tab_2(std::vector< int > &tab, bool (*comp)(int, int)) {
    std::sort(tab.begin(), tab.end(), comp);
}

void sort_tab_3(std::vector< int > &tab, std::function< bool(int, int) > comp) {
    std::sort(tab.begin(), tab.end(), comp);
}


void test_11() {
    std::cout << std::endl << "*** test_11 ***" << std::endl;
    const std::vector< int > tab{ 1, -2, 3, -4, 5, -6 };
    print_tab(tab);
    std::cout << std::endl;
}

void test_12() {
    std::cout << std::endl << "*** test_12 ***" << std::endl;
    std::vector< int > tab (10);
    random_tab(tab);
    print_tab(tab);
    std::cout << std::endl;
}

void test_13() {
    std::cout << std::endl << "*** test_13 ***" << std::endl;

    std::vector< int > tab (10);
    random_tab(tab);
    std::cout << std::endl << "Random tab" << std::endl;
    print_tab(tab);

    sort_tab_1(tab);
    std::cout << std::endl << "Sorted tab" << std::endl;
    print_tab(tab);

    std::cout << std::endl;
}

void test_14() {
    std::cout << std::endl << "*** test_14 ***" << std::endl;

    std::vector< int > tab_greater (10);
    random_tab(tab_greater);

    std::vector< int > tab_less = tab_greater;

    std::cout << std::endl << "Random tab" << std::endl;
    print_tab(tab_greater);

    sort_tab_2(tab_greater, greater);
    std::cout << std::endl << "Sorted tab with greater" << std::endl;
    print_tab(tab_greater);

    sort_tab_2(tab_less, less);
    std::cout << std::endl << "Sorted tab with less" << std::endl;
    print_tab(tab_less);

    std::cout << std::endl;
}

void test_15() {
    std::cout << std::endl << "*** test_15 ***" << std::endl;

    std::vector< int > tab_asc (10);
    random_tab(tab_asc);

    std::vector< int > tab_desc = tab_asc;

    std::cout << std::endl << "Random tab" << std::endl;
    print_tab(tab_asc);

    sort_tab_3(tab_asc, []( int a, int b ) { return abs(a)<abs(b); });
    std::cout << std::endl << "Sorted tab in ascending order" << std::endl;
    print_tab(tab_asc);

    sort_tab_3(tab_desc, []( int a, int b ) { return abs(a)>abs(b); });
    std::cout << std::endl << "Sorted tab in descending order" << std::endl;
    print_tab(tab_desc);

    std::cout << std::endl;
}

int main()
{
    std::srand( std::time( nullptr ));

    //test_11();
    //test_12();
    //test_13();
    //test_14();
    test_15();

    return 0;
}

