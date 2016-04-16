// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MATRIX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MATRIX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MATRIX_EXPORTS
#define MATRIX_API __declspec(dllexport)
#else
#define MATRIX_API __declspec(dllimport)
#endif

struct MATRIX_API CDimensionException// : public std::exception
{
	char message[80];
	CDimensionException()/* : std::exception("Bad dimensions")*/ { strcpy_s(message, "Bad dimensions"); }
};

// This class is exported from the Matrix.dll
class MATRIX_API CMatrix {
private:
	size_t rows;
	size_t columns;
	short int** m;

	CMatrix(void);
public:
	CMatrix(size_t rows, size_t columns);
	CMatrix(std::initializer_list<std::initializer_list<short int>> list);
	CMatrix(const CMatrix& matrix);
	virtual ~CMatrix();
	// TODO: add your methods here.

	size_t getRows() const;
	void setRows(const size_t& rows);

	size_t getColumns() const;
	void setColumns(const size_t& columns);

	short int*& operator[] (const size_t& index) const;

	CMatrix& operator=(const CMatrix& matrix);

	bool operator==(const CMatrix& matrix) const;
	bool operator!=(const CMatrix& matrix) const;

	CMatrix& operator+=(const CMatrix& matrix);
	CMatrix& operator-=(const CMatrix& matrix);

	CMatrix& operator*=(const short int& value);

	friend MATRIX_API CMatrix operator+(const CMatrix& m1, const CMatrix& m2);
	friend MATRIX_API CMatrix operator-(const CMatrix& m1, const CMatrix& m2);

	friend MATRIX_API CMatrix operator*(const CMatrix& m, const short int& value);
	friend MATRIX_API CMatrix operator*(const short int& value, const CMatrix& m);

	friend MATRIX_API std::istream& operator>>(std::istream& in, CMatrix& matrix);
	friend MATRIX_API std::ostream& operator<<(std::ostream& out, const CMatrix& matrix);
};