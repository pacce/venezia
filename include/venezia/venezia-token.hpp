#ifndef VENEZIA_TOKEN_HPP__
#define VENEZIA_TOKEN_HPP__

#include <boost/variant.hpp>
#include <ostream>

namespace venezia {
namespace token {
namespace operation {
    struct Assignment {
        friend std::ostream&
        operator<<(std::ostream& os, const Assignment&) {
            return os << "=";
        }
    };

    struct Plus {
        friend std::ostream&
        operator<<(std::ostream& os, const Plus&) {
            return os << "+";
        }
    };

    struct Minus {
        friend std::ostream&
        operator<<(std::ostream& os, const Minus&) {
            return os << "-";
        }
    };

    struct Bang {
        friend std::ostream&
        operator<<(std::ostream& os, const Bang&) {
            return os << "!";
        }
    };

    struct Asterisk {
        friend std::ostream&
        operator<<(std::ostream& os, const Asterisk&) {
            return os << "*";
        }
    };

    struct Slash {
        friend std::ostream&
        operator<<(std::ostream& os, const Slash&) {
            return os << "/";
        }
    };

    struct Lesser {
        friend std::ostream&
        operator<<(std::ostream& os, const Lesser&) {
            return os << "<";
        }
    };

    struct Greater {
        friend std::ostream&
        operator<<(std::ostream& os, const Greater&) {
            return os << ">";
        }
    };
} // namespace operation
    using Operation = boost::variant<
          operation::Assignment
        , operation::Plus
        , operation::Minus
        , operation::Bang
        , operation::Asterisk
        , operation::Slash
        , operation::Lesser
        , operation::Greater
        >;
namespace delimiter {
    struct Comma {
        friend std::ostream&
        operator<<(std::ostream& os, const Comma&) {
            return os << ",";
        }
    };

    struct Semicolon {
        friend std::ostream&
        operator<<(std::ostream& os, const Semicolon&) {
            return os << ";";
        }
    };
} // namespace delimiter
    using Delimiter = boost::variant<delimiter::Comma, delimiter::Semicolon>;

namespace parentheses {
    struct Left {
        friend std::ostream&
        operator<<(std::ostream& os, const Left&) {
            return os << "(";
        }
    };

    struct Right {
        friend std::ostream&
        operator<<(std::ostream& os, const Right&) {
            return os << ")";
        }
    };
} // namespace parentheses
    using Parentheses = boost::variant<parentheses::Left, parentheses::Right>;
namespace brace {
    struct Left {
        friend std::ostream&
        operator<<(std::ostream& os, const Left&) {
            return os << "{";
        }
    };

    struct Right {
        friend std::ostream&
        operator<<(std::ostream& os, const Right&) {
            return os << "}";
        }
    };
} // namespace brace
    using Brace = boost::variant<brace::Left, brace::Right>;
namespace keyword {
    struct Function {
        friend std::ostream&
        operator<<(std::ostream& os, const Function&) {
            return os << "fn";
        }
    };

    struct Let {
        friend std::ostream&
        operator<<(std::ostream& os, const Let&) {
            return os << "let";
        }
    };
} // namespace keyword
    using Keyword = boost::variant<keyword::Function, keyword::Let>;

    struct Identifier {
        std::string content;

        friend std::ostream&
        operator<<(std::ostream& os, const Identifier& identifier) {
            return os << "identifier: " << identifier.content;
        }

        friend bool
        operator==(const Identifier& lhs, const Identifier& rhs) {
            return lhs.content == rhs.content;
        }

        friend bool
        operator!=(const Identifier& lhs, const Identifier& rhs) {
            return lhs.content != rhs.content;
        }
    };
} // namespace token
    using Token = boost::variant<
          token::Operation
        , token::Delimiter
        , token::Parentheses
        , token::Brace
        , token::Keyword
        , token::Identifier
    >;

    struct Tokens {
        std::vector<Token> content;

        Tokens() {}
        Tokens(const std::vector<Token>& c) : content(c) {}
        Tokens(std::initializer_list<Token> c) : content(c) {}

        typedef typename std::vector<Token>::value_type value_type;
        typedef typename std::vector<Token>::size_type  size_type;

        typedef typename std::vector<Token>::iterator               iterator;
        typedef typename std::vector<Token>::const_iterator         const_iterator;
        typedef typename std::vector<Token>::reverse_iterator       reverse_iterator;
        typedef typename std::vector<Token>::const_reverse_iterator const_reverse_iterator;

        iterator begin()                        { return content.begin(); }
        iterator end()                          { return content.end(); }
        const_iterator begin() const            { return content.begin(); }
        const_iterator end() const              { return content.end(); }
        reverse_iterator rbegin()               { return content.rbegin(); }
        reverse_iterator rend()                 { return content.rend(); }
        const_reverse_iterator rbegin() const   { return content.rbegin(); }
        const_reverse_iterator rend() const     { return content.rend(); }

        size_type
        size() const {
            return content.size();
        }

        void
        insert(iterator pos, value_type value) {
            content.insert(pos, value);
        }

        void
        push_back(value_type value) {
            content.push_back(value);
        }
    };
} // namespace venezia

#endif // VENEZIA_TOKEN_HPP__
