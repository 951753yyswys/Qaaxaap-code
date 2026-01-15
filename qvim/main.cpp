#include<iostream>
#include<fstream>
#include<vector>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#endif
#include"./include/buffer.h"
#include"./include/edit.h"
#include"./include/cursor.h"
#include"./include/tui.h"
using std::cout;
using std::cin;
using std::flush;
using std::endl;
using std::vector;
enum KeyCode {
    KEY_ESC = 27,
    KEY_ENTER = 10,
    KEY_BACKSPACE = 127,
    KEY_UP = 256,
    KEY_DOWN = 257,
    KEY_LEFT = 258,
    KEY_RIGHT = 259
};

// 最简单的 getch 函数
char getch_simple() {
#ifdef _WIN32
    return _getch();
#else
    char ch;
    struct termios oldt, newt;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

// 处理特殊键的函数
int getchex() {
    char first_char = getch_simple();
    
    // 如果是 ESC，检查是否是方向键
    if (first_char == 27) {
        // 非阻塞地检查下一个字符
        // 使用简单的延迟，不要用 select
        #ifdef _WIN32
            // Windows: 方向键是 224 + 某个值
            if (_kbhit()) {
                char second_char = _getch();
                if (second_char == 224 && _kbhit()) {
                    char third_char = _getch();
                    switch (third_char) {
                        case 72: return KEY_UP;
                        case 80: return KEY_DOWN;
                        case 75: return KEY_LEFT;
                        case 77: return KEY_RIGHT;
                    }
                }
            }
        #else
            // Linux/macOS: 使用 usleep 等待并检查
            usleep(1000); // 10ms 延迟
            
            // 检查是否有字符可用（简化版本）
            struct termios oldt2, newt2;
            tcgetattr(STDIN_FILENO, &oldt2);
            newt2 = oldt2;
            newt2.c_lflag &= ~(ICANON | ECHO);
            newt2.c_cc[VMIN] = 0;  // 非阻塞读取
            newt2.c_cc[VTIME] = 0;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt2);
            
            char second_char = getchar();
            if (second_char == '[') {
                char third_char = getchar();
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt2);
                
                switch (third_char) {
                    case 'A': return KEY_UP;
                    case 'B': return KEY_DOWN;
                    case 'C': return KEY_RIGHT;
                    case 'D': return KEY_LEFT;
                }
            } else if (second_char != -1) {
                // 有其他字符，但不是方向键
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt2);
            } else {
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt2);
                return KEY_ESC;  // 单独的 ESC
            }
        #endif
        return KEY_ESC;  // 其他 ESC 序列也当作 ESC
    }
    
    return first_char;  // 返回普通字符
}
char getch() {
#ifdef _WIN32
    return _getch();
#else
    char ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}
Buffer BUFFER=Buffer();
vector<Cursor> CURSORS;
int ROW_BEGIN=0,ROW_END=0;
namespace Help {
	void GetHelp() {
		cout<<"=======欢迎使用 Qaaxaap-vim========"<<endl;
		cout<<"目前还在测试阶段，仅支持 qvim [file name] 以 qvim 打开文件"<<endl;
	}
}
int main(int argc,char* argv[]) {
	if(argc<2) {
		Help::GetHelp();
		return 0;
	}
	std::string FileName=argv[1];
	std::ifstream inFile(FileName.c_str());
	if(!inFile) {
		std::cerr<<"文件错误或不存在，自动创建";
	}
	else {
		std::string Line;
		while(std::getline(inFile,Line)) {
			//std::cerr<<Line<<endl<<endl;
			std::string Ins="";
			for(char c:Line) {
				if(c==9) 
					for(int i=1;i<=4;i++) 
						Ins+=' ';
				else 
					Ins+=c;
			}
			ROW_END++;
			BUFFER.NewLine();
			BUFFER.Insert(BUFFER.size()-1,0,Ins);
		}
		ROW_END--;
		ROW_END=std::max(0,ROW_END);
		inFile.close();
	}
//For Test
	cout<<"\x1b[?1049h"<<flush;
	CURSORS.push_back(Cursor());
	cin>>std::noskipws;
	if(BUFFER.size()==0) 
		BUFFER.NewLine();
	tui::draw();
	while(1) {
		int Chr;
		Chr=getchex();
		if(Chr==KEY_ESC) break;
		if(Chr==9) {
			for(int i=1;i<=4;i++) {
				Edit::Insert(' ');
			}
		}
		if(Chr>=32&&Chr<=126||Chr==KEY_ENTER) Edit::Insert((char)Chr);
		if(Chr==127) Edit::Delete();
		if(Chr==KEY_UP) {
			for(auto &Cur:CURSORS) {
				if(Cur.Place_screen().second>0) 
					Cur.Up();
			}
		}
		if(Chr==KEY_DOWN) {
			for(auto &Cur:CURSORS) {
				if(Cur.Place_screen().second<BUFFER.size()-1)
					Cur.Down();
			}
		}
		if(Chr==KEY_LEFT) {
			for(auto &Cur:CURSORS) {
				if(Cur.Place_screen().first>0)
					Cur.Left();
			}
		}
		if(Chr==KEY_RIGHT) {
			for(auto &Cur:CURSORS) {
				if(Cur.Place_screen().first<BUFFER.LineSize(Cur.Place_fact().second))
					Cur.Right();
			}
		}
		for(auto &Cur:CURSORS) {
			auto [x,y]=Cur.Place_screen();
			if(x>BUFFER.LineSize(y)) Cur.Move(BUFFER.LineSize(y),y);
		}
		tui::draw();
	}
	cout<<std::skipws;
	cout<<"\x1b[?1049l"<<flush;
	return 0;
}

