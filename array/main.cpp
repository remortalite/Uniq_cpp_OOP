#include "Array.hpp"

#include <gtest/gtest.h>

#include <ctime>
#include <iostream>

namespace Uniq_cpp {
	namespace Array {
			namespace {
			class ArrayTest : public ::testing::Test {
				protected:
					ArrayTest() {
					}

					~ArrayTest() override {
					}

					void SetUp() override {}

					void TearDown() override {}

			};

			TEST_F(ArrayTest, defaultConstructor) {
				Arr array;
				EXPECT_EQ(array.length(), 1) << "Wrong length inside default constructor";
			}

			TEST_F(ArrayTest, intConstructor) {
				Arr array (100);
				EXPECT_EQ(array.length(), 109) << "Wrong length inside int constructor";
			}
		}
	}
}

int main(int argc, char *argv[])
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

/*
    srand(time(0));

    Arr array;
    array.fillRand(10);
    array.print();

    array.fillInc(10);
    array.print();

    array.fillDec(10);
    array.print();

    array.setRange(10, 15);
    array.fillRand(10);
    array.print();

    Arr array2 = { 1, 2, 3, 4, -5, -6, -7, -8 };
    array2.print();

    array2.checkSum();
    array2.runNumber();
*/
    return 0;
}
