/**
 * Test written by Ben Gendler and Roi Mash
 * last update 04.04.2020
 */

#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>
#include <string>



using namespace family;

family::Tree T1("a");


TEST_CASE("") 
{
    T1.addFather("a","b");
    CHECK(T1.relation("b") == string("father"));


}

TEST_CASE("") 
{


}

TEST_CASE("") 
{


}

TEST_CASE("") 
{


}

TEST_CASE("") 
{


}

TEST_CASE("") 
{


}
