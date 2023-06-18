#ifndef DATABASE_h
#define DATABASE_h

#include<bits/stdc++.h>
#include "candidate.h"
#include "voter.h"
using namespace std;

// Creating Database for Candidate
class DBC{
    private:
        unordered_map<Candidate*,int> COD;
        unordered_map<int,Candidate*> CID;
        unordered_map<int,int> votes;
    public:
        // Constructor
        DBC(){
            Candidate* Nota = new Candidate("NOTA");
            COD[Nota] = true;
            CID[-1] = Nota;
        }

        // Adding candidate to the database
        void Add(Candidate *cand){
            // Marking candidate registered
            COD[cand] = true;
            int num = rand() % 100 + 1;
            while(CID.find(num) != CID.end()){
                num = rand() % 100 + 1;
            }
            // Adding candidate with it's Unique ID
            CID[num] = cand;
        }

        // Fuction to show list of Candidates
        void ListC(){
            int idx = 1;
            for(auto &it : CID){
                if(it.first == -1) continue;
                cout<<" Candidate "<<idx<<" : "<<it.second->fname()<<" -> "<<it.first<<endl;
                idx++;
            }
            cout<<" Candidate "<<idx<<" : "<<"NOTA"<<" -> "<<-1<<endl;
        }

        // Function to take votes
        void GiveVote(){
            int kid;
            cout<<"Enter the Candidate ID of Candidate to vote for : ";
            cin>>kid;
            while(CID.find(kid) == CID.end() && kid != -1){
                cout<<"Candidate ID entered is wrong , Enter correct Candidate ID : ";
                cin>>kid;
            }
            votes[kid]++;
        }


        // Declare Results
        void DeclareResult(){
            priority_queue<pair<int,int>> pq;
            int total = 0;
            for(auto &it : votes){
                total += it.second;
                pq.push({it.second,it.first});
            }

            cout<<"Candidate Name : Vote %"<<endl;
            int countNota = (votes[-1] *1.00* 100) / total;
            while(!pq.empty()){
                int v = pq.top().first;
                int id = pq.top().second;
                pq.pop();
                int per = (v *1.00* 100) / total;

                cout<<CID[id]->fname()<<" : "<<per<<"%"<<endl;
            }

            for(auto it : CID){
                if(votes[it.first] == 0){
                    cout<<CID[it.first]->fname()<<" : "<<0<<"%"<<endl;
                }
            }
        }
};

// Creating Database for Voter
class DBV{
    private:
        unordered_map<Voter*,bool> VID;
<<<<<<< HEAD
        unordered_map<string,Voter*> VoterID;
        unordered_map<string,bool> VoteGiven;
    public:
        // Checking if voter is valid
        bool check(string id){
            if(VoterID.find(id) == VoterID.end() || VoteGiven[id] == 1){
                return false;
            }
=======
        unordered_map<string,Voter*> VoterNo;
        unordered_map<string,bool> VoterID;
        unordered_map<string,bool> VoteGiven;
    public:
        DBV(){
            ifstream fileIn;
            fileIn.open("VoterID.txt");
            string line;

            while (getline(fileIn,line)) {
                VoterID[line] = true;
            }

            fileIn.close();
        }

        // Checking if voter is valid
        bool check(string id){
            if(VoterID[id] == false || VoteGiven[id] == 1){
                return false;
            }
            ofstream fileOut;
            fileOut.open("votingData.txt",ios::app);
            fileOut<<id<<'\n';
>>>>>>> master
            return true;
        }

        // Adding voter to the database
<<<<<<< HEAD
        void Add(Voter *vt){
=======
        string Add(Voter *vt){
>>>>>>> master
            // Marking candidate registered
            VID[vt] = true;
            int num = rand() % 100 + 1;
            string id = to_string(num);
<<<<<<< HEAD
            while(VoterID.find(id) != VoterID.end()){
=======
            while(VoterNo.find(id) != VoterNo.end()){
>>>>>>> master
                num = rand() % 100 + 1;
                id = to_string(num);
            }
            // Adding candidate with it's Unique ID
<<<<<<< HEAD
            VoterID[id] = vt;
=======
            VoterNo[id] = vt;
            return id;
>>>>>>> master
        }

        // Marking Vote is given
        void VoteMark(string id){
            VoteGiven[id] = true;
        }
<<<<<<< HEAD

        // Fuction to show list of Candidates
        void ListV(){
            int idx = 1;
            for(auto it : VoterID){
                cout<<" Voter "<<idx<<" : "<<it.second->fname()<<" -> "<<it.first<<endl;
                idx++;
            }
        }
=======
>>>>>>> master
};

#endif