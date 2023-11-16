#include <climits>
#include "ivy_cms.h"

auto IvyCMS::Increment(const std::string& key) -> void {
    for (int i = 0; i < depth_; i++) {
        int hash = hash_family_->hash(key, i) % width_;
        ++sketch_[hash][i];
    }
}

auto IvyCMS::Count(const std::string& key) -> int {
    int min = INT_MAX;
    for (int i = 0; i < depth_; i++) {
        size_t hash = hash_family_->hash(key, i) % width_;
        if (sketch_[hash][i] < min) {
            min = sketch_[hash][i];
        }
    }
    return min;
}