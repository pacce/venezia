#ifndef VENEZIA_LEXER_HPP__
#define VENEZIA_LEXER_HPP__

#include <boost/spirit/include/qi.hpp>
#include "venezia-token.hpp"

namespace venezia {
namespace lexer {
    namespace qi = boost::spirit::qi;

    template <typename Iterator>
    struct assignmentp : qi::grammar<Iterator, token::operation::Assignment> {
        assignmentp() : assignmentp::base_type(rule) {
            rule = &qi::lit("=");
        }

        qi::rule<Iterator, token::operation::Assignment> rule;
    };

    template <typename Iterator>
    struct plusp : qi::grammar<Iterator, token::operation::Plus> {
        plusp() : plusp::base_type(rule) {
            rule = &qi::lit("+");
        }

        qi::rule<Iterator, token::operation::Plus> rule;
    };

    template <typename Iterator>
    struct operationp : qi::grammar<Iterator, token::Operation> {
        operationp() : operationp::base_type(rule) {
            rule = assignment | plus;
        }

        assignmentp<Iterator>   assignment;
        plusp<Iterator>         plus;

        qi::rule<Iterator, token::Operation> rule;
    };

    template <typename Iterator>
    struct commap : qi::grammar<Iterator, token::delimiter::Comma> {
        commap() : commap::base_type(rule) {
            rule = &qi::lit(",");
        }

        qi::rule<Iterator, token::delimiter::Comma> rule;
    };

    template <typename Iterator>
    struct semicolonp : qi::grammar<Iterator, token::delimiter::Semicolon> {
        semicolonp() : semicolonp::base_type(rule) {
            rule = &qi::lit(";");
        }

        qi::rule<Iterator, token::delimiter::Semicolon> rule;
    };

    template <typename Iterator>
    struct delimiterp : qi::grammar<Iterator, token::Delimiter> {
        delimiterp() : delimiterp::base_type(rule) {
            rule = comma | semicolon;
        }

        commap<Iterator>        comma;
        semicolonp<Iterator>    semicolon;

        qi::rule<Iterator, token::Delimiter> rule;
    };

namespace parentheses {
    template <typename Iterator>
    struct leftp : qi::grammar<Iterator, token::parentheses::Left> {
        leftp() : leftp::base_type(rule) {
            rule = &qi::lit("(");
        }

        qi::rule<Iterator, token::parentheses::Left> rule;
    };

    template <typename Iterator>
    struct rightp : qi::grammar<Iterator, token::parentheses::Right> {
        rightp() : rightp::base_type(rule) {
            rule = &qi::lit(")");
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
} // namespace lexer
} // namespace venezia

#endif // VENEZIA_LEXER_HPP__
