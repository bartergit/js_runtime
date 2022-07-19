#include <iostream>
#include "expression.h"
#include "body.h"

JsValue evaluate_expression(Expression *expression) {
    if (expression->op == BIN_PLUS) {
        auto first = evaluate_expression(static_cast<Expression *>(expression->first));
        auto second = evaluate_expression(static_cast<Expression *>(expression->second));
        assert(first.type == second.type and first.type == NUMBER and "Expected number type here");
        return JsValue{NUMBER, first.get<float>() + second.get<float>()};
    }
    if (expression->op == SINGLE) {
        return *static_cast<JsValue *>(expression->first);
    }
    if (expression->op == UNARY_BRACKETS) {
        auto function = evaluate_expression(static_cast<Expression *>(expression->first));
        assert(function.type == FUNCTION && "Expected function");
        auto body = function.get<Body>();
        execute_body(body);
        return JsValue{NUMBER, 0.0f};
    }
    throw expression->op;
}
