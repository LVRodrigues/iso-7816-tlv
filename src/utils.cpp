/**
 * @file utils.cpp
 * @author $Author$
 * @brief Implementação de utils.h
 * @version 1.0
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 */

#include "utils.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

std::string Utils::bytes2hex(uint8_t *buffer, size_t length) {
    std::stringstream ss;
    for (uint32_t i = 0; i < length; i++) {
        if (i > 0) {
            ss << ' ';
        }
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buffer[i]);
    }
    return ss.str();
}

std::string Utils::bytes2hex(std::vector<uint8_t> buffer) {
    return Utils::bytes2hex(buffer.data(), buffer.size());
}

std::vector<uint8_t> Utils::hex2bytes(std::string hex) {
    std::vector<uint8_t> result;
    hex.erase(std::remove(hex.begin(), hex.end(), ' '), hex.end());
    if (hex.size() % 2 != 0) {
        throw new std::length_error("Tamanho inválido para o formato hexadecimal");
    }
    result.reserve(hex.length() / 2);
    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        uint8_t byte = (uint8_t) strtol(byteString.c_str(), NULL, 16);
        result.push_back(byte);
    }
    return result;
}
