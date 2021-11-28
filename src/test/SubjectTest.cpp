#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Subject.h"
#include "Dosierer.h"
#include "Waage.h"
#undef protected
#undef private

class Subjecttest : public ::testing::Test
{protected:
  Waage *r3;
  Dosierer *r2;
  Subject *r;
  virtual void SetUp() {
    r3 = new Waage();
    r2 = new Dosierer(1,1,"Test3",r3);
    r = new Subject();

  }
  virtual void TearDown()
  {
    delete r2;
    delete r;
    delete r3;
  }


};

TEST_F(Subjecttest,attach)
{
r->attach(r2);
EXPECT_EQ(r->observers.size(),1);
}
TEST_F(Subjecttest,notify)
{
EXPECT_EQ(r->observers.size(),0);
}
