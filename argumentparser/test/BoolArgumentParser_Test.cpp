#include "gtest/gtest.h"

#include "argparser/internal/BoolArgumentParser.hpp"
#include "argparser/InvalidFlagNameException.hpp"

namespace ArgumentParserTests
{

class BoolArgumentParserTests : public testing::Test
{
protected:
    
    BoolArgumentParserTests() = default;

    ~BoolArgumentParserTests() override = default;

    void SetUp() override 
    {
    
    }

    void TearDown() override 
    {
    
    }

    ArgumentParser::InternalAP::BoolArgumentParser testParser;
};

TEST_F(BoolArgumentParserTests, ParseBoolReturnsFalseGivenFalse)
{
    ASSERT_FALSE(testParser.parseBoolValue("false"));
}

TEST_F(BoolArgumentParserTests, ParseBoolReturnsTrueGivenTrue)
{
    ASSERT_TRUE(testParser.parseBoolValue("true"));
}

TEST_F(BoolArgumentParserTests, ParseBoolThrowsExceptionWhenGivenInvalidInput)
{
    ASSERT_THROW(testParser.parseBoolValue("Throw"), ArgumentParser::InvalidFlagNameException);
}

}
