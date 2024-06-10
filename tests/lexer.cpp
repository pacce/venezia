#include <boost/spirit/include/qi.hpp>
#include <gtest/gtest.h>
#include <venezia/venezia.hpp>

namespace qi = boost::spirit::qi;

TEST(LEX, ASSIGNMENT) {
    std::string s = "=";

    venezia::token::operation::Assignment decoded;
    venezia::lexer::operation::assignmentp<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}

TEST(LEX, PLUS) {
    std::string s = "+";

    venezia::token::operation::Plus decoded;
    venezia::lexer::operation::plusp<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}

TEST(LEX, OPERATION) {
    struct Experiment {
        std::string                 s;
        venezia::token::Operation   expected;
    };

    std::vector<Experiment> experiments {
          {"=", venezia::token::operation::Assignment{}}
        , {"+", venezia::token::operation::Plus{}}
    };

    venezia::lexer::operationp<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::token::Operation decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected.which(), decoded.which());
    }
}

TEST(LEX, COMMA) {
    std::string s = ",";

    venezia::token::delimiter::Comma decoded;
    venezia::lexer::delimiter::commap<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}

TEST(LEX, SEMICOLON) {
    std::string s = ";";

    venezia::token::delimiter::Semicolon decoded;
    venezia::lexer::delimiter::semicolonp<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}

TEST(LEX, DELIMITER) {
    struct Experiment {
        std::string                 s;
        venezia::token::Delimiter   expected;
    };

    std::vector<Experiment> experiments {
          {",", venezia::token::delimiter::Comma{}}
        , {";", venezia::token::delimiter::Semicolon{}}
    };

    venezia::lexer::delimiterp<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::token::Delimiter decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected.which(), decoded.which());
    }
}

namespace parentheses {
TEST(LEX, LEFT) {
    std::string s = "(";

    venezia::token::parentheses::Left decoded;
    venezia::lexer::parentheses::leftp<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}

TEST(LEX, RIGHT) {
    std::string s = ")";

    venezia::token::parentheses::Right decoded;
    venezia::lexer::parentheses::rightp<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}
} // namespace parentheses

TEST(LEX, PARENTHESES) {
    struct Experiment {
        std::string                 s;
        venezia::token::Parentheses expected;
    };

    std::vector<Experiment> experiments {
          {"(", venezia::token::parentheses::Left{}}
        , {")", venezia::token::parentheses::Right{}}
    };

    venezia::lexer::parenthesesp<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::token::Parentheses decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected.which(), decoded.which());
    }
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
