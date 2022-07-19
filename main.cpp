#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <variant>
#include "src/expression.h"
#include "src/statement.h"
#include "src/Machine.h"

#include "src/statement/Assign.h"
#include "src/statement/Branch.h"
#include "src/statement/Function.h"
#include "src/JsType.h"
#include "src/Lexer.h"

Machine machine;


int main() {
    try {
        Lexer lexer{{"let", "abb", "=", "19", "10", "+", ";"}};
        auto result = lexer.lex_statement();
        parse_statement(result);
        return 0;
    }
    catch (StatementType type) {
        std::cout << "unhandled StatementType " << type;
    }
    catch (Operator op) {
        std::cout << "unhandled Operator " << op;
    }
}
