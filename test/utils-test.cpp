#include <gtest/gtest.h>
#include <utils.h>

TEST(UTILS, HEX_2_BYTES) {
    std::string hex = "AB AB AB AB AB AB";
    std::vector<uint8_t> result = Utils::hex2bytes(hex);
    EXPECT_EQ(6, result.size());
    for (int i = 0; i < result.size(); i++) {
        EXPECT_EQ(0xAB, result[i]);
    }
}

TEST(UTILS, BYTES_2_HEX) {
    uint8_t buffer[] = {0xff, 0xff, 0xff, 0xff, 0xff};
    std::string expected = "ff ff ff ff ff";
    std::string result = Utils::bytes2hex(buffer, sizeof(buffer));
    EXPECT_EQ(expected, result);
}