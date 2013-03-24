#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
char table[50][50];
int inputlen;
int sizex,sizey;
class pos
{
	private:
		int x,y;
	public:
		pos(int origx,int origy):x(origx),y(origy){}
		int getchar()
		{
			return table[x][y];
		}
		pos  move(pos dst)
		{
			x+=dst.x;
			y+=dst.y;
			return *this;
		}
		bool _test(pos dst,char * input)
		{
			for( int i=0 ; i<inputlen ;++i )
			{
				if(x==0||x==sizex+1||y==0||y==sizey+1) return 0;
				if(*input!=getchar()) return 0;
				++input;
				move(dst);
			}
			return 1;
		}
		bool test(pos dst,char * input)
		{
			pos tmp=*this;
			bool value=_test(dst, input);
			*this=tmp;
			//std::cout<<value<<"  "<<tmp.x<<tmp.y<<std::endl;
			return value;
		}
			

};
int main()
{
	pos up(-1,0);
	pos down(1,0);
	pos left(0,-1);
	pos right(0,1);
	pos lu(-1,-1);
	pos ld(1,-1);
	pos ru(-1,1);
	pos rd(1,1);
	int n;
	std::cin>>n;
	while(n--)
	{
		//std::cin>>sizex>>sizey;
		scanf("%d%d",&sizex,&sizey);//std::cin>>testnum;
		for( int x=1 ; x<=sizex ; ++x )
		{
			for( int y=1 ; y<=sizey ; ++y )
			{
				std::cin>>table[x][y];
				table[x][y]=toupper(table[x][y]);			
			}
			
		}
		int testnum;
		scanf("%d",&testnum);//std::cin>>testnum;
		char input[50];
		while(testnum--)
		{
			//fgets(input,50,stdin);//scanf("%s",input);scanf("%s",input);
			scanf("%s",input);
			inputlen=strlen(input);
			for( int i=0 ; i!=strlen(input) ; ++i )
			{
				input[i]=toupper(input[i]);
			}
			for( int x=1 ; x<=sizex ; ++x )
			{
				for( int y=1 ; y<=sizey ; ++y )
				{
					pos test(x,y);
					if ( test.test(up ,input)||
					test.test(down,input)||
					test.test(left,input)||
					test.test(right,input)||
					test.test(lu,input)||
					test.test(ld,input)||
					test.test(ru,input)||
					test.test(rd,input))
					{
						std::cout<<x<<" "<<y<<std::endl;
						x=sizex+1;
						y=sizey+1;
					}
				}
				
			}
		}
	if (n)	std::cout<<std::endl;
	}
}
			
