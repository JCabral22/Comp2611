#include <iostream>


void printSequence(int n){
    if(n==0){
        return;
    }
    std::cout<<n<<std::endl;
    printSequence(n-1);

}

void printSequence2(int n, int curr){
    if(curr > n){
        return;
    }
    std::cout<<curr<<std::endl;
    printSequence2(n,curr+1);

}


void hailstone(int n){
    if(n<=1){
        std::cout<<std::endl;
        return;
    }
    std::cout<<n<<" ";
    n%2==0 ? hailstone(n/2) : hailstone((n*3)+1); 
}


void swap (int * x, int * y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    std::cout << "After Swapping: x =" << *x << ", y=" << *y<<std::endl;


}



int main(){

}