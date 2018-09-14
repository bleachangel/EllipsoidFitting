////////////////////////////////////////////////////////////////////////////////
// File: bilinear_pairing.c                                                   //
// Routine(s):                                                                //
//    Bilinear_Pairing                                                        //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  double Bilinear_Pairing(double u[], double *A, double v[],                //
//                                                     int nrows, int ncols)  //
//                                                                            //
//  Description:                                                              //
//     Pre-multiply the nrows x ncols matrix A by the transpose of the column //
//     vector u and post-multiply by the column vector v, to form the scalar  //
//     u'Av.                                                                  //
//     The matrix A should be declared as "double A[nrows][ncols]" in the     //
//     calling routine.  The vector u declared as "double u[nrows]" and       //
//     the vector v declared as "double v[ncols]" in the calling routine.     //
//                                                                            //
//     The definition of a pairing between vector spaces V,W follows that     //
//     given by Warner in "Foundations of Differentiable Manifolds and        //
//     Lie Groups" published by Scott-Freeman and Company copywrited in 1971, //
//     Page 58.                                                               //
//     Given real vector spaces V, W a pairing of V and W is a bilinear       //
//     map B:VxW -> R.                                                        //
//                                                                            //
//  Arguments:                                                                //
//     double *u    Pointer to the first element of the vector u.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     double *v    Pointer to the first element of the vector v.             //
//     int    nrows The number of rows of the matrix A and the number of      //
//                  components of the row vector u.                           //
//     int    ncols The number of columns of the matrices A and the           //
//                  number of components of the column vector v.              //
//                                                                            //
//  Return Values:                                                            //
//     Product of u' A v.                                                     //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     #define M                                                              //
//     double A[M][N],  u[M], v[N];                                           //
//     double product;                                                        //
//                                                                            //
//     (your code to initialize the matrix A, row vector u and                //
//                                                         column vector v)   //
//                                                                            //
//     product = Bilinear_Pairing(u, &A[0][0], v, M, N);                      //
//     printf("The product u'Av is \n"); ...                                  //
////////////////////////////////////////////////////////////////////////////////
double Bilinear_Pairing(double u[], double *A, double v[],
                                                          int nrows, int ncols) 
{
   int i,j;
   double product = 0.0;
   double sum;

   for (i = 0; i < nrows; i++) {
      for (j = 0, sum = 0.0; j < ncols; j++, A++) sum += *A * v[j];
      product += sum * u[i];
   }
   return product;
}
