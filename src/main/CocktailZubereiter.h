//@(#) CocktailZubereiter.h

#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H



#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"

/**Subsystem
*@class CocktailZubereiter
*
*@brief prepares the cocktail according to the recipe steps. 
*  
*/
class CocktailZubereiter {
public:
    /**
    *@brief constructor creates objects of CocktailZubereiter
    *@param dv points to DeviceVerwalter
    *@return a pointer to the created object
    */
    explicit CocktailZubereiter(DeviceVerwalter * dv);
    /**
    *@brief this method starts the process of creating the cocktail based on a recipe.
    *@param rzpt is the recipe for the Cocktail
    *@param ingredients contains a list of ingredients and their available amounts.
    *
    *@return true
    */
    bool cocktailZubereiten(Recipe * rzpt, VorhandeneZutaten* ingredients);
    //CocktailZubereiter& operator=(CocktailZubereiter overload);

private:
  /**
 * object of boolean for not enough ingrdient
 */
  bool ausreichend = true;
  /**
  * object of DeviceVerwalter
  */
  DeviceVerwalter * myDeviceVerwalter;
  /**
   * @brief function converts the ingredient amount to the actual weight of the ingredients.
   * @param zutat is the ingredient name.
   * @param menge ist the amount of the ingredient.
   * @return the amount of the ingredients in gram.
   *
   * Adds 10 to Eis amount and multiplies Limettenstücke amount with 10.
   */
  float amountToGramm(const std::string &zutat, float menge) const;

  /**
   * @brief function cleans all devices
   * @param rzpt steps from devices which must be cleaned
   */
  void cleanUsedDevices(Recipe *rzpt) const;

  /**
   * @brief checking, if we can mix cocktail n, if not, a boolean insides turn false and provides the mixing
   * @param rzpt our recipe
   * @param ingredients our ingredients
   */
  void checkMixinPossible(Recipe * rzpt, VorhandeneZutaten* ingredients);
};

#endif
