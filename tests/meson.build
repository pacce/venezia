gtest               = dependency('gtest')

dependencies = [gtest, venezia_dep]
test('lexer', executable('lexer', 'lexer.cpp', dependencies: dependencies))
test('token', executable('token', 'token.cpp', dependencies: dependencies))
