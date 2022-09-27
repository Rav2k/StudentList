/* Author: Wade Owojori
   Date:9/15/22
   Purpose: Creating a lists of students and storing their information
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;
struct student {//creates a struct with the info needed from the user
  char firstName[20];
  char lastName[20];
  int studentID;
  float GPA;
};
//defining the functions up here because they are below main and are used in main 
void add(vector<student*>& studentInfo);
void print(vector<student*>& studentInfo);
void del(vector<student*>& studentInfo);

int main(){
  vector<student*> studentInfo;//creating a vector to hold the info from the struct 
  char userInput[10];
do{//do this until the user says quit
 cout<<"Type 'add' to add student;Type 'del' to delete student;Type 'print' to print all student's info;Type 'quit' to quit"<<endl; //tells the user the options

 cin.getline(userInput,10,'\n');//gets the user's request then clears the cin
  
  if(strcmp(userInput, "add") == 0){//if they say add run the add function
    add(studentInfo);
  }
  if(strcmp(userInput, "print")==0){//if they say print run the print function
    print(studentInfo);//pass in the vector as a parameter in code so the that the information goes into the vector
  }
  if(strcmp(userInput, "del")==0){//if they say delete run the delete function
    del(studentInfo);
  }
  }while(strcmp(userInput, "quit") != 0);

  return 0;

}

void add(vector<student*>&studentInfo){//add function 
    student* info  = new student();//creates a pointer variable
    cout<<"Enter Student's first name"<<endl;
    cin>>info->firstName;//puts the information from the user into the firstname char
    cout<<"Enter Student's last name"<<endl;
    cin>> info->lastName;
    cout<<"Enter Student's ID number"<<endl;
    cin>>info->studentID;
    cout<<"Enter Student's GPA"<<endl;
    cin>>info->GPA;
    cin.ignore();//ignores the stuff that was originally in the cin
    cout<<endl;
    cout<<info->firstName << " "<< info->lastName<<endl;
    cout<<"ID: "<< info->studentID<<endl;
    cout<<setprecision(3)<<"GPA: "<<info->GPA<<endl;
    studentInfo.push_back(info);//pushes the stuff from the info into one spot in the vector's memeory
}

void print(vector<student*>&studentInfo){
  vector<student*>::iterator ptr;//cretes an iteration
  cout<<endl;
  for (ptr = studentInfo.begin(); ptr != studentInfo.end(); ptr++){//goes through the vector and prints the last day.
    cout<<endl;
    cout<<(*ptr)->firstName<<" "<<(*ptr)->lastName<<endl;
    cout<<(*ptr)->studentID<<" "<<(*ptr)->GPA<<endl;
    
  }
}

void del(vector<student*>&studentInfo){
  vector<student*>::iterator ptr;
  int userdel;
  cout<<"Type the Student's ID number: "<<endl;//get' the ID of the person who needs to be deleted so we can find it in the vector and delete that whole spot in memory
  cin>>userdel;
   
  for (ptr = studentInfo.begin(); ptr != studentInfo.end(); ptr++){
    if((*ptr)->studentID == userdel){//if the id is equal to one of the Id's in the vector then delete all the information about it
      delete *ptr;
      studentInfo.erase(ptr);
      break;
    }
  }

}
  
