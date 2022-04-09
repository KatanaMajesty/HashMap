#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

namespace algorithm
{
    std::shared_ptr<std::vector<std::size_t>> rabinCarp(const std::string& str, const std::string& sub)
    {
        using Size = std::size_t;
        std::shared_ptr<std::vector<std::size_t>> vec = std::make_shared<std::vector<std::size_t>>();

        Size strLen = str.length();
        Size subLen = sub.length();
        Size strHash = 0;
        Size subHash = 0;

        unsigned int x = 7;
        unsigned int optMultiplier = std::pow(x, subLen - 1);

        for (Size i = 0; i < subLen; i++)
        {
            strHash += str[i] * std::pow(x, subLen - i - 1);
            subHash += sub[i] * std::pow(x, subLen - i - 1);
        }
        
        for (Size i = 0; i < strLen - subLen + 1; i++)
        {
            if (strHash == subHash)
            {
                bool eq = true;
                for (Size j = 0; j < subLen; j++)
                    if (sub[j] != str[j + i])
                    {
                        eq = false;
                        break;
                    }

                if (eq)
                    vec->push_back(i);
            }
            strHash = (strHash - str[i] * optMultiplier) * x + str[subLen + i];
        }

        return vec;
    };
};