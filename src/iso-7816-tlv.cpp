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

TLV::Class TLV::getClass() {
    // Não pode ser da classe de aplicativo e de contexto dependente ao mesmo tempo:
    // Quando ocorrer, será considerado como tipo Indefinido.
    if (    ((tag & Class::APPLICATION) == Class::APPLICATION)
        &   ((tag & Class::CONTEXT_DEPENDENT) == Class::CONTEXT_DEPENDENT)) {
        return Class::UNDEFINED;
    } else if ((tag & Class::APPLICATION) == Class::APPLICATION) {
        return Class::APPLICATION;
    } else if ((tag & Class::CONTEXT_DEPENDENT) == Class::CONTEXT_DEPENDENT) {
        return Class::CONTEXT_DEPENDENT;
    }
    // Se não caiu em nenhuma condição acima, é da classe indefinida.
    return Class::UNDEFINED;
}

void TLV::setValue(const std::string value) {
    if (value.length() % 2 != 0) {
        std::__throw_length_error(std::string("[" + value + "] Tamanho inválido.").c_str());
    }
    // TODO: Validar o formato dos dados.
    this->value = value;
}