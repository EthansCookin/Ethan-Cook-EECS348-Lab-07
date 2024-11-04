
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(){
    //very jank way of reading in all matrix values but it works both when pasting in the values and manually importing
    cin >> data[0][0] >> data[0][1] >> data[0][2] >> data[0][3] >> 
    data[1][0] >> data[1][1] >> data[1][2] >> data[1][3] >> 
    data[2][0] >> data[2][1] >> data[2][2] >> data[2][3] >> 
    data[3][0] >> data[3][1] >> data[3][2] >> data[3][3];
    cout << endl;
  }
  
  // 2. Display a matrix
  void display() const{
    for (int i = 0; i < SIZE; i++){
      for (int j = 0; j < SIZE; j++){
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const{
    Matrix addedMatrix; //sacrificial matrix to store the values of the added matrices
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            addedMatrix.data[i][j] = int(data[i][j]) + int(other.data[i][j]);
        }
    }
    return addedMatrix;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const{
    Matrix multMatrix; //sacrificial matrix to store the values of the multiplies matrices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            multMatrix.data[i][j] = 0;
            for (int k = 0; k < SIZE;k++) {
                multMatrix.data[i][j] += int(data[i][k]) * int(other.data[k][j]);
            }
        }
    }
    return multMatrix;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    int sum = 0;
    for (int i = 0; i < SIZE; i++){
      sum  = sum + int(data[i][i]) + int(data[SIZE - i - 1][i]);
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    if (row1 < SIZE && row1 >= 0 && row2 < SIZE && row2 >= 0){ //checks if the row indexes are valid
      Matrix rowStorage;
      for (int i = 0; i < SIZE; i++){
        rowStorage.data[row1][i] = data[row1][i];
      }
      for (int i = 0; i < SIZE; i++){
        data[row1][i] = data[row2][i];
      }
      for (int i = 0; i < SIZE; i++){
        data[row2][i] = rowStorage.data[row1][i];
      }
    }
    else{ //runs if the given row indexes are invalid
      cout << "Invalid row indexes for swapping." << endl;
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter all values for Matrix 1 with each value separated by a single space:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter all values for Matrix 2 with each value separated by a single space:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
  cout << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  system("pause");
  return 0;
}