#pragma once

#include <variant>

#include "statement.h"

enum JsType {
    NUMBER,
    BOOLEAN,
    OBJECT,
    FUNCTION
};

struct JsValue {
    JsType type;
    std::variant<float, Body> value;

    ~JsValue() = default;

//    template<typename T>
//    T get() {
//        return std::get<T>(value);
//    }
};