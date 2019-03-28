#include <iostream>
#include "oil.h"

using namespace std;

struct{
	int i;
	int j;
}typedef Range;


int findleft(int start, int end);
int findright(int start, int end);

//1. �������ִ� ��츦 ã�� 
//2. ���ʿ��� ������ ã��
//3. �����ʿ��� ������ ã�� 
Range findOil(int start, int end){
//	cout << start <<" ";
//	cout << end <<"\n";

	Range tempR = {start, end};
	
	int mid = (start + end)/2;
	int mid_state = observe(mid,mid);

	//cout <<"front : "<< front <<" back : " <<back << "\n";

	if(mid_state==1) {
		tempR.i = findleft(start,mid);	//����
		tempR.j = findright(mid,end);	//������ 
		return tempR;
	}
	else if(mid_state==0){
 		if(observe(start,mid-1)==0){	//mid�� 0�ε� mid������ ��� 0���� �˾ƺ���. 
			findOil(mid+1,end);
		}
		else{	//mid������ �ٸ� �͵��� �ִٸ�  
			findOil(start,mid-1);	//mid ������ ���� ���� �ִ��� ��. mid���� �̹� ��� �̵� �������ͺ� 
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
	//else if(observe(start,end)==1) return start;	//�߰� 
	else if(mid_state == 0){
		return findleft(mid+1,end);	//mid�� 0�̶�� mid ������ ���� �� �ʿ� ���� 
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
	//else if(observe(start,end)==1) return end;	//�߰� 
	else if(mid_state == 0){	//mid�� 0�̶�� mid���� �������� ���� �� �ʿ� ���� 
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
