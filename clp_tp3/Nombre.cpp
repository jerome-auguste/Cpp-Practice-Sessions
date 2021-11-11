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


private:
    long value_;
};
