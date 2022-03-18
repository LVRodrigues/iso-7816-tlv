/**
 * @file iso-7816-tlv-parser.h
 * @author $Author$
 * @brief Analisador de elementos no protoclo TLV.
 * @version 1.0
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef TLV_PARSER_H
#define TLV_PARSER_H

#include "iso-7816-tlv.h"
#include <vector>

/**
 * @brief Analisador de elementos no protocolo TLV.
 */
class TLVParser {
    public:
        /**
         * @brief Analisa um fluxo de bytes no formato hexadecimal e extrai elementos
         * no formato TLV.
         * 
         * @param[in] data Bytes no formato hexadecimal.
         * @return std::vector<TLV> 
         */
        static std::vector<TLV> parse(std::string data);

        /**
         * @brief Analiza um fluxo de bytes e extrai elementos no formato TLV.
         * 
         * @param[in] data Matriz de bytes.
         * @param[in] length Tamanho da matriz de bytes.
         * @return std::vector<TLV> 
         */
        static std::vector<TLV> parse(const char* data, size_t length);

        /**
         * @brief Analiza um fluxo de bytes e extrai elementos no formato TLV.
         * 
         * @param[in] data Matriz de bytes.
         * @return std::vector<TLV> 
         */
        static std::vector<TLV> parse(std::vector<uint8_t> data);
};

#endif              // TLV_PARSER_H