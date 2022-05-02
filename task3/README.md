# MasterMicro task 3
# Matrix Flatten

## 1. Problem Description
- A 3D matrix is to be stored in a 1D vector (flattened).
- The 3D matrix is of size n x m x p and is indexed by i, j, k.
- The 1D vector is of size q and is indexed by y.

## 2. Requirements
- Implement the following functions:
  1. Create a 1D vector suitable for storing the 3D matrix.
  2. Convert the 3D matrix index (i, j, k) to a suitable 1D vector index (y). Must be O(1)

### Matrix illustration with indices directions:
![Image](https://github.com/osamamuhammad3623/MasterMicro_tasks/blob/main/task3/matrix_illustration.jpg)

### How to store 3D matrix in a 1D vector (how my algorithm works):
- Assume the matrix is a vector of 2D vectors, so I fill the first 2D vector, then the second 2D vector, so on
- Each 2D vector is called Block, I named it :D .
- so I fill first block, row-by-row till the end, then the second block, and so on.
- Then, index k, which indicates to Block (in my assumption), its offset in the 1D vector can be calculated by multiplying previous blocks by their size (k * n * m).
- Within a block, the offset is calculated by previous rows by their size + the column offset (i*m +j)
