#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Consider an array of k lists , where each list can be of a variable size, 
// The goal is to find an optimised approach to a range that is inclusive of the smallest elements from each list
// So, the first priority is that the range has to be the shortest/smallest.
// Also the range is supposed to include the smallest of elements.
// Consider the elements of each list to be sorted
// For Example:
// List ={
//     {1,4,7},
//     {-1,2,9},
//     {3,5,10}
//  } 

// Result should be [1,3]



// The above function will return the most optimal range that includes atleast one element from each of the k lists.
// Time Complexity will be O(n*logn) where n is the size of the list


// Data structure to store a heap node
struct Node
{
    // `value` stores the element,
    // `list_num` stores the list number of the element,
    // `index` stores the column number of the list from which element was taken
    int value, list_num, index;
};
 
// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node &lhs, const Node &rhs) const {
        return lhs.value > rhs.value;
    }
};
pair<int,int> smallest_inclusive_range(vector<vector<int>>&lists){
    // invalid input
    if (lists.size() == 0) {
        return {-1, -1};
    }
 
    int M = lists.size();
 
    // `high` will be the maximum element in a heap
    int high = INT_MIN;
 
    // stores minimum and maximum elements found so far in a heap
    pair<int, int> p = { 0, INT_MAX };
 
    // create an empty min-heap
    priority_queue<Node, vector<Node>, comp> pq;
 
    // push the first element of each list into the min-heap
    // along with the list number and their index in the list
    for (int i = 0; i < M; i++)
    {
        // invalid input
        if (lists[i].size() == 0) {
            return {-1, -1};
        }
 
        pq.push({lists[i][0], i, 0});
        high = max(high, lists[i][0]);
    }
 
    // run till the end of any list is reached
    while (true)
    {
        // get root node information from the min-heap
        int low = pq.top().value;
        int i = pq.top().list_num;
        int j = pq.top().index;
 
        // remove the root node
        pq.pop();
 
        // update `low` and `high` if a new minimum is found
        if (high - low < p.second - p.first) {
            p = {low, high};
        }
 
        // return on reaching the end of any list
        if (j == lists[i].size() - 1) {
            return p;
        }
 
        // take the next element from the "same" list and
        // insert it into the min-heap
        pq.push({lists[i][j + 1], i, j + 1});
 
        // update high if the new element is greater
        high = max(high, lists[i][j + 1]);
    }
}