
#include<stdio.h>

int m=1;
void print_mat(int mat[2][2]){
    int i,j;
    
    printf("\n Matrix:%d\n",m);
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){ 
        printf("%2d ",mat[i][j]);
      }
      printf("\n");  
    }    
}

void sparsemat2tripletf(int sparseMatrix[][2], int row, int col){
    int size = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (sparseMatrix[i][j] != 0)
                size++;
 
    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int compactMatrix[3][size+1];
    
    compactMatrix[0][0] = row;
    compactMatrix[1][0] = col;
    compactMatrix[2][0] = size;

    // Making of new matrix
    int k = 1;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
    
    printf("\n Triplet Matrix:%d\n",m);
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<=size; j++)
            printf("%2d ", compactMatrix[i][j]);
 
        printf("\n");
    }
}

int main(){
    int a[2][2]={{1,2},
                 {3,4}};
           
    int b[2][2]={{1,2},
                 {3,4}}; 

    int c[2][2]={0}, i, j, k;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            c[i][j]=0;
            for(k=0;k<2;k++)
              c[i][j] = c[i][j] + (a[i][k]*b[k][j]);
        }
    }      
    
    printf("\nThe Result:\n");
    print_mat(a);
    sparsemat2tripletf(a,2,2);
    m = m + 1; 
    print_mat(b);
    sparsemat2tripletf(b,2,2);
    m = m + 1; 
    print_mat(c);
    sparsemat2tripletf(c,2,2);

  return 0;  
}