#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class process
{
	public:
		int at,bt,btcopy,wt,ct,p,tat;
		static int i,twt ;
		static int totaltime,maxar;
		string pid;
		process()
		{
			i++;
			cout<<"Enter the processid of process number "<<i;
			cin>>pid;
			cout<<"Enter the arrival time";
			cin>>at;
			cout<<"Enter the burst time"<<endl;
			cin>>bt;
			while(bt<1)
			
			{
				cout<<"burst time cannot be less than 1"<<endl;	
				cin>>bt;
			}
			btcopy=bt;
			p=0;
			maxar=maxar>at?maxar:at;
			//cout<<"Enter the priority"<<endl;
			//cin>>p;
			totaltime=totaltime+bt;
		}
		void printd()
		{	static int a=0;
		if(a==0)
		{
			cout<<setw(15)<<"Process id"<<setw(15)<<"Arrival time"<<setw(15)<<"Burst time"<<setw(17)<<"Completion time"<<setw(15)<<"Waiting time"<<endl;
			
		}
			tat=ct-at;
			wt=tat-btcopy;
			twt+=wt;
			cout<<setw(15)<<pid<<setw(15)<<at<<setw(15)<<btcopy<<setw(17)<<ct<<setw(15)<<wt<<endl;	
			if(a==i-1)
			{
				cout<<setw(20)<<"Average waiting time ="<<(float)twt/i;
			}	
			a++;		
		}
		
};

int process::totaltime=0;
int process::i=0;
int process::twt=0;
int process::maxar=0;

bool arrivaltime(process p1,process p2)
{
	return p1.at<p2.at;
}

bool priority(process p1,process p2)
{
	return p1.p>=p2.p;
}
main()
{
	int n;
	cout<<"Enter the number of processes";
	cin>>n;
	process p[n];
	sort(p,p+n,arrivaltime);
	for(int i=0;i<=process::totaltime+process::maxar;i++)
	{
		int j=0;
		for(;j<n;j++)
		{
			if(p[j].at>i)
			break;
		}
		sort(p,p+j,priority);
		if(j>=0)
		{
			int k;
			for( k=0;k<j;k++)
			{
				if(p[k].bt!=0)
				break;
			}
			if(k==n)
			break;			
			if(k<j)
			{
				p[k].bt--;
				p[k].p++;
				if(p[k].bt==0)
				p[k].ct=i+1;			
			}	
			int pre=k;
			for( k=0;k<j;k++)
			{
				if(k==pre)
				continue;
				p[k].p+=2;
			}
		}
	}
	sort(p,p+n,arrivaltime);
	for(int i=0;i<n;i++)
	{
		p[i].printd(); 
	}
	return 0;
}
