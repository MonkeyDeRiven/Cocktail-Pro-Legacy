//@(#) CocktailZubereiter.h

#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H



#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"

/*Subsystem
*@class CocktailZubereiter
*
*@brief prepares the cocktail according to the recipe steps. 
*  
*/
class CocktailZubereiter {
public:
    /**
    *@brief constructor creates objects of CocktailZubereiter
    *@return a pointer to the created object
    *@param dv points to DeviceVerwalter 
    */
    CocktailZubereiter(DeviceVerwalter * dv);
    /**
    *@brief this method starts the process of creating the cocktail based on a recipe.
    *@param rzpt is the recipe for the Cocktail
    *
    *@return true
    */
    bool cocktailZubereiten(Recipe * rzpt);

private:
    /**
    * object of DeviceVerwalter 
    */
    DeviceVerwalter * myDeviceVerwalter;


};

#endif
