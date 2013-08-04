#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "thelonious/dsl/channel.h"

using namespace thelonious;
using namespace testing;

class ChannelTest : public Test {
public:
    void SetUp() {
        
        for (uint32_t i=0; i<constants::BLOCK_SIZE; i++) {
            ones[i] = 1.f;
            twos[i] = 2.f;
            threes[i] = 3.f;
        }
    }

    Chock ones;
    Chock twos;
    Chock threes;
};


TEST_F(ChannelTest, AddChannel) {
    Chock chock = ones + twos;
    ASSERT_THAT(chock, Each(FloatEq(3.f)));
}

TEST_F(ChannelTest, AddSample) {
    Chock chock = ones + 2.f;
    ASSERT_THAT(chock, Each(FloatEq(3.f)));
}

TEST_F(ChannelTest, AddSample2) {
    Chock chock = 2.f + ones;
    ASSERT_THAT(chock, Each(FloatEq(3.f)));
}

TEST_F(ChannelTest, AddAssignChannel) {
    Chock chock = ones;
    chock += twos;
    ASSERT_THAT(chock, Each(FloatEq(3.f)));
}

TEST_F(ChannelTest, AddAssignSample) {
    Chock chock = ones;
    chock += 2.f;
    ASSERT_THAT(chock, Each(FloatEq(3.f)));
}

TEST_F(ChannelTest, SubtractChannel) {
    Chock chock = threes - twos;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, SubtractSample) {
    Chock chock = threes - 2.f;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, SubtractSample2) {
    Chock chock = 3.f - twos;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, SubtractAssignChannel) {
    Chock chock = threes;
    chock -= twos;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, SubtractAssignSample) {
    Chock chock = threes;
    chock -= 2.f;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, MultiplyChannel) {
    Chock chock = twos * threes;
    ASSERT_THAT(chock, Each(FloatEq(6.f)));
}

TEST_F(ChannelTest, MultiplySample) {
    Chock chock = twos * 3.f;
    ASSERT_THAT(chock, Each(FloatEq(6.f)));
}

TEST_F(ChannelTest, MultiplySample2) {
    Chock chock = 3.f * twos;
    ASSERT_THAT(chock, Each(FloatEq(6.f)));
}

TEST_F(ChannelTest, MultiplyAssignChannel) {
    Chock chock = threes;
    chock *= twos;
    ASSERT_THAT(chock, Each(FloatEq(6.f)));
}

TEST_F(ChannelTest, MultiplyAssignSample) {
    Chock chock = threes;
    chock *= 2.f;
    ASSERT_THAT(chock, Each(FloatEq(6.f)));
}

TEST_F(ChannelTest, DivideChannel) {
    Chock chock = threes / twos;
    ASSERT_THAT(chock, Each(FloatEq(1.5f)));
}

TEST_F(ChannelTest, DivideSample) {
    Chock chock = threes / 2.f;
    ASSERT_THAT(chock, Each(FloatEq(1.5f)));
}

TEST_F(ChannelTest, DivideSample2) {
    Chock chock = 3.f / twos ;
    ASSERT_THAT(chock, Each(FloatEq(1.5f)));
}

TEST_F(ChannelTest, DivideAssignChannel) {
    Chock chock = threes;
    chock /= twos;
    ASSERT_THAT(chock, Each(FloatEq(1.5f)));
}

TEST_F(ChannelTest, DivideAssignSample) {
    Chock chock = threes;
    chock /= 2.f;
    ASSERT_THAT(chock, Each(FloatEq(1.5f)));
}

TEST_F(ChannelTest, ModuloChannel) {
    Chock chock = threes % twos;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, ModuloSample) {
    Chock chock = threes % 2.f;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, ModuloSample2) {
    Chock chock = 3.f % twos ;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, ModuloAssignChannel) {
    Chock chock = threes;
    chock %= twos;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}

TEST_F(ChannelTest, ModuloAssignSample) {
    Chock chock = threes;
    chock %= 2.f;
    ASSERT_THAT(chock, Each(FloatEq(1.f)));
}



int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}