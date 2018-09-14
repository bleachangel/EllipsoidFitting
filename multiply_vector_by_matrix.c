////////////////////////////////////////////////////////////////////////////////
// File: multiply_vector_by_matrix.c                                          //
// Routine(s):                                                                //
//    Multiply_Vector_by_Matrix                                               //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  void Multiply_Vector_by_Matrix(double u[], double v[], double *A,         //
//                                                    int nrows, int ncols)   //
//                                                                            //
//  Description:                                                              //
//     Pre multiply the nrows x ncols matrix A by the row vector v to form    //
//     the row vector u, i.e. u = v A.                                        //
//     The matrix A should be declared as "double A[nrows][ncols]" in the     //
//     calling routine.  The vector v declared as "double v[nrows]" and       //
//     the vector u declared as "double u[ncols]" in the calling routine.     //
//                                                                            //
//  Arguments:                                                                //
//     double *u    Pointer to the first element of the vector u.             //
//     double *v    Pointer to the first element of the vector v.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     int    nrows The number of rows of the matrix A and the number of      //
//                  components of the row vector v.                           //
//     int    ncols The number of columns of the matrices A and the           //
//                  number of components of the row vector u.                 //
//                                                                            //
//  Return Values:                                                            //
//     void                                                                   //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     #define M                                                              //
//     double A[M][N],  u[N], v[M];                                           //
//                                                                            //
//     (your code to initialize the matrix A and row vector v)                //
//                                                                            //
//     Multiply_Vector_by_Matrix(u, v, &A[0][0], M, N);                       //
//     printf("The vector u is \n"); ...                                      //
////////////////////////////////////////////////////////////////////////////////
void Multiply_Vector_by_Matrix(double u[], double v[], double *A,
                                                         int nrows, int ncols) 
{
   double *pA;
   int i,j;

   for (i = 0; i < ncols; A++, i++) {
      pA = A;
      u[i] = 0.0;
      for (j = 0; j < nrows; pA += ncols, j++) u[i] += *pA * v[j];
   }
}
