#include "InputHandler.h"
#include <gtest/gtest.h>

// Whitespace Tests

TEST(RemovesWhitespaceTest, NoWhitespace_StringUnchanged) {
    std::string input = "Hello";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(RemovesWhitespaceTest, LeadingWhitespace_Removed) {
    std::string input = "  Hello";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(RemovesWhitespaceTest, TrailingWhitespace_Removed) {
    std::string input = "Hello  ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(RemovesWhitespaceTest, BothSidesWhitespace_Removed) {
    std::string input = "  Hello   ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(RemovesWhitespaceTest, InnerSpaces_Unchanged) {
    std::string input = "  Hello World  ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello World");
}

TEST(RemovesWhitespaceTest, OnlyWhitespace_StringEmpty) {
    std::string input = "   ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "");
}
