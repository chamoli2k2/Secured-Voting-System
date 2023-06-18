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
#include "welcome.h"
#include<stdlib.h>
#include<fstream>

using namespace std;
int main(){
    // Variable Declaration
    ifstream fileIn;
    int nCand, nVoter;
    Welcome k;
    k.voting();
    cout<<endl<<endl<<"Press key to enter : ";
    cin.ignore();
    system("CLS");
    
    // Step 1 : Creating the Database for candidate and voter
    DBC DbCandidate;
    DBV DbVoter;

    // Step 2 : Taking cruical detail 
    fileIn.open("inputData.txt");
    fileIn>>nCand>>nVoter;

    // Step 3 : Creating Candidate profile
    for(int i=0;i<nCand;i++){
        cout<<"--------------------------------Fill the Candidate Detail--------------------------------"<<endl;
        // Creating a candidate
        Candidate *cand = new Candidate();
        cand->AddDetail();
        // Adding Candidate to the candidate database
        DbCandidate.Add(cand);
        system("CLS");
    }

    
    for(int i=0;i<nVoter;i++){
        cout<<"--------------------------------Fill the voter Details--------------------------------"<<endl;
        // Creating the candidate
        Voter* vt = new Voter();
        pair<string,string> VV;
        VV.first = vt->AddDetail();
        // Adding Voter to voter database
        VV.second = DbVoter.Add(vt);

        // Starting voting
        cout<<endl<<"--------------------------------Start Voting--------------------------------"<<endl<<endl;
        cout<<"Candidate No : Candidate Name -> Candidate ID"<<endl<<endl;
        DbCandidate.ListC();
        cout<<endl<<endl<<"------------------------------------------------------------"<<endl<<endl;
        // Checking Voter ID of voter
        string id;
        cout<<"Enter your Voter ID : ";
        cin>>id;

        // Checking if there voter exist with this ID and also is he eligible for vote
        if(DbVoter.check(id)){
            DbCandidate.GiveVote();
            DbVoter.VoteMark(VV.second);
        }
        else{
            cout<<endl<<"--------------------------------Voter is Not Eligible to Vote--------------------------------"<<endl;
            cin.ignore();
        }

        cin.ignore();
        system("CLS");
    }

    cout<<endl<<"--------------------------------Voting Result--------------------------------"<<endl<<endl;
    // Step 8 : Declaration of Results
    DbCandidate.DeclareResult();

    return 0;
}