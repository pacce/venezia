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
} // namespace operation
    using Operation = boost::variant<operation::Assignment, operation::Plus>;
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
} // namespace token
} // namespace venezia
// namespace brace {
//     struct Left {
//         friend std::ostream&
//         operator<<(std::ostream& os, const Left&) {
//             return os << "{";
//         }
//     };
//     struct Right {
//         friend std::ostream&
//         operator<<(std::ostream& os, const Right&) {
//             return os << "}";
//         }
//     };
// } // namespace brace
// namespace keyword {
//     struct Function {
//         friend std::ostream&
//         operator<<(std::ostream& os, const Function&) {
//             return os << "fn";
//         }
//     };
//     struct Let {
//         friend std::ostream&
//         operator<<(std::ostream& os, const Let&) {
//             return os << "let";
//         }
//     };
// } // namespace keyword
//     struct Illegal {
//         char value;
// 
//         friend std::ostream&
//         operator<<(std::ostream& os, const Illegal& v) {
//             return os << "illegal: " << v.value;
//         }
//     };
// 
//     struct End {
//         friend std::ostream&
//         operator<<(std::ostream& os, const End&) {
//             return os << "EOF";
//         }
//     };
// } // namespace token
//     using Token = std::variant<
//           token::Illegal
//         , token::End
//         , token::operation::Assignment
//         , token::operation::Plus
//         , token::delimiter::Comma
//         , token::delimiter::Semicolon
//         , token::parentheses::Left
//         , token::parentheses::Right
//         , token::brace::Left
//         , token::brace::Right
//         , token::keyword::Function
//         , token::keyword::Let
//     >;
// namespace token {
//     struct is_assignment {
//         bool operator()(const operation::Assignment&)   { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_plus {
//         bool operator()(const operation::Plus&)         { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_comma {
//         bool operator()(const delimiter::Comma&)        { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_semicolon {
//         bool operator()(const delimiter::Semicolon&)    { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_parentheses {
//         bool operator()(const parentheses::Left&)       { return true; }
//         bool operator()(const parentheses::Right&)      { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_brace {
//         bool operator()(const brace::Left&)             { return true; }
//         bool operator()(const brace::Right&)            { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_left {
//         bool operator()(const parentheses::Left&)       { return true; }
//         bool operator()(const brace::Left&)             { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_right {
//         bool operator()(const parentheses::Right&)      { return true; }
//         bool operator()(const brace::Right&)            { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_function {
//         bool operator()(const keyword::Function&)       { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// 
//     struct is_let {
//         bool operator()(const keyword::Let&)            { return true; }
//         template <typename T> bool operator()(const T&) { return false; }
//     };
// } // namespace token
// } // namespace venezia

#endif // VENEZIA_TOKEN_HPP__
