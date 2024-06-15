#ifndef VENEZIA_LEXER_HPP__
#define VENEZIA_LEXER_HPP__

#include <boost/spirit/include/qi.hpp>
#include "venezia-token.hpp"

namespace venezia {
namespace lexer {
    namespace qi = boost::spirit::qi;

namespace operation {
    template <typename Iterator>
    struct assignmentp : qi::grammar<Iterator, token::operation::Assignment> {
        assignmentp() : assignmentp::base_type(rule) {
            rule = "=" >> qi::attr(token::operation::Assignment{});
        }

        qi::rule<Iterator, token::operation::Assignment> rule;
    };

    template <typename Iterator>
    struct plusp : qi::grammar<Iterator, token::operation::Plus> {
        plusp() : plusp::base_type(rule) {
            rule = "+" >> qi::attr(token::operation::Plus{});
        }

        qi::rule<Iterator, token::operation::Plus> rule;
    };
} // namespace operation
    template <typename Iterator>
    struct operationp : qi::grammar<Iterator, token::Operation> {
        operationp() : operationp::base_type(rule) {
            rule = assignment | plus;
        }

        operation::assignmentp<Iterator>    assignment;
        operation::plusp<Iterator>          plus;

        qi::rule<Iterator, token::Operation> rule;
    };

namespace delimiter {
    template <typename Iterator>
    struct commap : qi::grammar<Iterator, token::delimiter::Comma> {
        commap() : commap::base_type(rule) {
            rule = "," >> qi::attr(token::delimiter::Comma{});
        }

        qi::rule<Iterator, token::delimiter::Comma> rule;
    };

    template <typename Iterator>
    struct semicolonp : qi::grammar<Iterator, token::delimiter::Semicolon> {
        semicolonp() : semicolonp::base_type(rule) {
            rule = ";" >> qi::attr(token::delimiter::Semicolon{});
        }

        qi::rule<Iterator, token::delimiter::Semicolon> rule;
    };
} // namespace delimiter

    template <typename Iterator>
    struct delimiterp : qi::grammar<Iterator, token::Delimiter> {
        delimiterp() : delimiterp::base_type(rule) {
            rule = comma | semicolon;
        }

        delimiter::commap<Iterator>     comma;
        delimiter::semicolonp<Iterator> semicolon;

        qi::rule<Iterator, token::Delimiter> rule;
    };
namespace parentheses {
    template <typename Iterator>
    struct leftp : qi::grammar<Iterator, token::parentheses::Left> {
        leftp() : leftp::base_type(rule) {
            rule = "(" >> qi::attr(token::parentheses::Left{});
        }

        qi::rule<Iterator, token::parentheses::Left> rule;
    };

    template <typename Iterator>
    struct rightp : qi::grammar<Iterator, token::parentheses::Right> {
        rightp() : rightp::base_type(rule) {
            rule = ")" >> qi::attr(token::parentheses::Right{});
        }

        qi::rule<Iterator, token::parentheses::Right> rule;
    };
} // namespace parentheses
    template <typename Iterator>
    struct parenthesesp : qi::grammar<Iterator, token::Parentheses> {
        parenthesesp() : parenthesesp::base_type(rule) {
            rule = left | right;
        }

        parentheses::leftp<Iterator>    left;
        parentheses::rightp<Iterator>   right;
        qi::rule<Iterator, token::Parentheses> rule;
    };
namespace brace {
    template <typename Iterator>
    struct leftp : qi::grammar<Iterator, token::brace::Left> {
        leftp() : leftp::base_type(rule) {
            rule = "{" >> qi::attr(token::brace::Left{});
        }

        qi::rule<Iterator, token::brace::Left> rule;
    };

    template <typename Iterator>
    struct rightp : qi::grammar<Iterator, token::brace::Right> {
        rightp() : rightp::base_type(rule) {
            rule = "}" >> qi::attr(token::brace::Right{});
        }

        qi::rule<Iterator, token::brace::Right> rule;
    };
} // namespace brace
    template <typename Iterator>
    struct bracep : qi::grammar<Iterator, token::Brace> {
        bracep() : bracep::base_type(rule) {
            rule = left | right;
        }

        brace::leftp<Iterator>    left;
        brace::rightp<Iterator>   right;
        qi::rule<Iterator, token::Brace> rule;
    };
namespace keyword {
    template <typename Iterator>
    struct functionp : qi::grammar<Iterator, token::keyword::Function> {
        functionp() : functionp::base_type(rule) {
            rule = "fn" >> qi::attr(token::keyword::Function{});
        }

        qi::rule<Iterator, token::keyword::Function> rule;
    };

    template <typename Iterator>
    struct letp : qi::grammar<Iterator, token::keyword::Let> {
        letp() : letp::base_type(rule) {
            rule = "let" >> qi::attr(token::keyword::Let{});
        }

        qi::rule<Iterator, token::keyword::Let> rule;
    };
} // namespace keyword
    template <typename Iterator>
    struct keywordp : qi::grammar<Iterator, token::Keyword> {
        keywordp() : keywordp::base_type(rule) {
            rule = function | let;
        }

        keyword::functionp<Iterator>        function;
        keyword::letp<Iterator>             let;
        qi::rule<Iterator, token::Keyword>  rule;
    };

    template <typename Iterator>
    struct identifierp : qi::grammar<Iterator, token::Identifier> {
        identifierp() : identifierp::base_type(rule) {
            word    = +(qi::alpha | qi::char_("_"));
            number  = +(qi::digit);
            rule    = word | number;
        }
        qi::rule<Iterator, std::string()>       word;
        qi::rule<Iterator, std::string()>       number;
        qi::rule<Iterator, token::Identifier>   rule;
    };

    template <typename Iterator>
    struct lexerp : qi::grammar<Iterator, Token> {
        lexerp() : lexerp::base_type(rule) {
            rule 
                = operation
                | delimiter
                | parentheses
                | brace
                | keyword
                ;
        }

        lexer::operationp<Iterator>     operation;
        lexer::delimiterp<Iterator>     delimiter;
        lexer::parenthesesp<Iterator>   parentheses;
        lexer::bracep<Iterator>         brace;
        lexer::keywordp<Iterator>       keyword;

        qi::rule<Iterator, Token>       rule;
    };

    template <typename Iterator>
    struct lexersp : qi::grammar<Iterator, Tokens> {
        lexersp() : lexersp::base_type(rule) {
            rule = qi::repeat[lexer];
        }

        lexerp<Iterator>            lexer;
        qi::rule<Iterator, Tokens>  rule;
    };
} // namespace lexer
} // namespace venezia

#endif // VENEZIA_LEXER_HPP__
