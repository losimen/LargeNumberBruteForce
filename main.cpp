#include <iostream>

#include "InfInt.h"
#include "CTimer.h"

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

    InfInt bits8 = Pow(BASE_2, 8)-1;
    InfInt bits16 = Pow(BASE_2, 16)-1;
    InfInt bits32 = Pow(BASE_2, 32)-1;
    InfInt bits64 = Pow(BASE_2, 64)-1;
    InfInt bits128 = Pow(BASE_2, 128)-1;
    InfInt bits256 = Pow(BASE_2, 256)-1;
    InfInt bits512 = Pow(BASE_2, 512)-1;
    InfInt bits1024 = Pow(BASE_2, 1024)-1;
    InfInt bits2048 = Pow(BASE_2, 2048)-1;
    InfInt bits4096 = Pow(BASE_2, 4096)-1;

    auto *timer1 = new CTimer("Counting max value of each bit");
    std::cout << "--8 bits DEC:: "  << bits8 << " ||HEX::  " << ConvertToHex(bits8) << std::endl;
    std::cout << "--16 bits DEC:: "  << bits16 << " ||HEX::  " << ConvertToHex(bits16)  << std::endl;
    std::cout << "--32 bits DEC:: "  << bits32 << "||HEX:: " << ConvertToHex(bits32) << std::endl;
    std::cout << "--64 bits DEC:: "  << bits64  << "||HEX:: " << ConvertToHex(bits64) << std::endl;
    std::cout << "--128 bits DEC:: "  << bits128  << "||HEX:: " << ConvertToHex(bits128) << std::endl;
    std::cout << "--256 bits DEC:: "  << bits256  << "||HEX:: " << ConvertToHex(bits256) << std::endl;
    std::cout << "--512 bits DEC:: "  << bits512  << "||HEX:: " << ConvertToHex(bits512) << std::endl;
    std::cout << "--1024 bits DEC:: "  << bits1024  << "||HEX:: " << ConvertToHex(bits1024) << std::endl;
    std::cout << "--2048 bits DEC:: "  << bits2048  << "||HEX:: " << ConvertToHex(bits2048) << std::endl;
    std::cout << "--4096 bits DEC:: "  << bits4096  << "||HEX:: " << ConvertToHex(bits4096) << std::endl;
    delete timer1;


//    PrintAllKeys(myNumber, 8);

    return 0;
}
