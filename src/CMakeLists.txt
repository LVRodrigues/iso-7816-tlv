add_library(iso-7816-tlv SHARED 
    utils.cpp
    iso-7816-tlv.cpp
    iso-7816-tlv-parser.cpp)   

target_include_directories (iso-7816-tlv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})    