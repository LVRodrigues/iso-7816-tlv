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

#include <bit>
#include <byteswap.h>
#include <cstring>

/**
 * @brief Máscara para identificar se a tag continua para o próximo byte.
 */
const uint8_t TAG_NEXT_BYTE = 0b00011111;

/**
 * @brief Constante para informar que o tamanho do campo está identificado
 * no próximo byte.
 */
const uint8_t LENGTH_MORE_1 = 0x81;

/**
 * @brief Constante para informar que o tamanho do campo está identificado
 * nos próximos 2 bytes.
 */
const uint8_t LENGTH_MORE_2 = 0x82;

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
    // Matriz vazia não será processada:
    if (data.empty()) {
        return result;
    }
    // Transformando a matriz de bytes em uma fila para facilitar o processamento:
    std::queue<uint8_t> queue;
    for (uint8_t byte : data) {
        queue.push(byte);
    }
    // Processando a matriz de bytes:
    do {
        TLV tlv;
        uint32_t tag    = TLVParser::parseTag(queue);
        uint32_t length = TLVParser::parseLength(queue);

        tlv.setTag(tag);
        for (int i = 0; i < length; i++) {
            tlv.getValue().push_back(queue.front());
            queue.pop();
        }
        result.push_back(tlv);
    } while (!queue.empty());
    return result;
}

uint32_t TLVParser::toInt32(std::vector<uint8_t> buffer) {
    uint32_t result;
    for (int i = buffer.size(); i < sizeof(uint32_t); i++) {
        buffer.insert(buffer.begin(), 0);
    }
    std::memcpy(&result, buffer.data(), buffer.size());
    if constexpr (std::endian::native == std::endian::big) {
        return result;
    }
    return bswap_32(result);
}

uint32_t TLVParser::parseTag(std::queue<uint8_t> &queue) {
    std::vector<uint8_t> result;
    uint8_t current = 0;
    do {
        current = queue.front();
        queue.pop();
        result.push_back(current);
    } while ((current & TAG_NEXT_BYTE) == TAG_NEXT_BYTE);
    return TLVParser::toInt32(result);
}

uint32_t TLVParser::parseLength(std::queue<uint8_t> &queue) {
    std::vector<uint8_t> result;
    uint8_t current = queue.front();
    queue.pop();
    if (current == LENGTH_MORE_1) {
        current = queue.front();
        queue.pop();
        result.push_back(current);
    } else if (current == LENGTH_MORE_2) {
        for (int i = 0; i < 2; i++) {
            current = queue.front();
            queue.pop();
            result.push_back(current);
        }
    } else {
        result.push_back(current);
    }
    return TLVParser::toInt32(result);
}