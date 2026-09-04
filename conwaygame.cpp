#include <iostream>
using namespace std;
int main()
{
    int r,c;//r=row and c=column
    std ::cout<<"enter the value of row"<<endl;
    cin>>r;
    std ::cout<<"enter the value of column"<<endl;
    cin>>c;
    string a[r][c];//a is an array which represent the grid
    string b[r][c];//b is an store the change array
    std ::cout<<"enter the initial condition"<<endl;
    std ::cout<<"# repredent live"<<endl;
    std ::cout<<"* represent died"<<endl;
    for(int i=0;i<r;i++)
    {
     for(int j=0;j<c;j++)
    {
     cin>>a[i][j];
    }
    }
    int il=0,id=0;
    //il is used to count the total no of live neighbors intially
    std ::cout<<"initial condition "<<endl;
    for(int i=0;i<r;i++)
    {
     for(int j=0;j<c;j++)
    {
        if(a[i][j]=="#")
        {
            il++;
        }
     std ::cout<<a[i][j]<<" ";
    }
    std ::cout<<endl;
    }
    int pp=il;//pp represent peak population 
    std ::cout<<"initial population "<<il<<endl;
    for(int i=0;i<r;i++)
    {
        
        for(int j=0;j<c;j++)
        {
            int l=0;//l is used to count the no of live neighbors
            if(i-1<0 && j-1>=0 )
       {
        if(a[r-i-1][c-j-1]=="#")
        {
            l++;
        }
       }
       if(j-1<0 && i-1>=0)
       {
        if(a[r-i-1][c-j-1]=="#")
        {
            l++;
        }
       }
       if(i-1<0 && j-1<0)
       {
        if(a[r-i-1][c-j-1]=="#")
        {
            l++;
        }
       }
       if(i>=r-1 && j<c-1)
       {
         if(a[r-i-1][c-j-1]=="#")
        {
            l++;
        }
       }
        if(j>=c-1 && i<r-1)
       {
         if(a[r-i-1][c-j-1]=="#")
        {
            l++;
        }
    }
    if(j>=c-1 && i>=r-1)
    {
        if(a[r-i-1][c-j-1]=="#")
        {
            l++;
        }
       }
       if(i!=0 && j==0 && i<r-1)
       {
        if(a[r-i][c-1]=="#")
        {
            l++;
        }
        if(a[r-2-i][c-1]=="#")
        {
            l++;
        }
       }
       if(i==0 && j!=0 && j<c-1)
       {
        if(a[r-1][c-j]=="#")
        {
            l++;
        }
        if(a[r-1][c-2-j]=="#")
        {
            l++;
        }
       }
       if(i==r-1 && j!=0 && j!=c-1)
    {
     if(a[0][c-j]=="#")
     {
        l++;
     }
     if(a[r-i-1][c-1-j]=="#")
     {
        l++;
     }
    }
      if(j==c-1 && i!=0 && i!=c-1)
    {
     if(a[r-i][0]=="#")
     {
        l++;
     }
     if(a[r-i-1][c-1-j]=="#")
     {
        l++;
     }
    }
            if((i-1)>=0 && (j-1)>=0)
            {
                if(a[i-1][j-1]=="#")
                {
                    l++;
                }
            }
            if((i-1)>=0)
            {
                if(a[i-1][j]=="#")
                {
                    l++;
            }
            if(j<c-1 )
            {
                if(a[i-1][j+1]=="#")
                {
                    l++;
                }
            }
            }
            if((j-1)>=0)
            {
              if(a[i][j-1]=="#")
                {
                    l++;
            }
            if(i<r-1)
            {
                if(a[i+1][j-1]=="#")
                {
                    l++;
                } 
            }
            }
            if(i<r-1)
            {

             if(a[i+1][j]=="#")
            {
                l++;
            }
        }
        if(j<c-1)
        {
             if(a[i][j+1]=="#")
            {
                l++;
            }
        }
        if(i<r-1 && j<c-1)
        {
             if(a[i+1][j+1]=="#")
            {
                l++;
            }
        }
            if(a[i][j]=="#" && l<2)
            {
                b[i][j]="*";
            }
            else if(a[i][j]=="#" && l>=2 && l<=3)
            {
             b[i][j]="#";
            }
            else if(a[i][j]=="#" && l>3)
            {
                b[i][j]="*";
            }
             else if(a[i][j]=="*" && l==3)
             {
                b[i][j]="#";
             }
             else{
                b[i][j]=a[i][j];
             }
              int cl=0;//to count how many are live
             for(int x=0;x<r;x++)
             {
                for(int y=0;y<c;y++)
                {
                    if(a[x][y]=="#")
                    {
                     cl++;
                    }
                }
             }
             if(cl>pp)
             {
                pp=cl;
             }
        }
    }
    int fl=0;//fl is used to count total lives
    cout<<"final condition "<<endl;
    for(int i=0;i<r;i++)
    {
    for(int j=0;j<c;j++)
    {
     if(b[i][j]=="#")
     {
      fl++;
     }
    std ::cout<<b[i][j]<<" ";
    }
    std ::cout<<endl;
    }
   std ::cout<<"final population "<<fl<<endl;
   std ::cout<<"peak population  "<<pp<<endl;
}