#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

char converter(char ch);
bool test();
char searcher(char ch);
constexpr char Alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char newAlphabet[26];

int main()
{
    const int MAX = 300;
    int c, text[MAX];
    char mode[30];
    bool modeToggle = true;
    std::cin >> newAlphabet;
    getchar();
    if (strlen(newAlphabet) == 26 && test() == true)
    {
        std::cin >> mode;
        getchar();
        if (mode[0] == 'd')
            modeToggle = false;
        while ((c = getchar()) != EOF)
        {
            int n = 0;
            while (c != '\n')
            {
                text[n++] = c;
                c = getchar();
            }
            if (modeToggle)
            {
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
                    case '\n':
                        putchar('\n');
                        break;
                    case '/':
                        putchar('/');
                        break;
                    case '[':
                        putchar('[');
                        break;
                    case ']':
                        putchar(']');
                        break;
                    default:
                        break;
                    }
                putchar('\n');
            } else {
                for (int i = 0; i < n; i++)
                    switch (text[i])
                    {
                    case 'a':
                        putchar(searcher('a'));
                        break;
                    case 'b':
                        putchar(searcher('b'));
                        break;
                    case 'c':
                        putchar(searcher('c'));
                        break;
                    case 'd':
                        putchar(searcher('d'));
                        break;
                    case 'e':
                        putchar(searcher('e'));
                        break;
                    case 'f':
                        putchar(searcher('f'));
                        break;
                    case 'g':
                        putchar(searcher('g'));
                        break;
                    case 'h':
                        putchar(searcher('h'));
                        break;
                    case 'i':
                        putchar(searcher('i'));
                        break;
                    case 'j':
                        putchar(searcher('j'));
                        break;
                    case 'k':
                        putchar(searcher('k'));
                        break;
                    case 'l':
                        putchar(searcher('l'));
                        break;
                    case 'm':
                        putchar(searcher('m'));
                        break;
                    case 'n':
                        putchar(searcher('n'));
                        break;
                    case 'o':
                        putchar(searcher('o'));
                        break;
                    case 'p':
                        putchar(searcher('p'));
                        break;
                    case 'q':
                        putchar(searcher('q'));
                        break;
                    case 'r':
                        putchar(searcher('r'));
                        break;
                    case 's':
                        putchar(searcher('s'));
                        break;
                    case 't':
                        putchar(searcher('t'));
                        break;
                    case 'u':
                        putchar(searcher('u'));
                        break;
                    case 'v':
                        putchar(searcher('v'));
                        break;
                    case 'w':
                        putchar(searcher('w'));
                        break;
                    case 'x':
                        putchar(searcher('x'));
                        break;
                    case 'y':
                        putchar(searcher('y'));
                        break;
                    case 'z':
                        putchar(searcher('z'));
                        break;
                    case 'A':
                        putchar(converter(searcher('a')));
                        break;
                    case 'B':
                        putchar(converter(searcher('b')));
                        break;
                    case 'C':
                        putchar(converter(searcher('c')));
                        break;
                    case 'D':
                        putchar(converter(searcher('d')));
                        break;
                    case 'E':
                        putchar(converter(searcher('e')));
                        break;
                    case 'F':
                        putchar(converter(searcher('f')));
                        break;
                    case 'G':
                        putchar(converter(searcher('g')));
                        break;
                    case 'H':
                        putchar(converter(searcher('h')));
                        break;
                    case 'I':
                        putchar(converter(searcher('i')));
                        break;
                    case 'J':
                        putchar(converter(searcher('j')));
                        break;
                    case 'K':
                        putchar(converter(searcher('k')));
                        break;
                    case 'L':
                        putchar(converter(searcher('l')));
                        break;
                    case 'M':
                        putchar(converter(searcher('m')));
                        break;
                    case 'N':
                        putchar(converter(searcher('n')));
                        break;
                    case 'O':
                        putchar(converter(searcher('o')));
                        break;
                    case 'P':
                        putchar(converter(searcher('p')));
                        break;
                    case 'Q':
                        putchar(converter(searcher('q')));
                        break;
                    case 'R':
                        putchar(converter(searcher('r')));
                        break;
                    case 'S':
                        putchar(converter(searcher('s')));
                        break;
                    case 'T':
                        putchar(converter(searcher('t')));
                        break;
                    case 'U':
                        putchar(converter(searcher('u')));
                        break;
                    case 'V':
                        putchar(converter(searcher('v')));
                        break;
                    case 'W':
                        putchar(converter(searcher('w')));
                        break;
                    case 'X':
                        putchar(converter(searcher('x')));
                        break;
                    case 'Y':
                        putchar(converter(searcher('y')));
                        break;
                    case 'Z':
                        putchar(converter(searcher('z')));
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
                    case '\n':
                        putchar('\n');
                        break;
                    case '/':
                        putchar('/');
                        break;
                    case '[':
                        putchar('[');
                        break;
                    case ']':
                        putchar(']');
                        break;
                    default:
                        break;
                    }
                    putchar('\n');
            }
        } 
    } else std::cout << "error" << std::endl;
}

char converter(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 'A';
    return 0;
}

bool test()
{
    char new1, new2;
    for (int i = 0; i < 26; i++)
    {
        char new1 = newAlphabet[i];
        for (int u = 0; u < i; u++)
        {
            char new2 = newAlphabet[u];
            if (new1 == new2 && i != u || isdigit(new1) != 0)
            {
                return false;
            }
        }
    }
    return true;
}

char searcher(char ch) {
    char letter;
    for (int i = 0; i < 26; i++) {
        if (ch == newAlphabet[i]) return Alphabet[i]; 
    }
    return 0;
}