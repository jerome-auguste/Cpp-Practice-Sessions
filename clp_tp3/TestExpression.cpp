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
#include "Multiplication.cpp"

 
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

TEST( TestExp, TestNomClone )
{
    Nombre n{ 1 };
    Expression* copy = n.clone();
    std::ostringstream os;
    os << *copy;
    EXPECT_EQ( os.str(), "1" );
}

TEST( TestExp, TestVarClone )
{
    Variable v{ "x" };
    Expression* copy = v.clone();
    std::ostringstream os;
    os << *copy;
    EXPECT_EQ( os.str(), "x" );
}


TEST( TestOp, TestAddVarNom ) {
    Variable v{ "x" };
    Nombre n{ 1 };
    Addition add{&v, &n};
    std::ostringstream os;
    os << add;
    EXPECT_EQ( os.str(), "x+1" );
}

TEST( TestOp, TestAddVarVar ) {
    Variable v1{ "x" };
    Variable v2{ "y" };
    Addition add{&v1, &v2};
    std::ostringstream os;
    os << add;
    EXPECT_EQ( os.str(), "x+y" );
}

TEST( TestOp, TestAddDerive) {
    Variable v{ "x" };
    Nombre n{ 2 };
    Addition add{ &v, &n };
    Expression* derive = add.derive("x");
    std::ostringstream os;
    os << *derive;
    EXPECT_EQ( os.str(), "1+0");
}

TEST( TestOp, TestAddDeriveConst) {
    Variable v1{ "x" };
    Variable v2{ "y" };
    Addition add{ &v1, &v2 };
    Expression* derive = add.derive("z");
    std::ostringstream os;
    os << *derive;
    EXPECT_EQ( os.str(), "0+0");
}

TEST( TestOp, TestAddClone ) {
    Addition add{ new Variable{ "x" }, new Nombre{ 2 } };
    Expression* copy = add.clone();
    std::ostringstream os;
    os << *copy;
    EXPECT_EQ( os.str(), "x+2" );
}

TEST( TestOp, TestMultVarNom ) {
    Multiplication mult{ new Nombre{ 2 }, new Variable{ "x" } };
    std::ostringstream os;
    os << mult;
    EXPECT_EQ( os.str(), "2*x" );
}

TEST( TestOp, TestMulClone ) {
    Multiplication mult{ new Nombre{ 3 }, new Variable{ "x" } };
    Expression* copy = mult.clone();
    std::ostringstream os;
    os << *copy;
    EXPECT_EQ( os.str(), "3*x" );
}

TEST( TestOp, TestMultDerive ) {
    Multiplication mult{ new Nombre{ 4 }, new Variable{ "x" } };
    Expression* deriv = mult.derive("x");
    std::ostringstream os;
    os << *deriv;
    EXPECT_EQ( os.str(), "0*x+1*4" );
}

TEST( TestOp, TestMulDeriveConst ) {
    Multiplication mult{ new Nombre{ 5 }, new Variable{ "x" } };
    Expression* deriv = mult.derive("y");
    std::ostringstream os;
    os << *deriv;
    EXPECT_EQ( os.str(), "0*x+0*5" );
}
