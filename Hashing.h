//
// Created by Arman on 2/1/2022.
//

#ifndef PROJECT_HASHING_H
#define PROJECT_HASHING_H
#include "math.h"
int hash_timestamp(string year, string month, string day){
    long long int hs = 0;
    int y = stoi(year), m = stoi(month), d = stoi(day);
    if (!((y > 0) && (m > 0 && m < 13) && (d > 0 && d < 31)))
        cout<<y<<" "<<m<<" "<<d<<"!!!!!!! sorry, timestamp is invalid !!!!!!!!!"<<endl;
    hs = y*200 + m*23 + d*5;
    return hs%100007;
}
long long int hashh(string s){
    long long int tmp = 0;
    for (int i = 0; i < s.length(); ++i) {
        tmp += (int(s[i])*pow(3.12,i));
        tmp %= 100007;
    }
    return tmp;
}

#endif //PROJECT_HASHING_H
