#include <gtest/gtest.h>
#include "../src/StringUtil.hpp"

TEST(StringUtilTest, stringUtilTest) {
    using namespace fpstr;

    EXPECT_EQ(StringUtil::toUpper("asdf"), "ASDF");

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
