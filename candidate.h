#ifndef CANDIDATE_H
#define CANDIDATE_H

#include<bits/stdc++.h>
#include<fstream>
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
            ofstream fileOut;
            fileOut.open("candidateData.txt",ios::app);
            string cname, gen, num;
            cout<<"Enter the name of Candidate : ";
            getline(cin,cname);
            fileOut<<cname<<"-";
            cout<<"Enter your sex ? (M/F/LGBTQ) : ";
            getline(cin,gen);
            fileOut<<gen<<"-";
            cout<<"Enter your mobile number : ";
            getline(cin,num);
            fileOut<<num<<"\n";
            
            // Adding Details
            this->name = cname;
            this->sex = gen;
            this->mobile_no = num;
            fileOut.close();
        }

        // name
        string fname(){
            return name;
        }
};

#endif