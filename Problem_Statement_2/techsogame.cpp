#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class UserVsAi
{
    public:
    UserVsAi(int b,int &winner)
    {
        int x=time(0);
        srand(x);
        int hp[4],s[4],d[4],ohp[4],ap[4],dam1[4],dam2[4],dam3[4],dam4[4],damA[4],maxDamA;
        string n[4],m1[4],m2[4],e[4],m3[4],m4[4],mA[4];
         for(int i=0;i<4;i++)
    {
        cout<<"Enter the detail of "<<(i+1)<<" character"<<endl;
         cout<<"Enter the name "<<endl;
        cin.ignore();
        getline(cin,n[i]);
        cout<<"Select the element  among(Water , Fire , Earth , or Air)"<<endl;
        cin>>e[i];
        cout<<"Enter the HP (1-200)"<<endl;
        cin>>hp[i];
        cout<<"Enter the attack power(1-100)"<<endl;
        cin>>ap[i];
        cout<<"enter the defence (1-100)"<<endl;
        cin>>d[i];
        cout<<"enter the speed(1-100)"<<endl;
        cin>>s[i];
        ohp[i]=hp[i];
    }
    int maxDam1=0,maxDam2=0,maxDam3=0;
    cout<<"Enter the fours move of the character "<<n[0]<<endl;
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
        cout<<"Enter the fours move of the character "<<n[1]<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m2[i]);
        }
        m2[3]="Healing";
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>dam2[i];
            if(dam2[i]>maxDam1)
            {
                maxDam1=dam2[i];
            }
        }
        dam2[3]=30;
        cout<<"Enter the fours move of the character "<<n[2]<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m3[i]);
        }
        m3[3]="Healing";
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>dam3[i];
            if(dam3[i]>maxDam2)
            {
                maxDam2=dam3[i];
            }
        }
        dam3[3]=30;
        cout<<"Enter the fours move of the character "<<n[3]<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m4[i]);
        }
        m4[3]="Healing";
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>dam4[i];
            if(dam4[i]>maxDam3)
            {
                maxDam3=dam4[i];
            }
        }
        dam4[3]=30;
        if(b==1)
        {
         for(int i=0;i<4;i++)
         {
            damA[i]=dam2[i];
            mA[i]=m2[i];
            maxDamA=maxDam1;
         }
        }
        if(b==2)
        {
         for(int i=0;i<4;i++)
         {
            damA[i]=dam3[i];
            mA[i]=m3[i];
            maxDamA=maxDam2;
         }
        }
    if(b==3)
        {
         for(int i=0;i<4;i++)
         {
            damA[i]=dam4[i];
            mA[i]=m4[i];
            maxDamA=maxDam3;
         }
        }
        cout<<"The fight is between "<<n[0]<<" and "<<n[b]<<endl;
        int t=0,c=1,et1,et2,effect=0,seh=0,criticalHits=0,dead,r6=0,r3=0;
       string effect1="",effect2="";
       if(s[0]>s[b])
       {
        cout<<"Your character will attack first as the speed of your character is more than the AI bot character speed"<<endl;
        while(1>0)
        {
        if(c%2!=0)
        {
             
            if(effect2 == "buried" && r6==0)
            {
                r6=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect2=="frozen" && et2<=3)
         {
            et2++;
            r6=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r6==1 || (effect2=="buried" && et1<=r6))
         {
            cout<<"The chance of the user skip"<<endl;
            c++;
            t++;
            et2++;
         }
         else
         {
            if(hp[0] < 0.2*ohp[0])
            {
                string decision;
                cout<<"Do you want to use the special effect"<<endl;
                cin>>decision;
                if(decision=="yes")
                {
                    et1=0;
                    cout<<"choose one special effect among (burn,frozen,buried)"<<endl;
                    cout<<"burn : Deals 10% max HP damage each turn for 4 turns"<<endl;
                    cout<<"Frozen 50percent chance to skip turns for 3 turns"<<endl;
                    cout<<"buried : cannot move for 2-4 turns(random duration)"<<endl;
                    cout<<"Write the name of the effect which you wanted to choose"<<endl;
                    cin>>effect1;
                    effect++;
                }
                else
                {
                    cout<<"No special effect is used"<<endl;
                }
            }
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n[0]<<" used "<<m1[ch]<<endl;
            double totalDamage=((ap[0]*dam1[ch])/d[b]);
            if(e[0]=="water" && e[b]=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e[0]=="fire" && e[b]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[0]=="fire" && e[b]=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[0]=="air" && e[b]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[0]=="air" && e[b]=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[0]=="earth" && e[b]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[0]=="earth" && e[b]=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[0]=="water" && e[b]=="earth")
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
if(effect1=="burn" && et1<=4)
{
    totalDamage=totalDamage + (0.1*ohp[b]);
    et1++;
}
            cout<<n[b]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[b])
            {
                cout<<n[b]<<" is fainted "<<endl;
                t++;
                dead=2;
                break;
            }
            else{
               cout<<n[b]<<" is not fainted and it is still alive with the hp of "<<(hp[b]-totalDamage)<<"/"<<ohp[b]<<endl;
               hp[b]=hp[b]-totalDamage;
               c++;
               t++;
            }
        }
    }
        else
        {
           
            if(effect1 == "buried" && r3==0)
            {
                r3=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect1=="frozen" && et1<=3)
         {
            et1++;
            r3=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r3==1 || (effect1=="buried" && et1<=r3))
         {
            cout<<"The chance of the AI bot skip"<<endl;
            c++;
            t++;
            et1++;
         }
         else
         {
            double totalDamage;
          if(hp[b]<0.3*ohp[b])
          {
            hp[b]=hp[b]+damA[3];
            c++;
          }
          else if(hp[0]>0.7*ohp[0])
          {
            effect++;
            et2=0;
            int r4=rand() % (3) + 1;
            if (r4==1)
            {
                effect2="burn";
            }
            if(r4==2)
            {
                effect2="frozen";
            }
            if(r4==3)
            {
                effect2="buried";
            }
          }
          else if(hp[0]<0.25*ohp[0])
          {
            totalDamage=maxDamA;
          }
          else{
            int r5=rand() % 3;
            totalDamage=((ap[b]*damA[r5])/d[0]);
          }
          if(e[b]=="water" && e[0]=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e[b]=="fire" && e[0]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b]=="fire" && e[0]=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[b]=="air" && e[0]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b]=="air" && e[0]=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[b]=="earth" && e[0]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b]=="earth" && e[0]=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[b]=="water" && e[0]=="earth")
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
if(effect2=="burn" && et2<=4)
{
    totalDamage=totalDamage + (0.1*ohp[0]);
    et2++;
}
            cout<<n[0]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[0])
            {
                cout<<n[0]<<" is fainted "<<endl;
                t++;
                dead=1;
                break;
            }
            else{
                cout<<n[0]<<" is not fainted and it is still alive with the hp of "<<(hp[0]-totalDamage)<<"/"<<ohp[0]<<endl;
                hp[0]=hp[0]-totalDamage;
                c++;
                t++;
            }
         }
        }
       }
        }
        else{
            cout<<"The AI bot will attack first as the speed of the bot is more than the user character"<<endl;
             while(1>0)
            {
            if(c%2!=0)
            {
            if(effect1 == "buried" && r3==0)
            {
                r3=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect1=="frozen" && et1<=3)
         {
            et1++;
            r3=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r3==1 || (effect1=="buried" && et1<=r3))
         {
            cout<<"The chance of the AI bot skip"<<endl;
            c++;
            t++;
            et1++;
         }
         else
         {
            double totalDamage;
          if(hp[b]<0.3*ohp[b])
          {
            hp[b]=hp[b]+damA[3];
            c++;
          }
          else if(hp[0]>0.7*ohp[0])
          {
            effect++;
            et2=0;
            int r4=rand() % (3) + 1;
            if (r4==1)
            {
                effect2="burn";
            }
            if(r4==2)
            {
                effect2="frozen";
            }
            if(r4==3)
            {
                effect2="buried";
            }
          }
          else if(hp[0]<0.25*ohp[0])
          {
            totalDamage=maxDamA;
          }
          else{
            int r5=rand() % 3;
            totalDamage=((ap[b]*damA[r5])/d[0]);
          }
          if(e[b]=="water" && e[0]=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e[b]=="fire" && e[0]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b]=="fire" && e[0]=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[b]=="air" && e[0]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b]=="air" && e[0]=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[b]=="earth" && e[0]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b]=="earth" && e[0]=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[b]=="water" && e[0]=="earth")
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
if(effect2=="burn" && et2<=4)
{
    totalDamage=totalDamage + (0.1*ohp[0]);
    et2++;
}
            cout<<n[0]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[0])
            {
                cout<<n[0]<<" is fainted "<<endl;
                t++;
                dead=1;
                break;
            }
            else{
                cout<<n[0]<<" is not fainted and it is still alive with the hp of "<<(hp[0]-totalDamage)<<"/"<<ohp[0]<<endl;
                hp[0]=hp[0]-totalDamage;
                c++;
                t++;
            }
         }
        }
        else{
            if(effect2 == "buried" && r6==0)
            {
                r6=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect2=="frozen" && et2<=3)
         {
            et2++;
            r6=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r6==1 || (effect2=="buried" && et1<=r6))
         {
            cout<<"The chance of the user skip"<<endl;
            c++;
            t++;
            et2++;
         }
         else
         {
            if(hp[0] < 0.2*ohp[0])
            {
                string decision;
                cout<<"Do you want to use the special effect"<<endl;
                cin>>decision;
                if(decision=="yes")
                {
                    et1=0;
                    cout<<"choose one special effect among (burn,frozen,buried)"<<endl;
                    cout<<"burn : Deals 10% max HP damage each turn for 4 turns"<<endl;
                    cout<<"Frozen 50percent chance to skip turns for 3 turns"<<endl;
                    cout<<"buried : cannot move for 2-4 turns(random duration)"<<endl;
                    cout<<"Write the name of the effect which you wanted to choose"<<endl;
                    cin>>effect1;
                    effect++;
                }
                else
                {
                    cout<<"No special effect is used"<<endl;
                }
            }
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n[0]<<" used "<<m1[ch]<<endl;
            double totalDamage=((ap[0]*dam1[ch])/d[b]);
            if(e[0]=="water" && e[1]=="fire")
{
    totalDamage=2*totalDamage;
    seh++;
}
else if(e[0]=="fire" && e[b]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[0]=="fire" && e[b]=="air")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[0]=="air" && e[b]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[0]=="air" && e[b]=="earth")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[0]=="earth" && e[b]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[0]=="earth" && e[b]=="water")
   {
    totalDamage=2*totalDamage;
    seh++;
   }
else if(e[0]=="water" && e[b]=="earth")
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
if(effect1=="burn" && et1<=4)
{
    totalDamage=totalDamage + (0.1*ohp[b]);
    et1++;
}
            cout<<n[b]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[b])
            {
                cout<<n[b]<<" is fainted "<<endl;
                t++;
                dead=2;
                break;
            }
            else{
               cout<<n[b]<<" is not fainted and it is still alive with the hp of "<<(hp[b]-totalDamage)<<"/"<<ohp[b]<<endl;
               hp[b]=hp[b]-totalDamage;
               c++;
               t++;
            }
        }
    }
}
}
if(dead==1)
    {
        cout<<"winner of the semifinal 1 : "<<n[b]<<endl;
        cout<<"Turn : "<<t<<endl;
        cout<<"critical hits : "<< criticalHits<<endl;
        cout<<"Super effective hits : "<<seh<<endl;
    }
    if(dead==2)
    {
        cout<<"winner of the semifinal 1 : "<<n[0]<<endl;
        cout<<"Turn : "<<t<<endl;
        cout<<"critical hits : "<< criticalHits<<endl;
        cout<<"Super effective hits : "<<seh<<endl;
    }
    winner=dead;
    }
};
class AiVsAi 
{
    public:
    AiVsAi(int b1,int b2,int &winner)
    {
         int hp[4],s[4],d[4],ohp[4],ap[4],dam1[4],dam2[4],dam3[4],dam4[4],damA[4],maxDamA,damA1[4],maxDamA1;
        string n[4],m1[4],m2[4],e[4],m3[4],m4[4],mA[4],mA1[4];
         for(int i=0;i<4;i++)
    {
        cout<<"Enter the detail of "<<(i+1)<<" character"<<endl;
         cout<<"Enter the name "<<endl;
        cin.ignore();
        getline(cin,n[i]);
        cout<<"Select the element  among(Water , Fire , Earth , or Air)"<<endl;
        cin>>e[i];
        cout<<"Enter the HP (1-200)"<<endl;
        cin>>hp[i];
        cout<<"Enter the attack power(1-100)"<<endl;
        cin>>ap[i];
        cout<<"enter the defence (1-100)"<<endl;
        cin>>d[i];
        cout<<"enter the speed(1-100)"<<endl;
        cin>>s[i];
        ohp[i]=hp[i];
    }
    int maxDam1=0,maxDam2=0,maxDam3=0;
    cout<<"Enter the fours move of the character "<<n[0]<<endl;
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
        cout<<"Enter the fours move of the character "<<n[1]<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m2[i]);
        }
        m2[3]="Healing";
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>dam2[i];
            if(dam2[i]>maxDam1)
            {
                maxDam1=dam2[i];
            }
        }
        dam2[3]=30;
        cout<<"Enter the fours move of the character "<<n[2]<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m3[i]);
        }
        m3[3]="Healing";
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>dam3[i];
            if(dam3[i]>maxDam2)
            {
                maxDam2=dam3[i];
            }
        }
        dam3[3]=30;
        cout<<"Enter the fours move of the character "<<n[3]<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m4[i]);
        }
        m4[3]="Healing";
        cout<<"Enter the damage of the respective move"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>dam4[i];
            if(dam4[i]>maxDam3)
            {
                maxDam3=dam4[i];
            }
        }
        dam4[3]=30;
        if(b1==1)
        {
         for(int i=0;i<4;i++)
         {
            damA[i]=dam2[i];
            mA[i]=m2[i];
            maxDamA=maxDam1;
         }
        }
        if(b1==2)
        {
         for(int i=0;i<4;i++)
         {
            damA[i]=dam3[i];
            mA[i]=m3[i];
            maxDamA=maxDam2;
         }
        }
    if(b1==3)
        {
         for(int i=0;i<4;i++)
         {
            damA[i]=dam4[i];
            mA[i]=m4[i];
            maxDamA=maxDam3;
         }
        }
         if(b2==1)
        {
         for(int i=0;i<4;i++)
         {
            damA1[i]=dam2[i];
            mA1[i]=m2[i];
            maxDamA1=maxDam1;
         }
        }
        if(b2==2)
        {
         for(int i=0;i<4;i++)
         {
            damA1[i]=dam3[i];
            mA1[i]=m3[i];
            maxDamA1=maxDam2;
         }
        }
    if(b2==3)
        {
         for(int i=0;i<4;i++)
         {
            damA1[i]=dam4[i];
            mA1[i]=m4[i];
            maxDamA1=maxDam3;
         }
        }
        cout<<"The fight is in between "<<n[b1]<<" and "<<n[b2]<<endl;
        int t1=0,c1=1,et3,et4,effects=0,seh1=0,criticalHits1=0,dead1,r8=0,r9=0;
       string effect3="",effect4="";
       if(s[b1]>s[b2])
       {
        cout<<n[b1]<<" is faster than "<<n[b2]<<" therfore it will attack first"<<endl;
        while(1>0)
        {
            if(c1%2!=0)
            {
                 
            if(effect4 == "buried" && r8==0)
            {
                r8=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect4=="frozen" && et4<=3)
         {
            et4++;
            r8=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r8==1 || (effect4=="buried" && et4<=r8))
         {
            cout<<"The chance is skip"<<endl;
            c1++;
            t1++;
            et4++;
         }
                else
                {
                 double totalDamage;
          if(hp[b1]<0.3*ohp[b1])
          {
            hp[b1]=hp[b1]+damA[3];
            c1++;
          }
          else if(hp[b2]>0.7*ohp[b2])
          {
            effects++;
            et3=0;
            int r4=rand() % (3) + 1;
            if (r4==1)
            {
                effect3="burn";
            }
            if(r4==2)
            {
                effect3="frozen";
            }
            if(r4==3)
            {
                effect3="buried";
            }
          }
          else if(hp[b2]<0.25*ohp[b2])
          {
            totalDamage=maxDamA;
          }
          else{
            int r5=rand() % 3;
            totalDamage=((ap[b1]*damA[r5])/d[b2]);
          }
          if(e[b1]=="water" && e[b2]=="fire")
{
    totalDamage=2*totalDamage;
    seh1++;
}
else if(e[b1]=="fire" && e[b2]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b1]=="fire" && e[b2]=="air")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b1]=="air" && e[b2]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b1]=="air" && e[b2]=="earth")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b1]=="earth" && e[b2]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b1]=="earth" && e[b2]=="water")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b1]=="water" && e[b2]=="earth")
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
     criticalHits1++;
}
else
{
    totalDamage=1*totalDamage;
}
if(effect3=="burn" && et3<=4)
{
    totalDamage=totalDamage + (0.1*ohp[b2]);
    et3++;
}
            cout<<n[b2]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[b2])
            {
                cout<<n[b2]<<" is fainted "<<endl;
                t1++;
                dead1=1;
                break;
            }
            else{
                cout<<n[b2]<<" is not fainted and it is still alive with the hp of "<<(hp[b2]-totalDamage)<<"/"<<ohp[b2]<<endl;
                hp[b2]=hp[b2]-totalDamage;
                c1++;
                t1++;
            }
         }
                }
                else
                {
                 
            if(effect3 == "buried" && r9==0)
            {
                r9=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect3=="frozen" && et3<=3)
         {
            et3++;
            r9=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r9==1 || (effect3=="buried" && et3<=r9))
         {
            cout<<"The chance is skip"<<endl;
            c1++;
            t1++;
            et3++;
         }
                else
                {
                 double totalDamage;
          if(hp[b2]<0.3*ohp[b2])
          {
            hp[b2]=hp[b2]+damA1[2];
            c1++;
          }
          else if(hp[b1]>0.7*ohp[b1])
          {
            effects++;
            et4=0;
            int r7=rand() % (3) + 1;
            if (r7==1)
            {
                effect4="burn";
            }
            if(r7==2)
            {
                effect4="frozen";
            }
            if(r7==3)
            {
                effect4="buried";
            }
          }
          else if(hp[b1]<0.25*ohp[b1])
          {
            totalDamage=maxDamA1;
          }
          else{
            int r8=rand() % 3;
            totalDamage=((ap[b2]*damA1[r8])/d[b1]);
          }
          if(e[b2]=="water" && e[b1]=="fire")
{
    totalDamage=2*totalDamage;
    seh1++;
}
else if(e[b2]=="fire" && e[b1]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b2]=="fire" && e[b1]=="air")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b2]=="air" && e[b1]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b2]=="air" && e[b1]=="earth")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b2]=="earth" && e[b1]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b2]=="earth" && e[b1]=="water")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b2]=="water" && e[b1]=="earth")
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
     criticalHits1++;
}
else
{
    totalDamage=1*totalDamage;
}
if(effect4=="burn" && et4<=4)
{
    totalDamage=totalDamage + (0.1*ohp[b1]);
    et4++;
}
            cout<<n[b1]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[b1])
            {
                cout<<n[b1]<<" is fainted "<<endl;
                t1++;
                dead1=2;
                break;
            }
            else{
                cout<<n[b1]<<" is not fainted and it is still alive with the hp of "<<(hp[b1]-totalDamage)<<"/"<<ohp[b1]<<endl;
                hp[b1]=hp[b1]-totalDamage;
                c1++;
                t1++;
            }
                }
            }
        }
       }
       else
       {
         cout<<n[b2]<<" is faster than "<<n[b2]<<" therfore it will attack first"<<endl;
         {
            while(1>0)
            {
                if(c1%2!=0)
                {
                    if(effect3 == "buried" && r9==0)
            {
                r9=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect3=="frozen" && et3<=3)
         {
            et3++;
            r9=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r9==1 || (effect3=="buried" && et3<=r9))
         {
            cout<<"The chance is skip"<<endl;
            c1++;
            t1++;
            et3++;
         }
                else
                {
                 double totalDamage;
          if(hp[b2]<0.3*ohp[b2])
          {
            hp[b2]=hp[b2]+damA1[2];
            c1++;
          }
          else if(hp[b1]>0.7*ohp[b1])
          {
            effects++;
            et4=0;
            int r7=rand() % (3) + 1;
            if (r7==1)
            {
                effect4="burn";
            }
            if(r7==2)
            {
                effect4="frozen";
            }
            if(r7==3)
            {
                effect4="buried";
            }
          }
          else if(hp[b1]<0.25*ohp[b1])
          {
            totalDamage=maxDamA1;
          }
          else{
            int r8=rand() % 3;
            totalDamage=((ap[b2]*damA1[r8])/d[b1]);
          }
          if(e[b2]=="water" && e[b1]=="fire")
{
    totalDamage=2*totalDamage;
    seh1++;
}
else if(e[b2]=="fire" && e[b1]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b2]=="fire" && e[b1]=="air")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b2]=="air" && e[b1]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b2]=="air" && e[b1]=="earth")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b2]=="earth" && e[b1]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b2]=="earth" && e[b1]=="water")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b2]=="water" && e[b1]=="earth")
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
     criticalHits1++;
}
else
{
    totalDamage=1*totalDamage;
}
if(effect4=="burn" && et4<=4)
{
    totalDamage=totalDamage + (0.1*ohp[b1]);
    et4++;
}
            cout<<n[b1]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[b1])
            {
                cout<<n[b1]<<" is fainted "<<endl;
                t1++;
                dead1=2;
                break;
            }
            else{
                cout<<n[b1]<<" is not fainted and it is still alive with the hp of "<<(hp[b1]-totalDamage)<<"/"<<ohp[b1]<<endl;
                hp[b1]=hp[b1]-totalDamage;
                c1++;
                t1++;
            }
            
                }
            }
            else
            {
               
            if(effect4 == "buried" && r8==0)
            {
                r8=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect4=="frozen" && et4<=3)
         {
            et4++;
            r8=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r8==1 || (effect4=="buried" && et4<=r8))
         {
            cout<<"The chance is skip"<<endl;
            c1++;
            t1++;
            et4++;
         }
                else
                {
                 double totalDamage;
          if(hp[b1]<0.3*ohp[b1])
          {
            hp[b1]=hp[b1]+damA[3];
            c1++;
          }
          else if(hp[b2]>0.7*ohp[b2])
          {
            effects++;
            et3=0;
            int r4=rand() % (3) + 1;
            if (r4==1)
            {
                effect3="burn";
            }
            if(r4==2)
            {
                effect3="frozen";
            }
            if(r4==3)
            {
                effect3="buried";
            }
          }
          else if(hp[b2]<0.25*ohp[b2])
          {
            totalDamage=maxDamA;
          }
          else{
            int r5=rand() % 3;
            totalDamage=((ap[b1]*damA[r5])/d[b2]);
          }
          if(e[b1]=="water" && e[b2]=="fire")
{
    totalDamage=2*totalDamage;
    seh1++;
}
else if(e[b1]=="fire" && e[b2]=="water")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b1]=="fire" && e[b2]=="air")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b1]=="air" && e[b2]=="fire")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b1]=="air" && e[b2]=="earth")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b1]=="earth" && e[b2]=="air")
   {
    totalDamage=0.5*totalDamage;
   }
else if(e[b1]=="earth" && e[b2]=="water")
   {
    totalDamage=2*totalDamage;
    seh1++;
   }
else if(e[b1]=="water" && e[b2]=="earth")
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
     criticalHits1++;
}
else
{
    totalDamage=1*totalDamage;
}
if(effect3=="burn" && et3<=4)
{
    totalDamage=totalDamage + (0.1*ohp[b2]);
    et3++;
}
            cout<<n[b2]<<" took "<<totalDamage<<" damage"<<endl;
            if(totalDamage>=hp[b2])
            {
                cout<<n[b2]<<" is fainted "<<endl;
                t1++;
                dead1=1;
                break;
            }
            else{
                cout<<n[b2]<<" is not fainted and it is still alive with the hp of "<<(hp[b2]-totalDamage)<<"/"<<ohp[b2]<<endl;
                hp[b2]=hp[b2]-totalDamage;
                c1++;
                t1++;
            }
       }
}
       }
    }
}
       if(dead1==1)
    {
        cout<<"winner of the semifinal 2 : "<<n[b1]<<endl;
        cout<<"Turn : "<<t1<<endl;
        cout<<"critical hits : "<< criticalHits1<<endl;
        cout<<"Super effective hits : "<<seh1<<endl;
    }
    if(dead1==2)
    {
        cout<<"winner of the semifinal 2 : "<<n[b2]<<endl;
        cout<<"Turn : "<<t1<<endl;
        cout<<"critical hits : "<< criticalHits1<<endl;
        cout<<"Super effective hits : "<<seh1<<endl;
    }
    winner=dead1;
}
};
int main()
{
    int choose;
    cout<<"Enter your choice "<<endl;
    cout<<"Enter 1 if you want to want to play against AI"<<endl;
    cout<<"Enter 2 if you want to play in the tournament"<<endl;
    cin>>choose;
    switch(choose)
    {
        case 1://playing against AI
        {
            string n1,m1[4],e1;
            int hp1,ap1,d1,s1,ohp1,seh=0,criticalHits=0,dead,effect=0;
            int dam1[4];
         cout<<"Enter the detail of your character"<<endl;
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
        //detail of the AI bot
        string n2="AI BOT";
        int x=time(0);
        srand(x);
        int hp2=rand() % (200) + 1;//for hp of the ai bot
        int ohp2=hp2;
        int ap2=rand() % (100) + 1;//for attack power of the ai bot
        int d2=rand() % (100) + 1;//for defence of the ai bot
        int s2=rand() % (100) + 1;//for speed of the ai bot
        int r=rand() % (4) + 0;//for element of the ai bot
        int r1=rand() % (4) + 0;//for moves of the ai bot
        string e[4]={"fire","water","earth","air"};
        string e2=e[r];
        string m2[4];
        int dam2[4];
        cout<<"Enter the name of the move and the damage of each move will be decided by AI itself"<<endl;
        cin.ignore();
        for(int i=0;i<3;i++)
        {
           getline(cin,m2[i]);
        }
        m2[3]="healing";
         int maxDam=0;
        for(int i=0;i<3;i++)
        {
            int r2=rand() % (100) + 1;
            dam2[i]=r2;
            if(dam2[i]> maxDam)
            {
             maxDam=dam2[i];
            }
        }
        dam2[3]=30;
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
       int t=0,c=1,et1,et2;
       string effect1="",effect2="";
       if(s1>s2)
       {
        cout<<"Your character will attack first as the speed of your character is more than the AI bot character speed"<<endl;
        while(1>0)
        {
        if(c%2!=0)
        {
             int r6;
            if(effect2 == "buried" )
            {
                r6=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect2=="frozen" && et2<=3)
         {
            et2++;
            r6=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r6==1 || (effect2=="buried" && et1<=r6))
         {
            cout<<"The chance of the user skip"<<endl;
            c++;
            t++;
            et2++;
         }
         else
         {
            if(hp1 < 0.2*ohp1)
            {
                string decision;
                cout<<"Do you want to use the special effect"<<endl;
                cin>>decision;
                if(decision=="yes")
                {
                    et1=0;
                    cout<<"choose one special effect among (burn,frozen,buried)"<<endl;
                    cout<<"burn : Deals 10% max HP damage each turn for 4 turns"<<endl;
                    cout<<"Frozen 50percent chance to skip turns for 3 turns"<<endl;
                    cout<<"buried : cannot move for 2-4 turns(random duration)"<<endl;
                    cout<<"Write the name of the effect which you wanted to choose"<<endl;
                    cin>>effect1;
                    effect++;
                }
                else
                {
                    cout<<"No special effect is used"<<endl;
                }
            }
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n1<<" used "<<m1[ch]<<endl;
            double totalDamage=((ap1*dam1[ch])/d2);
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
if(effect1=="burn" && et1<=4)
{
    totalDamage=totalDamage + (0.1*ohp2);
    et1++;
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
        else
        {
            int r3;
            if(effect1 == "buried" )
            {
                r3=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect1=="frozen" && et1<=3)
         {
            et1++;
            r3=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r3==1 || (effect1=="buried" && et1<=r3))
         {
            cout<<"The chance of the AI bot skip"<<endl;
            c++;
            t++;
            et1++;
         }
         else
         {
            double totalDamage;
          if(hp2<0.3*ohp2)
          {
            hp2=hp2+dam2[3];
            c++;
          }
          else if(hp1>0.7*ohp1)
          {
            effect++;
            et2=0;
            int r4=rand() % (3) + 1;
            if (r4==1)
            {
                effect2="burn";
            }
            if(r4==2)
            {
                effect2="frozen";
            }
            if(r4==3)
            {
                effect2="buried";
            }
          }
          else if(hp1<0.25*ohp1)
          {
            totalDamage=maxDam;
          }
          else{
            int r5=rand() % 3;
            totalDamage=((ap2*dam2[r5])/d1);
          }
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
if(effect2=="burn" && et2<=4)
{
    totalDamage=totalDamage + (0.1*ohp1);
    et2++;
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
        }
        else{
            cout<<"The AI bot will attack first as the speed of the bot is more than the user character"<<endl;
             while(1>0)
            {
            if(c%2!=0)
            {
            int r3;
            if(effect1 == "buried" )
            {
                r3=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect1=="frozen" && et1<=3)
         {
            et1++;
            r3=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r3==1 || (effect1=="buried" && et1<=r3))
         {
            cout<<"The chance of the AI bot skip"<<endl;
            c++;
            t++;
            et1++;
         }
         else
         {
            double totalDamage;
          if(hp2<0.3*ohp2)
          {
            hp2=hp2+dam2[3];
            c++;
          }
          else if(hp1>0.7*ohp1)
          {
            effect++;
            et2=0;
            int r4=rand() % (3) + 1;
            if (r4==1)
            {
                effect2="burn";
            }
            if(r4==2)
            {
                effect2="frozen";
            }
            if(r4==3)
            {
                effect2="buried";
            }
          }
          else if(hp1<0.25*ohp1)
          {
            totalDamage=maxDam;
          }
          else{
            int r5=rand() % 3;
            totalDamage=((ap2*dam2[r5])/d1);
          }
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
if(effect2=="burn" && et2<=4)
{
    totalDamage=totalDamage + (0.1*ohp1);
    et2++;
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
        else{
                int r6;
            if(effect2 == "buried" )
            {
                r6=rand() % (3) + 2;//because if the user use the buried special effect then the opponent will not moved for (2-4)turns
            }
         if(effect2=="frozen" && et2<=3)
         {
            et2++;
            r6=rand() % (1) ;//because their is 50% chance that the opponent will skip the chace therefore if r3=1 then the opponent will skip the turn and if r3=0 then the opponent will not skip the chance
         }
         if(r6==1 || (effect2=="buried" && et1<=r6))
         {
            cout<<"The chance of the user skip"<<endl;
            c++;
            t++;
            et2++;
         }
         else
         {
            if(hp1 < 0.2*ohp1)
            {
                string decision;
                cout<<"Do you want to use the special effect"<<endl;
                cin>>decision;
                if(decision=="yes")
                {
                    et1=0;
                    cout<<"choose one special effect among (burn,frozen,buried)"<<endl;
                    cout<<"burn : Deals 10% max HP damage each turn for 4 turns"<<endl;
                    cout<<"Frozen 50percent chance to skip turns for 3 turns"<<endl;
                    cout<<"buried : cannot move for 2-4 turns(random duration)"<<endl;
                    cout<<"Write the name of the effect which you wanted to choose"<<endl;
                    cin>>effect1;
                    effect++;
                }
                else
                {
                    cout<<"No special effect is used"<<endl;
                }
            }
            int ch;
            cout<<"choose the move of the character which is used for attacking (0-3)"<<endl;
            cin>>ch;
            cout<<n1<<" used "<<m1[ch]<<endl;
            double totalDamage=((ap1*dam1[ch])/d2);
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
if(effect1=="burn" && et1<=4)
{
    totalDamage=totalDamage + (0.1*ohp2);
    et1++;
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
}
}
if(dead==1)
    {
        cout<<"winner : "<<n2<<endl;
        cout<<"Turn : "<<t<<endl;
        cout<<"critical hits : "<< criticalHits<<endl;
        cout<<"Super effective hits : "<<seh<<endl;
        cout<<"total no of effects used : "<<effect<<endl;
    }
    if(dead==2)
    {
        cout<<"winner : "<<n1<<endl;
        cout<<"Turn : "<<t<<endl;
        cout<<"critical hits : "<< criticalHits<<endl;
        cout<<"Super effective hits : "<<seh<<endl;
         cout<<"total no of effects used : "<<effect<<endl;
    }
    break;
    }//case
    case 2:
    {
     int w1,w2,w3;
    int x=time(0);
    srand(x);
    int q=rand() % 3 + 1;
    UserVsAi(q,w1);
    if(q==1)
    {
        AiVsAi(2,3,w2);
        if(w1==1)//Aibot is the winner
    {
    if(w2==1)
    {
        AiVsAi(1,2,w3);
        if(w3==1)
        {
            cout<<"bot 1 is first"<<endl;
            cout<<"bot 2 is second"<<endl;
            cout<<"user and bot 3 tied for the third place"<<endl;
        }
        else{
            cout<<"bot 2 is first"<<endl;
            cout<<"bot 1 is second"<<endl;
            cout<<"user and bot 3 tied for the third place"<<endl;
        }
    }
    else
    {
    AiVsAi(1,3,w3);
    if(w3==1)
    {
        cout<<"bot 1 is first"<<endl;
            cout<<"bot 3 is second"<<endl;
            cout<<"user and bot 2 tied for the third place"<<endl;
    }
   else  
{
    cout<<"bot 3 is first"<<endl;
            cout<<"bot 1 is second"<<endl;
            cout<<"user and bot 2 tied for the third place"<<endl;
}
    }
    }
    else
    {
     if(w2==1)
    {
        UserVsAi(2,w3);
        if(w3==1)
        {
         cout<<"bot 2 is first"<<endl;
            cout<<"user is second"<<endl;
            cout<<"bot 1  and bot 3 tied for the third place"<<endl;
        }
        else{
             cout<<"user is first"<<endl;
            cout<<"bot 2 is second"<<endl;
            cout<<"bot 1 and bot 3 tied for the third place"<<endl;
        }
    }
    else
    {
    UserVsAi(3,w3);
    if(w3==1)
    {
        cout<<"bot 3 is first"<<endl;
            cout<<"user is second"<<endl;
            cout<<"bot 1  and bot 2 tied for the third place"<<endl;
    }
else
{
    cout<<"user is first"<<endl;
            cout<<"bot 3 is second"<<endl;
            cout<<"bot 1  and bot 2 tied for the third place"<<endl;
}
    }
    }
    }
    if(q==2)
    {
        AiVsAi(1,3,w2);
        if(w1==1)//Aibot is the winner
    {
    if(w2==1)
    {
        AiVsAi(2,1,w3);
        if(w3==1)
        {
            cout<<"bot 2 is first"<<endl;
            cout<<"bot 1 is second"<<endl;
            cout<<"bot 3  and user tied for the third place"<<endl;
        }
        else{
            cout<<"bot 1 is first"<<endl;
            cout<<"bot 2 is second"<<endl;
            cout<<"bot 3  and user tied for the third place"<<endl;
        }
    }
    else
    {
    AiVsAi(2,3,w3);
    if(w3==1)
    {
        cout<<"bot 2 is first"<<endl;
            cout<<"bot 3 is second"<<endl;
            cout<<"bot 1  and user tied for the third place"<<endl;
    }
    else{
        cout<<"bot 3 is first"<<endl;
            cout<<"bot 2 is second"<<endl;
            cout<<"bot 1  and user tied for the third place"<<endl;
    }
    }
    }
    else
    {
     if(w2==1)
    {
        UserVsAi(1,w3);
        if(w3==1)
        {
            cout<<"bot 1 is first"<<endl;
            cout<<"user is second"<<endl;
            cout<<"bot 2  and bot 3 tied for the third place"<<endl;
        }
        else{
            cout<<"user is first"<<endl;
            cout<<"bot 1 is second"<<endl;
            cout<<"bot 2  and bot 3 tied for the third place"<<endl;
        }
    }
    else
    {
    UserVsAi(3,w3);
    if(w3==1)
    {
        cout<<"bot 3 is first"<<endl;
            cout<<"user is second"<<endl;
            cout<<"bot 2  and bot 1 tied for the third place"<<endl;
    }
    else
    {
        cout<<"user is first"<<endl;
            cout<<"bot 3 is second"<<endl;
            cout<<"bot 2  and bot 1 tied for the third place"<<endl;
    }
    }
    }
    }
    if(q==3)
    {
        AiVsAi(1,2,w2);
        if(w1==1)//Aibot is the winner
    {
    if(w2==1)
    {
        AiVsAi(3,1,w3);
        if(w3==1)
        {
            cout<<"bot 3 is first"<<endl;
            cout<<"bot 1 is second"<<endl;
            cout<<"bot 2  and user tied for the third place"<<endl;
        }
        else{
            if(w3==1)
        {
            cout<<"bot 1 is first"<<endl;
            cout<<"bot 3 is second"<<endl;
            cout<<"bot 2  and user tied for the third place"<<endl;
        }
        }
    }
    else
    {
    AiVsAi(3,2,w3);
    if(w3==1)
        {
            cout<<"bot 3 is first"<<endl;
            cout<<"bot 2 is second"<<endl;
            cout<<"bot 1  and user tied for the third place"<<endl;
        }
        else
        {
             cout<<"bot 2 is first"<<endl;
            cout<<"bot 3 is second"<<endl;
            cout<<"bot 1  and user tied for the third place"<<endl;
        }
    }
    }
    else
    {
     if(w2==1)
    {
        UserVsAi(1,w3);
        if(w3==1)
        {
             cout<<"bot 1 is first"<<endl;
            cout<<"user is second"<<endl;
            cout<<"bot 2  and bot 3 tied for the third place"<<endl;
        }
        else{
            cout<<"user is first"<<endl;
            cout<<"bot 1 is second"<<endl;
            cout<<"bot 2  and bot 3 tied for the third place"<<endl;
        }
    }
    else
    {
    UserVsAi(2,w3);
    if(w3==1)
    {
        cout<<"bot 2 is first"<<endl;
            cout<<"user is second"<<endl;
            cout<<"bot 3  and bot 1 tied for the third place"<<endl;
    }
    else
    {
        cout<<"user is first"<<endl;
            cout<<"bot 2 is second"<<endl;
            cout<<"bot 1  and bot 3 tied for the third place"<<endl;
    }
    }
    }
    }
    break;
    }
}//switch
}//main
