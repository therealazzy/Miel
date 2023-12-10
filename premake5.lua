workspace "Miel"
	architecture "x86_64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Miel/vendor/GLFW/include"

include "Miel/vendor/GLFW"

project "Miel"
	location "Miel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mlpch.h"
	pchsource "Miel/src/mlpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ML_PLATFORM_WINDOWS",
			"ML_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "ML_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ML_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ML_DIST"
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
		"Miel/vendor/spdlog/include",
		"Miel/src"
	}

	links
	{
		"Miel"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ML_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
		defines "ML_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "ML_RELEASE"
		optimize "On"

		filter "configurations:Dist"
		defines "ML_DIST"
		optimize "On"