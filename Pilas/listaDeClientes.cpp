#include<iostream>
#include<list> //doblemente ensalada

using namespace std;

int main(){

    list<int> num;

    num.push_back(10);
    num.push_back(20);
    num.push_back(30);

    for (int i:num)
    {
        cout<<i<<"->";
    }
    cout<<endl;
    num.push_front(50),
    num.push_front(70);
    for (int  i : num)
    {
        cout <<i<<"->";
    }
    
num.pop_front();
num.pop_back();
for (int i : num)
{
    cout<<i<<"->";
}









    return 0;
}