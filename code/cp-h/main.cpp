#include<bits/stdc++.h>
#include<dirent.h>
namespace fs=std::filesystem;
namespace work
{
	void list_code_ds()
	{
		fs::path now_dir=fs::current_path();
		std::cout<<"显示目录："<<now_dir<<std::endl;
		std::cout<<"内容："<<std::endl;
		//for(const auto&nxt_dir:fs::directory_iterator(now_dir))
		//{
			
		//}
	    std::vector<fs::path> files;

		// 一行代码遍历并收集
		std::copy_if(
			fs::directory_iterator(fs::current_path()),
			fs::directory_iterator(),
			std::back_inserter(files),
		  	[](const auto& entry) { return entry.is_regular_file(); }
	   	);
	
		// 按文件名排序
		std::sort(files.begin(), files.end());
		for (const auto& file:files) std::cout<<file.filename()<<std::endl;
	}
	void list_code()
	{
		DIR* dir=opendir(".");
	}
	void new_race()
	{
		
	}
}
namespace help
{
	void get_help()
	{
		std::cout<<"用法："<<std::endl;
		std::cout<<"    --help    -h 显示此提示"<<std::endl;
		std::cout<<"    --version -v 显示版本信息"<<std::endl;
	}
	void get_version()
	{
		std::cout<<"更新时间：2026.1.11"<<std::endl;
		std::cout<<"更新内容：创建项目"<<std::endl;
	}
}
int main(int argc,char* argv[])
{
	if(argc<=1) 
	{
		help::get_help();
		return 0;
	}
	for(int i=1;i<argc;i++)
	{
		std::string arg=argv[i];
		if(arg=="--help"||arg=="-h") help::get_help();
		if(arg=="--version"||arg=="-v") help::get_version();
		//if(arg=="--code"||arg=="-c") work::list_code();
	}
	return 0;
}

