////////////////////////////////////////////////////////////////////////////////
// File: matrix_x_a_matrix_transposed.c                                       //
// Routine(s):                                                                //
//    Matrix_x_a_Matrix_Transposed                                            //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  void Matrix_x_a_Matrix_Transposed(double *C, double *A, int nrows,        //
//                                         int ncols, double *B, int mrows)   //
//                                                                            //
//  Description:                                                              //
//     Post multiply the nrows x ncols matrix A by the transpose of the       //
//     mrows x ncols matrix B to form the nrows x mrows matrix C,             //
//     i.e. C = A B', where ' denotes the transpose.                          //
//     I.e. C = (Cij), where Cij = Sum (Aik Bjk) where the sum extends from   //
//     k = 0 to ncols - 1.                                                    //
//                                                                            //
//     The matrix C should be declared as double C[nrows][mrows] in the       //
//     calling routine.  The memory allocated to C should not include any     //
//     memory allocated to A or B.                                            //
//                                                                            //
//  Arguments:                                                                //
//     double *C    Pointer to the first element of the matrix C.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     int    nrows The number of rows of matrices A and C.                   //
//     int    ncols The number of columns of the matrices A and B.            //
//     double *B    Pointer to the first element of the matrix B.             //
//     int    mrows The number of rows of the matrix B and columns of the     //
//                  matrix C.                                                 //
//                                                                            //
//  Return Values:                                                            //
//     void                                                                   //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     #define M                                                              //
//     #define MB                                                             //
//     double A[M][N],  B[MB][N], C[M][MB];                                   //
//                                                                            //
//     (your code to initialize the matrices A and B)                         //
//                                                                            //
//     Matrix_x_a_Matrix_Transposed(&C[0][0], &A[0][0], M, N, &B[0][0], NB);  //
//     printf("The matrix C = AB' is \n"); ...                                //
////////////////////////////////////////////////////////////////////////////////
void Matrix_x_a_Matrix_Transposed(double *C, double *A, int nrows, int ncols,
                                                          double *B, int mrows) 
{
   int i,j,k;
   double *pA;
   double *pB;

   for (i = 0; i < nrows; A += ncols, i++) 
      for (pB = B, j = 0; j < mrows; C++, j++) 
         for (pA = A, *C = 0.0, k  = 0; k < ncols; k++) *C += *pA++ * *pB++;
}
