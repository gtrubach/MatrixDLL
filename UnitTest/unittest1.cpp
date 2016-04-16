#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//operator[][]
		TEST_METHOD(MatrixSubscriptingTest)
		{
			// TODO: Your test code here
			CMatrix matrix = { { 1,2,3 } };
			
			Assert::IsTrue(matrix[0][1] == 2);
		}

		//operator==
		TEST_METHOD(MatrixEqualsTest)
		{
			// TODO: Your test code here
			CMatrix matrix1 = { { 1,2,3 } };
			CMatrix matrix2 = { { 1,2,3 } };

			Assert::IsTrue(matrix1 == matrix2);
		}

		//operator!=
		TEST_METHOD(MatrixNotEqualsTest)
		{
			// TODO: Your test code here
			CMatrix matrix1 = { { 1,2,3 } };
			CMatrix matrix2 = { { -1,-2,-3 } };

			Assert::IsTrue(matrix1 != matrix2);
		}

		//operator+=
		TEST_METHOD(MatrixSumTest1)
		{
			// TODO: Your test code here
			CMatrix matrix1 = { { 1,2,3 },{ 4,5,6 } };
			CMatrix matrix2 = { { -1,-2,-3 },{ -4,-5,-6 } };
			CMatrix matrix_res = { { 0,0,0 },{ 0,0,0 } };

			matrix1 += matrix2;

			Assert::IsTrue(matrix1 == matrix_res);
		}

		//operator-=
		TEST_METHOD(MatrixSubTest1)
		{
			// TODO: Your test code here
			CMatrix matrix1 = { { 1,2,3 },{ 4,5,6 } };
			CMatrix matrix2 = { { -9,-8,-7 },{ -6,-5,-4 } };
			CMatrix matrix_res = { { -10,-10,-10 },{ -10,-10,-10 } };

			matrix2 -= matrix1;

			Assert::IsTrue(matrix2 == matrix_res);
		}

		//operator*=
		TEST_METHOD(MatrixMulTest1)
		{
			// TODO: Your test code here
			CMatrix matrix = { { 1,2,3 },{ 4,5,6 } };
			short int value = 0;
			CMatrix matrix_res = { { 0,0,0 },{ 0,0,0 } };

			matrix *= value;

			Assert::IsTrue(matrix == matrix_res);
		}

		//operator+
		TEST_METHOD(MatrixSumTest2)
		{
			// TODO: Your test code here
			CMatrix matrix1 = { { 1,2,3 },{ 4,5,6 } };
			CMatrix matrix2 = { { 9,8,7 },{ 6,5,4 } };
			CMatrix matrix_res = { { 10,10,10 },{ 10,10,10 } };

			CMatrix sum = matrix1 + matrix2;

			Assert::IsTrue(sum == matrix_res);
		}

		//operator-
		TEST_METHOD(MatrixSubTest2)
		{
			// TODO: Your test code here
			CMatrix matrix1 = { { 1,2,3 },{ 4,5,6 } };
			CMatrix matrix2 = { { 1,2,3 },{ 4,5,6 } };
			CMatrix matrix_res = { { 0,0,0 },{ 0,0,0 } };

			CMatrix sub = matrix1 - matrix2;

			Assert::IsTrue(sub == matrix_res);
		}

		//operator* (constant on right)
		TEST_METHOD(MatrixMulTest2)
		{
			// TODO: Your test code here
			CMatrix matrix = { { 1,2,3 },{ 4,5,6 } };
			short int value = 11;
			CMatrix matrix_res = { { 11,22,33 },{ 44,55,66 } };

			CMatrix mul = matrix*value;

			Assert::IsTrue(mul == matrix_res);
		}

		//operator* (constant on left)
		TEST_METHOD(MatrixMulTest3)
		{
			// TODO: Your test code here
			CMatrix matrix = { { 1,2,3 },{ 4,5,6 } };
			short int value = -5;
			CMatrix matrix_res = { { -5,-10,-15 },{ -20,-25,-30 } };

			CMatrix mul = value*matrix;

			Assert::IsTrue(mul == matrix_res);
		}

		//operator>>
		TEST_METHOD(MatrixInTest)
		{
			// TODO: Your test code here
			char* input = "2 3\n1 2 3\n4 5 6";
			CMatrix matrix_res = { { 1,2,3 },{ 4,5,6 } };
			
			CMatrix matrix(2, 3);

			std::stringstream in(input, std::ios_base::in);
			in >> matrix;

			Assert::IsTrue(matrix == matrix_res);
		}

		//operator<<
		TEST_METHOD(MatrixOutTest)
		{
			// TODO: Your test code here
			CMatrix matrix = { { 1,2,3 },{ 4,5,6 } };
			char* expected = "2 3\n1 2 3\n4 5 6";

			std::stringstream out(std::ios_base::out);
			out << matrix;
			
			Assert::AreEqual(expected, out.str().c_str());
		}

	};
}