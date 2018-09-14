////////////////////////////////////////////////////////////////////////////////
// File: bilinear_form.c                                                      //
// Routine(s):                                                                //
//    Bilinear_Form                                                           //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  double Bilinear_Form(double u[], double *A, double v[], int n)            //
//                                                                            //
//  Description:                                                              //
//     Pre-multiply the n x n matrix A by the transpose of the column vector  //
//     u and post-multiply by the column vector v, to form the scalar u'Av.   //
//     The matrix A should be declared as "double A[n][n]" in the             //
//     calling routine.  The vector u declared as "double u[n]" and           //
//     the vector v declared as "double v[n]" in the calling routine.         //
//                                                                            //
//  Arguments:                                                                //
//     double *u    Pointer to the first element of the vector u.             //
//     double *A    Pointer to the first element of the matrix A.             //
//     double *v    Pointer to the first element of the vector v.             //
//     int    n     The number of rows and columns of the matrix A and the    //
//                  number of components of the vectors u and v.              //
//                                                                            //
//  Return Values:                                                            //
//     Product of u' A v.                                                     //
//                                                                            //
//  Example:                                                                  //
//     #define N                                                              //
//     double A[N][N],  u[N], v[N];                                           //
//     double product;                                                        //
//                                                                            //
//     (your code to initialize the matrix A, column vector u and             //
//                                                         column vector v)   //
//                                                                            //
//     product = Bilinear_Form(u, &A[0][0], v, N);                            //
//     printf("The product u'Av is \n"); ...                                  //
////////////////////////////////////////////////////////////////////////////////
double Bilinear_Form(double u[], double *A, double v[], int n) 
{
   int i,j;
   double sum_of_products = 0.0;
   double sum;

   for (i = 0; i < n; i++) {
      for (j = 0, sum = 0.0; j < n; j++, A++) sum += *A * v[j];
      sum_of_products += sum * u[i];
   }
   return sum_of_products;
}
