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
#include <vector>


void print_tab(const std::vector< int > tab) {
    std::cout << "[ ";
    for (int i=0; i<tab.size(); i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void test11() {
    std::cout << std::endl << "*** test_11 ***" << std::endl;
    const std::vector< int > tab{ 1, -2, 3, -4, 5, -6 };
    print_tab(tab);
    std::cout << std::endl;
}

int main()
{
    std::srand( std::time( nullptr ));

    test11();

    return 0;
}

