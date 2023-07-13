#include <bits/stdc++.h>

long long mulm(long long a,long long b,long long m){
	return ((a%m)*(b%m))%m;
}
int modularExponentiation(int x, int n, int m) {
	long long res=1;
	while(n){
		if(n&1) res=mulm(res,(long long)x,(long long)m);
		x=mulm((long long)x,(long long)x,(long long)m);
		n=n/2;
	}
	return (int)res;
}