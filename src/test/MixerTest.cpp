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

class MixerTest : public ::testing::Test{
 protected:

  virtual void setup(){

  }

  virtual void tearDown(){

  }

};