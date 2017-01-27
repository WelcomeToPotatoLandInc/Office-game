#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello and welcome to office manager 2000. You are the CEO of a large computer firm. In order to buy things, type buy/BUY item. The items are janitor, worker, and floor. Floors increase the capacity of workers and janitors, and hold spaces for 4 workers. Janitors clean those floors. That is all." << endl;
    cout << "Victory conditions are gaining more than 100,000 or more than 20 floors." << endl;
    cout << "Because of technical issues, you need to type buy/BUY first" << endl;
    cout << "and then you will be prompted for what to buy. Type skip to skip to the end of the day." << endl;
   int workers=0;
   int totalfund=7500;
    int janitors=0;
    int floors=0;
    int howmuchtheymade;
    int day=0;
    int workercapacity=floors*4;
    int janitorcapacity=0;
    string action="action";
    string answer2="action2";

        thenextday:;
        cout << "If you dont want to do anything, just type skip to skip to the end of this day." << endl;
        cin >> action;
        if(action=="skip"){
            goto toolazy;
        }

        if(action=="buy"|| action=="BUY"){
            buyingmore:;
            cout << "You can buy:" << endl;
            cout << "1. Worker $200, 100 a day for wage. Makes 150$ a day." << endl;
            cout << "2. Janitor $100, 25 a day for wage. Cleans floors. " << endl;
            cout << "3. Floor $250. Not much to say. Holds 4 workers. " << endl;
            cout << "Enter a number of its name, exactly as it is typed to not cause errors." << endl;
            cin >> action;
            if(action=="1" || action=="worker" || action=="Worker"){
                if(workers==workercapacity){
                    cout << "Buy more floors, not enough space for your workers" << endl;
                }
                else{
                    cout << "You have bought a worker" << endl;
                    workers++;
                    workercapacity--;
                    totalfund=totalfund-200;
                }
            }
                else if (action=="2" || action=="janitor" || action=="Janitor"){
                    if(janitors>janitorcapacity ){
                        cout << "One janitor is required per floor. Either get more floors, or you dont need any more janitors." << endl;
                    }
                    else{
                        cout << "You have bought a janitor!" << endl;
                        totalfund=totalfund-100;
                        janitors++;
                        janitorcapacity--;
                    }
                }
                else if (action=="3" || action=="floor" || action=="Floor"){
                    cout << "You have bought a floor" << endl;
                    totalfund=totalfund-250;
                    floors++;
                    workercapacity=floors*4;
                    janitorcapacity++;
                }
                else{
                    cout << "Uh, I dont understand. Try again." << endl;
                    goto buyingmore;
                }
        }
    else if (action=="exit" || action=="Exit"){
        cout << "Thanks for playing!";
        return 0;
    }
    else{
        cout << "I do not understand this input. Try again." << endl;
        goto thenextday;
    }
    inputerror:;
    cout << "Do you want to buy anything else [Y/N]" << endl;
    cin >> answer2;
    if(answer2=="Y"){
        goto buyingmore;
    }
    if(answer2=="y"){
        goto buyingmore;
    }

    if(totalfund>100000 || floors>50){
        cout << "You win! Good job!";
        return 0;
    }
    if(answer2=="n"){
        goto toolazy;
    }
    if(answer2=="N"){
        toolazy:;
        howmuchtheymade=workers*150;
        totalfund=(totalfund-workers*50)-janitors*25;
        if(janitors!=floors){
            howmuchtheymade=howmuchtheymade-workers*50;
            cout << "The janitor and floor number is not the same. Some floors are dirty. Worker productivity drops." << endl;
        }
        day++;
        cout << "You  had to pay " << workers*100 << " for worker wages and " << " janitors " << janitors*25 << " for wages." << endl;
        totalfund=totalfund-(workers*100+janitors*25);
        cout << "Your total fund is " << totalfund << " and the workers made " << howmuchtheymade << endl;
        cout << "Day " << day << " begins." << endl;
        cout << "Stats: " << endl;
        cout << "Workers: " << workers << endl;
        cout << "Janitors: " << janitors << endl;
        cout << "Floors: " << floors << endl;
        totalfund=totalfund+howmuchtheymade;
        goto thenextday;
    }
    else{
        cout << "Input error, try again." << endl;
        goto inputerror;
    }
    theend:;
    return 0;
    }
