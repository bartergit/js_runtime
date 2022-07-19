#include "body.h"

void execute_body(Body &body) {
    for (auto & statement: body) {
        execute_statement(statement);
    }
}
