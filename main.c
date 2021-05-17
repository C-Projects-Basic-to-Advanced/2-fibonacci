#include <stdio.h>
#include <stdlib.h>
#define N 2

// prototypes

void MultiplyMatrix(int[][N], int[][N], int[][N]);
void MultiplyMatrixVector(int[][N], int[], int[]);
void CopyMatrix(int [][N], int [][N]);
void ViewMatrix(int[][N]);

// main program

int main()

{
    int i, n, a=0;
    // create the matrices M, Aux and R. Fill in the values ​​of the matrix M
    int M[N][N] = {{0,1},{1,1}};
    int Aux[N][N], R[N][N];

    // create the v and r vectors. Fill in the values ​​of the vector v
    int v[N] = {0,1}, r[N];

    printf("Enter the desired Fibonacci number: ");
    scanf("%i", &n);

    // calculate R = M^n
    CopyMatrix(Aux,M);
    while (a<n-1)
    {
        MultiplyMatrix(M,Aux,R);
        CopyMatrix(Aux,R);
        a++;
    }
    MultiplyMatrixVector(R,v,r);
    printf("F%i = %i ",n,r[0]);

    // calculate r = R * v and shoe the first value

    return 0;

}

// sub-rotines

void MultiplyMatrix(int A[][N], int B[][N], int Resp[][N])

{
    int i, j, k;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            Resp[i][j] = 0;
            for (k=0; k<N; k++)
                Resp[i][j] += A[i][k]*B[k][j];
        }

}

void MultiplyMatrixVector(int M[][N], int v[], int resp[])

{
    //M[0][0]*v[0]+M[0][1]*v[1]
    //M[1][0]*v[0]+M[1][1]*v[1]
    int i,j;
    for(i=0; i<N; i++)
    {
        resp[i] = 0;
        for(j=0; j<N; j++)
        {
            resp[i]+=M[i][j]*v[j];
        }
    }
}

void CopyMatrix(int receive[][N], int send[][N])

{
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            receive[i][j]=send[i][j];
        }
    }
}

void ExibirMatriz(int M[][N])
{
    int i, j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
            printf("%6i\t", M[i][j]);
        printf("\n");
    }
}


