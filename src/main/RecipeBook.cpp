/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : RecipeBook.cpp
 *
 */

#include <algorithm>

#include "RecipeBook.h"

RecipeBook::RecipeBook(void) {
    m_Recipe.clear();

    // create Stream
    std::ifstream in;

    std::string FileName = "Rezepte.csv";
    // open file
    in.open(FileName.c_str(), std::ios::in);

    if (!in) {  // File could't be opened
    Recipe* r1;

    r1 = new Recipe; //building our Recipe Caipirinha
      recipeCaipirinha(r1);

    r1 = new Recipe; //building our Recipe Margarita
      recipeMargarita(r1);

    r1 = new Recipe;//building our Recipe Daiquiri
      recipeDaiquiri(r1);

    r1 = new Recipe;//building our Recipe Planters Punch
      recipePlantersPunch(r1);

    r1 = new Recipe;//building our Recipe Caipiroska
      recipeCaipiroska(r1);

    r1 = new Recipe;//building our Recipe Caipirisima
      recipeCaipirisma(r1);

    r1 = new Recipe;//building our Cuban Island
      recipeCubanIsland(r1);

    r1 = new Recipe;//building our Recipe Martini James B
      recipeMartiniJamesB(r1);
    // cout << m_Liste->size() << endl;

    } else {
        // Read and output data
        std::string zeile;

        // 1. line is title - Read and throw away!
        getline(in, zeile);
        // cout << zeile << endl;

        addRecipes(in, zeile);

        // close file
        in.close();
    } 
}
void RecipeBook::addRecipes(std::ifstream &in, std::string &line) {
  while (std::getline(in, line)) {
    // cout << line << endl;
    std::istringstream inputString(line);
    std::string name;

    Recipe* r1;
    r1 = new Recipe;

    // Read name from istringstream with semicolon as separator
    getline(inputString, name, ';');
    r1->setName(name);
    //cout << "name: " << name << endl;

    // Continue reading to the next separator (ingredient)
    importRecipe(inputString, r1);
    m_Recipe.push_back(r1);
  }
}
void RecipeBook::importRecipe(std::istringstream &inputString, Recipe *r1) const {
  std::string ingredient;
  std::string tempString;
  float amount;
  while (std::getline(inputString, ingredient, ';')&& !ingredient.empty()) {
      // Continue reading to the next separator (quantity)
      if (std::getline(inputString, tempString, ';')) {
          std::istringstream(tempString) >> amount;
      }
      r1->appendStep(ingredient, amount);
      //cout << " ingredient: " << ingredient << " amount: " << amount << "\n" << endl;
  }
}

RecipeBook::~RecipeBook() {
   m_Recipe.clear();
}

int RecipeBook::getNumberOfRecipes() {
    return (m_Recipe.size());
}

Recipe * RecipeBook::getRecipe(unsigned int i) {
    if (i > m_Recipe.size()) return NULL;
    else {
        std::list<Recipe*>::iterator p; // Iterator
        advance(p = m_Recipe.begin(), i); // now p points to the i-th Element
        return *p; // return value of p the pointer
    }
}

bool RecipeBook::deleteRecipe(unsigned int i) {
    if (i >= m_Recipe.size()) {
        return false;
    } else {
        std::list<Recipe*>::iterator p; // Iterator
        advance(p = m_Recipe.begin(), i); // now p points to the i-th Element
        m_Recipe.erase(p); // delete the element p is pointing to
        return true; // Success!
    }
}

void RecipeBook::recipeCaipirinha(Recipe *r1) {
  r1->setName("Caipirinha");
  r1->appendStep("Limettenstuecke", 8);//We're giving the name of the Ingredient and the amount how much we need to create our Cocktail
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Cachaca", 5);
  r1->appendStep("Mischen", 10);
  this->m_Recipe.push_back(r1);//using a pointer to list as container
}

void RecipeBook::recipeMargarita(Recipe *r1) {
  r1->setName("Margarita");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Tequilla", 4);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  this->m_Recipe.push_back(r1);
}

void RecipeBook::recipeDaiquiri(Recipe *r1) {
  r1->setName("Daiquiri");
  r1->appendStep("Limettensaft", 2);
  r1->appendStep("Zuckersirup", 2);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  this->m_Recipe.push_back(r1);
}

void RecipeBook::recipePlantersPunch(Recipe *r1) {
  r1->setName("Planters Punch");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Grenadine", 1);
  r1->appendStep("Orangensaft", 8);
  r1->appendStep("Rum braun", 6);
  r1->appendStep("Eis", 100);
  r1->appendStep("Mischen", 20);
  this->m_Recipe.push_back(r1);
}

void RecipeBook::recipeCaipiroska(Recipe *r1) {
  r1->setName("Caipiroska");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Wodka", 5);
  r1->appendStep("Mischen", 10);
  this->m_Recipe.push_back(r1);
}

void RecipeBook::recipeCaipirisma(Recipe *r1) {
  r1->setName("Caipirissima");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Mischen", 10);
  this->m_Recipe.push_back(r1);
}

void RecipeBook::recipeCubanIsland(Recipe *r1) {
  r1->setName("Cuban Island");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Rum weiss", 2);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Eis", 30);
  r1->appendStep("Mischen", 30);
  this->m_Recipe.push_back(r1);
}

void RecipeBook::recipeMartiniJamesB(Recipe *r1) {
  r1->setName("Martini James B");
  r1->appendStep("Gin", 6);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Noilly Prat", 1);
  r1->appendStep("Schuetteln", 10);
  this->m_Recipe.push_back(r1);
}