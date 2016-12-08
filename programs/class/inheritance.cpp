#include <iostream>
#include <vector>

using namespace std;


class Person{
 protected:
  string firstName;
  string lastName;
  int id;
 public:
  Person(string firstName, string lastName, int identification){
    cout<<"Person ctor called";
   this->firstName = firstName;
   this->lastName = lastName;
   this->id = identification;
  }
  void printPerson(){
   cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
  }
 
};


class Student :  public Person{
 private:
  vector<int> testScores;  
 public:
    // Write your constructor
    Student(string firstname, string lastname, int id, vector<int> scores):Person(firstname, lastname, id), testScores(scores) {       
    }
  
// Write char calculate()
   char calculate() {
      int sum = 0;
      int avg = 0;
      for(int i = 0; i<testScores.size(); i++) {
          sum = sum+testScores[i];
      }
      avg = sum/2;
      cout<<"sum is "<<sum<<" avg is "<<avg<<"\n";
      if(avg >= 90) {
         return 'O';
      } else if (avg <90 && avg >=80) {
           return 'E';
      } else if(avg<80 && avg >= 70) {
            return 'A';
      } else if(avg < 70 && avg >= 55) {
            return 'P';
      } else if (avg <55 && avg >= 40) {
            return 'D';
      } else {
            return 'T';
      }
    } 
};


int main() {
 string firstName;
   string lastName;
 int id;
   int numScores;
 cout<<"enter inputs\n";
 cin >> firstName >> lastName >> id >> numScores;
   vector<int> scores;
   for(int i = 0; i < numScores; i++){
    int tmpScore;
    cin >> tmpScore;
  scores.push_back(tmpScore);
 }
 Student* s = new Student(firstName, lastName, id, scores);
 s->printPerson();
 cout << "Grade: " << s->calculate() << "\n";
 return 0;
}
