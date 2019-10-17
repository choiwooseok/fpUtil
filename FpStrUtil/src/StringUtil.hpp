/*
 * StringUtil.h
 *
 *  Created on: 2019. 10. 17.
 *      Author: wschoi
 */

#ifndef STRINGUTIL_HPP_
#define STRINGUTIL_HPP_

#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <memory>
#include <iosfwd>
#include <sstream>
#include <vector>

namespace fpstr {

class StringUtil {
public:

    std::string toUpper(const std::string& str) {
        std::string ret;
        std::transform(str.begin(), str.end(), std::back_inserter(ret), ::toupper);
        return ret;
    }

    std::string toLower(const std::string& str) {
        std::string ret;
        std::transform(str.begin(), str.end(), std::back_inserter(ret), ::tolower);
        return ret;
    }

    std::string capitalize(const std::string& str) {
        std::string ret(str);
        ret[0] = ::toupper(ret[0]);
        return ret;
    }

    bool isEmpty(const std::string& str) {
        return str.empty();
    }

    bool isNotEmpty(const std::string& str) {
        return !isEmpty(str);
    }

    std::string trim_right(const std::string& source, const std::string& whitespaces) {
        std::string str(source);
        return str.erase(str.find_last_not_of(whitespaces) + 1);
    }

    std::string trim_left(const std::string& source, const std::string& whitespaces) {
        std::string str(source);
        return str.erase(0, str.find_first_not_of(whitespaces));
    }

    std::string trim(const std::string& source, const std::string& whitespaces) {
        std::string str(source);
        return trim_left(trim_right(str, whitespaces), whitespaces);
    }

    std::string makeZeroPrependDigit(long long value, unsigned int digit) {
        std::string ret = "";
        std::string stringValue = std::to_string(value);
        for (unsigned int i = digit - stringValue.length(); i > 0; i--) {
            ret += "0";
        }
        ret += stringValue;
        return ret;
    }

    std::string getAddressToIP(const std::string& address) {
        return address.find(':') < 0 ? address : address.substr(0, address.find(':'));
    }

    std::string getAddressToPort(const std::string& address) {
        return address.find(':') < 0 ? "" : address.substr(address.find(':') + 1);
    }

    bool isAlnum(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isalnum))) == str.end();
    }

    bool isAlpha(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isalpha))) == str.end();
    }

    bool isDigit(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isdigit))) == str.end();
    }

    bool isLower(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::islower))) == str.end();
    }

    bool isUpper(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isupper))) == str.end();
    }

    bool isSpace(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isspace))) == str.end();
    }

    std::string randomString(int length) {
        static const char alphanum[] = "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        std::string s(length, ' ');
        for (int i = 0; i < length; ++i) {
            s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        s[length] = '\0';
        return s;
    }

    std::string substringBefore(const std::string& str, const std::string& separator) {
        if (isEmpty(str) || separator == "") {
            return str;
        }
        if (separator.length() == 0) {
            return "";
        }
        int pos = str.find(separator);
        if (pos == -1) {
            return str;
        }
        return str.substr(0, pos);
    }

    std::string substringAfter(const std::string& str, const std::string& separator) {
        if (isEmpty(str)) {
            return str;
        }
        if (separator == "") {
            return "";
        }
        int pos = str.find(separator);
        if (pos == -1) {
            return "";
        }
        return str.substr(pos + separator.length());
    }

    bool ends_with(std::string const &fullString, std::string const &ending) {
        if (fullString.length() >= ending.length()) {
            return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
        } else {
            return false;
        }
    }

public:
    StringUtil() = default;
    virtual ~StringUtil() = default;
};

} /* namespace fpstr */

#endif /* STRINGUTIL_HPP_ */
