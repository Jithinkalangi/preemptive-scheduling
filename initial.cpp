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
main()
{
	int n;
	cout<<"Enter the number of processes";
	cin>>n;
	process p[n];
}
