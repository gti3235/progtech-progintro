#include "iostream"
#include "bits/stdc++.h"

using namespace std;

bool sortdescID (const tuple<int, string, string, int, int> &a,
                 const tuple<int, string, string, int, int> &b);

bool sortdescNAME (const tuple<int, string, string, int, int> &a,
                   const tuple<int, string, string, int, int> &b);

bool sortdescYEAR (const tuple<int, string, string, int, int> &a,
                   const tuple<int, string, string, int, int> &b);

bool sortdescSAL (const tuple<int, string, string, int, int> &a,
                  const tuple<int, string, string, int, int> &b);

bool sortascNAME (const tuple<int, string, string, int, int> &a,
                  const tuple<int, string, string, int, int> &b);

bool sortascYEAR (const tuple<int, string, string, int, int> &a,
                  const tuple<int, string, string, int, int> &b);

bool sortascSAL (const tuple<int, string, string, int, int> &a,
                 const tuple<int, string, string, int, int> &b);

int main () {
    int N, M;
    int id, year, salary;
    string name1, name2;
    cin >> N;
    vector<tuple<int, string, string, int, int>> Cinfo;
    for (int i = 0; i < N; i ++) {
        cin >> id >> name1 >> name2 >> year >> salary;
        Cinfo.emplace_back(make_tuple(id, name1, name2, year, salary));
    }
    cin >> M;
    char categ[7], query[5];
    int number;
    for (int j = 0; j < M; j ++) {
        cin >> categ >> query >> number;
        cout << "Query: " << categ << " " << query << " " << number << endl;
        switch (categ[0]) {
            case ('i') : {
                if (query[0] == 'a') {
                    sort(Cinfo.begin(), Cinfo.end());
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                } else {
                    sort(Cinfo.begin(), Cinfo.end(), sortdescID);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                }
            }
                break;
            case ('n') : {
                if (query[0] == 'a') {
                    sort(Cinfo.begin(), Cinfo.end(), sortascNAME);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                } else {
                    sort(Cinfo.begin(), Cinfo.end(), sortdescNAME);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                }
            }
                break;
            case ('y') : {
                if (query[0] == 'a') {
                    sort(Cinfo.begin(), Cinfo.end(), sortascYEAR);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                } else {
                    sort(Cinfo.begin(), Cinfo.end(), sortdescYEAR);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                }
            }
                break;
            default: {
                if (query[0] == 'a') {
                    sort(Cinfo.begin(), Cinfo.end(), sortascSAL);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                } else {
                    sort(Cinfo.begin(), Cinfo.end(), sortdescSAL);
                    for (int o = 0; o < number; o ++)
                        cout << get<0>(Cinfo[o]) << " "
                             << get<1>(Cinfo[o]) << " "
                             << get<2>(Cinfo[o]) << " "
                             << get<3>(Cinfo[o]) << " "
                             << get<4>(Cinfo[o]) << "\n";
                }
                break;
            }
        }
    }

}


bool sortdescID (const tuple<int, string, string, int, int> &a,
                 const tuple<int, string, string, int, int> &b) {
    return (get<0>(a) > get<0>(b));
}

bool sortdescNAME (const tuple<int, string, string, int, int> &a,
                   const tuple<int, string, string, int, int> &b) {
    if (get<2>(a) == get<2>(b)) return (get<1>(a) > get<1>(b));
    return (get<2>(a) > get<2>(b));
}

bool sortdescYEAR (const tuple<int, string, string, int, int> &a,
                   const tuple<int, string, string, int, int> &b) {
    if (get<3>(a) == get<3>(b)) return (get<0>(a) < get<0>(b));
    return (get<3>(a) > get<3>(b));
}

bool sortdescSAL (const tuple<int, string, string, int, int> &a,
                  const tuple<int, string, string, int, int> &b) {
    if (get<4>(a) == get<4>(b)) return (get<0>(a) < get<0>(b));
    return (get<4>(a) > get<4>(b));
}

bool sortascNAME (const tuple<int, string, string, int, int> &a,
                  const tuple<int, string, string, int, int> &b) {
    if (get<2>(a) == get<2>(b)) return (get<1>(a) < get<1>(b));
    return (get<2>(a) < get<2>(b));
}

bool sortascYEAR (const tuple<int, string, string, int, int> &a,
                  const tuple<int, string, string, int, int> &b) {
    if (get<3>(a) == get<3>(b)) return (get<0>(a) < get<0>(b));
    return (get<3>(a) < get<3>(b));
}

bool sortascSAL (const tuple<int, string, string, int, int> &a,
                 const tuple<int, string, string, int, int> &b) {
    if (get<4>(a) == get<4>(b)) return (get<0>(a) < get<0>(b));
    return (get<4>(a) < get<4>(b));
}