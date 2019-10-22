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
#include <initializer_list>
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

    static std::string unCapitalize(const std::string& str) {
        std::string ret(str);
        ret[0] = ::tolower(ret[0]);
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

    static std::string strip(const std::string& source) {
        std::string str(source);
        return trim(trim(trim(trim(str, " "), "\t"), "\r"), "\n");
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

    static bool starts_with(const std::string &src, const std::string& starting) {
        return src.length() >= starting.length() ? (0 == src.compare(0, starting.length(), starting)) : false;
    }

    static bool ends_with(const std::string& src, const std::string& ending) {
        return src.length() >= ending.length() ? (0 == src.compare(src.length() - ending.length(), ending.length(), ending)) : false;
    }

    static std::vector<std::string> split(const std::string& source, const std::string& delim) {
        // not good approach -> use template like boost
        size_t pos_start = 0, pos_end, delim_len = delim.length();
        std::vector<std::string> res;

        while ((pos_end = source.find(delim, pos_start)) != std::string::npos) {
            std::string token = source.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(source.substr(pos_start));
        return res;
    }

    static std::string join(const std::vector<std::string>& splited_string, const std::string& delim) {
        if (splited_string.empty()) {
            return "";
        }

        typename std::vector<std::string>::const_iterator const_it = splited_string.begin();
        std::string ret = *const_it++;
        for (; const_it != splited_string.end(); ++const_it) {
            ret += delim;
            ret += *const_it;
        }
        return ret;
    }

    static bool contains(const std::string& src, const std::string& sub) {
        return src.empty() ? false : src.find(sub) != std::string::npos;
    }

    static std::string replace_all_copy(const std::string& str, const std::string& from, const std::string& to) {
        std::string ret(str);
        size_t start_pos = 0;
        while ((start_pos = ret.find(from, start_pos)) != std::string::npos) {
            ret.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return ret;
    }

public:
    StringUtil() = default;
    virtual ~StringUtil() = default;
};

} /* namespace fpstr */

#endif /* STRINGUTIL_HPP_ */
