#include <iostream>
#include <random>

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


void PrintAllKeys(InfInt myNumber, const InfInt &maxKey) {
    for (; myNumber != maxKey; myNumber++)
        std::cout << ConvertToHex(myNumber) << std::endl;
}


bool BruteForceKey(const InfInt &myKey, const InfInt &maxKey) {
    for (InfInt forceValue = 0; forceValue != maxKey; forceValue++)
        if (forceValue == myKey)
            return true;

    return false;
}


InfInt Pow(int number, int toPow) {
   InfInt result = "1";

   for(; toPow != 0; toPow -= 1)
       result *= number;

    return result;
}


InfInt GenerateRandomKey(const InfInt &bitsAmount) {
    InfInt result;
    InfInt maxValue;

    try {
        maxValue = bitsAmount.toUnsignedLongLong();
    } catch (const std::overflow_error& err) {
        maxValue = ULLONG_MAX;
    }

    std::random_device rd;

    std::default_random_engine generator(rd());

    std::uniform_int_distribution<long long unsigned> distribution(0, maxValue.toUnsignedLongLong());

    result = distribution(generator);

    return result;
}


int main() {
    InfInt myNumber = "0";

    InfInt maxBits8 = Pow(BASE_2, 8) - 1;
    InfInt maxBits16 = Pow(BASE_2, 16) - 1;
    InfInt maxBits32 = Pow(BASE_2, 32) - 1;
    InfInt maxBits64 = Pow(BASE_2, 64) - 1;
    InfInt maxBits128 = Pow(BASE_2, 128) - 1;
    InfInt maxBits256 = Pow(BASE_2, 256) - 1;
    InfInt maxBits512 = Pow(BASE_2, 512) - 1;
    InfInt maxBits1024 = Pow(BASE_2, 1024) - 1;
    InfInt maxBits2048 = Pow(BASE_2, 2048) - 1;
    InfInt maxBits4096 = Pow(BASE_2, 4096) - 1;

    auto *timer1 = new CTimer("Counting max value of each bit");
    std::cout << "::::COUNT MAX VALUE OF EACH BEAT::::" << std::endl;
    std::cout << "--8 bits DEC:: "  << maxBits8 << " ||HEX::  " << ConvertToHex(maxBits8) << std::endl;
    std::cout << "--16 bits DEC:: "  << maxBits16 << " ||HEX::  " << ConvertToHex(maxBits16)  << std::endl;
    std::cout << "--32 bits DEC:: "  << maxBits32 << "||HEX:: " << ConvertToHex(maxBits32) << std::endl;
    std::cout << "--64 bits DEC:: "  << maxBits64  << "||HEX:: " << ConvertToHex(maxBits64) << std::endl;
    std::cout << "--128 bits DEC:: "  << maxBits128  << "||HEX:: " << ConvertToHex(maxBits128) << std::endl;
    std::cout << "--256 bits DEC:: "  << maxBits256  << "||HEX:: " << ConvertToHex(maxBits256) << std::endl;
    std::cout << "--512 bits DEC:: "  << maxBits512  << "||HEX:: " << ConvertToHex(maxBits512) << std::endl;
    std::cout << "--1024 bits DEC:: "  << maxBits1024  << "||HEX:: " << ConvertToHex(maxBits1024) << std::endl;
    std::cout << "--2048 bits DEC:: "  << maxBits2048  << "||HEX:: " << ConvertToHex(maxBits2048) << std::endl;
    std::cout << "--4096 bits DEC:: "  << maxBits4096  << "||HEX:: " << ConvertToHex(maxBits4096) << std::endl;
    delete timer1;

    InfInt generated8 = GenerateRandomKey(maxBits8);
    InfInt generated16 = GenerateRandomKey(maxBits16);
    InfInt generated32 = GenerateRandomKey(maxBits32);
    InfInt generated64 = GenerateRandomKey(maxBits64);
    InfInt generated128 = GenerateRandomKey(maxBits128);
    InfInt generated256 = GenerateRandomKey(maxBits256);
    InfInt generated512 = GenerateRandomKey(maxBits512);
    InfInt generated1024 = GenerateRandomKey(maxBits1024);
    InfInt generated2048 = GenerateRandomKey(maxBits2048);
    InfInt generated4096 = GenerateRandomKey(maxBits4096);

    std::cout << std::endl << "GENERATE RANDOM VALUE FOR EACH BIT" << std::endl;
    std::cout << "--8 bits DEC:: "  << generated8 << " ||HEX::  " << ConvertToHex(generated8) << std::endl;
    std::cout << "--16 bits DEC:: "  << generated16 << " ||HEX::  " << ConvertToHex(generated16) << std::endl;
    std::cout << "--32 bits DEC:: "  << generated32 << " ||HEX::  " << ConvertToHex(generated32) << std::endl;
    std::cout << "--64 bits DEC:: "  << generated64 << " ||HEX::  " << ConvertToHex(generated64) << std::endl;
    std::cout << "--128 bits DEC:: "  << generated128 << " ||HEX::  " << ConvertToHex(generated128) << std::endl;
    std::cout << "--256 bits DEC:: "  << generated256 << " ||HEX::  " << ConvertToHex(generated256) << std::endl;
    std::cout << "--512 bits DEC:: "  << generated512 << " ||HEX::  " << ConvertToHex(generated512) << std::endl;
    std::cout << "--1024 bits DEC:: "  << generated1024 << " ||HEX::  " << ConvertToHex(generated1024) << std::endl;
    std::cout << "--2048 bits DEC:: "  << generated2048 << " ||HEX::  " << ConvertToHex(generated2048) << std::endl;
    std::cout << "--4096 bits DEC:: "  << generated4096 << " ||HEX::  " << ConvertToHex(generated4096) << std::endl;

    std::cout << std::endl << "BRUTE FORCE THE KEY: " << std::endl;

    auto *timerForce8 = new CTimer("--brute force 8 bits");
    std::cout << "--brute force 8 bits begun--" << std::endl;
    BruteForceKey(generated8, maxBits8);
    delete timerForce8;

    auto *timerForce16 = new CTimer("--brute force 16 bits");
    std::cout << "--brute force 8 bits begun--" << std::endl;
    BruteForceKey(generated16, maxBits16);
    delete timerForce16;

    auto *timerForce32 = new CTimer("--brute force 32 bits");
    std::cout << "--brute force 32 bits begun--" << std::endl;
    BruteForceKey(generated32, maxBits32);
    delete timerForce32;

    auto *timerForce64 = new CTimer("--brute force 64 bits");
    std::cout << "--brute force 64 bits begun--" << std::endl;
    BruteForceKey(generated64, maxBits64);
    delete timerForce64;

    auto *timerForce128 = new CTimer("--brute force 128 bits");
    std::cout << "--brute force 128 bits begun--" << std::endl;
    BruteForceKey(generated128, maxBits128);
    delete timerForce128;

    auto *timerForce256 = new CTimer("--brute force 256 bits");
    std::cout << "--brute force 256 bits begun--" << std::endl;
    BruteForceKey(generated256, maxBits256);
    delete timerForce256;

    auto *timerForce512 = new CTimer("--brute force 512 bits");
    std::cout << "--brute force 512 bits begun--" << std::endl;
    BruteForceKey(generated512, maxBits512);
    delete timerForce512;

    auto *timerForce1024 = new CTimer("--brute force 1024 bits");
    std::cout << "--brute force 1024 bits begun--" << std::endl;
    BruteForceKey(generated1024, maxBits1024);
    delete timerForce1024;

    auto *timerForce2048 = new CTimer("--brute force 2048 bits");
    std::cout << "--brute force 2048 bits begun--" << std::endl;
    BruteForceKey(generated2048, maxBits2048);
    delete timerForce2048;

    auto *timerForce4096 = new CTimer("--brute force 4096 bits");
    std::cout << "--brute force 4096 bits begun--" << std::endl;
    BruteForceKey(generated4096, maxBits4096);
    delete timerForce4096;

    return 0;
}
