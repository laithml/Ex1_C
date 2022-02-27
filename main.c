#include <stdio.h>
#define true 1
#define false 0
#include <limits.h>
int isPrime(int x){
    if(x==2){
        return true;
    }
    if(x<2)
        return false;
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int nextPrime(int num){
    int res=0;
    if(num<2)
        return 2;
    for(int i=num+1;i<INT_MAX;i++){
        if(isPrime(i)==1) {
            res = i;
            return res;
        }
    }
    return false;
}


int isPalindromLoop(int num,int len){
    int arr[len],i,j=len-1;

    for(i=0;i<len;i++){
        arr[i]=num%10;
        num/=10;
    }
    for(i=0;i<(len/2)+1;i++){
        if(arr[i]!=arr[j])
            return false;
        j--;
    }

    return true;

}
int countDigit(int x){
    int count=1;
    while(x>9){
        x/=10;
        count++;
    }
    return count;
}
int isPalindrom(int num) {

    int len= countDigit(num);
    return isPalindromLoop(num,len);

}
int containsNonPrimesDigitsOnly(int num){
    int m=0;
    while(num>0){
        m=num%10;
        if(isPrime(m)==1){
            return false;
        }
        num/=10;
    }
    return true;
}

int isSpecial(int num) {

    if(isPrime(num)==1&& isPalindrom(num)==1&& containsNonPrimesDigitsOnly(num)==1)
        return 1;

    return 0;
}
void printAllSpecial(int from, int to) {
   int num=from;
    while(num<=to){
        if(isSpecial(num)==1)
            printf("%d\n",num);
        num++;
    }
}


