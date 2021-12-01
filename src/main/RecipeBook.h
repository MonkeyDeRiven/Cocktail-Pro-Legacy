#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>

#include <cstdlib> // fuer exit() unter Linux

#include <iostream>

#include <list>
#include <string>

#include "Recipe.h"

/**
 * @class RecipeBook
 *
 * @brief RecipeBook manages a collection of recipes
 *
 * A RecipeBook knows a list of recipes
 * You can ask for the number of recipes, query recipes by index
 * or delete a recipe
 *
 */
class RecipeBook {
    /**
    * This is the list of recipes that the RecipeBook manages
    *
    */
  private:
    std::list<Recipe *> m_Recipe;

  public:
    /** @brief Constructor that creates a RecipeBook
    * @return A pointer to the created RecipeBook
    *
    * This method creates a RecipeBook.
    * It uses temporarily an object of the class Initialisierer
    * to initialize the list of recipes. After that the
    * Initialisierer is destroyed.
    */
    RecipeBook(void);

    /** @brief Destructor that deletes the RecipeBook
    */
    virtual ~RecipeBook();

    /** @brief Returns the number of recipes
    * @return The number of recipes in the RecipeBook
    */
    int getNumberOfRecipes();

    /** @brief fetches the i-th recipe
    * @param [in] i a positive integer for the i-th recipe
    * @return A pointer to the requested recipe object, NULL for invalid i
    *
    * This method returns the i-th recipe;
    * where i is an integer from 0 to n-1
    * where n is the number of recipes in the RecipeBook
    */
    Recipe * getRecipe(unsigned int i);

    /** @brief Deletes the i-th recipe from the RecipeBook
    * @param [in] i a positive integer for the i-th recipe
    * @return Boolean that indicates whether the deletion was successful
    *
    * This method deletes the i-th recipe from the RecipeBook.
    * And returns true if the deletion was successful (valid i).
    * For values of i that are invalid (i <0 or i>=n) the function return false.
    */
    bool deleteRecipe(unsigned int i);
    /**
     * @brief reads a recipe from a stream.
     * @param inputString is the stream containing the recipe data.
     * @param r1 is the Recipe where the data gets stored.
     *
     * The method takes a stream as input and fills the given recipe with the ingredients and
     * amounts.
     */
    void importRecipe(std::istringstream &inputString, Recipe *r1) const;
    /**
     * @brief reads from a input filestream and fills the recipe list.
     * @param in is a input filestream, which contains all recipes together with its infos.
     * @param line is a input filestream which contains info of one single recipe.
     *
     * The method creates recipe instances and fills them with getlines. At the end it appends every
     * recipe to the recipe list.
     */
    void addRecipes(std::ifstream &in, std::string &line);

    /**
     * @brief building our Recipe Caipirinha
     * @param r1 pointer to recipe
     */
    void recipeCaipirinha(Recipe* r1);

    /**
     * @brief building our Recipe Margarita
     * @param r1 pointer to recipe
     */
    void recipeMargarita(Recipe* r1);
  /**
   * @brief building our Recipe Daiquira
   * @param r1 pointer to recipe
   */

    void recipeDaiquiri(Recipe* r1);

  /**
   * @brief building our Recipe PlantersPunch
   * @param r1 pointer to recipe
   */

    void recipePlantersPunch(Recipe* r1);
  /**
   * @brief building our Recipe Caipiroska
   * @param r1 pointer to recipe
   */

    void recipeCaipiroska(Recipe* r1);
  /**
   * @brief building our Recipe Caipirisma
   * @param r1 pointer to recipe
   */

    void recipeCaipirisma(Recipe* r1);
  /**
   * @brief building our Recipe MartinJamesB
   * @param r1 pointer to recipe
   */

    void recipeMartiniJamesB(Recipe* r1);

    /**
     * @brief building our Recipe MartinJamesB
     * @param r1 pointer to recipe
     */
    void recipeCubanIsland(Recipe* r1);

    /**
     * @brief else in our recipe building
     */
    void recipeElse(std::ifstream &in);









};

#endif
