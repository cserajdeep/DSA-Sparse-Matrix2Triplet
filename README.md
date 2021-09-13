Multiply two triplets (efficient representation of a sparse matrix): <br>
```ruby
void triplet_multiply(int a[][3], int b[][3]){
  int r1,c1,d1,r2,c2,d2,i,j,k,l,flag1=0,flag2=0;
  int t1,t2,t,x,y,m;

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
```

where the inputs are two triplets a[][3] and b[][3]; the output is computed in c[][3]. <br>
Modify it according to your requirement. A star will be appreciated. <br>

# Data Structure: Sparse Matrix to Triplet Representation using C
