#include <iostream>
//#include <iomanip>
#include <cassert>

using namespace std;

int num=1;
struct Matrix
{
    int **data;
    int row, col;
} m3;

void createMatrix (int row, int col, int num[], Matrix& mat)
{
    mat.row = row;
    mat.col = col;

    mat.data = new int *[row];
    for(int i=0; i<row; i++)
        mat.data[i]=new int[col];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            mat.data[i][j]=num[i*col+j];
    }
}
void deleteMatrix (int sizem,Matrix mat[])
{
    for(int i=0; i<sizem; i++)
    {
        for(int j=0; j<mat[i].row; j++)
            delete[] mat[i].data[j];
        delete[] mat[i].data;
    }

    for(int i=0; i<m3.row; i++)
        delete[] m3.data[i];
    delete[] m3.data;
}
istream& operator>> (istream& input, Matrix& m)
{
    char mult;

    cout<<"Enter the Dim of the( "<<num++<< " )Matrix by adding (x or X) between them : ";
    input>>m.row>>mult>>m.col;
    assert(mult=='x'||mult=='X');    //you must cin>>x or X after first number
    cout<<endl<<endl;
    int data1[m.row*m.col];
    cout<<"Enter data of the matrix : ";
    for(int i=0; i< m.row*m.col; i++)
    {
        input>>data1[i];
    }
    system("cls");
    createMatrix(m.row,m.col,data1,m);
    return input;

}
ostream& operator<< (ostream& output, Matrix& m)
{
    output<<"Matrix as follows ("<<m.row<<"x"<<m.col<<")"<<endl;
    for(int i=0; i<m.row; i++)
    {
        for(int j=0; j<m.col; j++)
            output<<m.data[i][j]<<" ";
        output<<endl;
    }
    return output;
}
Matrix& operator +(Matrix m1,Matrix m2)
{
    int data1[m1.row*m1.col];
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
            data1[i*m1.col+j]=m1.data[i][j] + m2.data[i][j];
    }
    createMatrix(m1.row,m1.col,data1,m3);
    return m3;
}
Matrix& operator -(Matrix m1,Matrix m2)
{
    int data1[m1.row*m1.col];
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
            data1[i*m1.col+j]=m1.data[i][j] - m2.data[i][j];
    }
    createMatrix(m1.row,m1.col,data1,m3);
    return m3;
}
Matrix& operator *(Matrix m1,Matrix m2)
{
    assert(m1.col == m2.row);
    int data1[m1.row][m2.col];
    for(int i = 0; i < m1.row; i++)
        for(int j = 0; j < m2.col; j++)
        {
            data1[i][j]=0;
        }
    for(int i=0; i < m1.row; i++)
    {
        for(int j=0; j < m2.col; j++)
        {
            for(int k=0; k < m1.col; k++)
                data1[i][j] += m1.data[i][k] * m2.data[k][j];
        }
    }
    createMatrix(m1.row,m2.col,*data1,m3);
    return m3;
}
Matrix& operator+(Matrix m1, int scalar)
{
    int data1[m1.row*m1.col];
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
            data1[i*m1.col+j]=m1.data[i][j] + scalar;
    }
    createMatrix(m1.row,m1.col,data1,m3);
    return m3;
}
Matrix& operator-(Matrix m1, int scalar)
{
    int data1[m1.row*m1.col];
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
            data1[i*m1.col+j]=m1.data[i][j] - scalar;
    }
    createMatrix(m1.row,m1.col,data1,m3);
    return m3;
}
Matrix& operator*(Matrix m1, int scalar)
{
    int data1[m1.row*m1.col];
    for(int i=0; i<m1.row; i++)
    {
        for(int j=0; j<m1.col; j++)
            data1[i*m1.col+j]=m1.data[i][j] * scalar;
    }
    createMatrix(m1.row,m1.col,data1,m3);
    return m3;
}
Matrix& operator+= (Matrix& m1, Matrix m2)
{
    for(int i=0; i<m1.row;i++)
    {
        for(int j=0; j<m1.col;j++)
            m1.data[i][j] += m2.data[i][j];
    }
    return m1;
}
Matrix& operator-= (Matrix& m1, Matrix m2)
{
    for(int i=0; i<m1.row;i++)
    {
        for(int j=0; j<m1.col;j++)
            m1.data[i][j] -= m2.data[i][j];
    }
    return m1;
}
Matrix& operator+= (Matrix& m1, int scalar)
{
    for(int i=0; i<m1.row;i++)
    {
        for(int j=0; j<m1.col;j++)
            m1.data[i][j] += scalar;
    }
    return m1;
}
Matrix& operator-= (Matrix& m1, int scalar)
{
    for(int i=0; i<m1.row;i++)
    {
        for(int j=0; j<m1.col;j++)
            m1.data[i][j] -= scalar;
    }
    return m1;
}
void operator++ (Matrix& m)
{
    for(int i=0; i<m.row;i++)
    {
        for(int j=0; j<m.col;j++)
            ++m.data[i][j];
    }
}
void operator-- (Matrix& m)
{
    for(int i=0; i<m.row;i++)
    {
        for(int j=0; j<m.col;j++)
            --m.data[i][j];
    }
}
bool   operator== (Matrix m1, Matrix m2)
{
    for(int i=0; i<m1.row;i++)
    {
        for(int j=0; j<m1.col;j++)
            if(m1.data[i][j] != m2.data[i][j])
                {return false;return 0;}
    }
    return true;
}
bool   operator!= (Matrix m1, Matrix m2)
{
    for(int i=0; i<m1.row;i++)
    {
        for(int j=0; j<m1.col;j++)
            if(m1.data[i][j] == m2.data[i][j])
                {return false;return 0;}
    }
    return true;
}
bool Issquare(Matrix m)
{
    if(m.col==m.row)
        return true;
    else
        return false;
}
bool Issymetric(Matrix m)
{
    if(m.col != m.row)
    {
        return false;
        return 0;
    }
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
            if(m.data[i][j] != m.data[j][i])
            {return false;return 0;}
    }
    return true;
}
bool Isidentity(Matrix m)
{
    if(m.col != m.row)
    {
        return false;
        return 0;
    }
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
            if((i == j && m.data[i][j] != 1) || (i != j && m.data[i][j] != 0))
            {return false;return 0;}
    }
    return true;

}
Matrix transpose(Matrix m)
{
    int data1[m.row*m.col];
    for(int i=0; i<m.row;i++)
    {
        for(int j=0; j<m.col;j++)
            data1[i*m.col+j]= m.data[j][i];
    }
    createMatrix(m.row,m.col,data1,m3);
    return m3;
}



int main()
{
    int s,choose;
    cout<<"How many matrices do you want? --> ";
    cin>>s;
    system("cls");
    Matrix matx[s];
    for(int i=1; i<=s; i++)
        cin>>matx[i];

    system("cls");
    cout<<"\t\t\t\t\t  *** The list of operations ***\n\n\n";
    cout<<"1- Addition of two matrices."
    <<"\n2- Subtraction of two matrices.\n3- Multiplication of two matrices."
    <<"\n4- Add number to the matrix and return new matrix.\n5- Sub number from the matrix and return new matrix."
    <<"\n6- Multiply number by the matrix.\n7- Add second matrix to first one."
    <<"\n8- Sub second matrix from first one.\n9- Add a scalar to matrix."
    <<"\n10- Sub a scalar from matrix.\n11- Add 1 to each element of matrix."
    <<"\n12- Sub 1 from each element of matrix.\n13- Check if two matrix are identical."
    <<"\n14- Check if two matrix are not identical.\n15- Check if the matrix is square."
    <<"\n16- Check if the matrix is symmetric.\n17- Check if the matrix is identity.\n18- Transpose the matrix.\n\nEnter the number of operation : ";
    cin>>choose;
    system("cls");

    if(choose==1)
    {
        int nx[2];char m;
        cout<<"Enter the pattern like (number of first mat + number of second mat) : ";
        cin>>nx[0]>>m>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]+matx[nx[1]])<<endl;
    }
    else if(choose==2)
    {
        int nx[2];char m;
        cout<<"Enter the pattern like (number of first mat - number of second mat) : ";
        cin>>nx[0]>>m>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]-matx[nx[1]])<<endl;
    }
    else if(choose==3)
    {
        int nx[2];char m;
        cout<<"Enter the pattern like (number of first mat * number of second mat) : ";
        cin>>nx[0]>>m>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]*matx[nx[1]])<<endl;
    }
    else if(choose==4)
    {
        int nx[2];char m;
        cout<<"Enter the pattern like (number of first mat + the scalar) : ";
        cin>>nx[0]>>m>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]+nx[1])<<endl;
    }
    else if(choose==5)
    {
        int nx[2];char m;
        cout<<"Enter the pattern like (number of first mat - the scalar) : ";
        cin>>nx[0]>>m>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]-nx[1])<<endl;
    }
    else if(choose==6)
    {
        int nx[2];char m;
        cout<<"Enter the pattern like (number of first mat * the scalar) : ";
        cin>>nx[0]>>m>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]*nx[1])<<endl;
    }
    else if(choose==7)
    {
        int nx[2];char m[2];
        cout<<"Enter the pattern like (number of first mat += number of second mat) : ";
        cin>>nx[0]>>m[0]>>m[1]>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]+=matx[nx[1]])<<endl;
    }
    else if(choose==8)
    {
        int nx[2];char m[2];
        cout<<"Enter the pattern like (number of first mat -= number of second mat) : ";
        cin>>nx[0]>>m[0]>>m[1]>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]-=matx[nx[1]])<<endl;
    }
    else if(choose==9)
    {
        int nx[2];char m[2];
        cout<<"Enter the pattern like (number of first mat += the scalar) : ";
        cin>>nx[0]>>m[0]>>m[1]>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]-nx[1])<<endl;
    }
    else if(choose==10)
    {
        int nx[2];char m[2];
        cout<<"Enter the pattern like (number of first mat -= the scalar) : ";
        cin>>nx[0]>>m[0]>>m[1]>>nx[1];
        system("cls");
        cout<<(matx[nx[0]]-nx[1])<<endl;
    }
    else if(choose==11)
    {
        int nx;
        cout<<"Enter number of mat : ";
        cin>>nx;
        system("cls");
        ++matx[nx];
        cout<<(matx[nx])<<endl;
    }
    else if(choose==12)
    {
        int nx;
        cout<<"Enter number of mat : ";
        cin>>nx;
        system("cls");
        --matx[nx];
        cout<<(matx[nx])<<endl;
    }
    else if(choose==13)
    {
        int nx[2];char m[2];
        cout<<"Enter the pattern like (number of first mat == number of second mat) : ";
        cin>>nx[0]>>m[0]>>m[1]>>nx[1];
        system("cls");
        if((matx[nx[0]]== matx[nx[1]]))
            cout<<"The matrices are identical.\n";
        else
            cout<<"The matrices are not identical.\n";
    }
    else if(choose==14)
    {
        int nx[2];char m[2];
        cout<<"Enter the pattern like (number of first mat != number of second mat) : ";
        cin>>nx[0]>>m[0]>>m[1]>>nx[1];
        system("cls");
        if((matx[nx[0]]!= matx[nx[1]]))
            cout<<"The matrices are not identical.\n";
        else
            cout<<"The matrices are identical.\n";
    }
    else if(choose==15)
    {
        int nx;
        cout<<"Enter the number of matrix : ";
        cin>>nx;
        system("cls");
        if(Issquare(matx[nx]))
            cout<<"the matrix is square.\n";
        else
            cout<<"the matrix is not square.\n";
    }
    else if(choose==16)
    {
        int nx;
        cout<<"Enter the number of matrix : ";
        cin>>nx;
        system("cls");
        if(Issymetric(matx[nx]))
            cout<<"the matrix is symmetric.\n";
        else
            cout<<"the matrix is not symmetric.\n";
    }
    else if(choose==17)
    {
        int nx;
        cout<<"Enter the number of matrix : ";
        cin>>nx;
        system("cls");
        if(Isidentity(matx[nx]))
            cout<<"the matrix is identity.\n";
        else
            cout<<"the matrix is not identity.\n";
    }
    else if(choose==18)
    {
        int nx;
        cout<<"Enter the number of matrix : ";
        cin>>nx;
        system("cls");
        transpose(matx[nx]);
        cout<<m3<<endl;
    }



    deleteMatrix(s,matx);


    return 0;
}
