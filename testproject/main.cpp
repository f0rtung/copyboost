#include <iostream>
#include <boost\filesystem.hpp>
#include <boost\algorithm\string.hpp>

bool FullDirCopy(const boost::filesystem::wpath& from, const boost::filesystem::wpath& to)
{
	using namespace boost::filesystem;
	if (!exists(to))
	{
		if (!create_directory(to))
		{
			return false;
		}
	}
	directory_iterator start(from);
	directory_iterator end = boost::filesystem::directory_iterator();
	for (; start != end; ++start)
	{
		if (is_directory(*start))
		{
			if (!FullDirCopy(*start, to / "\\" / start->path().filename()))
			{
				return false;
			}
		}
		else
		{
			copy_file(*start, to / "\\" / start->path().filename(),copy_option::overwrite_if_exists);
		}
	}
	return true;
}


int main()
{
	//try
	//{
	//	FullDirCopy("d:\\Games", "D:\\testtest");
	//}
	//catch (...)
	//{

	//}
	boost::filesystem::path dirPath("D:\\Games");
	if (boost::filesystem::is_directory(dirPath))
	{
		std::cout << boost::algorithm::replace_all_copy(dirPath.string(), "\\", "\\\\");
	}
	return 0;
}