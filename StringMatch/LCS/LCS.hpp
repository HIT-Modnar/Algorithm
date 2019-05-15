// Name   : LCS.hpp
// Author : Modnar
// Date   : 2019-05-15

/**
 * As we all know, the LCS algorithm could solve the problems not only for string.
 * I'll update the implementation to adapt more occasions one day.
 */

#ifndef LCS_HPP
#define LCS_HPP

#include <string>

const int MAX_SIZE = 50;

extern int LCS(const std::string &, const std::string &);

extern std::string LCS_STR(const std::string &, const std::string &, 
        bool still = false);

#endif /* LCS_HPP */
