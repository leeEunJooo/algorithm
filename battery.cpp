#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
using namespace std;

struct{
	int x,y;
}typedef Point;

int dist(const Point &a, const Point &b){
	double len = 0;
	len = sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
	int length = ceil(len);
	return length;
}

int findW(Point S, Point P[] , int range, int num){
	int position = 0;
	if(range == 0) return 0;
	int ok;
	queue<int> q;
	int visited[num] = {0};
	for(int i=0; i<num; i++){
		ok = dist(S,P[i]);
		if(ok<=range){
			q.push(i);
			visited[i] = 1;
		}
	}
	
	int k;
	while(!q.empty()){
		k = q.front();
		q.pop();
		for(int i=0; i<num; i++){
			if(dist(P[k],P[i])<=range && dist(P[k],P[i])>0 && visited[i]!=1){
				q.push(i);
				visited[i] = 1;
				position = i;
			}
			//else continue;
		}	
		if(position == num-1)
			return range;
	}
	if(position !=num-1)
		return 0;	
}

int recursive(Point S, Point P[], int start, int range, int N){
	int mid = (start+range)/2;
	int f = findW(S,P,mid,N+1);//119
	
	if(f != mid && findW(S,P,mid+1,N+1)!=0)
		return mid;		
	
	else{
		if(f == 0)
			return recursive(S,P,mid,range,N);
			
		else if(f != 0)
			return recursive(S,P,start,mid,N);
	}
	
}

int main(){
	
	ifstream fs_r;
	ofstream fs_w;
	fs_r.open("2.inp");
	fs_w.open("2.out");
	int N, z;
	
	fs_r >> N;
	fs_r >> z;
	
	Point P[N+1];
	
	for(int i=0; i<N; i++){
		fs_r >> P[i].x;
		fs_r >> P[i].y;	
	}
	
	P[N].x = P[N].y = z;	
	Point S = {0,0};
	
	int start=0;
	int result=0;
	int range = z;

	result = recursive(S, P, start, range,N);

	fs_w << result+1;

	fs_r.close();
	fs_w.close();
	return 0;
}
