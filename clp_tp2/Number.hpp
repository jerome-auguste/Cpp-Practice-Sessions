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

    Number( const Number & n) {
        first_ = new Digit(*(n.first_));
    }

    Number & operator=(const Number & n) {
        Number tmp(n);
        std::swap(first_, tmp.first_);

        return *this;
    }

    ~Number() { delete first_; }
 
    void print( std::ostream & out ) const { first_->print(out); }

private:
    using DigitType = unsigned int;
    // Un seul chiffre décimal par maillon : l'objectif ici n'est pas la performance
    static const DigitType number_base{ 10u };
    struct Digit {

        Digit(unsigned long long l):
            digit_( l%number_base )
            , next_( ( l>=number_base )? new Digit( l/number_base ): nullptr ) //if = ? et else = :
            {}
        
        ~Digit() { delete next_; }

        Digit(const Digit &d) {
            next_ = d.next_;
            digit_ = d.digit_;
            if (d.next_ != nullptr) {
                next_ = new Digit(*(d.next_));
            }
        }

        Digit & operator=(Digit d) {
            Digit tmp(d);
            digit_ = d.digit_;
            std::swap(next_, tmp.next_);
            return *this;
        }

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
