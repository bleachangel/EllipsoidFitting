////////////////////////////////////////////////////////////////////////////////
// File: multiply_matrix_by_vector.c                                          //
// Routine(s):                                                                //
//    Multiply_Matrix_by_Vector                                               //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  void Multiply_Matrix_by_Vector(double u[], double *A, int nrows,          //
//                                                   int ncols, double v[])   //
//                                                                            //
//  Description:                                                              //
//     Post multiply the nrows x ncols matrix A by the column vector v        //
//     to form the column vector u, i.e. u = A v.                             //
//     The matrix A should be declared as "double A[nrows][ncols]" in the     //
//     calling routine.  The vector v declared as "double v[ncols]" and       //
//     the vector u declared as "double u[nrows]" in the calling routine.     //
//                                                                            //
//  Arguments:                                                                //
//     double *u    Pointer to the first element of the vector u.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     int    nrows The number of rows of the matrix A and the number of      //
//                  components of the column vector u.                        //
//     int    ncols The number of columns of the matrices A and the           //
//                  number of components of the column vector v.              //
//     double *v    Pointer to the first element of the vector v.             //
//                                                                            //
//  Return Values:                                                            //
//     void                                                                   //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     #define M                                                              //
//     double A[M][N],  u[M], v[N];                                           //
//                                                                            //
//     (your code to initialize the matrix A and column vector v)             //
//                                                                            //
//     Multiply_Matrix_by_Vector(u, &A[0][0], M, N, v);                       //
//     printf("The vector u is \n"); ...                                      //
////////////////////////////////////////////////////////////////////////////////
void Multiply_Matrix_by_Vector(double u[], double *A, int nrows, int ncols,
                                                                    double v[]) 
{
   int i,j;

   for (i = 0; i < nrows; A += ncols, i++) 
      for (u[i] = 0.0, j = 0; j < ncols; j++) u[i] += A[j] * v[j];
}
