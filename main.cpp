#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
long long workers=0,janitors=0,floors=0,totalfund=7500,profit=0,workercapacity;
int workersavaliableforhire;
long long day=1;
bool evadingtax=false;
int chanceofgettingcaught;
bool caught=false;
bool painting=false,flower=false,fancyflower=false,watercooler=false;
bool paintingbought=false,flowerbought=false,fancyflowerbought=false,watercoolerbought=false;
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
            totalfund=totalfund-200;
            }
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
    else if(answer!="1" && answer!="2" && answer!="3" && answer!="exit" && answer!="Exit" && answer!="4" && answer!="5" && answer!="6" && answer!="7"){
        cout << "Error. Unknown input." << endl;
    }
    if(painting==true){
        cout << "4. Painting" << endl;
    }
    if(flower==true){
        cout << "5. Flower" << endl;
    }
    if(fancyflower==true){
        cout << "6. Fancy flower" << endl;
    }
    if(watercooler==true){
        cout << "7. Water cooler" << endl;
    }
    if(answer=="4" && day>5 && totalfund>10000 && painting==true){
        paintingbought==true;
        cout << "Painting bought!" << endl;
        painting=false;
    }
    if(answer=="5" && day>10 && totalfund>25000 && flower==true){
        flowerbought=true;
        cout << "Flower bought!" << endl;
        flower==false;
    }
    if(answer=="6"  && day>20 && totalfund>35000 && fancyflower==true){
        cout << "Fancy flowers bought!" << endl;
        fancyflowerbought=true;
        fancyflower=false;
    }
    if(answer=="7" && day>25 && totalfund>27500 && watercooler==true){
        cout << "Water cooler bought!" << endl;
        watercoolerbought=true;
        watercooler=false;
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
    if(evadingtax=true){
        srand(time(NULL));
        chanceofgettingcaught=rand() % 100 + 1;
        if(chanceofgettingcaught>50){
            cout << "Uh oh. You got caught evading taxes and are under arrest. G A M E O V E R" << endl;
            caught=true;
            return;
        }
        else if(chanceofgettingcaught<50 || chanceofgettingcaught==50){
            profit=profit*2;
        }
    }
    if(paintingbought==true){
        cout << "The painting doubled your profits, because workers enjoy the office more." << endl;
        profit=profit*2;
    }
    if(flowerbought==true){
        cout << "Flowers make the office better. Two times the income." << endl;
        profit=profit*2;
    }
    if(fancyflowerbought==true){
        cout << "People enjoy the fancy flowers. Profit tripled!" << endl;
        profit=profit*3;
    }
    if(watercoolerbought==true){
        cout << "Workers like cold, fresh water. Profits doubled!" << endl;
        profit=profit*2;
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
    workersavaliableforhire=rand() % 10 + 1;
    }
void taxevasion(){
    string evading;
    cout << "Do you want to attempt evading taxes? You have a 50 50 chance of getting caught, but it doubles your profits. [Y/N]" << endl;
    cin >> evading;
    if(evading=="Y" || evading=="y"){
        evadingtax=true;
    }
    else if(evading=="n" || evading=="N"){
        evadingtax=false;
    }

    }
void decorations(){
    if(day>5 && totalfund>10000){
        cout << "First decoration unlocked! Buy it for 5000$. Its a painting that boosts morale and workers give twice as much." << endl;
        painting=true;
    }
    if(day>10 && totalfund>25000){
        cout << "Second decoration unlocked! Rose flowers make the office smell better and look better. Workers give twice the income. 25000$" << endl;
        flower=true;
    }
    if(day>20 && totalfund>35000){
        cout << "Third decoration unlocked! Fancy flowers. Office looks better. Workers give 3 times the profit. 35000$" << endl;
        fancyflower=true;
    }
    if(day>25 && totalfund>27500){
        cout << "Water coolers unlocked! Workers do more work because of proper hydration. 27500$ to buy." << endl;
        watercooler=true;
    }
}
int main()
{
    while(true){
        workersforhire();
        decorations();
        buying();
        winlose();
        taxevasion();
        results();
        if(caught==true){
            exit(EXIT_SUCCESS);
        }
        string stayorexit;
        cout << "Press enter to continue the game. Type exit to leave, or continue to go on." << endl;
        cin >> stayorexit;
        if(stayorexit=="exit"){
            return 0;
        }

    }
}
