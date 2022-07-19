#pragma once

#include <vector>
#include <string>
#include <optional>
#include "expression.h"

#define VOIDED static_cast<void *>

#define CHECK(lit) \
if (check(lit)){ \
    ind = before_ind; \
    return {}; \
}

struct Lexer {
    std::vector<std::string> line;
    int ind = 0;

    bool empty() const {
        return ind >= line.size();
    }

    std::string &peek() {
        auto &temp = line.at(ind);
        ++ind;
        return temp;
    }

    std::string &lookahead() {
        return line[ind];
    }

    bool check(const char *expected) {
        auto actual = peek();
        return expected != actual;
//        assert( expected == actual && (std::string("expected ") + expected + " got " + actual).c_str());
    }

    std::optional<Assign *> lex_assign() {
        auto before_ind = ind;
        CHECK("let");
        auto var_name = peek();
        CHECK("=");
        if (auto expr = lex_expr()) {
            return new Assign{var_name.c_str(), *expr.value()};
        }
        ind = before_ind;
        return {};
    }


    std::optional<Branch *> lex_branch() {
        auto before_ind = ind;
        CHECK("if");
        CHECK("(");
        auto expr = lex_expr().value();
        CHECK(")");
        if (auto body = lex_body()) {
            return new Branch{*expr, *body};
        }
        return {};
    }

    std::tuple<StatementType, void *> lex_statement() {
        if (auto assign = lex_assign()) {
            return {ASSIGN, assign.value()};
        }
        if (auto branch = lex_branch()) {
            return {BRANCH, branch.value()};
        }
        throw "can't lex";
    }

    std::optional<Body> lex_body() {
        auto before_ind = ind;
        CHECK("{");
        Body body{};
        while (lookahead() != "}") {
            auto statement = lex_statement();
            body.push_back(statement);
        }
        peek();
        return body;
    }


    std::optional<Expression *> lex_expr() {
        std::vector<Expression *> stack = {};
        while (not empty()) {
            auto item = peek();
            if (item == ";") {
                break;
            }
            if (item == "+") {
                auto first = stack[stack.size() - 1];
                stack.pop_back();
                auto second = stack[stack.size() - 1];
                stack.pop_back();
                stack.push_back(new Expression{BIN_PLUS, VOIDED(first), VOIDED(second)});
            } else {
                auto value = new JsValue{NUMBER, std::stof(item)};
                auto expr = new Expression{SINGLE, VOIDED(value)};
                stack.push_back(expr);
            }
        }
        if (stack.size() != 1) {
            return {};
        }
        return stack[0];
    }
};