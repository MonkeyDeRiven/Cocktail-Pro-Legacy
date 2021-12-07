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
   * @brief overloads operators
   * @param overload is the overload
   * @return a reference to the storage address
   */
  CocktailPro& operator=(CocktailPro overload);
  /**
  *@brief constructor creates objects from CocktailPro
  *@return a pointer to the created object
  *@param argc is the number of command line options
  *@param turbo the individual command line options are in this array.
  *
  * those in protected variables are initialized with dynamic objects
  *
  */
  explicit CocktailPro(int argc, char ** turbo);

  /**
   * @brief
   * @param toCopyObject
   */
  CocktailPro(CocktailPro & toCopyObject);
  /**
  *@brief this method starts the process
  *
  * This method asks the user for a recipe number
  * that he should select to continue the process
  * and controls the selected number, whether it was selected sensibly or not.
  * The cocktail is also called by a method.
  */
  void start();

  /**
   * @brief this method checks which number was entered and returns the corresponding number.
   * It returns 0 if the number is not assigned to any cocktail
   *
   * @param input the input of the user
   * @param inputNumber the input of the user
   * @param max the number of cocktails
   * @return the number selected by the user
   */
  int checkInput(const std::string &input, int inputNumber) const;

  /**
   * @brief this method checks if the recipe exists and prepares it
   * @param cocktailExist bool that checks if the recipe exists
   * @param numInList number of the recipe in the list
   */
  void prepareCocktail(bool cocktailExist, int numInList);
};

#endif
