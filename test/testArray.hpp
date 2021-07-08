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
        } // namespace
    }     // namespace Array
} // namespace Uniq_cpp

#endif // #ifndef TEST_ARRAY
