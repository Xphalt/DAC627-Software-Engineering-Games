#ifdef _WIN32
#include "audiolib.h"
#include <windows.h>


//using namespace std;

//class audiolib
//{
//public:
    //audiolib::audiolib()
    //{

    //}

void audiolib::initialiselibrary()
{
    //loadfiles();
}

bool audiolib::loadfiles()
{
    

    return true;
}

//// folder must end with "/", e.g. "D:/images/"
//vector<string> get_all_files_full_path_within_folder(string folder)
//{
//    vector<string> names;
//    char search_path[200];
//    sprintf(search_path, "%s*.*", folder.c_str());
//    WIN32_FIND_DATA fd;
//    HANDLE hFind = ::FindFirstFile(search_path, &fd);
//    if (hFind != INVALID_HANDLE_VALUE)
//    {
//        do
//        {
//            // read all (real) files in current folder, delete '!' read other 2 default folder . and ..
//            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
//            {
//                names.push_back(folder + fd.cFileName);
//            }
//        } while (::FindNextFile(hFind, &fd));
//        ::FindClose(hFind);
//    }
//    return names;
//}

//char** directory_files(const char* path, size_t* size_return)
//{
//    size_t count = 0;
//    char** filenames = 0;
//
//    HANDLE hFind;
//    WIN32_FIND_DATA data;
//
//    // Count Files
//    hFind = FindFirstFile(path, &data);
//    if (hFind != INVALID_HANDLE_VALUE)
//    {
//        do
//        {
//            ++count;
//        } while (FindNextFile(hFind, &data));
//
//        FindClose(hFind);
//    }
//
//    if (count > 0)
//    {
//        filenames = malloc(sizeof(*filenames) * count);
//        size_t i = 0;
//
//        // Copy File Names to Array
//        hFind = FindFirstFile(path, &data);
//        if (hFind != INVALID_HANDLE_VALUE)
//        {
//            do
//            {
//                filenames[i] = malloc(strlen(data.cFileName) + 1);
//                strcpy(filenames[i], data.cFileName);
//                ++i;
//            } while (FindNextFile(hFind, &data));
//
//            FindClose(hFind);
//        }
//    }
//
//    if (size_return) *size_return = count;
//
//    return filenames;
//}
//
//void free_directory_files(char** filenames, size_t size)
//{
//    if (filenames)
//    {
//        for (size_t i = 0; i < size; ++i)
//            free(filenames[i]);
//
//        free(filenames);
//    }
//}

#endif // _WIN32