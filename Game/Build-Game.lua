project (GameName)
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"

   files { "Source/**.h", "Source/**.cpp", "Source/**.inl"}

   defines 
   {
        "SFML_STATIC", 
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
   }

   includedirs
   {
      "Source",
	  ("../" .. (CoreName) .."/Source"),
      "../Vendor/include"
   }

   libdirs
   {
	  "../Vendor/lib"
   }

   links
   {
	  (CoreName),
      "flac",
      "freetype",
      "ogg",
      "openal32",
      "vorbis",
      "vorbisenc",
      "vorbisfile",
      "opengl32.lib", 
      "winmm.lib",
      "gdi32.lib"
   }

   pchheader "gamepch.h"
   pchsource "Source/gamepch.cpp"

   targetdir ("../binaries/" .. OutputDir .. "/" .. GameName)
   objdir ("../binaries/intermediates/" .. OutputDir .. "/" .. GameName)
   debugdir "../Assets/"

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
       links { "sfml-graphics-s-d", "sfml-window-s-d", "sfml-system-s-d", "sfml-audio-s-d" }

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"
       links { "sfml-graphics-s", "sfml-window-s", "sfml-system-s", "sfml-audio-s" }

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
       links { "sfml-graphics-s", "sfml-window-s", "sfml-system-s", "sfml-audio-s" }