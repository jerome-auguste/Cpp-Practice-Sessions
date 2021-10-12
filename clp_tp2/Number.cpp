/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°2
 *
 * Number.cpp
 */

#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

#include "Number.hpp"


void Number::Digit::print( std::ostream & out ) const {

    if (next_ != nullptr) {
        next_->print(out);
    }
    out << digit_;
    
}

