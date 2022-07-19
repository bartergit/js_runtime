#include "Function.h"

#include "../Machine.h"
#include "../JsType.h"

extern struct Machine machine;

void parse_statement(Function *function) {
    machine.variables[function->name] = JsValue{OBJECT, function->body};
    std::cout << "func " << function->name << "\n";
}
