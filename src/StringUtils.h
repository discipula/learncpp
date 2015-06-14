#ifndef STRING_UTILS_GUARD
#define STRING_UTILS_GUARD 
#include "string"
#include "vector"
bool space(char c);
bool notSpace(char c);
std::vector<std::string> split (const std::string&);
bool isPalindrome(const std::string&);
bool notUrlChar(char);
std::string::const_iterator urlBegin (std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator urlEnd(std::string::const_iterator b, std::string::const_iterator e);
std::vector<std::string> findUrls(const std::string&);

#endif
