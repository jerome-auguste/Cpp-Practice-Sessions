#include <stdio.h>
#include "Expression.hpp"


class Operation : public Expression {
public:
    Operation (Expression* left, Expression* right) {
    /* Operation
    Create Operation instance
    Input:
        - Expression* : a pointer to an Expression
        - Expression* : a pointer to an Expression
    */
        left_exp_ = left;
        right_exp_ = right;

    }
    
    ~Operation() {};
    /* ~Operation
     Deletes the object but not the Operation's arguments
     */
    
    virtual std::string op_sym() const = 0;

    void display( std::ostream & out ) const {
        out << *left_exp_ << op_sym() << *right_exp_;
    }
    
    virtual Expression* derive(std::string name) const = 0;

protected:
    Expression* left_exp_;
    Expression* right_exp_;

private:
};
