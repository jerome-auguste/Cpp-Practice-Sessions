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

    std::string get_type() const {
        return "Multiplication";
    }

    Expression* simplify() const {
        Expression* left_simp = left_exp_->simplify();
        Expression* right_simp = right_exp_->simplify();

        if (left_simp->get_type()=="Nombre") {
            Nombre* left_num = dynamic_cast< Nombre* > ( left_simp );
            if (right_simp->get_type()=="Nombre") {
                Nombre* right_num = dynamic_cast< Nombre* > ( right_simp );
                long result = left_num->get_value() * right_num->get_value();
                delete left_simp;
                delete right_simp;
                return new Nombre { result };
            }
            else {
                if (left_num->get_value() == 1) {
                    delete left_simp;
                    return right_simp->clone();
                }
                if (left_num->get_value() == 0) {
                    delete left_simp;
                    delete right_simp;
                    return new Nombre(0);
                }

            }
        }

        if (right_simp->get_type()=="Nombre") {
            Nombre* right_num = dynamic_cast< Nombre* > ( right_simp );
            
            if (right_num->get_value() == 1) {
                delete right_simp;
                return left_simp->clone();
            }

            if (right_num->get_value() == 0) {
                delete right_simp;
                delete left_simp;
                return new Nombre(0);
            }
        }

        return new Multiplication(left_simp, right_simp);
    }

private:
};

