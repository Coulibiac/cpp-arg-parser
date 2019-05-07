#include "gtest/gtest.h"

#include "argparser/internal/IntArgumentParser.hpp"
#include "argparser/InvalidFlagNameException.hpp"

namespace ArgumentParserTests
{

class IntArgumentParserTests : public testing::Test
{
protected:
    
    IntArgumentParserTests() = default;

    ~IntArgumentParserTests() override = default;

    void SetUp() override 
    {
    
    }

    void TearDown() override 
    {
    
    }

    ArgumentParser::InternalAP::IntArgumentParser testParser;
};

TEST_F(IntArgumentParserTests, ParseIntReturnsIntGivenInt)
{
    ASSERT_EQ(0, testParser.parseIntValue("flag=0"));
}

//TEST_F(IntArgumentParserTests, ParseIntReturnsValueGivenValue)
//{
//    ASSERT_EQ(12, testParser.parseIntValue("flag=12"));
//}

}
