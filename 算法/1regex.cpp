// // #include <regex>
// // #include <iostream>
// // #include <string>

// // using namespace std;

// // int main()
// // {
// //     string str="255.255.255.255";    
// //    regex  _regex("^((25[0-5]|2[0-4]\\d|[01]?\\d\\d?)\.){3}(25[0-5]|2[0-4]\\d|[01]?\\d\\d?)$");
// //     cout<<regex_match(str,_regex)<<endl;

// //     return 0;
// // }



// // #include <stdio.h>
// // #include <string.h>

// // int main () {
// //     char str[50];
// //     strcpy(str,"This is string.h library function");
// //     puts(str);
// //     memset(str,'$',7);
// //     puts(str);
// //     return(0);
// // }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int i=1;
//     switch(i)
//     {
//         case 1:
//             cout<<"1";
//         case 2:
//             cout<<"2";
//         default:
//             cout<<"default";
//             break;
//     }
//     return 0;
// }


#include <regex>
using namespace std;

//写一个函数，判断一个字符串是否是合法的IP地址
bool isIP(string str)
{
    regex _regex("^((25[0-5]|2[0-4]\\d|[01]?\\d\\d?)\\.){3}(25[0-5]|2[0-4]\\d|[01]?\\d\\d?)$");
    return regex_match(str,_regex);
}