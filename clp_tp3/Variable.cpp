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

    Expression* derive(std::string nom) const {
        if (name_ == nom) {
            return new Nombre{ 1 };
        }
        return new Nombre{ 0 };
    }

    

private:
    std::string name_;
};
