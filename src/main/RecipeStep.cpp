
#include <algorithm>

#include "RecipeStep.h"

RecipeStep::RecipeStep(void) {
    m_Zutat = "";
    m_Menge = 0;
}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat(void) const {
    return m_Zutat;
}

float RecipeStep::getMenge(void) const {
    return m_Menge;
}

void RecipeStep::setZutat(std::string input_m_Zutat) {
    this->m_Zutat = input_m_Zutat;
}

void RecipeStep::setMenge(float input_m_Menge) {
    this->m_Menge = input_m_Menge;
}
