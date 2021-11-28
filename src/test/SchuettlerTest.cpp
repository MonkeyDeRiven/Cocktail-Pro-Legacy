#include "gtest/gtest.h"

#include <sys/time.h>
#define protected public
#define private public
#include "Schuettler.h"
#undef protected
#undef private

class SchuettlerTest : public ::testing::Test {
 protected:
  Schuettler* r;
  float turbo=20;
  std::basic_streambuf<char>* old_buf;
  std::stringstream ss;

  virtual void SetUp() {
    old_buf = std::cout.rdbuf(ss.rdbuf());
    r = new Schuettler();
    r->myTimer->set_Turbo(turbo);
  }

  virtual void TearDown() {
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
    delete r;
  }
};

TEST_F(SchuettlerTest,doIt) {
  float t = 20;
  time_t start = time(nullptr);
  time_t msStart = start * 1000;
  r->doIt(t);
  time_t end = time(nullptr);
  time_t msEnd = end * 1000;
  float neededTime = msEnd-msStart;
  float expTime=t*1000;
  EXPECT_FLOAT_EQ(neededTime*turbo, expTime);
}