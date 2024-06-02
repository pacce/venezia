#include <gtest/gtest.h>
#include <venezia/venezia.hpp>

TEST(READ, CHAR) {
    std::string input           = "=+(){},;";
    std::string::iterator begin = input.begin();
    std::string::iterator end   = input.end();

    std::optional<char> actual  = std::nullopt;

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, '=');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, '+');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, '(');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, ')');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, '{');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, '}');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, ',');

    actual = venezia::lexer::read(begin, end);
    ASSERT_TRUE(actual);
    EXPECT_EQ(*actual, ';');

    actual = venezia::lexer::read(begin, end);
    ASSERT_FALSE(actual);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
