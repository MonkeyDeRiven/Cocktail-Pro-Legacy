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
    std::string m_Zutat;

    /**
     * object of float
     */
    float m_Menge;

 public:

    /**
     * @brief Constructor that initializes the variables
     */
    RecipeStep(void);

    /** @brief Destructor
     */
    ~RecipeStep();

    /**
     * @brief Returns the value of the ingredient
     * @return the value of the ingredient
     */
    std::string getZutat(void) const;

    /**
     * @brief Returns the value of the quantity of the ingredients
     * @return the value of the quantity of the ingredients
     */
    float getMenge(void) const;

    /**
     * @brief Set the value of the ingredient
     * @param m_Zutat a string for the given ingredient
     */
    void setZutat(std::string m_Zutat);

    /**
     * @brief Set the value of the quantity of the ingredient
     * @param m_Menge a float for the given quantity of the ingredient
     */
    void setMenge(float m_Menge);

};
#endif
