/**
 * @file iso-7816-tlv.h
 * @author $Author$
 * @brief Estrutura de dados para elementos de protoclos codificados com o formato TLV.
 * @version 1.0
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 */

#include <cstdint>
#include <string>
#include <vector>

/**
 * @brief Tag-Length-Value
 * 
 * Mensagem codificada no formato TLV.
 */
class TLV {
    public:
        /**
         * @brief Classe do elemento.
         * 
         * Valor extraído dos dois primeiros bits do campo tag.
         */
        enum Class {
            UNDEFINED,          /**< Classe indefinida. */
            APPLICATION,        /**< Classe de aplicação. */
            CONTEXT_DEPENDENT   /**< Classe de conteúdo de dados complexos. */
        };

    private:
        /**
         * @brief Identificador do tipo de campo.
         */
        int32_t tag;

        /**
         * @brief Dados no formato hexadecimal.
         */
        std::string value;

        /**
         * @brief Elementos filhos.
         * 
         * Quando o elemento corrente é um objeto complexo, formado por outros 
         * elementos TLV.
         */
        std::vector<TLV> items;
    
    public:
        /**
         * @brief Construtor do objeto TLV.
         */
        TLV() {
            tag     = 0;
            value   = "";
        }

        /**
         * @brief Destrutor do objeto TLV.
         */
        ~TLV() {}

        /**
         * @brief Recupera o campo ::tag.
         * 
         * @return int32_t Identificador do tipo de campo.
         */
        int32_t getTag() { return tag; }

        /**
         * @brief Atribui o valor para o campo ::tag.
         * 
         * @param[in] value Identificador do tipo de campo.
         */
        void setTag(int32_t value) { tag = value; }

        /**
         * @brief Recupera o tamanho do campo de dados (::value).
         * 
         * @return int32_t Tamanho do campo value, em bytes.
         */
        int32_t getLength() { return value.size() / 2; }

        /**
         * @brief Recupera o campo ::value.
         * 
         * @return std::string Campo de dados no formato hexadecimal.
         */
        std::string getValue() { return value; }

        /**
         * @brief Atribui o valor para o campo ::value.
         * 
         * @param[in] value Valor no formato hexadecimal.
         */
        void setValue(const std::string value);

        /**
         * @brief Recupera a classe do elemento corrente.
         * 
         * @return ::Class
         */
        Class getClass();

        /**
         * @brief Recupera um conjunto de elementos filhos.
         * 
         * @return std::vector<TLV> Conjunto de elementos TVL.
         */
        std::vector<TLV> childrens() { return items; }
};