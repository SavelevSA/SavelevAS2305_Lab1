#include <iostream>
#include "Utils.h"

void ClearInput()
{
    std::cout << "Entered incorrect value\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //https://stackoverflow.com/questions/19469627/c-how-do-i-remove-bad-input-from-cin
}
