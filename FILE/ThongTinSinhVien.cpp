#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Date{
    int day;
    int month;
    int year;
};
struct Subject {
    string name;
    int grades;
};
struct Student{
    string name;
    string id;
    Date birthday;
    vector <Subject> Subject_arr;
};
void read_1_student_info(ifstream &FileIn, Student &student){
    getline(FileIn,student.name,',');
    getline(FileIn,student.id,',');
    string temp;
    getline(FileIn,temp,'/'); student.birthday.day=stoi(temp);
    getline(FileIn,temp,'/'); student.birthday.month=stoi(temp);
    FileIn>>student.birthday.year;
    int n; FileIn>>n; temp=""; FileIn.ignore(); 
    for (int i=0; i<n; i++){
        Subject subject_temp;
        getline(FileIn,temp,'-'); subject_temp.name=temp;
        FileIn>>subject_temp.grades;
        student.Subject_arr.push_back(subject_temp);
    }
    FileIn.ignore();   
}
void write_date(const Student &student){
    if (student.birthday.day<10) cout<<"0"<<student.birthday.day<<"/"; else cout<<student.birthday.day<<"/";
    if (student.birthday.month<10) cout<<"0"<<student.birthday.month<<"/"; else cout<<student.birthday.month<<"/";
    cout<<student.birthday.year<<endl;
}
void write_1_student_info(const Student &student){
    cout<<student.name<<", "<<student.id<<", "; write_date(student);
    cout<<student.Subject_arr.size()<<endl;
    for (int i=0; i<student.Subject_arr.size(); i++){
        cout<<student.Subject_arr[i].name<<"-"<<student.Subject_arr[i].grades;
    }
    cout<<endl;
}
void find_Student(const vector <Student> &arr, string name){
    for (int i=0; i<arr.size(); i++){
        if (arr[i].name==name) write_1_student_info(arr[i]);
    }
}
int main(){
    ifstream FileIn ("demo_in.txt");
    vector <Student> arr;
    while (!FileIn.eof()){
        Student st;
        read_1_student_info(FileIn,st);
        arr.push_back(st);
        // write_1_student_info(st);
        // cout<<"\n---------------"<<endl;
    }
    string name; getline(cin,name);
    find_Student(arr,name);
    FileIn.close();
    return 0;
}