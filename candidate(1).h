#ifndef CANDIDATE_H
#define CANDIDATE_H

#include<bits/stdc++.h>
using namespace std;

// Voter class
class Candidate{
    private:
        string name, sex, mobile_no;
    public: 
        Candidate(){
            
        }
        Candidate(string name){
            this->name = name;
        }

        // Function to add details of candidate
        void AddDetail(){
            string cname, gen, num;
            cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
            cout<<"Enter the name of Candidate : ";
            getline(cin,cname);
            cout<<"Enter your sex ? (M/F/LGBTQ) : ";
            getline(cin,gen);
            cout<<"Enter your mobile number : ";
            getline(cin,num);
            cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
            
            // Adding Details
            this->name = cname;
            this->sex = gen;
            this->mobile_no = num;
        }

        // name
        string fname(){
            return name;
        }
};

#endif