#pragma once

#include <iostream>
#include "../expression.h"

struct Assign {
    const char *name;
    Expression expression;
};

extern struct Machine machine;

void parse_statement(Assign *assign);