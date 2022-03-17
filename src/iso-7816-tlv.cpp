/**
 * @file iso-7816-tlv.cpp
 * @author $Author$
 * @brief Implementação de iso-7816-tlv.h.
 * @version 1.0
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 */

#include "iso-7816-tlv.h"

/**
 * @brief Máscara para identificar uma tag da classe de aplicativos.
 */
const int APPLICATION_CLASS_MASK = 0b01000000;

/**
 * @brief Máscara para identificar uma tag dependente de contexto.
 */
const int CONTEXT_DEPENDENT_CLASS_MASK = 0b10000000;

TLV::Class TLV::getClass() {
    // Não pode ser da classe de aplicativo e de contexto dependente ao mesmo tempo:
    if (    ((tag | APPLICATION_CLASS_MASK) == APPLICATION_CLASS_MASK)
        &   ((tag | CONTEXT_DEPENDENT_CLASS_MASK) == CONTEXT_DEPENDENT_CLASS_MASK)) {
        return Class::UNDEFINED;
    } else if ((tag | APPLICATION_CLASS_MASK) == APPLICATION_CLASS_MASK) {
        return Class::APPLICATION;
    } else if ((tag | CONTEXT_DEPENDENT_CLASS_MASK) == CONTEXT_DEPENDENT_CLASS_MASK) {
        return Class::CONTEXT_DEPENDENT;
    }
    // Se não caiu em nenhuma condição acima, é da classe indefinida.
    return Class::UNDEFINED;
}
