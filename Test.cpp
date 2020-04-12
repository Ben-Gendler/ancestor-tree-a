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


    family::Tree T1("a");
    family::Tree T2("1");
    family::Tree T3("Dolev");
    family::Tree T4("Dolev");




 TEST_CASE("1")
 {

   T1.addFather("a","b");
   T1.addFather("b","c");
   T1.addFather("c","d");
   T1.addFather("d","e");
   T1.addFather("e","f");

   T1.addMother("a","bb");
   T1.addMother("bb","cc");
   T1.addMother("cc","dd");
   T1.addMother("dd","ee");
   T1.addMother("ee","ff");

   CHECK(T1.relation("b") == string("father"));
   CHECK(T1.relation("c") == string("grandfather"));
   CHECK(T1.relation("d") == string("great-grandfather"));
   CHECK(T1.relation("e") == string("great-great-grandfather"));
   CHECK(T1.relation("f") == string("great-great-great-grandfather"));

   CHECK(T1.relation("bb") == string("mother"));
   CHECK(T1.relation("cc") == string("grandmother"));
   CHECK(T1.relation("dd") == string("great-grandmother"));
   CHECK(T1.relation("ee") == string("great-great-grandmother"));
   CHECK(T1.relation("ff") == string("great-great-great-grandmother"));


   CHECK(T1.find("father") == string("b"));
   CHECK(T1.find("grandfather") == string("c"));
   CHECK(T1.find("great-grandfather") == string("d"));
   CHECK(T1.find("great-great-grandfather") == string("e"));
   CHECK(T1.find("great-great-great-grandfather") == string("f"));

   CHECK(T1.find("mother") == string("bb"));
   // CHECK(T1.find("grandmother") == string("cc"));
   CHECK(T1.find("great-grandmother") == string("dd"));
   CHECK(T1.find("great-great-grandmother") == string("ee"));
   CHECK(T1.find("great-great-great-grandmother") == string("ff"));

   CHECK(T1.find("me") == string("a"));


 }

 TEST_CASE("2")
 {
 T2.addFather("1","2");
 T2.addFather("2","3");
 T2.addFather("3","4");
 T2.addFather("4","5");
 T2.addFather("5","6");

 T2.addMother("1","22");
 T2.addMother("22","33");
 T2.addMother("33","44");
 T2.addMother("44","55");
 T2.addMother("55","66");

 CHECK(T2.relation("2") == string("father"));
 CHECK(T2.relation("3") == string("grandfather"));
 CHECK(T2.relation("4") == string("great-grandfather"));
 CHECK(T2.relation("5") == string("great-great-grandfather"));
 CHECK(T2.relation("6") == string("great-great-great-grandfather"));

 CHECK(T2.relation("22") == string("mother"));
 CHECK(T2.relation("33") == string("grandmother"));
 CHECK(T2.relation("44") == string("great-grandmother"));
 CHECK(T2.relation("55") == string("great-great-grandmother"));
 CHECK(T2.relation("66") == string("great-great-great-grandmother"));


 CHECK(T2.find("father") == string("2"));
 CHECK(T2.find("grandfather") == string("3"));
 CHECK(T2.find("great-grandfather") == string("4"));
 CHECK(T2.find("great-great-grandfather") == string("5"));
 CHECK(T2.find("great-great-great-grandfather") == string("6"));

 CHECK(T2.find("mother") == string("22"));
 // CHECK(T1.find("grandmother") == string("33"));
 CHECK(T2.find("great-grandmother") == string("44"));
 CHECK(T2.find("great-great-grandmother") == string("55"));
 CHECK(T2.find("great-great-great-grandmother") == string("66"));

 CHECK(T2.find("me") == string("1"));

}
TEST_CASE("Family A")
{

  T3.addFather("Dolev", "Ron")
   .addMother("Dolev", "Meitar")
   .addFather("Ron", "Aviv")
   .addMother("Ron", "Inbal")
   .addFather("Meitar", "Roni")
   .addMother("Meitar", "Tal")
   .addFather("Aviv" , "Haim")
   .addMother("Aviv", "Eden")
   .addFather("Inbal", "Liran")
   .addMother("Inbal", "Nofar")
   .addFather("Roni", "Maor")
   .addMother("Roni", "Lina")
   .addFather("Tal" , "Gal")
   .addMother("Tal", "Shir");

    CHECK(T3.relation("Ron") == string("father"));
    CHECK(T3.relation("Aviv") == string("grandfather"));
    CHECK(T3.relation("Roni") == string("grandfather"));
    CHECK(T3.relation("Haim") == string("great-grandfather"));
    CHECK(T3.relation("Liran") == string("great-grandfather"));
    // CHECK(T3.relation("Maor" == string("great-grandfather"));
    CHECK(T3.relation("Gal") == string("great-grandfather"));

    CHECK(T3.relation("Meitar") == string("mother"));
    CHECK(T3.relation("Tal") == string("grandmother"));
    CHECK(T3.relation("Inbal") == string("grandmother"));
    CHECK(T3.relation("Nofar") == string("great-grandmother"));
    CHECK(T3.relation("Lina") == string("great-grandmother"));
    // CHECK(T3.relation("Eden" == string("great-grandmother"));
    CHECK(T3.relation("Shir") == string("great-grandmother"));

    CHECK_THROWS(T3.addFather("Meitar", "Amnon"));
    CHECK_THROWS(T3.addMother("Inbal", "Rina"));

    CHECK(T3.find("father") == string("Ron"));
    // CHECK((T3.find("grandfather") == string("Aviv")) || (T3.find("grandfather") == string("Roni")));
    // CHECK((T3.find("great-grandfather") == string("Haim")) || ((T3.find("grandfather") == string("Liran"))
    // || ((T3.find("grandfather") == string("Maor")) || ((T3.find("grandfather") == string("Gal")));

    CHECK(T3.find("mother") == string("Meitar"));
    // CHECK((T3.find("grandmother") == string("Tal")) || (T3.find("grandmother") == string("Inbal")));
    // CHECK({T3.find("great-grandmother") == string("Shir")) || (T3.find("grandmother") == string("Lina"))
    // || (T3.find("grandmother") == string("Nofar")) || (T3.find("grandmother") == string("Eden")));


    CHECK(T3.find("me") == string("Dolev"));
    CHECK_THROWS(T3.find("great-great-grandfather"));
    CHECK_THROWS(T3.find("great-great-great-grandmother"));

    T3.remove("Tal");
    CHECK(T3.relation("Tal") == string("unrelated"));
    CHECK(T3.relation("Gal") == string("unrelated"));
    CHECK(T3.relation("Shir") == string("unrelated"));

    T3.remove("Ron");
    CHECK(T3.relation("Ron") == string("unrelated"));
    CHECK(T3.relation("Aviv") == string("unrelated"));
    CHECK(T3.relation("Inbal") == string("unrelated"));
    CHECK(T3.relation("Haim") == string("unrelated"));
    CHECK(T3.relation("Eden") == string("unrelated"));
    CHECK(T3.relation("Liran") == string("unrelated"));
    CHECK(T3.relation("Nofar") == string("unrelated"));
    CHECK_THROWS(T3.find("grandmother"));
    CHECK_THROWS(T3.find("great-grandfather"));
    CHECK_THROWS(T3.find("great-grandmother"));


}

TEST_CASE("Family B")
{

  T4.addFather("Dolev", "Ron")
	  .addFather("Ron", "Aviv")
	  .addFather("Aviv", "Roni")
	  .addFather("Roni", "Haim")
	  .addFather("Haim", "Shlomi")
	  .addFather("Shlomi", "Tal")

    .addMother("Ron", "Meitar")
    .addMother("Meitar", "Inbal")
	  .addMother("Inbal", "Eden")
	  .addMother("Eden", "Shir")
	  .addMother("Shir", "Nofar")
	  .addMother("Nofar", "Lior");

    CHECK(T4.relation("Ron") == string("father"));
    CHECK(T4.relation("Aviv") == string("grandfather"));
    CHECK(T4.relation("Roni") == string("great-grandfather"));
    CHECK(T4.relation("Haim") == string("great-great-grandfather"));
    CHECK(T4.relation("Shlomi") == string("great-great-great-grandfather"));
    CHECK(T4.relation("Tal") == string("great-great-great-great-grandfather"));

    CHECK(T4.relation("Meitar") == string("grandmother"));
    CHECK(T4.relation("Inbal") == string("great-grandmother"));
    CHECK(T4.relation("Eden") == string("great-grandmother"));
    CHECK(T4.relation("Shir") == string("great-great-great-grandmother"));
    CHECK(T4.relation("Nofar") == string("great-great-great-great-grandmother"));
    CHECK(T4.relation("Lior") == string("great-great-great-great-great-grandmother"));

    CHECK(T4.find("father") == string("Ron"));
    CHECK(T4.find("grandfather") == string("Aviv"));
    CHECK(T4.find("great-grandfather") == string("Roni"));
    CHECK(T4.find("great-great-grandfather") == string("Haim"));
    CHECK(T4.find("great-great-great-grandfather") == string("Shlomi"));
    CHECK(T4.find("great-great-great-great-grandfather") == string("Tal"));

    CHECK(T4.find("grandmother") == string("Meitar"));
    CHECK(T4.find("great-grandmother") == string("Inbal"));
    CHECK(T4.find("great-great-grandmother") == string("Eden"));
    CHECK(T4.find("great-great-great-grandmother") == string("Shir"));
    CHECK(T4.find("great-great-great-great-grandmother") == string("Nofar"));
    CHECK(T4.find("great-great-great-great-great-grandmother") == string("Lior"));

    T3.remove("Aviv");
    CHECK(T3.relation("Meitar") != string("unrelated"));
    CHECK(T3.relation("Lior") != string("unrelated"));
    CHECK(T3.relation("Nofar") != string("unrelated"));
    CHECK(T3.relation("Roni") == string("unrelated"));
    CHECK(T3.relation("Aviv") == string("unrelated"));

    T3.remove("Ron");
    CHECK(T3.relation("Meitar") == string("unrelated"));
    CHECK(T3.relation("Lior") == string("unrelated"));
    CHECK(T3.relation("Nofar") == string("unrelated"));
    CHECK(T3.relation("Tal") == string("unrelated"));
    CHECK(T3.relation("Shlomi") == string("unrelated"));
    CHECK(T3.relation("Haim") == string("unrelated"));
}
