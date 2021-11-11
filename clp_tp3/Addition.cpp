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

    Expression* clone() const {
        return new Addition (left_exp_->clone(), right_exp_->clone());
    }

    Expression* simplify() const {
        Expression* left_simp = left_exp_->simplify();
        Expression* right_simp = right_exp_->simplify();

        if (left_simp->get_type()=="Nombre") {
            Nombre* left_num = dynamic_cast< Nombre* > ( left_simp );
            if (right_simp->get_type()=="Nombre") {
                Nombre* right_num = dynamic_cast< Nombre* > ( right_simp );
                long result = left_num->get_value() + right_num->get_value();
                delete left_simp;
                delete right_simp;
                return new Nombre { result };
            }
            else {
                if (left_num->get_value() == 0) {
                    delete left_simp;
                    return right_simp->clone();
                }

            }
        }

        if (right_simp->get_type()=="Nombre") {
            Nombre* right_num = dynamic_cast< Nombre* > ( right_simp );
            
            if (right_num->get_value() == 0) {
                delete right_simp;
                return left_simp->clone();
            }
        }

        return new Addition(left_simp, right_simp);

    }

    std::string get_type() const {
        return "Addition";
    }

private:
};
