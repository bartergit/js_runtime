#pragma once

#include <iostream>
#include "../statement.h"

struct Function {
    const char *name;
    Body body;
};

void parse_statement(Function *function);

