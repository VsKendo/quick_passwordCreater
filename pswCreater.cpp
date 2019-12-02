#include<bits/stdc++.h>
using namespace std;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
//ascii is form 0 to 127
//but 
int input(){
	int tmp;
	while(1){
		if(scanf("%d",&tmp)){
			break;
		}
	}
	return tmp;
}
void printTime(){
	// 基于当前系统的当前日期/时间
   time_t now = time(0);
   
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
   cout << "password created detail：" << endl;
   cout << "local date/time：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC date/time："<< dt << endl;
}

int main(){
	int n;
	cout<<"input the lenth of psw: ";
	while(1){
		n=input();
		//range from 5 to 16
		if(n==0){
			n=15;
			cout<<"using default value, n is 15 now"<<endl;
			break;
		}
		else if(n>=5&&n<=16){
			break;
		}
		else{
			cout<<"n most more then 4 and less than 17"<<endl;
			cout<<"please try again"<<endl;
		}
	}
	char str[n+1],tmp;
	for(int i=0;i<n;++i){
		tmp=rnd()%127;
		while(1){
			if(tmp>=33&&tmp<=126){
				break;
			}
			tmp=rnd()%127;
		}	
		str[i]=tmp;
	}
	str[n]='\0';
	cout<<"complete! your psw is: "<<str<<"\n"<<endl;
	cout<<"it will be write into a file in this dir which filename is out.txt "<<endl;
	cout<<"please remember to save it, good bye"<<endl;
	freopen("out.txt","a+",stdout);
	puts("--------------------------------------");
	printTime();
	cout<<str<<endl;
	puts("--------------------------------------");
	
	return 0;
}
