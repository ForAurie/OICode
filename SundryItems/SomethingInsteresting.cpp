#include<bits/stdc++.h>
#include<Windows.h>
#define n(x) rand()%(x)
#define p(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

using namespace std;
void hideCursor() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
}
void fun(int x, int y) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = y;
    coord.Y = x;
    SetConsoleCursorPosition(hConsoleOutput, coord);
}
string s123[10000005];
string s1234[1005][10005];
int d=0,d1=1,d2=0,shu=0,jin=0;
int xy=-1;
int main(){
	hideCursor();
	for(;;){
		
	 
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"  -------      -------      -------      -------          \n";
		cout<<"  |   ◆ |      | / <-|      |  A  |      |  |  |         \n";
		cout<<"  |  ●  |      |/    |      |  B  |      | /   |         \n";
		cout<<"  -------      -------      -------      -------          \n";
		cout<<"A.超级贪吃蛇  B.战斗游戏  C.打字游戏    D.计时器    \n\n\n\n";
		cout<<"  -------      -------      -------      -------          \n";
		cout<<"  | 一只|      |XXXXX|      |  ^  |      |#1###|          \n";
		cout<<"  |  鸡 |      |  ^  |      |  |  |      |#####|          \n";
		cout<<"  -------      -------      -------      -------          \n";
		cout<<"E.小鸡游戏    F.射击游戏   G.跳力游戏     H.扫雷    \n\n\n\n";
		cout<<"  -------      -------      -------      -------          \n";
		cout<<"  |百度 |      |浏览 |      |[   ]|      |  -  |          \n";
		cout<<"  | 搜索|      |   器|      |     |      |  o  |          \n";
		cout<<"  -------      -------      -------      -------          \n";
		cout<<"I.百度一下    J.浏览器    K.打人游戏  L.乒乓球游戏\n\n\n\n";
		cout<<"------------------------------------------------          \n";
		cout<<"| -|-         up系统                           |			 \n";
		cout<<"------------------------------------------------			 \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout<<"                              按T开启           			 \n";
		cout<<"                                                			 \n";
		cout<<"                               AI助手           			 \n";
		cout<<"                              \\   /            			 \n";
		cout<<"                               \\ /             			 \n";
		cout<<"                             --------   ( X )   			 \n";
		cout<<"                             | ^  ^ |  -------  			 \n";
		cout<<"                             |@ -- @|  |文件@|  			 \n";
		cout<<"                             --------  -------  			 \n";
		cout<<"                             /| AI |----------  			 \n";
		cout<<"                            / |    |            			 \n";
		cout<<"                           /  ------            			 \n";
		cout<<"                             / /  \\ \\         			 \n";
		cout<<"                            / /    \\ \\        			 \n";
		cout<<"                           ---      ---         			 \n";
		while(!(  p('A') || p('B') || p('C') || p('D') || p('E') || p('F') || p('G') || p('H') || p(' ') || p('I') || p('U') || p('J') || p('K') || p('L') || p('X') || p('T') || p(VK_UP))){
			
		}
		if(!(p('T') && p(' '))){
			jin+=3;
		}
		
		
		
		
		
		if(p(VK_UP)){
			system("cls");
			cout<<"                                                                                                     \n";
			cout<<"   ----------                                                                                        \n";
			cout<<"  / A. 银行  \\                                                                                      \n";
			cout<<"  | $      $ |                                                                                       \n";
			cout<<"  |  |--|    |                                                                                       \n";
			cout<<"  |  |  |    |                                                                                       \n";
			cout<<"  ------------  ==========                                                                           \n";
			cout<<"                        ||                                                                           \n";
			cout<<"                        ||                                                                           \n";
			cout<<"                        ====        \\ /                                                             \n";
			cout<<"                                     |                                                               \n";
			cout<<"                            ------------------                                                       \n";
			cout<<"                             B. 植物园                                                               \n";
			cout<<"                             //                                                                      \n";
			cout<<"                            //                                                                       \n";
			cout<<"                           //                                                                        \n";
			cout<<"               ------------                   D.查看学院（荐）                                       \n";
			cout<<"               |   Super  |                   -----------                                            \n";
			cout<<"               |    ZOO   |                        ||                                                \n";
			cout<<"               |          |                        ||                                                \n";
			cout<<"               ------------ ========================                                                 \n";
			cout<<"                 C.动物园                          //                                                \n";
			cout<<"                                                  //                                                 \n";
			cout<<"                                                 //                                                  \n";
			cout<<"                                             --------                                                \n";
			cout<<"                                             |  ||| |                                                \n";
			cout<<"                                             |   |  |E.餐厅                                          \n";
			cout<<"                                             --------                                                \n";
			cout<<"                                             ||                                                      \n";
			cout<<"                                             ||                                                      \n";
			cout<<"                                             ||                                                      \n";
			cout<<"                                             //                                                      \n";
			cout<<"                                            //                                                       \n";
			cout<<"                 F.【抢金币！！！】 =======//                                                        \n";
			cout<<"          $$$$$$$$$$$（需要先花费30金币）                                                            \n";
			cout<<"                                                                                                     \n";
			cout<<"                                                                                                     \n";
			while(!(p('A') || p('B') || p('C') || p('C') || p('D') || p('E') || p('F') ||p('0'))){
				
			}
			system("cls");
			if(p('F') && jin>=30){
				bool f2=true;
				jin-=5;
				int a[20]={4,7,1,0,7,9,3,10,80,40,30,0,8,6,9,10,40,5,8,120};
				while(true){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					for(int i=0;i<20;i++){
						system("cls");
						Sleep(1);
						cout<<a[i]<<"金币";
						if(p(' ')){
							jin+=a[i];
							f2=false;
							break;
						}
					}
					if(f2==false){
						break;
					}
				}
			}
			if(p('D')){
				system("cls");
				if(xy==-1){
					cout<<"您还没有分院，请按空格键分院……\n"; 
					while(!p(' ')){
						
					}
					SYSTEMTIME time;
					GetLocalTime(&time);
					int k=time.wSecond;
					Sleep(1000);
					if(k<=10){
						cout<<"                -----                     \n";
						cout<<"                //  |                     \n";
						cout<<"  ------------ ------ ------------        \n";
						cout<<"  \\        \\     \\_/   /        /      \n";
						cout<<"   \\        |   /  \\   |       /        \n";
						cout<<"    --------\\   \\||/   /-------         \n";
						cout<<"             \\   []   /                  \n";
						cout<<"             /        \\                  \n";
						cout<<"            /----------\\                 \n";
						cout<<"            格斯加斯！！！                \n";
						cout<<"            < Gushgash >                  \n";
						xy=1;
					}else if(k<=25){
						cout<<"        -----------------             \n";
						cout<<"        |       |       |             \n";
						cout<<"        | <|>   |   <|> |             \n";
						cout<<"        |       |       |             \n";
						cout<<"        |---------------|             \n";
						cout<<"         \\      |      /              \n";
						cout<<"          \\ <>  |  <> /               \n";
						cout<<"           \\    |    /                \n";
						cout<<"            \\-------/                 \n";
						cout<<"            赫文拉克！！！            \n";
						cout<<"         < Hewanllakle >              \n";
						xy=2;
					}else if(k<=30){
						cout<<"             -------                    \n";
						cout<<"            /       \\                   \n";
						cout<<"           /   \\ /   \\                  \n";
						cout<<"          -   --★--  -                 \n";
						cout<<"           \\   / \\   /                  \n";
						cout<<"            \\       /                   \n";
						cout<<"             -------                    \n";
						cout<<"             |     |                    \n";
						cout<<"             -------                    \n";
						cout<<"          文劳莱克！！！                \n";
						cout<<"         < Wanlouliker >                \n";
						xy=3;
					}else{
						cout<<"                                       \n";
						cout<<"        --------------               \n";
						cout<<"        \\  \\ / o     /               \n";
						cout<<"         \\  O  |    /                \n";
						cout<<"          \\/|--|   /                 \n";
						cout<<"           \\|  |  /                  \n";
						cout<<"            \\  | /                   \n";
						cout<<"             \\ |/                    \n";
						cout<<"              \\/                     \n";
						cout<<"        斯芬克特！！！               \n";
						cout<<"       < Shfankter >                 \n";
						xy=4;
					}
					
					while(!p('0')){
						
					}
				}
				
				
				
				
				
				
				
				
				else{
					if(xy==1){
						cout<<"1.战斗游戏时，可以一开始就增加50金币！\n";
						cout<<"2.玩超级贪吃蛇的时候，已吃食物数量+9！\n";
						while(!p('0')){
							
						}
					}else if(xy==2){
						cout<<"1.玩打人游戏时，不会被别人攻击！\n";
						cout<<"2.玩跳力游戏时，被攻击时会减少一些伤害！\n";
						while(!p('0')){
							
						}
					}else if(xy==3){
						cout<<"1.抢金币时，只需先付20金币！\n" ;
					}
				}
			}
			if(p('A')){
				cout<<"       -----------------         \n";
				cout<<"      /  $     $     $  \\        \n";
				cout<<"     / ----------------- \\       \n";
				cout<<"     |                   |       \n";
				cout<<"     |                   |       \n";
				cout<<"     |                   |       \n";
				cout<<"  ---------------------------    \n";
				cout<<"  |                         |    \n";
				cout<<"  |        "<<setw(5)<<jin<<"            |    \n";
				cout<<"  |          金币           |    \n";
				cout<<"  |                         |    \n";
				cout<<"  ---------------------------    \n";
				while(!p('0')){
					
				}
			}
			
			if(p('B')){
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				if(shu==0){
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=30){
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                        \\ /                          \n";
					cout<<"                         |                            \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=90){
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                        ---                           \n";
					cout<<"                       /   \\                          \n";
					cout<<"                       |   |                          \n";
					cout<<"                       |   |                          \n";
					cout<<"                       --|--                          \n";
					cout<<"                         |                            \n";
					cout<<"                         |                            \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=150){
					cout<<"                 -----------------                    \n";
					cout<<"                /   ●        ●  \\                  \n";
					cout<<"               /           ●      \\                 \n";
					cout<<"              /   ●           ●   \\                \n";
					cout<<"              \\        ●           /                \n";
					cout<<"               \\   ●        ●    /                 \n";
					cout<<"                \\      |   |      /                  \n";
					cout<<"                 ------|   |------                    \n";
					cout<<"                       ||  |                          \n";
					cout<<"                       |  ||                          \n";
					cout<<"                       |   |                          \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=250){
					cout<<"              --------------------                    \n";
					cout<<"             /   ●     ●       /                    \n";
					cout<<"            /      ●       ●   \\                    \n";
					cout<<"            \\  ●     ●          \\                   \n";
					cout<<"            /           ●    ●   \\                  \n";
					cout<<"           /      ●              -                  \n";
					cout<<"           \\           ●   ●    /                   \n";
					cout<<"            \\  ●                 \\                   \n";
					cout<<"            /       |       |  ●  \\                  \n";
					cout<<"            --------|   |   |--------                 \n";
					cout<<"                    ||  |   |                         \n";
					cout<<"                    ||      |                         \n";
					cout<<"                    |       |                         \n";
					cout<<"                    |      ||                         \n";
					cout<<"                    ||     ||                         \n";
					cout<<"                    ||      |                         \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}
				cout<<"按空格键浇水（10金币）或按0键退出";
				while(!p('0')) {
					if(p(' ') && jin>=10){
						shu+=5;
						jin-=10;
						cout<<"水量+5";
						Sleep(100);
					}
				}
			}
			
			
			
			if(p('C')){
				while(!p('0')){
					system("cls");
					cout<<"1.兔子  2.狮子  3.卡皮巴拉  4.小猫\n";
					while(!(p('1') || p('2') || p('4') || p('0') || p('3'))){
						
					}
					system("cls");
					if(p('0')){
						break;
					}
					if(p('1')){
						cout<<"      ---     ---                \n";
						cout<<"      | |     | |                \n";
						cout<<"      | |     | |                \n";
						cout<<"      | |     | |                \n";
						cout<<"     -------------               \n";
						cout<<"     |           |               \n";
						cout<<"     |   ●   ●   |               \n";
						cout<<"     |     \\/    |               \n";
						cout<<"     -------------               \n";
						cout<<"       /|  ★   |\\                \n";
						cout<<"        |-----|                  \n";
						cout<<"     ----     ----               \n";
						Sleep(100);
					}
					if(p('2')){
						cout<<"                                          \n";
						cout<<"                                          \n";
						cout<<"                                          \n";
						cout<<"          \\  \\  |  /  /                   \n";
						cout<<"         \\  --------- /                   \n";
						cout<<"        \\   | ●  ●  |  /                  \n";
						cout<<"       --   | ----- |  --                 \n";
						cout<<"         /  | |   | |  \\                  \n";
						cout<<"      |  /  --------- \\   |               \n";
						cout<<"      |   /  /  |  \\  \\   |               \n";
						cout<<"      -------|     |-------               \n";
						cout<<"             |-----|                      \n";
						cout<<"            / /  \\ \\                      \n";
						cout<<"           / /    \\ \\                     \n";
						cout<<"          / /      \\ \\                    \n";
					}
					if(p('3')){
						cout<<"             _                            \n";
						cout<<"            / \\                           \n";
						cout<<"          /----------\\                    \n";
						cout<<"         / \\  ●       \\                   \n";
						cout<<"        |   |          \\                  \n";
						cout<<"         \\ /            \\                 \n";
						cout<<"          \\---------    |                 \n";
						cout<<"          //       |    |                 \n";
						cout<<"         //\\    --------|                 \n";
						cout<<"         ---\\---|       |                 \n";
						cout<<"         |      ---------                 \n";
						cout<<"         -------|                         \n";
						cout<<"                                          \n";
						cout<<"                                          \n";
						cout<<"                                          \n";
						cout<<"                                          \n";
						
					}
					
					if(p('4')){
						cout<<"                                        \n";
						cout<<"                                        \n";
						cout<<"                                        \n";
						cout<<"         /\\           /\\                \n";
						cout<<"        /  \\         /  \\               \n";
						cout<<"      --------------------              \n";
						cout<<"      |      ^    ^      |              \n";
						cout<<"      |      ●   ●       |              \n";
						cout<<"      |                  |              \n";
						cout<<"      | @      \\/     @  |              \n";
						cout<<"      |                  |              \n";
						cout<<"      --------------------              \n";
						cout<<"|          |       |========            \n";
						cout<<"|          |   ★   |                    \n";
						cout<<"|          |       |                    \n";
						cout<<"---------- ---------                    \n";
						cout<<"           /       \\                    \n";
						cout<<"          /         \\                   \n";
						cout<<"         /           \\                  \n";
						
					}
					cout<<"按1键返回";
					while(!p('1')){
						
					}
					Sleep(1000);
				}
			}
			
			
		}
		
		
		
		
		
		
		if(p('T')){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout<<"                               AI助手           			 \n";
			cout<<"  -----------------------     \\   /            			 \n";
			cout<<"  |                     |      \\ /             			 \n";
			cout<<"  |    请问我有什么     |    -------- A.时间      		 \n";
			cout<<"  |                      >   | ^  ^ | B.和我玩  			 \n";
			cout<<"  |  可以帮到你的吗？   |    |@ -- @| C.查找文件			 \n";
			cout<<"  |                     |    -------- D.退出    			 \n";
			cout<<"  -----------------------    /| AI |-------------		 \n";
			cout<<"                            / |    |            			 \n";
			cout<<"                           /  ------            			 \n";
			cout<<"                             / /  \\ \\         			 \n";
			cout<<"                            / /    \\ \\        			 \n";
			cout<<"                           ---      ---         			 \n";
			while(!(p('A') || p('B') || p('C') || p('D'))) {
			
		}
		if(p('A')){
			while(!p('0')){
				system("cls");
				SYSTEMTIME time;
				GetLocalTime(&time);
				cout<<time.wYear<<"年"<<time.wMonth<<"月"<<time.wDay<<"日"<<time.wHour<<":"<<time.wMinute<<":"<<time.wSecond; 
			}
		}if(p('C')){
			string s;
			cin>>s;
			for(int i=1;i<=d1;i++){
				if(s123[i].find(s)!=string::npos){
					cout<<"第"<<i<<"个\n" ; 
				}
			}
		}if(p('B')){
			system("cls");
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout<<"                              \\   /            			 \n";
			cout<<"                               \\ /             			 \n";
			cout<<"                             --------   		   			 \n";
			cout<<"                             | -  - |  		  			 \n";
			cout<<"                             |@ -- @|  		  			 \n";
			cout<<"                             -------- 		  			 \n";
			cout<<"                             /| AI |\\  			 		 \n";
			cout<<"                            / |    | \\          		 \n";
			cout<<"                           /  ------  \\          		 \n";
			cout<<"                             / /  \\ \\         			 \n";
			cout<<"                            / /    \\ \\        			 \n";
			cout<<"                           ---      ---         			 \n";
			cout<<"A.呼我大嘴巴子  B.摸我的头  C.部件分离  D.做表情  E.种树 \n";
			while(!(p('A') || p('B') || p('C') || p('D') || p('E'))){
				
			}
			if(p('E')) {
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				if(shu==0){
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=30){
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                        \\ /                          \n";
					cout<<"                         |                            \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=90){
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                                                      \n";
					cout<<"                        ---                           \n";
					cout<<"                       /   \\                          \n";
					cout<<"                       |   |                          \n";
					cout<<"                       |   |                          \n";
					cout<<"                       --|--                          \n";
					cout<<"                         |                            \n";
					cout<<"                         |                            \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=150){
					cout<<"                 -----------------                    \n";
					cout<<"                /   ●        ●  \\                  \n";
					cout<<"               /           ●      \\                 \n";
					cout<<"              /   ●           ●   \\                \n";
					cout<<"              \\        ●           /                \n";
					cout<<"               \\   ●        ●    /                 \n";
					cout<<"                \\      |   |      /                  \n";
					cout<<"                 ------|   |------                    \n";
					cout<<"                       ||  |                          \n";
					cout<<"                       |  ||                          \n";
					cout<<"                       |   |                          \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}else if(shu<=250){
					cout<<"              --------------------                    \n";
					cout<<"             /   ●     ●       /                    \n";
					cout<<"            /      ●       ●   \\                    \n";
					cout<<"            \\  ●     ●          \\                   \n";
					cout<<"            /           ●    ●   \\                  \n";
					cout<<"           /      ●              -                  \n";
					cout<<"           \\           ●   ●    /                   \n";
					cout<<"            \\  ●                 \\                   \n";
					cout<<"            /       |       |  ●  \\                  \n";
					cout<<"            --------|   |   |--------                 \n";
					cout<<"                    ||  |   |                         \n";
					cout<<"                    ||      |                         \n";
					cout<<"                    |       |                         \n";
					cout<<"                    |      ||                         \n";
					cout<<"                    ||     ||                         \n";
					cout<<"                    ||      |                         \n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout<<"------------------------------------------------------"<<shu<<"\n";
				}
				cout<<"按空格键浇水（10金币）或按0键退出";
				while(!p('0')) {
					if(p(' ') && jin>=10){
						shu+=5;
						jin-=10;
						cout<<"水量+5";
						Sleep(100);
					}
				}
			}
			if(p('A')){
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                               ----   		   			 \n";
				cout<<"                              |O  |  啊！	  			 \n";
				cout<<"                              |- @| 		  				 \n";
				cout<<"                               ----  		  			 \n";
				cout<<"                             /| AI |\\  					 \n";
				cout<<"                            / |    | \\         			 \n";
				cout<<"                           /  ------  \\        			 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(1000);
			}if(p('B')){
				system("cls");
				cout<<"                              	   ||        			 \n";
				cout<<"                             =========          			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | -  - |  好舒服！ 			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(1000);
			}if(p('C')){
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n\n\n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | -  - |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n\n\n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                           /  | AI |  \\  			 		 \n";
				cout<<"                          /   |    |   \\          		 \n";
				cout<<"                         /    ------    \\          		 \n\n\n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(1000);
			}if(p('D')){
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | ^  ^ |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  - |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  < |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | O  O |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | O  < |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  - |  		  			 \n";
				cout<<"                             |@ -- @| / 		  			 \n";
				cout<<"                             --------/ 		  			 \n";
				cout<<"                             /| AI |/ 			 		 \n";
				cout<<"                            / |    |             		 \n";
				cout<<"                           /  ------             		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  < |  		  			 \n";
				cout<<"                             |@  ^ @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                            \\ ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  < |  		  			 \n";
				cout<<"                           \\ |@ -- @| /		  			 \n";
				cout<<"                            \\--------/ 		  			 \n";
				cout<<"                             \\| AI |/  			 		 \n";
				cout<<"                              |    |             		 \n";
				cout<<"                              ------             		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | ^  ^ |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  - |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  < |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | O  O |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | O  < |  		  			 \n";
				cout<<"                             |@ -- @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                           /  ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  - |  		  			 \n";
				cout<<"                             |@ -- @| / 		  			 \n";
				cout<<"                             --------/ 		  			 \n";
				cout<<"                             /| AI |/ 			 		 \n";
				cout<<"                            / |    |             		 \n";
				cout<<"                           /  ------             		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  < |  		  			 \n";
				cout<<"                             |@  ^ @|  		  			 \n";
				cout<<"                             -------- 		  			 \n";
				cout<<"                             /| AI |\\  			 		 \n";
				cout<<"                            / |    | \\          		 \n";
				cout<<"                            \\ ------  \\          		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             | >  < |  		  			 \n";
				cout<<"                           \\ |@ -- @| /		  			 \n";
				cout<<"                            \\--------/ 		  			 \n";
				cout<<"                             \\| AI |/  			 		 \n";
				cout<<"                              |    |             		 \n";
				cout<<"                              ------             		 \n";
				cout<<"                             / /  \\ \\         			 \n";
				cout<<"                            / /    \\ \\        			 \n";
				cout<<"                           ---      ---         			 \n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                               \\   /           			 \n";
				cout<<"                                \\ /            			 \n";
				cout<<"                              --------   		   		 \n";
				cout<<"                              |    > | 冲啊！	  		 \n";
				cout<<"                              |   @ -|  		  			 \n";
				cout<<"                    -----------------------    			 \n";
				cout<<"          ----------|New-Space| 		        	 		 \n";
				cout<<"                    -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                                \\   /           		 \n";
				cout<<"                                 \\ /            		 \n";
				cout<<"                               --------   				 \n";
				cout<<"                               |    > | 冲啊！			 \n";
				cout<<"                               |   @ -|  				 \n";
				cout<<"                     -----------------------    	    	 \n";
				cout<<"           ----------|New-Space| 		         		 \n";
				cout<<"                     -----------          				 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                                 \\   /            			 \n";
				cout<<"                                  \\ /             			 \n";
				cout<<"                                --------   		   			 \n";
				cout<<"                                |    > | 冲啊！	  			 \n";
				cout<<"                                |   @ -|  		  			 \n";
				cout<<"                      -----------------------    			 \n";
				cout<<"            ----------|New-Space| 		        	 		 \n";
				cout<<"                      -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                                    \\   /           			 \n";
				cout<<"                                     \\ /            			 \n";
				cout<<"                                   --------   		   		 \n";
				cout<<"                                   |    > | 冲啊！	  		 \n";
				cout<<"                                   |   @ -|  		  			 \n";
				cout<<"                         -----------------------    			 \n";
				cout<<"               ----------|New-Space| 		        	 		 \n";
				cout<<"                         -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                               \\   /           			 \n";
				cout<<"                                \\ /            			 \n";
				cout<<"                              --------   		   		 \n";
				cout<<"                              |    > | 冲啊！	  		 \n";
				cout<<"                              |   @ -|  		  			 \n";
				cout<<"                    -----------------------    			 \n";
				cout<<"          ----------|New-Space| 		        	 		 \n";
				cout<<"                    -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                               \\   /           			 \n";
				cout<<"                                \\ /            			 \n";
				cout<<"                              --------   		   		 \n";
				cout<<"                              |    > | 冲啊！	  		 \n";
				cout<<"                              |   @ -|  		  			 \n";
				cout<<"                    -----------------------    			 \n";
				cout<<"          ----------|New-Space| 		        	 		 \n";
				cout<<"                    -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                               \\   /           			 \n";
				cout<<"                                \\ /            			 \n";
				cout<<"                              --------   		   		 \n";
				cout<<"                              |    > | 冲啊！	  		 \n";
				cout<<"                              |   @ -|  		  			 \n";
				cout<<"                    -----------------------    			 \n";
				cout<<"          ----------|New-Space| 		        	 		 \n";
				cout<<"                    -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                               \\   /           			 \n";
				cout<<"                                \\ /            			 \n";
				cout<<"                              --------   		   		 \n";
				cout<<"                              |    > | 冲啊！	  		 \n";
				cout<<"                              |   @ -|  		  			 \n";
				cout<<"                    -----------------------    			 \n";
				cout<<"          ----------|New-Space| 		        	 		 \n";
				cout<<"                    -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                              			 \n";
				cout<<"                                                          \n";
				cout<<"        |        |         |        		   |         	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                               \\   /           			 \n";
				cout<<"                                \\ /            			 \n";
				cout<<"                              --------   		   		 \n";
				cout<<"                              |    > | 冲啊！	  		 \n";
				cout<<"                              |   @ -|  		  			 \n";
				cout<<"                    -----------------------    			 \n";
				cout<<"          ----------|New-Space| 		        	 		 \n";
				cout<<"                    -----------          			     \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"       /      /      |    \\    /      |	    \\     /   	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
				system("cls");
				cout<<"                              \\   /            			 \n";
				cout<<"                               \\ /             			 \n";
				cout<<"                             --------   		   			 \n";
				cout<<"                             |    > | 冲啊！	  			 \n";
				cout<<"                             |   @ -|  		  			 \n";
				cout<<"                   -----------------------    			 \n";
				cout<<"         ----------|New-Space| 		        	 		 \n";
				cout<<"                   -----------          					 \n";
				cout<<"                                   		 				 \n";
				cout<<"                                      			 		 \n";
				cout<<"   /   |    /     /     |      \\   	\\    /     |     	 \n";
				cout<<"----------------------------------------------------------\n";
				Sleep(100);
			}
		}
		continue;
		}
		
		
		
		
	
		if(p('X')){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout<<"-------------------------------\n";
			for(int i=1;i<=d;i++){
				cout<<"|"<<i<<"."<<s123[i]<<"\n";
			}
			cout<<"-------------------------------\n";
			int c;
			cin>>c;
			for(int i=1;i<=d2;i++){
				cout<<s1234[c][i]<<"\n";
			}
			cout<<"\n请按0退出……\n";
			while(!p('0')){
				
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		if(p('L')){
			char a[105][105];
			bool f=true,n=true;
			int g1=0,g2=0;
	for(;;){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"| X |\n";
		if(n==false){
			break;
		}
		if(g1==9){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<" /---\\-----------------\n";
			cout<<"|  $  |选手A获胜！！！|\n";
			cout<<" \\---/-----------------\n";
			cout<<"请按o键退出游戏……\n";
			while(!p('O')){
				
			}
			break;
		}if(g2==9){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<" /---\\-----------------\n";
			cout<<"|  $  |选手B获胜！！！|\n";
			cout<<" \\---/-----------------\n";
			cout<<"请按B键退出游戏……\n";
			break;
		} 
		int b2[100]={1,1,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2,1,3,1,2},p=-1,b=1;
		
		
		
		hideCursor();
	for(int i=1;i<=30;i++){
		for(int j=1;j<=60;j++){
			a[i][j]=' ';
		}
	} 
	for(int i=1;i<=30;i++){
		a[i][1]='|';
		a[i][60]='|';
	}
	int x11=30,y11=30;
	int x12=30,y12=29;
	int x13=30,y13=31;
	
	int x21=1,y21=30;
	int x22=1,y22=29;
	int x23=1,y23=31;
	int xb=15,yb=30;
	a[x11][y11]='-';
	a[x12][y12]='-';
	a[x13][y13]='-';
	a[x21][y21]='-';
	a[x23][y23]='-';
	a[x22][y22]='-';
	a[xb][yb]='o';
	for(;;){
		
		if(xb==30){
			g1++;
			break;
		}if(xb==1){
			g2++;
			break;
		}
		
		a[xb][yb]='o';
		a[x11][y11]='-';
	a[x12][y12]='-';
	a[x13][y13]='-';
	a[x21][y21]='-';
	a[x23][y23]='-';
	a[x22][y22]='-';
		system("cls");
		
		for(int i=1;i<=30;i++){
			for(int j=1;j<=60;j++){
				if(!(i==x11 && j==y11 || i==x12 && j==y12 || i==xb && j==yb || a[i][j]=='|' || i==x13 && j==y13  || i==x21 && j==y21 || i==x22 && j==y22 || i==x23 && j==y23)){
					a[i][j]=' ';
				}
				if(a[i][j]=='-'){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				} else if(a[i][j]=='|'){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				}else if(a[i][j]=='o'){
					printf("\033[38;5;166mo\033[0m");
					continue;
				}
				cout<<a[i][j];
			}
			cout<<"\n";
		}
		cout<<"\n\n";
		cout<<"-----------------\n";
		cout<<"|       |       |\n";
		cout<<"|   "<<g1<<"   |   "<<g2<<"   |\n";
		cout<<"|       |       |\n";
		cout<<"-----------------\n";
		cout<<"| 选手A | 选手B |\n";
		cout<<"-----------------\n";
		if(a[xb+1][yb]=='-'){
				f=false;
				p++;
				b=b2[p];
		}
		if(a[xb-1][yb]=='-'){
				f=true;
				p++;
				b=b2[p];
			}
		if(f==true){
			if(a[xb+1][yb]=='-'){
				f=false;
				p++;
				b=b2[p];
				continue;
			}
			if(b==1){
				swap(a[xb][yb],a[xb+2][yb]);
				xb++;
			}
			
			
			if(b==2){
				swap(a[xb][yb],a[xb+2][yb-2]);
				xb++,yb--;
			}
			
			
			if(b==3){
				swap(a[xb][yb],a[xb+2][yb+2]);
				xb++,yb++;
			}
			
		}
			
		
		
		
		
		
		
		
		
		
		//
		if(f==false){
			if(a[xb-1][yb]=='-'){
				f=true;
				p++;
				b=b2[p];
				continue;
			}
			if(b==1){
				swap(a[xb][yb],a[xb+2][yb]);
				xb--;
			}
			
			
			if(b==2){
				swap(a[xb][yb],a[xb-2][yb-2]);
				xb--,yb--;
			}
			
			if(b==3){
				swap(a[xb][yb],a[xb-2][yb+2]);
				xb--,yb++;
			}
			
		}
		if(p('0')){
			n=false;
			break;
		}
		
		
		
		if(p(VK_RIGHT)){
				swap(a[x11][y11],a[x11][y11+1]);
				y11++;
				swap(a[x12][y12],a[x12][y12+1]);
				y12++;
				swap(a[x13][y13],a[x13][y13+1]);
				y13++;
			}if(p(VK_LEFT)){
				swap(a[x11][y11],a[x11][y11-1]);
				y11--;
				swap(a[x12][y12],a[x12][y12-1]);
				y12--;
				swap(a[x13][y13],a[x13][y13-1]);
				y13--;
				
			}if(p(VK_UP)){
				swap(a[x11][y11],a[x11-1][y11]);
				x11--;
				swap(a[x12][y12],a[x12-1][y12]);
				x12--;
				swap(a[x13][y13],a[x13-1][y13]);
				x13--;
				
			}if(p(VK_DOWN)){
				swap(a[x11][y11],a[x11+1][y11]);
				x11++;
				swap(a[x12][y12],a[x12+1][y12]);
				x12++;
				swap(a[x13][y13],a[x13+1][y13]);
				x13++;
				
			}
			
			
			
			if(p('D')){
				swap(a[x21][y21],a[x22][y21+1]);
				y21++;
				swap(a[x22][y22],a[x22][y22+1]);
				y22++;
				swap(a[x23][y23],a[x23][y23+1]);
				y23++;
				
			}if(p('A')){
				swap(a[x21][y21],a[x21][y21-2]);
				y21--;
				swap(a[x22][y22],a[x22][y22-2]);
				y22--;
				swap(a[x23][y23],a[x23][y23-2]);
				y23--;
				
			}if(p('W')){
				swap(a[x21][y21],a[x21-2][y21]);
				x21--;
				swap(a[x22][y22],a[x22-2][y22]);
				x22--;
				swap(a[x23][y23],a[x23-2][y23]);
				x23--;
			}if(p('S')){
				swap(a[x21][y21],a[x21+1][y21]);
				x21++;
				swap(a[x22][y22],a[x22+1][y22]);
				x22++;
				swap(a[x23][y23],a[x23+1][y23]);
				x23++;
			}
	}
	} 
		}
		if(p('K')){
			system("cls");
			int a=1,o=0,v=0,y=0,x=10,x2=200;
	hideCursor();
	string s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout<<"       *****\n";
	Sleep(2);
	cout<<"        *****\n";
	Sleep(2);
	cout<<"         *****\n";
	Sleep(2);
	cout<<"          *****\n";
	Sleep(2);
	cout<<"           *****\n";
	Sleep(2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout<<"************\n";
	Sleep(2);
	cout<<"************\n";
	Sleep(2);
	cout<<"************\n";
	Sleep(2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<<" Game-Box\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"请输入密码：";
	while(true){
		cin>>s;
		if(s=="lql123"){
			cout<<"开始！！！";
			Sleep(70);
			break; 
		}else{
			cout<<"请重新输入……";
		}
	}
	
	
	for(int k=1;x2>0;k++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
		o++;
		if(o==5 && a!=4){
			a=1;
			Sleep(50);
			o=0; 
		}
		y++;
		if(y==15){
			a=1;
			Sleep(50);
			y=0;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
		system("cls");
		cout<<"蓄力值：[";                        
		for(int i=1;i<=v;i++){
			cout<<"■";
		} 
		for(int i=1;i<=30-v;i++){
			cout<<" ";
		}
		cout<<"]          \n";
		cout<<"血量："<<x<<"      对方血量："<<x2<<"\n";
		if(x==0){
			cout<<"你死啦！！！\n";
			cout<<"请安空格键结束……";
			while(!p(' ')) {

			}
			break;
		} 
		cout<<"对手要发怒啦！！！";
		
		cout<<"\n";
		cout<<"___________________________________________________________________________________________\n";
		if(k%100==0){
			x--;
			cout<<" O···=]\n"; 
			cout<<"/|\\ /|\\\n";
			cout<<"/ \\ / \\\n";
			Sleep(1000);
			continue;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		if(a==1){
			cout<<" O   O\n"; 
			cout<<"/|\\ /|\\\n";
			cout<<"/ \\ / \\\n";
			if(p('J')){
				a=2;
				v++;
				o=0;
			}else if(p('K')){
				a=3;
				o=0;
				v++;
				x2-=2;
			}else if(p('Z') && v>=30){
				a=4;
				y=0;
				o=0;
				x2-=2;
			}
		}else if(a==2){
			
			cout<<" O    O\n"; 
			cout<<"/|\\  /|\\\n";
			cout<<"/ -- / \\\n";
			if(p('J')){
				a=2;
			}else if(p('K')){
				a=3;
			}else if(p('Z')){
				a=4;
			}
		}else if(a==3){
			cout<<" O    O\n"; 
			cout<<"/|-- /|\\\n";
			cout<<"/ \\  / \\\n";
			if(p('J')){
				a=2;
			}else if(p('K')){
				a=3;
			}else if(p('Z')){
				a=4;
			}
		}else{
			v=0;
			cout<<" O              O\n"; 
			cout<<" |==▄︻┻━┳一";
			if(p(' ')){
				cout<<"···";
				v+=3;
				x2-=10;
			}else{
				cout<<"   ";
			}
			cout<<"/|\\\n";
			cout<<"/ \\            / \\\n";
			if(p('J')){
				a=2;
			}else if(p('K')){
				a=3;
			}else if(p('Z')){
				a=4;
			}
		}
		if(x2<=0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			system("mode con cols=60 lines=37");
			cout<<"▇▇▇▇▇▇▇▇▇▇▇▇\n";
			cout<<"▇  你赢啦  ▇\n";
			cout<<"▇  ！！！  ▇\n";
			cout<<"▇▇▇▇▇▇▇▇▇▇▇▇\n";
			cout<<"请安0键结束……";
			while(!p('0')) {

			}
		}
	}
	
		}
		
		
		if(p('A')){
			system("cls");
			int a[25][55]={0};
	char r='y';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout<<"       *****\n";
	Sleep(2);
	cout<<"        *****\n";
	Sleep(2);
	cout<<"         *****\n";
	Sleep(2);
	cout<<"          *****\n";
	Sleep(2);
	cout<<"           *****\n";
	Sleep(2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout<<"************\n";
	Sleep(2);
	cout<<"************\n";
	Sleep(2);
	cout<<"************\n";
	Sleep(2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<<" Game-Box\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Sleep(5);

	//锟斤拷迎锟斤拷锟斤拷
	for(int i=1; i<=9; i++) {
		for(int j=1; j<=50; j++) {
			if(i==1 || j==1 || j==50) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				cout<<"▇";
				Sleep(1);
			} else {
				cout<<" ";
			}
		}
		cout<<"\n";
	}
	cout<<"▇                   请";
	Sleep(1);
	cout<<"输";
	Sleep(1);
	cout<<"入";
	Sleep(1);
	cout<<"密";
	Sleep(1);
	cout<<"码";
	Sleep(1);
	cout<<"：                 ▇\n";
	for(int i=11; i<=20; i++) {
		for(int j=1; j<=50; j++) {
			if(i==1 || j==1 || j==50 || i==20) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				cout<<"▇";
				Sleep(1);
			} else {
				cout<<" ";
			}
		}
		cout<<"\n";
	}
	string s1;
	cin>>s1;
	if(s1=="lql123") {
		cout<<"开始\n";
		Sleep(5);
	} else {
		break;
	}



	int s=0,sw=0,k,h;
	bool f=true;
	int x=10,y=25;
	for(int i=1; i<=20; i++) {
		for(int j=1; j<=50; j++) {
			a[i][j]=0;
		}
	}
	for(int i=1; i<=50; i++) {
		a[1][i]=1;
	}
	for(int i=1; i<=20; i++) {
		a[i][1]=1;
		a[i][50]=1;
	}
	for(int i=1; i<=50; i++) {
		a[20][i]=1;
	}
	a[x][y]=3;













	//开始 
	for(int o=1;; o++) {
		hideCursor();
		system("cls");
		if(p('0')){
			break;
		}
		
		
		
		
		
		
		
		if(sw*3==30) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			system("mode con cols=60 lines=37");
			cout<<"▇▇▇▇▇▇▇▇▇▇▇▇\n";
			cout<<"▇  你赢啦  ▇\n";
			cout<<"▇  ！！！  ▇\n";
			cout<<"▇▇▇▇▇▇▇▇▇▇▇▇\n";
			cout<<"请安空格键结束……";
			while(!p(' ')) {

			}
			break;
		}
		
		
		
		if(o==80) {
			break;
		}
		system("cls 10000");
		if(f==true) {
			o=1;
			srand(time(NULL));
			k=n(17);
			srand(time(NULL));
			h=n(47);
			a[k][h]=2;
			f=false;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"| X |\n";
		for(int i=1; i<=20; i++) {
			for(int j=1; j<=50; j++) {
				if(a[i][j]==0) {
					cout<<" ";
				} else if(a[i][j]==2) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					cout<<"●";
				} else if(a[i][j]==3) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					cout<<"◆";
				} else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout<<"▇";
				}
			}
			cout<<"\n";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"力量："<<sw*3<<"   已吃食物数量"<<sw<<"   暂停：空格键   移动：↑ ↓ ← →      \n剩余时间："<<80-o<<" （时间不多啦！！！）    位置：行："<<x<<"  列："<<y<<"\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"作者：李晴朗\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if(p(VK_UP)) {
			r='s';
			if(a[x-1][y]==2) {
				o=1;
				sw++;
				f=true;
				a[x][y]=0;
				a[--x][y]=3;
			} else if(a[x-1][y]==1) {
				cout<<"你死啦！！！";
				break;
			} else {
				a[x][y]=0;
				a[--x][y]=3;
			}
		}
		if(p(VK_DOWN)) {
			r='x';
			if(a[x+1][y]==2) {
				sw++;
				o=1;
				f=true;
				a[x][y]=0;
				a[++x][y]=3;
			} else if(a[x+1][y]==1) {
				cout<<"你死啦！！！";
				break;
			} else {
				a[x][y]=0;
				a[++x][y]=3;
			}
		}
		if(p(VK_LEFT)) {
			r='z';
			if(a[x][y-1]==2) {
				sw++;
				o=1;
				f=true;
				a[x][y]=0;
				a[x][--y]=3;
			} else if(a[x][y-1]==1) {
				cout<<"你死啦！！！";
				break;
			} else {
				a[x][y]=0;
				a[x][--y]=3;
			}
		}
		if(p(VK_RIGHT)) {
			r='y';
			if(a[x][y+1]==2) {
				sw++;
				o=1;
				f=true;
				a[x][y]=0;
				a[x][++y]=3;
			} else if(a[x][y+1]==1) {
				cout<<"你死啦！！！";
				break;
			} else {
				a[x][y]=0;
				a[x][++y]=3;
			}
		}
		if(p(' ')) {
			cout<<"游戏已暂停……\n请按B键继续：";
			for(;;) {
				if(p('B')) {
					break;
				}
			}
		}
		if(p('J')) {
			o=1;
			a[k][h]=0;
			srand(time(NULL));
			k=n(17);
			srand(time(NULL));
			h=n(47);
			a[k][h]=2;
			f=false;
		}
		if(p('K')){
			cout<<"姓名：李晴朗   密码：lql123 \n";
			Sleep(10000);
		}
	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('B')){
		
		system("cls");
			int s=50,t=0,a=1,y=0,h=0,b=1;
	int c=0;
	string s1;
	int v=30;
	getline(cin,s1);
	if(s1!="lql123") {
		return 0;
	}
	int r=0;
	bool f=true;
	for(;;) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"| X |\n";
		system("cls");
		if(p(VK_MBUTTON)) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<"Name: liqinglang     Age: 10\nGender: male     Password: xxxxxx\nLevel: Lv"<<a<<"Gold coin: "<<t<<"\n";
			string o;
			getline(cin,o);
			if(o=="123456") {
				cout<<"Password: lql123\n";
				cin>>o;
			}
		}

		h++;
		if(h<=3000) {
			b=1;
		} else if(h<=50000) {
			b=2;
		}else{
			b=1;
		}
		if(y==8) {
			a=1;
		}

		s--;
		if(s==0 && a!=6) {
			v--;
		}
		if(v==0) {
			a=1;
			y=0;
			t=0;
			s=50;
			v=50;
			b=1;
			cout<<"you are die!!!";
			for(int i=1; i<=10000000; i++) {
				a=1;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"$ <"<<t<<">      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"() <"<<v<<">";
		cout<<"\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout<<" /\\   \n/  \\     \n|  | \n----\n\n\n\n\n\n";







		if(a==1) {
			if(p('0')){
				break;
			}
			if(f==true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<" O  / ";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
			} else {
				f=true;
				s=50;
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==1) {
				cout<<"<**>\n";
			} else if(b==2) {
				cout<<"<--\n";
			} else if(b==3) {
				cout<<" () \n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/|\\/ ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			for(int i=1; i<=s; i++) {
				cout<<" ";
			}
			if(b==1) {
				cout<<" ^^^^\n";
			} else if(b==3) {
				cout<<"/|\\\n";
			} else if(b==2) {
				cout<<"\n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/ \\ \n\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==3) {
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
				cout<<"/ \\\n";
			} else if(b==2) {
				cout<<"\n";
			}
			if(p(VK_LBUTTON)) {
				if(s<=6 && b==1) {
					f=false;
					t+=10;
					cout<<"+10!!!";
				} else if(s<=6 && (b==2 || b==3)) {
					v--;
				}
			} else if(p(VK_RBUTTON)) {
				cout<<"A.  250$      B.  300$\nC.  400$      D.  1500$\nE.  1$       F.10000$\n";
				char n;
				cin>>n;
				if(n=='A' && t>=250) {
					y=90;
					a=2;
					t-=250;
				} else if(n=='B' && t>=300) {
					a=3;
					t-=300;
				} else if(n=='C' && t>=400) {
					a=4;
					t-=400;
				} else if(n=='D' && t>=1500) {
					a=5;
					y=90;
					t-=1500;
				} else if(n=='E' && t>=1) {
					a=1;
					t-=1;
				} else if(n=='F' && t>=10000) {
					a=6;
					t-=10000;
				}
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}






















		if(a==2) {
			if(p('0')){
			break;
		}
			if(y==0) {
				a=1;
			}
			if(f==true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<" O  == ";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
			} else {
				f=true;
				s=50;
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==1) {
				cout<<"<**>\n";
			} else if(b==2) {
				cout<<"<--\n\n";
			} else if(b==3) {
				cout<<" () \n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/|\\| ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			for(int i=1; i<=s; i++) {
				cout<<" ";
			}
			if(b==1) {
				cout<<" ^^^^\n";
			} else if(b==3) {
				cout<<"/|\\\n";
			} else if(b==2) {
				cout<<"\n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/ \\ \n\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==3) {
				cout<<"/ \\\n";
			} else if(b==2) {
				cout<<"\n";
			}
			if(p(VK_LBUTTON)) {
				if(s<=1000000000 && (b==2 || b==1)) {
					f=false;
					y--;
					t+=20;
					cout<<"+20!!!";
				} else if(s<=100000000000 && (b==3)) {
					v--;
				}
			}  else if(p(VK_RBUTTON)) {
				cout<<"A.  250$      B.  300$\nC.  400$      D.  1500$\nE.  1$       F.10000$\n\n";
				char n;
				cin>>n;
				if(n=='A' && t>=250) {
					a=2;
					y=90;
					s-=250;
				} else if(n=='B' && t>=300) {
					a=3;
					t-=300;
				} else if(n=='C' && t>=400) {
					a=4;
					y=90;
					t-=400;
				} else if(n=='D' && t>=1500) {
					a=5;
					y=90;
					t-=1500;
				} else if(n=='E' && t>=1) {
					a=1;
					t-=1;
				} else if(n=='F' && t>=10000) {
					a=6;
					t-=10000;
				}
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}






























		if(a==6) {
			if(p('0')){
			break;
		}
			if(f==true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout<<" ****";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
			} else {
				f=true;
				s=50;
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==1) {
				cout<<"<**>\n";
			} else if(b==2) {
				cout<<"<--\n\n";
			} else if(b==3) {
				cout<<" () \n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"****";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			for(int i=1; i<=s; i++) {
				cout<<" ";
			}
			if(b==1) {
				cout<<" ^^^^\n";
			} else if(b==3) {
				cout<<"/|\\\n";
			} else if(b==2) {
				cout<<"\n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"****\n\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==3) {
				cout<<"/ \\\n";
			} else if(b==2) {
				cout<<"\n";
			}
			if(s==3) {
				a=1;
				s=50;
				v+=20;
				t+=1000;
				cout<<"+1000!!!\n";
				b=1;
			}
			if(p(VK_RBUTTON)) {
				cout<<"A.  250$      B.  300$\nC.  400$      D.  1500$\nE.  1$       F.10000$\n";
				char n;
				cin>>n;
				if(n=='A' && t>=250) {
					y=90;
					a=2;
					t-=250;
				} else if(n=='B' && t>=300) {
					a=3;
					t-=300;
				} else if(n=='C' && t>=400) {
					a=4;
					y=90;
					t-=400;
				} else if(n=='D' && t>=1500) {
					a=5;
					y=90;
					t-=1500;
				} else if(n=='E' && t>=1) {
					a=1;
					t-=1;
				} else if(n=='F' && t>=10000) {
					a=6;
					t-=10000;
				}
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}



















		if(a==3) {
			if(p('0')){
			break;
		}
			r++;
			if(r==100000) {
				a=2;
				t-=10;
			}
			if(f==true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<" O/) ";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
			} else {
				f=true;
				s=50;
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==1) {
				cout<<"<**>\n";
			} else if(b==2) {
				cout<<"<--\n";
			} else if(b==3) {
				cout<<" () \n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/| ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			for(int i=1; i<=s; i++) {
				cout<<" ";
			}
			if(b==1) {
				cout<<" ^^^^\n";
			} else if(b==3) {
				cout<<"/|\\\n";
			} else if(b==2) {
				cout<<"\n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/ \\ \n\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==3) {
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
				cout<<"/ \\\n";
			} else if(b==2) {
				cout<<"\n";
			}
			if(s==2 && b<=2) {
				s=50;
				v++;
				t--;
			} else if(s==2 && b==3) {
				v--;
				t+10;
			}
			if(p(VK_RBUTTON)) {
				cout<<"A.  250$      B.  300$\nC.  400$      D.  1500$\nE.  1$       F.10000$\n";
				char n;
				cin>>n;
				if(n=='A' && t>=250) {
					y=90;
					a=2;
					t-=250;
				} else if(n=='B' && t>=300) {
					a=3;
					t-=300;
				} else if(n=='C' && t>=400) {
					a=4;
					y=90;
					t-=400;
				} else if(n=='D' && t>=1500) {
					a=5;
					y=90;
					t-=1500;
				} else if(n=='E' && t>=1) {
					a=1;
					t-=1;
				} else if(n=='F' && t>=10000) {
					a=6;
					t-=10000;
				}
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}

















































		if(a==4) {
			if(p('0')){
			break;
		}
			if(f==true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"\\---";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
			} else {
				f=true;
				s=50;
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==1) {
				cout<<"<**>\n";
			} else if(b==2) {
				cout<<"<--\n\n";
			} else if(b==3) {
				cout<<" () \n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/---";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			for(int i=1; i<=s; i++) {
				cout<<" ";
			}
			if(b==1) {
				cout<<" ^^^^\n";
			} else if(b==3) {
				cout<<"/|\\\n";
			} else if(b==2) {
				cout<<"\n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"/ \\ \n\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==3) {
				cout<<"/ \\\n";
			} else if(b==2) {
				cout<<"\n";
			}
			if(p(VK_LBUTTON)) {
				if(s<=50 && (b==2 || b==1)) {
					f=false;
					c++;
					if(c==5000) {
						a=1;
						t+=1;
					}
					t-=3;
					y--;
					v+=2;
					cout<<"()+2";
				} else if(s<=50 && (b==3)) {
					v--;
				}
			}  else if(p(VK_RBUTTON)) {
				cout<<"A.  250$      B.  300$\nC.  400$      D.  1500$\nE.  1$       F.10000$\n\n";
				char n;
				cin>>n;
				if(n=='A' && t>=250) {
					y=90;
					a=2;
					s-=250;
				} else if(n=='B' && t>=300) {
					a=3;
					t-=300;
				} else if(n=='C' && t>=400) {
					a=4;
					y=90;
					t-=400;
				} else if(n=='D' && t>=1500) {
					a=5;
					y=90;
					t-=1500;
				} else if(n=='E' && t>=1) {
					a=1;
					t-=1;
				} else if(n=='F' && t>=10000) {
					a=6;
					t-=10000;
				}
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		if(a==5) {
			if(p('0')){
			break;
		}
			if(y==0) {
				a=2;
			}
			if(f==true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"          |";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
			} else {
				f=true;
				s=50;
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==1) {
				cout<<"<**>\n";
			} else if(b==2) {
				cout<<"<--\n\n";
			} else if(b==3) {
				cout<<" () \n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"	-<|------------->";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			for(int i=1; i<=s; i++) {
				cout<<" ";
			}
			if(b==1) {
				cout<<" ^^^^\n";
			} else if(b==3) {
				cout<<"/|\\\n";
			} else if(b==2) {
				cout<<"\n";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"          |";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			if(b==3) {
				cout<<"/ \\\n";
			} else if(b==2) {
				cout<<"\n";
			}
			if(p(VK_LBUTTON)) {
				if(s<=1000000000 && (b==2 || b==1)) {
					f=false;
					s=50;
					y--;
					t+=1;
					v+=5;
					cout<<"()+5!!!";
				} else if(s<=100000000000 && (b==3)) {
					v--;
				}
			}  else if(p(VK_RBUTTON)) {
				cout<<"A.  250$      B.  300$\nC.  400$      D.  1500$\nE.  1$       F.10000$\n\n";
				char n;
				cin>>n;
				if(n=='A' && t>=250) {
					a=2;
					y=90;
					s-=250;
				} else if(n=='B' && t>=300) {
					a=3;
					t-=300;
				} else if(n=='C' && t>=400) {
					a=4;
					y=90;
					t-=400;
				} else if(n=='D' && t>=1500) {
					a=5;
					t-=1500;
				} else if(n=='E' && t>=1) {
					a=1;
					t-=1;
				} else if(n=='F' && t>=10000) {
					a=6;
					t-=10000;
				}
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
		} 
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	

	
	
	
	
	
	else if(p('C')) {
		system("cls");
		int s=0;
	char k,j;
	hideCursor();
	cout<<"请";
	Sleep(1);
	cout<<"输";
	Sleep(1);
	cout<<"入";
	Sleep(1);
	cout<<"密";
	Sleep(1);
	cout<<"码：";
	Sleep(1);
	string s1;
	cin>>s1;
	if(s1=="lql123") {
		cout<<"开始\n";
		Sleep(20);
	} else {
		break;
	}
	for(int d=1;d<=30;d++){
		if(p('0')){
			break;
		}
		j=k;
		srand(time(NULL));
		system("cls");
		
		while((!(k>='A' && k<='Z')) || j==k){
			k=n(200);
		}
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		
			cout<<"| X |\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"-----  _\n";
		cout<<"|   | |"<<(char)k<<"|"<<"\n";
		cout<<"-----  -\n";
		cout<<"  |  \n";
		cout<<"  |  \n";
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"-----   -\n";
		cout<<"|   |  |"<<(char)k<<"|"<<"\n";
		cout<<"-----   -\n";
		cout<<"  |  \n";
		cout<<"  |  \n";
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"-----    -\n";
		cout<<"|   |   |"<<(char)k<<"|"<<"\n";
		cout<<"-----    -\n";
		cout<<"  |  \n";
		cout<<"  |  \n";
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"-----     -\n";
		cout<<"|   |    |"<<(char)k<<"|"<<"\n";
		cout<<"-----     -\n";
		cout<<"  |  \n";
		cout<<"  |  \n";
		cout<<"剩余个数："<<30-d<<"\n";
		int i=0; 
		bool f=true;
		for(;;){
			i++;
			if(i==2200000){
				cout<<"你死啦！！！！！！！！";
				Sleep(1000); 
				f=false;
				break;
			}
			if(p(k)){
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"-----    \\|/\n";
				cout<<"|   |   -----\n";
				cout<<"-----   / | \\\n";
				cout<<"  |  \n";
				cout<<"  |  \n";
				cout<<"剩余个数："<<30-d<<"\n";
				Sleep(200);
				break;
			}
		}
		if(f==false){
			break;
		}
	} 
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('D')){
		system("cls");
		int n,m=0,f=0,s=0,hm=0;
		cout<<"请输入毫秒数：";
		cin>>n;
	for(int i=1; i<=n; i++) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"| X |\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if(p('0')){
			break;
		}
		m++;
		if(m==59){
			f++;
			m=0;
		}
		if(f==59) {
			s++;
			f=0;
		}
		printf("  %d : %d : %d\n",s,f,m);
		printf("  时  分  秒\n\n"); 
		printf("  暂停（空格）\n\n");
		printf("----------------\n");
		printf("|   <|空格|>   |\n");
		printf("----------------\n");
		if(p(' ')){
			cout<<"按B键继续……\n";
			while(!p('B')){
				
			}
		}
		Sleep(1000);
		if(p(' ')){
			cout<<"按B键继续……\n";
			while(!p('B')){
				
			}
		}
	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('E')){
		system("cls");
		if(p('0')){
			break;
		}
		string s1;
	cin>>s1;
	if(s1=="lql123") {
		cout<<"Start!!!\n";
	} else {
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char n;
	char u='y';
	int i=1,k=0;
	for(;;) {
		if(p('0')){
			break;
		}
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"| X |\n";
		if(u=='y') {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   ****\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"  **";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);

			cout<<"***\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<"********\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"  ******\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   ****\n";
			for(int j=1; j<=k; j++) {
				cout<<"\n";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			for(int j=1; j<=i+10; j++) {
				cout<<"*";
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cin>>n;
			if(n=='a') {
				i--;
			} else if(n=='d') {
				i++;
			} else if(n=='w') {
				k++;
			} else if(n=='s') {
				k--;
			} else if(n=='b') {
				u='r';
			}
			if(k>=5) {
				k=0;
			}
		}








		if(u=='r') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   ****\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"  **";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);

			cout<<"***\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<"********\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"  ******\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   ****\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"   *  *\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   *  *\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   *  *\n";
			for(int j=1; j<=k; j++) {
				cout<<"\n";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			for(int j=1; j<=i+10; j++) {
				cout<<"*";
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cin>>n;
			if(n=='a') {
				i--;
			} else if(n=='d') {
				i++;
			} else if(n=='w') {
				k+=2;
			} else if(n=='s') {
				k--;
			} else if(n=='b') {
				u='b';
			}
			if(k>=30) {
				k=0;
			}
		}




		if(u=='b') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   ****\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"  **";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);

			cout<<"***\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			cout<<"********\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"  ******\n";
			for(int j=1; j<=i; j++) {
				cout<<" ";
			}
			cout<<"   ****";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"*";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"***\n";
			for(int j=1; j<=k; j++) {
				cout<<"\n";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			for(int j=1; j<=i+10; j++) {
				cout<<"*";
			}
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cin>>n;
			if(n=='a') {
				i-=3;
			} else if(n=='d') {
				i+=3;
			} else if(n=='w') {
				k++;
			} else if(n=='s') {
				k--;
			} else if(n=='b') {
				u='y';
			}
			if(k>=4) {
				k=0;
			}
		}
	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('F')){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
		char a[1000][1000],n,b[4][21];
	int x=11,d=3;
	int y[21];
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=20; j++) {
			a[i][j]='X';
			b[i][j]=' ';
		}
	}
	for(int j=1; j<=20; j++) {
		y[j]=3;
	}
	b[3][11]='^';
	for(;;) {
		if(p('0')){
			break;
		}
		system("cls");
		bool f=true;
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=20; j++) {
				if(a[i][j]=='X') {
					f=false;
				}
			}
		}
		if(f==true) {
			break;
		}
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=20; j++) {
				cout<<a[i][j];
			}
			cout<<'\n';
		}
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=20; j++) {
				cout<<b[i][j];
			}
			cout<<'\n';
		}
		cin>>n;
		if(n=='a') {
			swap(b[d][x],b[d][x-1]);
			x--;
		} else if(n=='d') {
			swap(b[d][x],b[d][x+1]);
			x++;
		} else if(n=='h') {
			if(y[x]>0) {
				a[y[x]][x]=' ';
				y[x]--;
			}
		} else if(n=='s') {
			swap(b[d][x],b[d+1][x]);
			d++;
		} else if(n=='w') {
			swap(b[d][x],b[d-1][x]);
			d--;
		}
	}
	cout<<"you are won!!!!!!!!!!";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('G')){
		system("cls");
		int s=100,j=0,o=0,v=5,t=0,s2=0,v2=8,k=400;
	bool a=true;
	bool f=false;
	string s1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout<<"       *****\n";
	cout<<"        *****\n";
	cout<<"         *****\n";
	cout<<"          *****\n";
	cout<<"           *****\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	cout<<"************\n";
	cout<<"************\n";
	cout<<"************\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<<" Game-Box\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	getline(cin,s1);
	if(s1!="lql123") {
		break;
	}
	for(int i=1;; i++) {
		if(p('0')){
			break;
		}
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
		if(p('A')) {
			cout<<"NO MORE NOW!!!!!!!!!!\n";
			cout<<"Please choose ' ' to go......\n";
			while(!p(' ')) {

			}
		}

		if(v==0) {
			cout<<"/_\\   You are lost!!!";
			cout<<"Please choose ' ' to go......";
			while(!p(' ')) {

			}
			break;
		}
		if(v2==0) {
			break;
		}
		o++;
		if(o==5) {
			f=false;
		}system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"($)<"<<t<<">      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		for(int i=1; i<=v2; i++) {
			cout<<"*";
		}
		cout<<"        ";
		if(f==false) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"++++        ";
		} else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout<<"++++        ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"[]<"<<v<<">      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout<<i;
		cout<<"\n________________________\n\n\n";


		
		if(a==true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<" O\n/|\\|";
			srand(time(NULL));
			int h=n(4);
			if(h==0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			} else if(h==1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			} else if(h==2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			} else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			if(f==false) {
				for(int k=1; k<=s; k++) {
					cout<<" ";
				}
				cout<<"<----------<-\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"/ \\";
				for(int k=1; k<=s; k++) {
					cout<<" ";
				}
				cout<<"             ";
				for(int i=1; i<=s2; i++) {
					cout<<" ";
				}
			} else {
				cout<<"\n/ \\";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
				for(int i=1; i<=s; i++) {
					cout<<" ";
				}
				cout<<"<----------<-\n";
				cout<<"    ";
				for(int i=1; i<=s2; i++) {
					cout<<" ";
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout<<"========|>>\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout<<"| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | \n";
			cout<<"------------------------------------------------------------------------------------------------------------------------------->\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			if(i%400==0) {
				v++;
			}
			if(i%500==0) {
				t++;
			}
			for(int k=1; k<=j; k++) {
				cout<<"\n";
			}
			s-=5;
			s2+=5;
			if(s==0 && f==false) {
				s=100;
				s2=0;
				v--;
			} else if(s==0) {
				s=100;
				s2=0;
				t++;
			}
			if(p(' ')) {
				f=true;
				o=0;
			} else if(p('B') && t>=30) {
				a=false;
				k=400;
				t-=30;
			}
		}











		else {
			k--;
			if(k==0) {
				a=true;
			}
			f=false;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<" \\\n |> ";
			srand(time(NULL));
			int h=n(4);
			if(h==0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			} else if(h==1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			} else if(h==2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			} else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			for(int k=1; k<=s; k++) {
				cout<<" ";
			}
			cout<<"<----------<-\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<" /";
			for(int k=1; k<=s; k++) {
				cout<<" ";
			}
			cout<<"             ";
			for(int i=1; i<=s2; i++) {
				cout<<" ";
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout<<"========|>>\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout<<"| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | \n";
			cout<<"------------------------------------------------------------------------------------------------------------------------------->\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			if(i%400==0) {
				v++;
			}
			if(i%500==0) {
				t++;
			}
			for(int k=1; k<=j; k++) {
				cout<<"\n";
			}
			s-=5;
			s2+=5;
			if(s==0) {
				s=100;
				s2=0;
				v2--;
			}
		}
		system("cls");
	}


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout<<"___________\n";
	cout<<"| 你赢啦  |\n";
	cout<<"| ！！！  |\n";
	cout<<"-----------\n";   
	cout<<"请按0键继续……";
	while(!p('0')) {

	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('H')){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout<<"If you have four '1',you are won!"<<'\n';
	srand(time(NULL));
	int a[10][10];
	bool b[10][10];
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			b[i][j]=n(3);
		}
	}
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			a[i][j]=2;
		}
		cout<<'\n';
	}
	int win=2,x,y;
	int f=0;
	while(win!=0) {
		if(p('0')){
			break;
		}
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				if(a[i][j]==1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout<<"[1]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					//f++;
					continue;
				}
				if(a[i][j]==0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					cout<<"[0]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					win=0;
					continue;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout<<"[ ]";
			}
			cout<<"\n";
		}
		if(win==0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"you are lose!!! /[|_|]\\";
			break;
		}
		cin>>x>>y;
		cout<<'\b';
		if(x==123 && y==456) {
			for(int i=1; i<=10; i++) {
				for(int j=1; j<=10; j++) {
					cout<<b[i][j]<<' ';
				}
				cout<<'\n';
			}
			continue;
		}
		if(b[x][y]==0) {
			a[x-1][y-1]=0;
		} else {
			a[x-1][y-1]=1;
			f++;
		}
		if(f==4) {
			for(int i=0; i<10; i++) {
				for(int j=0; j<10; j++) {
					if(a[i][j]==1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						cout<<"[1]";
						continue;
					}
					if(a[i][j]==0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						cout<<"[0]";
						win=0;
						continue;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					cout<<"[ ]";
				}
				cout<<'\n';
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"you are won!!!\n";
			return 0;
		}
	}
	cout<<"you are lose!!!\n";
	}
	
	
	else if(p(' ')){
		system("cls");
		Sleep(800);
		while(!p(' ')){
			
		}
		Sleep(500);
	}
	 
	
	else if(p('I')) {
		system("cls");
		cout<<"https://www.baidu.com/";
		while(!p('0')){
			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	else if(p('U')){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"  -------      -------      -------      -------      \n";
		cout<<"  |   ◆ |      | / <-|      |  A  |      |  |  |     \n";
		cout<<"  |  ●  |      |/    |      |  B  |      | /   |     \n";
		cout<<"  -------      -------      -------      -------      \n";
		cout<<"A.超级贪吃蛇  A.战斗游戏  C.打字游戏    D.计时器      \n\n\n\n";
		cout<<"  -------      -------      -------      -------\n";
		cout<<"  | 一只|      |XXXXX|      |  ^  |      |#1###|\n";
		cout<<"  |  鸡 |      |  ^  |      |  |  |      |#####|\n";
		cout<<"  -------      -------      -------      -------\n";
		cout<<"E.-------------.射击游戏   G.跳力游戏     H.扫雷\n";
		cout<<"  |   信息    |             \n";
		cout<<"  |A.99乘法表 |             \n";
		cout<<"  |           |             \n";
		cout<<"  |           |-------      -------      -------\n";
		cout<<"  |B.计算器   ||浏览 |      |[   ]|      |  -  |\n";
		cout<<"  |           ||   器|      |     |      |  o  |\n";
		cout<<"  |           |-------      -------      -------\n";
		cout<<"I.|C.画图     |.浏览器    K.打人游戏  L.乒乓球游戏\n";
		cout<<"  |           |             \n";
		cout<<"  |           |      \n";
		cout<<"  |D.天气     |      \n";
		cout<<"------------------------------------------------\n";
		cout<<"|  X          up系统                           |\n";
		cout<<"------------------------------------------------\n";
		Sleep(100);
		while(!(p('A') || p('B') || p('C') || p('U') || p('D') || p(VK_DOWN))) {
			
		}
		if(p('U')){
			Sleep(100);
		}
		
		if(p('A')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
			for(int i=1;i<=9;i++){
				for(int j=1;j<=i;j++){
					cout<<j<<"*"<<i<<"="<<i*j<<" ";
				}
				cout<<"\n";
			}
			while(!p(' ')){
				
			}
		}
		
		
		else if(p('B')){
			int b;
			for(;;){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout<<"| X |\n";
			int a;
			string s;	
		cin>>a;
		if(a==0){
			break;
		}
		cin>>s;
		if(s=="sqrt"){
			string s1;
			cin>>s1;
			cout<<sqrt(a)<<"\n";
		}else{
			cin>>b;
			string s1;
			cin>>s1;
		}
		if(s=="*"){
			cout<<a*b<<"\n";
		}if(s=="/"){
			printf("%.10lf\n",a/b);
		}if(s=="+"){
			cout<<a+b<<"\n";
		}if(s=="-"){
			cout<<a-b<<"\n";
		}if(s=="pow"){
			cout<<pow(a,b)<<"\n";
		}
	}
	
		}
		
		
		
		
		
		
		
		
		
		else if(p('C')){
			system("cls");
			char a[105][105];
	for(int i=1; i<=100; i++) {
		for(int j=1; j<=100; j++) {
			a[i][j]=' ';
		}
		cout<<"\n";
	}
	a[100][1]='_';
	int x=100,y=1;
	for(;;) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"| X |\n";
		system("cls");
		for(int i=1; i<=100; i++) {
			for(int j=1; j<=100; j++) {
				cout<<a[i][j];
			}
			cout<<"\n";
		}
		while(!p('A') && !p('S') && !p('D') && !p('W') && !p('R') && !p('B') && !p('P')  && !p('Y') && !p('G') && !p(' ')) {

		}
		if(p(' ')){
			break;
		}
		if(p('A')) {
			a[x][y]='-';
			a[x][--y]='(';
		} else if(p('D')) {
			a[x][y]='-';
			a[x][++y]=')';
		} else if(p('W')) {
			a[x][y]='|';
			int o=y;
			a[--x][y]='^';
			y=o;
		} else if(p('S')) {
			a[x][y]='|';
			int o=y;
			a[++x][o]='X';
			y=o;
		}else if(p('R')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		}else if(p('B')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}else if(p('P')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		}else if(p('Y')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		}else if(p('G')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		}
	}
		}
		
		
		
		else if(p('D')){
			cout<<"https://www.msn.cn/zh-cn/weather/forecast/in-%E5%AE%89%E5%BE%BD%E7%9C%81,%E8%8A%9C%E6%B9%96%E5%B8%82?loc=eyJsIjoi6Iqc5rmW5biCIiwiciI6IuWuieW%2BveecgSIsImMiOiLkuK3ljY7kurrmsJHlhbHlkozlm70iLCJpIjoiQ04iLCJnIjoiemgtY24iLCJ4IjoiMTE4LjM2NDczMDgzNDk2MDk0IiwieSI6IjMxLjI5MTU4NDAxNDg5MjU3OCJ9&weadegreetype=C&ocid=msedgdhp&cvid=675438a3c5214ce997943f2f3e42e9b1";
			while(!p('0')){
				
			}
		}
		
		else if(p(VK_DOWN)){
			time_t now=time(nullptr);
			system("cls");
			cout<<"  -------      -------      -------      -------      \n";
			cout<<"  |   ◆ |      | / <-|      |  A  |      |  |  |     \n";
			cout<<"  |  ●  |      |/    |      |  B  |      | /   |     \n";
			cout<<"  -------      -------      -------      -------      \n";
			cout<<"A.超级贪吃蛇  A.战斗游戏  C.打字游戏    D.计时器      \n\n\n\n";
			cout<<"  -------      -------      -------      -------\n";
			cout<<"  | 一只|      |XXXXX|      |  ^  |      |#1###|\n";
			cout<<"  |  鸡 |      |  ^  |      |  |  |      |#####|\n";
			cout<<"  -------      -------      -------      -------\n";
			cout<<"E.-------------.射击游戏   G.跳力游戏     H.扫雷\n";
			cout<<"  | E.小文档  |             \n";
			cout<<"  |           |             \n";
			cout<<"  |           |             \n";
			cout<<"  |           |-------      -------      -------\n";
			cout<<"  |           ||浏览 |      |[   ]|      |  -  |\n";
			cout<<"  |           ||   器|      |     |      |  o  |\n";
			cout<<"  |           |-------      -------      -------\n";
			cout<<"I.|           |.浏览器    K.打人游戏   L.乒乓球游戏\n";
			cout<<"  |           |             \n";
			cout<<"  |           |      \n";
			cout<<"  |           |      \n";
			cout<<"------------------------------------------------\n";
			cout<<"|  X          up系统                           |\n";
			cout<<"------------------------------------------------\n";
			Sleep(100);
			while(!(p('E') || p(VK_UP))) {
				
			} 
			if(p('E')){
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout<<"| X |\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				
				string c;
				for(;;){
					getline(cin,c);
					d2++;
					s1234[d1][d2]=c;
					if(c=="okup"){
						cout<<"|保存 |不保存|\n"; 
						cout<<"保存请按0键  |\n";
						cout<<"否则按1键    |\n";
						while(true){
							if(p('1')){
								d1--;
								break;
							}else if(p('0')){
								system("cls");
								cout<<"请输入名称：\n";
								cout<<"|                                                                 \n";
								cout<<"-----------------\n";
								fun(1,2);
								string s;
								cin>>s;
								d++;
								s123[d]=s;
								d1++;
								break;
							}
						}
						break;
					}
				}
			}
			else{
				system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"  -------      -------      -------      -------      \n";
		cout<<"  |   ◆ |      | / <-|      |  A  |      |  |  |     \n";
		cout<<"  |  ●  |      |/    |      |  B  |      | /   |     \n";
		cout<<"  -------      -------      -------      -------      \n";
		cout<<"A.超级贪吃蛇  A.战斗游戏  C.打字游戏    D.计时器      \n\n\n\n";
		cout<<"  -------      -------      -------      -------\n";
		cout<<"  | 一只|      |XXXXX|      |  ^  |      |#1###|\n";
		cout<<"  |  鸡 |      |  ^  |      |  |  |      |#####|\n";
		cout<<"  -------      -------      -------      -------\n";
		cout<<"E.-------------.射击游戏   G.跳力游戏     H.扫雷\n";
		cout<<"  |   信息    |             \n";
		cout<<"  |A.99乘法表 |             \n";
		cout<<"  |           |             \n";
		cout<<"  |           |-------      -------      -------\n";
		cout<<"  |B.计算器   ||浏览 |      |[   ]|      |  -  |\n";
		cout<<"  |           ||   器|      |     |      |  o  |\n";
		cout<<"  |           |-------      -------      -------\n";
		cout<<"I.|C.画图     |.浏览器    K.打人游戏   L.乒乓球游戏\n";
		cout<<"  |           |             \n";
		cout<<"  |           |      \n";
		cout<<"  |D.天气     |      \n";
		cout<<"------------------------------------------------\n";
		cout<<"|  X          up系统                           |\n";
		cout<<"------------------------------------------------\n";
		Sleep(100);
		while(!(p('A') || p('B') || p('C') || p('U') || p('D'))) {
			
		}
		if(p('U')){
			Sleep(100);
		}
		
		if(p('A')){
			system("cls");
			for(int i=1;i<=9;i++){
				for(int j=1;j<=i;j++){
					cout<<j<<"*"<<i<<"="<<i*j<<" ";
				}
				cout<<"\n";
			}
			while(!p(' ')){
				
			}
		}
		
		
		else if(p('B')){
			system("cls");
			int b;
			for(;;){
			int a;
			string s;	
		cin>>a;
		if(a==0){
			break;
		}
		cin>>s;
		if(s=="sqrt"){
			string s1;
			cin>>s1;
			cout<<sqrt(a)<<"\n";
		}else{
			cin>>b;
			string s1;
			cin>>s1;
		}
		if(s=="*"){
			cout<<a*b<<"\n";
		}if(s=="/"){
			printf("%.10lf\n",a/b);
		}if(s=="+"){
			cout<<a+b<<"\n";
		}if(s=="-"){
			cout<<a-b<<"\n";
		}if(s=="pow"){
			cout<<pow(a,b)<<"\n";
		}if(s=="off"){
			return 0;
		}
	}
	
		}
		
		
		
		
		
		
		
		
		
		else if(p('C')){
			system("cls");
			char a[105][105];
	for(int i=1; i<=100; i++) {
		for(int j=1; j<=100; j++) {
			a[i][j]=' ';
		}
		cout<<"\n";
	}
	a[100][1]='_';
	int x=100,y=1;
	for(;;) {
		
		system("cls");
		for(int i=1; i<=100; i++) {
			for(int j=1; j<=100; j++) {
				cout<<a[i][j];
			}
			cout<<"\n";
		}
		while(!p('A') && !p('S') && !p('D') && !p('W') && !p('R') && !p('B') && !p('P')  && !p('Y') && !p('G') && !p(' ')) {

		}
		if(p(' ')){
			break;
		}
		if(p('A')) {
			a[x][y]='-';
			a[x][--y]='(';
		} else if(p('D')) {
			a[x][y]='-';
			a[x][++y]=')';
		} else if(p('W')) {
			a[x][y]='|';
			int o=y;
			a[--x][y]='^';
			y=o;
		} else if(p('S')) {
			a[x][y]='|';
			int o=y;
			a[++x][o]='X';
			y=o;
		}else if(p('R')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		}else if(p('B')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		}else if(p('P')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		}else if(p('Y')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		}else if(p('G')){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		}
	}
		}
		
		
		
		else if(p('D')){
			system("cls");
			cout<<"https://www.msn.cn/zh-cn/weather/forecast/in-%E5%AE%89%E5%BE%BD%E7%9C%81,%E8%8A%9C%E6%B9%96%E5%B8%82?loc=eyJsIjoi6Iqc5rmW5biCIiwiciI6IuWuieW%2BveecgSIsImMiOiLkuK3ljY7kurrmsJHlhbHlkozlm70iLCJpIjoiQ04iLCJnIjoiemgtY24iLCJ4IjoiMTE4LjM2NDczMDgzNDk2MDk0IiwieSI6IjMxLjI5MTU4NDAxNDg5MjU3OCJ9&weadegreetype=C&ocid=msedgdhp&cvid=675438a3c5214ce997943f2f3e42e9b1";
			while(!p('0')){
				
			}
		}
			}
			
		}
		
		
		
		
		
		else if(p(' ')){
			system("cls");
			
		}
	}
	
	
	else if(p('J')) {
		system("cls");
		cout<<"http://ybt.ssoier.cn:8088/";
		while(!p('0')){
			
		}
	}
	
	}
		
	return 0;
	}
	
	
	
	
	
	

