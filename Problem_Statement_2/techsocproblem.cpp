#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class bender
{
    public:
    bender()//constructor
    {
        int x=time(0);
        srand(x);
        string n1,n2,e1,e2;int dead=0;
        int hp1,hp2,ap1,ap2,d1,d2,s1,s2,ohp1,ohp2,criticalHits=0,seh=0;
        string m1[4],m2[4];
        int dam1[4],dam2[4];
        //suffix 1 represent the first character
        //suffix 2 represent the second character
        //n represent the name of the character
        //e represent the element which the character shows
        //hp represent the health of the character
        //ap represent the attacking power of the character
        //d represent the defencing power of the character
        //s represent the speed of the character
        //m represent the move which the character can show while attacking
        //dam represent the damage of the respective move
        //dead represent which character has fainted
        //ohp represent the the initial HP of a character
        //criticalHits it is used to store the total no of critical hits performed in the game
        //seh it is used to store the total no of super effective hits performed in the game( advantage due to the effect of the character)
        cout<<"Enter the detail for the first character"<<endl;
        cout<<"Enter the name "<<endl;
        cin.ignore();
        getline(cin,n1);
        cout<<"Select the element  among(Water , Fire , Earth , or Air)"<<endl;
        cin>>e1;
        cout<<"Enter the HP (1-200)"<<endl;
        cin>>hp1;
        cout<<"Enter the attack power(1-100)"<<endl;
        cin>>ap1;
        cout<<"enter the defence (1-100)"<<endl;
        cin>>d1;
        cout<<"enter the speed(1-100)"<<endl;
        cin>>s1;
        ohp1=hp1;
        cout<<"Enter the fours move of the character"<<endl;
        cin.ignore();
        for(int i=0;i<4;i++)
        {
           getline(cin,m1[i]);
        }
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<4;i++)
        {
            cin>>dam1[i];
        }
        cout<<"Enter the detail for the second character"<<endl;
        cout<<"Enter the name "<<endl;
        cin.ignore();
        getline(cin,n2);
        cout<<"Select the element among(Water , Fire , Earth , or Air)"<<endl;
        cin>>e2;
        cout<<"Enter the HP (1-200)"<<endl;
        cin>>hp2;
        cout<<"Enter the attack power(1-100)"<<endl;
        cin>>ap2;
        cout<<"enter the defence (1-100)"<<endl;
        cin>>d2;
        cout<<"enter the speed(1-100)"<<endl;
        cin>>s2;
        ohp2=hp2;
        cout<<"Enter the fours move of the character "<<endl;
        cin.ignore();
        for(int i=0;i<4;i++)
        {
           getline(cin,m2[i]);
        }
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<4;i++)
        {
            cin>>dam2[i];
        }
        cout<<"the detail of the character "<<n1<<" : "<<endl;
        cout<<"element :"<<e1<<endl;
        cout<<"HP :"<<hp1<<endl;
        cout<<"attack power :"<<ap1<<endl;
        cout<<"defence :"<<d1<<endl;
        cout<<"speed :"<<s1<<endl;
        cout<<"the move of the character are as follows "<<endl;
        for(int i=0;i<4;i++)
        {
            cout<<m1[i]<<" the damage of this move is ("<<dam1[i]<<")"<<endl;
        }
        cout<<"the detail of the character "<<n2<<" : "<<endl;
        cout<<"element :"<<e2<<endl;
        cout<<"HP :"<<hp2<<endl;
        cout<<"attack power :"<<ap2<<endl;
        cout<<"defence :"<<d2<<endl;
        cout<<"speed :"<<s2<<endl;
        cout<<"the move of the character are as follows "<<endl;
        for(int i=0;i<4;i++)
        {
            cout<<m2[i]<<" the damage of this move is ("<<dam2[i]<<")"<<endl;
        }
        int c=1,t=0;
        if(s1>s2)
        {
            cout<<"whose speed is more will  attack first therefore as the speed of the first character is more therefore it will attack first"<<endl;
            while(1>0)
            {
                if(c%2!=0)
            {
                //chararter 1 is the attacker
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n1<<" used "<<m1[ch]<<endl;
            int totalDamage=((ap1*dam1[ch])/d2);
            if(e1=="water" && e2=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e1=="fire" && e2=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e1=="fire" && e2=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e1=="air" && e2=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e1=="air" && e2=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e1=="earth" && e2=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e1=="earth" && e2=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e1=="water" && e2=="earth")
   {
    totalDamage=0.5*totalDamage;
   }
else
{
    totalDamage=1*totalDamage;
}
double critical_chance = 0.10;  // 10% chance
bool is_critical = rand()%2 < critical_chance;
if(is_critical)
{
    totalDamage=2*totalDamage;
    criticalHits++;
}
else
{
    totalDamage=1*totalDamage;
}
            cout<<n2<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp2)
            {
                cout<<n2<<" is fainted "<<endl;
                t++;
                dead=2;
                break;
            }
            else{
               cout<<n2<<" is not fainted and it is still alive with the hp of "<<(hp2-totalDamage)<<"/"<<ohp2<<endl;
               hp2=hp2-totalDamage;
               c++;
               t++;
            }
        }
        else
        {
            //chararter 2 is the attacker
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n2<<" used "<<m2[ch]<<endl;
            int totalDamage=((ap2*dam2[ch])/d1);
            if(e2=="water" && e1=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e2=="fire" && e1=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e2=="fire" && e1=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e2=="air" && e1=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e2=="air" && e1=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e2=="earth" && e1=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e2=="earth" && e1=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e2=="water" && e1=="earth")
   {
    totalDamage=0.5*totalDamage;
   }
else
{
    totalDamage=1*totalDamage;
}
double critical_chance = 0.10;  // 10% chance
bool is_critical = rand()%2 < critical_chance;
if(is_critical)
{
    totalDamage=2*totalDamage;
     criticalHits++;
}
else
{
    totalDamage=1*totalDamage;
}
            cout<<n1<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp1)
            {
                cout<<n1<<" is fainted "<<endl;
                t++;
                dead=1;
                break;
            }
            else{
                cout<<n1<<" is not fainted and it is still alive with the hp of "<<(hp1-totalDamage)<<"/"<<ohp1<<endl;
                hp1=hp1-totalDamage;
                c++;
                t++;
            }
        }
    }
}
        else 
        {
            //chararter 2 is the attacker
            cout<<"whose speed is more will  attack first therefore as the speed of the second character is more therefore it will attack first"<<endl;
            while(1>0)
            if(c%2!=0)
            {
            int ch,suh=0;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n2<<" used "<<m2[ch]<<endl;
            int totalDamage=((ap2*dam2[ch])/d1);
 if(e2=="water" && e1=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e2=="fire" && e1=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e2=="fire" && e1=="air")
   {
    totalDamage=2*totalDamage;
     seh++;
   }
else if(e2=="air" && e1=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e2=="air" && e1=="earth")
   {
    totalDamage=2*totalDamage;
     seh++;
   }
else if(e2=="earth" && e1=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e2=="earth" && e1=="water")
   {
    totalDamage=2*totalDamage;
     seh++;
   }
else if(e2=="water" && e1=="earth")
   {
    totalDamage=0.5*totalDamage;
   }
else
{
    totalDamage=1*totalDamage;
}
double critical_chance = 0.10;  // 10% chance
bool is_critical = rand()%2 < critical_chance;
if(is_critical)
{
    totalDamage=2*totalDamage;
     criticalHits++;
}
else
{
    totalDamage=1*totalDamage;
}
            cout<<n1<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp1)
            {
                cout<<n1<<" is fainted "<<endl;
                t++;
                dead=1;
                break;
            }
            else{
                cout<<n1<<" is not fainted and it is still alive with the hp of "<<(hp1-totalDamage)<<"/"<<ohp1<<endl;
                hp1=hp1-totalDamage;
                c++;
                t++;
            }
        }
        else{
            //chararter 1 is the attacker
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n1<<" used "<<m1[ch]<<endl;
            int totalDamage=((ap1*dam1[ch])/d2);
            if(e1=="water" && e2=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e1=="fire" && e2=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e1=="fire" && e2=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e1=="air" && e2=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e1=="air" && e2=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e1=="earth" && e2=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e1=="earth" && e2=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e1=="water" && e2=="earth")
   {
    totalDamage=0.5*totalDamage;
   }
else
{
    totalDamage=1*totalDamage;
}
double critical_chance = 0.10;  // 10% chance
bool is_critical = rand()%2 < critical_chance;
if(is_critical)
{
    totalDamage=2*totalDamage;
     criticalHits++;
}
else
{
    totalDamage=1*totalDamage;
}
            cout<<n2<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp2)
            {
                cout<<n2<<" is fainted "<<endl;
                t++;
                dead=2;
                break;
            }
            else{
               cout<<n2<<" is not fainted and it is still alive with the hp of "<<(hp2-totalDamage)<<"/"<<ohp2<<endl;
               hp2=hp2-totalDamage;
               c++;
               t++;
            }
        }
    }
    if(dead==1)
    {
        cout<<"winner :"<<n2<<endl;
        cout<<"Turn :"<<t<<endl;
        cout<<"critical hits :"<< criticalHits<<endl;
        cout<<"Super effective hits :"<<seh<<endl;
    }
    if(dead==2)
    {
        cout<<"winner :"<<n1<<endl;
        cout<<"Turn :"<<t<<endl;
        cout<<"critical hits :"<< criticalHits<<endl;
        cout<<"Super effective hits :"<<seh<<endl;
    }
}
};
int main()
{
    bender();//calling of the constructor
}