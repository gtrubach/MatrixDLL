// Matrix.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Matrix.h"

MATRIX_API CMatrix operator+(const CMatrix& m1, const CMatrix& m2)
{
	if (m1.rows != m2.rows || m1.columns != m2.columns) throw CDimensionException();

	CMatrix m_res(m1);
	m_res += m2;

	return m_res;
}

MATRIX_API CMatrix operator-(const CMatrix& m1, const CMatrix& m2)
{
	if (m1.rows != m2.rows || m1.columns != m2.columns) throw CDimensionException();

	CMatrix m_res(m1);
	m_res -= m2;

	return m_res;
}

MATRIX_API CMatrix operator*(const CMatrix& m, const short int& value)
{
	CMatrix m_res(m);
	m_res *= value;

	return m_res;
}

MATRIX_API CMatrix operator*(const short int& value, const CMatrix& m)
{
	return CMatrix(m)*value;
}

MATRIX_API std::istream& operator >> (std::istream& in, CMatrix& matrix)
{
	// TODO: insert return statement here
	size_t rows;
	size_t columns;

	in >> rows >> columns;

	if (rows <= 0 && columns <= 0) throw CDimensionException();

	if (matrix.rows != rows || matrix.columns != columns)
	{
		matrix = CMatrix(rows, columns);
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			in >> matrix.m[i][j];
		}
	}

	return in;
}

MATRIX_API std::ostream& operator<<(std::ostream& out, const CMatrix& matrix)
{
	// TODO: insert return statement here
	size_t rows = matrix.rows;
	size_t columns = matrix.columns;

	out << rows << ' ' << columns << '\n';

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			out << matrix.m[i][j];

			if (j != columns - 1) out << ' ';
		}
		if (i != rows - 1) out << '\n';
	}

	return out;
}

// This is the constructor of a class that has been exported.
// see Matrix.h for the class definition
CMatrix::CMatrix()
{
    return;
}

CMatrix::CMatrix(size_t rows, size_t columns) :rows(rows), columns(columns)
{
	if (rows <= 0 && columns <= 0) throw CDimensionException();

	m = new short int*[rows];

	for (size_t i = 0; i < rows; i++)
	{
		m[i] = new short int[columns];
	}
}

CMatrix::CMatrix(std::initializer_list<std::initializer_list<short int>> list)
{
	this->rows = list.size();
	size_t columns = (*list.begin()).size();

	for (std::initializer_list<std::initializer_list<short int>>::iterator it = list.begin(); it != list.end(); it++)
	{
		if ((*it).size() != columns) throw CDimensionException();
	}

	this->columns = columns;

	size_t i = -1;
	
	m = new short int*[this->rows];

	for (std::initializer_list<short int> columns_list : list)
	{
		size_t j = 0;

		m[++i] = new short int[this->columns];

		for (short int value : columns_list)
		{
			m[i][j++] = value;
		}
	}
}

CMatrix::CMatrix(const CMatrix& matrix) :CMatrix(matrix.rows, matrix.columns)
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->columns; j++)
		{
			this->m[i][j] = matrix.m[i][j];
		}
	}
}

CMatrix::~CMatrix()
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] m[i];
	}
	delete[] m;
}

size_t CMatrix::getRows() const
{
	return rows;
}

void CMatrix::setRows(const size_t& rows)
{
	this->rows = rows;
}

size_t CMatrix::getColumns() const
{
	return columns;
}

void CMatrix::setColumns(const size_t& columns)
{
	this->columns = columns;
}

short int*& CMatrix::operator[](const size_t& index) const
{
	// TODO: insert return statement here
	return m[index];
}

CMatrix& CMatrix::operator=(const CMatrix& matrix)
{
	// TODO: insert return statement here
	if (this != &matrix)
	{
		this->rows = matrix.rows;
		this->columns = matrix.columns;

		this->m = new short int*[this->rows];

		for (size_t i = 0; i < this->rows; i++)
		{
			this->m[i] = new short int[columns];

			for (size_t j = 0; j < this->columns; j++)
			{
				this->m[i][j] = matrix.m[i][j];
			}
		}
	}

	return *this;
}

bool CMatrix::operator==(const CMatrix& matrix) const
{
	if (this->rows != matrix.rows || this->columns != matrix.columns) return false;

	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->columns; j++)
		{
			if (this->m[i][j] != matrix.m[i][j])
				return false;
		}
	}

	return true;
}

bool CMatrix::operator!=(const CMatrix& matrix) const
{
	return !(*this == matrix);
}

CMatrix& CMatrix::operator+=(const CMatrix& matrix)
{
	// TODO: insert return statement here
	if (this->rows != matrix.rows || this->columns != matrix.columns) throw CDimensionException();

	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->columns; j++)
		{
			this->m[i][j] += matrix.m[i][j];
		}
	}

	return *this;
}

CMatrix& CMatrix::operator-=(const CMatrix& matrix)
{
	// TODO: insert return statement here
	if (this->rows != matrix.rows || this->columns != matrix.columns) throw CDimensionException();

	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->columns; j++)
		{
			this->m[i][j] -= matrix.m[i][j];
		}
	}

	return *this;
}

CMatrix& CMatrix::operator*=(const short int& value)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->columns; j++)
		{
			this->m[i][j] *= value;
		}
	}

	return *this;
}
