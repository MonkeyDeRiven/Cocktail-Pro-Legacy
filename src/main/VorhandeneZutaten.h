//@(#) VorhandeneZutaten.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <cstdlib> // fuer exit() unter Linux
#include <iostream>

/**
 * @class VorhandeneZutaten
 * @brief this class contains every available ingredient. It can read in ingredients from a file,
 * add new ingredients, print all ingredients, find a ingredient via index and return the amount of
 * available ingredients.
 */
class VorhandeneZutaten {

  VorhandeneZutaten& operator= (VorhandeneZutaten copy);
 public:
  /**
   * Constructor without Parameter => Standard constructor
   */
  VorhandeneZutaten();

  /**
   * copy constructor
   */
   VorhandeneZutaten(VorhandeneZutaten &original);
  /**
   * destructor for our Instances
   */
  virtual ~VorhandeneZutaten();
/**
 * @brief ???This method is called, but it happens NOTHING. (Info:Declared in vorhandeneZutaten.h)
 */
  void browse(void);

  /**
   * @brief All Ingredients have a value, what we use to get our Ingredients
   * @return is the Ingredient
   * @param i is the indicator for our Ingredients
   */
  std::string getZutat(int i);

  /**
   * @brief getter for numb. of Ingredients
   * @return we get the sum of all Ingredients
   */
  int getAnzahlVorhandeneZutaten();

 private:
  /**
   * @brief list of Ingredients
   */
  std::vector<std::string> * zutaten;

/**
 * @brief we can read our Ingredients from a given filaName
 * @param string is our fileName from where we want to read and initialize our Ingredients
 */
  virtual void ZutatenDateiEinlesen(std::string);


  int anzahlDosierer;

};
/**
 * declaring our fileName
 */
static std::string FileName;
#endif