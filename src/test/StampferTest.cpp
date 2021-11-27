#include "gtest/gtest.h"

#define protected public
#define private public
#include "Stampfer.h"
#undef protected
#undef private

class StampferTest : public ::testing::Test {
 protected:
  Stampfer* r;

  virtual void SetUp() {
    r = new Stampfer();
  }

  virtual void TearDown() {
    delete r;
  }
};

TEST_F(StampferTest,doIt) {
  //EXPECT_EQ(,);
}