{
  "targets": [
    {
      "target_name": "SimpleMathNodeAddon", #Compiled node addon name.
      "cflags!": [
        "-fno-exceptions"
      ],
      "cflags_cc!": [
        "-fno-exceptions"
      ],
      "sources": [ #Source files required to build.
        "cpp_source/main.cpp",
        "cpp_source/wrapper.cpp",
        "cpp_source/simple-math-node-addon/simple_math.cpp",
      ],
      "include_dirs": [ #If you use any library in cpp project, write here header files path.
        "<!@(node -p \"require('node-addon-api').include\")",
      ],
      "libraries": [#If you use any libray in cpp projecy, write here library lib files path.
      ],
      "configurations": {#Compilation settings, default RuntimeTypeInfo is closed.
        "Release": {
          "msvs_settings": {
            "VCCLCompilerTool": {
              "ExceptionHandling": "2",
              "RuntimeTypeInfo": "true",
              "AdditionalOptions": [
                "/std:c++17"
              ]
            }
          }
        }
      },
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "defines":[
       "WIN",
       '_HAS_EXCEPTIONS=1' #To handle exceptions occured in cpp project. 
       ]
    }
  ]
}
