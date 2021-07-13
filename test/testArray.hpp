#ifndef TEST_ARRAY
#define TEST_ARRAY

#include <libuniq/Array.hpp>

#include <gtest/gtest.h>

#include <ctime>
#include <iostream>

namespace Uniq_cpp {
    namespace Array {
        namespace {
            class ArrayTest : public ::testing::Test
            {
            protected:
                ArrayTest() {}

                ~ArrayTest() override {}

                void SetUp() override {}

                void TearDown() override {}
            };

            TEST_F(ArrayTest, defaultConstructor)
            {
                Arr array;
                EXPECT_EQ(array.length(), 0)
                    << "Wrong length inside default constructor";
            }

            TEST_F(ArrayTest, intConstructor)
            {
                Arr array(100);
                EXPECT_EQ(array.length(), 100)
                    << "Wrong length inside int constructor";
            }

            TEST_F(ArrayTest, initListConstructor)
            {
                Arr array = { 1, 2, 3, 4, 5 };
                EXPECT_EQ(array.length(), 5) << "Wrong length!";
                EXPECT_EQ(array[0], 1);
                EXPECT_EQ(array[4], 5);

                Arr array2 = {};
                EXPECT_EQ(array2.length(), 0) << "Wrong length!";
            }

            TEST_F(ArrayTest, reset)
            {
                Arr array = { 1, 2, 3, 4, 5 };

                array.reset();
                EXPECT_EQ(array.length(), 0) << "Wrong length!";
            }

            TEST_F(ArrayTest, setRange)
            {
                Arr array;
                array.setRange(5, 6);
                array.fillRand(5);
                EXPECT_EQ(array.length(), 5) << "Wrong length!";
                EXPECT_EQ(array[0], 5);
                EXPECT_EQ(array[1], 5);
                EXPECT_EQ(array[2], 5);
                EXPECT_EQ(array[3], 5);
                EXPECT_EQ(array[4], 5);
            }

            TEST_F(ArrayTest, fillRand)
            {
                Arr array;
                array.fillRand(5);
                EXPECT_EQ(array.length(), 5) << "Wrong length!";
            }

            TEST_F(ArrayTest, fillInc)
            {
                Arr array;
                array.fillInc(3);
                EXPECT_EQ(array[0], 1);
                EXPECT_EQ(array[1], 2);
                EXPECT_EQ(array[2], 3);
            }

            TEST_F(ArrayTest, fillDec)
            {
                Arr array;
                array.fillDec(3);
                EXPECT_EQ(array[0], 3);
                EXPECT_EQ(array[1], 2);
                EXPECT_EQ(array[2], 1);
            }

            TEST_F(ArrayTest, checkSum)
            {
                Arr array;
                EXPECT_EQ(array.checkSum(false), 0);

                Arr array2 = { 1 };
                EXPECT_EQ(array2.checkSum(false), 1);

                Arr array3 = { -1, 1 };
                EXPECT_EQ(array3.checkSum(false), 0);
            }

            TEST_F(ArrayTest, runNumber)
            {
                Arr array;
                EXPECT_EQ(array.runNumber(false), 0);

                Arr array2 = { 1 };
                EXPECT_EQ(array2.runNumber(false), 1);

                Arr array3 = { -1, 1 };
                EXPECT_EQ(array3.runNumber(false), 1);

                Arr array4 = { 1, -1 };
                EXPECT_EQ(array4.runNumber(false), 2);

                Arr array5 = { 1, 2, 2, 2, 3 };
                EXPECT_EQ(array5.runNumber(false), 1);

                Arr array6 = { 3, 2, 2, 2, 1 };
                EXPECT_EQ(array6.runNumber(false), 3);
            }

            TEST_F(ArrayTest, swap)
            {
                Arr array = { -1, 1 };
                array.swap(0, 1);
                EXPECT_EQ(array[0], 1);
                EXPECT_EQ(array[1], -1);

                Arr array2 = { 1, 2, 3, 4, 5 };
                array2.swap(0, 1);
                array2.swap(4, 2);
                EXPECT_EQ(array2[0], 2);
                EXPECT_EQ(array2[1], 1);
                EXPECT_EQ(array2[2], 5);
                EXPECT_EQ(array2[4], 3);
            }

            TEST_F(ArrayTest, reallocate)
            {
                Arr array = { 1, 2, 3, 4, 5 };
                array.reallocate(1);

                EXPECT_EQ(array.length(), 1);
            }

            TEST_F(ArrayTest, resize)
            {
                Arr array = { 1, 2, 3, 4, 5 };
                array.resize(4);

                EXPECT_EQ(array.length(), 4);
                EXPECT_EQ(array[3], 4);
                EXPECT_EQ(array[2], 3);

                array.resize(5);
                array[4] = 100;
                EXPECT_EQ(array.length(), 5);
                EXPECT_EQ(array[3], 4);
                EXPECT_EQ(array[4], 100);
            }
        } // namespace
    }     // namespace Array
} // namespace Uniq_cpp

#endif // #ifndef TEST_ARRAY
