#include "company.h"

CompanyTracker::CompanyTracker (int n)
  // initializes the tracker with n students and their 1-person companies
{
  numCompanies = n;
  companies = new Company* [numCompanies];
  for (int i = 0; i < numCompanies; ++i){
      companies[i] = new Company ();
    }
}

CompanyTracker::~CompanyTracker ()
  // deallocates all dynamically allocated memory
{
  // your implementation goes here

}
Company* CompanyTracker::helper(Company* merge){
  if(merge->parent==NULL){
    return merge;
    }
  else{
    return helper(merge->parent);
    }
  }


void CompanyTracker::merge (int i, int j)
  /* Merges the largest companies containing students i and j,
     according to the rules described above.
     That is, it generates a new Company object which will
     become the parent company of the largest companies currently
     containing students i and j.
     If i and j already belong to the same company (or are the same),
     merge doesn't do anything.
     If either i or j are out of range, merge doesn't do anything. */
{   
    if(i>=numCompanies ||j>=numCompanies){
      return;
    }
    if(helper(companies[i])==helper(companies[j]))
    {
      return;
    }

        Company *parent1;
    parent1=new Company(helper(companies[i]),helper(companies[j]));
    helper(companies[i])->parent=parent1;
    helper(companies[j])->parent=parent1;


}



void CompanyTracker::split (int i)
  /* Splits the largest company that student i belongs to,
     according to the rules described above.
     That is, it deletes that Company object, and makes sure that
     the two subcompanies have no parent afterwards.
     If i's largest company is a 1-person company, split doesn't do anything.
     If i is out of range, split doesn't do anything. */
{    
   if(i>=numCompanies){
    return;
   }
   Company*parent2=helper(companies[i]);
   Company* a=parent2->merge1;
   Company* b=parent2->merge2;
   parent2->merge2=NULL;
   parent2->merge1=NULL;
   a->parent=NULL;
   b->parent=NULL;
}

bool CompanyTracker::inSameCompany (int i, int j)
  /* Returns whether students i and j are currently in the same company.
     Returns true if i==j.
     Returns false if i or j (or both) is out of range. */
{
      if(i>=numCompanies ||j>=numCompanies){
      return false;
    }

  // your implementation goes here
    if(helper(companies[i])==helper(companies[j])){
      return true;
    }
    else{
      return false;
    }
}


  int main(){
    CompanyTracker c(5);
    c.merge(0,1);
    c.merge(2,3);
    c.merge(0,3);
    c.split(2);
    c.merge(2,4);
    c.split(0);




}

