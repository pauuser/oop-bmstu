#include <iostream>

#include "Matrix.hpp"
//#include "Matrix.h"

/*
* Добавить коммутативные операции
* Операции с разными типами
*/

template <typename T>
void print_matrix(typename Matrix<T>& matr )
{
	if (matr.getRows() == 0 && matr.getColumns() == 0)
	{
		std::cout << "Empty matrix!" << std::endl;
	}
	else if (bool(matr) == 0)
	{
		std::cout << "Empty matrix! But with m = " << matr.getRows() << " n = " << matr.getColumns() << std::endl;
	}
	else
	{
		for (size_t i = 0; i < matr.getRows(); i++)
		{
			for (size_t j = 0; j < matr.getColumns(); j++)
			{
				std::cout << matr[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	std::cout << "CONSTRUCTOR TEST" << std::endl;
	std::cout << "Initialiser list:" << std::endl;
	Matrix A = { {1, 2, 3}, { 4, 6, 1 } };
	print_matrix(A);

	std::cout << "Filler:" << std::endl;
	int filler = 10;
	Matrix B(5, 5, filler);
	print_matrix(B);

	std::cout << "No parameters:" << std::endl;
	Matrix<short> D;
	print_matrix(D);

	std::cout << "No filler:" << std::endl;
	Matrix<int> E(3, 3);
	print_matrix(E);

	std::cout << "Copy / move:" << std::endl;
	B = A;
	print_matrix(A);
	print_matrix(B);
	
	std::cout << "Diagonal matrix: " << std::endl;
	double r = -2.357;
	Matrix<double> C;
	C.DiagonalMatrix(6, r);
	print_matrix(C);

	std::cout << "\nOPERATORS" << std::endl;
	std::cout << "EQUAL OPERATORS" << std::endl;
	std::cout << "A == B == (should be  true) " << (A == B) << std::endl;
	std::cout << "A == B == (should be  true) " << (A.equals(B)) << std::endl;
	std::cout << "A == A == (should be  true) " << (A == A) << std::endl;
	std::cout << "A == A == (should be  true) " << (A.equals(A)) << std::endl;
	std::cout << "A == C == (should be false) " << (A == E) << std::endl;
	std::cout << "A == C == (should be false) " << (A.equals(E)) << std::endl;

	std::cout << "UNEQUAL OPERATORS" << std::endl;
	std::cout << "A != B == (should be false) " << (A != B) << std::endl;
	std::cout << "A != B == (should be false) " << (A.unequals(B)) << std::endl;
	std::cout << "A != A == (should be false) " << (A != A) << std::endl;
	std::cout << "A != A == (should be false) " << (A.unequals(A)) << std::endl;
	std::cout << "A != C == (should be  true) " << (A != E) << std::endl;
	std::cout << "A != C == (should be  true) " << (A.unequals(E)) << std::endl;

	std::cout << "\nBOOL" << std::endl;
	std::cout << "A == (should be 1) " << (bool(A)) << std::endl;
	Matrix<float> F;
	std::cout << "F == (should be 0) " << (bool(F)) << std::endl << std::endl;

	std::cout << "\nARITHMETIC OPERATORS" << std::endl;
	Matrix sum1 = { {1, 2}, {3, 4} };
	Matrix sum2 = { {2, 3}, {-3, 1} };
	Matrix sum3 = { {1}, {3} };
	std::cout << "\nADD" << std::endl;
	std::cout << "Equal size:" << std::endl;
	Matrix res1 = sum1 + sum2;
	sum1.addMatrix(sum2);
	print_matrix(res1);
	print_matrix(sum1);
	std::cout << "Different size:" << std::endl;
	try
	{
		Matrix res2 = sum2 + sum3;
	}
	catch (SizeError& err)
	{
		std::cout << err.what() << std::endl;
	}
	try
	{
		sum2.addMatrix(sum3);
	}
	catch (SizeError& err)
	{
		std::cout << err.what() << std::endl;
	}

	std::cout << "\nSUB" << std::endl;
	res1 = sum1 + sum2;
	sum1.addMatrix(sum2);
	print_matrix(res1);
	print_matrix(sum1);

	std::cout << "\nDIV" << std::endl;
	std::cout << "No zero devision:" << std::endl;
	sum1 = { {1, 2}, {3, 4} };
	sum2 = { {2, 3}, {-3, 1} };
	res1 = sum1 / sum2;
	sum1.divMatrix(sum2);
	print_matrix(res1);
	print_matrix(sum1);
	std::cout << "Zero devision:" << std::endl;
	Matrix<int> sum4 = { { 1, 2 }, { 0,  1 } };
	try
	{
		res1 = sum1 / sum4;
	}
	catch (ZeroDivMatrix& err)
	{
		std::cout << err.what() << std::endl;
	}

	std::cout << "\nMUL" << std::endl;
	std::cout << "Appropriate size:" << std::endl;
	sum1 = { {1, 2}, {3, 4} };
	sum2 = { {2, 3}, {-3, 1} };
	res1 = sum1 * sum2;
	sum1.mulMatrix(sum2);
	print_matrix(res1);
	print_matrix(sum1);
	sum1 = { { 0 }, { 1 } };
	res1 = sum2 * sum1;
	print_matrix(res1);
	std::cout << "Inappropriate size : " << std::endl;
	sum1 = { { 1 } };
	try
	{
		res1 = sum2 * sum1;
	}
	catch (SizeError& err)
	{
		std::cout << err.what() << std::endl;
	}

	std::cout << "\nOPERATORS X=" << std::endl;
	sum1 = { { 1, 2 }, { 3, 4 } };
	sum2 = { { 1, 1 }, { 0, 1 } };

	std::cout << "\n+" << std::endl;
	sum1 += 5;
	print_matrix(sum1);

	std::cout << "\n-" << std::endl;
	sum1 -= 5;
	print_matrix(sum1);

	std::cout << "\n*" << std::endl;
	sum1 *= 5;
	print_matrix(sum1);

	std::cout << "\n/" << std::endl;
	sum1 /= 5;
	print_matrix(sum1);

	std::cout << "\n+ matrix" << std::endl;
	sum1 += sum2;
	print_matrix(sum1);

	std::cout << "\n- matrix" << std::endl;
	sum1 -= sum2;
	print_matrix(sum1);

	std::cout << "\n* matrix" << std::endl;
	sum1 *= sum2;
	print_matrix(sum2);

	std::cout << "\n/ matrix" << std::endl;
	sum2 = { { 1, 1 }, { 2, 3 } };
	sum1 /= sum2;
	print_matrix(sum1);

	std::cout << "\nDETERMINANT" << std::endl;
	sum1 = { { 1, 2, 4 },
			 { 3, 4, 5 },
			 { 1, 0, 2 } };
	std::cout << "Matrix:" << std::endl;
	print_matrix(sum1);
	std::cout << "Det = " << sum1.determinant() << std::endl;

	sum1 = { { 1 } };
	std::cout << "Matrix:" << std::endl;
	print_matrix(sum1);
	std::cout << "Det = " << sum1.determinant() << std::endl;

	sum1 = { { 1, 1, 1 },
			 { 1, 1, 1 },
			 { 1, 1, 1 } };
	std::cout << "Matrix:" << std::endl;
	print_matrix(sum1);
	std::cout << "Det = " << sum1.determinant() << std::endl;

	sum1 = { { 1, 2, 4 },
			 { 0, 4, 5 },
			 { 0, 0, 0 } };
	std::cout << "Matrix:" << std::endl;
	print_matrix(sum1);
	std::cout << "Det = " << sum1.determinant() << std::endl;

	sum1 = { { 0, 2, 4 },
			 { 4, 4, 0 },
			 { 2, 0, 3 } };
	std::cout << "Matrix:" << std::endl;
	print_matrix(sum1);
	std::cout << "Det = " << sum1.determinant() << std::endl;

	Matrix<double> sum5 = { { 1.1, 2.3, 9.78, 3.92 },
					{ 5.6, 4.2, 43.0, -123 },
					{ 0.1, -4.3, +7., 4.444 },
					{ -5.26, -15.9, -33, 0 } };
	std::cout << "Matrix:" << std::endl;
	print_matrix(sum5);
	std::cout << "Det = " << sum5.determinant() << std::endl;

	return 0 ;

}