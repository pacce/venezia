#include <boost/spirit/include/qi.hpp>
#include <gtest/gtest.h>
#include <venezia/venezia.hpp>

namespace qi = boost::spirit::qi;

TEST(LEX, ASSIGNMENT) {
    std::string s = "=";

    venezia::token::operation::Assignment decoded;
    venezia::lexer::assignmentp<std::string::iterator> grammar;

    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
}

TEST(LEX, PLUS) {
    std::string s = "+";

    venezia::token::operation::Plus decoded;
    venezia::lexer::plusp<std::string::iterator> grammar;

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

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
