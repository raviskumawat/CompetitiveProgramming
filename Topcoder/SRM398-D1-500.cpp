/*
*     Idea: 1- we need to calculate  how many path with number from 0 to n
*              Just assign every Speical Field with number according to his rank i mean from 1 to n
*              Then to to make moves if is the special field and less in rank then back to i==0 && j==0 
*              And the Base Cases Are in Function Have Fun :)
*              
*              Happy Solving :)
*
*/


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
const int N=55;
int vis[N][N];
int dp[N][N][N][N];
using namespace std;
const int MOD=1000007;
class CountPaths {
public:
       int solve(int i,int j,int k,int prev){
              int &ret=dp[i][j][k][prev];
              if(ret!=-1)return ret;
              ret=0;
              if(i==0&&j==0){
                if(vis[i][j]==-1)return ret=k==0;
                else{
                 if(vis[i][j]<prev&&k==1)return ret=1;
                }
              }
              if(vis[i][j]==-1){
               if(i) ret+=solve(i-1,j,k,prev);
               if(j) ret+=solve(i,j-1,k,prev);
              }else if(vis[i][j]<prev){
                if(i&&k) ret+=solve(i-1,j,k-1,vis[i][j]);
                if(j&&k) ret+=solve(i,j-1,k-1,vis[i][j]);
              }
             return ret=ret%MOD;
       }
	vector <int> difPaths(int r, int c, vector <int> fieldrow, vector <int> fieldcol) {
	         int n=fieldrow.size();
	         memset(vis,-1,sizeof(vis));
	         memset(dp,-1,sizeof(dp));
	         for(int i=0;i<n;i++)vis[fieldrow[i]-1][fieldcol[i]-1]=i;
	         vector<int>ret;
	         for(int i=0;i<n+1;i++){
	             ret.push_back(solve(r-1,c-1,i,n));
	         }
	         return ret;

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, vector <int> p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	CountPaths *obj;
	vector <int> answer;
	obj = new CountPaths();
	clock_t startTime = clock();
	answer = obj->difPaths(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p4.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p4[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p4.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p4[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	vector <int> p2;
	vector <int> p3;
	vector <int> p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 3;
	int t2[] = {2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {1,3,2};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 6;
	p1 = 4;
	int t2[] = {5,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {14,24,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 5;
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,4,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {42,14,10,4};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 35;
	p1 = 37;
	int t2[] = {3,28,28,27,27,5,15,23,21,3,8,25,34,31,33,35,13,34};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {12,34,3,9,34,3,18,17,26,5,23,14,20,7,3,20,19,23};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {830519,709835,755976,219563,868547,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 50;
	p1 = 50;
	int t2[] = {50,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {50,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,0,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
