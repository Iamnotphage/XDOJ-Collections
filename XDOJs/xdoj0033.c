//xdoj0033.c
double function(int n){  
 	return n==1?1:1/(1+function(n-1));
}