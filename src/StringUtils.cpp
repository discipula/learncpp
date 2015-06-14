#include "StringUtils.h"
#include "cstring"
#include "algorithm"

bool space(char c)
{
    return isspace(c);
}

bool notSpace(char c)
{
    return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end())
    {
        i = find_if(i, str.end(), notSpace);
        iter j = find_if(i, str.end(), space);
        if (i != str.end())
            ret.push_back(std::string(i, j));
        i = j;
    }
    return ret;
}

bool isPalindrome (const std::string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

bool notUrlChar(char c)
{
    static const std::string urlCharacters = "~;?:@=&$-_.+!\"'(),";
    return !(isalnum(c) || find(urlCharacters.begin(), urlCharacters.end(), c) != urlCharacters.end());
}

std::string::const_iterator urlBegin (std::string::const_iterator b, std::string::const_iterator e)
{

    static const std::string sep = "://";
    typedef std::string::const_iterator iter;
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e)
    {

        if (i != b && i + sep.size() != e)
        {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            if (beg != i && !notUrlChar(i[sep.size()]))
                return beg;
        }
        i += sep.size(); // not URL, advance to find next separator 
    }
    return e;
}

std::string::const_iterator urlEnd(std::string::const_iterator b, std::string::const_iterator e)
{
    return find_if(b, e, notUrlChar);
}

std::vector<std::string> findUrls(const std::string& s)
{

    std::vector<std::string> ret;

    typedef std::string::const_iterator iter;

    iter b = s.begin(), e = s.end();

    while (b != e)
    {

        b = urlBegin(b, e);

        if (b != e)
        {
            
            iter after = urlEnd(b, e);
            ret.push_back(std::string(b, after));
            b = after;
        }
    }
    return ret;
}

