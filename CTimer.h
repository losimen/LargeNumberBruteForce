//
//  CTimer.h
//
//  Created by Павло Коваль on 18.08.2021.
//

#ifndef LARGENUMBERS_CTIMER_H
#define LARGENUMBERS_CTIMER_H

#include <chrono>
#include <iostream>

class CTimer
{
public:
    CTimer(const std::string &name)
    {
        this->name = name;
        start = std::chrono::system_clock::now();
    }

    ~CTimer()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> time = end - start;

        std::cout << "COUNTER: " << name << "|| DURATION: " << time.count() << "s." << std::endl;
    }
private:
    std::string name;
    std::chrono::time_point<std::chrono::system_clock> start, end;
};


#endif //LARGENUMBERS_CTIMER_H
