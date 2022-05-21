#include <iostream>

#include "InfInt.h"

const int BASE_2 = 2;


std::string ConvertToHex(InfInt myNum) {
    std::string hexStr;
    std::string resultHex;

    while (true)
    {
        if (myNum == 0)
            break;

        std::stringstream stream;

        stream << std::hex << myNum%16;
        myNum /= 16;

        hexStr += stream.str();
    }

    std::transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);
    std::reverse(hexStr.begin(), hexStr.end());

    return hexStr;
}


void PrintAllKeys(InfInt myNumber, const int maxKey) {
    for (; myNumber != maxKey; myNumber++)
        std::cout << ConvertToHex(myNumber) << std::endl;
}


InfInt Pow(int number, int toPow) {
   InfInt result = "1";

   for(; toPow != 0; toPow -= 1)
       result *= number;

    return result;
}


int main() {
    InfInt myNumber = "0";


    std::cout << "--8 bits DEC:: "  << Pow(BASE_2, 8)-1 << " ||HEX::  " << ConvertToHex(Pow(BASE_2, 8)-1) << std::endl;
    std::cout << "--16 bits DEC:: "  << Pow(BASE_2, 16)-1 << " ||HEX::  " << ConvertToHex(Pow(BASE_2, 16)-1)  << std::endl;
    std::cout << "--32 bits DEC:: "  << Pow(BASE_2, 32)-1 << "||HEX:: " << ConvertToHex(Pow(BASE_2, 32)-1) << std::endl;
    std::cout << "--64 bits DEC:: "  << Pow(BASE_2, 64)-1  << "||HEX:: " << ConvertToHex(Pow(BASE_2, 64)-1) << std::endl;


//    PrintAllKeys(myNumber, 8);

    return 0;
}
