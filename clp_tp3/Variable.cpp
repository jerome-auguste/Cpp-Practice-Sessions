#include "Expression.hpp"

class Variable : public Expression {
public:
    Variable (std::string s) {
        name_ = s;
    }

    ~Variable() {};

    void display(std::ostream & out) const {
        out << name_;
    }


    

private:
    std::string name_;
};
