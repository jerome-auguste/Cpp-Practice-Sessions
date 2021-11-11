#include "Addition.cpp"
#include <string>

class Multiplication : public Operation {
public:
    Multiplication (Expression* left, Expression* right) : Operation(left, right) {}

    ~Multiplication() {};
    
    std::string op_sym() const {
        return "*";
    }
    
    Expression* derive(std::string name) const {
    return new Addition (
                         new Multiplication(left_exp_->derive(name), right_exp_->clone()),
                         new Multiplication(right_exp_->derive(name), left_exp_->clone()) );
    }

    Expression* clone() const {
    return new Multiplication (left_exp_->clone(), right_exp_->clone());
    }


private:
};

