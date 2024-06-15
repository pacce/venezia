#include <boost/spirit/include/qi.hpp>
#include <gtest/gtest.h>
#include <ranges>
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

namespace brace {
    TEST(LEX, LEFT) {
        std::string s = "{";

        venezia::token::brace::Left decoded;
        venezia::lexer::brace::leftp<std::string::iterator> grammar;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
    }

    TEST(LEX, RIGHT) {
        std::string s = "}";

        venezia::token::brace::Right decoded;
        venezia::lexer::brace::rightp<std::string::iterator> grammar;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
    }
} // namespace brace

TEST(LEX, BRACE) {
    struct Experiment {
        std::string             s;
        venezia::token::Brace   expected;
    };

    std::vector<Experiment> experiments {
          {"{", venezia::token::brace::Left{}}
        , {"}", venezia::token::brace::Right{}}
    };

    venezia::lexer::bracep<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::token::Brace decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected.which(), decoded.which());
    }
}

namespace keyword {
    TEST(LEX, FUNCTION) {
        std::string s = "fn";

        venezia::token::keyword::Function decoded;
        venezia::lexer::keyword::functionp<std::string::iterator> grammar;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
    }

    TEST(LEX, LET) {
        std::string s = "let";

        venezia::token::keyword::Let decoded;
        venezia::lexer::keyword::letp<std::string::iterator> grammar;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
    }
} // namespace keyword

TEST(LEX, KEYWORD) {
    struct Experiment {
        std::string             s;
        venezia::token::Keyword expected;
    };

    std::vector<Experiment> experiments {
          {"fn", venezia::token::keyword::Function{}}
        , {"let", venezia::token::keyword::Let{}}
    };

    venezia::lexer::keywordp<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::token::Keyword decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected.which(), decoded.which());
    }
}

TEST(LEX, IDENTIFIER) {
    struct Experiment {
        std::string                 s;
        venezia::token::Identifier  expected;
    };

    std::vector<Experiment> experiments = {
          { "ten",  venezia::token::Identifier{"ten"}}
        , {  "10",   venezia::token::Identifier{"10"}}
        , {"five", venezia::token::Identifier{"five"}}
        , {   "5",    venezia::token::Identifier{"5"}}
        , { "add",  venezia::token::Identifier{"add"}}
    };

    venezia::lexer::identifierp<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::token::Identifier decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected, decoded);
    }
}

TEST(LEX, TOKEN) {
    struct Experiment {
        std::string     s;
        venezia::Token  expected;
    };

    std::vector<Experiment> experiments {
          {  "=", venezia::token::operation::Assignment{}}
        , {  "+", venezia::token::operation::Plus{}}
        , {  ",", venezia::token::delimiter::Comma{}}
        , {  ";", venezia::token::delimiter::Semicolon{}}
        , {  "(", venezia::token::parentheses::Left{}}
        , {  ")", venezia::token::parentheses::Right{}}
        , {  "{", venezia::token::brace::Left{}}
        , {  "}", venezia::token::brace::Right{}}
        , { "fn", venezia::token::keyword::Function{}}
        , {"let", venezia::token::keyword::Let{}}
    };

    venezia::lexer::lexerp<std::string::const_iterator> grammar;
    for (const Experiment& experiment : experiments) {
        const std::string& s = experiment.s;

        venezia::Token decoded;

        ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));
        EXPECT_EQ(experiment.expected.which(), decoded.which());
    }
}

TEST(LEX, TOKENS) {
    venezia::Tokens  expected = {
          venezia::token::operation::Assignment{}
        , venezia::token::operation::Plus{}
        , venezia::token::delimiter::Comma{}
        , venezia::token::delimiter::Semicolon{}
        , venezia::token::parentheses::Left{}
        , venezia::token::parentheses::Right{}
        , venezia::token::brace::Left{}
        , venezia::token::brace::Right{}
        , venezia::token::keyword::Function{}
        , venezia::token::keyword::Let{}
    };
    venezia::Tokens  decoded;

    std::string s = "=+,;(){}fnlet";
    venezia::lexer::lexersp<std::string::iterator> grammar;
    ASSERT_TRUE(qi::parse(s.begin(), s.end(), grammar, decoded));

    EXPECT_EQ(expected.size(), decoded.size());
    for (std::pair<venezia::Token&, venezia::Token&> element : std::views::zip(expected, decoded)) {
        EXPECT_EQ(element.first.which(), element.second.which());
    }
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
