add_executable(tlv-test tlv-test.cpp)

target_link_libraries(tlv-test 
    LINK_PRIVATE gtest_main
    LINK_PUBLIC iso-7816-tlv)

    include(GoogleTest)
    gtest_discover_tests(tlv-test)    