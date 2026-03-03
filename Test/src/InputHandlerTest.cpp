#include "InputHandler.h"
#include <gtest/gtest.h>

// Whitespace Tests

TEST(GivenRemovesWhitespaceTest, WhenNoWhitespace_ThenStringUnchanged) {
    std::string input = "Hello";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(GivenRemovesWhitespaceTest, WhenLeadingWhitespace_ThenSpacesRemoved) {
    std::string input = "  Hello";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(GivenRemovesWhitespaceTest, WhenTrailingWhitespace_ThenSpacesRemoved) {
    std::string input = "Hello  ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(GivenRemovesWhitespaceTest, WhenBothSidesWhitespace_ThenSpacesRemoved) {
    std::string input = "  Hello   ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello");
}

TEST(GivenRemovesWhitespaceTest, WhenInnerSpaces_ThenSpacesUnchanged) {
    std::string input = "  Hello World  ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "Hello World");
}

TEST(GivenRemovesWhitespaceTest, WhenOnlyWhitespace_ThenStringEmpty) {
    std::string input = "   ";
    InputHandler::removeLeadingAndTrailingWhitespaces(input);
    EXPECT_EQ(input, "");
}
