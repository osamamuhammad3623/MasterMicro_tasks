#include <iostream>
#include <vector>
using namespace std;

/*
Description: A function to create a 1D vector that holds the 3D matrix
            - Inputs: 3D matrix size (n*m*p)
            - Outputs: 1D vector to store all elements of a matrix
*/
vector<int> craete_vector_fits_matrix(int n, int m, int p){
    vector<int> one_dim_vector(n*m*p);
    return one_dim_vector;
}

/*
Description: A function to convert 3D matrix index to 1D vector index
            - Inputs: 3D matrix indices (i, j, k) and size
            - Outputs: 1D index
*/
int access_one_dim_vector(int i, int j, int k, int n, int m, int p){
    int inner_vector_offset = j; // column index
    int middle_vector_offset = i*m; // row index: previous rows * size of row
    // assume block is a 2D vector
    // "block" index: previous blocks * (rows size * columns size)
    int outer_vector_offset = k*n*m; 
    
    // index of 1D vector: sum of all offsets: k*n*m + i*m + j
    return (outer_vector_offset + middle_vector_offset + inner_vector_offset);
}



int main(void){
    const int n=3, m= 3, p=2;

    // sample matrix: n: 3, m: 3, p: 2
    vector<vector<vector<int>>> matrix = {
        {{1,2,3},{4,5,6},{7,8,9}}, // first "block"
        {{10,11,12},{13,14,15},{16,17,18}}, // second "block"
    };

    vector<int> one_dim_vector = craete_vector_fits_matrix(n,m,p);
    cout << "size of 1D vector: " << one_dim_vector.size() << "\n";
    one_dim_vector = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    
    // we want to access second block, first row, second column
    // that is: k=1, i=0, j=1, element is --> 11
    int one_dim_index = access_one_dim_vector(0,1,1,n,m,p);
    cout << "Element at i=0, j=1, k=1 is: " << one_dim_vector[one_dim_index] << "\n";
    return 0;
}