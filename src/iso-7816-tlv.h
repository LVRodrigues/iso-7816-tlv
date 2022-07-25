/**
 * @file iso-7816-tlv.h
 * @author $Author$
 * @brief Estrutura de dados para elementos de protoclos codificados com o formato TLV.
 * @version 1.0
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef TLV_H
#define TLV_H

#include <cstdint>
#include <vector>
#include <string>

/**
 * @brief Tag-Length-Value
 * 
 * Mensagem codificada no formato TLV.
 */
class TLV {
    public:
        /**
         * @brief Tipos de identificadores de campos.
         */
        enum TAG {
            APPLICATION_TEMPLATE                                = 0x61,
            APPLICATION_LABEL                                   = 0x50,
            APPLICATION_IDENTIFIER                              = 0x4F,     // AID
            APPLICATION_EXPIRATION_DATE                         = 0x5F24,
            DIRECTORY_DISCRETIONARY_TEMPLATE                    = 0x73,
            FILE_CONTROL_INFORMATION_PROPRIETARY_TEMPLATE       = 0xA5,
            FILE_CONTROL_INFORMATION_TEMPLATE                   = 0x6F,     // FCI
            APPLICATION_PREFERRED_NAME                          = 0x9F12,
            LANGUAGE_PREFERENCE                                 = 0x5F2D,
            APPLICATION_PRIORITY_INDICATOR                      = 0x87,
            DEDICATED_FILE_NAME                                 = 0x84,     // DF
            ISSUER_CODE_TABLE_INDEX                             = 0x9F11,
            FILE_CONTROL_INFORMATION_ISSUER_DISCRETIONARY_DATA  = 0xBF0C,
            LOG_ENTRY                                           = 0x9F4D
        };

        /**
         * @brief Classe do elemento.
         * 
         * Valor extraído dos dois primeiros bits do campo tag.
         */
        enum Class {
            UNDEFINED           = 0b00000000,   /**< Classe indefinida. */
            APPLICATION         = 0b01000000,   /**< Classe de aplicação. */
            CONTEXT_DEPENDENT   = 0b10000000    /**< Classe de conteúdo de dados complexos. */
        };

        /**
         * @brief Tipo de dados no elemento TLV.
         * 
         * Se não for um tipo construído, será considerado como primitivo.
         */
        enum DataObject {
            PRIMITIVE       = 0b00000000,       /**< Tipo de dados primitivo (padrao). */
            CONSTRUCTED     = 0b00100000        /**< Tipo de dados complexo, construindo vários elementos. */
        };

    private:
        /**
         * @brief Identificador do tipo de campo.
         */
        int32_t tag;

        /**
         * @brief Matriz de bytes com os dados do elemento TLV.
         */
        std::vector<uint8_t> _value;

        /**
         * @brief Elementos filhos.
         * 
         * Quando o elemento corrente é um objeto complexo, formado por outros 
         * elementos TLV.
         */
        std::vector<TLV*> _childrens;
    public:
        /**
         * @brief Construtor do objeto TLV.
         */
        TLV(): tag(0) {}

        /**
         * @brief Destrutor do objeto TLV.
         */
        ~TLV();

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
         * @brief Recupera a classe do elemento corrente.
         * 
         * @return ::Class
         */
        Class getClass();

        /**
         * @brief Recupera o tipo de objetos registrado para o elemento TLV.
         * 
         * @return ::DataObject 
         */
        DataObject getDataObject();

        /**
         * @brief Recupera o campo ::value.
         * 
         * @return Matriz de bytes do campo de dados.
         */
        std::vector<uint8_t>* value() { return &_value; }

        /**
         * @brief Recupera o tamanho do campo de dados (::value).
         * 
         * @return int32_t Tamanho do campo value, em bytes.
         */
        size_t length() { return _value.size(); }

        /**
         * @brief Recupera um conjunto de elementos filhos.
         * 
         * @return std::vector<TLV*> Conjunto de elementos TVL.
         */
        std::vector<TLV*> *childrens() { return &_childrens; }
};

/**
 * @brief Pesquisa por um TLV específico em uma lista de TLV.
 * 
 * Classe utilitária com método estático.
 */
class TLVFinder {
    public:
        /**
         * @brief Localiza por um objeto TLV em uma lista de items.
         * 
         * @param[in] items Conjunto de items TLV.
         * @param[in] tag Identificador do TLV para pesquisa.
         * @return TLV TLV encontrado, ou nulo, se não o encontrar.
         */
        static TLV* find(std::vector<TLV*> items, int32_t tag);
};

#endif              // TLV_H