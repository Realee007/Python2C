%module fac_module
%{
int fac_function(int n){
	if (n >1)
		return n*fac_function(n-1);
	return 1;
	}
%}
int fac_function(int n);