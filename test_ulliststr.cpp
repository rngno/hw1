#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;
    
    // push three items 
    std::cout << "Start 3 item push_back" << std::endl;
    list.push_back("7");
    list.push_back("2");
    list.push_back("5");
    list.push_front("3");
    list.push_front("4");
    list.push_front("9");
    std::cout << "Finished 3 item push_back test" << std::endl;

    // pop 2 items back
    std::cout << "Start 2 pop_back test" <<  std::endl;
    list.pop_back();
    list.pop_back();
    std::cout << "Finished 2 pop_back test" << std::endl;

    // front and back tests
    std::cout << "Front and back tests" << std::endl;
    list.front();
    list.back();
    std::cout << "Finished front and back test" << std::endl;

    // getValAtLoc test
    std::cout << "Start getValAtLoc test" << std::endl;
    list.get(3);
    list.get(57);
    std::cout << "Finished getValAtLoc test" << std::endl;


    return 0;
}
