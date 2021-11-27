#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "DeviceVerwalter.h"
#undef protected
#undef private

 class DeviceVerwalterTest : public ::testing::Test{
 protected:
  DeviceVerwalter* v;

  virtual void SetUp(){
    v = new DeviceVerwalter();

  }
};


