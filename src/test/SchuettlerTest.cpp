#include "gtest/gtest.h"

#define protected public
#define private public
#include "Schuettler.h"
#undef protected
#undef private

class SchuettlerTest : public ::testing::Test {
 protected:
  Schuettler* r;

  virtual void SetUp() {
    r = new Schuettler();
  }

  virtual void TearDown() {
    delete r;
  }
};

TEST_F(SchuettlerTest,doIt) {
  //EXPECT_EQ(,);
}