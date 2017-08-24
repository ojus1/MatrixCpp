#ifndef MATRIX_H
#define MATRIX_H
//Created by - Surya Kant.   Last modified on 24 August 2017
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<sstream>

template <typename T> class Matrix
{
public:
  std::vector< std::vector<T> > mat;

  static Matrix<T> MultiplyMatrices(Matrix<T> &m1, Matrix<T> &m2)
  {
    Matrix<T> m; unsigned i,j,k;
  if(m1.mat[0].size() == m2.mat.size())
  {
      m.ResizeMatrix(m1.mat.size(), m2.mat[0].size());

      for(i = 0; i < m1.mat.size(); ++i)
      {
        for(j = 0; j < m2.mat[0].size(); ++j)
        {
          m.mat[i][j] = 0.0;
          for(k = 0; k < m2.mat.size(); ++k)
          {
            m.mat[i][j] = m.mat[i][j] + m1.mat[i][k] * m2.mat[k][j];
          }
        }
      }
  }
  else std::cout << "Matrices not multiplicable.";
  return m;
  }

  Matrix<T> operator-(Matrix<T> const &m1)
  {
    Matrix<T> temp;
    temp.ResizeMatrix(m1.mat.size(),m1.mat[0].size());

    for(unsigned i = 0; i < m1.mat.size(); ++i)
    {
        for(unsigned j = 0; j < m1.mat[0].size(); ++j)
        {
          temp.mat[i][j] = this->mat[i][j] - m1.mat[i][j];
        }
    }
    return temp;
  }

  Matrix<T> operator+(Matrix<T> const &m1)
  {
    Matrix<T> temp;
    temp.ResizeMatrix(m1.mat.size(),m1.mat[0].size());

    for(unsigned i = 0; i < m1.mat.size(); ++i)
    {
        for(unsigned j = 0; j < m1.mat[0].size(); ++j)
        {
          temp.mat[i][j] = this->mat[i][j] + m1.mat[i][j];
        }
    }
    return temp;
  }

  void ResizeMatrix(unsigned a, unsigned b)
  {
    mat.resize(a);
    for(unsigned i = 0; i < a; ++i) mat[i].resize(b);
  }

  static Matrix<T> RandMatrix(unsigned a, unsigned b)
  {
    Matrix<T> m;
    m.ResizeMatrix(a,b);
    for(unsigned i = 0; i < a; ++i)
        for(unsigned j = 0; j < b; ++j)
          m.mat[i][j] = std::rand()/(T)RAND_MAX ;
    return m;
  }

  Matrix<T> Transpose()
  {
    Matrix<T> m;
    if(!this->mat.empty())
    {
      m.ResizeMatrix(this->mat[0].size(), this->mat.size());
      for(unsigned i = 0; i < m.mat.size(); ++i)
        for(unsigned j = 0; j < m.mat[0].size(); ++j)
          m.mat[i][j] = this->mat[j][i];
    }
    return m;
  }

  void MultiplyScalar(T scalar)
  {
    for(unsigned i = 0; i < this->mat.size(); ++i)
        for(unsigned j = 0; j < this->mat[0].size(); ++j)
          this->mat[i][j] *= scalar;
  }

  void LoadMatrix(std::string &file)
  {
    std::string line;
    unsigned i = 0;
    char ch;
    std::ifstream myFile(file.c_str(),std::ios::in);
    while (std::getline(myFile, line))
    {
        T value;
        std::stringstream ss(line);

        this->mat.push_back(std::vector<T>());

        while (ss >> value)
        {
            this->mat[i].push_back(value);
        }
        ++i;
    }
    myFile.close();
  }

  Matrix<T> SubMatrix(unsigned r, unsigned c, unsigned a, unsigned b)
  {
    Matrix<T> temp;
    temp.ResizeMatrix(r,c);

    for(unsigned i = 0; i < temp.mat.size(); ++i)
      for(unsigned j = 0; j < temp.mat[0].size(); ++j)
          temp.mat[i][j] = this->mat[i + a][j + b];
    return temp;
  }

  void WriteMatrixToFile(std::string &file)
  {
    std::string line;
    T d;
    unsigned i,j;
    std::ofstream myFile(file.c_str(),std::ios::out);
    for(i = 0; i < this->mat.size(); ++i)
    {
      for(j = 0; j < this->mat[0].size(); ++j)
      {
        myFile << std::fixed << std::setprecision(4) << this->mat[i][j] << "  ";
      }
      myFile << std::endl;
    }
    myFile.close();
  }
  //void NormalizeMatrix(Matrix<T> &m);
};

#endif
