//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "VorhandeneZutaten.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux

/**
 *  @class MischbaresRezeptbuch
 *
 *  @brief contains all mixable recipes.
 *
 *  knows every mixable recipe and is able to print them.
 *  
 */
class MischbaresRezeptbuch : public RecipeBook {
public:
    /** @brief constructor of the class, checks which recipes are mixable
     *  @param ze is a list containing all available ingredients
     *
     *  this methode prints all recipes first and then checks for every recipe, if the ingredients
     *  are all available. If an ingredient is not available anymore, the recipe gets deleted from
     *  the mixable recipes list.
     */
    explicit MischbaresRezeptbuch(VorhandeneZutaten * ze);
    /** @brief prints all recipes of the recipe list.
     */
    void browse();


private:
    /**
     *  contains the ingredient manager which contains all ingredients and their amount.
     */
    VorhandeneZutaten * myZutatenVerwalter;

    /**
     *  contains every mixable recipe
     */
    std::vector<Recipe *> recipeList;

    /**
     * @brief assigns a new ingredient manager
     * @param ze contains the new ingredient manager
     */
    void setZutatenVerwalter(VorhandeneZutaten * ze);

  bool isIngredientInStock(const std::string &gesuchteZutat);
  bool isRecipeStepValid(Recipe *r);
};

#endif
