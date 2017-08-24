#include "Matrix.h"

std::string Matrix3Path = "data_mat3.txt";

int main()
{
  float d = 0.0;
  Matrix<float> matrix1, matrix2, matrix3, matrix4, matrix5, matrix6, matrix7;
  unsigned rows = 2, cols = 4;

  matrix1 = Matrix<float>::RandMatrix(rows,cols);
  matrix2 = matrix1.Transpose();
  for(unsigned i = 0; i < rows; ++i)
  {
    for(unsigned j = 0; j < cols; ++j)
    {
      std::cout << matrix1.mat[i][j];
    }
  std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix1 : " << matrix1.mat.size() << "x" << matrix1.mat[0].size() << std::endl;
  std::cout << std::endl;

  for(unsigned i = 0; i < rows; ++i)
  {
    for(unsigned j = 0; j < cols; ++j)
    {
      std::cout << matrix2.mat[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix2 : " << matrix2.mat.size() << "x" << matrix2.mat[0].size() << std::endl;
  std::cout << std::endl;

  matrix3 = Matrix<float>::MultiplyMatrices(matrix1, matrix2);
  for(unsigned i = 0; i < matrix3.mat.size(); ++i)
  {
    for(unsigned j = 0; j < matrix3.mat[0].size(); ++j)
    {
      std::cout << matrix3.mat[i][j] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix3 : " << matrix3.mat.size() << "x" << matrix3.mat[0].size() << std::endl;
  std::cout << std::endl;

  matrix3.WriteMatrixToFile(Matrix3Path);
  matrix4.LoadMatrix(Matrix3Path);

  for(unsigned i = 0; i < matrix4.mat.size(); ++i)
  {
    for(unsigned j = 0; j < matrix4.mat[0].size(); ++j)
    {
      std::cout << matrix4.mat[i][j] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix4 : " << matrix4.mat.size() << "x" << matrix4.mat[0].size() << std::endl;
  std::cout << std::endl;

  matrix5 = matrix1*(3.20);
  //matrix5.MultiplyScalar(3.20);
  for(unsigned i = 0; i < matrix5.mat.size(); ++i)
  {
    for(unsigned j = 0; j < matrix5.mat[0].size(); ++j)
    {
      std::cout << matrix5.mat[i][j] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix5 : " << matrix5.mat.size() << "x" << matrix5.mat[0].size() << std::endl;
  std::cout << std::endl;

  matrix2 = matrix2*(1.23);
  //matrix2.MultiplyScalar(1.23);
  matrix6 = matrix1.Transpose() + matrix2;
  for(unsigned i = 0; i < matrix6.mat.size(); ++i)
  {
    for(unsigned j = 0; j < matrix6.mat[0].size(); ++j)
    {
      std::cout << std::fixed << std::setprecision(2) << matrix6.mat[i][j] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix6 : "  << matrix6.mat.size() << "x" << matrix6.mat[0].size() << std::endl;
  std::cout << std::endl;

  matrix7 = matrix1.SubMatrix(2, 1, 0, 0);
  for(unsigned i = 0; i < matrix7.mat.size(); ++i)
  {
    for(unsigned j = 0; j < matrix7.mat[0].size(); ++j)
    {
      std::cout << std::fixed << std::setprecision(2) << matrix7.mat[i][j] << "  ";
    }
    std::cout << std::endl;
  }

  std::cout << "Dimensions of matrix7 : "  << matrix7.mat.size() << "x" << matrix7.mat[0].size() << std::endl;
  std::cout << std::endl;


  return 0;
}
