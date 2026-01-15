#include<iostream>
#include"../include/cursor.h"
#include"../include/tui.h"
#include"../include/buffer.h"
namespace tui {
	void draw() {
		std::cout<<"\x1b[2J";
		std::cout<<"\x1b[1;1H";
		for(int i=ROW_BEGIN;i<=ROW_END;i++) {
			std::cout<<BUFFER.ReadLine(i)<<'\n';
		}
		std::cout<<std::flush;
		auto [X,Y]=(*CURSORS.begin()).Place_screen();
		std::cout<<"\x1b["<<Y+1<<';'<<X+1<<'H'<<std::flush;
	}
	void drawcursor() {
		auto [X,Y]=(*CURSORS.begin()).Place_screen();
		std::cout<<"\x1b["<<Y+1<<';'<<X+1<<'H'<<std::flush;
	}
}
