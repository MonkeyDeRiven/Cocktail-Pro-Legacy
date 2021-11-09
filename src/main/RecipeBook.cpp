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

    r1 = new Recipe;
    r1->setName("Caipirinha");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Cachaca", 5);
    r1->appendStep("Mischen", 10);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Margarita");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Tequilla", 4);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Daiquiri");
    r1->appendStep("Limettensaft", 2);
    r1->appendStep("Zuckersirup", 2);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Planters Punch");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Grenadine", 1);
    r1->appendStep("Orangensaft", 8);
    r1->appendStep("Rum braun", 6);
    r1->appendStep("Eis", 100);
    r1->appendStep("Mischen", 20);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Caipiroska");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Wodka", 5);
    r1->appendStep("Mischen", 10);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Caipirissima");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Mischen", 10);
    this->m_Recipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Cuban Island");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Rum weiss", 2);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Eis", 30);
    r1->appendStep("Mischen", 30);
    this->m_Recipe.push_back(r1);


    r1 = new Recipe;
    r1->setName("Martini James B");
    r1->appendStep("Gin", 6);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Noilly Prat", 1);
    r1->appendStep("Schuetteln", 10);
    this->m_Recipe.push_back(r1);
    // cout << m_Liste->size() << endl;
        
        
        
        
    } else {
        // Read and output data
        std::string zeile;

        // 1. line is title - Read and throw away!
        getline(in, zeile);
        // cout << zeile << endl;

        while (getline(in, zeile)) {
          // cout << zeile << endl;
          std::istringstream inputString(zeile);
          std::string Name;
          std::string Zutat;
          std::string tempstring;
          float Menge;

          Recipe* r1;

          r1 = new Recipe;

          // Read name from istringstream with semicolon as separator
          getline(inputString, Name, ';');
          r1->setName(Name);
          //cout << "Name: " << Name << endl;

          // Continue reading to the next separator (ingredient)
          while (getline(inputString, Zutat, ';')&& !Zutat.empty()) {
              // Continue reading to the next separator (quantity)
              if (getline(inputString, tempstring, ';')) {
                  std::istringstream(tempstring) >> Menge;
              }
              r1->appendStep(Zutat, Menge);
              //cout << " Zutat: " << Zutat << " Menge: " << Menge << "\n" << endl;
          }
          this->m_Recipe.push_back(r1);
        }

        // close file
        in.close();
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