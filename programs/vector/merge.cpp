#include<iostream>
#include<vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval():start(0),end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> intervals;
  vector<Interval> insert(vector<Interval> &inter, Interval I);
  void print(vector<Interval> it);
};

void swap(Interval &newInterval) { 
    if (newInterval.start > newInterval.end) {
        int temp1 = 0;
        temp1 = newInterval.end;
        newInterval.end = newInterval.start;
        newInterval.start = temp1;
    } 
}

Interval setend(vector<Interval> &intervals, Interval &newInterval, int &i) {
  cout<<"In Function setend\n";
  Interval Temp;
  Temp.start = 0;
  if(newInterval.end < intervals[i].start) {
      cout<<"setend1\n";
      Temp.end = newInterval.end;
  }
  if(newInterval.end >= intervals[i].start) {
     cout<<"setend2\n";
     if (newInterval.end < intervals[i].end) {
        cout<<"setend3\n";
        Temp.end = intervals[i].end;
      }
      for (; i< intervals.size(); ++i) {
         cout<<"setend inside for i = "<< i<<"\n";
         if (newInterval.end >= intervals[i].end) {
            cout<<"setend5\n";
            if (i == ((intervals.size())-1)) {
              if (newInterval.end >= intervals[(intervals.size())-1].end) {
                 cout<<"setend6\n";
                 Temp.end = newInterval.end; i++;
                 break;
              }
            }
           continue;
         }
         if (newInterval.end <= intervals[i].end) {
           cout<<"setend7\n";
           Temp.end = intervals[i].end;
                      i++;
                      break;
         }
      }
  }
  return Temp;
}

void sort_array(vector<Interval> &intervals) {

  Interval temp;
  for(int i=0; i< intervals.size(); ++i) {

      int j = i;
      for(int k=i+1; k<intervals.size(); ++k) {
        if(intervals[k].start < intervals[j].start) {
            j=k;
 
         }
      }

      temp.start = intervals[i].start;
      temp.end = intervals[i].end;

      intervals[i].start = intervals[j].start;
      intervals[i].end = intervals[j].end;

      intervals[j].start = temp.start;
      intervals[j].end = temp.end;
   }
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    Interval Temp,Temp1;
    cout<< " new intervals = (" << newInterval.start<<","<<newInterval.end<<")\n";
    int count =0;
    swap(newInterval);
    
    for(int i = 0; i< intervals.size(); ++i) {
       cout<<"In first For Loop\n";
       if ((newInterval.start<=intervals[i].start) && ( count == 0)) {
         cout<<"TEST1\n";
         Temp.start = newInterval.start;
         Temp1 =setend(intervals, newInterval, i);
         Temp.end = Temp1.end;
         count++;
         res.push_back(Temp);
       }
      
       if ((newInterval.start > intervals[i].start) && (count == 0)) {
          cout<<"TEST2\n";
          Temp.start = intervals[i].start;
          if(newInterval.start > intervals[i].end) {
             cout<<"TEST3\n";
             Temp.end = intervals[i].end;
          } else {
             cout<<"TEST4\n";
             if (newInterval.end < intervals[i].end) {
                cout<<"TEST5\n";
                Temp.end = intervals[i].end;
             } else {
               cout<<"TEST6\n";
               for( ; i< intervals.size(); ++i) {
                     cout<<"Inside for of end \n";
                  if (newInterval.end >= intervals[i].end) {
                     cout<<"TEST7\n";
                     if (i == ((intervals.size())-1)) {
                     if(newInterval.end >= intervals[(intervals.size()) -1].end) {
                         Temp.end = newInterval.end;
                         count++; i++;
                         break;
                     }
                     }
                     continue;
                  }
                  if (newInterval.end < intervals[i].end) {
                      cout<<"TEST9 "<< i<<"\n";
                      Temp.end = intervals[i].end;
                      count++;
                      i++;
                      break;
                  }
               }
             }
          }
          if ((newInterval.start > intervals[(intervals.size())-1].end) && (count == 0)) {
             cout << "Test10\n";
             Temp.start =  newInterval.start;
             Temp.end = newInterval.end;
             count++;
          }
         res.push_back(Temp);
      }
      if (( count!=0 ) && (i < (intervals.size()))) {
            cout <<"Other Pushes i = "<< i <<"\n";
            cout << "intervals.size = "<<intervals.size() <<"\n";
            Temp.start = intervals[i].start;
            Temp.end = intervals[i].end;
            res.push_back(Temp);
       }
    }// for
    sort_array(res);
    return res;  
} 

void Solution::print(vector<Interval> it) {

  cout<<"****************************************\n";
  for(int i=0;i < it.size(); ++i) {
    cout<<"("<<it[i].start<<","<<it[i].end<<")";
  }  
  cout<<"\n";
}

int main() {

  Solution S;
  vector<Interval> sorted_intervals;
  vector<Interval> sorted_intervals_print;
 
  sorted_intervals.push_back(Interval(2,5));
  sorted_intervals.push_back(Interval(10,12));
  sorted_intervals.push_back(Interval(13,17));
  sorted_intervals.push_back(Interval(19,24));

 
  S.print(sorted_intervals);
  Interval merge;
  int s, e;
  cout <<"Enter the merge intervals\n";
  cin >> s;
  cin>>e;
  merge.start = s;
  merge.end = e;
  sorted_intervals_print = S.insert(sorted_intervals, merge);
  S.print(sorted_intervals_print);
  return 0;
}
