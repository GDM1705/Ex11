// Copyright 2020 Golovanov

#include <gtest/gtest.h>

#include <random>

#include "train.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Train, test1) {
    Train train;
    EXPECT_EQ(0, train.getLenght());
}

TEST(Train, test2) {
    Train train;
    std::random_device rd;
    std::mt19937 mersenne(rd());

    for (size_t i = 0; i < 10; i++) {
        train.addCage(mersenne() % 2);
    }

    EXPECT_EQ(10, train.getLenght());
}

TEST(Train, test3) {
    Train train;
    std::random_device rd;
    std::mt19937 mersenne(rd());

    train.addCage(mersenne() % 2);

    EXPECT_EQ(1, train.getLenght());
}
