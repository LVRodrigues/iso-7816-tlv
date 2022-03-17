add_library(iso-7816-tlv SHARED 
    iso-7816-tlv.cpp)   

target_include_directories (iso-7816-tlv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})    