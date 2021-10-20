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

    Number(std::string s) {
        if (s.length() == 0) {
            throw std::invalid_argument("Empty string");
        }
        first_ = new Digit(s);

    }

    Number & operator=(const Number & n) {
        Number tmp(n);
        std::swap(first_, tmp.first_);

        return *this;
    }

    ~Number() { delete first_; }
 
    void print( std::ostream & out ) const { first_->print(out); }

    void add(unsigned int i) {
        first_->add(i);
    }

    void multiply(unsigned int i)
    {
    first_->multiply(i);
    }


private:
    using DigitType = unsigned int;
    // Un seul chiffre décimal par maillon : l'objectif ici n'est pas la performance
    static const DigitType number_base{ 10u };
    struct Digit {

        Digit(unsigned long long l):
            digit_( l%number_base )
            , next_( ( l>=number_base )? new Digit( l/number_base ): nullptr ) //if = ? et else = :
            {}
        
        Digit(std::string s) {
            unsigned int pow = 1;
            digit_ = 0;
            if (! std::isdigit( s.back())) {
                throw std::invalid_argument("Not a digit");
            }
            unsigned int c = static_cast< unsigned int >( s.back() - '0' ) * pow;

            while ((digit_ + c < number_base) && (s.length() > 0)) {
                digit_ += c;
                pow *= 10;
                if (! std::isdigit(s.back())) {
                    throw std::invalid_argument("Not a digit");
                }
                s.pop_back();
                c = static_cast< unsigned int >( s.back() - '0' ) * pow;
                }

                if (s.length() == 0) next_ = nullptr;
                else next_ = new Digit{ s };

        }
        
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

        void add(unsigned int i) {
            unsigned int intadd{ digit_ + i };
            digit_ = intadd % number_base;
            if( next_ != nullptr )  {
                next_->add( intadd / number_base );
            }
            else if( intadd >= number_base ) {
                next_ = new Digit{ intadd / number_base };
            }
        }

        void multiply(unsigned int i) {
            unsigned int intmult{ digit_ * i};
            digit_ = intmult%number_base;
            if( next_ != nullptr ) {
                next_->multiply(i);
                next_->add(intmult/number_base);
            }
            else if( intmult >= number_base ) next_ = new Digit{ intmult / number_base };
        }



        
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

inline Number factorial( unsigned int i ) {
        if (i==1) {
            return *new Number(1);
        }
        Number n = factorial(i-1);
        n.multiply(i);
        return n;
}

std::istream & operator>>( std::istream & in, Number & n );

#endif
