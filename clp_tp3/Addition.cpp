#include <string>
#include "Operation.cpp"

class Addition : public Operation {
public:
    Addition (Expression* left, Expression* right) : Operation(left, right) {}

    ~Addition() {};
    
    std::string op_sym() const {
        return "+";
    }
    
    Expression* derive(std::string name) const {

        return new Addition (left_exp_->derive(name), right_exp_->derive(name));
    }

private:
};
