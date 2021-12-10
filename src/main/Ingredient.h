//
// Created by Max on 10.12.2021.
//

#ifndef COCKTAILPRO_INGREDIENT_H
#define COCKTAILPRO_INGREDIENT_H

#include <string>

class Ingredient{
 private:
  std::string name;
  int amount;

 public:
  /**
   * @brief Constructor for the class Ingredient sets the name and amount of the ingredient.
   * @param newName is the name for the ingredient
   * @param newAmount is the amount available of the ingredient
   */
  Ingredient(std::string newName, int newAmount);
  /**
   * get function for the class variable name, returns the name of the ingredient.
   * @return the name of the ingredient.
   */
  std::string getName();
  /**
   * @brief get function for the class variable amount, returns the available amount of the ingredient.
   * @return the available amount of the ingredient.
   */
  int getAmount();
  /**
   * @brief set function for the class variable amount, sets the new available amount of the ingredient.
   * @param newAmount is the new available amount of the ingredient.
   */
  void setAmount(int newAmount);
};
#endif //COCKTAILPRO_INGREDIENT_H
