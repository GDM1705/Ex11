// Copyright 2020 Golovanov

#include <gtest/gtest.h>

#include <random>

#include "train.h"

TEST(TrainTests, test1) {
    Cage* c = new Cage();
    EXPECT_EQ(c->get(), false);
    c->on();
    EXPECT_EQ(c->get(), true);
}

TEST(TrainTests, test2) {
    Cage* f = new Cage();
    Cage* s = new Cage();
    f->on();
    Train tr = Train(f, s);
    testing::internal::CaptureStdout();
    tr.printCagesState();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Number: 0; Light is on\nNumber: 1; Light is off\n");
}

TEST(TrainTests, test3) {
    Cage* f = new Cage();
    Cage* s = new Cage();
    Cage* t = new Cage();
    Cage* fo = new Cage();
    Cage* fi = new Cage();
    Cage* si = new Cage();
    Cage* se = new Cage();
    f->on();
    fi->on();
    Train tr = Train(f, s);
    tr.addCage(t, true);
    tr.addCage(fo, true);
    tr.addCage(fi, true);
    tr.addCage(si, true);
    tr.addCage(se, true);
    EXPECT_EQ(tr.findLength(), 7);
}
