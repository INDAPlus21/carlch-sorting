#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define less(a,b) ((a)<(b))
#define swap(a,b) do{char t=a; a=b; b=t;}while(0)


void insert_sort(char *l,char *r) {
  for(char *px=l+1; px<=r; px++)
    if(less(*px,*l))
      swap(*px,*l);
  for(char *px=l+2; px<=r; px++) {
    char h=*px;
    char *p=px-1;
    while(less(h,*p)) {
      *(p+1)=*p;
      p-=1;
    }
    *(p+1)=h;
    for(int i=0;i<10;i++) {
      usleep(50000);
      printf("\033[4;%dH%c ",1+(2*i),l[i]);
      fflush(stdout);
    }
  }
}

void select_sort(char *a,int len) {
  register int i,j;
  for(i=0;i<len;i++)
    for(j=i+1;j<len;j++) {
      if(*(a+i)>*(a+j))
        swap(*(a+i),*(a+j));
      for(int i=0;i<10;i++) {
        usleep(50000);
        printf("\033[7;%dH%c ",1+(2*i),a[i]);
        fflush(stdout);
      }
    }

}

void cocktail_sort(char *a,int len) {
  do{
    char flag;
    int start[2]={1,len-1},
        end[2]={len,0},
        inc[2]={1,-1};
    for(int i=0; i<2; ++i) {
      flag=1;
      for(int j=start[i]; j!=end[i]; j+=inc[i])
        if(a[j-1]>a[j]) {
          swap(a[j-1],a[j]);
          flag=0;
        }
      if(flag)
        return;
      for(int i=0;i<10;i++) {
        usleep(50000);
        printf("\033[10;%dH%c ",1+(2*i),a[i]);
        fflush(stdout);
      }
    }
  }while(1);
}

int main() {
  FILE *in = fopen("data", "rb");
  char *vals = (char*)mmap(0, 10*sizeof(int),
                  PROT_READ, MAP_FILE | MAP_PRIVATE, fileno(in),0);
  fclose(in);
  char *a = (char*)malloc(10*sizeof(char));
  char *b = (char*)malloc(10*sizeof(char));
  char *c = (char*)malloc(10*sizeof(char));
  register int i;
  for(i=0; i<10; i++) {
    a[i] = vals[i];
    b[i] = vals[i];
    c[i] = vals[i];
    printf("%c ",vals[i]);
  }
  printf("\n\n-INSERTION-SORT----\n");
  insert_sort(a, a+10-1);
  printf("\n\n-SELECTION-SORT----\n");
  select_sort(b,10);

  printf("\n\n-COCKTAIL-SORT-----\n");
  cocktail_sort(c,10);

  free(a);
  free(b);
  free(c);
  return 0;
}

