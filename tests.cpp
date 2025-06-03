/* Belan Artem Vladislavovich
./stl st135609@student.spbu.ru*/
#include "gtest/gtest.h"
#include "include/cyclic_list.hpp"

TEST(CyclicListTest, PushBackAndSize) {
    CyclicList<int> list;
    EXPECT_TRUE(list.empty());

    list.push_back(10);
    EXPECT_EQ(list.size(), 1);

    list.push_back(20);
    EXPECT_EQ(list.size(), 2);
}

TEST(CyclicListTest, IterationSum) {
    CyclicList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    int sum = 0;
    for (int val : list) {
        sum += val;
    }

    EXPECT_EQ(sum, 6);
}

TEST(CyclicListTest, PopBackWorks) {
    CyclicList<int> list;
    list.push_back(100);
    list.push_back(200);
    list.pop_back();

    EXPECT_EQ(list.size(), 1);

    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(CyclicListTest, PopBackFromEmptyThrows) {
    CyclicList<int> list;
    EXPECT_THROW(list.pop_back(), std::underflow_error);
}
