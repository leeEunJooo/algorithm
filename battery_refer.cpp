#include <iostream>
#include <queue>
#include <cmath>
#include <tuple>
#include <vector>
#include <array>
#include <fstream>
using Coord = std::tuple<int,int>;


void push(std::queue<int>& q, int idx, std::vector<bool>& pushed) {
    if (pushed[idx] == false) {
        q.push(idx);
        pushed[idx] = true;
    }
}

constexpr int NONE = -1;
int pop(std::queue<int>& q) {
    if (q.empty()) {
        return NONE;
    } else {
        auto poped = q.front();
        q.pop();
        return poped;
    }
}

double l2dist(Coord xy1, Coord xy2){
    auto x1 = std::get<0>(xy1), y1 = std::get<1>(xy1);
    auto x2 = std::get<0>(xy2), y2 = std::get<1>(xy2);
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

std::vector<int> next_idxs(int now, int max_len, 
                           std::vector<Coord>& xys, std::vector<bool> pushed){
    std::vector<int> nexts;
    for (int idx = 0; idx < xys.size(); idx++) {
        if(pushed[idx] == false &&
           l2dist(xys[now], xys[idx]) <= max_len) {
            nexts.push_back(idx);
        }
    }
    return nexts;
}

bool has_path(std::vector<Coord>& xys, int max_len){
    int beg = 0, end = 1;
    std::queue<int> q;
    auto pushed = std::vector<bool>(xys.size());
    push(q, beg, pushed);
    while (!q.empty()) {
        auto now = pop(q);
        if (now == end) {
            return true;
        }
        auto nexts = next_idxs(now, max_len, xys, pushed);
        for (auto next_idx : nexts) {
            push(q, next_idx, pushed);
        }
    }
    return false;
}

inline int pow2(int x) { // assert(x > 0)
    return 2 << (x - 1);
}

template<typename T, typename F>
int search_(int ans, int prev, int n_try, T arg1, F predicate) {
    if (predicate(arg1, ans)) {
        return (ans - prev == 1 ? ans : search_(prev + 1, prev, 1, arg1, predicate));
    }
    else {
        return search_(ans + pow2(n_try), ans, n_try + 1, arg1, predicate);
    }
}
template<typename T, typename F> 
int log_search(T arg1, F predicate, int min_ans=1) {
    return search_(1,0,1,arg1,predicate);
}


int main(void) {
    auto ifs = std::ifstream("battery.inp");
    int n, z;
    ifs >> n >> z;

    std::vector<Coord> xys;
    xys.push_back({ 0,0 });
    xys.push_back({ z,z });

    int x, y;
    while (ifs >> x >> y) {
        xys.push_back({ x,y });
    }

    auto weight = log_search(xys, has_path);
    auto ofs = std::ofstream("battery.out");
    ofs << weight;

    return 0;
}
//--------------------------------------------------------------------------------------------------
//
//이 방법은 제가 문제를 만들 때 쓴 방법이며, 그다지 빠르지는 않고 적당히 통과만 되는 수준입니다.
//
//저보다 더 빠른 알고리즘을 작성하신 분들이 있습니다.
//
//
//
//
//
//
//
//명예의 전당
//
//ID          time
//
//-----------------
//
//tsei        0.264
//
//ksj931227   0.265
//
//k14j        0.279
//
//nono5546    0.295
//
//hadan       0.296
//
//-----------------
//
//
//
//이번 과제에서 가장 짧은 수행 시간을 기록하신 분들입니다.
//
//제가 쓴 알고리즘은 그냥 중간만 가는 알고리즘이고
//
//이 분들의 알고리즘이 정말로 빠른 알고리즘입니다. 친구들에게 자랑하세요!
//
//
//
//명예의 전당에 오르신 분들은
//
//사용하신 알고리즘을 댓글로 설명해주세요.
//
//
//
//어케했노.PNG
//
//
//
//여기 오르셨다고 가산점이 있지는 않지만
//
//댓글로 알고리즘을 설명하지 않으신 분은 
//
//교수님이 수업 시간에 설명을 시킬 수도 있다고 합니다(실제로 하신 말씀)
//
//
//
//다음은 가장 수행시간이 빠른 분들의 코드입니다.
//
//
//
//
//
//tsei        0.264
//
//---------------------------------------------------------------------------------------------------
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//int **set;
//int *visit;
//int dfs(int station,int x,int pivot){
//    if(set[x][station]<=pivot)
//        return 1;
//    int sum=0;
//    for(int i=0;i<=station;++i){
//        if(sum!=0)
//            break;
//        if(i==x||visit[i]==1){
//            continue;
//        }
//        else if(set[x][i]<=pivot){
//            visit[i]=1;
//            sum= dfs(station,i,pivot);
//        }
//    }
//    return sum;
//}
//int battery(int station, int *point, int pivot, int left,int right){
//    int i;
//    int j;
//    int check=1;
//    int result;
//    int k,l;
//
//    if((right-left)<=1){
//        //printf("%d\n",left);
//        return pivot;
//    }
//
//    //printf("distance: %d, left: %d, right:%d \n",pivot, left,right);
//    visit = (int*)calloc(station+2,sizeof(int*)*(station+2));
//
//    if(dfs(station,0,pivot)){
//        //printf("big\n");
//        return 1 * battery(station,point, (pivot+left)/2 ,left,pivot);
//    }
//    else{
//        //printf("small\n");
//        return 1 * battery(station, point, (pivot+right)/2, pivot,right);
//    }
//}
//int main()
//{
//
//    int station, depart;
//    int distance;
//    int point[2004];  // point x , y
//    int i,j,k;
//    int min;
//    int sum=0;
//    int result;
//
//
//    FILE* fp1 = fopen("battery.inp", "rt");
//    FILE* fp2 = fopen("battery.out", "wt");
//
//    
//    point[0] = 0; // start point x
//    point[1]= 0; // start point y
//    for(i=2; i<=2*station; i+=2){ // point 
//        fscanf(fp1, "%d %d", &point[i], &point[i+1]);
//    }
//    station+=1;
//    point[i] = depart;
//    point[i+1] = depart;
//    set = (int**)malloc(sizeof(int*)*(station+2));
//    for(int i=0; i<=station; i++){
//        set[i] = (int*)malloc (sizeof(int) * station+2);
//    }
//    for(i=0; i<=2*station; i+=2){
//        for(j=0; j<=2*station; j+=2){
//           set[i/2][j/2]= ceil(sqrt(pow(point[i]-point[j],2) + pow(point[i+1] - point[j+1],2)));
//        }
//    }
//
//    distance = ceil(sqrt(pow(depart,2)+pow(depart,2))); 
//    min = battery(station, point, distance/2, 0,distance);
//    fprintf(fp2,"%d",min+1);
//    //printf("min distance: %d\n",min);
//
//
//    free(set);
//    fclose(fp1);
//    fclose(fp2);
//    return 0;
//}
//---------------------------------------------------------------------------------------------------
//
//
//
//ksj931227   0.265
//
//---------------------------------------------------------------------------------------------------
//
//#include <stdio.h>
//#include <math.h>
//using namespace std;
//int n, z;
//int map[1005][5];
//double len[1005][1005];
//int visit[1005];
//int queue[1005];
//int lsort[1005][1005];
//
//
//void length(void){
//	for(int i=0; i<n+2; i++){
//		for(int j=i+1; j<n+2; j++){
//			double x = (double) (map[i][0] - map[j][0]);
//			double y = (double) (map[i][1] - map[j][1]);
//			double l = sqrt(x*x+y*y);
//			len[i][j] = l;
//			len[j][i] = l;
//		}
//	}
//}
//
//void set(){
//	for(int i=0; i<n+2; i++){
//		visit[i]=0;
//	}
//}
//
//void dfs(double w, int start){
//	visit[start]=1;
//	for(int i=0; i<n+2; i++){
//		if(len[start][i]<=w && visit[i]==0){
//			dfs(w, i);
//		}
//	}
//}
//
//int dnc(){
//	double w=1.0;
//	while(visit[n+1]==0){
//		set();
//		dfs(w, 0);
//		w+=1;
//	}
//	return (w-1);
//}
//
//int main(void){
//	FILE *fp = fopen("battery.inp", "r");
//	FILE *fo = fopen("battery.out", "w");
//	fscanf(fp, "%d %d", &n, &z);
//	for(int i=1; i<=n; i++){
//		int a, b;
//		fscanf(fp, "%d %d", &map[i][0], &map[i][1]);
//	}
//	map[n+1][0]=z;
//	map[n+1][1]=z;
//	length();
//
//	fprintf(fo, "%d", dnc());
//	fclose(fp);
//	return 0;
//}
//---------------------------------------------------------------------------------------------------
//
//
//
//k14j        0.279
//
//---------------------------------------------------------------------------------------------------
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cmath>
//using namespace std;
//#define endl '\n'
//void fastIO() {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
//}
//
//vector<pair<int, int> > arr;
//
//int dist(int here, int i) {
//        return (arr[here].first - arr[i].first) * (arr[here].first - arr[i].first) +
//        (arr[here].second - arr[i].second) * (arr[here].second - arr[i].second);
//}
//
//int bfs(int mid) {
//        queue<int> q;
//        int size = arr.size();
//        vector<int> visited(size, 0);
//        int dest = size - 1;
//        visited[0] = 1;
//        q.emplace(0);
//        while(!q.empty()) {
//                int here = q.front();
//                q.pop();
//
//                for(int i = size - 1 ; i >= 0; i -= 1) {
//                        if(visited[i] == 0 && dist(here, i) <= mid) {
//                                if(i == dest) return 1;
//                                visited[i] = 1;
//                                q.emplace(i);
//                        }
//                }
//        }
//        return 0;
//}
//
//int main() {
//        fastIO();
//
//        //ifstream in("C:\\Users\\ksaid\\Downloads\\4-1\\¾E°i¸®Ao\\sampleData3\\1.inp");
//        ifstream in("battery.inp");
//        ofstream out("battery.out");
//
//        int n, z;
//        in >> n >> z;
//        arr.emplace_back(0, 0);
//        for(int i = 1 ; i <= n ; i += 1) {
//                int x, y;
//                in >> x >> y;
//                arr.emplace_back(x, y);
//        }
//        arr.emplace_back(z, z);
//        sort(arr.begin(), arr.end());
//        int lo = 1, hi = 14143;
//        while(lo <= hi) {
//                int mid = (lo + hi) / 2;
//                if(bfs(mid * mid)) {
//                        hi = mid - 1;
//                }
//                else {
//                        lo = mid + 1;
//                }
//        }
//        out << lo << endl;
//        in.close();
//        out.close();
//        return 0;
//}
//---------------------------------------------------------------------------------------------------
//
//
//
//nono5546    0.295
//
//---------------------------------------------------------------------------------------------------
//
//#include<bits/stdc++.h>
//using namespace std;
//vector<pair<int,int>> btr;
//int len(pair<int,int> A, pair<int,int> B){
//    return ceil(sqrt(pow(A.first-B.first,2)+pow(A.second-B.second,2)));
//}
//int dfs(vector<vector<int>> &length,vector<int> &visit,int ind,int limit){
//    if(ind == length.size()-1)
//        return 1;
//    visit[ind]=1;
//    int cnt=0;
//    for(int i=length.size()-1;i>=0;--i){
//        if((length[ind][i]!=0)&&(visit[i]==0)&&(length[ind][i]<=limit)){
//            cnt+=dfs(length,visit,i,limit);
//            if(cnt!=0)
//                break;
//        }
//    }
//    return cnt;
//}
//int main(){
//    ifstream in("battery.inp");
//    ofstream out("battery.out");
//    int N,Z;
//    in>>N>>Z;
//    vector<vector<int>> length(N+2,vector<int>(N+2,0));
//    btr.push_back(make_pair(0,0));
//    for(int i=0;i<N;++i){
//        int x,y;
//        in>>x>>y;
//        btr.push_back(make_pair(x,y));
//    }
//    btr.push_back(make_pair(Z,Z));
//    for(int i=0;i<btr.size();++i){
//        for(int j=i+1;j<btr.size();++j){
//            length[i][j] = len(btr[i],btr[j]);
//            length[j][i] = length[i][j];
//        }
//    }
//    int left=0;
//    int right=length[0][N+1];
//    int pivot=right/2;
//    while(left+1<right){
//        vector<int> visit(N+2,0);
//        if(dfs(length,visit,0,pivot)){
//            right=pivot;
//            pivot=ceil((pivot+left)/2);
//        }
//        else{
//            left=pivot;
//            pivot=ceil((pivot+right)/2);
//        }
//    }
//    out<<pivot+1;
//}
//---------------------------------------------------------------------------------------------------
//
//
//
//hadan       0.296
//
//---------------------------------------------------------------------------------------------------
//
//#include<cmath>
//#include<iostream>
//#include<queue>
//#include<bits/stdc++.h>
//#define MAX_LENGTH 10001
//using namespace std;
//
//int n,pivot,k;
//float frval;
//float dist[MAX_LENGTH][MAX_LENGTH];
//
//class Node{
//public:
//    int counter=0,dpcount=0;
//    int number,x,y;
//    Node(int X,int Y,int num): x(X),y(Y),number(num){}
//    float dp[MAX_LENGTH];
////    int pri[MAX_LENGTH];
//    int print()
//    {
//        for(int i=0;i<n+1;i++)
//            cout <<dp[i] <<" ";
//        cout<<endl;
//    }
//};
//
//int distinction(Node **nodes)
//{
//    int A,B;
//    for(int i=0;i<n+1;i++)
//    {
//        k=0;
//        for(int j=i+1;j<n+2;j++){
//            A=(nodes[i]->x)-(nodes[j]->x);
//            B=(nodes[i]->y)-(nodes[j]->y);
//            A*=A,B*=B;
//            dist[i][j]=sqrt(A+B);
//            dist[j][i]=dist[i][j];
//            nodes[i]->dp[(nodes[i]->dpcount)++]=dist[i][j];
//            nodes[j]->dp[(nodes[j]->dpcount)++]=dist[i][j];
//        }
//    }
//}
//
//int BFS(int piv,Node ** node)
//{
//    queue<int> Q;
//    int num;
//    int expset[n+2]={0,};
//    int ftcheck[n+2]={0,};
//    Q.push(0);
//    ftcheck[0]=1;
//    while(!Q.empty())
//    {
//        num=Q.front();
//        Q.pop();
//        ftcheck[num]=0;
//        if(num==n+1)return 1;
//        else{
//            expset[num]=1;
//            for(int i=0;i<n+2;i++){
//                if(dist[num][i]<=piv)
//                {
//                    if(expset[i] || ftcheck[i])continue;
//                    Q.push(i);
//                    ftcheck[i]=1;
//                }
//            }
//        }
//    }
//    return 0;
//}
//
//int main()
//{
//    ifstream input("battery.inp");
//    ofstream output("battery.out");
//
//    int z,A,B;
//    input >> n >>z;
//
//    int wl=1,wr=n*sqrt(2);
//    Node* nodes[n+2];
//    nodes[0]=new Node(0,0,0);
//    nodes[n+1]=new Node(z,z,n+1);
//    for(int i=1;i<n+1;i++)
//    {
//        input>>A >>B;
//        nodes[i]=new Node(A,B,i);
//    }
//    distinction(nodes);
//
//    while(wl<wr)
//    {
//        pivot=(wl+wr)/2;
//        if(BFS(pivot,nodes)) wr=pivot;
//        else wl=pivot+1;
//    }
//    output <<wl << endl;
//    input.close();
//    output.close();
//
//    return 0;
//}
