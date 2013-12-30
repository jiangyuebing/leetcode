/***************************************************
** Author: Yuebing Jiang
** email:jiangyuebing@gmail.com
** Endian:
**     Big:
**         addr:    0    1    2    3
**         con"    A   B    C    D
**     little
**         addr:    0    1    2    3
**                 D    C    B    A
** Date: Wed 30 Jan 2013 11:44:28 PM MST
** Desc:
**  Given an array of integers, find two numbers 
**  such that they add up to a specific target number.
** 
**  The function twoSum should return indices of the 
**  two numbers such that they add up to the target, 
**  where index1 must be less than index2. Please note 
**  that your returned answers (both index1 and index2) 
**  are not zero-based.
**
**  You may assume that each input would have exactly one solution.
**
**  Input: numbers={2, 7, 11, 15}, target=9
**  Output: index1=1, index2=2
**************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include<sstream>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define OdP(m,a)    {REP(i,m) cout<<"--"; cout<<endl; REP(i,m){ cout<<a[i]<<" ";} cout<<endl; REP(i,m) cout<<"--"; cout<<endl;}

class Solution0 { 
  /*
  ** Naive: pin one index and search the rest. Since only
  **    one solution is expected.
  ** */
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j;
        vector<int> res;
        for(i=0;i<numbers.size();i++)
            for(j=i+1;j<numbers.size();j++){
                if(numbers[i]+numbers[j]==target){
                        res.push_back(i+1);
                        res.push_back(j+1);
                    return res;
                }
            }
        return res;
    }
};

class Solution1 { 
   /* idea 2, use hashtable, key(number)->data(index)
   **  problem1, duplicate value, need to use erase operation.
   ** */     
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j;
        vector<int> res;
        map<int,int> val_index;
        for(i=0;i<numbers.size();i++){
            val_index.insert(make_pair(numbers[i],i+1));
        }
        for(i=0;i<numbers.size();i++){
            if(val_index.find(target-numbers[i])!=val_index.end()){
                int index1, index2;
                index1=(val_index.find(numbers[i]))->second;
                index2=(val_index.find(target-numbers[i]))->second;
                res.push_back(index1);
                res.push_back(index2);
                return res;
            } 
        }
    }
};
int main(){
     int Vec[]={0,1,2,4,5,6,7,10};
    vector<int> testVec(Vec,Vec+8);
    int target=11;
    Solution0 s0;
    Solution1 s1;
    OdP(2,s0.twoSum(testVec,target)); 
    OdP(2,s1.twoSum(testVec,target)); 

return 0;
}

