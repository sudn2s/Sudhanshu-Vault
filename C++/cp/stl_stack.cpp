
#include <iostream>
#include<stack>
#include<cstring>

using namespace std;
int main() {
    stack<string> s;

   s.push("Sudhanshu");
   s.push("Ajey");
   s.push("aman");
   while(!s.empty()){
       cout<<s.top()<<endl;
        s.pop();      
   }
}
