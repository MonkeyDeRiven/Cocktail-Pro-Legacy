//
// Created by arian on 23/11/2021.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Mixer.h"
#undef protected
#undef private

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Mixer.h"
#undef protected
#undef private

class MixerTest : public ::testing::Test {
 protected:
  Mixer *r;
  float turbo = 20;
  std::basic_streambuf<char> *old_buf;
  std::stringstream ss;

  virtual void SetUp() {
    old_buf = std::cout.rdbuf(ss.rdbuf());
    r = new Mixer();
    r->myTimer->set_Turbo(turbo);
  }

  virtual void TearDown() {
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
    delete r;
  }

};

TEST_F(MixerTest,doIt) {
  float t = 20;
  time_t start = time(nullptr);
  time_t msStart = start * 1000;
  r->doIt(t);
  time_t end = time(nullptr);
  time_t msEnd = end * 1000;
  float neededTime = msEnd - msStart;
  float expTime = 20000;
  EXPECT_FLOAT_EQ(neededTime*turbo, expTime);
}