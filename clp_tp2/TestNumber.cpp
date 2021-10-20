/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Concepts des langages de programmation - TP n°2
 *
 * TestNumber.cpp
 * c++ -std=c++20 -o TestNumber Number.cpp TestNumber.cpp -lgtest
 */

#include <exception>
#include <sstream>
#include <utility>

#include <gtest/gtest.h>

#include "Number.hpp"

 
TEST( TestNumber, TestNumber0 )
{
    Number n{ 0 };
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "0" );
}
 
TEST( TestNumber, TestNumber12345678 )
{
    Number n{ 12345678 };
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "12345678" );
}
 
TEST( TestNumber, TestNumberBig )
{
    Number n{ 12345123451234512345UL };
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "12345123451234512345" );
}

TEST( TestNumber, TestCopy ) {
    Number n1{ 1111UL };
    Number n2 = n1;
    std::ostringstream os1;
    os1 << n1;
    EXPECT_EQ( os1.str(), "1111" );
    std::ostringstream os2;
    os2 << n2;
    EXPECT_EQ( os2.str(), "1111" );
}

TEST( TestNumber, TestAssignment ) {
    Number n1{ 1111UL };
    Number n2{ 2222UL };
    n2 = n1;
    std::ostringstream os1;
    os1 << n1;
    EXPECT_EQ( os1.str(), "1111" );
    std::ostringstream os2;
    os2 << n2;
    EXPECT_EQ( os2.str(), "1111" );
}

TEST( TestNumber, TestAdd ) {
    Number n{ 9999UL };
    unsigned i = 2222;
    n.add(i);
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "12221" );
}

TEST( TestNumber, TestMultiply) {
    Number n{ 5555UL };
    unsigned int i = 2;
    n.multiply(i);
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "11110" );
}

TEST( TestNumber, TestFactorial123 )
{
    std::ostringstream os;
    Number fact = factorial( 123 );
    os << fact;
    EXPECT_EQ( os.str(), "121463043670253296757662432418812958554542170884833823153289181618292"
                         "358923621676688311569606126402021707358352212940477825910915704116514"
                         "72186029519906261646730733907419814952960000000000000000000000000000" );
}

TEST( TestNumber, TestStringConstructor )
{
    Number n{ "12345"};
    std::ostringstream os;
    os << n;
    EXPECT_EQ( os.str(), "12345");
}

TEST( TestNumber, TestRead )
{
    Number n{ "12345" };
    std::ostringstream os;
    
    std::string stringvalue = " 54321L";
    std::istringstream stringstream (stringvalue);
    stringstream>>n;
    os << n;
    EXPECT_EQ( os.str(), "54321" );

}


int main( int argc, char * argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
