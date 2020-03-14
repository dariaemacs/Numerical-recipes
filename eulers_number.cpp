// Calculation of Euler's Number using the Taylor Series approximation (Maclaurin series, it's more precisely). 
// Created by DariaEmacs (http://www.youtube.com/DariaEmacsHappy)
// This algorithm was written in AlgoL originally. I rewrote it in C++.
// The video about this code is https://youtu.be/EgKfZBAJZoE

#include <vector>
#include <iomanip>
#include <iostream>

void print(std::vector<int>& v){
  for(auto i: v){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void get_exponent(std::vector<int>& a, std::vector<int>& b,
		  std::vector<int>& e){
  if(a.size() != e.size() || b.size() != e.size()){
    return;
  }

  e[0] = 1;
  b[0] = 1;

  for(int n = 1; n < e.size(); ++n){
    // Saving old member of the series in vector "a": vector "a" = vector "b"
    for(int i = 0; i < e.size(); ++i){
      a[i] = b[i];
    }
    int c = a[0];
    // Calculation new member of the series: vector "b" = vector "a" / n
    for(int i = 0; i < e.size() - 1; ++i){
      b[i] = c / n;
      c = (c - n * b[i]) * 10 + a[i+1];
    }
    int p = 0;
    // Addition last member of the series to e: vector "e" += vector "b"
    for(int i = e.size(); i >= 0; --i){
      c = e[i] + b[i] + p;
      p = 0;
      if(c < 10){
	e[i] = c;
      }else{
	e[i] = c - 10;
	p = 1;
      }
    }
  }
}

int main(){
  const int signs = 600;

  std::vector<int> a(signs, 0);
  std::vector<int> b(signs, 0);
  std::vector<int> e(signs, 0);

  get_exponent(a, b, e);
  
  std::cout << "e = " << e[0] << ".";
  for(int i = 1; i < e.size() - 9; ++i){
    std::cout << e[i];
    if(i % 6 == 0){
      std::cout << "\t ";
    }
  }
  std::cout << std::endl;
}
