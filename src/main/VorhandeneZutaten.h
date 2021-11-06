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
 *  Liest Zutaten aus Liste ein.
 *  Merkt sich in der Liste die Zutaten + Aggregatszustand.
 *
 */
class VorhandeneZutaten {
 public:
  /**
   * @class VorhandeneZutaten
   *
   * Constructor without Parameter => Standard constructor
   */
  VorhandeneZutaten(void);
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
   * @param int is the indicator for our Ingredients
   */
  std::string getZutat(int);

  /**
   * @breif getter for numb. of Ingredients
   * @return we get the sum of all Ingredients
   */
  int getAnzahlVorhandeneZutaten();

 private:
  /**
   * @brief list of Ingredients
   */
  std::vector<std::string> * zutaten;

  static const bool DEBUG = false;
/**
 * @brief if we are in DEBUG mode, we read the ingredients from zutaten.txt
 */
  void DummyZutatenEinfuegen();
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