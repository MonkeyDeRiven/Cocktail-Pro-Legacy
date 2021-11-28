#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Waage.h"

#undef protected
#undef private

class Waage_Test : public ::testing::Test
{protected:
  Waage *r;

  virtual void SetUp() {
    r = new Waage();
    r->changeWeight(10);
  }
  virtual void TearDown()
  {
    delete r;
  }
};

TEST_F(Waage_Test,getWeight)
{
EXPECT_EQ(r->getWeight(),10);
}

TEST_F(Waage_Test,changeWeight)
{r->changeWeight(20);
EXPECT_EQ(r->getWeight(),30);
}

TEST_F(Waage_Test,getDelta)
{

EXPECT_EQ(r->getDelta(),10);
}

TEST_F(Waage_Test, tara){
  EXPECT_EQ(0,0);
}
