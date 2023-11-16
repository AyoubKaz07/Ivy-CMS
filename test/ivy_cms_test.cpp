#include <gtest/gtest.h>
#include "ivy_cms.h"


#define width 16
#define depth 4

TEST(CMS, Increment) {
    auto* ivy_cms = new IvyCMS(width, depth);

    int key = 120;
    int freq = 10;

    for (int i = 0; i < freq; i++) {
        ivy_cms->Increment(std::to_string(key));
    }

    EXPECT_EQ(ivy_cms->Count(std::to_string(key)), 10);
}

TEST(CMS, MinCount) {
    auto* ivy_cms = new IvyCMS(width, depth);

    std::vector<int> keys;
    int size = 100000;
    for (int i = 0 ; i < size ; i++) {
        keys.push_back(i);
    }

    for (auto key : keys) {
        ivy_cms->Increment(std::to_string(key));
    }

    int special_key = 100;
    for (int i = 0 ; i < 500; i++){
        ivy_cms->Increment(std::to_string(special_key));
    } 

    /*
     * 100 was inserted 500 times + 1
     * should expect minimum of 501 count
    */
    EXPECT_LE(501, ivy_cms->Count(std::to_string(special_key)));
}