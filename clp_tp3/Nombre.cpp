#include "Expression.hpp"

class Nombre : public Expression {
public:
    Nombre (long l) {
        value_ = l;
    }

    ~Nombre() {};

private:
    long value_;
};
