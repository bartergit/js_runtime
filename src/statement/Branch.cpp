#include "Branch.h"

void parse_statement(Branch *branch) {
    auto result = evaluate_expression(&branch->condition);
    if (result.type == NUMBER and result.get<float>() == 1) {
        execute_body(branch->body);
    }
}
