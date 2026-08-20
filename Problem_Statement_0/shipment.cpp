#include <iostream>
using namespace std;
int main ()
{
    int c,n,sum=0,k;
    double avg;
    // c is the maximum storage capacity of the port
    // n is the number of container
    cout<<"enter the maximum capacity of the port"<<endl;
    cin>>c;
    cout<<"enter the total number of container"<<endl;
    cin>>n;
    int w[n];
    // w is an array in which we store the weight of the container
    for(int i=0;i<n;i++)
    {
        cout<<"enter the weight of the container "<<i+1<<endl;
       cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+w[i];
    }
    avg = sum/n;
    int max = w[0];
    int min= w[0];
    // we assume that the maximum and minmum value of the weight of the container is w[0]
    for(int i=1;i<n;i++)
    {
        if(max<w[i])
        {
            max=w[i];
        }
        if(min>w[i])
        {
            min=w[i];
        }
    }
    int p=0,q=0;
    int hw[p];
    int lw[q];
    for(int i=0;i<n;i++)
    {
        if(w[i]>200)
        {
         hw[p]=w[i];
            p++;
        }
        else{
         lw[q]=w[i];
            q++;
        }
    }
    //sorting of the given data in ascending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(w[j]>w[j+1])
            {
                int m=w[j+1];//to store the value of w[j+1]
                w[j+1]=w[j];
                w[j]=m;
            }
        }
    }
    //printing the sorted array
    cout<<"the weights is arranged in ascending order"<<endl;
    for(int i=0;i<n;i++)
    {
    cout<<w[i]<<"  ";
    }
    cout<<endl;
    //bar graph of the weight of the shipment
    for(int i=0;i<n;i++)
    {
        int p=0;
    for(int j=0;j<n;j++)
    {
        if(w[i]==w[j])
        {
            p++;
        }
    }
    cout<<w[i];
    for(int k=0;k<p;k++)
    {
    cout<<" * ";
    }
    cout<<endl;
    i=i+(p-1);
    }
    //removing the repeated elements (personal addition)
    int r=0;// to store the size of array b
    int b[r];// to store the array after the removal of elements
    cout<<"the data of the weight after the removal of weight"<<endl;
    for(int i=0;i<n;i++)
    {
        int e=0;//to store how many time a given weight is repeated
        for(int j=0;j<n;j++)
        {
            if(w[i]==w[j])
            {
               e++;
            }
        }
        b[r]=w[i];
        cout<<w[i]<<" ";
        i=i+(e-1);
        r++;
    }
    cout<<endl;
    // hw represent the heavy weight container
    // lw represent the light weight container
    cout<<"the port capacity is "<<c<<endl;
    cout<<"the sum of weight of total container is "<<sum<<endl;
    cout<<"the average of the weights of the container is "<<avg<<endl;
    cout<<"the maximum weight of the container is "<<max<<endl;
    cout<<"the minimum weight of the container is "<<min<<endl;
    cout<<"the total number of heavy shipment is "<<p<<endl;
    cout<<"the total number of light shipment is "<<q<<endl;
    int x;//to store the value of weight of the shipment enter by the user
    cout<<"enter the weight to be searched"<<endl;
    cin>>x;
    int v=0;//to check whether the entered weight is present or not if present then it value is greater than 0 and if not present the it value remain 0
    for(int i=0;i<n;i++)
    {
        if(w[i]==x)
        {
            v++;
        }
    }
    if(v>0)
    {
        cout<<"the shipment of weight "<<x<<" is found"<<endl;
    }
    else{
        cout<<"the shipment of weight "<<x<<" is not found"<<endl;
    }
    cout<<"enter the value of k to find the kth heaviest shipment"<<endl;
    cin>>k;
    cout<<"kth heaviest shipment is "<<b[r-k]<<endl;
    if(sum<=c)
    {
        cout<<"shipment can be unloaded";
    }
    else{
        cout<<"shipment exceed the port capacity";
    }


    return 0;
}