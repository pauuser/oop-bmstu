#include <iostream>

#include "Matrix.h"

int main()
{
    std::cout << "========= CONSTRUCTOR TEST =========" << std::endl;

    std::cout << "Initialiser list:" << std::endl;
    Matrix A = { {1, 2, 3}, { 4, 6, 1 } };
    std::cout << A;

    std::cout << "Filler:" << std::endl;
    int filler = 10;
    Matrix B(5, 5, filler);
    std::cout << B;

    std::cout << "No parameters:" << std::endl;
    Matrix<short> D;
    std::cout << D;

    std::cout << "No filler:" << std::endl;
    Matrix<int> E(3, 3);
    std::cout << E;

    std::cout << "Copy / move:" << std::endl;
    B = A;
    std::cout << A;
    std::cout << B;
    
    std::cout << "Diagonal matrix: " << std::endl;
    double r = -2.357;
    Matrix<double> C;
    C = Matrix<double>::DiagonalMatrix(6, r);
    std::cout << C;

    std::cout << "\n========= OPERATORS =========" << std::endl;

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

    std::cout << "\n========= BOOL =========" << std::endl;

    std::cout << "A == (should be 1) " << (bool(A)) << std::endl;
    Matrix<float> F;
    std::cout << "F == (should be 0) " << (bool(F)) << std::endl << std::endl;
    
    std::cout << "\n========= ARITHMETIC OPERATORS =========" << std::endl;

    Matrix sum1 = { {1, 2}, {3, 4} };
    Matrix sum2 = { {2, 3}, {-3, 1} };
    Matrix sum3 = { {1}, {3} };

    std::cout << "\nADD" << std::endl;
    std::cout << "Equal size:" << std::endl;
    Matrix res1 = sum1 + sum2;
    sum1.addMatrix(sum2);
    std::cout << res1;
    std::cout << sum1;
    
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
    std::cout << res1;
    std::cout << sum1;

    std::cout << "\nDIV" << std::endl;
    std::cout << "No zero devision:" << std::endl;
    sum1 = { {1, 2}, {3, 4} };
    sum2 = { {2, 3}, {-3, 1} };
    res1 = sum1 / sum2;
    sum1.divMatrix(sum2);
    std::cout << res1;
    std::cout << sum1;

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
    std::cout << res1;
    std::cout << sum1;

    sum1 = { { 0 }, { 1 } };
    res1 = sum2 * sum1;
    std::cout << res1;

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

    std::cout << "\n========= OPERATORS X= =========" << std::endl;
    sum1 = { { 1, 2 }, { 3, 4 } };
    sum2 = { { 1, 1 }, { 0, 1 } };

    std::cout << "\n+" << std::endl;
    sum1 += 5;
    std::cout << sum1;

    std::cout << "\n-" << std::endl;
    sum1 -= 5;
    std::cout << sum1;

    std::cout << "\n*" << std::endl;
    sum1 *= 5;
    std::cout << sum1;

    std::cout << "\n/" << std::endl;
    sum1 /= 5;
    std::cout << sum1;

    std::cout << "\n+ matrix" << std::endl;
    sum1 += sum2;
    std::cout << sum1;

    std::cout << "\n- matrix" << std::endl;
    sum1 -= sum2;
    std::cout << sum1;

    std::cout << "\n* matrix" << std::endl;
    sum1 *= sum2;
    std::cout << sum2;

    std::cout << "\n/ matrix" << std::endl;
    sum2 = { { 1, 1 }, { 2, 3 } };
    sum1 /= sum2;
    std::cout << sum1;

    std::cout << "\n========= DETERMINANT =========" << std::endl;

    sum1 = { { 1, 2, 4 },
             { 3, 4, 5 },
             { 1, 0, 2 } };
    std::cout << "Matrix:" << std::endl;
    std::cout << sum1;
    std::cout << "Det = " << sum1.determinant() << std::endl;

    sum1 = { { 1 } };
    std::cout << "Matrix:" << std::endl;
    std::cout << sum1;
    std::cout << "Det = " << sum1.determinant() << std::endl;

    sum1 = { { 1, 1, 1 },
             { 1, 1, 1 },
             { 1, 1, 1 } };
    std::cout << "Matrix:" << std::endl;
    std::cout << sum1;
    std::cout << "Det = " << sum1.determinant() << std::endl;

    sum1 = { { 1, 2, 4 },
             { 0, 4, 5 },
             { 0, 0, 0 } };
    std::cout << "Matrix:" << std::endl;
    std::cout << sum1;
    std::cout << "Det = " << sum1.determinant() << std::endl;

    sum1 = { { 0, 2, 4 },
             { 4, 4, 0 },
             { 2, 0, 3 } };
    std::cout << "Matrix:" << std::endl;
    std::cout << sum1;
    std::cout << "Det = " << sum1.determinant() << std::endl;

    Matrix<double> sum5 = { { 1.1, 2.3, 9.78, 3.92 },
                    { 5.6, 4.2, 43.0, -123 },
                    { 0.1, -4.3, +7., 4.444 },
                    { -5.26, -15.9, -33, 0 } };

    std::cout << "Matrix:" << std::endl;
    std::cout << sum5;
    std::cout << "Det = " << sum5.determinant() << std::endl;

    std::cout << "\n========= TRANSPOSE =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    Matrix trans1 = { { 1, 2 },
                      { 3, 4 },
                      { 5, 6 } };

    trans1.transpose();
    std::cout << trans1;

    std::cout << "---" << std::endl;
    trans1.transpose();
    std::cout << trans1;

    std::cout << "== 2 ==" << std::endl;
    Matrix trans2 = { { 1 } };
    trans2.transpose();
    std::cout << trans2;

    std::cout << "\n========= HORIZONTAL MIRROR ========= " << std::endl;

    std::cout << "== 1 ==" << std::endl;
    trans1 = { { 1, 2 },
                      { 3, 4 },
                      { 5, 6 } };
    trans1.horizontal_mirror();
    std::cout << trans1;
    std::cout << "---" << std::endl;
    trans1.horizontal_mirror();
    std::cout << trans1;

    std::cout << "== 2 ==" << std::endl;
    trans2 = { { 1 } };
    trans2.horizontal_mirror();
    std::cout << trans2;

    std::cout << "\n========= VERTICAL MIRROR =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    trans1 = { { 1, 2 },
                      { 3, 4 },
                      { 5, 6 } };
    trans1.vertical_mirror();
    std::cout << trans1;

    std::cout << "---" << std::endl;
    trans1.vertical_mirror();
    std::cout << trans1;

    std::cout << "== 2 ==" << std::endl;
    trans2 = { { 1 } };
    trans2.vertical_mirror();
    std::cout << trans2;
    
    std::cout << "\n========= ROTATE RIGHT =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    trans1 = { { 1, 2 },
               { 3, 4 },
               { 5, 6 } };
    std::cout << trans1;

    std::cout << "Rotation 1:" << std::endl;
    trans1.rotate_right();
    std::cout << trans1;

    std::cout << "Rotation 2:" << std::endl;
    trans1.rotate_right();
    std::cout << trans1;

    std::cout << "== 2 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    trans2 = { { 1 } };
    std::cout << trans2;
    
    std::cout << "Rotation 1:" << std::endl;
    trans2.rotate_right();
    std::cout << trans2;

    std::cout << "Rotation 2:" << std::endl;
    trans2.rotate_right();
    std::cout << trans2;

    std::cout << "\n========= ROTATE LEFT ========= " << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    trans1 = { { 1, 2 },
               { 3, 4 },
               { 5, 6 } };
    std::cout << trans1;

    std::cout << "Rotation 1:" << std::endl;
    trans1.rotate_left();
    std::cout << trans1;

    std::cout << "Rotation 2:" << std::endl;
    trans1.rotate_left();
    std::cout << trans1;

    std::cout << "== 2 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    trans2 = { { 1 } };
    std::cout << trans2;

    std::cout << "Rotation 1:" << std::endl;
    trans2.rotate_left();
    std::cout << trans2;

    std::cout << "Rotation 2:" << std::endl;
    trans2.rotate_left();
    std::cout << trans2;

    std::cout << "\n========= INVERSE =========" << std::endl;
    std::cout << "== 1 ==" << std::endl;

    std::cout << "Before:" << std::endl;
    Matrix<double> inv1 = { { 1.2, 5, 3 },
                            { 0, 5., 6 },
                            { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Inverse:" << std::endl;
    inv1.inverse();
    std::cout << inv1;

    std::cout << "== 2 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    Matrix<double> inv2 = { { 1.2 } };
    std::cout << inv2;

    std::cout << "Inverse:" << std::endl;

    try
    {
        inv2.inverse();
        std::cout << inv2;
    }
    catch (MatrixException& err)
    {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\n========= INSERT ROW =========" << std::endl;
    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Insert at <0>:" << std::endl;
    inv1.insertRow(0);
    std::cout << inv1;

    std::cout << "Insert at <4>:" << std::endl;
    inv1.insertRow(4);
    std::cout << inv1;

    std::cout << "Insert at <1>:" << std::endl;
    inv1.insertRow(0);
    std::cout << inv1;

    std::cout << "\n========= INSERT COL =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Insert at <0>:" << std::endl;
    inv1.insertCol(0);
    std::cout << inv1;

    std::cout << "Insert at <4>:" << std::endl;
    inv1.insertCol(4);
    std::cout << inv1;

    std::cout << "Insert at <1>:" << std::endl;
    inv1.insertCol(0);
    std::cout << inv1;

    std::cout << "\n========= DELETE COL =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Delete at <0>:" << std::endl;
    inv1.deleteCol(0);
    std::cout << inv1;

    std::cout << "Delete at <1>:" << std::endl;
    inv1.deleteCol(1);
    std::cout << inv1;

    try
    {
        std::cout << "Delete at <0>:" << std::endl;
        inv1.deleteCol(0);
        std::cout << inv1;
    }
    catch (SizeError& err)
    {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\n========= DELETE ROW =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Delete at <0>:" << std::endl;
    inv1.deleteRow(0);
    std::cout << inv1;

    std::cout << "Delete at <1>:" << std::endl;
    inv1.deleteRow(1);
    std::cout << inv1;

    try
    {
        std::cout << "Delete at <0>:" << std::endl;
        inv1.deleteRow(0);
        std::cout << inv1;
    }
    catch (SizeError& err)
    {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\n========= RESIZE =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Resize to <1, 1>" << std::endl;
    inv1.resize(1, 1);
    std::cout << inv1;

    std::cout << "Resize to <4, 5>" << std::endl;
    inv1.resize(4, 5);
    std::cout << inv1;

    std::cout << "Resize to <10, 1>" << std::endl;
    inv1.resize(10, 1);
    std::cout << inv1;

    std::cout << "\n========= RESIZE ROWS =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Resize to <1, 3>" << std::endl;
    inv1.resizeRows(1);
    std::cout << inv1;

    std::cout << "Resize to <4, 3>" << std::endl;
    inv1.resizeRows(4);
    std::cout << inv1;

    std::cout << "Resize to <10, 3>" << std::endl;
    inv1.resizeRows(10);
    std::cout << inv1;

    std::cout << "\n========= RESIZE COLUMNS =========" << std::endl;

    std::cout << "== 1 ==" << std::endl;
    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };
    std::cout << inv1;

    std::cout << "Resize to <3, 1>" << std::endl;
    inv1.resizeColumns(1);
    std::cout << inv1;

    std::cout << "Resize to <3, 4>" << std::endl;
    inv1.resizeColumns(4);
    std::cout << inv1;

    std::cout << "Resize to <3, 10>" << std::endl;
    inv1.resizeColumns(10);
    std::cout << inv1;


    std::cout << "\n============ ITERATOR =============" << std::endl;

    std::cout << "Before:" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };

    std::cout << inv1;
    std::cout << "== 1 ==" << std::endl;

    for (auto a : inv1)
    {
        std::cout << a << std::endl;
    }

    std::cout << "== 2 ==" << std::endl;

    inv1 = { { 1 } };
    for (auto a : inv1)
    {
        std::cout << a << std::endl;
    }

    std::cout << "== 3 ==" << std::endl;
    inv1 = { { 1.2, 5, 3 },
             { 0, 5., 6 },
             { 7, -2, 9 } };

    Iterator it1(inv1);

    std::cout << "inv1[0][0] = " << *it1 << std::endl;
    std::cout << "inv1[0][0] = " << it1.value() << std::endl;
    it1.next();
    std::cout << "inv1[0][1] = " << *it1 << std::endl;
    std::cout << "inv1[0][1] = " << it1.value() << std::endl;
    it1 -= 1;
    std::cout << "inv1[0][0] = " << *it1 << std::endl;
    std::cout << "inv1[0][0] = " << it1.value() << std::endl;
    it1 = it1 - 1;
    std::cout << "inv1[0][0 / -1] = " << *it1 << std::endl;
    std::cout << "inv1[0][0 / -1] = " << it1.value() << std::endl;
    std::cout << "isStart = " << it1.isStart() << std::endl;
    std::cout << "isEnd = " << it1.isEnd() << std::endl;
    it1 += 5;
    std::cout << "inv1[1][2] = " << *it1 << std::endl;
    std::cout << "inv1[1][2] = " << it1.value() << std::endl;
    std::cout << "isStart = " << it1.isStart() << std::endl;
    std::cout << "isEnd = " << it1.isEnd() << std::endl;
    it1--;
    std::cout << "inv1[1][1] = " << *it1 << std::endl;
    std::cout << "inv1[1][1] = " << it1.value() << std::endl;

    *(it1) = 1000;
    std::cout << "inv1[1][1] = " << *it1 << std::endl;
    std::cout << "inv1[1][1] = " << it1.value() << std::endl;

    std::cout << "inv1[2][2] = " << it1[6] << std::endl;
    std::cout << "inv1[2][2] = " << it1[6] << std::endl;

    it1 = Iterator(inv1, 0, 1);

    Iterator it3(inv1, 1, 2);

    std::cout << "OPERATORS OF EQUALITY " << std::endl;
    std::cout << "it1 < it2 =  " << (it1 < it3) << std::endl;
    std::cout << "it1 > it2 =  " << (it1 > it3) << std::endl;
    std::cout << "it1 >= it2 " << (it1 >= it3) << std::endl;
    std::cout << "it1 <= it2 " << (it1 <= it3) << std::endl;
    std::cout << "it1 >= it1 " << (it1 >= it1) << std::endl;
    std::cout << "it1 <= it1 " << (it1 <= it1) << std::endl;
    std::cout << "it1 == it2 " << (it1 == it3) << std::endl;
    std::cout << "it1 != it2 " << (it1 != it3) << std::endl;
    std::cout << "it1 == it1 " << (it1 == it1) << std::endl;
    std::cout << "it1 != it1 " << (it1 != it1) << std::endl;

    std::cout << "\n============= CONST ITERATOR =============" << std::endl;

    std::cout << "Before:" << std::endl;
    const Matrix<double> inv5 = { { 1.2, 5, 3 },
                            { 0, 5., 6 },
                            { 7, -2, 9 } };
    std::cout << inv5;

    std::cout << "== 1 ==" << std::endl;
    for (auto a : inv5)
    {
        std::cout << a << std::endl;
    }

    ConstIterator it2(inv5);

    std::cout << "inv1[0][0] = " << *it2 << std::endl;
    std::cout << "inv1[0][0] = " << it2.value() << std::endl;
    it2.next();
    std::cout << "inv1[0][1] = " << *it1 << std::endl;
    std::cout << "inv1[0][1] = " << it2.value() << std::endl;
    it2 -= 1;
    std::cout << "inv1[0][0] = " << *it2 << std::endl;
    std::cout << "inv1[0][0] = " << it2.value() << std::endl;
    it2 = it2 - 1;
    std::cout << "inv1[0][0 / -1] = " << *it2 << std::endl;
    std::cout << "inv1[0][0 / -1] = " << it2.value() << std::endl;
    std::cout << "isStart = " << it2.isStart() << std::endl;
    std::cout << "isEnd = " << it2.isEnd() << std::endl;
    it2 += 5;
    std::cout << "inv1[1][2] = " << *it2 << std::endl;
    std::cout << "inv1[1][2] = " << it2.value() << std::endl;
    std::cout << "isStart = " << it2.isStart() << std::endl;
    std::cout << "isEnd = " << it2.isEnd() << std::endl;
    it2--;
    std::cout << "inv1[1][1] = " << *it2 << std::endl;
    std::cout << "inv1[1][1] = " << it2.value() << std::endl;

    std::cout << "inv1[1][1] = " << *it2 << std::endl;
    std::cout << "inv1[1][1] = " << it2.value() << std::endl;

    std::cout << "inv1[2][2] = " << it2[6] << std::endl;
    std::cout << "inv1[2][2] = " << it2[6] << std::endl;

    it2 = ConstIterator(inv1, 0, 1);

    ConstIterator it4(inv5, 1, 2);

    std::cout << "OPERATORS OF EQUALITY " << std::endl;
    std::cout << "it1 < it2 =  " << (it4 < it2) << std::endl;
    std::cout << "it1 > it2 =  " << (it4 > it2) << std::endl;
    std::cout << "it1 >= it2 " << (it4 >= it2) << std::endl;
    std::cout << "it1 <= it2 " << (it4 <= it2) << std::endl;
    std::cout << "it1 >= it1 " << (it4 >= it4) << std::endl;
    std::cout << "it1 <= it1 " << (it4 <= it4) << std::endl;
    std::cout << "it1 == it2 " << (it4 == it2) << std::endl;
    std::cout << "it1 != it2 " << (it4 != it2) << std::endl;
    std::cout << "it1 == it1 " << (it4 == it4) << std::endl;
    std::cout << "it1 != it1 " << (it4 != it4) << std::endl;

    std::cout << "\n========= UNARY NEGATIVE =========" << std::endl;

    Matrix a = { { 1, 2, 3 },
                 { 0, 9, 10 } };

    std::cout << a;
    std::cout << -a;

    std::cout << "\n============= COMMUTATIVE OPERATIONS =============" << std::endl;

    Matrix nr = { { 1, -2, 44, 2 },
                  { 0, 2, 3, 54 } };

    std::cout << "Initial matrix:\n" << nr;
    std::cout << "5 + matrix:\n" << 5 + nr;
    std::cout << "5 - matrix:\n" << 5 - nr;
    std::cout << "5 * matrix:\n" << 5 * nr;

    std::cout << "abs(5 * matrix):\n" << (-(5 * nr)).abs();

    std::cout << "\n============= MULTI-TYPE OPERATIONS =============" << std::endl;
    std::cout << "++++++ 1 ++++++" << std::endl;
    Matrix<int> FA = { { 1, 2 },
                      { 3, 4 }};
    Matrix<double> P = { { 1.2, -0.8 },
                         { 3.1, 4 } };
    std::cout << FA << "+" << std::endl;
    std::cout << P << "=" << std::endl;
    std::cout << FA + P;

    std::cout << "++++++ 2 ++++++" << std::endl;
    std::cout << FA << "-" << std::endl;
    std::cout << P << "=" << std::endl;
    std::cout << FA - P;

    std::cout << "++++++ 3 ++++++" << std::endl;
    std::cout << FA << "*" << std::endl;
    std::cout << P << "=" << std::endl;
    std::cout << FA * P;

    std::cout << "++++++ 4 ++++++" << std::endl;
    std::cout << FA << "/" << std::endl;
    std::cout << P << "=" << std::endl;
    std::cout << FA / P;

    std::cout << "++++++ 5 ++++++" << std::endl;
    std::cout << P << "+" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P + FA;

    std::cout << "++++++ 6 ++++++" << std::endl;
    std::cout << P << "-" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P - FA;

    std::cout << "++++++ 7 ++++++" << std::endl;
    std::cout << P << "*" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P * FA;

    std::cout << "++++++ 8 ++++++" << std::endl;
    std::cout << P << "/" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P / FA;

    /*
    std::cout << "++++++ 9 ++++++" << std::endl;
    std::cout << FA << "dot" << std::endl;
    std::cout << P << "=" << std::endl;
    std::cout << FA.dot(P);
    */

    std::cout << "++++++ 10 ++++++" << std::endl;
    std::cout << P << "dot" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P.dot(FA);

    FA = Matrix({ { 1, 2 } , { 3, 4 }});

    std::cout << "++++++ 11 ++++++" << std::endl;
    std::cout << P << "+" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P.addMatrix(FA);

    std::cout << "++++++ 12 ++++++" << std::endl;
    std::cout << P << "-" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P.subMatrix(FA);

    std::cout << "++++++ 13 ++++++" << std::endl;
    std::cout << P << "*" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P.mulMatrix(FA);

    std::cout << "++++++ 14 ++++++" << std::endl;
    std::cout << P << "/" << std::endl;
    std::cout << FA << "=" << std::endl;
    std::cout << P.divMatrix(FA);

    std::cout << "++++++ 15 ++++++" << std::endl;
    std::cout << P << "+" << std::endl;
    std::cout << 5 << "=" << std::endl;
    std::cout << P.addElem(5);

    std::cout << "++++++ 16 ++++++" << std::endl;
    std::cout << P << "-" << std::endl;
    std::cout << 5.5 << "=" << std::endl;
    std::cout << P.subElem(5.5);

    std::cout << "++++++ 17 ++++++" << std::endl;
    std::cout << P << "*" << std::endl;
    std::cout << 10 << "=" << std::endl;
    std::cout << P.mulElem(10);

    std::cout << "+++++ 18 ++++++" << std::endl;
    std::cout << P << "/" << std::endl;
    std::cout << 10 << "=" << std::endl;
    std::cout << P.divElem(10);

    std::cout << "+++++ 19 ++++++" << std::endl;
    std::cout << P << "+" << std::endl;
    std::cout << 10 << "=" << std::endl;
    std::cout << (P += 10);

    std::cout << "+++++ 20 ++++++" << std::endl;
    std::cout << P << "-" << std::endl;
    std::cout << 10 << "=" << std::endl;
    std::cout << (P -= 10);

    std::cout << "+++++ 21 ++++++" << std::endl;
    std::cout << P << "*" << std::endl;
    std::cout << 10 << "=" << std::endl;
    std::cout << (P *= 10);

    std::cout << "+++++ 22 ++++++" << std::endl;
    std::cout << P << "/" << std::endl;
    std::cout << 10 << "=" << std::endl;
    std::cout << (P /= 10);

    return 0;
}