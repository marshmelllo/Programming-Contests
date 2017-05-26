/*
 * BTS2016CherryTree.cpp
 *
 *  Created on: May 26, 2017
 *      Author: Rob
 */
/*
 *
 * basic recursion solution
 *
 * all you need to do:
 *  1) store all connections between patches
 *  2) staring at 1 (because we know this is the trunk/root of the tree), equate the cherries for that
 *  branch equal to the cherries of all connections (if those connections havent been visited before)
 *  do the same thing for weight
 *  before you return answer for a branch, check if cherries are >= c and weight <= k, if so, add one to
 *  counter of unique cuts
 *
 *  make sure you dont add one to the counter for the 1st branch because, as specified in the question,
 *  you cannot cut the trunk.
 *
 */
#include<iostream>
#include<list>
using namespace std;
#define pb push_back
#define mp make_pair
struct Branch{
	int dest;
	int w;
};
int count = 0;
int n,c,k;
int f,t,w;
int nc[10001] = {0};
int we[10001] = {0};
list<Branch> con[10001];
bool v[10001] = {0};
pair<int,int> getvals(int i,int wei){
	v[i] = true;
	int tc, tw = 0;
	tw = wei;
	tc = nc[i];
	for(Branch c:con[i]){
		if(!v[c.dest]){
			pair<int,int> cur = getvals(c.dest,c.w);
			tc += cur.first;
			tw += cur.second;
		}
	}
	nc[i] = tc;
	we[i] = tw;
	if(tc >= c && tw <= k && i != 1){
		count++;
	}
	//printf("%d %d %d \n",i,tc,tw);
	return mp(tc,tw);

}
int main(){
	scanf("%d%d%d",&n,&c,&k);
	for(int i = 1; i<=n; i++){
		scanf("%d",&nc[i]);
	}
	for(int i = 0; i<n-1; i++){
		scanf("%d%d%d",&f,&t,&w);
		con[f].pb(Branch{t,w});
		con[t].pb(Branch{f,w});

	}
	getvals(1,0);
	printf("%d",count);
	return 0;
}



