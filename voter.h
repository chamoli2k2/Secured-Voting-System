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
        void AddDetail(){
            string cname, gen, Age;
            cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<"Enter your Name : ";
            getline(cin,cname);
            cout<<"Enter your sex ? (M/F/LGBTQ) : ";
            getline(cin,gen);
            cout<<"Enter your Age : ";
            getline(cin,age);
            cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
            
            // Adding Details
            this->name = cname;
            this->sex = gen;
            this->age = Age;
        }

        // name
        string fname(){
            return name;
        }
};

#endif 