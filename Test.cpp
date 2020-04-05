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
 T1.addFather("a","b");


// T1.addFather("b","c");
// T1.addFather("c","d");
// T1.addFather("d","e");
//
//
// T1.addMother("a","bb");
// T1.addMother("bb","cc");
// T1.addMother("cc","dd");
// T1.addMother("dd","ee");

TEST_CASE("")
{

    //
    // CHECK(T1.relation("b") == string("father"));
    // CHECK(T1.relation("a") == string("self"));
    // CHECK(T1.relation("wooooooooooof") == string("unrelated"));
    // CHECK(T1.relation("") == string("unrelated"));
    // CHECK(T1.relation("c") == string("grandfather"));
    // CHECK(T1.relation("d") == string("great-grandfather"));
    // CHECK(T1.relation("e") == string("great-great-grandfather"));
    //
    //
    // CHECK(T1.relation("b") == string("mother"));
    // CHECK(T1.relation("a") == string("self"));
    // CHECK(T1.relation("wooooooooooffffof") == string("unrelated"));
    // CHECK(T1.relation("itzik") == string("unrelated"));
    // CHECK(T1.relation("cc") == string("grandmother"));
    // CHECK(T1.relation("dd") == string("great-grandmother"));
    // CHECK(T1.relation("ee") == string("great-great-grandmother"));

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
