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
    static inline unsigned int nb_inst = 0;

    Expression() {nb_inst++;};

    virtual ~Expression() {nb_inst--;};

    virtual void display(std::ostream & out) const = 0;

    virtual Expression* derive(std::string name) const = 0;
    /* derivative of expression with respect to "name"
     Input:
        - string : variable
     Output:
        - A newly allocated Expression* element :
            * Derivative of Nombre with respect to any variable is 0
            * Derivative of Variable "x" with respect to string "x" is 1
            * Derivative of Variable "y" with respect to string "x" is 0
     */

    virtual Expression* clone() const = 0;


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