#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;

	b = 0;
	c = 0;
	

		cin >> b;
		c=b/5;
		d=b%5;
		if(d==1){
		
		 if(b>=6) c+=1;
			else c=-1;
		}
		if(d==2){
		 if(b>=12) c+=2;
		else c=-1;
		}
		if(d==3) c+=1;
		if(d==4) {	if(b>=9) c+=2
		;
		else c=-1;
		}
		cout<<c;




}