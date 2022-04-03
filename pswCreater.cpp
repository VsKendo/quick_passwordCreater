#include <iostream>
#include <ctime>
#include<chrono>
#include <random>
using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(seed);

// get the length of password from user
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
   time_t now = time(0);

   char* dt = ctime(&now);
   cout << "password created detail" << endl;
   cout << "local date/time: " << dt << endl;
 
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC date/time: "<< dt << endl;
}

int main(){
	int n;
	cout<<"input the lenth of password: ";
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
	cout<<"complete! your password is: "<<str<<"\n"<<endl;
	cout<<"this result will be written into out.txt "<<endl;
	cout<<"please remember to save it, good bye"<<endl;
	freopen("out.txt","a+",stdout);
	puts("--------------------------------------");
	printTime();
    cout<<"your password is: "<<endl;
	cout<<str<<endl;
	puts("--------------------------------------");
	
	return 0;
}
