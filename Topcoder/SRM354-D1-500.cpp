/*
* target: get Biggest Number from swaping two digit and reduce them by 1
* sol : try to swap every 2 digit in the number and put the number that had been swaped
*       in  queue and do the same thing untill can't do swap anymore..
* corner case : if digit of i =0 or digit of j=0  || the number already in queue or calculated before
*
*
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
#include <string>
using namespace std;
const int NN=12345678;
bool vis[NN];
class RemissiveSwaps {
public:
      int findMaximum(int N) {
	     queue<int>q;
	     q.push(N);
	     vis[N]=1;
	     while(!q.empty()){
	       int n=q.front();
	       q.pop();
               char ss[20]={};
               
	       sprintf(ss,"%d",n);
               string s=ss;
	       for(int i=0;i<s.length();i++){
	           for(int j=i+1;j<s.length();j++){
	              string next=s;
	              if(s[i]=='0'||s[j]=='0')continue;
    	                 next[i]=s[j]-1,next[j]=s[i]-1;
    	                 if(next[0]=='0')continue;
    	                 int num=atoi(next.c_str());
    	                 if(vis[num])continue;
    	                  vis[num]=1;
    	                  q.push(num);
                   }
	       }
	   }
	    for(int i=NN;i>=0;i--){
	           if(vis[i])return i;
	       }
         }


};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	RemissiveSwaps *obj;
	int answer;
	obj = new RemissiveSwaps();
	clock_t startTime = clock();
	answer = obj->findMaximum(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	{
	// ----- test 0 -----
	p0 = 166;
	p1 = 560;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3499;
	p1 = 8832;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 34199;
	p1 = 88220;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 809070;
	p1 = 809070;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
