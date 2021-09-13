#include<stdio.h>
#define ROW 10
#define COL 10
#define MAX 100

int a[ROW][COL];
int b[ROW][COL];
int c[ROW][COL];

int atrip[3][MAX];
int btrip[3][MAX];
int ctrip[3][MAX];
int dtrip[3][MAX];

void read_sparse(int mat[][COL], int row, int col){
    int i,j;
    
    printf("\nEnter %d rows X %d cols elements:\n",row,col);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        } 
    }
}

void print_sparse(int mat[][COL], int row, int col){
    int i,j;
    
    printf("\nMatrix:\n");
    for(i=0;i<row;i++){
      for(j=0;j<col;j++){ 
        printf("%4d ",mat[i][j]);
      }
      printf("\n");  
    }    
}

void read_triplet(int mat[][3])
{
  int i,t,m,n;
    
  printf("\n Enter no. of rows and columns:\n");
  scanf("%d%d",&m,&n);
  
  printf("\n No. of non-zero triples:\n");
  scanf("%d",&t);
    
  mat[0][0]=m;
  mat[0][1]=n;
  mat[0][2]=t;

  printf("\n Enter the triples(row, column, value):\n");  
  for(i=1;i<=t;i++){
    scanf("%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2]);
  }
}

void print_triplet(int mat[3][MAX], int nzero){
    int t;

    printf("\nOnly Print (Triplet):\n");
    for(t=0;t<=nzero;t++){
        printf("\n%d--%d: %d",mat[0][t],mat[1][t],mat[2][t]);
    }
}

void print_sparse_triplet(int sparseMat[][COL], int trip[3][MAX], int row, int col){
    int size = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (sparseMat[i][j] != 0)
                size++;
 
    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int tripletMatrix[3][size+1];
    
    tripletMatrix[0][0] = row;
    tripletMatrix[1][0] = col;
    tripletMatrix[2][0] = size;

    // Making of new matrix
    int k = 1;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (sparseMat[i][j] != 0)
            {
                tripletMatrix[0][k] = i;
                tripletMatrix[1][k] = j;
                tripletMatrix[2][k] = sparseMat[i][j];
                k++;
            }
    
    printf("\n Triplet Matrix:\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<=size; j++){
            printf("%4d", tripletMatrix[i][j]);
            trip[i][j] = tripletMatrix[i][j];
        }
        printf("\n");
    }
}

void mul2sparse_mat(int mat1[][COL], int mat2[][COL],  int row1, int col1, int row2, int col2){
    int i, j, k;

    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            c[i][j]=0;
            for(k=0;k<col1;k++)
              c[i][j] = c[i][j] + (mat1[i][k]*mat2[k][j]);
        }
    }
    
    printf("\nThe multiplied matrix in traditional way:\n");
    print_sparse(c, row1, col2);      
}

void multiply_triplet(int a[3][MAX], int b[3][MAX]){
  int r1,c1,d1,r2,c2,d2,i,j,k,l,flag1=0,flag2=0;
  int t1,t2,i1,j1,t,x,y,m;

  r1 = a[0][0]; 
	c1 = a[1][0]; 
	d1 = a[2][0]; 
	r2 = b[0][0]; 
	c2 = b[1][0]; 
	d2 = b[2][0]; 

  dtrip[0][0] = r1; 
  dtrip[1][0] = c2;
  
  l=1;
  t = 0;
  x = 0;
  y = 0;
  for(i=0;i<r1;i++){
    for(t1=1;t1<=d1;t1++){
      if(a[0][t1]==i){
          //printf("A:%d\t",a[2][t1]);
          
          for(j=0;j<c2;j++){
              for(t2=1;t2<=d2;t2++){
                  if(b[1][t2]==j){
                    //printf("B:%d\n",b[2][t2]);    
                    
                    for(k=0;k<c1;k++){
                        
                      if(a[1][t1]==k && b[0][t2]==k && flag1 == 0) {
                        x = a[0][t1];
                        y = b[1][t2];
                        //printf("\n%d-%d\n",x,y);
                        //printf("\n%d * %d\n",a[2][t1],b[2][t2]);
                        t = (a[2][t1]*b[2][t2]); 
                        flag1 = 1;
                      }
                      else
                        flag1 = 0;

                      if (flag1==1){
                        
                        for(m=1;m<=l;m++){
                            if(dtrip[0][m] == x && dtrip[1][m]==y){
                                dtrip[2][m] = dtrip[2][m] + t;
                                flag2 = 1;
                            }
                        }

                        if(flag2==0){
                          dtrip[0][l] = x;
                          dtrip[1][l] = y;
                          dtrip[2][l] = t;   
                          l = l + 1;
                          flag1 = 0;
                          flag2 = 0;
                          t = 0;
                        }
                        else{
                          if(l==1){
                            dtrip[2][l] = t; 
                            l = l + 1;
                          }    
                          flag1 = 0;
                          flag2 = 0;
                          t = 0;  
                        }
                      }                         
                    }
                    
                  }
              }
          }
      }  
    }  
  }
  dtrip[2][0] = l-1;
}

int main(){
  int row1, col1,row2, col2;
  printf("\nEnter the Row1 and Col1 values:\n");
  scanf("%d%d",&row1,&col1);  
  printf("\nEnter the Row2 and Col2 values:\n");
  scanf("%d%d",&row2,&col2);

  printf("\nRead Sparse Matrix1:\n");  
  read_sparse(a,row1, col1);
  printf("\nRead Sparse Matrix2:\n"); 
  read_sparse(b,row2, col2); 
  
  printf("\nPrint Sparse Matrix1:\n"); 
  print_sparse(a,row1, col1);
  print_sparse_triplet(a, atrip, row1, col1);

  printf("\nPrint Sparse Matrix2:\n"); 
  print_sparse(b,row2, col2); 
  print_sparse_triplet(b, btrip, row2, col2);
  
  //Multiplication in traditional way
  mul2sparse_mat(a, b, row1, col1, row2, col2);
  print_sparse_triplet(c, ctrip, row1, col2);
  
  //Print the respective triplets only
  print_triplet(atrip, row1*col1);
  print_triplet(btrip, row1*col1);
  print_triplet(ctrip, row1*col1);

  printf("\n***Triplet Multiplication***");
  multiply_triplet(atrip, btrip);
  print_triplet(dtrip, row1*col1);

 return 0;   
}