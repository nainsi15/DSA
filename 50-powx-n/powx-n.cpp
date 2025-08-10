class Solution {
public:
double power( double x , long long n){
    if( n == 0){
        return 1.0;
    }
    if(n == 1){
        return x;
    }
    if( n %2 == 1){
        return x * power(x, n - 1 );
    }
    else{
        return power( x*x, n/2);
    }
}
    double myPow(double x, long long n) {
        long long num = n;
        if( num < 0){
            x = 1/x;
            num = -1*1LL *n;
        }
        return power( x, num);
    }
};