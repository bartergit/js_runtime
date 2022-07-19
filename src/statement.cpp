#include "statement.h"

void execute_statement(std::tuple<StatementType, void *> statement) {
    auto &[type, statement_ptr] = statement;
    switch (type) {
        case ASSIGN:
            parse_statement(static_cast<Assign *>(statement_ptr));
            break;
        case BRANCH:
            parse_statement(static_cast<Branch *>(statement_ptr));
            break;
        case FUNCTION_DECLARATION:
            parse_statement(static_cast<Function *>(statement_ptr));
            break;
        default:
            throw type;
    }
}