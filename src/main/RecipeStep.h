#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
 * @class RecipeStep
 *
 * @brief RecipeStep coordinates the ingredients and their quantities
 *
 * You can set and return the values.
 *
 */
class RecipeStep {
 private:
    /**
     * object of string
     */
    std::string m_Zutat = "";

    /**
     * object of float
     */
    float m_Menge = 0;

 public:

    /**
     * @brief Constructor that initializes the variables
     */
    RecipeStep();

    /** @brief Destructor
     */
    ~RecipeStep();

    /**
     * @brief Returns the value of the ingredient
     * @return the value of the ingredient
     */
    std::string getZutat() const;

    /**
     * @brief Returns the value of the quantity of the ingredients
     * @return the value of the quantity of the ingredients
     */
    float getMenge() const;

    /**
     * @brief Set the value of the ingredient
     * @param input_m_Zutat a string for the given ingredient
     */
    void setZutat(std::string &input_m_Zutat);

    /**
     * @brief Set the value of the quantity of the ingredient
     * @param input_m_Menge a float for the given quantity of the ingredient
     */
    void setMenge(float input_m_Menge);

};
#endif
