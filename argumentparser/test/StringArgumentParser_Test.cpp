#include "gtest/gtest.h"

#include "argparser/internal/StringArgumentParser.hpp"
#include "argparser/InvalidFlagNameException.hpp"

namespace ArgumentParserTests
{

class StringArgumentParserTests : public testing::Test
{
protected:
    
    StringArgumentParserTests() = default;

    ~StringArgumentParserTests() override = default;

    void SetUp() override 
    {
    
    }

    void TearDown() override 
    {
    
    }

    ArgumentParser::InternalAP::StringArgumentParser testParser;
};

TEST_F(StringArgumentParserTests, ParseStringReturnsBlankGivenBlank)
{
    ASSERT_EQ("", testParser.parseStringValue("flag="));
}

TEST_F(StringArgumentParserTests, ParseStringReturnsValueGivenValue)
{
    ASSERT_EQ("test", testParser.parseStringValue("flag=test"));
}

}
