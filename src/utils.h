/**
 * @file utils.h
 * @author $Author$
 * @brief Classe de métodos utilitários.
 * @version 1.0
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _UTILS_H
#define _UTILS_H

#include <cstdint>
#include <string>
#include <vector>

/**
 * @brief Classe de métodos utilitários.
 */
class Utils {
    public:
        /**
         * @brief Converte uma matriz de bytes em um texto hexadecimal.
         * 
         * @param[in] buffer Matriz de bytes.
         * @param[in] length Tamaho da matriz de bytes.
         * @return std::string Texto com os bytes convertidos para seus valores hexadecimais.
         */
        static std::string bytes2hex(uint8_t *buffer, size_t length);

        /**
         * @brief Converte uma matriz de bytes em um texto hexadecimal.
         * 
         * @param[in] buffer Matriz de bytes.
         * @return std::string Texto com os bytes convertidos para seus valores hexadecimais.
         */
        static std::string bytes2hex(std::vector<uint8_t> buffer);

        /**
         * @brief Converte um texto com valores hexadeximais em uma matriz de bytes.
         * 
         * @param[in] hex Texto com valores hexadecimais.
         * @return std::vector<uint8_t> Matriz de bytes extraídos do texto hexadecimal.
         */
        static std::vector<uint8_t> hex2bytes(std::string hex);
};

#endif          // _UTILS_H