#include <iostream>
#include "vector.h"
#include <vector>
#include "DeriveAndBase.h"
using namespace::std;
int main() {

   vector<int > stl_vec;
   for(int i = 0; i < 35566; i++){
       stl_vec.push_back(i);
   }
   cout << stl_vec.size() << endl;
   cout << stl_vec.capacity() << endl;


   for(int i = 0; i < 35566; i++){
       stl_vec.pop_back();
   }

   cout << stl_vec.size() << endl;
   cout << stl_vec.capacity() << endl;

   stl_vec.push_back(0);
   stl_vec.push_back(1);
   stl_vec.push_back(2);
   stl_vec.push_back(3);
   stl_vec.push_back(4);
   auto it = stl_vec.begin();
   for(int i = 0; i < 3; i++){
       it++;
   }
   stl_vec.erase(it);
   for(auto it = stl_vec.begin(); it != stl_vec.end(); it++){
       cout << *it << endl;
   }

   Vector<int> vec;
   vec.push_back(10);
   vec.push_back(16);
   for(auto it = vec.begin(); it != vec.end(); it++){
       cout << *it <<endl;
   }

   return 0;
}