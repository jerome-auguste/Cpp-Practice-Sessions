/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°3
 *
 * TestExpression.cpp
 * c++ -std=c++20 -o TestExpression TestExpression.cpp Expression.cpp -lgtest -lpthread
 */

#include <sstream>
#include <utility>

#include <gtest/gtest.h>

#include "Expression.cpp"
#include "Nombre.cpp"
#include "Variable.cpp"

 
int main( int argc, char * argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}

TEST( TestExp, TestNombre0 ) {
    Nombre n{ 0 };
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "0" );
}

TEST( TestExp, TestNombre734998 ) {
    Nombre n{ 734998 };
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "734998" );
}

TEST( TestExp, TestVariableEmpty ) {
    Variable v{ "" };
    std::ostringstream os;
    os << v;
    EXPECT_EQ( os.str(), "" );
}

TEST( TestExp, TestVariableName ) {
    Variable v{ "x" };
    std::ostringstream os;
    os << v;
    EXPECT_EQ( os.str(), "x" );
}

TEST( TestExp, TestDeriveVariable ) {
    Variable v{ "x" };
    Expression* deriv = v.derive("x");
    std::ostringstream os;
    os << *deriv;
    EXPECT_EQ( os.str(), "1" );
}

TEST( TestExp, TestDeriveOtherVariable ) {
    Variable v{ "a" };
    Expression* deriv = v.derive("x");
    std::ostringstream os;
    os << *deriv;
    EXPECT_EQ( os.str(), "0" );
}


TEST( TestExp, TestDeriveNombre ) {
    Nombre n{ 1 };
    Expression* deriv = n.derive("x");
    std::ostringstream os;
    os << *deriv;
    EXPECT_EQ( os.str(), "0" );
}

TEST( TestExp, TestAddExp ) {
    int init_nb_instance = Expression::nb_inst;
    Variable* v = new Variable{ "x" };
    Nombre* n = new Nombre{ 1 };
    Expression* derive = v->derive( "x" );
    std::ostringstream os;
    os << derive->nb_inst;
    EXPECT_EQ( os.str(), std::to_string(init_nb_instance + 3));
}

TEST( TestExp, TestDestructExp ) {
    int init_nb_instance = Expression::nb_inst;
    Variable* v = new Variable{ "x" };
    Nombre* n = new Nombre{ 1 };
    Expression* derive = v->derive( "x" );
    std::ostringstream os;
    delete v;
    delete n;
    os << derive->nb_inst;
    EXPECT_EQ( os.str(), std::to_string(init_nb_instance + 1));
}

