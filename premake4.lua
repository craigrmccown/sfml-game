solution "sfml-work"
	configurations { "Debug", "Release" }

	project "sfml-game"
		kind "WindowedApp"
		language "C++"
		files { "./include/*.h", "./src/*.cpp" }
		location "build"

		configuration "macosx"
			buildoptions { "-F /Library/Frameworks", 
						   "-std=c++11"	
						 }
			linkoptions { "-framework sfml-window",
						  "-framework sfml-graphics",
						  "-framework sfml-system",
						  "-framework sfml-audio"
						}

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
