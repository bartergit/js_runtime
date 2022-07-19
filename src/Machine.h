#pragma once

#include <unordered_map>
#include "JsType.h"

struct Machine {
    std::unordered_map<const char *, JsValue> variables{};
};