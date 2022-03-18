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
#include "utils.h"

void TLV::setValue(std::vector<uint8_t> value) {
    this->value = value;
}

void TLV::setValue(const std::string value) {
    this->value = Utils::hex2bytes(value);
}

void TLV::setValue(const uint8_t* buffer, size_t length) {
    this->value.clear();
    this->value.reserve(length);
    for (size_t i = 0; i < length; i++) {
        this->value.push_back(buffer[i]);
    }
}

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

TLV::DataObject TLV::getDataObject() {
    // Se não for um tipo construído (complexo) é um tipo primitivo.
    if ((tag & DataObject::CONSTRUCTED) == DataObject::CONSTRUCTED) {
        return DataObject::CONSTRUCTED;
    }
    return DataObject::PRIMITIVE;
}