// Name   : StringProcess.hpp
// Author : Modnar
// Date   : 2019-05-11

#include "StringProcess.hpp"

// Store the sub-string in vector.
std::vector<std::string> split(const std::string &str, const std::string &delim) { 
    std::vector<std::string> res;
    if("" == str) return res;
    std::string strs = str + delim; 
    size_t pos;
    size_t size = strs.size();
    for (int i = 0; i < size; ++i) {
        // pos is the position of the delimeter's first appearation, and the string
        // between i and pos is the string to be seperated.
        pos = strs.find(delim, i); 
        if(pos < size) { 
            std::string s = strs.substr(i, pos - i); 
            res.push_back(s); 
            i = pos + delim.size() - 1;
        }
    }
    return res;	
}

// Remove the space character at a string's two sides.
std::string &trim(std::string &s) {
    if (s.empty()) {
        return s;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}
