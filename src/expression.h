#pragma once

#include <cassert>
#include "JsType.h"

enum Operator {
    BIN_PLUS,
    SINGLE,
    UNARY_BRACKETS
};

struct Expression {
    Operator op;
    void *first;
    void *second;
    // if op == Single, first holds JsValue*, second is nullptr
    // if op == BIN_SOMETHING, first and second hold Expression*
    // if op == UNARY_SOMETHING, first holds Expression*, second is nullptr
};

JsValue evaluate_expression(Expression *expression);

