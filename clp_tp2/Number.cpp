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

std::istream & operator>>( std::istream & in, Number & n ) {
    // TODO
    // in est le flux d'entrée
 
  // ignore les blancs au début
    in >> std::ws;
    std::string str_number = "";
    while( in.good() ) {
      int c{ in.get() };
        if( std::isdigit( c )) {
            // ... à vous de l'utiliser ...
            str_number.append(std::to_string(c-48));
            
        }
        else {
            in.putback( c );
            break;
        }
    }
    n = Number(str_number);
    return in;
}

