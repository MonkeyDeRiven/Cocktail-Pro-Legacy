//
// Created by Max on 10.12.2021.
//

#include "Ingredient.h"


Ingredient::Ingredient(std::string &newName, int newAmount) : name(newName){
  amount = newAmount;
}

std::string Ingredient::getName() {
  return name;
}

int Ingredient::getAmount() {
  return amount;
}

void Ingredient::setAmount(int newAmount) {
  this->amount = newAmount;
}
