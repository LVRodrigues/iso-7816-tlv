#include <gtest/gtest.h>
#include <iso-7816-tlv.h>

TEST(TLV, TLV) {
  TLV tlv;
  EXPECT_EQ(0x00, tlv.getTag());
  EXPECT_EQ("", tlv.getValue());
  EXPECT_EQ(0, tlv.getLength());

  tlv.setTag(0x0A);
  tlv.setValue("ababababab");
  EXPECT_EQ(0x0A, tlv.getTag());
  EXPECT_EQ("ababababab", tlv.getValue());
  EXPECT_EQ(5, tlv.getLength());

  EXPECT_ANY_THROW(tlv.setValue("abababababa"));
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

TEST(TLV, DATA_OBJECT) {
  TLV tlv;
  
  tlv.setTag(0x4B);
  EXPECT_EQ(TLV::DataObject::PRIMITIVE, tlv.getDataObject());

  tlv.setTag(0x6B);
  EXPECT_EQ(TLV::DataObject::CONSTRUCTED, tlv.getDataObject());
}