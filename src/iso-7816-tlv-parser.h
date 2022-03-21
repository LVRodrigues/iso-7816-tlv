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
#include <queue>

/**
 * @brief Analisador de elementos no protocolo TLV.
 */
class TLVParser {
        /**
         * @brief Converte uma matriz de byte em um valor Inteiro de 32 bits.
         * 
         * @param[in] buffer Matriz de bytes.
         * @return uint32_t Valor inteiro.
         */
        static uint32_t toInt32(std::vector<uint8_t> buffer);

        /**
         * @brief Extrai o campo tag de uma matriz de bytes.
         * 
         * Os bytes da tag são removidos da matriz de bytes.
         * 
         * @param[in,out] queue Matriz de bytes
         * @return uint32_t Tag identificada.
         */
        static uint32_t parseTag(std::queue<uint8_t> &queue);

        /**
         * @brief Extrai o campo de tamanho dos dados na matriz de bytes.
         * 
         * @param[in,out] queue Matriz de bytes.
         * @return uint32_t Tamanho do campo.
         */
        static uint32_t parseLength(std::queue<uint8_t> &queue);
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
        static std::vector<TLV> parse(const uint8_t* data, size_t length);

        /**
         * @brief Analiza um fluxo de bytes e extrai elementos no formato TLV.
         * 
         * @param[in] data Matriz de bytes.
         * @return std::vector<TLV> 
         */
        static std::vector<TLV> parse(std::vector<uint8_t> data);
};

#endif              // TLV_PARSER_H