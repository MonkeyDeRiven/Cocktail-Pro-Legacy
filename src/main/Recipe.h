#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <vector>
#include <list>
#include <string>

/**
 * @class Recipe
 *
 * @brief implements a data type for recipes.
 *
 * the class holds a list with all recipe steps that are needed to mix it. It can print all steps or
 * certain single steps as well as the number of steps. It can return and set its name, and add
 * new steps to the recipe steps list.
 */

class Recipe {
private:

    /**
     *  contains a list of all recipe steps.
     */
    std::list<RecipeStep*> m_RecipeStep;

    /**
     * contains the name of the recipe
     */
    std::string m_Name;

public:

    /**
     * @brief constructor of the class, clears all recipe steps and sets the name to "".
     */
    Recipe(void);

    /**
     * @brief destructor
     */
    ~Recipe();

    /**
     * holds the number of steps needed for mixing the recipe
     */
    int getNoOfRecipeSteps();

    /**
     * @brief returns a certain step from the recipe step list.
     * @param i contains the index of the step.
     * @return a pointer of the step or NULL.
     *
     * returns null if i is bigger than the size of the recipe list, otherwise it returns the recipe
     * step, at the given index i.
     */
    RecipeStep * getRecipeStep(unsigned int i);

    /**
     * @brief returns the name of the recipe.
     * @return recipe name.
     */
    std::string getName(void) const;

    /**
     * @brief sets the name of the recipe.
     * @param Name contains the new recipe name.
     */
    void setName(const std::string& Name);

    /**
     * @brief adds a new recipe step to the recipe list.
     * @param z holds the ingredient needed for the new step.
     * @param m contains the ingredient amount needed for the new recipe.
     *
     * creates a new recipe step and assignes the ingedient needed, as well as the amount and
     * appends it to the recipe steps list.
     */
    RecipeStep* appendStep(std::string z, float m);

    /**
     * @brief prints all recipe steps
     */
    std::vector<std::string>* browse();

};

#endif
