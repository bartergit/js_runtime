#include "Assign.h"
#include "../Machine.h"

void parse_statement(Assign *assign) {
    std::cout << assign->name << " VARNAME\n";
    std::cout << assign->name << " VARNAME\n";
    auto value = evaluate_expression(&assign->expression);
    std::cout << assign->name << " VARNAME\n";
    std::cout << "INFO: assign `" << assign->name << "` " << value.get<float>() << "\n";
    machine.variables[assign->name] = value;
}
