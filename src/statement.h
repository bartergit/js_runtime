#pragma once

#include <vector>
#include <tuple>
#include "statement/Assign.h"
#include "statement/Branch.h"

enum StatementType {
    ASSIGN,
    BRANCH,
    FUNCTION_DECLARATION
};

typedef std::vector<std::tuple<StatementType, void *>> Body;

void execute_statement(std::tuple<StatementType, void *> statement);

