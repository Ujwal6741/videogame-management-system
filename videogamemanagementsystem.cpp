#include<iostream>
#include<string>
using namespace std;

class game {
    int playerid, playerlevel, quests, choice;
    float kd, kills, deaths;
    string name;
    static int totalplayers;

public:
	//static functions
	game()
	{}
	static showtotalplayers()
	{
		cout<<"\nTotal players created:"<<totalplayers<<endl;
	}
	
	//friend function
    friend float kdd(game kdr);

    void input();
    void output();
    void greet(string name = "PLAYER");
    void buy(int x=1000,int y=1500,int z=500);
   // void kdcalc();
    void gamechoose();
};
int game::totalplayers=0;

class buyskins {
    int skinchoose;
public:
    void skins();
};
//friend fucntion
float kdd(game kdr) {
    if (kdr.deaths == 0)
        return 0;
    return kdr.kills/kdr.deaths;
}

 /*void game::kdcalc() {
    kd=kdd(*this);
    cout<<"\nK/D Ratio: "<<kd<<endl;

    if (kd == 0.00) {
        cout<<"Bad performance\n";
    } else if (kd >= 50.00) {
        cout<<"Outstanding performance\n";
    } else if (kd >= 15.00) {
        cout<<"Excellent performance\n";
    } else if (kd >= 10.00) {
        cout<<"Good performance\n";
    } else if (kd >= 5.00) {
        cout<<"Average performance\n";
    } else {
        cout<<"Need to improve\n";
    }
}*/

void game::gamechoose() {
    cout<<"\n====Enter the choice of your game====\n";
    cout<<"1 = Battle Royale\n2 = Festival\n3 = Rocket Racing\n";
    cin>>choice;
	
    switch (choice) {
        case 1: cout<<"Game chosen is Battle Royale\n"; break;
        case 2: cout<<"Game chosen is Festival\n"; break;
        case 3: cout<<"Game chosen is Rocket Racing\n"; break;
        default: cout<<"Invalid option\n"; break;
	}
}

void buyskins::skins() {
    cout<<"\n====Enter the skin you want to wear====\n";
    cout<<"1. Ruby\n2. Lady Gaga\n3. Kit\n";
    cin>>skinchoose;
    switch (skinchoose) {
        case 1: cout<<"Skin chosen is Ruby\n"; break;
        case 2: cout<<"Skin chosen is Lady Gaga\n"; break;
        case 3: cout<<"Skin chosen is Kit\n"; break;
        default: cout<<"Invalid skin\n"; break;
    }
}

void game::input() {
    cout<<"\nEnter the player ID:";
    cin>>playerid;
    cout<<"Enter player name:";
    cin>>name;
    gamechoose();
    cout<<"Enter the number of quests completed:";
    cin>>quests;
    playerlevel=quests*5;
    totalplayers++;

}

void game::output() {
    cout<<"\nPlayer ID: "<<playerid<<endl;
    cout<<"Player  name:"<<name<<endl;
    cout<<"Quests completed: "<<quests<<endl;
    cout<<"Player level: "<< playerlevel<<endl;
}

void game::greet(string name) {
    cout<<"\n=== WELCOME " << name << "! ===\n";
}

void game::buy(int x, int y, int z) {
    int choice1;
    cout<<"\n===Enter the skin to buy===\n";
    cout<<"1. Renegade Raider\n2. Lady Gaga\n3. Sabrina Carpenter\n";
    cin>>choice1;

    switch (choice1) {
        case 1: cout<<"Skin bought is Renegade Raider = "<< x <<" V-Bucks\n"; break;
        case 2: cout<<"Skin bought is Lady Gaga = "<< y <<" V-Bucks\n"; break;
        case 3: cout<<"Skin bought is Sabrina Carpenter = "<<z<<" V-Bucks\n"; break;
        default: cout<<"Invalid option\n"; break;
    }
}
//constructors prog4
class playerstats {
    int kills, deaths;
public:
    playerstats() {
        kills = 0;
        deaths = 0;
    }
    playerstats(int k, int d) {
        kills = k;
        deaths = d;
    }
    playerstats(const playerstats &p) {
        kills = p.kills;
        deaths = p.deaths;
    }
    void display() {
        if (deaths == 0)
            cout << "KD cannot be calculated (no deaths yet)\n";
        else {
            cout<<"The player kills="<<kills;
            cout<<"\nThe player deaths="<<deaths;
            cout<<"\nThe player KD="<<(float)kills/deaths<<"\n";
        }
    }
};
//function overloading prog6
class match
{
	public: 
	void rank(int kills)
	{
		cout<<"kills="<<kills;
		if(kills>=25)
			cout<<"unreal rank\n";
		else if(kills>=20)
			cout<<"champion rank\n";
		else if(kills>=15)
			cout<<"elite rank\n";
		else if(kills>=10)
			cout<<"diamond rank\n";
		else if(kills>=5)
			cout<<"gold rank\n";			
	}
	void rank(float kills)
	{
		cout<<"kills="<<kills;
		if (kills>=25.0)
			cout<<"unreal rank\n";
		else if(kills>=20.0)
			cout<<"champion rank\n";
		else if(kills>=15.0)
			cout<<"elite rank\n";
		else if(kills>=10.0)
			cout<<"diamond rank\n";
		else if(kills>=5.0)
			cout<<"gold rank\n";;				
	}
};
//unary operator overloading prog7
class players 
{
    int player;
public:
    players() 
	{
        player=0;
    }

    players(int x)
	{
        player=x;
    }

    void input()
	{
        cout<<"enter the current players that are in a match:\n";
        cin>>player;
    }

    void operator++()
	{
        player++;
    }

    void operator--() 
	{
        if(player>0)
            player--;
    }

    void output()
	 {
        cout<<"player count:\n"<<player<<endl;
    }
};
//binary operator overloading porg8

class VideoGame {
    string title;
    float price;

public:
    VideoGame() {
        title = "Unknown";
        price = 0.0;
    }

    VideoGame(string t, float p) {
        title =t;
        price=p;
    }

    void display() {
        cout<<"game: "<<title<<"Price: Rs"<<price<<endl;
    }

    VideoGame operator+(VideoGame &vg) {
        VideoGame temp;
        temp.title=title + " & " + vg.title;
        temp.price=price + vg.price;
        return temp;
    }
};


//multiple inheritance prog9
class fortniteplayer:public game,public buyskins
{
	public: void showall()
	{
		cout<<"\n==fortnite player info==\n";
		skins();
		output();
			
	}
};
//multilevel inheritance prog10
	class character:public game
	{
		protected: string type;
		public:
			void choosechar()
			{
				input();
				cout<<"\nchoose your character(mage/warrior/zyborg)";
				cin>>type;
			}
			void showchar()
			{
				output();
				cout<<"character chosen is"<<type<<endl;
			}
	};
	class power:public character
	{
		public:
		void showpower()
		{
			cout<<"\nspecial power\n";
			if(type=="mage")
			cout<<"healing spell\n";
			else if(type=="warrior")
			cout<<"double attack strength\n";
			else if(type=="zyborg")
			cout<<"regeneration\n";
			else
			cout<<"no super power";
			}	
	};


int main() {
    game g[10];
    buyskins bs; 
    int n,ch,i;
    int k, d;
    playerstats ppp[100];
    match m[100];
    VideoGame g1("Fortnite", 20.0);
    VideoGame g2("Save the world", 30.50);

    players p;
    fortniteplayer f;
    power po[10];

    cout<<"How many players do you want to enter: ";
    cin>>n;

    for (int i=0;i<n;i++) {
        cout<<"\nWelcome player "<<i+1<<":\n";
        g[i].greet();
    }

    do {
        cout<<"\n=== Fortnite Game Management Menu ===\n";
        cout<<"1.Enter Player Details\n";
        cout<<"2.Skins Available\n";
        cout<<"3.Show Player Info\n";
        cout<<"4.Show K/D Ratio and Performance\n";
        cout<<"5.ranks\n";
        cout<<"6.players count\n";
        cout<<"7.buy games\n";
        cout<<"8.fortnite player info\n";
        cout<<"9.powers\n";
        cout<<"10.total players\n";
        cout<<"11.exit\n";
        cout<<"Enter your choice:";
        cin>>ch;

        switch (ch) {
            case 1:
                for(i=0;i<n;i++) 
				{
                    cout<<"\n--- Entering details for Player "<<i+1<<" ---\n";
                    g[i].input();
                }
                break;

            case 2:
            	for(i=0;i<n;i++) 
				{
            		cout<<"\n--- Skins Available for Player "<<i+1<<" ---\n";
            		bs.skins();
            	}
            	break;
				
            case 3:
                for (i=0;i<n;i++) 
				{
                    cout<<"\n--- Player "<<i+1<<" Info ---\n";
                    g[i].output();
                }
                break;

            case 4: 
			{
                for (i=0;i<n;i++) 
				{
                    cout<<"\nEnter the kills of player"<<i+1<<":";
                    cin>>k;
                    cout<<"Enter the deaths of player"<<i+1<<":";
                    cin>>d;
                    ppp[i]=playerstats(k, d); 
                }

                cout<<"\n--- Player Stats ---\n";
                for (i=0;i<n;i++) 
				{
                    cout<<"\nPlayer"<<i+1<<":\n";
                    ppp[i].display();
                }
                break;   
            }
//prog 6
            case 5:
			{
			for(i=0;i<n;i++)
			{
                cout<<"Ranks\n";
                m[i].rank(20);
                m[i].rank(20.5f);
            }
        	}
                break;
//porg 7
            case 6: 
            {
            
            	{
            	cout<<"match player count\n";
					    p.input();
    					++p;
    					p.output();
   						--p;
    					p.output();
    		}
		}
		break; 
//prog 8   
			
			case 7:
				{
				cout<<"Game 1 details:"<<endl;
    			g1.display();
    			cout<<"Game 2 details:"<<endl;
   				g2.display();	
    			VideoGame combo=g1+g2;
    			cout<<"\nCombined Game Pack details"<<endl;
    			combo.display();	
				}
				break;

//porg9
            case 8:
			{
            	cout<<"==player info==\n";
            	f.input();
            	f.skins();
            	f.showall();
            }
				break;
			case 9:
			{
				cout<<"==powers==\n";
				for(i=0;i<n;i++)
				{
				po[i].choosechar();
				po[i].showchar();
				po[i].showpower();
				}	
			}
				break;

//porg10
			case  10:
				{
    				game::showtotalplayers();
				}
				break;
				
				case 11:
   						{
   							cout<<"exiting\n";
						   }
    break;
				
            default:
                cout<<"Invalid option\n";
        }

    } while(ch!=11);
    return 0;
}

