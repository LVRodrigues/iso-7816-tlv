#include <gtest/gtest.h>
#include <iso-7816-tlv-parser.h>
#include <sstream>
#include <iostream>
#include <utils.h>

TEST(PARSER, PARSE_1) {
    std::string data = "050A0431190501123CB707DE";
    std::vector<TLV*> result = TLVParser::parse(data);
    ASSERT_EQ(1, result.size());
}

TEST(PARSER, PARSE_2) {
    std::stringstream stream;
    stream << "5F8703AABBCC";
    stream << "1A81910102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405060708090A0102030405";
    stream << "B105FEFEFEFEFE";
    std::vector<TLV*> result = TLVParser::parse(stream.str());
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(0x5f87, result[0]->getTag());
    ASSERT_EQ(0x1a, result[1]->getTag());
    ASSERT_EQ(0xb1, result[2]->getTag());
}

TEST(PARSER, Luciano) {
    std::string data = "610B4F04444730395003494D4D9000";
    std::vector<TLV*> result = TLVParser::parse(data);
    for (int i = 0; i < result.size(); i++) {
        std::cout << std::to_string(result[i]->getTag());
        std::cout << ", ";
        std::cout << Utils::bytes2hex(result[i]->value()->data(), result[i]->value()->size());
        std::cout << std::endl;
    }
}