
#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "DeviceVerwalter.h"
#undef protected
#undef private

  class DeviceVerwalterTest : public ::testing::Test {
   protected:
    DeviceVerwalter *deviceVerwalterVec;
    VorhandeneZutaten *zutatenVecPointer;

    virtual void SetUp() {
      zutatenVecPointer = new VorhandeneZutaten();
      deviceVerwalterVec = new DeviceVerwalter(zutatenVecPointer);
      Timer *t = Timer::getInstance();
      t->set_Turbo(1000);
    }

    virtual void TearDown() {
      delete zutatenVecPointer;
      delete deviceVerwalterVec;
    }
  };

TEST_F(DeviceVerwalterTest, testForCorrectlyCreatedDevices) {
  deviceVerwalterVec->myDevices->clear();
  deviceVerwalterVec->createDevices();
  EXPECT_NE(deviceVerwalterVec->myDevices->find("Entleeren"), deviceVerwalterVec->myDevices->end());
  EXPECT_NE(deviceVerwalterVec->myDevices->find("Stampfen"), deviceVerwalterVec->myDevices->end());
  EXPECT_EQ(deviceVerwalterVec->theWaage->getDelta(), 0);
}

TEST_F(DeviceVerwalterTest, testZutatenVerwalterForCorrectIngredientStorage) {
  zutatenVecPointer->zutaten->clear();
  Ingredient* testIngredient = new Ingredient("TestZutat", 1000);
  zutatenVecPointer->zutaten->push_back(testIngredient);
  deviceVerwalterVec->setZutatenVerwalter(zutatenVecPointer);
  EXPECT_EQ(testIngredient, zutatenVecPointer->zutaten->at(0));
}

TEST_F(DeviceVerwalterTest, testIfRezeptSchrittZubereitenCovertsCorrectly) {
  float amount = 10;
  std::string testIngredient = "Wodka";
  deviceVerwalterVec->rezeptSchrittZubereiten(testIngredient, amount);
  EXPECT_GE(deviceVerwalterVec->theWaage->getDelta(), amount);

  std::string testIngredient2 = "Limettenstuecke";
  deviceVerwalterVec->rezeptSchrittZubereiten(testIngredient2, amount);
  int testSlicesMin = dynamic_cast<Dosierer*>(deviceVerwalterVec->myDevices->at(testIngredient))->getStueckProZeit();
  EXPECT_GE(deviceVerwalterVec->theWaage->getDelta(), amount * testSlicesMin);
}


