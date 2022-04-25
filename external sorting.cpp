#include<bits/stdc++.h>
using namespace std;

vector<int> l1;
void mergeSort(vector<vector<int> > &arr)
{
    int k= arr.size();
    int pos[k]={0};

    int index;
    do
    {
        int minele= INT_MAX;
        index=-1;
        for(int i=0;i<k;i++)
        {
            if(pos[i]<arr[i].size() && arr[i][pos[i]]<minele)
            {
                minele= arr[i][pos[i]];
                index=i;
            }
        }

        if(index!=-1)
        {
            cout<<minele<<endl;
            l1.push_back(minele);
            pos[index]++;
        }
    } while(index!=-1);
}

int main()
{
    int bufferPages, pageLimit;
    double n;
    cin>>bufferPages;
    cin>>pageLimit;
    cin>>n;
    int k=ceil(n/pageLimit);

    vector<vector<int> > arr;
    int i=0;
    int pageNo=0;
    int j=0;

    while(i<n)
    {
        int x;
        cin>>x;

        if(j==0)
        {
            vector<int> v;
            arr.push_back(v);
        }
        arr[pageNo].push_back(x);

        j++;
        if(j==pageLimit)
        {
            sort(arr[pageNo].begin(), arr[pageNo].end());
            pageNo++;
            j=0;
        }
        i++;
    }

    cout<<"\nNumber of pages: "<<arr.size()<<endl;
    cout<<"\nPrinting pages:\n";
    for(int l=0;l<arr.size();l++)
    {
        for(int p=0;p<arr[l].size(); p++)
        {
            cout<<arr[l][p]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    mergeSort(arr);
    cout<<endl;
    int index=0;
    for(int l=0;l<k;l++)
    {
        cout<<l<<" :";
        for(index=pageLimit*l;index<=pageLimit*(l+1)-1 && index<n;index++)
        {
            cout<<" "<<l1[index];
        }
        cout<<endl;
    }
}
