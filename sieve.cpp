#include<iostream>
#include"stdc++.h"
using namespace std;

#if 0
Sieve Implementation in Templates, later will optimize it to constexpr to save compile computation
#endif

template<typename t = int,typename container = std::vector<bool>>

container sieve(t n){
  int count = 0;
  container is_prime(n+1 ,true);
  if(n >= 0)is_prime[0] = false;count++;
  if(n>=1)is_prime[1] = false;count++;
  

  for(t i{2};i*i<=n;i++){
    if(is_prime[i]){
      for(t j{i*i};j<=n;j+=i){
        is_prime[j] = false;
        count++;
      }
    }
  }
  return is_prime;
}

int main(){
  long long n{};
  std::cout << "Please enter your n, Remeber we will traverse sqrt" << endl;
  cin >> n;
  using Int = decltype(n);
  auto p = sieve<Int>(n);

  for(Int i{2};i*i<=n;i++){
    if(p[i]){std::cout << i << std::endl;}
  }
  return 0;
}
