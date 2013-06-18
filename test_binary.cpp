/*

    test_binary.cpp

    Test cases for cpp-generic-serialize
*/

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <utility>

#include "binary.hpp"

namespace usb = util::serialize::binary;

template<typename T>
void test1(std::string fn, const T & t) {

    /* save */
    std::ofstream   os(fn, std::ios::out | std::ios::binary);
    usb::save(os, t);
    os.close();
    
    /* load */
    T t_in;
    std::ifstream   is(fn, std::ios::in | std::ios::binary);
    usb::load(is, t_in);
    is.close();

    /* assert */
    assert(t_in == t);
}

template<typename T>
void test2(std::string fn, const T & t) {

    /* save */
    std::ofstream   os(fn, std::ios::out | std::ios::binary);
    usb::save(os, t);
    os.close();
    
    /* load */
    std::ifstream   is(fn, std::ios::in | std::ios::binary);
    auto t_in = usb::load<T>(is);
    is.close();

    /* assert */
    assert(t_in == t);
}

int main() {
    std::list<int>  l = {1,2,3};
    // int l = 5;
    int s = 8;
    // std::string     s("foobar");
    auto pair = std::make_pair(s, l);
    test1("int.bin",         int                                         { -5 }                                                  );
    test1("string.bin",      std::string                                 {"foobarbaz"}                                           );
    test1("map_1.bin",       std::map<std::string, unsigned>             {{"foo", 1}, {"bar", 2}}                                );
    test1("list_1.bin",      std::list<unsigned int>                     { 1, 2, 3, 4, 5, 6, 7, 8, 9 }                           );
    test1("list_map_1.bin",  std::list<std::map<std::string, unsigned>>  {{{"foo", 1}, {"bar", 2}}, {{"baz", 1}, {"quux", 2}}}   );
    // test("pair.bin",        pair                                     );
    
    test2("int.bin",         int                                         { -5 }                                                  );
    test2("string.bin",      std::string                                 {"foobarbaz"}                                           );
    test2("map_1.bin",       std::map<std::string, unsigned>             {{"foo", 1}, {"bar", 2}}                                );
    test2("list_1.bin",      std::list<unsigned int>                     { 1, 2, 3, 4, 5, 6, 7, 8, 9 }                           );
    test2("list_map_1.bin",  std::list<std::map<std::string, unsigned>>  {{{"foo", 1}, {"bar", 2}}, {{"baz", 1}, {"quux", 2}}}   );
    // test("pair.bin",        pair                                     );
    
    std::cout << "All tests run successful." << std::endl;
    return 0;
}