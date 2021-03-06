workspace "CoconutEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CoconutEngine"
	location "CoconutEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CN_PLATFORM_WINDOWS",
			 "CN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CN_Dist"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CoconutEngine/vendor/spdlog/include",
		"CoconutEngine/src"
	}

	links
	{
		"CoconutEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CN_Dist"
		optimize "On"