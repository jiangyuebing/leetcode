/***************************************************
** Author: Yuebing Jiang
** email:jiangyuebing@gmail.com
** Endian:
** 	Big:
** 		addr:	0	1	2	3
** 		con"	A   B	C	D
** 	little
** 		addr:	0	1	2	3
** 				D	C	B	A
** Date: Wed 30 Jan 2013 11:50:56 PM MST
** Desc: There are two sorted arrays A and B of size m and n 
**  respectively. Find the median of the two sorted arrays. 
**  The overall run time complexity should be O(log (m+n)).
**************************************************/
#define LOCAL
#include <iostream>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include<sstream>
using namespace std;

#define PB push_back
#define MP make_pair
#define CtoI(x) ((x)-'0')
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define FOR(i,m,n)  for(int (i)=(m);(i)<(int)(n);(i)++)
#define SZ(x) (x).size()
#define RORD(i,h,l)  for((i)=(h);(i)>(int)(l);(i)--)
#define TdP(m,n,a)	{REP(i,n) cout<<"--"; cout<<endl; REP(i,m){REP(j,n) cout<<a[i][j]<<" "; cout<<endl;} REP(i,n) cout<<"--"; cout<<endl;}
#define OdP(m,a)	{REP(i,m) cout<<"--"; cout<<endl; REP(i,m){ cout<<a[i]<<" ";} cout<<endl; REP(i,m) cout<<"--"; cout<<endl;}
string int2str(int a){string res; ostringstream  ss; ss<<a; res=ss.str();}
int str2int(string s){int i,sum; sum=0; for(i=0;i<s.size();i++){sum=sum*10+s[i]-'0';} return sum;}

void read(char *a) {freopen(a,"r", stdin);}
void write(char *a) {freopen(a,"w",stdout);}

int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
int valid(int x,int y,int m,int n){
	if (x>=0 && x<m && y>=0 && y<n)
		return 1;
	return 0;
}
/*----------qsort----------------*/
//int compare(const void *a,const void *b){return (*(int*)a -*(int*)b);}
//qsort(array,arraysize,sizeof(int),compare);
/*----------qsort----------------*/

	//1) merge sort and return the median;
class Solution1 {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      	vector<int> merge;
		int k=0,l=0;
		for(int i=0;i<m+n;i++){
			while(k<m && l<n){
				if(A[k]<B[l])
					merge.push_back(A[k++]);
				else
					merge.push_back(B[l++]);
			}
			if(k<m){
				for(;k<m;k++){
					merge.push_back(A[k]);
				}
			}
			if(l<n){
				for(;l<n;l++){
					merge.push_back(B[l]);
				}
			}
		}
		if((m+n)%2==0){
			return ((double)merge[(m+n)/2]+merge[(m+n)/2-1])/2
		}else{
			return merge[(m+n)/2];
		}
    }
};

/*(By comparing the medians of two arrays)
This method works by first getting medians of 
the two sorted arrays and then comparing them.
Let A and B be the input arrays.

Algorithm:
Input: input Array A and B. index for A [l1,r1), 
		index for B[l2,r2). A's length is m, B's length is n.
1) initialize, l1=0, r1=m, l2=0, r2=n; i_want=(l2-l1+r2-l2)/2
2) Calculate the medians m1 and m2 of the input arrays A
   and B respectively. m1 with index i1=(l1+r1)/2 in A. 
   m2 with index i2=(l2+r2)/2 in B. 
   m1=A[i1],m2=B[i2];
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one 
   of the below two subarrays.
    a)  From first element of A to i1   [l1---i1+1). 
            len: i1+1-l1=(l1+r1)/2+1-l1;
    b)  From i2 to last element of B    [i2--r2) .   
            len: r2-i2=r2-(l2+r2)/2
	This will form array length of m/2+n/2+2;
		i_want=(r1-l1+r2-l2)/2-i2=(r1-l1+r2-l2)/2-(l2+r2)/2.

4) If m2 is greater than m1, then median is present in one    
   of the below two subarrays.
   a)  From m1 to last element of ar1  (i1...(len1-1))
   b)  From first element of ar2 to m2 (0 ...  i2-1)
   	the index of the median is (m+n)/2 -i1;
5) Repeat the above process until size of both the subarrays 
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get 
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
*/
int main(){
Solution1 s1;
    int A={0,1,2,6,7,8};
    int B={3,4,5,9,10,11};
    cout<<s1.findMedianSortedArrays(A,6,B,6)<<endl;
return 0;
}

