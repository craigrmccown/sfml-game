solution "sfml-work"
	configurations { "Debug", "Release" }

	project "sfml-game"
		kind "WindowedApp"
		language "C++"
		files { "./include/*.h", "./src/*.cpp" }

		configuration "macosx"
			buildoptions { 
						   "-F /Library/Frameworks", 
						   "-std=c++11"	
						 }

			linkoptions { 
						  "-framework sfml-window",
						  "-framework sfml-graphics",
						  "-framework sfml-system",
						  "-framework sfml-audio"
						}

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
			targetdir "bin/debug"
			postbuildcommands 
			{
				"cp -rf assets bin/debug/sfml-game.app/Contents/MacOS/Resources"
			}

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
