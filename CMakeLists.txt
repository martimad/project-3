cmake_minimum_required(VERSION 3.17)
project(project_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(project_2 main.cpp Automaton.h ColonAutomaton.cpp ColonAutomaton.h ColonDashAutomaton.cpp ColonDashAutomaton.h Comment.h DatalogProgram.cpp DatalogProgram.h ID.h Lexer.cpp Lexer.h MatcherAutomaton.cpp MatcherAutomaton.h Rule.h Predicate.h Parameter.h Parser.cpp Parser.h String.h Token.cpp Token.h)