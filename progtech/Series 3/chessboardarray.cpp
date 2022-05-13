#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class ChessBoardArray {
protected:
    class Row {
    public:
        Row(ChessBoardArray &a, int i) : chessBoardArray(a), row(i) {}

        int &operator[](int i) const {
            return chessBoardArray.select(row, i);
        }

    private:
        ChessBoardArray &chessBoardArray;
        int row;
    };

    class ConstRow {
    public:
        ConstRow(const ChessBoardArray &a, int i) : chessBoardArray(a), row(i) {}

        int operator[](int i) const {
            return chessBoardArray.select(row, i);
        }

    private:
        const ChessBoardArray &chessBoardArray;
        int row;
    };

public:
    ChessBoardArray(unsigned size = 0, unsigned base = 0) : baseRowCol(base),
                                                            numRowCol(size) {
        length = (numRowCol * numRowCol);
        if (length % 2 == 0) length /= 2;
        else length = length / 2 + 1;
        data = new int[length]();
    }

    ChessBoardArray(const ChessBoardArray &a) {
        numRowCol = a.numRowCol;
        baseRowCol = a.baseRowCol;
        delete [] data;
        data = new int[a.length]();
        for (int i = 0; i < a.length; i++) {
            data[i] = a.data[i];
        }
    }

    ~ChessBoardArray() {
        delete[] data;
    }

    ChessBoardArray &operator=(const ChessBoardArray &a)  {
        numRowCol = a.numRowCol;
        baseRowCol = a.baseRowCol;
        delete [] data;
        data = new int[a.length]();
        for (int i = 0; i < a.length; i++) {
            data[i] = a.data[i];
        }
        return *this;
    }

    int &select(int i, int j)  {
        return data[loc(i, j)];
    }

    int select(int i, int j) const  {
        return data[loc(i, j)];
    }

    const Row operator[](int i)  {
        return Row(*this, i);
    }

    const ConstRow operator[](int i) const  {
        return ConstRow(*this, i);
    }

    friend ostream &operator<<(ostream &out, const ChessBoardArray &a)  {

        for (int i = 0; i < a.numRowCol; i++) {
            for (int j = 0; j < a.numRowCol; j++)
                try {
                    out << setw(4) << a.select(i + a.baseRowCol, j + a.baseRowCol);
                } catch (out_of_range &e) { out << setw(4) << 0; }
            out << endl;
        }
        return out;
    }

private:
    int *data = nullptr;
    unsigned int baseRowCol;
    unsigned int numRowCol;
    unsigned int length;

    unsigned int loc(int i, int j) const throw(out_of_range) {
        int di = i - baseRowCol;
        int dj = j - baseRowCol;
        if (di < 0 || di >= numRowCol || dj < 0 || dj >= numRowCol) throw out_of_range("invalid index");
        else if ((di + dj) % 2 == 0) return (di * numRowCol + dj) / 2;
        else throw out_of_range("step on black");
    }
};


#ifndef CONTEST

int main() {
    ChessBoardArray a(4, 1); // size 4x4, rows and columns numbered from 1
    a[3][1] = 42;
    a[4][4] = 17;
    try { a[2][1] = 7; }
    catch (exception &e) { cout << "a[2][1] is black" << endl; }
    try { cout << a[1][2] << endl; }
    catch (exception &e) { cout << "and so is a[1][2]" << endl; }
    cout << a;
}
/* EXPECTED OUTPUT
a[2][1] is black
and so is a[1][2]
   0    0    0    0
   0    0    0    0
  42    0    0    0
   0    0    0   17
*/
#endif //CONTEST
