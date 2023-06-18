#ifndef VOTER_H
#define VOTER_H

#include<bits/stdc++.h>
using namespace std;

// Voter class
class Voter{
    private:
        string name, sex, age;
    public: 
        // Function to add details of Voter
        string AddDetail(){
            ofstream fileOut;
            fileOut.open("voterData.txt",ios::app);
            string cname, gen, Age;
            cout<<"Enter your Name : ";
            getline(cin,cname);
            fileOut<<cname<<"-";
            cout<<"Enter your sex ? (M/F/LGBTQ) : ";
            getline(cin,gen);
            fileOut<<gen<<"-";
            cout<<"Enter your Age : ";
            getline(cin,age);
            fileOut<<age<<"\n";
            
            // Adding Details
            this->name = cname;
            this->sex = gen;
            this->age = Age;
            fileOut.close();

            return cname;
        }

        // name
        string fname(){
            return name;
        }
};
#endif 