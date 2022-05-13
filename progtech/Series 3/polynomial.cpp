#include <iostream>
#include <stdexcept>
#include "cmath"

using namespace std;

class Polynomial {
protected:
    class Term {
    protected:
        int exponent;
        int coefficient;
        Term *next;

        Term(int exp, int coeff, Term *n) {
            next = n;
            coefficient = coeff;
            exponent = exp;
        }

        friend class Polynomial;

        friend Polynomial operator+(const Polynomial &p, const Polynomial &q) noexcept;

        friend Polynomial operator*(const Polynomial &p, const Polynomial &q) noexcept;

        friend ostream &operator<<(ostream &out, const Polynomial &p) noexcept;

    };

    Term *head;
public:
    Polynomial() {
        head = nullptr;
    }

    Polynomial(const Polynomial &p) {
        if (p.head == nullptr) {
            head = nullptr;
        } else {
            head = new Term(p.head->exponent, p.head->coefficient, head);
            Term *current = head;
            Term *phead = p.head;
            Term *currentObj = phead;
            while (currentObj->next != nullptr) {
                current->next = new Term(currentObj->next->exponent, currentObj->next->coefficient,
                                         currentObj->next->next);
                currentObj = currentObj->next;
                current = current->next;
            }
        }
    }

    ~Polynomial() {
        Term *s = head, *p;
        while (s != nullptr) {
            p = s->next;
            free(s);
            s = p;
        }
    }

    Polynomial &operator=(const Polynomial &p) noexcept {
        Term *s = head, *z;
        while (s != nullptr) {
            z = s->next;
            free(s);
            s = z;
        }
        free(head);
        if (p.head == nullptr) {
            head = nullptr;
        } else {
            head = new Term(p.head->exponent, p.head->coefficient, head);
            Term *current = head;
            Term *phead = p.head;
            Term *currentObj = phead;
            while (currentObj->next != nullptr) {
                current->next = new Term(currentObj->next->exponent, currentObj->next->coefficient,
                                         currentObj->next->next);
                currentObj = currentObj->next;
                current = current->next;
            }
        }
        return *this;
    }

    void addTerm(int expon, int coeff) noexcept {
        Term *s = head, *t;
        bool enter = true;
        if (coeff == 0) enter = false;
        if (enter) {
            if (s == nullptr || expon > s->exponent) {
                s = new Term(expon, coeff, s);
                s->next = head;
                head = s;
            } else if (expon == s->exponent) {
                s->coefficient += coeff;
            } else { // expon < s->exponent
                while (s->next != nullptr) {
                    if (expon == s->next->exponent) {
                        s = s->next;
                        s->coefficient += coeff;
                        addterm = true;
                        break;
                    } else if (expon < s->next->exponent) s = s->next;
                    else {
                        s->next = new Term(expon, coeff, s->next);
                        addterm = true;
                        break;
                    }
                }
                if (s->next == nullptr && expon < s->exponent) {
                    s->next = new Term(expon, coeff, s->next);
                    addterm = true;
                }
                if (!addterm) s->next = new Term(expon, coeff, s->next);
                addterm = false;
            }
        }
        if (head->coefficient == 0) {
            t = head;
            head = head->next;
            delete t;
        }
    }

    double evaluate(double x) noexcept {
        double result = 0;
        Term *s = head;
        while (s != nullptr) {
            result += (s->coefficient * pow(x, s->exponent));
            s = s->next;
        }
        return (result);
    }

    friend Polynomial operator+(const Polynomial &p, const Polynomial &q) noexcept {
        Term *s = p.head;
        Term *a = q.head;
        bool sAct = false, aAct = false, enter = true;
        Polynomial adder;
        while (s != nullptr || a != nullptr) {
            if (s == nullptr && a != nullptr) {
                adder.addTerm(a->exponent, a->coefficient);
                aAct = true;
                enter = false;
            } else if (s != nullptr && a == nullptr) {
                adder.addTerm(s->exponent, s->coefficient);
                sAct = true;
                enter = false;
            }
            if (enter) {
                if ((s->coefficient + a->coefficient) != 0 && s->exponent == a->exponent) {
                    adder.addTerm(s->exponent, s->coefficient + a->coefficient);
                    sAct = true;
                    aAct = true;
                } else if (s->exponent != a->exponent) {
                    if (s->coefficient == 0) {
                        adder.addTerm(a->exponent, s->coefficient + a->coefficient);
                        aAct = true;
                    } else if (a->coefficient == 0) {
                        adder.addTerm(s->exponent, s->coefficient + a->coefficient);
                        sAct = true;
                    } else {
                        adder.addTerm(max(a->exponent, s->exponent),
                                      (s->exponent > a->exponent ? s->coefficient : a->coefficient));
                        if (s->exponent > a->exponent) sAct = true;
                        else aAct = true;
                    }
                } else if (s->coefficient + a->coefficient == 0) {
                    sAct = true;
                    aAct = true;
                }
            }
            if (aAct) a = a->next;
            if (sAct) s = s->next;
            aAct = false;
            sAct = false;
            enter = true;
        }
        return adder;
    }

    friend Polynomial operator*(const Polynomial &p, const Polynomial &q) noexcept {
        Term *s = p.head;
        Term *a = q.head;
        Polynomial multi;
        while (s != nullptr) {
            while (a != nullptr) {
                if (s->coefficient != 0 && a->coefficient != 0) {
                    multi.addTerm(s->exponent + a->exponent, s->coefficient * a->coefficient);
                }
                a = a->next;
            }
            a = q.head;
            s = s->next;
        }
        return multi;
    }

    friend ostream &operator<<(ostream &out, const Polynomial &p) noexcept {
        objectRegulator(p);
        Term *s = p.head;
        int counter = 0;
        bool start = false;
        if (s != nullptr) if (s->coefficient == 0) start = true;
        while (s != nullptr) {
            if (s->coefficient > 1) {
                counter++;
                if (s->exponent > 1)
                    out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                        << (s->coefficient < 0 && s != p.head ? "- " : "") << abs(s->coefficient)
                        << ((s->exponent == 0) ? "" : "x")
                        << ((s->exponent == 1) ? "" : "^") << s->exponent
                        << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
                else if (s->exponent == 1)
                    out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                        << (s->coefficient < 0 && s != p.head ? "- " : "") << abs(s->coefficient)
                        << ((s->exponent == 0) ? "" : "x")
                        << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
                else if (s->exponent == 0)
                    out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                        << (s->coefficient < 0 && s != p.head ? "- " : "") << abs(s->coefficient);
            } else if (s->coefficient == 0) {
                out << "";
            } else {
                counter++;
                if (s->exponent > 1 || s->exponent < 0)
                    if (s->coefficient != 1 && s->coefficient != (-1))
                        out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                            << (s->coefficient < 0 ? "- " : "") << abs(s->coefficient)
                            << ((s->exponent == 0) ? "" : "x")
                            << ((s->exponent == 1) ? "" : "^") << s->exponent
                            << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
                    else
                        out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                            << (s->coefficient < 0 ? "- " : "")
                            << ((s->exponent == 0) ? "" : "x")
                            << ((s->exponent == 1) ? "" : "^") << s->exponent
                            << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
                else if (s->exponent == 1)
                    if (s->coefficient != 1 && s->coefficient != (-1))
                        out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                            << (s->coefficient < 0 && s != p.head ? "- " : "") << abs(s->coefficient)
                            << ((s->exponent == 0) ? "" : "x")
                            << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
                    else
                        out << (s->coefficient > 0 && s != p.head && !start ? "+ " : "")
                            << (s->coefficient < 0 ? "- " : "") << ((s->exponent == 0) ? "" : "x")
                            << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
                else
                    out << (s->coefficient > 0 && s != p.head ? "+ " : "")
                        << (s->coefficient < 0 ? "- " : "") << abs(s->coefficient)
                        << ((s->exponent == 0) ? "" : "x")
                        << ((s->next == nullptr) || (s->next->coefficient == 0) ? "" : " ");
            }
            s = s->next;
        }
        start = false;
        if (counter == 0) out << "0";
        return out;
    }

    static Polynomial objectRegulator(const Polynomial &z) {
        Term *s = z.head, *p;
        while (s != nullptr && s->next != nullptr) {
            if (s->next->coefficient == 0) {
                p = s->next;
                s->next = p->next;
                delete p;
            }
            s = s->next;
        }
        return z;
    }

private:
    bool addterm;
};

//int main() {
//    Polynomial p;
//    p.addTerm(2, 1);
//    p.addTerm(1, -1);
//    p.addTerm(2, -1);
//    p.addTerm(1, 1);
//    cout << "P(x) : " << p << endl;
//    cout << p.evaluate(0) << endl;
//    cout << p.evaluate(-1) << endl;
//    cout << p.evaluate(-25) << endl;
//    cout << p.evaluate(44) << endl;
//
//    Polynomial q;
//    q.addTerm(0, 5);
//    q.addTerm(1, 6);
//    cout << "Q(x) : " << q << endl;
//    cout << q.evaluate(0) << endl;
//    cout << q.evaluate(-1) << endl;
//    cout << q.evaluate(-25) << endl;
//    cout << q.evaluate(44) << endl;
//
//    cout << "P(x) + Q(x) : " << p + q << endl;
//    cout << (p + q).evaluate(0) << endl;
//    cout << (p + q).evaluate(-1) << endl;
//    cout << (p + q).evaluate(-25) << endl;
//    cout << (p + q).evaluate(44) << endl;
//
//    cout << "P(x) * Q(x) : " << p * q << endl;
//    cout << (p * q).evaluate(0) << endl;
//    cout << (p * q).evaluate(-1) << endl;
//    cout << (p * q).evaluate(-25) << endl;
//    cout << (p * q).evaluate(44) << endl;
//}
