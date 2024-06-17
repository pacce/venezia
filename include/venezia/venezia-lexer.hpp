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

    template <typename Iterator>
    struct minusp : qi::grammar<Iterator, token::operation::Minus> {
        minusp() : minusp::base_type(rule) {
            rule = "-" >> qi::attr(token::operation::Minus{});
        }

        qi::rule<Iterator, token::operation::Minus> rule;
    };

    template <typename Iterator>
    struct bangp : qi::grammar<Iterator, token::operation::Bang> {
        bangp() : bangp::base_type(rule) {
            rule = "!" >> qi::attr(token::operation::Bang{});
        }

        qi::rule<Iterator, token::operation::Bang> rule;
    };

    template <typename Iterator>
    struct asteriskp : qi::grammar<Iterator, token::operation::Asterisk> {
        asteriskp() : asteriskp::base_type(rule) {
            rule = "*" >> qi::attr(token::operation::Asterisk{});
        }

        qi::rule<Iterator, token::operation::Asterisk> rule;
    };

    template <typename Iterator>
    struct slashp : qi::grammar<Iterator, token::operation::Slash> {
        slashp() : slashp::base_type(rule) {
            rule = "/" >> qi::attr(token::operation::Slash{});
        }

        qi::rule<Iterator, token::operation::Slash> rule;
    };

    template <typename Iterator>
    struct lesserp : qi::grammar<Iterator, token::operation::Lesser> {
        lesserp() : lesserp::base_type(rule) {
            rule = "<" >> qi::attr(token::operation::Lesser{});
        }

        qi::rule<Iterator, token::operation::Lesser> rule;
    };

    template <typename Iterator>
    struct greaterp : qi::grammar<Iterator, token::operation::Greater> {
        greaterp() : greaterp::base_type(rule) {
            rule = ">" >> qi::attr(token::operation::Greater{});
        }

        qi::rule<Iterator, token::operation::Greater> rule;
    };
} // namespace operation
    template <typename Iterator>
    struct operationp : qi::grammar<Iterator, token::Operation> {
        operationp() : operationp::base_type(rule) {
            rule = assignment 
                | plus 
                | minus
                | bang
                | asterisk
                | slash
                | lesser
                | greater
                ;
        }

        operation::assignmentp<Iterator>    assignment;
        operation::plusp<Iterator>          plus;
        operation::minusp<Iterator>         minus;
        operation::bangp<Iterator>          bang;
        operation::asteriskp<Iterator>      asterisk;
        operation::slashp<Iterator>         slash;
        operation::lesserp<Iterator>        lesser;
        operation::greaterp<Iterator>       greater;

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

    template <typename Iterator>
    struct truep : qi::grammar<Iterator, token::keyword::True> {
        truep() : truep::base_type(rule) {
            rule = "true" >> qi::attr(token::keyword::True{});
        }

        qi::rule<Iterator, token::keyword::True> rule;
    };

    template <typename Iterator>
    struct falsep : qi::grammar<Iterator, token::keyword::False> {
        falsep() : falsep::base_type(rule) {
            rule = "false" >> qi::attr(token::keyword::False{});
        }

        qi::rule<Iterator, token::keyword::False> rule;
    };

    template <typename Iterator>
    struct ifp : qi::grammar<Iterator, token::keyword::If> {
        ifp() : ifp::base_type(rule) {
            rule = "if" >> qi::attr(token::keyword::If{});
        }

        qi::rule<Iterator, token::keyword::If> rule;
    };

    template <typename Iterator>
    struct elsep : qi::grammar<Iterator, token::keyword::Else> {
        elsep() : elsep::base_type(rule) {
            rule = "else" >> qi::attr(token::keyword::Else{});
        }

        qi::rule<Iterator, token::keyword::Else> rule;
    };

    template <typename Iterator>
    struct returnp : qi::grammar<Iterator, token::keyword::Return> {
        returnp() : returnp::base_type(rule) {
            rule = "return" >> qi::attr(token::keyword::Return{});
        }

        qi::rule<Iterator, token::keyword::Return> rule;
    };
} // namespace keyword
    template <typename Iterator>
    struct keywordp : qi::grammar<Iterator, token::Keyword> {
        keywordp() : keywordp::base_type(rule) {
            rule = function 
                | let
                | truep
                | falsep
                | ifp
                | elsep
                | returnp
                ;
        }

        keyword::functionp<Iterator>    function;
        keyword::letp<Iterator>         let;
        keyword::truep<Iterator>        truep;
        keyword::falsep<Iterator>       falsep;
        keyword::ifp<Iterator>          ifp;
        keyword::elsep<Iterator>        elsep;
        keyword::returnp<Iterator>      returnp;

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
                | identifier
                ;
        }

        lexer::operationp<Iterator>     operation;
        lexer::delimiterp<Iterator>     delimiter;
        lexer::parenthesesp<Iterator>   parentheses;
        lexer::bracep<Iterator>         brace;
        lexer::keywordp<Iterator>       keyword;
        lexer::identifierp<Iterator>    identifier;

        qi::rule<Iterator, Token>       rule;
    };

    template <typename Iterator>
    struct lexersp : qi::grammar<Iterator, Tokens> {
        lexersp() : lexersp::base_type(rule) {
            rule = qi::repeat[qi::skip(qi::space)[lexer]];
        }

        lexerp<Iterator>            lexer;
        qi::rule<Iterator, Tokens>  rule;
    };
} // namespace lexer
} // namespace venezia

#endif // VENEZIA_LEXER_HPP__
