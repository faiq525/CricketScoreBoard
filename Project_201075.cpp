#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Match{
	private:
		int toss,dec;
	protected:
		string TeamName1,TeamName2;
	public:
		bool InputStartingData(){
			cout<<"********Welcome to Rawalpindi Cricket Stadium***********"<<endl;
			cout<<"The Match is About to Start"<<endl;
			cout<<"Enter Name of Team 1: ";
			cin>>TeamName1;
			cout<<"Enter Name of Team 2: ";
			cin>>TeamName2;
			system("CLS");
			cout<<"The Coin is up in the air and................"<<endl;
			cout<<"Who Won the Toss??"<<endl;
			cout<<"Enter 1 for "<<TeamName1<<" and 2 for "<<TeamName2<<": ";
			cin>>toss;
			cout<<"The Toss Winner Selected for,"<<endl;
			cout<<"Enter 1 for Batting and 2 for Bowling: ";
			cin>>dec;
			system("CLS");
			if (toss==1){
				cout<<TeamName1<<" has won the toss and selected to";
				if (dec==1){
					cout<<" Bat first."<<endl;
					return 0;
				}
				else if (dec=2){
					cout<<" Ball first."<<endl;
					return 1;
				}
			}
			if (toss==2){
				cout<<TeamName2<<" has won the toss and selected to";
				if (dec==1){
					cout<<" Bat first."<<endl;
					return 1;
				}
				else if (dec=2){
					cout<<" Ball first."<<endl;
					return 0;
				}
			}
		}
		string getTeamName1(){
			return TeamName1;
		}
		string getTeamName2(){
			return TeamName2;
		}
};

class PlayerTeam{
	public:
		string name;
		int BattingRuns,BallingRuns,wickets,BallsPlayed,BallsThrown,overs,fours,sixes,noballs,wide;
		PlayerTeam1(){
			BattingRuns=0;
			BallingRuns=0;
			wickets=0;
			BallsPlayed=0;
			BallsThrown=0;
			overs=0;
			fours=0;
			sixes=0;
			noballs=0;
			wide=0;
		}
};

class ScoreCard: public Match, public PlayerTeam{
	private:
		int Team1Runs, Team1Wickets, Team1Sixes, Team1Fours, Team1Dotballs, Team1Noballs, Team1Wide, Team2Runs, Team2Wickets, Team2Sixes, Team2Fours, Team2Dotballs, Team2Noballs, Team2Wide, overs1, overs2, BallsThrown1, BallsThrown2;
		PlayerTeam *PT1[4], *PT2[4],*baller,*currentbatter,*secondbatter;
	protected:
		
	public:
		ScoreCard(){
			Team1Runs=0;
			overs1=0;
			overs2=0;
			BallsThrown1=0;
			BallsThrown2=0;
			Team2Runs=0;
			Team1Sixes=0;
			Team2Sixes=0;
			Team1Fours=0;
			Team2Fours=0;
			Team1Dotballs=0;
			Team2Dotballs=0;
			Team1Noballs=0;
			Team2Noballs=0;
			Team1Wide=0;
			Team2Wide=0;
			Team1Wickets=0;
			Team2Wickets=0;
			baller=NULL;
			for (int i=0; i<4; i++){
				PT1[i] = new PlayerTeam();
				PT2[i] = new PlayerTeam();
			}
		}
		void Exchange(){
			PlayerTeam *exchange;
			exchange=secondbatter;
			secondbatter=currentbatter;
			currentbatter=exchange;
		}
		void InputPlayerNames(){
			cout<<"Enter Player Names for Team "<<getTeamName1()<<" (According to batting order): "<<endl;
			cin.ignore(100,'\n');
			for (int i=0; i<4; i++){
				getline(cin,PT1[i]->name);
			}
			system("CLS");
			cout<<"Enter Player Names for Team "<<getTeamName2()<<" (According to batting order): "<<endl;
			for (int i=0; i<4; i++){
				getline(cin,PT2[i]->name);
			}
		}
		void ShowScore1(){
			cout<<getTeamName1()<<" "<<Team1Runs<<" - " <<Team1Wickets<<endl;
			cout<<"Overs "<<overs1<<"."<<BallsThrown1<<endl;
			cout<<currentbatter->name<<"* "<<currentbatter->BattingRuns<<"("<<currentbatter->BallsPlayed<<")\t"<<secondbatter->name<<" "<<secondbatter->BattingRuns<<"("<<secondbatter->BallsPlayed<<")"<<endl;
			cout<<baller->name<<" "<<baller->overs<<"."<<baller->BallsThrown<<" "<<baller->BallingRuns<<"-"<<baller->wickets<<endl;
		}
		void ShowScore2(){
			cout<<getTeamName2()<<" "<<Team2Runs<<" - " <<Team2Wickets<<endl;
			cout<<"Overs "<<overs2<<"."<<BallsThrown2<<endl;
			cout<<currentbatter->name<<"* "<<currentbatter->BattingRuns<<"("<<currentbatter->BallsPlayed<<")\t"<<secondbatter->name<<" "<<secondbatter->BattingRuns<<"("<<secondbatter->BallsPlayed<<")"<<endl;
			cout<<baller->name<<" "<<baller->overs<<"."<<baller->BallsThrown<<" "<<baller->BallingRuns<<"-"<<baller->wickets<<endl;	
		}
		void BattingTeam1(){
			int balls=0;
			int runs=0;
			int selection;
			currentbatter=PT1[0];
			secondbatter=PT1[1];
			cout<<endl;
			cout<<"Who is Balling First? \nPress";
			for (int i=0; i<4; i++){
				cout<<" "<<i<<" for "<<PT2[i]->name<<",";
			}
			cout<<": ";
			cin>>selection;
			baller=PT2[selection];
			cout<<endl;
			system("CLS");
			ShowScore1();
			while (balls<24 && Team1Wickets<4){
				if (balls%6==0 && balls>5 && balls!=24){
					PlayerTeam *exchange;
					overs1+=1;
					BallsThrown1=0;
					baller->overs+=1;
					baller->BallsThrown=0;
					exchange=secondbatter;
					secondbatter=currentbatter;
					currentbatter=exchange;
					cout<<"Who is Balling, \nPress";
					for (int i=0; i<4; i++){
						cout<<" "<<i<<" for "<<PT2[i]->name<<",";
					}
					cout<<": ";
					cin>>selection;
					baller=PT2[selection];
					cout<<endl;	
				}
				cout<<"Press 0 for DotBall, 1 for 1 runs, 2 for 2 runs, 3 for 3 runs, 4 for 4 runs, 6 for 6 runs, 7 for Wide, 8 for NoBall, 9 for OUT"<<endl;
				cin>>runs;
				if (runs==0){
					system("CLS");
					baller->BallsThrown+=1;
					BallsThrown1+=1;
					currentbatter->BallsPlayed+=1;
					Team1Dotballs+=1;
					balls++;
				}
				else if (runs==1){
					system("CLS");
					baller->BallsThrown+=1;
					baller->BallingRuns+=1;
					BallsThrown1+=1;
					Team1Runs+=1;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=1;
					Exchange();
					balls++;
				}
				else if (runs==2){
					system("CLS");
					baller->BallsThrown+=1;
					baller->BallingRuns+=2;
					BallsThrown1+=1;
					Team1Runs+=2;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=2;
					balls++;
				}
				else if (runs==3){
					system("CLS");
					baller->BallsThrown+=1;
					baller->BallingRuns+=3;
					BallsThrown1+=1;
					Team1Runs+=3;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=3;
					Exchange();
					balls++;
				}
				else if (runs==4){
					system("CLS");
					cout<<"*********A Beautifull Four************"<<endl;
					baller->BallsThrown+=1;
					baller->BallingRuns+=4;
					BallsThrown1+=1;
					Team1Runs+=4;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=4;
					currentbatter->fours+=1;
					Team1Fours+=1;
					balls++;
				}
				else if (runs==6){
					system("CLS");
					cout<<"************A Big Six************"<<endl;
					baller->BallsThrown+=1;
					baller->BallingRuns+=6;
					BallsThrown1+=1;
					Team1Runs+=6;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=6;
					currentbatter->sixes+=1;
					Team1Sixes+=1;
					balls++;
				}
				else if (runs==7){
					system("CLS");
					cout<<"***************Wide Ball***************"<<endl;
					baller->BallingRuns+=1;
					Team1Runs+=1;
					currentbatter->BattingRuns+=1;
					baller->wide+=1;
					Team1Wide+=1;
				}
				else if (runs==8){
					system("CLS");
					int temp=0;
					cout<<"How many runs on NoBall: ";
					cin>>temp;
					baller->BallingRuns+=temp;
					Team1Runs+=temp;
					currentbatter->BattingRuns+=temp;
					baller->noballs+=1;
					Team1Noballs+=1;
					if(temp%2!=0){
						Exchange();
					}
					cout<<"********No Ball Free Hit*********"<<endl;
				}
				else if (runs==9){
					system("CLS");
					cout<<"*********OUT**********"<<endl;
					int temp=0;
					cout<<"How many runs gained before getting out on the Ball: ";
					cin>>temp;
					baller->BallsThrown+=1;
					baller->BallingRuns+=temp;
					baller->wickets+=1;
					BallsThrown1+=1;
					Team1Runs+=temp;
					Team1Wickets+=1;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=temp;
					if(Team1Wickets<3){
						currentbatter=PT1[Team1Wickets+1];
						cout<<"Next Batter is "<<currentbatter->name<<endl;
					}
					else if (Team1Wickets==3){
						currentbatter=secondbatter;
					}
					if (temp%2!=0){
						Exchange();
					}
					balls++;
				}
				else {
					system("CLS");
					cout<<"Wrong Option Selected Try Again!!!!!!!!!!!!!"<<endl;
				}
				ShowScore1();
			}
			cout<<"***************Inings Ended******************"<<endl;
			cout<<"Press Enter to continue..........."<<endl;
			string cont;
			cin.ignore(100,'\n');
			getline(cin,cont);
		}
		void BattingTeam2(){
			int balls=0;
			int runs=0;
			int selection;
			currentbatter=PT2[0];
			secondbatter=PT2[1];
			cout<<endl;
			cout<<"Who is Balling First? \nPress";
			for (int i=0; i<4; i++){
				cout<<" "<<i<<" for "<<PT1[i]->name<<",";
			}
			cout<<": ";
			cin>>selection;
			baller=PT1[selection];
			cout<<endl;
			system("CLS");
			ShowScore2();
			while (balls<24 && Team2Wickets<4){
				if (balls%6==0 && balls>5 && balls!=24){
					PlayerTeam *exchange;
					overs2+=1;
					BallsThrown2=0;
					baller->overs+=1;
					baller->BallsThrown=0;
					exchange=secondbatter;
					secondbatter=currentbatter;
					currentbatter=exchange;
					cout<<"Who is Balling, \nPress";
					for (int i=0; i<4; i++){
						cout<<" "<<i<<" for "<<PT1[i]->name<<",";
					}
					cout<<": ";
					cin>>selection;
					baller=PT1[selection];
					cout<<endl;	
				}
				cout<<"Press 0 for DotBall, 1 for 1 runs, 2 for 2 runs, 3 for 3 runs, 4 for 4 runs, 6 for 6 runs, 7 for Wide, 8 for NoBall, 9 for OUT"<<endl;
				cin>>runs;
				if (runs==0){
					system("CLS");
					baller->BallsThrown+=1;
					BallsThrown2+=1;
					currentbatter->BallsPlayed+=1;
					Team2Dotballs+=1;
					balls++;
				}
				else if (runs==1){
					system("CLS");
					baller->BallsThrown+=1;
					baller->BallingRuns+=1;
					BallsThrown2+=1;
					Team2Runs+=1;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=1;
					Exchange();
					balls++;
				}
				else if (runs==2){
					system("CLS");
					baller->BallsThrown+=1;
					baller->BallingRuns+=2;
					BallsThrown2+=1;
					Team2Runs+=2;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=2;
					balls++;
				}
				else if (runs==3){
					system("CLS");
					baller->BallsThrown+=1;
					baller->BallingRuns+=3;
					BallsThrown2+=1;
					Team2Runs+=3;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=3;
					Exchange();
					balls++;
				}
				else if (runs==4){
					system("CLS");
					cout<<"*************A Beautiful Four*****************"<<endl;
					baller->BallsThrown+=1;
					baller->BallingRuns+=4;
					BallsThrown2+=1;
					Team2Runs+=4;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=4;
					currentbatter->fours+=1;
					Team2Fours+=1;
					balls++;
				}
				else if (runs==6){
					system("CLS");
					cout<<"************A Big Six***********"<<endl;
					baller->BallsThrown+=1;
					baller->BallingRuns+=6;
					BallsThrown2+=1;
					Team2Runs+=6;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=6;
					currentbatter->sixes+=1;
					Team2Sixes+=1;
					balls++;
				}
				else if (runs==7){
					system("CLS");
					cout<<"************Wide Ball***************"<<endl;
					baller->BallingRuns+=1;
					Team2Runs+=1;
					currentbatter->BattingRuns+=1;
					baller->wide+=1;
					Team2Wide+=1;
					ShowScore2();
				}
				else if (runs==8){
					system("CLS");
					int temp=0;
					cout<<"How many scores on NoBall: ";
					cin>>temp;
					baller->BallingRuns+=temp;
					Team2Runs+=temp;
					currentbatter->BattingRuns+=temp;
					baller->noballs+=1;
					Team2Noballs+=1;
					if (temp%2!=0){
						Exchange();
					}
					cout<<"********No Ball Free Hit*********"<<endl;
				}
				else if (runs==9){
					system("CLS");
					cout<<"*********OUT**********"<<endl;
					int temp=0;
					cout<<"How many runs gained before getting out on the Ball: ";
					cin>>temp;
					baller->BallsThrown+=1;
					baller->BallingRuns+=temp;
					baller->wickets+=1;
					BallsThrown2+=1;
					Team2Runs+=temp;
					Team2Wickets+=1;
					currentbatter->BallsPlayed+=1;
					currentbatter->BattingRuns+=temp;
					if(Team2Wickets<3){
						currentbatter=PT2[Team2Wickets+1];
						cout<<"Next Batter is "<<currentbatter->name<<endl;
					}
					else if (Team2Wickets==3){
						currentbatter=secondbatter;
					}
					if(temp%2!=0){
						Exchange();
					}
					balls++;
				}
				else {
					system("CLS");
					cout<<"Wrong Option Selected Try Again!!!!!!!!!!!!!"<<endl;
				}
				ShowScore2();
			}
			cout<<"***************Inings Ended******************"<<endl;
			cout<<"Press Enter to continue..........."<<endl;
			string cont;
			cin.ignore(100,'\n');
			getline(cin,cont);
		}
		void ShowStats1(){
			cout<<"***************Batting Stats of Team "<<getTeamName1()<<"******************"<<endl;
			cout<<"Player Name\tFours\tSixes\tBalls PLayed\tTotal Runs"<<endl;
			for (int i=0; i<4; i++){
				cout<<PT1[i]->name<<"\t\t"<<PT1[i]->fours<<"\t"<<PT1[i]->sixes<<"\t"<<PT1[i]->BallsPlayed<<"\t"<<PT1[i]->BattingRuns<<endl;
			}
			cout<<"Total Runs: "<<Team1Runs<<endl;
			cout<<"Wickets Down: "<<Team1Wickets<<endl;
			cout<<"Total Fours: "<<Team1Fours<<endl;
			cout<<"Total Sixes: "<<Team1Sixes<<endl<<endl;
			cout<<"***************Balling Stats of Team "<<getTeamName1()<<"******************"<<endl;
			cout<<"Player Name\tOvers\tWide\tNoBall\tWickets\tTotal Runs"<<endl;
			for (int i=0; i<4; i++){
				cout<<PT1[i]->name<<"\t\t"<<PT1[i]->overs<<"\t"<<PT1[i]->wide<<"\t"<<PT1[i]->noballs<<"\t"<<PT1[i]->wickets<<"\t"<<PT1[i]->BallingRuns<<endl;
			}
			cout<<"Total Dot Balls: "<<Team2Dotballs<<endl;
			cout<<"Total Wides: "<<Team2Wide<<endl;
			cout<<"Total No Balls: "<<Team2Noballs<<endl<<endl;
		}
		void ShowStats2(){
			cout<<"***************Batting Stats of Team "<<getTeamName2()<<"******************"<<endl;
			cout<<"Player Name\tFours\tSixes\tBalls PLayed\tTotal Runs"<<endl;
			for (int i=0; i<4; i++){
				cout<<PT2[i]->name<<"\t\t"<<PT2[i]->fours<<"\t"<<PT2[i]->sixes<<"\t"<<PT2[i]->BallsPlayed<<"\t"<<PT2[i]->BattingRuns<<endl;
			}
			cout<<"Total Score: "<<Team2Runs<<endl;
			cout<<"Wickets Down: "<<Team1Wickets<<endl;
			cout<<"Total Fours: "<<Team2Fours<<endl;
			cout<<"Total Sixes: "<<Team2Sixes<<endl<<endl;
			cout<<"***************Balling Stats of Team "<<getTeamName2()<<"******************"<<endl;
			cout<<"Player Name\tOvers\tWide\tNoBall\tWickets\tTotal Runs"<<endl;
			for (int i=0; i<4; i++){
				cout<<PT2[i]->name<<"\t\t"<<PT2[i]->overs<<"\t"<<PT2[i]->wide<<"\t"<<PT2[i]->noballs<<"\t"<<PT2[i]->wickets<<"\t"<<PT2[i]->BallingRuns<<endl;
			}
			cout<<"Total Dot Balls: "<<Team1Dotballs<<endl;
			cout<<"Total Wides: "<<Team1Wide<<endl;
			cout<<"Total No Balls: "<<Team1Noballs<<endl<<endl;
		}
		void Winner(){
			if (Team1Runs>Team2Runs)
			cout<<"**************Team "<<getTeamName1()<<" Winner******************"<<endl;
			else if (Team1Runs<Team2Runs)
			cout<<"**************Team "<<getTeamName2()<<" Winner******************"<<endl;
			else if (Team1Runs==Team2Runs)
			cout<<"*************Match is Draw*****************"<<endl;
		}
};

int main(){
	ScoreCard match;
	int dec;
	bool x;
	x=match.InputStartingData();
	match.InputPlayerNames();
	if (x==0){
		match.BattingTeam1();
		match.BattingTeam2();
	}
	else if (x==1){
		match.BattingTeam2();
		match.BattingTeam1();
	}
	while(1){
		system("CLS");
		cout<<"*****Select A Option*****"<<endl;
		cout<<"1.Show Team 1 Stats"<<endl<<"2.Show Team 2 Stats"<<endl<<"3.Show Winners Name"<<endl<<"4.Exit"<<endl;
		cin>>dec;
		if (dec==1)
		match.ShowStats1();
		else if(dec==2)
		match.ShowStats2();
		else  if (dec==3)
		match.Winner();
		else if (dec==4)
		break;
		else
		cout<<"Wrong Option Entered!!!!! Try Again"<<endl;
		cout<<"Press Enter to continue..........."<<endl;
		string cont;
		cin.ignore(100,'\n');
		getline(cin,cont);
	}
	return 0;
}
