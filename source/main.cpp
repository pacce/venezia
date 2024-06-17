#include <boost/spirit/include/qi.hpp>
#include <venezia/venezia.hpp>

namespace qi = boost::spirit::qi;

template <typename Iterator>
venezia::Tokens
scan(Iterator begin, Iterator end) {
    venezia::lexer::lexersp<Iterator> grammar;
    venezia::Tokens decoded;

    if (qi::parse(begin, end, grammar, decoded)) {
        return decoded; 
    } else {
        return {};
    }
}

int
main(int, char**) {
    while (true) {
        std::cout << ">> ";

        std::string line;
        std::getline(std::cin, line);
        venezia::Tokens tokens = scan(std::begin(line), std::end(line));
        for (const venezia::Token& token : tokens) {
            std::cout << token << std::endl;
        }
    }
    return 0;
}
