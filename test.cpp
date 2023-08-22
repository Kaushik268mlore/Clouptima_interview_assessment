#include<bits/stdc++.h>
#include "solution.cpp"

int32_t main(){
    vector<vector<int>>list1={
    {1,4,7},
    {-1,2,9},
    {3,5,10}
 };
//  answer should be [1,3]
 vector<vector<int>>list2={
    {3,4,5},
    {2,3,4},
    {6,7,8},
    {4,5,6}
 };
//  answer should be [4,6]
    auto p=smallest_inclusive_range(list1);
    auto q=smallest_inclusive_range(list2);
    cout<<"The smallest inclusive range that includes all the elements for list1 is ["<<p.first<<","<<p.second<<"]\n";
    cout<<"The smallest inclusive range that includes all the elements for list2 is ["<<q.first<<","<<q.second<<"]\n";
}