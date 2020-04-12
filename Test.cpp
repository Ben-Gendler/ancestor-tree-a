/**
 * Test written by Ben Gendler and Roi Mash
 * last update 04.04.2020
 */
 #define CHECK DOCTEST_CHECK

 #include "FamilyTree.hpp"
 #include "doctest.h"
 #include <iostream>
 #include <stdexcept>
 using namespace std;
 using namespace family;


 // T1.addFather("b","c");
 // T1.addFather("c","d");
 // T1.addFather("d","e");
 //
 //
 // T1.addMother("a","bb");
 // T1.addMother("bb","cc");
 // T1.addMother("cc","dd");
 // T1.addMother("dd","ee");
 // T1.addFather("a","b");
 //    CHECK(T1.relation("b") == string("father"));
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
 TEST_CASE("1")
 {
     family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
 	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
 	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
 	 .addFather("Yaakov", "Isaac")
 	 .addMother("Yaakov", "Rivka")
 	 .addFather("Isaac", "Avraham")
 	 .addFather("Avraham", "Terah");

     CHECK(T.relation("Yaakov").compare("father") == 0 );
     CHECK(T.relation("Yaakov")=="father");

     CHECK(T.relation("Yaakov").compare("father") == 0 );
     CHECK(T.relation("Yaakov")=="father");




 }
