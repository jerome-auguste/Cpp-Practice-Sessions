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

int main( int argc, char * argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
