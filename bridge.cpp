#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double length(double a[], double p[]){
	double dist = 0;
	dist = sqrt(pow(p[0]-a[0],2) + pow(p[1]-a[1],2) + pow(p[2]-a[2],2)); 
	return dist;
}

double binarysort(double a[], double b[], double p[]){
	//그 전에 거리 계산 
	double middle[3] = {(a[0] + b[0])/2, (a[1] + b[1])/2, (a[2] + b[2])/2};
	
	if(length(a,p) > length(b,p)) //A-P > B-P -> B-P, M-P비교
		return binarysort(middle,b,p);
	if(length(a,p) < length(b,p)) //A-P < B-P -> A-P, M-P비교
		return binarysort(a,middle,p);
	if(length(a,p) == length(b,p)) //A-P, M-P 또는 B-P, M-P가 거의 같다  
		return length(middle,p);
}

int main(){
	
	double a[3] = {};
	double b[3] = {};
	double p[3] = {};
	
	ifstream fs_r;
	ofstream fs_w;
	
	fs_r.open("bridge.inp");
	fs_w.open("bridge.out");
	
	if(fs_r.is_open()){
		//파일에서 좌표 입력받기 
		for(int i=0; i<3; i++)
			fs_r >> a[i];
		for(int i=0; i<3; i++)
			fs_r>>b[i];
		for(int i=0; i<3; i++)
			fs_r>>p[i];
			
		for(int i=0; i<3; i++)
		cout << a[i] << " ";
		cout << "\n";
		for(int i=0; i<3; i++)
		cout << b[i] << " ";
		cout << "\n";
		for(int i=0; i<3; i++)
		cout << p[i] << " ";
		
		//분할정복 후 해당 값 리턴 
		double result = binarysort(a,b,p);
		
		cout << "답 : " << ceil(result);
		fs_w << ceil(result);
		fs_r.close();
		fs_w.close();
	}
	return 0;
}
