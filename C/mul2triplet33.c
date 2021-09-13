//Sparse Matrix Multiplication(Triplet Original) 
#include<stdio.h> 

int c[10][3];

void print_triplet(int compactMatrix[][3], int size){
    printf("\n");

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<=size; j++)
            printf("%4d ", compactMatrix[j][i]);
 
        printf("\n");
    }
}

void triplet_multiply(int a[][3], int b[][3]){
  int r1,c1,d1,r2,c2,d2,i,j,k,l,flag1=0,flag2=0;
  int t1,t2,i1,j1,t,x,y,m;

  r1 = a[0][0]; 
	c1 = a[0][1]; 
	d1 = a[0][2]; 
	r2 = b[0][0]; 
	c2 = b[0][1]; 
	d2 = b[0][2]; 

  c[0][0] = r1; 
  c[0][1] = c2;
  
  l=1;
  t = 0;
  x = 0;
  y = 0;
  for(i=0;i<r1;i++){
    for(t1=1;t1<=d1;t1++){
      if(a[t1][0]==i){
          //printf("A:%d\t",a[t1][2]);
          
          for(j=0;j<c2;j++){
              for(t2=1;t2<=d2;t2++){
                  if(b[t2][1]==j){
                    //printf("B:%d\n",b[t2][2]);    
                    
                    for(k=0;k<c1;k++){
                        
                      if(a[t1][1]==k && b[t2][0]==k && flag1 == 0) {
                        x = a[t1][0];
                        y = b[t2][1];
                        //printf("\n%d-%d\n",a[t1][0],b[t2][1]);
                        //printf("\n%d * %d\n",a[t1][2],b[t2][2]);
                        t = (a[t1][2]*b[t2][2]); 
                        flag1 = 1;
                      }
                      else
                        flag1 = 0;

                      if (flag1==1){
                        
                        for(m=1;m<=l;m++){
                            if(c[m][0] == x && c[m][1]==y){
                                c[m][2] = c[m][2] + t;
                                flag2 = 1;
                            }
                        }

                        if(flag2==0){
                          c[l][0] = x;
                          c[l][1] = y;
                          c[l][2] = t;   
                          l = l + 1;
                          flag1 = 0;
                          flag2 = 0;
                          t = 0;
                        }
                        else{
                          if(l==1){
                            c[l][2] = t; 
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
  c[0][2] = l-1;
}

int main() 
{ 
	int r1,c1,d1,r2,c2,d2,i,j,temp; 
  
	//Enter the two Sparse Matrices 
	printf("\nSparse Matrix 1:\n"); 
	int sparse1[10][3]={{3,3,9},
                      {0,0,1},
                      {0,1,2},
                      {0,2,3},
                      {1,0,4},
                      {1,1,5},
                      {1,2,6},
                      {2,0,7},
                      {2,1,8},
                      {2,2,9},};
  print_triplet(sparse1,9);
 
	printf("\nSparse Matrix 2:\n"); 
	int sparse2[10][3]={{3,3,9},
                      {0,0,1},
                      {0,1,2},
                      {0,2,3},
                      {1,0,4},
                      {1,1,5},
                      {1,2,6},
                      {2,0,7},
                      {2,1,8},
                      {2,2,9},};
	print_triplet(sparse2,9);
 
  if(3 == 3){  
    //multiply_sparse(sparse1, sparse2);
    triplet_multiply(sparse1, sparse2);
  }  
  else
    printf("\nMultiplication is not possible...!!\n");

  printf("\nThe Result is:\n");
  for(i=0;i<=c[0][2];i++) 
		printf("(i):%d--(j):%d--(value)%d\n",c[i][0],c[i][1],c[i][2]); 
 
  print_triplet(c,c[0][2]);
 
  return 0;
}