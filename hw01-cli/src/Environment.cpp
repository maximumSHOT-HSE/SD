#include "Environment.h"

Environment::Environment() : lastCommandExitCode(0) { }

void Environment::setVariableValue(const std::string &variableName, const std::string &variableValue) {
    variableNameToValue[variableName] = variableValue;
}

const std::string &Environment::getVariableValue(const std::string &variableName) {
    return variableNameToValue[variableName];
}

int Environment::getLastCommandExitCode() const {
    return lastCommandExitCode;
}

void Environment::setLastCommandExitCode(int lastCommandExitCode) {
    Environment::lastCommandExitCode = lastCommandExitCode;
}
