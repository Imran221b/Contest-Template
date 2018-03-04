1> Download MinGW64 . 2> Go to Tools -> Build system -> New build system . 3> Paste this code
 
{ "cmd": ["g++.exe","-std=c++11", "-o", "$file_base_name", "$file"],
 
"variants": [
 
    {
        "cmd": ["start", "cmd", "/k", "$file_base_name"],
        "shell": true,
        "name": "Run"
    }
]
 
} and save the build . 4>Select this build system now . Save your programs inside Bin folder in MinGW64
