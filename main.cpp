#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
long long workers=0,janitors=0,floors=0,totalfund=7500,profit=0,workercapacity;
int workersavaliableforhire;
long long day=1;
bool economicrises,economicrise,economicrises1;
void buying(){
cout << "Workers avaliable for hire: " << workersavaliableforhire << endl;
cout << "Worker - 200$ initially, 100$ for wages" << endl << "Janitor - 100$ initially, 25$ for wages." << endl << "Floor - 250$, 100$ for upkeep" << endl;
cout << "Type a number from 1 to 3, or exit to stop buying." << endl;
string answer;
while(answer!="exit"){
cin >> answer;
if(answer=="1"){
    if(workers==workercapacity){
        cout << "Get more floors!" << endl;
    }
    else if(workersavaliableforhire==0){
        cout << "You cant hire more workers. No more applicants." << endl;
    }
    else{
    cout << "You just bought a worker!" << endl;
    workers++;
    workersavaliableforhire--;
    totalfund=totalfund-200;}
}
if(answer=="2"){
    if(janitors==floors){
        cout << "You dont need more janitors." << endl;
    }
    else{
    cout << "You bought a janitor." << endl;
    janitors++;
    totalfund=totalfund-100;
    }
}
if(answer=="3"){
    cout << "You just bought a floor." << endl;
    floors++;
    totalfund=totalfund-250;
    workercapacity=workercapacity+4;
}
if(answer=="exit" || answer=="Exit"){
    return;
}
else if(answer!="1" && answer!="2" && answer!="3" && answer!="exit" && answer!="Exit"){
    cout << "Error. Unknown input." << endl;
}

}
}
int winlose(){
if(totalfund>100000 && floors>50){
    cout << "You win!" << endl;
    return 0;
}
if(totalfund<-20000){
    cout << "Congratulations. You went bankrupt. You just lost the entire game." << endl;
    return 0;
}
}
void results(){
profit=workers*150;
if(janitors!=floors){
    cout << "Not all floors have janitors and therefor are dirty. Worker productivity drops." << endl;
    profit=profit-workers*50;
}
if(economicrises1=true){
    profit=profit-250;
}
cout << "You made " << profit << endl;
totalfund=(totalfund+profit)-(workers*100+janitors*25+floors*100);
cout << "Your total fund is, after paying your workers wages " << totalfund << endl;
cout << "You have " << endl;
cout << workers << " workers." << endl;
cout << janitors << " janitors and" << endl;
cout << floors << " floors." << endl;
day++;
cout << "Day " << day << endl;
}
void workersforhire(){
    srand(time(NULL));
    workersavaliableforhire=rand() % 10 + 1;}
void economy(){

while(day>25 && workers<15){
    cout << "As your company expands you will need more workers to adjust. Having less than 15 makes you give less economic output" << endl;
    cout << "so your profit falls. -250$ until this is fixed." << endl;
    economicrises1=true;
}
if()



}
int main()
{
    while(true){
        workersforhire();
        buying();
        winlose();
        results();
        string stayorexit;
        cout << "Press enter to continue the game. Type exit to leave, or continue to go on." << endl;
        cin >> stayorexit;
        if(stayorexit=="exit"){
            return 0;
        }

    }
}
