include(GoogleTest)

add_executable(tlv-test tlv-test.cpp)
target_link_libraries(tlv-test 
    LINK_PRIVATE gtest_main
    LINK_PUBLIC iso-7816-tlv)
gtest_discover_tests(tlv-test)

add_executable(utils-test utils-test.cpp)
target_link_libraries(utils-test 
    LINK_PRIVATE gtest_main
    LINK_PUBLIC iso-7816-tlv)
gtest_discover_tests(utils-test)    

add_executable(parser-test parser-test.cpp)
target_link_libraries(parser-test 
    LINK_PRIVATE gtest_main
    LINK_PUBLIC iso-7816-tlv)
gtest_discover_tests(parser-test)    