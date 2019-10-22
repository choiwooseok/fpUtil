#include <gtest/gtest.h>
#include "../src/StringUtil.hpp"

TEST(StringUtilTest, stringUtilTest) {
    using namespace fpstr;

    EXPECT_EQ(StringUtil::toUpper("asdf"), "ASDF");
    EXPECT_EQ(StringUtil::toUpper("asDF"), "ASDF");

    EXPECT_EQ(StringUtil::toLower("ASdF"), "asdf");
    EXPECT_EQ(StringUtil::toLower("ASDF"), "asdf");

    EXPECT_EQ(StringUtil::capitalize("asdf"),"Asdf");

    EXPECT_EQ(StringUtil::isEmpty(""), true);
    EXPECT_EQ(StringUtil::isEmpty("a"), false);

    EXPECT_EQ(StringUtil::isNotEmpty(""), false);
    EXPECT_EQ(StringUtil::isNotEmpty("a"), true);

    EXPECT_EQ(StringUtil::makeZeroPrependDigit(13LL, 4), "0013");

    EXPECT_EQ(StringUtil::getAddressToIP("0.0.0.0:1024"), "0.0.0.0");
    EXPECT_EQ(StringUtil::getAddressToPort("0.0.0.0:1024"), "1024");

    EXPECT_EQ(StringUtil::isAlnum("\xdf"), false);
    EXPECT_EQ(StringUtil::isAlnum("asdf"), true);

    EXPECT_EQ(StringUtil::isAlpha("asdf"), true);
    EXPECT_EQ(StringUtil::isAlpha("123a"), false);

    EXPECT_EQ(StringUtil::isDigit("1234"), true);
    EXPECT_EQ(StringUtil::isDigit("123a"), false);

    EXPECT_EQ(StringUtil::isLower("asdf"), true);
    EXPECT_EQ(StringUtil::isLower("asDf"), false);

    EXPECT_EQ(StringUtil::isUpper("ASDF"), true);
    EXPECT_EQ(StringUtil::isUpper("asDf"), false);

    EXPECT_EQ(StringUtil::isSpace(" "), true);
    EXPECT_EQ(StringUtil::isSpace("a"), false);

    EXPECT_EQ(StringUtil::substringBefore("zxcv", "xc"), "z");
    EXPECT_EQ(StringUtil::substringAfter("zxcv", "zx"), "cv");

    EXPECT_EQ(StringUtil::start_with("asdf", "as"), true);
    EXPECT_EQ(StringUtil::start_with("asdf", "df"), false);

    EXPECT_EQ(StringUtil::ends_with("asdf", "df"), true);
    EXPECT_EQ(StringUtil::ends_with("asdf", "as"), false);

    EXPECT_EQ(StringUtil::trim_right("  asdf  ", " "), "  asdf");
    EXPECT_EQ(StringUtil::trim_left("  asdf  ", " "), "asdf  ");
    EXPECT_EQ(StringUtil::trim("  asdf  ", " "), "asdf");

    EXPECT_EQ(StringUtil::trim_right("  asdf\n\n", "\n"), "  asdf");
    EXPECT_EQ(StringUtil::trim_left("\n\nasdf  ", "\n"), "asdf  ");
    EXPECT_EQ(StringUtil::trim("\n\nasdf\n\n", "\n"), "asdf");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
