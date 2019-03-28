#include <iostream>
#include "oil.h"

using namespace std;

struct{
	int i;
	int j;
}typedef Range;


int findleft(int start, int end);
int findright(int start, int end);

//1. 걸쳐져있는 경우를 찾고 
//2. 왼쪽에서 시작점 찾기
//3. 오른쪽에서 시작점 찾기 
Range findOil(int start, int end){
//	cout << start <<" ";
//	cout << end <<"\n";

	Range tempR = {start, end};
	
	int mid = (start + end)/2;
	int mid_state = observe(mid,mid);

	//cout <<"front : "<< front <<" back : " <<back << "\n";

	if(mid_state==1) {
		tempR.i = findleft(start,mid);	//왼쪽
		tempR.j = findright(mid,end);	//오른쪽 
		return tempR;
	}
	else if(mid_state==0){
 		if(observe(start,mid-1)==0){	//mid가 0인데 mid이전이 모두 0인지 알아본다. 
			findOil(mid+1,end);
		}
		else{	//mid이전에 다른 것들이 있다면  
			findOil(start,mid-1);	//mid 이전에 오일 줄이 있는지 봄. mid에는 이미 없어서 미드 이전부터봄 
		}
	}
	
}

int findleft(int start, int end){
	int mid = (start + end)/2;
	int mid_state = observe(mid,mid);
	
	if(mid_state == 1){
		if(observe(mid-1,mid-1)==0 || mid-1 == -1) return mid;
		else return findleft(start,mid);	//start,mid-1
	}
	//else if(observe(start,end)==1) return start;	//추가 
	else if(mid_state == 0){
		return findleft(mid+1,end);	//mid가 0이라면 mid 이전의 것은 볼 필요 없다 
	}
	
	
	
}

int findright(int start, int end){
	int mid = (start + end)/2;
	if((end+start)%2 ==1 && end != mid) mid+=1;	
	int mid_state = observe(mid,mid);
	if(mid_state == 1){
		if(observe(mid+1,mid+1)==0 || mid == oil_size()-1) return mid;	
		else{
			return findright(mid,end);	//mid+1,end
		} 
		
	}
	//else if(observe(start,end)==1) return end;	//추가 
	else if(mid_state == 0){	//mid가 0이라면 mid부터 오른쪽의 값은 볼 필요 없다 
		return findright(start,mid-1);
	}
}
int main(){
	
	initial();
	int N = oil_size();
	
	Range r = {0,N-1};
	Range temp={0};
	
	temp = findOil(r.i, r.j);
	
//	cout <<"i : "<< temp.i << "\n";
//	cout <<"j : "<< temp.j<< "\n";
	oil_report(temp.i,temp.j);
	return 0;
}
