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

    Expression* clone() const {
        return new Nombre{value_};
    }

    Expression* simplify() const {
        return this->clone();
    }

    std::string get_type() const {
        return "Nombre";
    }

    long get_value() const {
        return value_;
    }


private:
    long value_;
};
