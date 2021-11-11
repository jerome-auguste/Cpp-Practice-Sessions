/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°3
 *
 * Expression.hpp
 */

#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include <iostream>
#include <string>
#include <utility>
#include <memory>

class Expression {
public:
    Expression() {};

    virtual ~Expression() {};

    virtual void display(std::ostream & out) const = 0;

private:
};

inline std::ostream & operator << (std::ostream & out, const Expression & exp) {
    /* Sends an expression to a specified stream.
     Params:
        - std::ostream & : the stream to send the expression to
        - Expression & : the expression to output (const argument)
     Returns:
        - The out stream
     */

    exp.display(out);
    return out;
}

#endif