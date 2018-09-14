////////////////////////////////////////////////////////////////////////////////
// File: matrix_transposed_x_the_matrix.c                                     //
// Routine(s):                                                                //
//    Matrix_Transposed_x_the_Matrix()                                        //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  void Matrix_Transposed_x_the_Matrix(double *C, double *A, int nrows,      //
//                                                                int ncols ) //
//                                                                            //
//  Description:                                                              //
//     Pre multiply an nrows x ncols matrix A by its transpose.  The result   //
//     is an ncols x ncols square symmetric matrix C, i.e. C = A' A, where '  //
//     denotes the transpose.  I.e. C = (Cij), where Cij = Sum (Aki Akj) where//
//     the sum extends from k = 0 to nrows - 1.                               //
//                                                                            //
//     The matrix C should be declared as double C[ncols][ncols] in the       //
//     calling routine.  The memory allocated to C should not include any     //
//     memory allocated to A.                                                 //
//                                                                            //
//  Arguments:                                                                //
//     double *C    Pointer to the first element of the matrix C.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     int    nrows The number of rows of matrix A.                           //
//     int    ncols The number of columns of the matrices A.                  //
//                                                                            //
//  Return Values:                                                            //
//     void                                                                   //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     #define M                                                              //
//     double A[M][N], C[N][N];                                               //
//                                                                            //
//     (your code to initialize the matrix A)                                 //
//                                                                            //
//     Matrix_Transposed_x_the_Matrix(&C[0][0], &A[0][0], M, N);              //
//     printf("The matrix C = A'A is \n"); ...                                //
////////////////////////////////////////////////////////////////////////////////
void Matrix_Transposed_x_the_Matrix(double*C, double *A, int nrows, int ncols)
{
   double *pAki;
   double *pAkj;
   double *pA0i;
   double *pCij;
   double *pCji;
   double *pCii = C;
   int i,j,k;

   for (i = 0; i < ncols; pCii += ncols + 1, i++) {
      pCji = pCii;
      pCij = pCii;
      pA0i = A + i;
      for (j = i; j < ncols; pCij++, pCji += ncols, j++) {
         pAki = pA0i;
         pAkj = A + j;
         *pCij = 0.0;
         for (k = 0; k < nrows; pAki += ncols, pAkj += ncols, k++) 
            *pCij += *pAki * *pAkj;
         *pCji = *pCij;
      }
   }
}
