
// use following command to run : 
// g++ -std=c++14 snake.cpp -lpthread

#include <bits/stdc++.h>
#include <thread>
#include <unistd.h>
#include <termios.h>
using namespace std;

enum direction { LEFT, RIGHT, UP, DOWN };
enum tileConf { EMPTY, BLOCKED, OCCUPIED, FOOD };
enum gameState { RUNNING, OVER };

////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tile
{
	public:
		tileConf conf;
		Tile(tileConf);
};

Tile::Tile(tileConf tc)
{
	conf = tc;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Screen // should be a singleton class
{
	public:
		int WIDTH,HEIGHT;
		vector< vector<Tile> >matrix;

		Screen();
		void print(int,int,int,int,int);
};

Screen::Screen()
{
	HEIGHT = 40;
	WIDTH = 100;
	Tile tile(EMPTY);
	matrix = vector< vector<Tile> >(HEIGHT,vector<Tile>(WIDTH,tile));
	/*
	   for(int i=0;i<WIDTH;i++)
	   matrix[HEIGHT-1][i].conf = matrix[0][i].conf = BLOCKED;
	   for(int i=0;i<HEIGHT;i++)
	   matrix[i][WIDTH-1].conf = matrix[i][0].conf = BLOCKED;
	 */
}

void Screen::print(int score,int level,int snakex,int snakey,int snakeLength)
{
	system("clear"); // clearing the existing screen
	for(int i=0;i<WIDTH+2;i++)
		cout<<"@";
	cout<<endl;
	for(int i=0;i<HEIGHT;i++)
	{
		cout<<"@";
		for(int j=0;j<WIDTH;j++)
		{
			if(matrix[i][j].conf == OCCUPIED)
			{
				if(i==snakex && j==snakey)
					cout<<'O';
				else cout<<'o';
			}
			if(matrix[i][j].conf == BLOCKED)
				cout<<'#';
			if(matrix[i][j].conf == EMPTY)
				cout<<' ';
			if(matrix[i][j].conf == FOOD)
				cout<<'F';

		}
		cout<<"@"<<endl;
	}
	for(int i=0;i<WIDTH+2;i++)
		cout<<"@";
	cout<<endl;
	cout<<"SCORE : "<<score<<endl;
	cout<<"LEVEL : "<<level<<endl;
	cout<<"Snake_Length : "<<snakeLength<<endl;
	cout<<"Snake_head (X,Y) : "<<snakex<<","<<snakey<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Food
{
	public:
		pair<int,int>coordinates;
		Food(Screen&);
};

Food::Food(Screen&screen)
{
	//for(int i=0;i<10;i++)
	{
		int x,y;
		do{
			x = rand()%screen.HEIGHT;
			y = rand()%screen.WIDTH;
		}while(screen.matrix[x][y].conf!=EMPTY);
		coordinates = make_pair(x,y);
		screen.matrix[x][y] = FOOD;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Snake // should be a singleton class
{
	public:
		pair<int,int>head,tail;
		list< pair<int,int> >body;
		int currentLength;
		volatile direction headDirection;
		int speed;

		Snake(Screen&);
		Snake();

		void moveHeadLeft(Screen&,int&);
		void moveHeadRight(Screen&,int&);
		void moveHeadDown(Screen&,int&);
		void moveHeadUp(Screen&,int&);
		void moveTail(Screen&);

		void move(Screen&,int&);

		void eat(Screen&,int&);
		bool bitesItself(); // bites itself
		bool hitsWall(Screen&);
};

Snake::Snake()
{

}
Snake::Snake(Screen&screen)
{
	int startx = screen.HEIGHT/2;
	int starty = screen.WIDTH/2;
	int endx = startx;
	int endy = starty+2;

	head = make_pair(endx,endy);
	tail = make_pair(startx,starty);
	pair<int,int>intermediate = make_pair(startx,starty+1);

	body.push_back(head);
	body.push_back(intermediate);
	body.push_back(tail);

	currentLength = 3;
	headDirection = RIGHT;
	speed = 1;

	screen.matrix[head.first][head.second].conf = OCCUPIED;
	screen.matrix[intermediate.first][intermediate.second].conf = OCCUPIED;
	screen.matrix[tail.first][tail.second].conf = OCCUPIED;
}

void Snake::moveTail(Screen&screen)
{ 
	screen.matrix[tail.first][tail.second]=EMPTY;
	body.pop_back();
	tail = body.back();
}

void Snake::moveHeadLeft(Screen&screen,int &score)
{
	int newx = head.first;
	int newy = head.second-1;
	if(newy<0)
		newy+=screen.WIDTH;
	tileConf tc = screen.matrix[newx][newy].conf;
	if(tc==FOOD)
		eat(screen,score);
	else if(tc==BLOCKED || tc==OCCUPIED)
		exit(0);
	screen.matrix[newx][newy]=OCCUPIED;
	head = make_pair(newx,newy);
	body.push_front(head);
}

void Snake::moveHeadRight(Screen&screen,int &score)
{
	int newx = head.first;
	int newy = head.second+1;
	if(newy>=screen.WIDTH)
		newy%=screen.WIDTH;
	tileConf tc = screen.matrix[newx][newy].conf;
	if(tc==FOOD)
		eat(screen,score);
	else if(tc==BLOCKED || tc==OCCUPIED)
		exit(0);
	screen.matrix[newx][newy]=OCCUPIED;
	head = make_pair(newx,newy);
	body.push_front(head);
}

void Snake::moveHeadDown(Screen&screen,int &score)
{
	int newx = head.first+1;
	int newy = head.second;
	if(newx>=screen.HEIGHT)
		newx%=screen.HEIGHT;
	tileConf tc = screen.matrix[newx][newy].conf;
	if(tc==FOOD)
		eat(screen,score);
	else if(tc==BLOCKED || tc==OCCUPIED)
		exit(0);
	screen.matrix[newx][newy]=OCCUPIED;
	head = make_pair(newx,newy);
	body.push_front(head);
}

void Snake::moveHeadUp(Screen&screen,int &score)
{
	int newx = head.first-1;
	int newy = head.second;
	if(newx<0)
		newx = newx + screen.HEIGHT;
	tileConf tc = screen.matrix[newx][newy].conf;
	if(tc==FOOD)
		eat(screen,score);
	else if(tc==BLOCKED || tc==OCCUPIED)
		exit(0);
	screen.matrix[newx][newy]=OCCUPIED;
	head = make_pair(newx,newy);
	body.push_front(head);
}

void Snake::move(Screen &screen,int &score)
{

	if(headDirection == RIGHT)
		moveHeadRight(screen,score);
	else if(headDirection == LEFT)
		moveHeadLeft(screen,score);
	else if(headDirection == UP)
		moveHeadUp(screen,score);
	else if(headDirection == DOWN)
		moveHeadDown(screen,score);
	moveTail(screen);
}

void Snake::eat(Screen&screen,int &score)
{
	pair<int,int>tail1,tail2;
	tail1 = body.back();
	body.pop_back();
	tail2 = body.back();
	body.push_back(tail);

	//direction tailDirection;
	int x1,y1,x2,y2;
	x1 = tail1.first;
	y1 = tail1.second;
	x2 = tail2.first;
	y2 = tail2.second;

	if(y1+1==y2)
	{
		body.push_back(make_pair(x1,y1-1));
		tail = body.back();
		screen.matrix[x1][y1-1].conf=OCCUPIED;
	}
	else if(y1==y2+1)
	{
		body.push_back(make_pair(x1,y1+1));
		tail = body.back();
		screen.matrix[x1][y1+1].conf=OCCUPIED;
	}
	else if(x1==x2+1)
	{
		body.push_back(make_pair(x1+1,y1));
		tail = body.back();
		screen.matrix[x1+1][y1].conf=OCCUPIED;
	}
	else if(x1+1==x2)
	{
		body.push_back(make_pair(x1-1,y1));
		tail = body.back();
		screen.matrix[x1-1][y1].conf=OCCUPIED;
	}

	currentLength++;
	score+=10;
	Food f(screen);
}

bool Snake::bitesItself()
{
	return false;
}

bool Snake::hitsWall(Screen&s)
{
	return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Game // should be a singleton class
{
	public:
		gameState state;
		int score;
		int level;
		Snake snake; // should be a singleton class
		Screen screen; // should be a singleton class

		Game();
		void run();
		void keepSnakeMoving(Snake&,Screen&);
};
Game::Game()
{
	state = RUNNING;
	score = 0; 
	level = 1;

	screen = Screen();
	snake = Snake(screen);
}
void Game::keepSnakeMoving(Snake &snake,Screen &screen)
{
	for(int i=0;i<10;i++)
		Food f(screen);
	while(true)
		//for(int i=0;i<10;i++)
	{
		usleep(100000);
		//cout<<"here"<<endl;
		snake.move(screen,score);
		screen.print(score,level,snake.head.first,snake.head.second,snake.currentLength);
	}
}

char getch() { // to get a character in c++
	char buf = 0;
	struct termios old = {0};
	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(0, &buf, 1) < 0)
		perror ("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror ("tcsetattr ~ICANON");
	return (buf);
}
void Game::run()
{
	thread th(&Game::keepSnakeMoving,this,std::ref(snake),std::ref(screen));

	while(true)
	{
		char ch = getch();
		if((ch=='w' || ch=='8') && snake.headDirection!=DOWN)
			snake.headDirection = UP;
		else if((ch=='d' || ch=='6') && snake.headDirection!=LEFT)
			snake.headDirection = RIGHT;
		else if((ch=='s' || ch=='5') && snake.headDirection!=UP)
			snake.headDirection = DOWN;
		else if((ch=='a' || ch=='4') && snake.headDirection!=RIGHT)
			snake.headDirection = LEFT;
	}
	th.join();
}


int main()
{
	srand((unsigned)time(0)); 
	Game g;
	g.run();
	return 0;
}
