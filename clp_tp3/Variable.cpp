#include "Expression.hpp"

class Variable : public Expression {
public:
    Variable (std::string s);

    ~Variable() {};
    

private:
    std::string name_;
};
