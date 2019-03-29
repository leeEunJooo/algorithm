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
	//�� ���� �Ÿ� ��� 
	double middle[3] = {(a[0] + b[0])/2, (a[1] + b[1])/2, (a[2] + b[2])/2};
	
	if(length(a,p) > length(b,p)) //A-P > B-P -> B-P, M-P��
		return binarysort(middle,b,p);
	if(length(a,p) < length(b,p)) //A-P < B-P -> A-P, M-P��
		return binarysort(a,middle,p);
	if(length(a,p) == length(b,p)) //A-P, M-P �Ǵ� B-P, M-P�� ���� ����  
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
		//���Ͽ��� ��ǥ �Է¹ޱ� 
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
		
		//�������� �� �ش� �� ���� 
		double result = binarysort(a,b,p);
		
		cout << "�� : " << ceil(result);
		fs_w << ceil(result);
		fs_r.close();
		fs_w.close();
	}
	return 0;
}
