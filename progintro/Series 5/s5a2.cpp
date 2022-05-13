#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

char converter(char ch);
bool test();
char newAlphabet[26];

int main()
{
    const int MAX = 300;
    int c, text[MAX];
    std::cin >> newAlphabet;
    getchar();
    if (strlen(newAlphabet) == 26 && test() == true)
    {
        while ((c = getchar()) != EOF)
        {
            int n = 0;
            while (c != '\n')
            {
                text[n++] = c;
                c = getchar();
            }
            for (int i = 0; i < n; i++)
                switch (text[i])
                {
                case 'a':
                    putchar(newAlphabet[0]);
                    break;
                case 'b':
                    putchar(newAlphabet[1]);
                    break;
                case 'c':
                    putchar(newAlphabet[2]);
                    break;
                case 'd':
                    putchar(newAlphabet[3]);
                    break;
                case 'e':
                    putchar(newAlphabet[4]);
                    break;
                case 'f':
                    putchar(newAlphabet[5]);
                    break;
                case 'g':
                    putchar(newAlphabet[6]);
                    break;
                case 'h':
                    putchar(newAlphabet[7]);
                    break;
                case 'i':
                    putchar(newAlphabet[8]);
                    break;
                case 'j':
                    putchar(newAlphabet[9]);
                    break;
                case 'k':
                    putchar(newAlphabet[10]);
                    break;
                case 'l':
                    putchar(newAlphabet[11]);
                    break;
                case 'm':
                    putchar(newAlphabet[12]);
                    break;
                case 'n':
                    putchar(newAlphabet[13]);
                    break;
                case 'o':
                    putchar(newAlphabet[14]);
                    break;
                case 'p':
                    putchar(newAlphabet[15]);
                    break;
                case 'q':
                    putchar(newAlphabet[16]);
                    break;
                case 'r':
                    putchar(newAlphabet[17]);
                    break;
                case 's':
                    putchar(newAlphabet[18]);
                    break;
                case 't':
                    putchar(newAlphabet[19]);
                    break;
                case 'u':
                    putchar(newAlphabet[20]);
                    break;
                case 'v':
                    putchar(newAlphabet[21]);
                    break;
                case 'w':
                    putchar(newAlphabet[22]);
                    break;
                case 'x':
                    putchar(newAlphabet[23]);
                    break;
                case 'y':
                    putchar(newAlphabet[24]);
                    break;
                case 'z':
                    putchar(newAlphabet[25]);
                    break;
                case 'A':
                    putchar(converter(newAlphabet[0]));
                    break;
                case 'B':
                    putchar(converter(newAlphabet[1]));
                    break;
                case 'C':
                    putchar(converter(newAlphabet[2]));
                    break;
                case 'D':
                    putchar(converter(newAlphabet[3]));
                    break;
                case 'E':
                    putchar(converter(newAlphabet[4]));
                    break;
                case 'F':
                    putchar(converter(newAlphabet[5]));
                    break;
                case 'G':
                    putchar(converter(newAlphabet[6]));
                    break;
                case 'H':
                    putchar(converter(newAlphabet[7]));
                    break;
                case 'I':
                    putchar(converter(newAlphabet[8]));
                    break;
                case 'J':
                    putchar(converter(newAlphabet[9]));
                    break;
                case 'K':
                    putchar(converter(newAlphabet[10]));
                    break;
                case 'L':
                    putchar(converter(newAlphabet[11]));
                    break;
                case 'M':
                    putchar(converter(newAlphabet[12]));
                    break;
                case 'N':
                    putchar(converter(newAlphabet[13]));
                    break;
                case 'O':
                    putchar(converter(newAlphabet[14]));
                    break;
                case 'P':
                    putchar(converter(newAlphabet[15]));
                    break;
                case 'Q':
                    putchar(converter(newAlphabet[16]));
                    break;
                case 'R':
                    putchar(converter(newAlphabet[17]));
                    break;
                case 'S':
                    putchar(converter(newAlphabet[18]));
                    break;
                case 'T':
                    putchar(converter(newAlphabet[19]));
                    break;
                case 'U':
                    putchar(converter(newAlphabet[20]));
                    break;
                case 'V':
                    putchar(converter(newAlphabet[21]));
                    break;
                case 'W':
                    putchar(converter(newAlphabet[22]));
                    break;
                case 'X':
                    putchar(converter(newAlphabet[23]));
                    break;
                case 'Y':
                    putchar(converter(newAlphabet[24]));
                    break;
                case 'Z':
                    putchar(converter(newAlphabet[25]));
                    break;
                case ' ':
                    putchar(' ');
                    break;
                case ',':
                    putchar(',');
                    break;
                case '.':
                    putchar('.');
                    break;
                case '!':
                    putchar('!');
                    break;
                case '-':
                    putchar('-');
                    break;
                case '\'':
                    putchar('\'');
                    break;
                case '"':
                    putchar('"');
                    break;
                case '?':
                    putchar('?');
                    break;
                case '(':
                    putchar('(');
                    break;
                case ')':
                    putchar(')');
                    break;
                case '^':
                    putchar('^');
                    break;
                case ';':
                    putchar(';');
                    break;
                case ':':
                    putchar(':');
                    break;
                case '#':
                    putchar('#');
                    break;
                case '1':
                    putchar('1');
                    break;
                case '2':
                    putchar('2');
                    break;
                case '3':
                    putchar('3');
                    break;
                case '4':
                    putchar('4');
                    break;
                case '5':
                    putchar('5');
                    break;
                case '6':
                    putchar('6');
                    break;
                case '7':
                    putchar('7');
                    break;
                case '8':
                    putchar('8');
                    break;
                case '9':
                    putchar('9');
                    break;
                case '0':
                    putchar('0');
                    break;
                default:
                    break;
                }
            putchar('\n');
        }
    } else std::cout << "error" << std::endl;
}

char converter(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 'A';
}

bool test() {
    char new1, new2;
    for (int i = 0; i < 26; i++) {
        char new1 = newAlphabet[i];
        for (int u = 0; u < i; u++) {
            char new2 = newAlphabet[u];
            if (new1 == new2 && i != u || isdigit(new1) != 0) {
                return false;
            }
        }
    }
    return true;
}