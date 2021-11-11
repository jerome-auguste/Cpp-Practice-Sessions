#include "Expression.hpp"

class Nombre : public Expression {
public:
    Nombre (long l) {
        value_ = l;
    }

    ~Nombre() {};

    void display(std::ostream & out) const {
        out << value_;
    }

    Expression* derive(std::string nom) const {
        return new Nombre{ 0 };
    }



private:
    long value_;
};