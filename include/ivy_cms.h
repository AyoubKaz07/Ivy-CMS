#pragma once

#include <vector>
#include "hash_family.h"

class IvyCMS {
public:
    IvyCMS(int w, int d) : width_(w), depth_(d) {
        sketch_.resize(width_, std::vector<int>(depth_, 0));

        hash_family_ = new HashFamily(width_);
    }

    auto Increment(const std::string& key) -> void;

    auto Count(const std::string& key) -> int;

    ~IvyCMS() {
        delete hash_family_;
    }

private:
    std::vector<std::vector<int>> sketch_;  // 2D vector representing the matrix (called sketch)
    int width_;     // Width of the matrix
    int depth_;     // Depth of the matrix
    HashFamily* hash_family_;
};
