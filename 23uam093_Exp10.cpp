#include <iostream>
#include <map>
#include <vector>
#include <numeric>   
#include <algorithm> 
#include <string>

using namespace std;

int main() {
    map<string, vector<int>>students;
    students["Alice"]={80,90,85};
    students["Bob"]={75,65,70};
    students["Charlie"]={88,92,91};
    string topper;
    double highestAverage=0;
    for(auto&entry:students) 
	{
        string name=entry.first;
        vector<int>marks=entry.second;
        int total=accumulate(marks.begin(),marks.end(),0);
        double average=(double)total/marks.size();
        cout<<"Student:"<<name<<",Marks:";
        for (int mark:marks)
            cout<<mark<<" ";
        cout <<"Average:"<<average<<endl;

        if(average>highestAverage){
            highestAverage=average;
            topper=name;
        }
    }
    cout<<"Topper:"<<topper<<"with average"<<highestAverage<<endl;
    return 0;
}

