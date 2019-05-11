// Name   : StringProcess.hpp
// Author : Modnar
// Date   : 2019-05-11

#ifndef STRING_PROCESS_HPP
#define STRING_PROCESS_HPP

#include <string>
#include <vector>

extern std::vector<std::string> split(const std::string &, 
        const std::string &delim = " ");

extern std::string &trim(std::string &);

#endif /* STRING_PROCESS_HPP */
