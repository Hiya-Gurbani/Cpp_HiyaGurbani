#include <gtest/gtest.h>

TEST(CounterTest, IncrementIncreasesCount) {
    Counter c;

    EXPECT_EQ(c.getCount(), 0); 

    c.increment();               

    EXPECT_EQ(c.getCount(), 1);  
}

TEST(CounterTest, MultipleIncrements) {
    Counter c;

    c.increment();
    c.increment();
    c.increment();

    EXPECT_EQ(c.getCount(), 3); 
}

TEST(CounterTest, ResetSetsCountToZero) {
    Counter c;

    c.increment();
    c.increment();
    EXPECT_EQ(c.getCount(), 2);

    c.reset();                  
    EXPECT_EQ(c.getCount(), 0);
}
