
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SomeMaterial.h"

class MaterialTest : public ::testing::Test {
protected:
    
    virtual void SetUp() {

    }

    virtual void TearDown() {
        
        
    }
};

TEST_F( MaterialTest, defaultConstructor )
{
    NanoMagnetic::SomeMaterial material;
    
    std::vector<int> v{5, 10, 15};
    ASSERT_THAT(v, testing::ElementsAre(5, 10, 15));
}

