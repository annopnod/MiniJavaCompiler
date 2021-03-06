//
// Created by Igor Maximov on 03.05.2020.
//

#include "ScopeTree.h"
#include "error.h"

void ScopeTree::DefineVariable(VariableScope *layer, const std::string& variable) {
  if (!VariableDefined(variable)) {
    // Add to stack
    scope_shadowing_map_.insert({variable, std::stack<VariableScope*>()});
  }
  
  layer->DefineVariable(variable);
  scope_shadowing_map_.at(variable).push(layer);
}

VariableScope *ScopeTree::TopDefinitionLayer(const std::string& variable) {
  if (!VariableDefined(variable)) {
    ERROR("Undefined variable", "ScopeLayerTree::TopDefinitionLayer");
  }
  
  return scope_shadowing_map_.at(variable).top();
}

bool ScopeTree::VariableDefined(const std::string& variable) {
  return scope_shadowing_map_.find(variable) != scope_shadowing_map_.end()
         && !scope_shadowing_map_.at(variable).empty();
}
