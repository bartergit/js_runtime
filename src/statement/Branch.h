#pragma once

#include "../statement.h"
#include "../body.h"

struct Branch {
    Expression condition;
    Body body{};
};

void parse_statement(Branch *branch);