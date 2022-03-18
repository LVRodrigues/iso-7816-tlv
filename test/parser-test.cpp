#include <gtest/gtest.h>
#include <iso-7816-tlv-parser.h>

TEST(PARSER, PARSE_1) {
    std::string data = "050A0431190501123CB707DE";
    std::vector<TLV> result = TLVParser::parse(data);
    ASSERT_EQ(1, result.size());
}