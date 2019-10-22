/*
 * StringUtil.h
 *
 *  Created on: 2019. 10. 17.
 *      Author: wschoi
 */

#ifndef STRINGUTIL_HPP_
#define STRINGUTIL_HPP_

#include <algorithm>
#include <cctype>
#include <chrono>
#include <functional>
#include <iterator>
#include <random>
#include <string>

namespace fpstr {

class StringUtil {
public:

    static std::string toUpper(const std::string& str) {
        std::string ret;
        std::transform(str.begin(), str.end(), std::back_inserter(ret), ::toupper);
        return ret;
    }

    static std::string toLower(const std::string& str) {
        std::string ret;
        std::transform(str.begin(), str.end(), std::back_inserter(ret), ::tolower);
        return ret;
    }

    static std::string capitalize(const std::string& str) {
        std::string ret(str);
        ret[0] = ::toupper(ret[0]);
        return ret;
    }

    static bool isEmpty(const std::string& str) {
        return str.empty();
    }

    static bool isNotEmpty(const std::string& str) {
        return !isEmpty(str);
    }

    static std::string trim_right(const std::string& source, const std::string& whitespaces) {
        std::string str(source);
        return str.erase(str.find_last_not_of(whitespaces) + 1);
    }

    static std::string trim_left(const std::string& source, const std::string& whitespaces) {
        std::string str(source);
        return str.erase(0, str.find_first_not_of(whitespaces));
    }

    static std::string trim(const std::string& source, const std::string& whitespaces) {
        std::string str(source);
        return trim_left(trim_right(str, whitespaces), whitespaces);
    }

    static std::string makeZeroPrependDigit(long long value, unsigned int digit) {
        std::string ret = "";
        std::string stringValue = std::to_string(value);
        for (unsigned int i = digit - stringValue.length(); i > 0; i--) {
            ret += "0";
        }
        ret += stringValue;
        return ret;
    }

    static std::string getAddressToIP(const std::string& address) {
        return substringBefore(address, ":");
    }

    static std::string getAddressToPort(const std::string& address) {
        return substringAfter(address, ":");
    }

    static bool isAlnum(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isalnum))) == str.end();
    }

    static bool isAlpha(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isalpha))) == str.end();
    }

    static bool isDigit(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isdigit))) == str.end();
    }

    static bool isLower(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::islower))) == str.end();
    }

    static bool isUpper(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isupper))) == str.end();
    }

    static bool isSpace(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun(::isspace))) == str.end();
    }

    static std::string randomString(int length) {
        static const char alphanum[] = "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        std::string s(length, ' ');
        std::mt19937 mtRand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
        for (int i = 0; i < length; ++i) {
            s[i] = alphanum[mtRand() % (sizeof(alphanum) - 1)];
        }

        s[length] = '\0';
        return s;
    }

    static std::string substringBefore(const std::string& str, const std::string& separator) {
        if (isEmpty(str) || isEmpty(separator)) {
            return str;
        }
        return str.find(separator) == std::string::npos ? str : str.substr(0, str.find(separator));
    }

    static std::string substringAfter(const std::string& str, const std::string& separator) {
        if (isEmpty(str)) {
            return str;
        }
        if (isEmpty(separator)) {
            return "";
        }
        return str.find(separator) == std::string::npos ? "" : str.substr(str.find(separator) + separator.length());
    }

    static bool start_with(std::string const &fullString, const std::string& starting) {
        return fullString.length() >= starting.length() ? (0 == fullString.compare(0, starting.length(), starting)) : false;
    }

    static bool ends_with(std::string const &fullString, const std::string& ending) {
        return fullString.length() >= ending.length() ? (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending)) : false;
    }

public:
    StringUtil() = default;
    virtual ~StringUtil() = default;
};

} /* namespace fpstr */

#endif /* STRINGUTIL_HPP_ */
