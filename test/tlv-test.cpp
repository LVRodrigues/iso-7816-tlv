#include <gtest/gtest.h>
#include <iso-7816-tlv.h>

TEST(TLV, TLV) {
  TLV tlv;
  tlv.setTag(0x00);
  tlv.setValue("ababababab");
  EXPECT_EQ(0x00, tlv.getTag());
  EXPECT_EQ("ababababab", tlv.getValue());
  EXPECT_EQ(5, tlv.getLength());
}

TEST(TLV, CLASS) {
  TLV tlv;
  EXPECT_EQ(TLV::Class::UNDEFINED, tlv.getClass());

  tlv.setTag(0X50);
  EXPECT_EQ(TLV::Class::APPLICATION, tlv.getClass());

  tlv.setTag(0x8B);
  EXPECT_EQ(TLV::Class::CONTEXT_DEPENDENT, tlv.getClass());

  tlv.setTag(0XCF);
  EXPECT_EQ(TLV::Class::UNDEFINED, tlv.getClass());
}
