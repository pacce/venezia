#ifndef VENEZIA_LEXER_HPP__
#define VENEZIA_LEXER_HPP__

#include <optional>
#include <vector>
#include "venezia-token.hpp"

namespace venezia {
namespace lexer {
    template <typename Iterator>
    std::optional<char>
    read(Iterator& begin, Iterator end) {
        if (begin == end) { return std::nullopt; }
        return *(begin++);
    }
} // namespace lexer
    struct Lexer {
        template <typename Iterator>
        std::vector<venezia::Token>
        operator()(Iterator begin, Iterator end) const {
            std::vector<venezia::Token> tokens;

            std::optional<char> ch = std::nullopt;
            while (true) {
                ch = lexer::read(begin, end);
                if (not ch) { 
                    tokens.push_back(venezia::token::End{}); break;
                } else {
                    switch (*ch) {
                        case '=': { tokens.push_back(venezia::token::operation::Assignment{}); break; }
                        case '+': { tokens.push_back(venezia::token::operation::Plus{}); break; }
                        case '(': { tokens.push_back(venezia::token::parentheses::Left{}); break; }
                        case ')': { tokens.push_back(venezia::token::parentheses::Right{}); break; }
                        case '{': { tokens.push_back(venezia::token::brace::Left{}); break; }
                        case '}': { tokens.push_back(venezia::token::brace::Right{}); break; }
                        case ';': { tokens.push_back(venezia::token::delimiter::Semicolon{}); break; }
                        case ',': { tokens.push_back(venezia::token::delimiter::Comma{}); break; }
                    }
                }
            }
            return tokens;
        }
    };
} // namespace venezia

#endif // VENEZIA_LEXER_HPP__
