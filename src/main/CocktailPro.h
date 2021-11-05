//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
 * Overall system
 *@class CocktailPro
 *
 *@brief CocktailPro this class initiates the start of the Program
 *
 * and it selects the recipe number
 */
class CocktailPro {
 protected:
  /**
  * object of CocktailZubereiter
  */
  CocktailZubereiter * theCocktailZubereiter;
  /**
  * object of DeviceVerwalter
  */
  DeviceVerwalter * theDeviceVerwalter;
  /**
  * object of MischbaresRezeptbuch
  */
  MischbaresRezeptbuch * theMischbaresRezeptbuch;
  /**
  * object of VorhandeneZutaten
  */
  VorhandeneZutaten * theZutatenVerwalter;

 protected:
  /**
  *@brief waehle() is used to select the recipe number
  *@return the selected recipe number or -1 to end
  *
  * and returns the first introduction
  */
  int waehle();
  /**
  *@brief demo() does the same as the method start()
  *@see start()
  *
  * but the selected recipe number is zero
  * which means the recipe name is shown and the cocktail gets prepared.
  */
  void demo();

 public:
  /**
  *@brief constructor creates objects from CocktailPro
  *@return a pointer to the created object
  *@param argc is the number of command line options
  *@param turbo the individual command line options are in this array.
  *
  * those in protected variables are initialized with dynamic objects
  *
  */
  CocktailPro(int argc, char * * turbo);
  /**
  *@brief this method starts the prozess
  *
  * This method asks the user for a recipe number
  * that he should select to continue the process
  * and controls the selected number, whether it was selected sensibly or not.
  * The cocktail is also called by a method.
  */
  void start();


};

#endif
