/**
*
* @Name : CppFileUse/main.cpp
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-06-26
* @Released under : https://github.com/BaseMax/CppFileUse/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/CppFileUse
*
**/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string search, product[100], edit, save1[100], save2[100];

int action, item=0, index1, index0=1, index2;
void display() {
	fstream file("output.txt", ios::in);
	if(!file) {
		cerr<<"Cannot open file!"<<endl;
		exit(1);
	}
	cout <<" List: "<<endl<<endl;
	index0=1;
	while(file>>product[index0]) {
		cout<<" "<<index0<<". "<<product[index0]<<endl;
		index0++;
	}
}

int main(int argc, char** argv) {
	display();
	cout<<endl<< " Enter a action: "<<endl<<" 1. add  2.edit  3.delete  4.search"<<endl;
	cin >> action;
	if(action == 1) {
		fstream file ("output.txt", ios::app);
		if(!file) {
			cerr<<"Cannot open file!"<<endl;
			exit(1);
		}
		cout << "Enter a name : "<<endl;
		while(cin>>product[index0]) {
			file <<product[index0]<<endl;
			index0++;
		}
	}
	if(action==2) {
		cout<<"Enter a item from the list: "<<endl;
		cin>>item;
		fstream file("output.txt", ios::in);
		if(!file) {cerr<<"Cannot open file!"<<endl;exit(1);}
		index0=1;
		while(file>>product[index0]) {
			if(index0<item)
				save1[index0]=product[index0];
			index0++;
			if(index0==item)
				index0++;
			if(index0>item)
				save2[index0]=product[index0];
		}
		while(index1<1) {
			fstream file ("output.txt", ios::out);
			if(!file) {
				cerr<<"Cannot open file!"<<endl;
				exit(1);
			}
			for(index0=1;index0<item;index0++) {
				product[index0]=save1[index0];
				file <<product[index0]<<endl;
			}
			index1=1;
		}
		while(index2<1) {
			fstream file ("output.txt", ios::app);
			if(!file) {
				cerr<<"Cannot open file!"<<endl;
				exit(1);
			}
			cout << "Enter new name: "<<endl;
			cin>>product[index0];
			file <<product[index0]<<endl;
			for(index0=item+1;index0<=100;index0++) {
				product[index0]=save2[index0];
				file <<product[index0]<<endl;
			}
			index0=1;
			display();  
			index2=1;
		}
		display();
	}
	if(action==3) {
		cout<<"Enter a item from the list: "<<endl;
		cin>>item;
		fstream file("output.txt", ios::in);
		if(!file) {
			cerr<<"Cannot open file!"<<endl;
			exit(1);
		}
		index0=1;
		while(file>>product[index0]) {
			if(index0<item)
				save1[index0]=product[index0];
			index0++;
			if(index0==item)
				index0++;
			if(index0>item)
				save2[index0]=product[index0];
		}
		while(index1<1) {
			fstream file ("output.txt", ios::out);
			if(!file) {
				cerr<<"Cannot open file!"<<endl;
				exit(1);
			}
			for(index0=1;index0<item;index0++) {
				product[index0]=save1[index0];
				file <<product[index0]<<endl;
			}
			index1=1;
		}
		while(index2<1) {
			fstream file ("output.txt", ios::app);
			if(!file) {
				cerr<<"Cannot open file!"<<endl;
				exit(1);
			}
			for(index0=item+1;index0<=100;index0++) {
				product[index0]=save2[index0];
				file <<product[index0]<<endl;
			}
			display();
			index2=1;
		}
	}
	if(action==4) {
		cout<<"Enter a word: "<<endl;
		cin>>search;
		fstream file("output.txt", ios::in);
		if(!file) {
			cerr<<"Cannot open file!"<<endl;
			exit(1);
		}
		index0=1;
		while(file>>product[index0]) {
			if(product[index0]==search) {
				cout<<index0<<". "<<product[index0]<<endl;
			}
			index0++;
		}
	}  
	display();
	return 0;
}
