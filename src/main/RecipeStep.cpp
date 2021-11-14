
#include <algorithm>

#include "RecipeStep.h"

RecipeStep::RecipeStep() {
}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat() const {
    return m_Zutat;
}

float RecipeStep::getMenge() const {
    return m_Menge;
}

void RecipeStep::setZutat(std::string &input_m_Zutat) {
    this->m_Zutat = input_m_Zutat;
}

void RecipeStep::setMenge(float input_m_Menge) {
    this->m_Menge = input_m_Menge;
}
