-- premake5.lua
CoreName = "Mint"
GameName = "Game"
ProjectName = "Sandbox"

workspace (ProjectName)
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject (GameName)

   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group (CoreName)
	include (CoreName .. "/Build-" .. CoreName .. ".lua")
group ""
include (GameName .. "/Build-" .. GameName ..".lua")