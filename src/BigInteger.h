//
// Created by Matthew Paletta on 2018-12-31.
//

#ifndef PROJECT_BIGFLOAT_H
#define PROJECT_BIGFLOAT_H

#pragma once

#include <vector>
#include <string>

class BigInteger {
private:
    static const int NUMBASE = 10;

    bool isPositive;
    std::vector<int> repr;

    BigInteger(std::vector<int> val, bool isPositive);
    bool operator>=(std::vector<int> b) const;
    BigInteger add(BigInteger b, bool isPositive);
    BigInteger sub(BigInteger b, bool isPositive);

    // Helper function used to turn number into integer
    struct parse {
        template <class T>
        std::vector<int> operator()(T current_val) {
            return parse()(current_val, {});
        }

        template <class T>
        std::vector<int> operator()(T current_val, std::vector<int> acc) {
            if (current_val == 0) {
                // Once we reach 0, we stop
                return acc;
            } else {
                // We compute the next digit, it will always be < 10
                int digit = (int) current_val % NUMBASE;
                current_val /= NUMBASE;

                // Once we have already added to tail, we add the head
                acc.push_back(digit);

                return parse()(current_val);
            }
        }
    };

public:
    BigInteger(std::string val);
    BigInteger(int val);
    BigInteger(short int val);
    BigInteger(unsigned short int val);
    BigInteger(unsigned int val);
    BigInteger(long int val);
    BigInteger(unsigned long int val);
    BigInteger(long long int val);
    BigInteger(unsigned long long int val);

    std::string string() const;

    bool operator==(const BigInteger b) const;
    BigInteger operator+(BigInteger b);
    BigInteger operator-(BigInteger b);
    BigInteger operator*(int b);

    bool operator>=(const BigInteger b) const;

    template<typename T>
    BigInteger operator+(T b);

    virtual ~BigInteger();
};


#endif //PROJECT_BIGFLOAT_H
