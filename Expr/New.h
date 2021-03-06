//
// Created by Igor Maximov on 11.05.2020.
//

#pragma once
#include "Expr.h"
#include <Expr/Id.h>

namespace Expr {

class New : public Expr::Base {
 public:
  explicit New(std::string class_name);
  
  void Accept(Visitor::Base *visitor) override;
 
 public:
  Class *cls{nullptr};
  std::string class_name;
};

}