// ------------------------------------ Project Name : Voting System -----------------------------------------
// ------------------------------------- Contribution ----------------------------------
//                                     1) Gaurav Prakash   (21/11/EC/041)
//                                     2) Harsh Bansal     (21/11/EC/037)
//                                     3) Shivam           (21/11/EC/046)
//                                     4) Vishal Saini     (21/11/EC/029) 

// --------------------------------- Projected Created on 24/05/2023 ------------------------

#include<bits/stdc++.h>
#include "voter.h"
#include "database.h"
#include "candidate.h"

using namespace std;
int main(){
    // Variable Declaration
    int nCand, nVoter, flag = true;
    cout<<"--------------------------------Voting System---------------------------------------"<<endl<<endl;
    // Step 1 : Creating the Database for candidate and voter
    DBC DbCandidate;
    DBV DbVoter;

    // Step 2 : Taking Input of number or candidate participating in the election
    cout<<"Enter the number of Candidate : ";
    cin>>nCand;
    cin.ignore();

    // Step 3 : Creating Candidate profile
    for(int i=0;i<nCand;i++){
        // Creating a candidate
        Candidate *cand = new Candidate();
        cand->AddDetail();
        // Adding Candidate to the candidate database
        DbCandidate.Add(cand);
    }

    // Step 4 : Taking Votes from Voter and Recording Voting Data
    cout<<endl<<"Enter Number of Voter : ";
    cin>>nVoter;
    cin.ignore();
    cout<<endl<<"-----------------------------------------------------------------"<<endl<<endl;

    for(int i=0;i<nVoter;i++){
        // Creating the candidate
        Voter* vt = new Voter();
        vt->AddDetail();
        // Adding Voter to voter database
        DbVoter.Add(vt);
    }

    // Step 5 : Showing List of all Candidate to the voter Before Voting
    cout<<"Candidate No : Candidate Name -> Candidate ID"<<endl<<endl;
    DbCandidate.ListC();
    cout<<endl<<endl<<"------------------------------------------------------------"<<endl;

    // Step 6 : Showing List of all Voter Before Voting
    cout<<"Voter No : Voter Name -> Voter ID"<<endl<<endl;
    DbVoter.ListV();
    cout<<endl<<endl<<"------------------------------------------------------------"<<endl;


    // Step 7 : Starting Voting
    for(int i=0;i<nVoter && flag;i++){
        // Checking Voter ID of voter
        string id;
        cout<<"Enter your Voter ID : ";
        cin>>id;

        // Checking if there voter exist with this ID and also is he eligible for vote
        if(DbVoter.check(id)){
            DbCandidate.GiveVote();
            DbVoter.VoteMark(id);
        }
        else{
            cout<<endl<<"--------------------------Voter is Not Eligible to Vote-----------------------------"<<endl;
        }

        cout<<"Still Voter Left ? (yes '1' / no '0') : ";
        cin>>flag;
        if(flag == 0) break;
        cout<<endl;
    }

    cout<<endl<<"-----------------------------------------------------------------------------------------------"<<endl<<endl;
    // Step 8 : Declaration of Results
    DbCandidate.DeclareResult();

    return 0;
}