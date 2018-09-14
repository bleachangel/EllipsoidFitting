////////////////////////////////////////////////////////////////////////////////
// File: matrix_transposed_x_a_matrix.c                                       //
// Routine(s):                                                                //
//    Matrix_Transposed_x_a_Matrix                                            //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  void Matrix_Transposed_x_a_Matrix(double *C, double *A, int nrows,        //
//                                         int ncols, double *B, int mcols)   //
//                                                                            //
//  Description:                                                              //
//     Post multiply the transpose of the nrows x ncols matrix A by the       //
//     nrows x mcols matrix B to form the ncols x mcols matrix C,             //
//     i.e. C = A' B, where ' denotes the transpose.                          //
//     I.e. C = (Cij), where Cij = Sum (Aki Bkj) where the sum extends        //
//     from k = 0 to nrows - 1.                                               //
//                                                                            //
//     The matrix C should be declared as double C[ncols][mcols] in the       //
//     calling routine.  The memory allocated to C should not include any     //
//     memory allocated to A or B.                                            //
//                                                                            //
//  Arguments:                                                                //
//     double *C    Pointer to the first element of the matrix C.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     int    nrows The number of rows of matrix A and the number of rows     //
//                  of the matrix B.                                          //
//     int    ncols The number of columns of the matrices A and the number    //
//                   number of rows of the matrix C.                          //
//     double *B    Pointer to the first element of the matrix B.             //
//     int    mcols The number of columns of the matrices B and C.            //
//                                                                            //
//  Return Values:                                                            //
//     void                                                                   //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     #define M                                                              //
//     #define NB                                                             //
//     double A[M][N],  B[M][NB], C[N][NB];                                   //
//                                                                            //
//     (your code to initialize the matrices A and B)                         //
//                                                                            //
//     Matrix_Transposed_x_a_Matrix(&C[0][0], &A[0][0], M, N, &B[0][0], NB);  //
//     printf("The matrix C = A'B is \n"); ...                                //
////////////////////////////////////////////////////////////////////////////////
void Matrix_Transposed_x_a_Matrix(double *C, double *A, int nrows,
                                              int ncols, double *B, int mcols) 
{
   int i,j,k;
   double *pA = A;
   double *pB;
   double *p_B;

   for (i = 0; i < ncols; A++, i++) 
      for (p_B = B, j = 0; j < mcols; C++, p_B++, j++) {
         pB = p_B;
         pA = A;
         *C = 0.0; 
         for (k = 0; k < nrows; pA += ncols, pB += mcols, k++) *C += *pA * *pB;
      }
}
