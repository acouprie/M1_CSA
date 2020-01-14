bool present = FALSE;
for (int i=0; i<n ; i++)
    if (v[i] == looked_up_value)
        present = TRUE;

#define N 16384
int input[N]={...} ;
int output[N];
#pragma omp parallel {
    int nb;
    #pragma omp for {
    for (int i=0 ; i<N ; i++){
        nb = 0;
        for (int j=0 ; j<N ; j++)
            if (input[i] > input[j])
                nb++;
            output[nb] = input[i];
    }
    }
}


#define N 16388
typedef struct struct_element Element;
struct struct_element
{
    int value;
    Element *next;
};

int mat[N][N]= {...};
Element *list = NULL ;
bool remarkable(int value);//This function returns true if the value is remarkable

#pragma omp parallel {
    #pragma omp for {
for (int i=0 ; i<N ; i++){
    for (int j=0 ; j<N ; j++){
        if ( remarkable(mat[i][j]) ){
            // add the value to the list
            Element *new = malloc(sizeof(Element)) ;
            // We suppose malloc always returns positively
            new->value = mat[i][j] ;
            #pragma omp critical {
                new->next = list ;
                list = new ;
            }
        }
    }
}
}
}