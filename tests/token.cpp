#include <gtest/gtest.h>
#include <venezia/venezia.hpp>

TEST(OPERATION, ASSIGNMENT) {
    std::string s = "=";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_assignment{}, tokens.at(0)));
}

TEST(OPERATION, PLUS) {
    std::string s = "+";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_plus{}, tokens.at(0)));
}

TEST(DELIMITER, COMMA) {
    std::string s = ",";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_comma{}, tokens.at(0)));
}

TEST(DELIMITER, SEMICOLON) {
    std::string s = ";";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_semicolon{}, tokens.at(0)));
}

TEST(PARENTHESES, LEFT) {
    std::string s = "(";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_left{}, tokens.at(0)));
    EXPECT_TRUE(std::visit(venezia::token::is_parentheses{}, tokens.at(0)));
}

TEST(PARENTHESES, RIGHT) {
    std::string s = ")";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_right{}, tokens.at(0)));
    EXPECT_TRUE(std::visit(venezia::token::is_parentheses{}, tokens.at(0)));
}

TEST(BRACE, LEFT) {
    std::string s = "{";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_left{}, tokens.at(0)));
    EXPECT_TRUE(std::visit(venezia::token::is_brace{}, tokens.at(0)));
}

TEST(BRACE, RIGHT) {
    std::string s = "}";

    venezia::Lexer lexer;
    std::vector<venezia::Token> tokens = lexer(s.begin(), s.end());

    ASSERT_EQ(tokens.size(), 2);
    EXPECT_TRUE(std::visit(venezia::token::is_right{}, tokens.at(0)));
    EXPECT_TRUE(std::visit(venezia::token::is_brace{}, tokens.at(0)));
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
