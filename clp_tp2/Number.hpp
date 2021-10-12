/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°2
 *
 * Number.hpp
 */

#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include <iostream>
#include <string>
#include <utility>

class Number {
public:
    Number( unsigned long long l ): first_( new Digit( l ) ) {}
    ~Number() { delete first_; }
 
    void print( std::ostream & out ) const { first_->print(out); }

private:
    using DigitType = unsigned int;
    // Un seul chiffre décimal par maillon : l'objectif ici n'est pas la performance
    static const DigitType number_base{ 10u };
    struct Digit {

        Digit(unsigned long long l):
            digit_( l%number_base )
            , next_( ( l>=number_base )? new Digit( l/number_base ): nullptr ) //if -> ? et else -> :
            {}
        
        ~Digit() { delete next_; }

        void print(std::ostream & out) const;
        
        DigitType digit_;
        Digit * next_;

    };
    Digit * first_;
};

inline std::ostream & operator<<( std::ostream & out, const Number & n )
{
    n.print( out );
    return out;
}

#endif
