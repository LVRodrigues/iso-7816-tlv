/**
 * @file iso-7816-tlv-parser.cpp
 * @author Luciano Vieira Rodrigues (luciano.vieira@digicon.com.br)
 * @brief Implementação de iso-7816-tlv-parser.h.
 * @version 1.0
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "iso-7816-tlv-parser.h"
#include "utils.h"

std::vector<TLV> TLVParser::parse(std::string data) {
    std::vector<uint8_t> buffer = Utils::hex2bytes(data);
    return parse(buffer);
}

std::vector<TLV> TLVParser::parse(const uint8_t* data, size_t length) {
    std::vector<uint8_t> buffer;
    buffer.reserve(length);
    for (size_t i = 0; i < length; i++) {
        buffer.push_back(data[i]);
    }
    return parse(buffer);
}

std::vector<TLV> TLVParser::parse(std::vector<uint8_t> data) {
    std::vector<TLV> result;
    return result;
}